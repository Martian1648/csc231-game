add_library(items
  bite.cpp
        sword.cpp
        spear.cpp
        mace.cpp
        hammer_big.cpp
        cleaver.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
