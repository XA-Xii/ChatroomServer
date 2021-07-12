# ChatroomServer
# 基于C++ muduo网络库的集群聊天室服务器

使用nginx的tcp负载均衡器配置，基于发布订阅的服务器中间件redis进行消息的存储及获取。

nginx负载均衡器的配置：

```
stream {
        upstream Myserver {

                server 127.0.0.1:6000 weight=1 max_fails=3 fail_timeout=30s;
                server 127.0.0.1:6002 weight=1 max_fails=3 fail_timeout=30s;

        }

        server {
                proxy_connect_timeout 1s;
                listen 8000;
                proxy_pass MyServer;
                tcp_nodelay on;
        }
}


```

部分功能的测试：
