#ifndef TCPUTIL_H
#define TCPUTIL_H
#include <QTcpServer>
#include <QTcpSocket>
#include <c_systemlogmng.h>
class TcpUtil :public QObject
{
    Q_OBJECT
public:
    TcpUtil();
    void CreatTcpServer();
    void New_Connect();
    void Reivce();
    void Send(QByteArray buff);
    bool ConnectState;
private:
    QTcpSocket *com;
    QTcpServer *m_server;
    void ClientDisconnect();
signals:
    void signalResive(QByteArray);
};

#endif // TCPUTIL_H
