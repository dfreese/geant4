// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLStoredXView.hh,v 2.1 1998/11/06 13:42:21 allison Exp $
// GEANT4 tag $Name: geant4-00 $
//
// 
// Andrew Walkden  7th February 1997
// Class G4OpenGLStoredXView : a class derived from G4OpenGLXView and
//                             G4OpenGLStoredView.

#ifdef G4VIS_BUILD_OPENGLX_DRIVER

#ifndef G4OPENGLSTOREDXVIEW_HH
#define G4OPENGLSTOREDXVIEW_HH

#include "G4VView.hh"
#include "G4OpenGLStoredView.hh"
#include "G4OpenGLXView.hh"

class G4OpenGLStoredScene;

class G4OpenGLStoredXView:
public G4OpenGLXView, public G4OpenGLStoredView{
  
public:
  G4OpenGLStoredXView (G4OpenGLStoredScene& scene, const G4String& name = "");
  void DrawView ();
};

#endif

#endif
