/* Copyright (c) 2015, Stefan Isler, islerstefan@bluewin.ch
*
This file is part of hand_eye_calibration, a ROS package for hand eye calibration,

hand_eye_calibration is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
hand_eye_calibration is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License
along with hand_eye_calibration. If not, see <http://www.gnu.org/licenses/>.
*/

 
#include "hand_eye_calibration/autonomous_hand_eye_calibrator.h"

using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "autonomous_hand_eye_calibration");
  ros::NodeHandle n("autonomous_hand_eye_calibration");
  
  
  AutonomousHandEyeCalibrator calibrator(&n);
  
  ros::Rate rate(0.2);
  while ( calibrator.runSingleIteration() && n.ok() )
  {
    rate.sleep();
  }
  
  return 0;
} 
