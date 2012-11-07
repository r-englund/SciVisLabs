

VTK_INCLUDES = -I/usr/include/vtk-5.8/

VTK_LIBS     = -lvtkVolumeRendering \
               -lvtkRendering -lvtkGraphics -lvtkIO \
               -lvtkImaging -lvtkFiltering -lvtkCommon

WX_INCLUDES  = `wx-config --cxxflags` \
               -I/usr/include/glib-2.0 \
               -I/usr/include/gtk-2.0 \
               -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
               -I/usr/include/gdk-pixbuf-2.0 \
               -I`pwd` \
               -I/usr/lib/glib-2.0/include \
               -I/usr/include/pango-1.0 \
               -I/usr/lib/gtk-2.0/include \
               -I/usr/include/cairo \
               -I/usr/include/atk-1.0

WX_LIBS      = `wx-config --libs  --gl-libs`

CXX          = g++
CXXFLAGS     = -g -Wno-deprecated $(VTK_INCLUDES) $(WX_INCLUDES)
LDLIBS       = $(VTK_LIBS) $(WX_LIBS)


PROGS = Cone wxGUI


all:	$(PROGS)

Cone:	Cone.o
wxGUI:	wxGUI.o wxVTKRenderWindowInteractor.o

clean:
	rm -f *~ *.o $(PROGS)

