//author voidccc
#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "Declear.h"
#include "IChannelCallback.h"

#include <string>
using namespace std;

class TcpConnection : public IChannelCallback
{
    public:
        TcpConnection(int sockfd, EventLoop* pLoop);
        ~TcpConnection();
        void send(const string& message);
        void connectEstablished();
        void setUser(IMuduoUser* pUser);

        void virtual handleRead();
        void virtual handleWrite();
    private:
        int _sockfd;
        Channel* _pChannel;
        EventLoop* _pLoop;
        IMuduoUser* _pUser;
        string* _inBuf;
        string* _outBuf;
};

#endif
