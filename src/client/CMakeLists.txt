#记录源文件路径
aux_source_directory(. SRC_LIST)

#指定生成可执行文件
add_executable(ChatClient ${SRC_LIST})
#可执行文件链接时所需要的库文件
target_link_libraries(ChatClient pthread)