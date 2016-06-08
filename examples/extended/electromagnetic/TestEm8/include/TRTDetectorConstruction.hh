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
// $Id: TRTDetectorConstruction.hh,v 1.3 2001/07/11 09:57:55 gunter Exp $
// GEANT4 tag $Name: geant4-04-01-patch-01 $
//
// 

#ifndef TRTDetectorConstruction_h
#define TRTDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "Randomize.hh"

class TRTTrackerSD;
class SCTTrackerSD;
class HepJamesRandom;

class TRTDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    TRTDetectorConstruction();
    ~TRTDetectorConstruction();

  public:
     G4VPhysicalVolume* Construct();

  private:
    TRTTrackerSD *TRTStrawSD;
    SCTTrackerSD *SCTStripSD;
    HepJamesRandom theJamesEngine;    
};

#endif