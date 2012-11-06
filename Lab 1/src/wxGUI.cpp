

#include "wxGUI.hh"
#include "wxVTKRenderWindowInteractor.hh"

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkConeSource.h>
#include <vtkCamera.h>


enum {
  Menu_Quit = 1,
  Menu_About,
  Ctrl_Slider1,
  Ctrl_Slider2,
  Ctrl_Slider3
};


#define MY_FRAME      101
#define MY_VTK_WINDOW 102


BEGIN_EVENT_TABLE(MyFrame, wxFrame)
 EVT_MENU(Menu_Quit,  MyFrame::OnQuit)
 EVT_MENU(Menu_About, MyFrame::OnAbout)
 EVT_COMMAND_SCROLL(Ctrl_Slider1, MyFrame::OnSlider1)
 EVT_COMMAND_SCROLL(Ctrl_Slider2, MyFrame::OnSlider2)
 EVT_COMMAND_SCROLL(Ctrl_Slider3, MyFrame::OnSlider3)
 // Connect events from new widgets here
END_EVENT_TABLE()

IMPLEMENT_APP(MyApp)


bool MyApp::OnInit() {
  MyFrame *frame = new MyFrame(_T("wxWindows-VTK App"),
                               wxPoint(50, 50), wxSize(450, 340));
  frame->Show(TRUE);
  return TRUE;
}

MyFrame::MyFrame( const wxString& title,
                  const wxPoint& pos,
                  const wxSize& size )
  : wxFrame( (wxFrame *)NULL, -1, title, pos, size ){
#ifdef __WXMAC__
  wxApp::s_macAboutMenuItemId = Menu_About;
#endif
  
  wxMenu *menuFile = new wxMenu(_T(""), wxMENU_TEAROFF);
  
  wxMenu *helpMenu = new wxMenu;
  helpMenu->Append( Menu_About,
                    _T("&About...\tCtrl-A"),
                    _T("Show about dialog") );
  
  menuFile->Append( Menu_Quit,
                    _T("E&xit\tAlt-X"),
                    _T("Quit this program") );
  
  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(menuFile, _T("&File"));
  menuBar->Append(helpMenu, _T("&Help"));
  
  SetMenuBar(menuBar);
  
  CreateStatusBar(2);
  SetStatusText(_T("Drag the mouse in the frame above"));
  SetStatusText(_T("VTK/wx example"),1);
  
  
  // Widgets ---
  
  
  wxFlexGridSizer *m_sizer = new wxFlexGridSizer(1);
  SetSizer(m_sizer);
  
  m_pVTKWindow = new wxVTKRenderWindowInteractor(this, MY_VTK_WINDOW);
  m_pVTKWindow->UseCaptureMouseOn();
  //m_pVTKWindow->DebugOn();
  m_sizer->Add( m_pVTKWindow, 0, wxEXPAND );
  
  wxSlider *m_slider1 = new wxSlider( this,Ctrl_Slider1, 0, 0, 100 );
  m_sizer->Add( m_slider1, 0, wxEXPAND );
  
  wxSlider *m_slider2 = new wxSlider( this,Ctrl_Slider2, 0, 0, 100 );
  m_sizer->Add( m_slider2, 0, wxEXPAND );
  
  wxSlider *m_slider3 = new wxSlider( this,Ctrl_Slider3, 0, 0, 64 );
  m_sizer->Add( m_slider3, 0, wxEXPAND );
  
  // Add or remove widgets here
  // Connect their events to the event table above
  
  m_sizer->AddGrowableCol( 0, 1 );
  m_sizer->AddGrowableRow( 0, 1 );
  
  
  // Construct VTK ---
  
  
  ConstructVTK();
}



MyFrame::~MyFrame() {
  if(m_pVTKWindow) m_pVTKWindow->Delete();
  DestroyVTK();
}



void MyFrame::ConstructVTK() {

  pRenderer     = vtkRenderer::New();
  pConeMapper   = vtkPolyDataMapper::New();
  pConeActor    = vtkActor::New();
  pConeSource   = vtkConeSource::New();

  // connect the render window and wxVTK window
  pRenderWindow = m_pVTKWindow->GetRenderWindow();
  
  // connect renderer and render window and configure render window
  pRenderWindow->AddRenderer(pRenderer);
  
  // initialize cone
  pConeSource->SetResolution(8);
  
  // connect pipeline
  
  pConeMapper->SetInput(pConeSource->GetOutput());
  pConeActor->SetMapper(pConeMapper);
  pRenderer->AddActor(pConeActor);
  
  // configure renderer
  pRenderer->SetBackground(1.0,0.333333,0.5);
  pRenderer->GetActiveCamera()->Elevation(30.0);
  pRenderer->GetActiveCamera()->Azimuth(30.0);
  pRenderer->GetActiveCamera()->Zoom(1.0);
  pRenderer->GetActiveCamera()->SetClippingRange(1,1000);
}



void MyFrame::DestroyVTK() {
  if (pRenderer != 0)
    pRenderer->Delete();
  if (pConeMapper != 0)
    pConeMapper->Delete();
  if (pConeActor != 0)
    pConeActor->Delete();
  if (pConeSource != 0)
    pConeSource->Delete();
}



// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
  Close(TRUE);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
  wxString msg;
  msg.Printf( _T("This is the about dialog of wx-vtk sample.\n") );
  wxMessageBox( msg, _T("About wx-vtk"),
                wxOK | wxICON_INFORMATION, this );
}

void MyFrame::OnSlider1(wxScrollEvent& event){
  pConeSource->SetRadius( event.GetPosition() / 100.0 );
  m_pVTKWindow->Render();
  SetStatusText(_T("Updated cone radius."));
}

void MyFrame::OnSlider2(wxScrollEvent& event){
  pConeSource->SetHeight( event.GetPosition() / 100.0 );
  m_pVTKWindow->Render();
  SetStatusText(_T("Updated cone height."));
}

void MyFrame::OnSlider3(wxScrollEvent& event){
  pConeSource->SetResolution( event.GetPosition() );
  m_pVTKWindow->Render();
  SetStatusText(_T("Updated cone resolution."));
}
