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
// $Id: Em3PhysicsList.hh,v 1.6 2002/02/14 14:20:46 maire Exp $
// GEANT4 tag $Name: geant4-04-01-patch-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef Em3PhysicsList_h
#define Em3PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class Em3PhysicsListMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class Em3PhysicsList: public G4VUserPhysicsList
{
  public:
    Em3PhysicsList();
   ~Em3PhysicsList();

  protected:
    // Construct particle
    void ConstructParticle();
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructMesons();
    void ConstructBarions();
    void ConstructIons();   
    
  public: 
    void SetCuts();
    void SetCutForGamma(G4double);
    void SetCutForElectron(G4double);
    void SetCutForProton(G4double);
        
  protected:
  // Construct physics processes and register them
    void ConstructProcess();  
    void ConstructGeneral();
    void ConstructEM();
    
  private:
    G4double cutForGamma;
    G4double cutForElectron; 
    G4double cutForProton;
    G4double currentDefaultCut;
    
    Em3PhysicsListMessenger* pMessenger;             
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


