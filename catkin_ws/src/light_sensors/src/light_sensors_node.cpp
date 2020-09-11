#include <ros/ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <light_sensors/simulator_light.h>



using namespace std;


float light_sensor[4];

void light_callback(const std_msgs::Int16MultiArrayConstPtr& msg) {

    cout << " [" << msg->data[0] << ", " << msg->data[1] << ", " << msg->data[2] << ", " << msg->data[3] << "] " << endl;
    
    for(int i=0; i<4; i++) 
	light_sensor[i] = msg->data[i];
}

bool get_intensities(light_sensors::simulator_light::Request &req, light_sensors::simulator_light::Response &res) {

    //Ghost sensor
    res.values[0] = (light_sensor[0] + light_sensor[3]) / 2;

    for(int i=1; i<5; i++) { 

	res.values[i*2-1] = light_sensor[i-1];

	if(i<4)
	    res.values[i*2] = (light_sensor[i-1] + light_sensor[i+1]) / 2; //Ghost sensors   
    
    }

    
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
