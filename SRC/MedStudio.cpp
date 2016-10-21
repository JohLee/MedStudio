#include "MedStudio.h"
#include "MedMainScene.h"
#include "MedStdafx.h"
#include <QFileDialog>

MedStudio::MedStudio(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Initialize();
	Connect();
}

MedStudio::~MedStudio()
{

}

void MedStudio::Initialize()
{
	m_pMainScene = new MedMainScene();
	ui.graphicsView->setScene(m_pMainScene);
}

void MedStudio::Connect()
{
	connect(ui.actionOpenDicom, SIGNAL(triggered()), this, SLOT(OpenDicom()));
}

void MedStudio::OpenDicom()
{
	QString FilePath = QFileDialog::getOpenFileName(this, tr("Open Dicom"), "E:\\DICOM", "Image(*.dcm)");
	if (!FilePath.isEmpty())
	{
		m_pMainScene->ImportDicom(FilePath);
	}
}
