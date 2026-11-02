#include "CustomWindow.h"
#include "NativeWindow.h"
#include <QApplication>
#include <QStyleHints>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  app.styleHints()->setColorScheme(Qt::ColorScheme::Light);

  CustomWindow customWin;
  NativeWindow nativeWin;

  // side-by-side
  customWin.setGeometry(100, 100, 350, 600);
  nativeWin.setGeometry(480, 100, 350, 600);

  customWin.show();
  nativeWin.show();

  return app.exec();
}
