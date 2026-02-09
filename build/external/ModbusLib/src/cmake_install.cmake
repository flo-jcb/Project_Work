# Install script for directory: /home/flo_virt/projet/external/ModbusLib/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/flo_virt/projet/build/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./lib" TYPE SHARED_LIBRARY FILES
    "/home/flo_virt/projet/build/libmodbus.so.0.4.9"
    "/home/flo_virt/projet/build/libmodbus.so.0"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./lib/libmodbus.so.0.4.9"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./lib/libmodbus.so.0"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./lib" TYPE SHARED_LIBRARY FILES "/home/flo_virt/projet/build/libmodbus.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./include/modbus" TYPE FILE FILES
    "/home/flo_virt/projet/external/ModbusLib/src/Modbus_config.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusPlatform.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusGlobal.h"
    "/home/flo_virt/projet/external/ModbusLib/src/Modbus.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusObject.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusSerialPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusRtuPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusAscPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusTcpPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusClient.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusClientPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusServerResource.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusServerPort.h"
    "/home/flo_virt/projet/external/ModbusLib/src/ModbusTcpServer.h"
    "/home/flo_virt/projet/external/ModbusLib/src/cModbus.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/flo_virt/projet/build/external/ModbusLib/src/CMakeFiles/modbus.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

