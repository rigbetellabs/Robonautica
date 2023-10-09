#!/usr/bin/env python3

import rospy
from std_msgs.msg import Bool

def bool_publisher():
    # Initialize the ROS node
    rospy.init_node('bool_publisher', anonymous=True)

    # Create a publisher for the boolean topic
    pub = rospy.Publisher('PID_control', Bool, queue_size=10)

    # Get the boolean argument from the launch file (default to False)
    my_bool_value = rospy.get_param('~pid', False)

    rate = rospy.Rate(1)  # 1 Hz
    while not rospy.is_shutdown():
        # Publish the boolean value
        pub.publish(my_bool_value)
        rate.sleep()

if __name__ == '__main__':
    try:
        bool_publisher()
    except rospy.ROSInterruptException:
        pass
