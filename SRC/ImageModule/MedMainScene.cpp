#include "MedMainScene.h"
#include "gdcmImageReader.h"
#include <QPixmap>

MedMainScene::MedMainScene(QObject *parent)
	: QGraphicsScene(parent)
{

}

MedMainScene::~MedMainScene()
{

}

void MedMainScene::ImportDicom(QString path)
{
	gdcm::ImageReader ImageReader;
	ImageReader.SetFileName(path.toLocal8Bit().constData());
	if (!ImageReader.Read())
	{
		std::cout << "The image is not valid!" << std::endl;
	}
	gdcm::Image gImage = ImageReader.GetImage();
	std::vector<char> vbuffer;
	vbuffer.resize(gImage.GetBufferLength());
	char *buffer = &vbuffer[0];

	QImage *imageQt = NULL;
	if (ConvertImageFormat(gImage, buffer, imageQt))
	{
		int width = imageQt->width();
		int height = imageQt->height();
		this->addPixmap(QPixmap::fromImage(*imageQt));
	}
}

bool MedMainScene::ConvertImageFormat(gdcm::Image const& gimage, char* buffer, QImage*& imageQt)
{
	const unsigned int* dimension = gimage.GetDimensions();

	unsigned int dimX = dimension[0];
	unsigned int dimY = dimension[1];

	gimage.GetBuffer(buffer);
	if (gimage.GetPhotometricInterpretation() == gdcm::PhotometricInterpretation::RGB)
	{
		if (gimage.GetPixelFormat() == gdcm::PixelFormat::UINT8)
		{
			unsigned char *ubuffer = (unsigned char*)buffer;
			imageQt = new QImage((unsigned char *)ubuffer, dimX, dimY, 3 * dimX, QImage::Format_RGB888);
			return true;
		}
	}
	else if (gimage.GetPhotometricInterpretation() == gdcm::PhotometricInterpretation::MONOCHROME2)
	{
		if (gimage.GetPixelFormat() == gdcm::PixelFormat::UINT8)
		{
			unsigned char *ubuffer = new unsigned char[dimX*dimY * 3];
			unsigned char *pubuffer = ubuffer;
			for (unsigned int i = 0; i < dimX*dimY; i++)
			{
				*pubuffer++ = *buffer;
				*pubuffer++ = *buffer;
				*pubuffer++ = *buffer++;
			}

			imageQt = new QImage(ubuffer, dimX, dimY, QImage::Format_RGB888);
			return true;
		}
		else if (gimage.GetPixelFormat() == gdcm::PixelFormat::INT16)
		{
			short *buffer16 = (short*)buffer;
			unsigned char *ubuffer = new unsigned char[dimX*dimY * 3];
			unsigned char *pubuffer = ubuffer;
			for (unsigned int i = 0; i < dimX*dimY; i++)
			{
				*pubuffer++ = (unsigned char)std::min(255, (32768 + *buffer16) / 255);
				*pubuffer++ = (unsigned char)std::min(255, (32768 + *buffer16) / 255);
				*pubuffer++ = (unsigned char)std::min(255, (32768 + *buffer16) / 255);
				buffer16++;
			}

			imageQt = new QImage(ubuffer, dimX, dimY, QImage::Format_RGB888);
			return true;
		}
	}

	return false;
}
