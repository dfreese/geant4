//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: ExN04IonPhysics.cc,v 1.1 2002/04/29 20:44:01 asaim Exp $
// GEANT4 tag $Name: geant4-04-01-patch-01 $
//
// 

#include "ExN04IonPhysics.hh"

#include "globals.hh"
#include "G4ios.hh"
#include "g4std/iomanip"   


ExN04IonPhysics::ExN04IonPhysics(const G4String& name)
                 :  G4VPhysicsConstructor(name)
{
}

ExN04IonPhysics::~ExN04IonPhysics()
{
}

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"

// Nuclei
#include "G4IonConstructor.hh"

void ExN04IonPhysics::ConstructParticle()
{
  //  Construct light ions
  G4IonConstructor pConstructor;
  pConstructor.ConstructParticle();  
}


#include "G4ProcessManager.hh"


void ExN04IonPhysics::ConstructProcess()
{
  G4ProcessManager * pManager = 0;
  
  // Elastic Process
  theElasticModel = new G4LElastic();
  theElasticProcess.RegisterMe(theElasticModel);

  // Generic Ion
  pManager = G4GenericIon::GenericIon()->GetProcessManager();
  // add process
  pManager->AddDiscreteProcess(&theElasticProcess);

  pManager->AddProcess(&fIonIonisation, ordInActive, 2, 2);

  pManager->AddProcess(&fIonMultipleScattering);
  pManager->SetProcessOrdering(&fIonMultipleScattering, idxAlongStep,  1);
  pManager->SetProcessOrdering(&fIonMultipleScattering, idxPostStep,  1);

  // Deuteron 
  pManager = G4Deuteron::Deuteron()->GetProcessManager();
  // add process
  pManager->AddDiscreteProcess(&theElasticProcess);

  fDeuteronModel = new G4LEDeuteronInelastic();
  fDeuteronProcess.RegisterMe(fDeuteronModel);
  pManager->AddDiscreteProcess(&fDeuteronProcess);

  pManager->AddProcess(&fDeuteronIonisation, ordInActive, 2, 2);

  pManager->AddProcess(&fDeuteronMultipleScattering);
  pManager->SetProcessOrdering(&fDeuteronMultipleScattering, idxAlongStep,  1);
  pManager->SetProcessOrdering(&fDeuteronMultipleScattering, idxPostStep,  1);
 
  // Triton 
  pManager = G4Triton::Triton()->GetProcessManager();
  // add process
  pManager->AddDiscreteProcess(&theElasticProcess);

  fTritonModel = new G4LETritonInelastic();
  fTritonProcess.RegisterMe(fTritonModel);
  pManager->AddDiscreteProcess(&fTritonProcess);

  pManager->AddProcess(&fTritonIonisation, ordInActive, 2, 2);

  pManager->AddProcess(&fTritonMultipleScattering);
  pManager->SetProcessOrdering(&fTritonMultipleScattering, idxAlongStep,  1);
  pManager->SetProcessOrdering(&fTritonMultipleScattering, idxPostStep,  1);
 
  // Alpha 
  pManager = G4Alpha::Alpha()->GetProcessManager();
  // add process
  pManager->AddDiscreteProcess(&theElasticProcess);

  fAlphaModel = new G4LEAlphaInelastic();
  fAlphaProcess.RegisterMe(fAlphaModel);
  pManager->AddDiscreteProcess(&fAlphaProcess);

  pManager->AddProcess(&fAlphaIonisation, ordInActive, 2, 2);

  pManager->AddProcess(&fAlphaMultipleScattering);
  pManager->SetProcessOrdering(&fAlphaMultipleScattering, idxAlongStep,  1);
  pManager->SetProcessOrdering(&fAlphaMultipleScattering, idxPostStep,  1);
 
  // He3
  pManager = G4He3::He3()->GetProcessManager();
  // add process
  pManager->AddDiscreteProcess(&theElasticProcess);

  pManager->AddProcess(&fHe3Ionisation, ordInActive, 2, 2);

  pManager->AddProcess(&fHe3MultipleScattering);
  pManager->SetProcessOrdering(&fHe3MultipleScattering, idxAlongStep,  1);
  pManager->SetProcessOrdering(&fHe3MultipleScattering, idxPostStep,  1);
   
}


