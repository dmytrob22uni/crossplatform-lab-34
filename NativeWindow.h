#pragma once
#include <QWidget>

class NativeWindow : public QWidget
{
  Q_OBJECT // Qt's macro for signals, slots, emits, etc.

public:
  explicit NativeWindow(QWidget *parent = nullptr);
};
