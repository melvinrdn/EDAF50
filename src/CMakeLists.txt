add_library(clientserver
    connection.cc
    memory_database.cc
    disk_database.cc
    messagehandler.cc
    newsgroup.cc
    server.cc
)

target_include_directories(clientserver PUBLIC ${PROJECT_SOURCE_DIR}/include)
