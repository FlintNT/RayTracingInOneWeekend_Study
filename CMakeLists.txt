cmake_minimum_required( VERSION 3.0.0 )

project ( RayTracingInOneWeekend 
    VERSION 0.1.0
    LANGUAGES CXX
)

# set to c++11
set ( CMAKE_CXX_STANDARD 11 )

# Source
set ( COMMON_ALL 
    src/common/vec3.h
    src/common/ray.h
)

set ( SOURCE_ONE_WEEKEND 
    ${COMMON_ALL}
    src/InOneWeekend/main.cpp
)

# Executables
add_executable(InOneWeekend ${SOURCE_ONE_WEEKEND})

include_directories(src/common)