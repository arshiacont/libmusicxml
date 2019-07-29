/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___xml2brlOah___
#define ___xml2brlOah___

#include "exports.h"
#include "oahBasicTypes.h"


namespace MusicXML2
{

//______________________________________________________________________________
class xml2brlOahVersionAtom : public oahAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<xml2brlOahVersionAtom> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    xml2brlOahVersionAtom (
      string shortName,
      string longName,
      string description);

    virtual ~xml2brlOahVersionAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printVersion (ostream& os) const;

    void                  printAtomOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<xml2brlOahVersionAtom> S_xml2brlOahVersionAtom;
EXP ostream& operator<< (ostream& os, const S_xml2brlOahVersionAtom& elt);

//______________________________________________________________________________
class xml2brlOahAboutAtom : public oahAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<xml2brlOahAboutAtom> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    xml2brlOahAboutAtom (
      string shortName,
      string longName,
      string description);

    virtual ~xml2brlOahAboutAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printAbout (ostream& os) const;

    void                  printAtomOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<xml2brlOahAboutAtom> S_xml2brlOahAboutAtom;
EXP ostream& operator<< (ostream& os, const S_xml2brlOahAboutAtom& elt);

//______________________________________________________________________________
class xml2brlOahContactAtom : public oahAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<xml2brlOahContactAtom> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    xml2brlOahContactAtom (
      string shortName,
      string longName,
      string description);

    virtual ~xml2brlOahContactAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printContact (ostream& os) const;

    void                  printAtomOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<xml2brlOahContactAtom> S_xml2brlOahContactAtom;
EXP ostream& operator<< (ostream& os, const S_xml2brlOahContactAtom& elt);

//_______________________________________________________________________________
class EXP xml2brlOahHandler : public oahHandler
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<xml2brlOahHandler> create (
      string           executableName,
      indentedOstream& ios);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    xml2brlOahHandler (
      string           executableName,
      indentedOstream& ios);

    virtual ~xml2brlOahHandler ();

  private:

    // initialization
    // ------------------------------------------------------

    void                  initializeOptionsHandler (
                            string executableName);

  public:

    // quiet mode
    // ------------------------------------------------------

    void                  enforceOahHandlerQuietness ();

  public:

    // services
    // ------------------------------------------------------

    void                  checkOptionsAndArguments ();

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<xml2brlOahHandler> S_xml2brlOahHandler;
EXP ostream& operator<< (ostream& os, const S_xml2brlOahHandler& elt);

//______________________________________________________________________________
class xml2brlOah : public oahGroup
{
  public:

    static SMARTP<xml2brlOah> create (
      S_oahHandler handler);

  public:

    // initialisation
    // ------------------------------------------------------

    void                  initializeXml2brlOah ();

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    xml2brlOah (
      S_oahHandler handler);

    virtual ~xml2brlOah ();

  public:

    // quiet mode
    // ------------------------------------------------------

    void                  enforceQuietness ();

  public:

    // consistency check
    // ------------------------------------------------------

    void                  checkOptionsConsistency ();

  public:

    // services
    // ------------------------------------------------------

    virtual S_oahValuedAtom
                          handleAtom (
                            ostream&  os,
                            S_oahAtom atom);

  public:

    // print
    // ------------------------------------------------------

    void                  printXml2brlOahHelp ();

    void                  printXml2brlOahValues (int fieldWidth);

  public:

    // input
    // --------------------------------------


    // output file
    // --------------------------------------

    string                fOutputFileName;
    bool                  fAutoOutputFile;


};
typedef SMARTP<xml2brlOah> S_xml2brlOah;
EXP ostream& operator<< (ostream& os, const S_xml2brlOah& elt);

EXP extern S_xml2brlOah gXml2brlOah;

//______________________________________________________________________________
void initializeXml2brlOah (
  S_oahHandler handler);


}


#endif
