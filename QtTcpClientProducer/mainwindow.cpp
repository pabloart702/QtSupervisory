#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimerEvent>

/**
 * @brief MainWindow::MainWindow Constroi um novo MainWindow
 * @param parent O widget pai, passado por padrão com um ponteiro vazio
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(ui->connect,
            SIGNAL(clicked()),
            this,
            SLOT(on_connect_clicked())
            );
    connect(ui->disconnect,
            SIGNAL(clicked()),
            this,
            SLOT(on_disconnect_clicked())
            );
    connect(ui->start,
            SIGNAL(clicked()),
            this,
            SLOT(start_temp())
            );
    connect(ui->stop,
            SIGNAL(clicked()),
            this,
            SLOT(stop_temp())
            );
}




/**
 * @brief MainWindow::~MainWindow Destrutor da classe MainWindow
 * deleta o socket e a interface do usuario
 */
MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}

/**
 * @brief MainWindow::tcpConnect Realiza  a conexão com o server
 */

void MainWindow::tcpConnect(){
    socket->connectToHost(ui->ip->text(),1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        ui->status->setText("Conectado");
    }
    else{
        qDebug() << "Disconnected";
    }
}

/**
 * @brief MainWindow::start_temp Inicializa a contagem do tempo
 * pegando o valor do slider e colocando como parametro para gerar
 * os dados com esse intervalo fornecido pelo slider
 */

void MainWindow::start_temp(){
    int timerSeg = 1000*ui->sliderTimer->value();
    temp = startTimer(timerSeg);
    ui->status2->setText("Start");
}

/**
 * @brief MainWindow::stop_temp Mata o temporizador
 */

void MainWindow::stop_temp(){
    killTimer(temp);
    ui->status2->setText("Stop");
}

/**
 * @brief MainWindow::putData Sorteia um valor entre o min e o max definido pelos sliders,
 * concatena em um string e
 */

void MainWindow::putData(){
    QDateTime datetime;
    QString str;
    qint64 msecdate;

    int vmin = ui->minimo->value();
    int vmax = ui->maximo->value();

    if(socket->state()== QAbstractSocket::ConnectedState){

        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch(); //GERE O NUMERO
        str = "set "+ QString::number(msecdate) + " " +  QString::number(vmin + rand()% (vmax - vmin))+"\r\n"; //CONCATENTE

        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str())
                 << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
        }
        ui->tabela->append(str); //ADC NA TABELA
    }
}

/**
 * @brief MainWindow::timerEvent Manipulador de eventos do temporizador
 * @param event O widget pai, passado por padrão com um ponteiro vazio
 */
void MainWindow::timerEvent(QTimerEvent *event){
    putData();
}

/**
 * @brief MainWindow::on_connect_clicked Manipulador do click do botão connect
 */
void MainWindow::on_connect_clicked()
{
    tcpConnect();
}

/**
 * @brief MainWindow::on_disconnect_clicked Manipulador do click do botão desconnect
 */
void MainWindow::on_disconnect_clicked(){
    socket->disconnectFromHost();
    ui->status->setText("Desconectado");
}

/**
 * @brief MainWindow::on_sliderMin_valueChanged Manipulador da mudança do valor do slider Min
 * @param value O valor do slider atual que representa o valor minimo
 */
void MainWindow::on_sliderMin_valueChanged(int value)
{
    ui->minimo->display(value);
}

/**
 * @brief MainWindow::on_sliderMin_valueChanged Manipulador da mudança do valor do slider Max
 * @param value O valor do slider atual que representa o valor maximo
 */
void MainWindow::on_sliderMax_valueChanged(int value)
{
    ui->maximo->display(value);
}

/**
 * @brief MainWindow::on_sliderMin_valueChanged Manipulador da mudança do valor do slider temp
 * @param value O valor do slider atual que representa o valor temporizador
 */
void MainWindow::on_sliderTimer_valueChanged(int value)
{
    ui->intervalTimer->setText(QString::number(value));
}






