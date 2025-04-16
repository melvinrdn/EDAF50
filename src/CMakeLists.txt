add_library(clientserver
    article.cc
    connection.cc
    memory_database.cc
    messagehandler.cc
    newsgroup.cc
    server.cc
)

target_include_directories(clientserver PUBLIC ${PROJECT_SOURCE_DIR}/include)
