 /* Copyright (c) 2015, Stefan Isler, islerstefan@bluewin.ch
*

eigen_utils is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
eigen_utils is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License
along with eigen_utils. If not, see <http://www.gnu.org/licenses/>.
*/ 
 
#include "utils/eigen_utils.h"

using namespace Eigen;

namespace st_is
{
  
Matrix3d crossProdMatrix( Vector3d _vec )
{
  Matrix3d ret;
  ret<< 0,		-_vec.z(),	_vec.y(),
	_vec.z(),	0,		-_vec.x(),
	-_vec.y(),	_vec.x(),	0;
  return ret;
}

DualQuaternion::DualQuaternion()
{
  
}

DualQuaternion::DualQuaternion( Eigen::Quaterniond _rot, Eigen::Vector3d _trans )
{
  Eigen::Quaterniond q, qPrime;
  
  q = _rot.normalized(); // just to ensure normalization
  
  // by the screw congruence theorem q and q' one must be equal for hand eye calibration for both the eye and the hand movement. since the rotation represented by quaternion q is equal to -q, enforcing q_1>=0
  if( q.w()<0 )
  {
    q.w() = - q.w();
    q.x() = -q.x();
    q.y() = -q.y();
    q.z() = -q.z();
  }
  
  Vector3d qAxis = q.vec();
  
  Vector3d qPrimeAxis = 0.5*( q.w()*_trans + _trans.cross(qAxis) );
  double qPrimeW = -0.5*qAxis.dot(_trans);
  
  qPrime.x() = qPrimeAxis.x();
  qPrime.y() = qPrimeAxis.y();
  qPrime.z() = qPrimeAxis.z();
  qPrime.w() = qPrimeW;
  
  q_prime = qPrime;
}
    
} 