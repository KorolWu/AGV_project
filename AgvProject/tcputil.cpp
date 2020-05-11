#include "tcputil.h"

TcpUtil::TcpUtil()
{
    com = nullptr;
    m_server = nullptr;
    ConnectState = false;
}

void TcpUtil::CreatTcpServer()
{
    if(m_server == NULL)
    {
        m_server = new QTcpServer();
        m_server->listen(QHostAddress::Any,8888);
        connect(m_server,&QTcpServer::newConnection,this,&TcpUtil::New_Connect);   //有新链接过来
    }
}

void TcpUtil::New_Connect()
{
    com = m_server->nextPendingConnection();
    GetSystemLogObj()->writeLog("new connect is come in!",0);

    if(com != NULL)
    {
         connect(com,&QTcpSocket::readyRead,this,&TcpUtil::Reivce);
         connect(com,&QTcpSocket::disconnected,this,&TcpUtil::ClientDisconnect);
         ConnectState = true;
    }
}

void TcpUtil::Reivce()
{
    QByteArray buff = com->readAll();
     GetSystemLogObj()->writeLog(QString(buff),0);
    emit signalResive(buff);
}

void TcpUtil::Send(QByteArray buff)
{
     if(com != nullptr)
         com->write(buff);
}

void TcpUtil::ClientDisconnect()
{
    GetSystemLogObj()->writeLog("Client disconnect!",0);
    ConnectState = false;
}
