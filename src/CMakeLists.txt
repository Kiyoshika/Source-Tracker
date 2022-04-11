add_executable(strac
    # globals
    main/globals.cpp
    # command handler
    main/CommandHandler.cpp 
    # commands
    main/commands/init.cpp
    main/commands/new_branch.cpp
    main/commands/delete_branch.cpp
    main/commands/branches.cpp
    main/commands/switch.cpp
    # util
    main/util/util.cpp)

target_include_directories(strac
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/commands)