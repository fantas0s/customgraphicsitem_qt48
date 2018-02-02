#ifndef TRIANGLESINGLETON_H
#define TRIANGLESINGLETON_H
#include <QObject>
#include <QColor>
#include <QGraphicsPolygonItem>

class TriangleSingleton : public QObject
{
    Q_OBJECT
public:
    static TriangleSingleton* getInstance();
    void setPolyItem(QGraphicsPolygonItem* itemToUse);
    QColor getColor() const;
    void setColor(QColor newColor);
    void setGeometry(int width, int height);
    void setX(qreal newX);
    void setY(qreal newY);
signals:
    void colorChanged();
private:
    TriangleSingleton();
    static TriangleSingleton* m_instance;
    QGraphicsPolygonItem* m_polyItem;
    QColor m_color;
    int m_width;
    int m_height;
    qreal m_x;
    qreal m_y;
    void setPolygonFromWidthAndHeight();
    void setPolygonColor();
};
#endif // TRIANGLESINGLETON_H
