#pragma once
#include <QWidget>

class CustomButton : public QWidget
{
  Q_OBJECT // Qt's macro for signals, slots, emits, etc.

public:
  explicit CustomButton(const QString &text, QWidget *parent = nullptr);
  void setText(const QString &text);

signals:
  void clicked();

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void enterEvent(QEnterEvent *event) override;
  void leaveEvent(QEvent *event) override;

private:
  QString m_text;
  bool m_isHovered = false;
  bool m_isPressed = false;
};
