cmake_minimum_required(VERSION 2.8.3)
project(hand_eye_calibration)

find_package(catkin REQUIRED COMPONENTS
  sensor_msgs
  cv_bridge
  geometry_msgs
  roscpp
  tf2_msgs
  tf2_ros
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Eigen REQUIRED)


catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp geometry_msgs tf2_msgs tf2_ros sensor_msgs cv_bridge
  DEPENDS opencv opencv2 Eigen
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

add_executable(youbot_link_position_publisher src/YoubotLinkPositionPublisher.cpp src/youbot_link_position_publisher.cpp)

target_link_libraries(youbot_link_position_publisher
  ${catkin_LIBRARIES}
)

add_executable(eye_position_from_checkerboard src/EyePositionFromCheckerboard.cpp src/eye_position_from_checkerboard.cpp)

target_link_libraries(eye_position_from_checkerboard
  ${catkin_LIBRARIES}
)

add_executable(dual_quaternion_transformation_estimator src/DualQuaternionTransformationEstimator.cpp src/dual_quaternion_transformation_estimator.cpp)

target_link_libraries(dual_quaternion_transformation_estimator
  ${catkin_LIBRARIES}
)