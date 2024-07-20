#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QWidget>
#include <QTimer>
#include <QString>

namespace Ui {
    class MainWindow;
}

/**
 * @brief The MainWindow class Fornece a interface principal para a apliação
 * do cliente consumidor
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief MainWindow Constroi um novo objeto MainWindow
     * @param parent O widget pai, passado por padrão com um ponteiro vazio
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     *  @brief Destrutor do objeto MainWindow
     */
    ~MainWindow();


public slots:

    /**
     * @brief getData Recupera dados do server
     */
    void getData();
    /**
     * @brief tcpConnect Estabelece a conexão tcp
     */
    void tcpConnect();
    /**
     * @brief tcpDisconnect Desconecta a conexão tcp
     */
    void tcpDisconnect();

    /**
     * @brief updateIp Atualiza os endereços Ip disponiveis para a conexão
     */
    void updateIp();
    /**
     * @brief startButton Lida com o evento de clique do botão start
     */
    void startButton();
    /**
     * @brief stopTimer Para o temporizador
     */
    void stopTimer();
    /**
     * @brief intervalTimer Define o intervalo para o temporizador
     * @param interval O tempode intervalo em milissegundos
     */
    void intervalTimer(int interval);

    /**
     * @brief timerEvent Manipulador de eventos para os eventos
     */
    void timerEvent();


private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStringList ipList;
    QTimer *timer;

    int intervalT = 1000;
    int value;


};

#endif // MAINWINDOW_H
