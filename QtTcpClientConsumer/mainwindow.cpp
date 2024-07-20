#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QString>

/**
 * @brief MainWindow::MainWindow Constroi um novo objeto MainWindow
 * @param parent O widget pai, passado por padrão com um ponteiro vazio
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(intervalT);
    socket = new QTcpSocket(this);

    connect(ui->startButton,
            SIGNAL(clicked()),
            this,
            SLOT(getData()));

    connect(ui->stopButton,
            SIGNAL(clicked()),
            this,
            SLOT(stopTimer()));

    connect(ui->connectButton,
            SIGNAL(clicked()),
            SLOT(tcpConnect()));

    connect(ui->disconnectButton,
            SIGNAL(clicked()),
            SLOT(tcpDisconnect()));

    connect(ui->horizontalSlider_Timing,
            SIGNAL(valueChanged(int)),
            ui->intervalTimer,
            SLOT(setNum(int)));

    connect(ui->updateButton,
            SIGNAL(clicked()),
            this,
            SLOT(updateIp()));

    connect(ui->horizontalSlider_Timing,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(valorInterv(int)));

    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(timerEvent()));

    connect(ui->startButton,
            SIGNAL(clicked()),
            this,
            SLOT(startButton()));

    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(startButton()));
}

/**
 * @brief MainWindow::~MainWindow Destrutor do objeto MainWindow
 * deleta o socket e a interface do usuario
 */
MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}

/**
 * @brief MainWindow::tcpConnect Estabelece a conexão tcp com o server
 */
void MainWindow::tcpConnect(){
    socket->connectToHost(ui->ipServer->text(),1234);

    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        statusBar()->showMessage("Connected");
    }
    else{
        qDebug() << "Disconnected";
        statusBar()->showMessage("Disconnected");
    }
}

/**
 * @brief MainWindow::tcpDisconnect Desconecta a conexão tcp com o server
 */
void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
    statusBar()->showMessage("Disconnected");
}

/**
 * @brief MainWindow::getData Recupera os dados do servidor
 */
void MainWindow::getData(){
    timer->start();
    QString str;
    QByteArray array;
    QStringList list;
    qint64 thetime;

    qDebug() << "to get data...";
    QHostAddress ipAddress = socket->peerAddress();
    QString ipString = ipAddress.toString();

    if(ipList.contains(ipString)){

    }else{

        ipList.append(ipString);

    }
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            QStringList teste;
            teste << "get" << ipString << "5";
            QString command = teste.join(' ');
            socket->write(command.toUtf8());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");

                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    qDebug() << thetime << ": " << str;
                }
                value = list.at(1).toInt();
                qDebug() << value << "\n";

            }
        }
    }
}

/**
 * @brief MainWindow::updateIp Atualiza os endereços Ip disponiveis para a conexão
 */
void MainWindow::updateIp(){
    ui->listMaquinas->clear();
    ui->listMaquinas->addItems(ipList);
}

/**
 * @brief MainWindow::startButton Lida com o evento de clique do botão start
 */
void MainWindow::startButton(){
    ui->widget->setValor(value);
}

/**
 * @brief MainWindow::stopTimer Para o temporizador
 */
void MainWindow::stopTimer(){
    qDebug() << "reading...";
    timer->stop();
}

/**
 * @brief MainWindow::intervalTimer Define o intervalo para o temporizador
 * @param interval O tempode intervalo em milissegundos
 */
void MainWindow::intervalTimer(int interval){
    intervalT = interval*1000;
    timer->setInterval(intervalT);
}

/**
 * @brief MainWindow::timerEvent Manipular de eventos para os eventos
 */
void MainWindow::timerEvent(){
    getData();
}



