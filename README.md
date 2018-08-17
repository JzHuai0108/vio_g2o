# vio_g2o

Depends on sophus, and vio_common which depends on eigen and opencv

# Build example


## with g2o in ORB_SLAM2
Assume sophus, vio_common installed in $INSTALL_PREFIX
```
cmake .. -DOpenCV_DIR=/opt/ros/kinetic/share/OpenCV-3.3.1 -DEIGEN_INCLUDE_DIR=/usr/include/eigen3 -DINSTALL_PREFIX=$HOME/slam_devel -DORBSLAM_G2O_PATH=../../../ORB_SLAM2/Thirdparty/g2o
make
```

## with g2o from github
Assume sophus, vio_common, g2o installed in $INSTALL_PREFIX
```
cmake .. -DOpenCV_DIR=/opt/ros/kinetic/share/OpenCV-3.3.1 -DEIGEN_INCLUDE_DIR=/usr/include/eigen3 -DINSTALL_PREFIX=$HOME/slam_devel
make
```
