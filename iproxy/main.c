//
//  main.c
//  iproxy
//
//  Created by noprom on 12/13/15.
//  Copyright © 2015 tyee.noprom@qq.com. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

/**
 * 监听端口
 */
void listen_port(char* port) {
    int status;
    struct addrinfo hints;
    struct addrinfo *serviceinfo; // will point to the results
    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    
    hints.ai_family = AF_UNSPEC; // 这里设置为“不指定”,意思是 IPv4 或者 IPv6 都行
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets,意思是要筛选流式的 sockets, 其他类型的不要出现在 res 中
    hints.ai_flags = AI_PASSIVE; // 自动帮我把我的 IP 填入 res 的 IP 地址成员中
    if ((status = getaddrinfo(NULL, port, &hints, &serviceinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }
// 如果程序能运行到这行,说明 serviceinfo 现在就会指向一个拥有 1 个或者更多 struct addrinfo 类型的节点的链表
// ...你可以开始利用得到的 serviceinfo 中的节点的信息做点有意义的事情了!
    freeaddrinfo(serviceinfo); // 释放链表
}