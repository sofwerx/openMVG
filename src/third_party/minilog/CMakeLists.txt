PROJECT (minilog CXX)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_LIBRARY (minilog STATIC minilog.h minilog.cpp)

INSTALL(TARGETS minilog DESTINATION lib EXPORT openMVG-targets)
