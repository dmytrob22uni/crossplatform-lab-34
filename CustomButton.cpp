#include "CustomButton.h"
#include <QMouseEvent>
#include <QPainter>

CustomButton::CustomButton(const QString &text, QWidget *parent)
  : QWidget(parent),
  m_text(text)
{
  setMinimumSize(100, 35);
  setCursor(Qt::PointingHandCursor);
}

void CustomButton::setText(const QString &text)
{
  m_text = text;
  update();
}

void CustomButton::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // color based on state
  QColor bgColor = QColor(53, 132, 228); // default blue
  if (m_isPressed)
  {
    bgColor = QColor(26, 95, 180); // darker on pressed
  }
  else if (m_isHovered)
  {
    bgColor = QColor(98, 160, 234); // lighter on hover
  }

  // background
  painter.setPen(Qt::NoPen);
  painter.setBrush(bgColor);
  painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 6, 6);

  // text label
  painter.setPen(Qt::white);
  painter.setFont(QFont("Sans Serif", 10, QFont::Bold));
  painter.drawText(rect(), Qt::AlignCenter, m_text);
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    m_isPressed = true;
    update();
  }
}

void CustomButton::mouseReleaseEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton && m_isPressed)
  {
    m_isPressed = false;
    update();
    if (rect().contains(event->pos()))
    {
      emit clicked();
    }
  }
}

void CustomButton::enterEvent(QEnterEvent *)
{
  m_isHovered = true;
  update();
}

void CustomButton::leaveEvent(QEvent *)
{
  m_isHovered = false;
  m_isPressed = false;
  update();
}
