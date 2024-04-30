add_library(util
  randomness.cpp
  grid.cpp
  timer.cpp
  vec.cpp
        multipliers.h
)

target_include_directories(util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
