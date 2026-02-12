cmake_minimum_required(VERSION 3.16)
project(mon_projet CXX)

# Ajouter ModbusLib
add_subdirectory(external/ModbusLib)

# Créer ton exécutable
add_executable(exec src/motor_control/main.cpp)

# Ajouter le dossier des headers de ModbusLib
target_include_directories(exec PRIVATE
    ${CMAKE_SOURCE_DIR}/external/ModbusLib/src
)

# Linker avec la lib modbus
target_link_libraries(exec PRIVATE modbus)
