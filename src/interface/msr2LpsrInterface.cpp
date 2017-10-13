/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifdef VC6
# pragma warning (disable : 4786)
#endif

#include <iostream>

#include "xml.h"
#include "xmlfile.h"
#include "xmlreader.h"

#include "versions.h"

#include "msr2LpsrInterface.h"

#include "msr2LpsrTranslator.h"

using namespace std;

namespace MusicXML2 
{

// useful shortcut macros
#define idtr indenter::gIndenter
#define tab  indenter::gIndenter.getSpacer ()

//_______________________________________________________________________________
/*
 * The method that converts the file contents to LilyPond code
 * and  writes the result to the output stream
*/
S_lpsrScore msr2Lpsr (
  const S_msrScore mScore,
  S_msrOptions&    msrOpts,
  S_lpsrOptions&   lpsrOpts,
  ostream&         os) 
{  
  // create an indented output stream for the log
  indentedOutputStream
    logIndentedOutputStream (
      os, idtr);
    
  // build LPSR score from MSR score
  S_lpsrScore
    lpScore =
      buildLpsrScoreFromMsrScore (
        mScore,
        msrOpts,
        lpsrOpts,
        logIndentedOutputStream);

  // display it
  if (lpsrOpts->fDisplayLpsr)
    displayLpsrScore (
      lpScore,
      msrOpts,
      lpsrOpts,
      logIndentedOutputStream);

  return lpScore;
}

//_______________________________________________________________________________
S_lpsrScore buildLpsrScoreFromMsrScore (
  const S_msrScore mScore,
  S_msrOptions&    msrOpts,
  S_lpsrOptions&   lpsrOpts,
  ostream&         os)
{
  clock_t startClock = clock();
      
  // create an indented output stream for the log
  indentedOutputStream
    logIndentedOutputStream (
      os, idtr);
  
  if (gGeneralOptions->fTraceGeneral) {
    string separator =
      "%--------------------------------------------------------------";
  
    logIndentedOutputStream <<
      endl <<
      separator <<
      endl <<
      "Pass 3: translating the MSR into a LPSR" <<
      endl <<
      separator <<
      endl <<
      endl;
  }
  
  // create an msr2LpsrTranslator
  msr2LpsrTranslator translator (
    logIndentedOutputStream,
    mScore);
      
  // build the LPSR score
  translator.buildLpsrScoreFromMsrScore ();

  clock_t endClock = clock();

  // register time spent
  timing::gTiming.appendTimingItem (
    "Pass 3: translate MSR to LPSR",
    timingItem::kMandatory,
    startClock,
    endClock);

  return translator.getLpsrScore ();
}

//_______________________________________________________________________________
void displayLpsrScore (
  const S_lpsrScore lpScore,
  S_msrOptions&     msrOpts,
  S_lpsrOptions&    lpsrOpts,
  ostream&          os)
{
  clock_t startClock = clock();

  // create an indented output stream for the log
  indentedOutputStream
    logIndentedOutputStream (
      os, idtr);

  string separator =
    "%--------------------------------------------------------------";

  logIndentedOutputStream <<
    endl <<
    idtr <<
      separator <<
      endl <<
    idtr <<
      "Optional pass: displaying the LPSR as text" <<
      endl <<
    idtr <<
      separator <<
      endl <<
      endl;  

  logIndentedOutputStream <<
    idtr <<
      "%{" <<
      endl <<
    
    lpScore <<
    
    idtr <<
      "%}" <<
      endl;
  
  logIndentedOutputStream <<
    idtr <<
      separator <<
      endl;

  clock_t endClock = clock();

  // register time spent
  timing::gTiming.appendTimingItem (
    "        display the LPSR",
    timingItem::kOptional,
    startClock,
    endClock);
}


}
