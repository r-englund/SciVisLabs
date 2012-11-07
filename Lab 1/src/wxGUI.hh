
#include <wx/wx.h>

class wxVTKRenderWindowInteractor;
class vtkRenderer;
class vtkRenderWindow;
class vtkPolyDataMapper;
class vtkActor;
class vtkConeSource;


class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  // constructor(s)
  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  ~MyFrame();
  
  // event handlers (these functions should _not_ be virtual)
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnSlider1(wxScrollEvent& event);
  void OnSlider2(wxScrollEvent& event);
  void OnSlider3(wxScrollEvent& event);
  void OnSlider4(wxScrollEvent& event);
  void OnSlider5(wxScrollEvent& event);
  void OnSlider6(wxScrollEvent& event);
  
protected:
  void ConstructVTK();
  void DestroyVTK();
  
private:
  wxVTKRenderWindowInteractor *m_pVTKWindow;
  
  // vtk classes
  vtkRenderer       *pRenderer;
  vtkRenderWindow   *pRenderWindow;
  vtkPolyDataMapper *pConeMapper;
  vtkActor          *pConeActor;
  vtkConeSource     *pConeSource;
  
private:
  // any class wishing to process wxWindows events must use this macro
  DECLARE_EVENT_TABLE();
};
