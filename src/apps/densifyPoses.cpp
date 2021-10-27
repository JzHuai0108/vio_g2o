// Given consecutive poses obtained by a drifting odometer, 
// and sparse key poses obtained by an optimization backend,
// densify the sparse poses with the dense consecutive odometry poses,
// by using a pose graph optimization on SE3.
#include "vio_g2o/IMU_constraint.h"
#include <vio/ImuGrabber.h>

#include <iostream>
#include <fstream>
#include <iomanip>      // std::setprecision

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <sophus/se3.hpp>

void densifyPoses(const std::string &framePoseTxt, const std::string &keyframePoseTxt) {
  std::cout << "Frame pose file " << framePoseTxt << "\nKeyframe pose file " << keyframePoseTxt << "\n"; 
// 1.1 load keyframe poses from test/data/dataset-corridor1_512_16_poses.txt, 
// refer to loadCsvData in SimDataInterface.cpp of repo swift_vio.
// 1.2 load frame poses from test/data/dataset-corridor1_512_16_kfposes.txt, 
// refer to loadCsvData in SimDataInterface.cpp of repo swift_vio.

// 2. build the g2o optimization problem, refer to optimizeScaleTrans in scale_solver.cpp of this package, OR
// https://github.com/JzHuai0108/sim3opt/blob/master/kitti_surf.cpp#L542
// 2.1 states: SE3 poses for all frames. Frames includes all keyframes.
// These states are represented by G2oVertexSE3
// 2.2 observations: 
// SE3 pose priors for keyframes, represented by G2oSE3Observation6DEdge
// SE3 relative motion constraints for consecutive frames, represented by G2oEdgeSE3

// 2.3 initialization of SE3 poses: for keyframes, use the values loaded from the file, 
// for frames, initialize their poses relative to the nearest keyframe using relative motion.

// 2.4 optimize the poses

// 3. save the refined frame poses to a csv file with the same format as the poses.txt.

}

int main(int argc, char *argv[])
{
    if (argc < 3) {
      std::cerr << "Usage: " << argv[0] << "frame_poses.txt keyframe_poses.txt\n" <<
          "Both files should have lines in TUM RGBD format, i.e., time[sec] tx ty tz qx qy qz qw\n";
      return -1;
    }
    densifyPoses(argv[1], argv[2]);
    return 0;
}
