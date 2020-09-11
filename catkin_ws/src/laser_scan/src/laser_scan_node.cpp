
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/transform_listener.h>
#include <std_msgs/Int16MultiArray.h>


using namespace std;

double  left_sharp_distance;
double right_sharp_distance;

void sharp_callback(const std_msgs::Int16MultiArray::ConstPtr& msg) {

	left_sharp_distance  = 9.609  * pow(msg->data[0], -0.832);
	right_sharp_distance = 19.327 * pow(msg->data[1], -0.958); 
    //cout << "left_sharp_distance: " << left_sharp_distance << "\tright_sharp_distance: " << right_sharp_distance << endl;
}

int main(int argc, char** argv){

	cout << "Starting laser_scan_node by Luis Näva..." << endl;

	ros::init(argc, argv, "laser_scan_node");
	ros::NodeHandle n;

	ros::Publisher  scan_pub = n.advertise<sensor_msgs::LaserScan>("/scan", 50);
	ros::Subscriber laser_sub = n.subscribe("/sharp_sensors", 100, sharp_callback); 

	unsigned int num_readings = 2;
	double laser_frequency = 40;
	double ranges[num_readings];
	double intensities[num_readings];
	double theta = 0.5235;

	int count = 0;
	ros::Rate loop(20);

	tf::TransformListener listener;


	while(n.ok()){

		tf::StampedTransform transform;
		try {

			listener.waitForTransform("base_link", "laser_link", ros::Time(0), ros::Duration(10.0));
			listener.lookupTransform("base_link", "laser_link", ros::Time(0), transform);
		}

		catch (tf::TransformException ex){

			ROS_ERROR("%s",ex.what());
			ros::Duration(1.0).sleep();
		}

		ranges[0] = right_sharp_distance;
		ranges[1] =  left_sharp_distance;

		intensities[0] = 100;
		intensities[1] = 100;

		float right_theta = atan(0.04 / right_sharp_distance);
		float left_theta  = atan(0.04 /  left_sharp_distance);

		float right_beam = sqrt(pow(0.04, 2) + pow(right_sharp_distance, 2));
		float  left_beam = sqrt(pow(0.04, 2) + pow(left_sharp_distance , 2)); 

		ranges[0] = right_beam;
		ranges[1] =  left_beam;

		ros::Time scan_time = ros::Time::now();

		sensor_msgs::LaserScan scan;
		scan.header.stamp = scan_time;
		scan.header.frame_id = "laser_link";
		scan.angle_min = - right_theta;
		scan.angle_max =    left_theta;

		scan.angle_increment = right_theta + left_theta;
		scan.time_increment = (1 / laser_frequency) / (num_readings);
		scan.range_min = 0.0;
		scan.range_max = 100.0;

		scan.ranges.resize(num_readings);
		scan.intensities.resize(num_readings);

		for(unsigned int i = 0; i < num_readings; ++i) {

			scan.ranges[i] = ranges[i];
			scan.intensities[i] = intensities[i];
		}

		scan_pub.publish(scan);
		++count;

		ros::spinOnce();
		loop.sleep();
	}
}
