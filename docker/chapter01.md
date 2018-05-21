# Using Docker

## 第三章

### 3.1
1. 请求docker提供一个容器中的shell
~~~
    docker run -i -t debian /bin/bash
~~~

### 3.2 基本命令
1. 启动容器
~~~
    docker run -n CONTAINER -i -t debian /bin/bash
    -h 用来指定一个新的主机名
~~~

2. 容器信息
~~~
获取所有容器基本信息
    (1). docker ps （查看容器信息， 包括容器names）
获取单个容器详细信息
    (2). docker inspect (容器names)
获取容器改动情况
    (3). docker diff (容器names)
获取容器ip地址
    docker inspect (容器names) | grep IPAddress
~~~
