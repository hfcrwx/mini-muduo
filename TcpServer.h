//author voidccc
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <sys/epoll.h>

#include "Declare.h"
#include "Define.h"
#include "IChannelCallBack.h"

#include <map>

using namespace std;

class TcpServer : public IChannelCallBack
{
    public:
        TcpServer();
        ~TcpServer();
        void start();
        virtual void OnIn(int sockfd);
    private:
        int createAndListen();

        int _epollfd;
        int _listenfd;
        struct epoll_event _events[MAX_EVENTS];
};

#endif
