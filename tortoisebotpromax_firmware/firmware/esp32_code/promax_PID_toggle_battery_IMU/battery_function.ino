//=================== battery read veriables =======================

#define FILTER_LEN 30

uint32_t V_ADC_Buffer[FILTER_LEN] = { 0 };

int V_ADC_i = 0;
int V_ADC_Raw = 0;
int V_ADC_Filtered = 0;

float bat_voltage = 0.0;
float voltage_offset = 0.05;  // 0.06 for 244   and  0.2 for 116 and 0.03 for 86 and 0.05 for iisc5 
float V_pin_voltage;
float vin = 0.0;
float R1 = 98400.0;
float R2 = 10000.0;
float minvin = 20.6;
float maxvin = 25.2;
int batper = 0;
int old_batper = 0;
int bat_check_interval = 10;  // in sec

int smart_bat_per = 0;

bool stable = true;
unsigned long startTime;

bool battery_low = false;

const float battery_low_voltage = 20.80;

const unsigned long adc_satble_wait = 10000;
unsigned long adc_stable_startTime = 0;
bool adc_stable = false;

//================= buzzer beeping variables =======================

unsigned long bat_previousMillis = 0;
int beepCount = 0;
bool buzzerOn = false;
bool isBreakTime = false;
const int beepDuration = 100;    // Duration of each beep in milliseconds
const int breakDuration = 5000;  // Duration of the break in milliseconds
bool bat_low_flag = false;

uint32_t V_readADC_Avg(int ADC_Raw) {
  int i = 0;
  uint32_t Sum = 0;

  V_ADC_Buffer[V_ADC_i++] = ADC_Raw;
  if (V_ADC_i == FILTER_LEN) {
    V_ADC_i = 0;
  }
  for (i = 0; i < FILTER_LEN; i++) {
    Sum += V_ADC_Buffer[i];
  }
  return (Sum / FILTER_LEN);
}

uint32_t readADC_Cal(int ADC_Raw) {
  esp_adc_cal_characteristics_t adc_chars;
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
  return (esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars));
}

void read_battery_voltage() {

  if (!adc_stable) {
    unsigned long adc_currentMillis = millis();

    // If 10 seconds have passed since the start time, set the flag to true
    if (adc_currentMillis - adc_stable_startTime >= adc_satble_wait) {
      adc_stable = true;
    }
  }

  V_ADC_Raw = analogRead(voltagePin);
  V_ADC_Filtered = V_readADC_Avg(V_ADC_Raw);
  vin = readADC_Cal(V_ADC_Filtered);
  V_pin_voltage = (vin / 1000) - voltage_offset;

  bat_voltage = V_pin_voltage / (R2 / (R1 + R2));
  batper = ((bat_voltage - minvin) / (maxvin - minvin)) * 100;

  bat_volt_msg.data = bat_voltage;
  bat_volt_pub.publish(&bat_volt_msg);

  //====================== Serial print data =======================
  if (stable) {
    unsigned long elapsedTime = (millis() - startTime) / 1000;

    if (elapsedTime >= bat_check_interval) {
      startTime = millis();
      smart_bat_per = batper;
      old_batper = batper;
      bat_per_msg.data = smart_bat_per;
      bat_per_pub.publish(&bat_per_msg);
      // Serial.println("5 seconds have elapsed. Counter restarted!");
    } else {
      smart_bat_per = old_batper;
    }
  }
  if (smart_bat_per == 0) {
    smart_bat_per = batper;
  }

  if (adc_stable == true) {
    if (bat_voltage < battery_low_voltage) {
      bat_low_flag = true;
    }
    if (bat_low_flag == true) {
      battery_low = true;
    } else {
      battery_low = false;
    }
    if (bat_voltage > battery_low_voltage + 0.70) {
      bat_low_flag = false;
    }
  }
}

void enable_buzzer() {

  if (battery_low == true) {
    unsigned long buzz_currentMillis = millis();

    // Check if it's break time
    if (isBreakTime) {
      if (buzz_currentMillis - bat_previousMillis >= breakDuration) {
        // Break time is over, reset for the next beep sequence
        isBreakTime = false;
        beepCount = 0;
        // hard_stop();
        // anim_pub_msg.data = 15;
        // anim_msg_pub.publish(&anim_pub_msg);
      }
    }
    // Check if it's time for a beep
    else if (beepCount < 5) {
      if (buzz_currentMillis - bat_previousMillis >= beepDuration) {
        bat_previousMillis = buzz_currentMillis;
        buzzerOn = !buzzerOn;  // Toggle the buzzer state
        if (buzzerOn) {
          tone(buzzerPin, NOTE_G4, (1000/8));
        } else {
          noTone(buzzerPin);
          beepCount++;
        }
      }
    } else {
      // All beeps are done, set break time
      isBreakTime = true;
      bat_previousMillis = buzz_currentMillis;
    }
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}
