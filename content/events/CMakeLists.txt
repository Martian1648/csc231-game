add_library(events
  updatefov.cpp
        hit.cpp
        die.cpp
        swing.cpp
        lightning.cpp
        thrust.cpp
        sound.cpp
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
