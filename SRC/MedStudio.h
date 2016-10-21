#ifndef MEDSTUDIO_H
#define MEDSTUDIO_H

#include <QMainWindow>
#include "ui_MedStudio.h"

class MedMainScene;
class MedStudio : public QMainWindow
{
	Q_OBJECT

public:
	MedStudio(QWidget *parent = 0);
	~MedStudio();
private slots:
	void OpenDicom();
private:
	void Initialize();
	void Connect();
private:
	Ui::MedStudioClass ui;
	MedMainScene*		m_pMainScene;
};

#endif // MEDSTUDIO_H
