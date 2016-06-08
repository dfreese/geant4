// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4BREPSolidTorus.hh,v 2.1 1998/10/20 16:31:08 broglia Exp $
// GEANT4 tag $Name: geant4-00 $
//
#ifndef __G4BREPSolidTorus
#define __G4BREPSolidTorus
#include "G4BREPSolid.hh"

class G4BREPSolidTorus: public G4BREPSolid
{
 public:
  G4BREPSolidTorus(const G4String ,
		   const G4ThreeVector&,
		   const G4ThreeVector&,
		   const G4ThreeVector&,
		   G4double,
		   G4double);
};

#endif