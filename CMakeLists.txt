cmake_minimum_required(VERSION 3.16.0)

set(EXTRA_COMPONENT_DIRS ${CMAKE_SOURCE_DIR}/components/esp-dsp)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(ESP32_test)
