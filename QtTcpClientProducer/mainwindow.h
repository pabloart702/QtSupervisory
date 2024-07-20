#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimerEvent>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class A classe MainWIndow é responsavel por gerenciar a interface do
 * cliente produtor
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow Constroi um novo objeto MainWindow
     * @param parent O widget pai, passado por padrão com um ponteiro vazio
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * Destrutor do objeto MainWindow
     */
    ~MainWindow();

    /**
     * @brief tcpConnect Estabelece a conexão tcp com o server
     */
    void tcpConnect();

public slots:

    /**
     * @brief start_temp Inicia o temporizador
     */
    void start_temp();

    /**
     * @brief stop_temp Finaliza o temporizador
     */
    void stop_temp();

    /**
     * @brief putData Envia os dados para o servidor
     */
    void putData();

    /**
     * @brief timerEvent Manipulador de eventos do temporizador
     * @param event O evento de temporizador
     */
    void timerEvent(QTimerEvent *event);

private slots:

    /**
     * @brief on_connect_clicked Manipulador do click do botão connect
     */
    void on_connect_clicked();
    /**
     * @brief on_disconnect_clicked Manipulador do click do botão desconnect
     */
    void on_disconnect_clicked();

    /**
     * @brief on_sliderMin_valueChanged Manipulador da mudança do valor do slider Min
     * @param value O valor do slider atual que representa o valor minimo
     */
    void on_sliderMin_valueChanged(int value);

    /**
     * @brief on_sliderMax_valueChanged Manipulador da mudança do valor do slider Max
     * @param value O valor do slider atual que representa o valor maximo
     */
    void on_sliderMax_valueChanged(int value);

    /**
     * @brief on_sliderTimer_valueChanged Manipulador da mudança do valor do slider Tempo
     * @param value O valor do slider atual que representa o valor do temporizador
     */
    void on_sliderTimer_valueChanged(int value);


private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    int temp;
};

#endif // MAINWINDOW_H
