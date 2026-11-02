#include "NativeWindow.h"
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>

NativeWindow::NativeWindow(QWidget *parent)
  : QWidget(parent)
{
  setWindowTitle("Native Qt CheckBoxes");
  QVBoxLayout *layout = new QVBoxLayout(this);

  int indentLevel1 = 0, indentLevel2 = 25, indentLevel3 = 50;

  // --- level 1 ---
  QCheckBox *root1 = new QCheckBox("Native Root", this);
  root1->setTristate(true);

  // --- level 2 ---
  QCheckBox *child1 = new QCheckBox("Child 1", this);
  QCheckBox *child2 = new QCheckBox("Child 2", this);
  child1->setTristate(true);
  child2->setTristate(true);

  // --- level 3 ---
  QCheckBox *sub1_1 = new QCheckBox("Sub-Child 1.1", this);
  QCheckBox *sub1_2 = new QCheckBox("Sub-Child 1.2", this);
  QCheckBox *sub2_1 = new QCheckBox("Sub-Child 2.1", this);
  QCheckBox *sub2_2 = new QCheckBox("Sub-Child 2.2", this);

  // margins
  root1->setContentsMargins(indentLevel1, 0, 0, 0);
  child1->setContentsMargins(indentLevel2, 0, 0, 0);
  child2->setContentsMargins(indentLevel2, 0, 0, 0);
  sub1_1->setContentsMargins(indentLevel3, 0, 0, 0);
  sub1_2->setContentsMargins(indentLevel3, 0, 0, 0);
  sub2_1->setContentsMargins(indentLevel3, 0, 0, 0);
  sub2_2->setContentsMargins(indentLevel3, 0, 0, 0);

  // --- layout ---
  layout->addWidget(root1);
  layout->addWidget(child1);
  layout->addWidget(sub1_1);
  layout->addWidget(sub1_2);
  layout->addWidget(child2);
  layout->addWidget(sub2_1);
  layout->addWidget(sub2_2);

  layout->addStretch();

  // --- button ---
  // doesn't toggle anything actually
  QPushButton *toggleBtn = new QPushButton("Toggle Native Root", this);
  layout->addWidget(toggleBtn);

  connect(
    toggleBtn,
    &QPushButton::clicked,
    [root1]()
    {
      root1->setCheckState(
        root1->checkState() == Qt::Checked ?
        Qt::Unchecked :
        Qt::Checked);
  });
}
