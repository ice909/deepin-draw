#include "canvaswidget.h"

#include <QHBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

#include <cmath>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QLabel(parent)
    , m_scaleValue(1)
{
//   setStyleSheet("border: 1px solid rgba(0, 0, 0, 30);");

    m_shapesWidget = new ShapesWidget(this);
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_shapesWidget);
    setLayout(layout);

    connect(this, &CanvasWidget::drawShapeChanged, m_shapesWidget,
            &ShapesWidget::setCurrentShape);
    connect(this, &CanvasWidget::fillShapeSelectedActive, m_shapesWidget,
            &ShapesWidget::setFillShapeSelectedActive);
    connect(this, &CanvasWidget::rotateImage,
            m_shapesWidget,  &ShapesWidget::handleImageRotate);
    connect(this, &CanvasWidget::mirroredImage,
            m_shapesWidget, &ShapesWidget::mirroredImage);

//    connect(this, &CanvasWidget::saveImage,
//            m_view, &ImageView::saveImage);

    connect(m_shapesWidget, &ShapesWidget::updateMiddleWidgets,
            this, &CanvasWidget::updateMiddleWidget);
    connect(m_shapesWidget, &ShapesWidget::adjustArtBoardSize,
            this, &CanvasWidget::adjustArtBoardSize);
}

CanvasWidget::~CanvasWidget()
{
}
