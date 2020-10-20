#include <ros/ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <light_sensors/simulator_light.h>



using namespace std;

float light_sensor[8];

void light_callback(const std_msgs::Int16MultiArrayConstPtr& msg) {

    cout << " [" << msg->data[0] << ", " << 
					msg->data[1] << ", " << 
					msg->data[2] << ", " << 
					msg->data[3] << " ," << 
					msg->data[4] << ", " << 
					msg->data[5] << " ," << 
					msg->data[6] << ", " << 
					msg->data[7] << " ," << 
					"] " << endl;
    
    for(int i=0; i<8; i++)  light_sensor[i] = msg->data[i];
}

bool get_intensities(light_sensors::simulator_light::Request &req, light_sensors::simulator_light::Response &res) {

	for(int i=0; i<5; i++)  res.values[i] = light_sensor[i+3];
	for(int i=5; i<8; i++)  res.values[i] = light_sensor[i-5];
    
    return true;
}
    
int main(int argc, char **argv) {

    cout << "Starting light_sensors_node by Luis Näva..." << endl;
    ros::init(argc, argv, "light_sensors_node");
    ros::NodeHandle nh;

    ros::Subscriber sub_light_sensors = nh.subscribe("/light_sensors", 10, light_callback);
    ros::ServiceServer service = nh.advertiseService("simulator_light_RealRobot", get_intensities);

    ros::spin();

    return 0;
}
