#!/usr/bin/env python3

import rospy
from std_msgs.msg import Bool
from std_srvs.srv import Empty, EmptyResponse

class PIDControlNode:
    def __init__(self):
        rospy.init_node('pid_control_node')
        
        # Read the initial value of the ROS parameter ~pid
        self.pid_param = rospy.get_param('~pid', False)
        
        # Create a publisher for the PID_control topic
        self.pid_pub = rospy.Publisher('PID_control', Bool, queue_size=10)
        
        # Create ROS services
        self.pid_on_service = rospy.Service('pid_on', Empty, self.pid_on)
        self.pid_off_service = rospy.Service('pid_off', Empty, self.pid_off)

    def pid_on(self, request):
        # Service callback to turn PID on
        self.pid_param = True
        rospy.set_param('~pid', True)
        return EmptyResponse()

    def pid_off(self, request):
        # Service callback to turn PID off
        self.pid_param = False
        rospy.set_param('~pid', False)
        return EmptyResponse()

    def run(self):
        rate = rospy.Rate(10)  # 10 Hz

        while not rospy.is_shutdown():
            # Continuously publish the value of self.pid_param on PID_control topic
            pid_msg = Bool()
            pid_msg.data = self.pid_param
            self.pid_pub.publish(pid_msg)
            rate.sleep()

if __name__ == '__main__':
    try:
        pid_node = PIDControlNode()
        pid_node.run()
    except rospy.ROSInterruptException:
        pass

