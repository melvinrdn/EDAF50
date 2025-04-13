# Helper macro to create executables with the right settings
macro(add_program TARGETNAME)
  add_executable(${TARGETNAME} ${ARGN})

  target_compile_options(${TARGETNAME}
    PRIVATE
      ${clientserver_sanitizer_options}
  )

  target_compile_definitions(${TARGETNAME}
    PRIVATE
      ${clientserver_config_defines}
  )

  target_include_directories(${TARGETNAME}
    PUBLIC
      ${clientserver_public_include_dirs}
    PRIVATE
      ${clientserver_private_include_dirs}
  )

  target_link_libraries(${TARGETNAME}
    PUBLIC
      clientserver
    PRIVATE
      ${clientserver_sanitizer_options}
  )
endmacro()

# Add client and server
add_program(news_server news_server.cc)
add_program(news_client news_client.cc)

install(TARGETS news_server news_client)
