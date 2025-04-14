add_executable(news_server news_server.cc)
target_link_libraries(news_server clientserver)

add_executable(news_client news_client.cc)
target_link_libraries(news_client clientserver)

target_include_directories(news_server PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(news_client PRIVATE ${PROJECT_SOURCE_DIR}/include)
