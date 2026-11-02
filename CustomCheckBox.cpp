#include "CustomCheckBox.h"
#include <QMouseEvent>
#include <QPainter>

CustomCheckBox::CustomCheckBox(const QString &text, QWidget *parent)
  : QWidget(parent),
  m_text(text),
  m_state(Unchecked),
  m_parentBox(nullptr)
{
  setMinimumSize(200, 25);
  setCursor(Qt::PointingHandCursor);
}

CustomCheckBox::State CustomCheckBox::state() const
{
  return m_state;
}

void CustomCheckBox::setState(State newState)
{
  setCheckStateDown(newState);
  if (m_parentBox)
  {
    m_parentBox->updateStateUp();
  }
}

void CustomCheckBox::setCheckStateDown(State newState)
{
  if (m_state != newState)
  {
    m_state = newState;
    update();
    emit stateChanged(m_state);
  }
  // PartiallyChecked means update up only
  if (newState == Checked || newState == Unchecked)
  {
    for (auto *child : m_children)
    {
      child->setCheckStateDown(newState);
    }
  }
}

void CustomCheckBox::updateStateUp()
{
  if (m_children.isEmpty())
  {
    return;
  }

  int checkedCount = 0;
  int uncheckedCount = 0;

  // count (un-)checked
  for (auto *child : m_children)
  {
    if (child->state() == Checked)
    {
      checkedCount++;
    }
    else if (child->state() == Unchecked)
    {
      uncheckedCount++;
    }
  }

  // decide state (thus icon)
  State calcState = PartiallyChecked;
  if (checkedCount == m_children.size())
  {
    calcState = Checked;
  }
  else if (uncheckedCount == m_children.size())
  {
    calcState = Unchecked;
  }

  // any reason to update
  if (m_state != calcState)
  {
    m_state = calcState;
    update();
    emit stateChanged(m_state);
  }

  // is child itself
  if (m_parentBox)
  {
    m_parentBox->updateStateUp();
  }
}

void CustomCheckBox::addChild(CustomCheckBox *child)
{
  if (child)
  {
    child->m_parentBox = this;
    m_children.append(child);
    updateStateUp();
  }
}

void CustomCheckBox::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    State nextState = (m_state == Checked) ? Unchecked : Checked;
    setState(nextState);
  }
}

void CustomCheckBox::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // respects setContentsMargins()
  QRect cRect = contentsRect();

  // draw box
  QRect boxRect(
    cRect.left(),
    cRect.top() + (cRect.height() - 16) / 2,
    16,
    16);
  painter.setPen(
    QPen(
      QColor(119, 118, 123),
      1.5));
  painter.setBrush(Qt::white);
  painter.drawRoundedRect(boxRect, 3, 3);

  // draw icons
  if (m_state == Checked)
  {
    // pen setup
    painter.setPen(
      QPen(
        QColor(53, 132, 228),
        2.5,
        Qt::SolidLine,
        Qt::RoundCap));
    // short downward stroke (left side)
    painter.drawLine(
      boxRect.left() + 3,
      boxRect.center().y(),
      boxRect.center().x() - 1,
      boxRect.bottom() - 3);
    // long upward stroke (right side)
    painter.drawLine(
      boxRect.center().x() - 1,
      boxRect.bottom() - 3,
      boxRect.right() - 2,
      boxRect.top() + 3);
  }
  else if (m_state == PartiallyChecked)
  {
    // pen setup
    painter.setPen(
      QPen(
        QColor(53, 132, 228),
        2.5,
        Qt::SolidLine,
        Qt::RoundCap));
    // horizontal straight line
    painter.drawLine(
      boxRect.left() + 4,
      boxRect.center().y(),
      boxRect.right() - 4,
      boxRect.center().y());
  }

  // draw text
  QRect textRect(
    boxRect.right() + 8,
    cRect.top(),
    cRect.width() - 24,
    cRect.height());
  painter.setPen(Qt::black);
  painter.setFont(QFont("Sans Serif", 10));
  painter.drawText(
    textRect,
    Qt::AlignVCenter | Qt::AlignLeft,
    m_text);
}
