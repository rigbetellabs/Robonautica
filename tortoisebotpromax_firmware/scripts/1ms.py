#!/usr/bin/env python3
import rospy 
from geometry_msgs.msg import Twist

def move():
	rospy.init_node('move')
	pub = rospy.Publisher("cmd_vel", Twist, queue_size=10)
	rate = rospy.Rate(1)

	v = Twist()
	rate.sleep()
	while True:
		v.angular.z = 1.57 #m/s
		pub.publish(v)
		rate.sleep()
		rospy.loginfo(v)
		break
	v.angular.z = 0
	pub.publish(v)
	rate.sleep()
	rospy.loginfo(v) 

if __name__ == '__main__':
	move()

