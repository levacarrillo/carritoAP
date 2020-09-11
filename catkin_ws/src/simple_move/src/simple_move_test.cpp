#include <ros/ros.h>
#include <simple_move/SimpleMove.h>

using namespace std;
enum State{
	SM_INIT,
	SM_GOAL_POSE_ACCEL,
	SM_GOAL_POSE_CRUISE,
	SM_GOAL_POSE_DECCEL,
	SM_GOAL_POSE_CORRECT_ANGLE,
	SM_GOAL_POSE_FINISH
}

bool simpleMoveCallback(simple_move::SimpleMove::Request &req, simple_move::SimpleMove::Response &resp){
	cout<<"holi"<<endl;
	State state = SM_INIT;
	ros::Rate rate(30);

}

int main(int argc, char **argv)
{
    cout<<"Starting simple_move_test_node"<<endl;
    ros::init(argc, argv, "simple_move_test");
    ros::NodeHandle n;
    ros::Rate rate(30);
    
    ros::ServiceServer simpleMoveService = n.advertiseService("simple_move_test", simpleMoveCallback);

    while(ros::ok())
    {

        ros::spinOnce();
	rate.sleep();	
    }
    return 0;
}
