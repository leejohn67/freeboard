#ifndef UBSHAPEFACTORY_H
#define UBSHAPEFACTORY_H

#include <QObject>
#include <QColor>
#include <QGraphicsItem>

class UBShape;
class UBBoardView;
class QMouseEvent;
class UBDrawingController;

class UBShapeFactory : public QObject
{
    Q_OBJECT

public:
    UBShapeFactory();
    void init();

    static bool isShape(QGraphicsItem *item);
    static void desactivateEditionMode(QGraphicsItem *item);
    static bool isInEditMode(QGraphicsItem *item);

    enum ShapeType
    {
        Ellipse,
        Circle,
        Rectangle,
        Square,
        Line,
        Pen,
        RegularPolygon,
        Polygon,
        None
    };

    enum FillType
    {
        Transparent,
        Full,
        Dense,
        Diag,
        Gradient
    };

    QColor strokeColor();
    QColor fillFirstColor();
    QColor fillSecondColor();

    void setFillingStyle(Qt::BrushStyle brushStyle);
    void setFillingFirstColor(QColor color);
    void setFillingSecondColor(QColor color);
    void setGradientFillingProperty(UBShape* shape);
    void updateFillingPropertyOnSelectedItems();

    FillType fillType();
    void setFillType(FillType fillType);

    QRectF reverseRect(const QRectF &rect);

public slots:
    void createRegularPolygon(int nVertices);
    void createEllipse(bool create);
    void createPolygon(bool create);
    void createCircle(bool create);
    void createRectangle(bool create);
    void createSquare(bool create);
    void createLine(bool create);

    void createPen(bool create);    

    void prepareChangeFill();
    void changeFillColor(const QPointF& pos);

    void onMouseMove(QMouseEvent *event);
    void onMousePress(QMouseEvent *event);
    void onMouseRelease(QMouseEvent *event);

    void desactivate();
    void terminateShape();

    void setStrokeStyle(Qt::PenStyle penStyle);
    void setStrokeColor(QColor color);

    void setThickness(int thickness);


private:
    UBShape* mCurrentShape;
    UBBoardView* mBoardView;

    bool mIsCreating;
    bool mIsPress;
    bool mIsRegularShape;

    bool mFirstClickForFreeHand;

    ShapeType mShapeType;

    QColor mCurrentStrokeColor;
    QColor mCurrentFillFirstColor;
    QColor mCurrentFillSecondColor;

    Qt::BrushStyle mCurrentBrushStyle;
    Qt::PenStyle mCurrentPenStyle;

    int mThickness;
    UBDrawingController *mDrawingController;

    int mNVertices;

    FillType mFillType;
    QRectF mBoundingRect;

    bool mCursorMoved;

protected:
    UBShape *instanciateCurrentShape();

};

#endif // UBSHAPEFACTORY_H
