//author voidccc
#ifndef CHANNEL_H
#define CHANNEL_H

#include "Declare.h"

class Channel
{
    public:
        Channel(int epollfd, int sockfd);
        ~Channel();
        void setCallBack(IChannelCallBack* callBack);
        void handleEvent();
        void setRevents(int revent);
        int getSockfd();
        void enableReading();
    private:
        void update();
        int _epollfd;
        int _sockfd;
        int _events;
        int _revents;
        IChannelCallBack* _callBack;
};

#endif
