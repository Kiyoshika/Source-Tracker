add_executable(strac
    # globals
    main/globals.cpp
    # command handler
    main/CommandHandler.cpp 
    main/commands/init.cpp
    # branches
    main/commands/new_branch.cpp
    main/commands/delete_branch.cpp
    # util
    main/util/util.cpp)

target_include_directories(strac
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/commands)