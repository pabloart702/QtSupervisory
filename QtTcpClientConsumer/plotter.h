#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QTimer>
#include <QVector>

/**
 * @brief The Plotter class É responsavel por desenhar os valores sorteados
 */
class Plotter : public QWidget
{
    Q_OBJECT
private:
    int *atl;
    QTimer *atual;
    QVector<int> valor;
public:
    /**
     * @brief Plotter Constroi um novo objeto plotter
     * @param parent O widget pai, passado por padrão com um ponteiro vazio
     */
    explicit Plotter(QWidget *parent = nullptr);

    /**
     * @brief paintEvent Evento de pintura para desenhar os valores no gráfico
     * @param event O evento de pintura
     */
    void paintEvent(QPaintEvent *event);
public slots:
    /**
     * @brief setValor Define um valor a ser plotado
     * @param _valor O valor sorteado
     */
    void setValor(int _valor);
signals:

};

#endif // PLOTTER_H
