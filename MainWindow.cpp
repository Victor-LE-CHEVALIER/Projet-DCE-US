#include <MainWindow.h>

#include "ui_MainWindow.h"

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkImageReader2Factory.h>
#include <vtkImageReader2.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>
#include <vtkImageData.h>
#include <vtkImageSliceMapper.h>
#include <vtkImageProperty.h>
#include <vtkImageSlice.h>
#include <vtkDataSetMapper.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
	mRenderer(vtkSmartPointer<vtkRenderer>::New()),
	mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
	mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())
{
    ui->setupUi(this);

	// Set up the rendering
	mRenderWindow->AddRenderer(mRenderer);
	mRenderWindow->SetInteractor(mInteractor);
	ui->openGLWidget->SetRenderWindow(mRenderWindow);
	mInteractor->SetInteractorStyle(mInteractorStyle);
	mInteractor->Initialize();

	// Set the background color 
	mRenderer->SetBackground(0.9, 0.9, 0.9);

	// Set the UI connections
	QObject::connect(ui->load_file_button, &QPushButton::clicked,
		this, &MainWindow::onDrawSphereClick);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onDrawSphereClick() {

	//lecture de l'image
	std::string inputFilename = "chat.jpg.jpg";
	vtkSmartPointer<vtkImageReader2Factory> readerFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
	vtkSmartPointer<vtkImageReader2> imgReader;
	imgReader.TakeReference(readerFactory->CreateImageReader2(inputFilename.c_str()));
	imgReader->SetFileName(inputFilename.c_str());
	imgReader->Update();

	// Create the actor where the image is rendered
	vtkSmartPointer<vtkDataSetMapper> imgMapper =vtkSmartPointer<vtkDataSetMapper>::New();
	imgMapper->SetInputData(imgReader->GetOutput());

	vtkSmartPointer<vtkActor> imgActor = vtkSmartPointer<vtkActor>::New();
	imgActor->SetMapper(imgMapper);

	// Add the image actor to the OpenGL
	mRenderer->AddViewProp(imgActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}
