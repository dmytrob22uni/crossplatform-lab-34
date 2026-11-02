#pragma once
#include <QWidget>

class CustomWindow : public QWidget
{
  Q_OBJECT // Qt's macro for signals, slots, emits, etc.

public:
  explicit CustomWindow(QWidget *parent = nullptr);
};
