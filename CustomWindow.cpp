#include "CustomWindow.h"
#include "CustomButton.h"
#include "CustomCheckBox.h"
#include <QVBoxLayout>

CustomWindow::CustomWindow(QWidget *parent)
  : QWidget(parent)
{
  setWindowTitle("Custom CheckBoxes");
  QVBoxLayout *layout = new QVBoxLayout(this);

  int indentLevel1 = 0, indentLevel2 = 25, indentLevel3 = 50;

  // --- level 1 ---
  CustomCheckBox *root1 = new CustomCheckBox("Custom Root", this);
  root1->setContentsMargins(indentLevel1, 0, 0, 0);

  // --- level 2 ---
  CustomCheckBox *child1 = new CustomCheckBox("Child 1", this);
  CustomCheckBox *child2 = new CustomCheckBox("Child 2", this);
  child1->setContentsMargins(indentLevel2, 0, 0, 0);
  child2->setContentsMargins(indentLevel2, 0, 0, 0);
  root1->addChild(child1);
  root1->addChild(child2);

  // --- level 3 ---
  CustomCheckBox *sub1_1 = new CustomCheckBox("Sub-Child 1.1", this);
  CustomCheckBox *sub1_2 = new CustomCheckBox("Sub-Child 1.2", this);
  sub1_1->setContentsMargins(indentLevel3, 0, 0, 0);
  sub1_2->setContentsMargins(indentLevel3, 0, 0, 0);
  child1->addChild(sub1_1);
  child1->addChild(sub1_2);

  CustomCheckBox *sub2_1 = new CustomCheckBox("Sub-Child 2.1", this);
  CustomCheckBox *sub2_2 = new CustomCheckBox("Sub-Child 2.2", this);
  sub2_1->setContentsMargins(indentLevel3, 0, 0, 0);
  sub2_2->setContentsMargins(indentLevel3, 0, 0, 0);
  child2->addChild(sub2_1);
  child2->addChild(sub2_2);

  // --- layout ---
  layout->addWidget(root1);
  layout->addWidget(child1);
  layout->addWidget(sub1_1);
  layout->addWidget(sub1_2);
  layout->addWidget(child2);
  layout->addWidget(sub2_1);
  layout->addWidget(sub2_2);

  // add stretch element under the widgets, thus pushing them to top
  layout->addStretch();

  // --- button ---
  CustomButton *toggleBtn = new CustomButton("Toggle Custom Root", this);
  layout->addWidget(toggleBtn);

  connect(
    toggleBtn,
    &CustomButton::clicked,
    [root1]()
    {
      root1->setState(
        root1->state() == CustomCheckBox::Checked ?
        CustomCheckBox::Unchecked :
        CustomCheckBox::Checked);
  });
}
