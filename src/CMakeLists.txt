add_executable(strac
    main/globals.cpp
    main/CommandHandler.cpp 
    main/commands/init.cpp
    main/commands/new_branch.cpp
    main/util/util.cpp)

target_include_directories(strac
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/commands)