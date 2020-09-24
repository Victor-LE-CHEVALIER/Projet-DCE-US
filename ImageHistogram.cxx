#include <vtkSmartPointer.h>
#include <vtkImageHistogram.h>

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

int main(int argc, char *argv[])
{
  if( argc < 1 )
  {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return EXIT_FAILURE;
  }
  
  std::string inputFilename = "chat.jpg.jpg";

  //lecture de l'image
  vtkSmartPointer<vtkImageReader2Factory> readerFactory =vtkSmartPointer<vtkImageReader2Factory>::New();
  vtkSmartPointer<vtkImageReader2> imgReader;
  imgReader.TakeReference(readerFactory->CreateImageReader2(inputFilename.c_str()));
  imgReader->SetFileName(inputFilename.c_str());

  std::cout << "ok"<< std::endl;



  vtkSmartPointer<vtkDataSetMapper> imgDataSetMapper = vtkSmartPointer<vtkDataSetMapper>::New();
  imgDataSetMapper->SetInputConnection(imgReader->GetOutputPort());

  vtkSmartPointer<vtkActor> imgActor = vtkSmartPointer<vtkActor>::New();
  imgActor->SetMapper(imgDataSetMapper);

  vtkSmartPointer<vtkRenderer> imgRenderer = vtkSmartPointer<vtkRenderer>::New();
  imgRenderer->AddActor(imgActor);

  vtkSmartPointer<vtkRenderWindow> imgRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  imgRenderWindow->AddRenderer(imgRenderer);

  vtkSmartPointer<vtkRenderWindowInteractor> imgInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  imgInteractor->SetRenderWindow(imgRenderWindow);
  imgRenderWindow->Render();
  imgInteractor->Initialize();
  imgInteractor->Start();

  return EXIT_SUCCESS;





}
