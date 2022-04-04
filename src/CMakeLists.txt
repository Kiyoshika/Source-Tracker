add_executable(strac 
    main/CommandHandler.cpp 
    main/commands/init.cpp
    main/util/filepaths/filepaths.cpp)

target_include_directories(strac
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include/util
    ${CMAKE_SOURCE_DIR}/include/commands)