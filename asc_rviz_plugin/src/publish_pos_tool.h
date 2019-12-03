#ifndef PUBLISH_POS_TOOL_H
#define PUBLISH_POS_TOOL_H

#ifndef Q_MOC_RUN 
# include <QObject>

#include <ros/ros.h>

#include <rviz/default_plugin/tools/pose_tool.h>

#endif

namespace rviz
{
class Arrow;
class DisplayContext;
class StringProperty;
class FloatProperty;


class PublishPosTool: public PoseTool
{
Q_OBJECT
public:
  PublishPosTool();
  virtual ~PublishPosTool() {}
  virtual void onInitialize();

protected:
  virtual void onPoseSet(double x, double y, double theta);

private Q_SLOTS:
  void updateTopic();

private:
  ros::NodeHandle nh_;
  ros::Publisher pub_;

  StringProperty* topic_property_;
  FloatProperty* std_dev_x_;
  FloatProperty* std_dev_y_;
  FloatProperty* std_dev_theta_;
};

}

#endif // PLANT_FLAG_TOOL_H
