SET(PROJECT_NAME vio_g2o)
PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.3)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMakeModules/")

ADD_DEFINITIONS(-DMONO) #enable compiling monocular related g2o edges and vertices

# Set build flags. Set IS_ARM on odroid board as environment variable
SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -D_LINUX -D_REENTRANT -march=native -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas")

IF(DEFINED ENV{ARM_ARCHITECTURE})
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon -march=armv7-a")
ELSE()
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmmx -msse -msse -msse2 -msse3 -mssse3")
ENDIF()

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -fsee -fomit-frame-pointer -fno-signed-zeros -fno-math-errno -funroll-loops")

# Add plain cmake packages 
FIND_PACKAGE(Eigen REQUIRED)
set(Sophus_INCLUDE_DIRS thirdparty/Sophus/)

FIND_PACKAGE(catkin REQUIRED COMPONENTS roscpp cmake_modules vio_common g2o_catkin)
catkin_package(
  DEPENDS Eigen
  CATKIN_DEPENDS roscpp
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
)

INCLUDE_DIRECTORIES(
  include
  ${Eigen_INCLUDE_DIRS}
  ${Sophus_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

LIST(APPEND SOURCEFILES 
src/anchored_points.cpp
src/IMU_constraint.cpp
src/scale_solver.cpp
include/vio_g2o/transformations.h
)

# Create library
ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCEFILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${catkin_LIBRARIES})

ADD_EXECUTABLE(densifyPoses src/apps/densifyPoses.cpp)
TARGET_LINK_LIBRARIES(densifyPoses ${PROJECT_NAME})

# Tests
IF(FALSE)
FIND_PACKAGE(OpenCV 2.4 REQUIRED)
MESSAGE ( STATUS "Found OpenCV: ${OpenCV_VERSION}" )
MESSAGE ( STATUS "OpenCV_INCLUDE_DIRS= ${OpenCV_INCLUDE_DIRS}" )

INCLUDE_DIRECTORIES(BEFORE ${OpenCV_INCLUDE_DIRS})
ADD_EXECUTABLE(test_IMU test/test_IMU.cpp) # this depends on cv::FileStorage
TARGET_LINK_LIBRARIES(test_IMU ${PROJECT_NAME} ${OpenCV_LIBS})
ENDIF()
