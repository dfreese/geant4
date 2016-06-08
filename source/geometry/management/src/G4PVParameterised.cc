// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4PVParameterised.cc,v 2.0 1998/07/02 16:57:27 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
// 
// class G4PVParameterised
//
// Implementation

#include "G4PVParameterised.hh"

G4PVParameterised::G4PVParameterised(const G4String& pName,
			 G4LogicalVolume* pLogical,
			 G4VPhysicalVolume* pMother,
                         const EAxis pAxis,
                         const G4int nReplicas,
		         G4VPVParameterisation *pParam) :
  G4PVReplica(pName,pLogical,pMother,pAxis,nReplicas,0,0),
  fparam(pParam)
{
}

G4PVParameterised::G4PVParameterised(const G4String& pName,
			 G4LogicalVolume* pLogical,
			 G4LogicalVolume* pMotherLogical,
                         const EAxis pAxis,
                         const G4int nReplicas,
		         G4VPVParameterisation *pParam) :
  G4PVReplica(pName,pLogical,pMotherLogical,pAxis,nReplicas,0,0),
  fparam(pParam)
{
}

G4VPVParameterisation* G4PVParameterised::GetParameterisation() const
{
    return fparam;
}

void G4PVParameterised::GetReplicationData(EAxis& axis,
                                   G4int& nReplicas,
				   G4double& width,
                                   G4double& offset,
                                   G4bool& consuming) const
{
    axis=faxis;
    nReplicas=fnReplicas;
    width=fwidth;
    offset=foffset;
    consuming=false;
}
