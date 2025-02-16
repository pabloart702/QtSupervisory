#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <iostream>
#include <QLine>

/**
 * @brief Plotter::Plotter Constroi um novo objeto plotter
 * @param parent O widget pai, passado por padrão com um ponteiro vazio
 */
Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    atl = new int;
}

/**
 * @brief Plotter::paintEvent Evento de pintura para desenhar os valores no grafico
 * @param event O evento de pintura
 */
void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    int x1, y1, x2, y2;
    brush.setColor(QColor(250,250,10));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(20,150,250));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(), height());

    pen.setColor(QColor(25,6,90));

    int width = this->width();
    int height = this->height();

    double xScale = (width) / (31);
    double yScale = (height) / (100);

    x1 = 0;
    y1 = height;

    for(int i = 0; i< valor.size(); i++){
        x2 = i * xScale;
        y2 = height - valor.at(i)*yScale;

        QPointF p1(x1, y1);
        QPointF p2(x2,y2);
        painter.drawLine(p1, p2);

        x1 = x2;
        y1 = y2;
        if(valor.size() >= 34){
            valor.erase(valor.begin());
        }
    }

}

/**
 * @brief Plotter::setValor Define um novo valor a ser plotado
 * @param _valor O valor sorteado
 */

void Plotter::setValor(int _valor)
{
    valor.append(_valor);
    repaint();
}





















