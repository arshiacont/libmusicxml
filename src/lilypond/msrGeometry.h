/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___msrGeometry___
#define ___msrGeometry___

#include "msrElements.h"

#include "msrBasicTypes.h"

#include "msrLayouts.h"


namespace MusicXML2
{

//______________________________________________________________________________
class msrGeometry : public msrElement
{
  public:

    // creation from MusicXML
    // ------------------------------------------------------

    static SMARTP<msrGeometry> create (
      int inputLineNumber);

    SMARTP<msrGeometry> createMsrGeometryNewbornClone ();

  public:

    // constructors/destructor
    // ------------------------------------------------------

    msrGeometry (
      int inputLineNumber);

    virtual ~msrGeometry ();

  public:

    // set and get
    // ------------------------------------------------------

    // relative to absolute lengths conversion
    void                  setMillimeters (float val)
                              { fMillimeters = val; }
    float                 getMillimeters () const
                              { return fMillimeters; }

    void                  setTenths (int val)
                              { fTenths = val; }
    float                 getTenths () const
                              { return float(fTenths); }

    // page layout
    void                  setPageLayout (S_msrPageLayout val)
                              { fPageLayout = val; }
    S_msrPageLayout       getPageLayout () const
                              { return fPageLayout; }

  public:

    // services
    // ------------------------------------------------------

    float                 fetchGlobalStaffSize () const;

  public:

    // visitors
    // ------------------------------------------------------

    virtual void          acceptIn  (basevisitor* v);
    virtual void          acceptOut (basevisitor* v);

    virtual void          browseData (basevisitor* v);

  public:

    // print
    // ------------------------------------------------------

    virtual void          print (ostream& os) const;


  private:

    // fields
    // ------------------------------------------------------

    // relative to absolute lengths conversion
    float                 fMillimeters;
    int                   fTenths;

    // page layout
    S_msrPageLayout       fPageLayout;
};
typedef SMARTP<msrGeometry> S_msrGeometry;
EXP ostream& operator<< (ostream& os, const S_msrGeometry& elt);


} // namespace MusicXML2


#endif
