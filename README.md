# vio_g2o

Depends on Sophus, g2o, and vio_common.
vio_common depends on Eigen and openCV.
Sophus is included in thirdparty/ folder as submodules.
g2o and vio_common will be downloaded as catkin packages.

# Build

## With ROS
```
mkdir -p vio_g2o_ws/src
cd vio_g2o_ws/src
git clone --recursive https://github.com/JzHuai0108/vio_g2o.git

wstool init
wstool merge vio_g2o/dependencies.rosinstall
wstool update -j 8

catkin build vio_g2o -DUSE_ROS=ON -DCMAKE_BUILD_TYPE=Release -j4

```

