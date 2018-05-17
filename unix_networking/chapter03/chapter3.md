# 套接字编程简介


## preview 2.6.1 三次握手(P32)
- (1)服务器必须准备好接收外来的连接, 这通常通过调用socket, bind和listen这3个函数来完成, 我们称之为被动打开;
- (2)客户通过connect 主动打开, 同时发送一个SYN 分节, 他告诉服务器, 客户将在(待建立)连接中发送的数据的初始序列号, 通常SYN 分节不携带数据, 其所在IP数据报只含有一个IP首部, 一个TCP首部及可能有的TCP选项;
- (3)服务器必须确认(ACK)客户的SYN, 同时自己也要发送一个SYN分节, 
- (4)客户必须确认服务器的SYN 



## 4.1 概述

## 4.2 socket 函数

## 4.3 connect函数
1. 如果是TCP套接字, 调用connect函数将激发TCP的三路握手, 而且仅在连接建立成功或者出错时才返回; 其中出错可能有以下几种情况:
    - (1) 若TCP客户没有收到SYN分节的响应, 则返回ETIMEDOUT错误;
    - (2) 若客户的SYN的响应是RST(表示复位), 则表明该服务器主机在我们制定的端口上没有进程在等待与之相连, 客户一收到RST就马上返回ECONNREFUSED错误, 产生RST的三个条件:
    ~~~
        a. 目的地为某端口的SYN到达, 该端口没有正在监听的服务器;
        b. TCP想取消一个已有连接;
        c. TCP 收到一个根本不存在的连接上的分节;
    ~~~
    - (3) 若客户发出的SYN在中间的某个路由器上引发了一个"destination unreachable"的ICMP错误, 客户主机内核保存该消息, 并按第一种情况中所描述的时间间隔继续发送SYN, 若在某个规定的时间后仍未收到响应, 则把保存的消息作为 `EHOSTUNREACH`或`ENETUNREACH`错误;

2. 总结:
    - 若connect失败, 则该套接字不再可用, 必须关闭, 我们不能对这样的套接字再次调用connect函数, 在每次connect失败之后, 都必须close当前的套接字描述符并重新调用socket;

## 4.4 bind 函数
- bind函数把一个本地协议地址赋予一个套接字, 对于网际协议, 协议地址是32位的IPv4地址或128位的IPv6地址与16位的TCP或UDP端口号的组合;
- 进程捆绑非通配IP地址到套接字的常见例子是在为多个组织提供web服务器的主机上;
- 从bind函数返回的一个常见错误是EADDRINUSE("adress already in use");

## 4.5 listen 函数
~~~
#include<sys/socket.h>

int listen(int sockfd, int backlog)
~~~
- 仅由TCP服务器调用， 它做两件事
1. listen函数把一个未连接的套接字转换成一个被动套接字；
2. 第二个参数规定了内核应该为相应套接字排队的最大连接个数；
    - (1) 未完成连接队列， 每个这样的SYN分节对应其中的一项：已有某个客户发出并到达服务器， 而服务器正在等待完成相应的TCP三次握手过程， 这些套接字处于SYN_RCVD状态；
    - (2) 已完成连接队列， 每个已完成TCP三路握手的客户对应其中的一项， 这些套接字处于ESTABLISHED状态；

## 4.6 accept 函数
- 由TCP服务器调用， 从已完成连接队列发布会下一个已完成连接， 如果已完成连接队列已经为空， 那么进程被投入睡眠；
~~~
#include<sys/socket.h>

int accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen)

(1) cliaddr 和 addrlen 用来返回已连接的而对端进程
(客户)的协议地址；
(2) 如果accept返回成功， 那么其返回值是由内核自动生成的一个全新的描述符， 代表与所返回客户的TCP连接；
(3) 本函数最多返回三个值，如果我们对cliaddr， 或者addrlen置为空指针；
~~~

###### 4.6 to be continued