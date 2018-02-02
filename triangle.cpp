#include "triangle.h"

QmlTriangle::QmlTriangle(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    internalTriangle = TriangleSingleton::getInstance();
    connect(this, SIGNAL(heightChanged()), this, SLOT(updateSingletonGeometry()));
    connect(this, SIGNAL(widthChanged()), this, SLOT(updateSingletonGeometry()));
    connect(this, SIGNAL(xChanged()), this, SLOT(updateSingletonX()));
    connect(this, SIGNAL(yChanged()), this, SLOT(updateSingletonY()));
}

QColor QmlTriangle::getColor() const
{
    return internalTriangle->getColor();
}

void QmlTriangle::setColor(QColor newColor)
{
    internalTriangle->setColor(newColor);
    emit colorChanged();
}

void QmlTriangle::updateSingletonGeometry()
{
    internalTriangle->setGeometry(width(), height());
}

void QmlTriangle::updateSingletonX()
{
    internalTriangle->setX(x());
}

void QmlTriangle::updateSingletonY()
{
    internalTriangle->setY(y());
}
