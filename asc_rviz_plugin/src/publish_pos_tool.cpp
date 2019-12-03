#include "publish_pos_tool.h"

#include <tf/transform_listener.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include <rviz/display_context.h>
#include <rviz/properties/string_property.h>
#include <rviz/properties/float_property.h>


namespace rviz
{

PublishPosTool::PublishPosTool()
{
  shortcut_key_ = 'p';

  topic_property_ = new StringProperty( "Topic", "subgoal_pose",
                                        "The topic on which to publish pose.",
                                        getPropertyContainer(), SLOT( updateTopic() ), this );
  std_dev_x_ = new FloatProperty("X std deviation", 0.5, "X standard deviation for initial pose [m]", getPropertyContainer());
  std_dev_y_ = new FloatProperty("Y std deviation", 0.5, "Y standard deviation for initial pose [m]", getPropertyContainer());
  std_dev_theta_ = new FloatProperty("Theta std deviation", M_PI / 12.0, "Theta standard deviation for initial pose [rad]", getPropertyContainer());
  std_dev_x_->setMin(0);
  std_dev_y_->setMin(0);
  std_dev_theta_->setMin(0);
}

void PublishPosTool::onInitialize()
{
  PoseTool::onInitialize();
  setName( "2D Pose Publisher" );
  updateTopic();
}

void PublishPosTool::updateTopic()
{
    pub_ = nh_.advertise<geometry_msgs::PoseWithCovarianceStamped>( topic_property_->getStdString(), 1 );
}


void PublishPosTool::onPoseSet(double x, double y, double theta)
{
  std::string fixed_frame = context_->getFixedFrame().toStdString();
  geometry_msgs::PoseWithCovarianceStamped pose;
  pose.header.frame_id = fixed_frame;
  pose.header.stamp = ros::Time::now();
  pose.pose.pose.position.x = x;
  pose.pose.pose.position.y = y;

  tf::Quaternion quat;
  quat.setRPY(0.0, 0.0, theta);
  tf::quaternionTFToMsg(quat,
                        pose.pose.pose.orientation);
  pose.pose.covariance[6*0+0] = std::pow(std_dev_x_->getFloat(), 2);
  pose.pose.covariance[6*1+1] = std::pow(std_dev_y_->getFloat(), 2);
  pose.pose.covariance[6*5+5] = std::pow(std_dev_theta_->getFloat(), 2);
  ROS_INFO("Setting pose: %.3f %.3f %.3f [frame=%s]", x, y, theta, fixed_frame.c_str());
  pub_.publish(pose);
}

}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz::PublishPosTool,rviz::Tool )

