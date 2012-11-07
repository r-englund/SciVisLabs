#define CONE 1
#define READ 3
#define HYDRO 4

#define TASK HYDRO

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkInteractorStyleSwitch.h>
#include <vtkProperty.h>
#include <vtkXMLMaterial.h>
#include <vtkSTLReader.h>
#include <vtkSampleFunction.h>
#include <vtkStructuredPointsWriter.h>
#include <vtkExtractVOI.h>

#include "wxVTKRenderWindowInteractor.hh"

#include "wxGUI.hh";

#include "ImpFunc.h";


#if TASK == HYDRO
int main( int argc, char *argv[] )
{
  char a;
  int winSize[2] = {300, 300};

  // create a rendering window and renderer
  vtkRenderer *ren = vtkRenderer::New();
  vtkRenderWindow *renWindow = vtkRenderWindow::New();
  renWindow->SetSize(winSize);
  renWindow->AddRenderer(ren);
  
  vtkRenderWindowInteractor *interactor = vtkRenderWindowInteractor::New(); 
  interactor->SetRenderWindow(renWindow);

  ImpFunc *f = ImpFunc::New();
  vtkSampleFunction *sample = vtkSampleFunction::New();
  sample->SetImplicitFunction(f);
  sample->SetSampleDimensions(32,32,32);
  sample->SetModelBounds(-6,6,-6,6,-6,6);
  sample->ComputeNormalsOff();
  sample->Update();

  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  writer->SetInputConnection(sample->GetOutputPort());
  writer->SetFileName("../hydrogen.vtk");
  writer->Write();
/*
  vtkConeSource *cone = vtkConeSource::New();  
    cone->SetResolution(8);

  vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
    coneMapper->SetInput(cone->GetOutput());

  vtkActor *coneActor = vtkActor::New();
    coneActor->SetMapper(coneMapper);
	
	double c[3] = {1,0,0};
	coneActor->GetProperty()->SetColor(c);*/

  vtkSTLReader *reader = vtkSTLReader::New();
  reader->SetFileName("../42400-IDGH.stl");
  reader->Update();
  
  vtkPolyDataMapper *stlMapper = vtkPolyDataMapper::New();
  stlMapper->SetInput(reader->GetOutput());

  vtkActor *stlActor = vtkActor::New();
  stlActor->SetMapper(stlMapper);



  // assign our actor to the renderer
  ren->AddActor(stlActor);

  // draw the resulting scene
  renWindow->Render();
  
  
  interactor->Start();

  // loop until key is pressed
  cout << "Press any key followed by <Enter> to exit>> ";
  //cin >> a;

  // Clean up
  ren->Delete();
  renWindow->Delete();
  /*cone->Delete();
  coneMapper->Delete();
  coneActor->Delete();*/
  reader->Delete();
  stlMapper->Delete();
  stlActor->Delete();
  interactor->Delete();
}
#endif


#if TASK == READ
int main( int argc, char *argv[] )
{
  char a;
  int winSize[2] = {300, 300};

  // create a rendering window and renderer
  vtkRenderer *ren = vtkRenderer::New();
  vtkRenderWindow *renWindow = vtkRenderWindow::New();
  renWindow->SetSize(winSize);
  renWindow->AddRenderer(ren);
  
  vtkRenderWindowInteractor *interactor = vtkRenderWindowInteractor::New(); 
  interactor->SetRenderWindow(renWindow);

/*
  vtkConeSource *cone = vtkConeSource::New();  
    cone->SetResolution(8);

  vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
    coneMapper->SetInput(cone->GetOutput());

  vtkActor *coneActor = vtkActor::New();
    coneActor->SetMapper(coneMapper);
	
	double c[3] = {1,0,0};
	coneActor->GetProperty()->SetColor(c);*/


  vtkSTLReader *reader = vtkSTLReader::New();
  reader->SetFileName("../42400-IDGH.stl");
  reader->Update();
  
  vtkPolyDataMapper *stlMapper = vtkPolyDataMapper::New();
  stlMapper->SetInput(reader->GetOutput());

  vtkActor *stlActor = vtkActor::New();
  stlActor->SetMapper(stlMapper);

  // assign our actor to the renderer
  ren->AddActor(stlActor);

  // draw the resulting scene
  renWindow->Render();
  
  
  interactor->Start();

  // loop until key is pressed
  cout << "Press any key followed by <Enter> to exit>> ";
  //cin >> a;

  // Clean up
  ren->Delete();
  renWindow->Delete();
  /*cone->Delete();
  coneMapper->Delete();
  coneActor->Delete();*/
  reader->Delete();
  stlMapper->Delete();
  stlActor->Delete();
  interactor->Delete();
}
#endif

#if TASK == CONE
int main( int argc, char *argv[] )
{
  char a;
  int winSize[2] = {300, 300};

  // create a rendering window and renderer
  vtkRenderer *ren = vtkRenderer::New();
  vtkRenderWindow *renWindow = vtkRenderWindow::New();
  renWindow->SetSize(winSize);
  renWindow->AddRenderer(ren);
  
  vtkRenderWindowInteractor *interactor = vtkRenderWindowInteractor::New(); 
  interactor->SetRenderWindow(renWindow);
  /*vtkInteractorObserver *obs = interactor->GetInteractorStyle();
  vtkInteractorStyleSwitch* switcher = dynamic_cast<vtkInteractorStyleSwitch*>(obs);
  switcher->SetCurrentStyleToTrackballCamera();
  switcher->SetCurrentStyleToTrackballActor();*/

  vtkConeSource *cone = vtkConeSource::New();  
    cone->SetResolution(8);

  vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
    coneMapper->SetInput(cone->GetOutput());

  vtkActor *coneActor = vtkActor::New();
    coneActor->SetMapper(coneMapper);
	
	double c[3] = {1,0,0};
	coneActor->GetProperty()->SetColor(c);

  // assign our actor to the renderer
  ren->AddActor(coneActor);

  // draw the resulting scene
  renWindow->Render();
  
  
  interactor->Start();

  // loop until key is pressed
  cout << "Press any key followed by <Enter> to exit>> ";
  //cin >> a;

  // Clean up
  ren->Delete();
  renWindow->Delete();
  cone->Delete();
  coneMapper->Delete();
  coneActor->Delete();
  interactor->Delete();
}
#endif
