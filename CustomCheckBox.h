#pragma once
#include <QVector>
#include <QWidget>

class CustomCheckBox : public QWidget
{
  Q_OBJECT // Qt's macro for signals, slots, emits, etc.

public:
  enum State { Unchecked, Checked, PartiallyChecked };

  explicit CustomCheckBox(const QString &text, QWidget *parent = nullptr);

  State state() const;
  void setState(State newState);
  void addChild(CustomCheckBox *child);

signals:
  void stateChanged(CustomCheckBox::State state);

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

private:
  QString m_text;
  State m_state;
  CustomCheckBox *m_parentBox;
  QVector<CustomCheckBox *> m_children;

  void setCheckStateDown(State newState);
  void updateStateUp();
};
