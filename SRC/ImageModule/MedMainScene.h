#ifndef MEDMAINSCENE_H
#define MEDMAINSCENE_H

#include <QGraphicsScene>
#include "MedConfigure.h"
#include "gdcmImageReader.h"

class MedMainScene : public QGraphicsScene
{
	Q_OBJECT

public:
	MedMainScene(QObject *parent = 0);
	~MedMainScene();
	void ImportDicom(QString);
private:
	bool ConvertImageFormat(gdcm::Image const&, char*,QImage*&);
	
};

#endif // MEDMAINSCENE_H
