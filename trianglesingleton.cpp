#include "trianglesingleton.h"
#include <QPen>

TriangleSingleton* TriangleSingleton::m_instance = 0;

TriangleSingleton::TriangleSingleton() :
    m_polyItem(0),
    m_color(0,0,0),
    m_width(0),
    m_height(0),
    m_x(0),
    m_y(0)
{
}

TriangleSingleton* TriangleSingleton::getInstance()
{
    if (!m_instance)
        m_instance = new TriangleSingleton();
    return m_instance;
}

void TriangleSingleton::setPolyItem(QGraphicsPolygonItem *itemToUse)
{
    if (!m_polyItem) {
        m_polyItem = itemToUse;
        setPolygonColor();
        m_polyItem->setX(m_x);
        m_polyItem->setY(m_y);
        setPolygonFromWidthAndHeight();
    }
}

QColor TriangleSingleton::getColor() const
{
    return m_color;
}

void TriangleSingleton::setPolygonColor()
{
    if (m_polyItem)
        m_polyItem->setPen(QPen(m_color));
}

void TriangleSingleton::setColor(QColor newColor)
{
    m_color = newColor;
        setPolygonColor();
}

void TriangleSingleton::setPolygonFromWidthAndHeight()
{
    if (m_polyItem) {
        QVector<QPointF> polyPoints;
        polyPoints.append(QPointF(0,0));
        polyPoints.append(QPointF(m_width,m_height));
        polyPoints.append(QPointF(0,m_height));
        m_polyItem->setPolygon(QPolygonF(polyPoints));
    }
}

void TriangleSingleton::setGeometry(int width, int height)
{
    m_width = width;
    m_height = height;
    setPolygonFromWidthAndHeight();
}

void TriangleSingleton::setX(qreal newX)
{
    m_x = newX;
    if (m_polyItem)
        m_polyItem->setX(m_x);
}

void TriangleSingleton::setY(qreal newY)
{
    m_y = newY;
    if (m_polyItem)
        m_polyItem->setY(m_y);
}
