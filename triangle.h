#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "trianglesingleton.h"
#include <QColor>
#include <QDeclarativeItem>

class QmlTriangle : public QDeclarativeItem
{
    Q_OBJECT
public:
    QmlTriangle(QDeclarativeItem* parent = 0);
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)
    QColor getColor() const;
    void setColor(QColor newColor);
signals:
    void colorChanged();
private slots:
    void updateSingletonGeometry();
    void updateSingletonX();
    void updateSingletonY();
private:
    TriangleSingleton* internalTriangle;
};
#endif // TRIANGLE_H
