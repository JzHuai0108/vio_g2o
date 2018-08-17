vio_g2o

Depends on vio_common which depends on eigen and opencv, sophus

Build example
with g2o in ORB_SLAM2
```
cmake .. -DOpenCV_DIR=/opt/ros/kinetic/share/OpenCV-3.3.1 -DEIGEN_INCLUDE_DIR=/usr/include/eigen3 -DINSTALL_PREFIX=$HOME/slam_devel -DORBSLAM_G2O_PATH=../../../ORB_SLAM2/Thirdparty/g2o
make
```

with g2o from github, supposedly installed into slam_devel
```
cmake .. -DOpenCV_DIR=/opt/ros/kinetic/share/OpenCV-3.3.1 -DEIGEN_INCLUDE_DIR=/usr/include/eigen3 -DINSTALL_PREFIX=$HOME/slam_devel
make
```
