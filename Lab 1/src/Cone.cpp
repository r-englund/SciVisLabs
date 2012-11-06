
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

int main( int argc, char *argv[] )
{
  char a;
  int winSize[2] = {300, 300};

  // create a rendering window and renderer
  vtkRenderer *ren = vtkRenderer::New();
  vtkRenderWindow *renWindow = vtkRenderWindow::New();
  renWindow->SetSize(winSize);
  renWindow->AddRenderer(ren);
  
  vtkConeSource *cone = vtkConeSource::New();  
    cone->SetResolution(8);

  vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
    coneMapper->SetInput(cone->GetOutput());

  vtkActor *coneActor = vtkActor::New();
    coneActor->SetMapper(coneMapper);

  // assign our actor to the renderer
  ren->AddActor(coneActor);

  // draw the resulting scene
  renWindow->Render();
  
  // loop until key is pressed
  cout << "Press any key followed by <Enter> to exit>> ";
  cin >> a;
    
  // Clean up
  ren->Delete();
  renWindow->Delete();
  cone->Delete();
  coneMapper->Delete();
  coneActor->Delete();
}
