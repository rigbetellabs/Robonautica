## Instructions for Preliminary event of ROBONAUTICA 2023 @ IISC Bengaluru.
### ROS Noetic Installation
Follow the below reference for the installation of ROS-Noetic in Ubuntu 20.04 (For other OS, navigate in rosWiki and follow the procedure, however, we encourage you to use Ubuntu 20.04 + ROS NOETIC framework)
[http://wiki.ros.org/noetic/Installation/Ubuntu](http://wiki.ros.org/noetic/Installation/Ubuntu)

### Catkin Workspace
After the installation of ROS, we can create a catkin workspace through the following commands
```
mkdir –p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_init_workspace
cd ~/catkin_ws/
catkin_make
source ~/catkin_ws/devel/setup.bash
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
```
To ensure your workspace is properly set up, check for the ROS_PACKAGE_PATH using the following command. You must see the current directory similar to 
```
echo $ROS_PACKAGE_PATH
```
> /home/<username>/catkin_ws/src:/opt/ros/noetic/share:/opt/ros/noetic/stacks
### Cloning the current repository
All the executables and folders are to be placed in src/ and catkin_make every time you modify the src/ folder.
Hence, navigate to the src/ folder and clone the required repositories & dependencies as follows:
```
cd ~/catkin_ws/src
git clone https://github.com/rigbetellabs/Robonautica.git
```
### Dependencies
```
git clone https://github.com/nilseuropa/realsense_ros_gazebo.git
```
```
git clone https://github.com/issaiass/realsense2_description.git
```
```
sudo apt-get install ros-noetic-teleop-twist-keyboard ros-noetic-urdf ros-noetic-xacro ros-noetic-rqt-image-view  ros-noetic-robot-state-publisher ros-noetic-joint-state-publisher-gui
```
Before moving on to launching the setup, navigate to the root of the workspace and make the workspace
```
cd ~/catkin_ws
catkin_make
```
Use the commands in the following section to launch the bot.
### Running Gazebo Simulations
In terminal 1,
``` 
roslaunch tortoisebotpromax_gazebo tortoisebotpromax_playground.launch
```
### Running RViz Visualization
Open another terminal (terminal 2)
``` 
roslaunch tortoisebotpromax_description display.launch
```
You may change the Rviz configuration by adding topics for generating maps, visualization purposes, etc.,
### Teleoperation of the bot
In terminal 3
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
and follow the instructions in the terminal for teleoperation. 
Note: Use keyboard commands while being in the terminal for publishing the control commands.  

You may subscribe to the needed sensor feedback and publish your control commands through corresponding rostopics via subscribers and publishers.
To list down all rostopics, use
```
rostopic list
```
## Task
After launching the above setup, 
1. Participants need to visualize the lidar point cloud in Rviz. 
2. Teleoperate, scan the AruCo markers, and store the corresponding waypoint information and robot's pose.
3. Generate an occupancy grid-based map ( You may use established algorithms by mentioning) while teleoperating with the bot.
4. Finally, drive the robot autonomously through a sequence of waypoints stored.
5. Follow the submission guidelines mentioned in Preliminary_Events.pdf as in the mail. You may also include a README.txt in your submission .zip to mention different references and algorithms you have used.


### General Useful references
1. ROS Tutorials -[http://wiki.ros.org/ROS/Tutorials](http://wiki.ros.org/ROS/Tutorials)
2. Rviz User guide -[http://wiki.ros.org/rviz/UserGuide](http://wiki.ros.org/rviz/UserGuide)

> Reach out to us through the team leader( Whatsapp) in case of any queries.
