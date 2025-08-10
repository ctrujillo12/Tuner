cmake_minimum_required(VERSION 3.16.0)

# Tell ESP-IDF where your extra components are (before including project.cmake)
set(EXTRA_COMPONENT_DIRS ${CMAKE_SOURCE_DIR}/components/esp-dsp)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(ESP32_test)
