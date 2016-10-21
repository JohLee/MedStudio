#include "MedStudio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MedStudio window;
	window.show();
	return app.exec();
}
