/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___optionsBasicTypes___
#define ___optionsBasicTypes___

#include "list"
#include "vector"
#include "map"
#include "set"

#include "smartpointer.h"
#include "rational.h"

#include "utilities.h"

#include "msrBasicTypes.h"
#include "lpsrBasicTypes.h"

#include "setTraceOptionsIfDesired.h"


using namespace std;

namespace MusicXML2
{

// layout settings
//______________________________________________________________________________
const int K_OPTIONS_ELEMENTS_INDENTER_OFFSET = 3;
  // indent a bit more for readability

const int K_FIELD_WIDTH = 40;

// PRE-declarations for class dependencies
//______________________________________________________________________________
class optionsElement;
typedef SMARTP<optionsElement> S_optionsElement;

class optionsSubGroup;
typedef SMARTP<optionsSubGroup> S_optionsSubGroup;

class optionsGroup;
typedef SMARTP<optionsGroup> S_optionsGroup;

class EXP optionsHandler;
typedef SMARTP<optionsHandler> S_optionsHandler;

// options elements
//______________________________________________________________________________
class optionsElement : public smartable
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsElement> create (
      string optionsElementShortName,
      string optionsElementLongName,
      string optionsElementDescription);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsElement (
      string optionsElementShortName,
      string optionsElementLongName,
      string optionsElementDescription);

    virtual ~optionsElement ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsElementShortName () const
                              { return fOptionsElementShortName; }

    string                getOptionsElementLongName () const
                              { return fOptionsElementLongName; }

    string                getOptionsElementDescription () const
                              { return fOptionsElementDescription; }

    void                  setOptionsElementIsHidden ()
                              { fOptionsElementIsHidden = true; }

    bool                  getOptionsElementIsHidden () const
                              { return fOptionsElementIsHidden; }

    // services
    // ------------------------------------------------------

    string                optionsElementNames () const;
    string                optionsElementNamesInColumns (
                            int subGroupsShortNameFieldWidth) const;

    string                optionsElementNamesBetweenParentheses () const;
    string                optionsElementNamesInColumnsBetweenParentheses (
                            int subGroupsShortNameFieldWidth) const;

    string                operator () () const
                              { return fOptionsElementDescription; }

    S_optionsElement      fetchOptionElement ( // JMI
                            string optiontElementName);

    // print
    // ------------------------------------------------------

    virtual void          printHeader (ostream& os) const;

    virtual void          printElementEssentials (
                            ostream& os,
                            int      fieldWidth) const;

    virtual void          print (ostream& os) const;

    virtual void          printHelp (ostream& os) const;

  protected:

    // fields
    // ------------------------------------------------------

    string                fOptionsElementShortName;
    string                fOptionsElementLongName;
    string                fOptionsElementDescription;

    bool                  fOptionsElementIsHidden;
};
typedef SMARTP<optionsElement> S_optionsElement;
EXP ostream& operator<< (ostream& os, const S_optionsElement& elt);

// options items
//______________________________________________________________________________
class optionsItem : public optionsElement
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription);

    virtual ~optionsItem ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setOptionsSubGroupUplink (
                            S_optionsSubGroup optionsSubGroup);

    S_optionsSubGroup     getOptionsSubGroupUplink () const
                              { return fOptionsSubGroupUplink; }

    // services
    // ------------------------------------------------------

    void                  registerOptionsItemInHandler (
                            S_optionsHandler optionsHandler);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    virtual void          printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // fields
    // ------------------------------------------------------

    S_optionsSubGroup     fOptionsSubGroupUplink;
};
typedef SMARTP<optionsItem> S_optionsItem;
EXP ostream& operator<< (ostream& os, const S_optionsItem& elt);

// options help usage items
//______________________________________________________________________________
class optionsHelpUsageItem : public optionsItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsHelpUsageItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsHelpUsageItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription);

    virtual ~optionsHelpUsageItem ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelpUsage (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<optionsHelpUsageItem> S_optionsHelpUsageItem;
EXP ostream& operator<< (ostream& os, const S_optionsHelpUsageItem& elt);

// options help summary items
//______________________________________________________________________________
class optionsHelpSummaryItem : public optionsItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsHelpSummaryItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsHelpSummaryItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription);

    virtual ~optionsHelpSummaryItem ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelpSummary (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<optionsHelpSummaryItem> S_optionsHelpSummaryItem;
EXP ostream& operator<< (ostream& os, const S_optionsHelpSummaryItem& elt);

// options combined items items
//______________________________________________________________________________
class optionsCombinedItemsItem : public optionsItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsCombinedItemsItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsCombinedItemsItemVariableDisplayName,
      bool&  optionsCombinedItemsItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsCombinedItemsItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsCombinedItemsItemVariableDisplayName,
      bool&  optionsCombinedItemsItemVariable);

    virtual ~optionsCombinedItemsItem ();

  public:

    // set and get
    // ------------------------------------------------------

    const list<S_optionsItem>&
                          getOptionsCombinedItemsList ()
                              {
                                return
                                  fOptionsCombinedItemsList;
                              }

/*
    void                  setCombinedItemsItemVariableValue (
                            set<int> value)
                              {
                                fOptionsCombinedItemsItemVariable = value;
                              }
*/
    // services
    // ------------------------------------------------------

    void                  appendOptionsItemToCombinedItemsList (
                            S_optionsItem optionsItem);

    void                  appendOptionsItemToCombinedItemsList (
                            string optionsItemName);

    void                  setCombinedItemsVariablesValue (
                            bool value);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsCombinedItemsItemVariableDisplayName;
    bool&                 fOptionsCombinedItemsItemVariable;

    list<S_optionsItem>
                          fOptionsCombinedItemsList;
};
typedef SMARTP<optionsCombinedItemsItem> S_optionsCombinedItemsItem;
EXP ostream& operator<< (ostream& os, const S_optionsCombinedItemsItem& elt);

// options boolean items
//______________________________________________________________________________
class optionsBooleanItem : public optionsItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsBooleanItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsBooleanItemVariableDisplayName,
      bool&  optionsBooleanItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsBooleanItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsBooleanItemVariableDisplayName,
      bool&  optionsBooleanItemVariable);

    virtual ~optionsBooleanItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsBooleanItemVariableDisplayName () const
                              {
                                return
                                  fOptionsBooleanItemVariableDisplayName;
                              }

    void                  setBooleanItemVariableValue (
                            bool value)
                              {
                                fOptionsBooleanItemVariable = value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsBooleanItemVariableDisplayName;
    bool&                 fOptionsBooleanItemVariable;
};
typedef SMARTP<optionsBooleanItem> S_optionsBooleanItem;
EXP ostream& operator<< (ostream& os, const S_optionsBooleanItem& elt);

class optionsTwoBooleansItem : public optionsItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsTwoBooleansItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsTwoBooleansItemVariableDisplayName,
      bool&  optionsTwoBooleansItemVariable,
      bool&  optionsTwoBooleansItemSecondaryVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsTwoBooleansItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsTwoBooleansItemVariableDisplayName,
      bool&  optionsTwoBooleansItemVariable,
      bool&  optionsTwoBooleansItemSecondaryVariable);

    virtual ~optionsTwoBooleansItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsTwoBooleansItemVariableDisplayName () const
                              {
                                return
                                  fOptionsTwoBooleansItemVariableDisplayName;
                              }

    void                  setTwoBooleansItemVariableValue (
                            bool value)
                              {
                                fOptionsTwoBooleansItemVariable =
                                  value;
                                fOptionsTwoBooleansItemSecondaryVariable =
                                  value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsTwoBooleansItemVariableDisplayName;
    bool&                 fOptionsTwoBooleansItemVariable;

    bool&                 fOptionsTwoBooleansItemSecondaryVariable;
};
typedef SMARTP<optionsTwoBooleansItem> S_optionsTwoBooleansItem;
EXP ostream& operator<< (ostream& os, const S_optionsTwoBooleansItem& elt);

class optionsThreeBooleansItem : public optionsItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsThreeBooleansItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsThreeBooleansItemVariableDisplayName,
      bool&  optionsThreeBooleansItemVariable,
      bool&  optionsThreeBooleansItemSecondaryVariable,
      bool&  optionsThreeBooleansItemTertiaryVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsThreeBooleansItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsThreeBooleansItemVariableDisplayName,
      bool&  optionsThreeBooleansItemVariable,
      bool&  optionsThreeBooleansItemSecondaryVariable,
      bool&  optionsThreeBooleansItemTertiaryVariable);

    virtual ~optionsThreeBooleansItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsThreeBooleansItemVariableDisplayName () const
                              {
                                return
                                  fOptionsThreeBooleansItemVariableDisplayName;
                              }

    void                  setThreeBooleansItemVariableValue (
                            bool value)
                              {
                                fOptionsThreeBooleansItemVariable =
                                  value;
                                fOptionsThreeBooleansItemSecondaryVariable =
                                  value;
                                fOptionsThreeBooleansItemTertiaryVariable =
                                  value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsThreeBooleansItemVariableDisplayName;
    bool&                 fOptionsThreeBooleansItemVariable;

    bool&                 fOptionsThreeBooleansItemSecondaryVariable;
    bool&                 fOptionsThreeBooleansItemTertiaryVariable;
};
typedef SMARTP<optionsThreeBooleansItem> S_optionsThreeBooleansItem;
EXP ostream& operator<< (ostream& os, const S_optionsThreeBooleansItem& elt);

// options valued items
//______________________________________________________________________________
class optionsValuedItem : public optionsItem
{
  public:

    // data types
    // ------------------------------------------------------

    enum optionsValuedItemKind {
      kOptionsItemHasNoArgument,
      kOptionsItemHasARequiredArgument,
      kOptionsItemHasAnOptionsArgument };

    static string optionsItemKindAsString (
      optionsValuedItemKind optionsItemKind);

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsValuedItem> create (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsValueSpecification);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsValuedItem (
      string optionsItemShortName,
      string optionsItemLongName,
      string optionsItemDescription,
      string optionsValueSpecification);

    virtual ~optionsValuedItem ();

  public:

    // set and get
    // ------------------------------------------------------

    optionsValuedItemKind
                          getOptionsItemKind () const
                              { return fOptionsItemKind; }

    string                getOptionsValueSpecification () const
                              { return fOptionsValueSpecification; }

    // services
    // ------------------------------------------------------

    void                  registerOptionsItemInHandler (
                            S_optionsHandler optionsHandler);

    // print
    // ------------------------------------------------------

    virtual void          printValuedItemEssentials (
                            ostream& os,
                            int      fieldWidth) const;

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    virtual void          printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // fields
    // ------------------------------------------------------

    optionsValuedItemKind fOptionsItemKind;

    string                fOptionsValueSpecification;
};
typedef SMARTP<optionsValuedItem> S_optionsValuedItem;
EXP ostream& operator<< (ostream& os, const S_optionsValuedItem& elt);

// options items helps items
//______________________________________________________________________________
class optionsItemHelpItem : public optionsValuedItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsItemHelpItem> create (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsItemHelpItem (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification);

  protected:


    virtual ~optionsItemHelpItem ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    virtual void          printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;
  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<optionsItemHelpItem> S_optionsItemHelpItem;
EXP ostream& operator<< (ostream& os, const S_optionsItemHelpItem& elt);

// options integer items
//______________________________________________________________________________
class optionsIntegerItem : public optionsValuedItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsIntegerItem> create (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsIntegerItemVariableDisplayName,
      int&               optionsIntegerItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsIntegerItem (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsIntegerItemVariableDisplayName,
      int&               optionsIntegerItemVariable);

  protected:


    virtual ~optionsIntegerItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsIntegerItemVariableDisplayName () const
                              {
                                return
                                  fOptionsIntegerItemVariableDisplayName;
                              }

    void                  setIntegerItemVariableValue (
                            int value)
                              {
                                fOptionsIntegerItemVariable = value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;
  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsIntegerItemVariableDisplayName;
    int&                  fOptionsIntegerItemVariable;
};
typedef SMARTP<optionsIntegerItem> S_optionsIntegerItem;
EXP ostream& operator<< (ostream& os, const S_optionsIntegerItem& elt);

// options float items
//______________________________________________________________________________
class optionsFloatItem : public optionsValuedItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsFloatItem> create (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsFloatItemVariableDisplayName,
      float&             optionsFloatItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsFloatItem (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsFloatItemVariableDisplayName,
      float&             optionsFloatItemVariable);

    virtual ~optionsFloatItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsFloatItemVariableDisplayName () const
                              {
                                return
                                  fOptionsFloatItemVariableDisplayName;
                              }

    void                  setFloatItemVariableValue (
                            float value)
                              {
                                fOptionsFloatItemVariable = value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsFloatItemVariableDisplayName;
    float&                fOptionsFloatItemVariable;
};
typedef SMARTP<optionsFloatItem> S_optionsFloatItem;
EXP ostream& operator<< (ostream& os, const S_optionsFloatItem& elt);

// options string items
//______________________________________________________________________________
class optionsStringItem : public optionsValuedItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsStringItem> create (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsStringItemVariableDisplayName,
      string&            optionsStringItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsStringItem (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsStringItemVariableDisplayName,
      string&            optionsStringItemVariable);

    virtual ~optionsStringItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsStringItemVariableDisplayName () const
                              {
                                return
                                  fOptionsStringItemVariableDisplayName;
                              }

    void                  setStringItemVariableValue (
                            string value)
                              {
                                fOptionsStringItemVariable = value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsStringItemVariableDisplayName;
    string&               fOptionsStringItemVariable;
};
typedef SMARTP<optionsStringItem> S_optionsStringItem;
EXP ostream& operator<< (ostream& os, const S_optionsStringItem& elt);

// options rational items
//______________________________________________________________________________
class optionsRationalItem : public optionsValuedItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsRationalItem> create (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsRationalItemVariableDisplayName,
      rational&          optionsRationalItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsRationalItem (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsRationalItemVariableDisplayName,
      rational&          optionsRationalItemVariable);

    virtual ~optionsRationalItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsRationalItemVariableDisplayName () const
                              {
                                return
                                  fOptionsRationalItemVariableDisplayName;
                              }

    void                  setRationalItemVariableValue (
                            rational value)
                              {
                                fOptionsRationalItemVariable = value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsRationalItemVariableDisplayName;
    rational&             fOptionsRationalItemVariable;
};
typedef SMARTP<optionsRationalItem> S_optionsRationalItem;
EXP ostream& operator<< (ostream& os, const S_optionsRationalItem& elt);

// options numbers sets items
//______________________________________________________________________________
class optionsNumbersSetItem : public optionsValuedItem
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsNumbersSetItem> create (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsNumbersSetItemVariableDisplayName,
      set<int>&          optionsNumbersSetItemVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsNumbersSetItem (
      string             optionsItemShortName,
      string             optionsItemLongName,
      string             optionsItemDescription,
      string             optionsValueSpecification,
      string             optionsNumbersSetItemVariableDisplayName,
      set<int>&          optionsNumbersSetItemVariable);

    virtual ~optionsNumbersSetItem ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsNumbersSetItemVariableDisplayName () const
                              {
                                return
                                  fOptionsNumbersSetItemVariableDisplayName;
                              }

    void                  setNumbersSetItemVariableValue (
                            set<int> value)
                              {
                                fOptionsNumbersSetItemVariable = value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsNumbersSetItemVariableDisplayName;
    set<int>&             fOptionsNumbersSetItemVariable;
};
typedef SMARTP<optionsNumbersSetItem> S_optionsNumbersSetItem;
EXP ostream& operator<< (ostream& os, const S_optionsNumbersSetItem& elt);

// options subgroups
//_______________________________________________________________________________
class optionsSubGroup : public optionsElement
{
  public:

    // data types
    // ------------------------------------------------------

    enum optionsSubGroupDescriptionVisibilityKind {
      kAlwaysShowDescription,
      kHideDescriptionByDefault };

    static string optionsSubGroupDescriptionVisibilityKindAsString (
      optionsSubGroupDescriptionVisibilityKind
        optionsSubGroupDescriptionVisibilityKind);

  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsSubGroup> create (
      string optionsSubGroupHelpHeader,
      string optionsSubGroupShortName,
      string optionsSubGroupLongName,
      string optionsSubGroupDescription,
      optionsSubGroupDescriptionVisibilityKind
             optionsSubGroupDescriptionVisibilityKind,
      S_optionsGroup
             optionsGroupUplink);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsSubGroup (
      string optionsSubGroupHelpHeader,
      string optionsSubGroupShortName,
      string optionsSubGroupLongName,
      string optionsSubGroupDescription,
      optionsSubGroupDescriptionVisibilityKind
             optionsSubGroupDescriptionVisibilityKind,
      S_optionsGroup
             optionsGroupUplink);

    virtual ~optionsSubGroup ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setOptionsGroupUplink (
                            S_optionsGroup optionsGroup)
                              {
                                fOptionsGroupUplink =
                                  optionsGroup;
                              }

    S_optionsGroup        getOptionsGroupUplink () const
                              { return fOptionsGroupUplink; }

    string                getOptionsSubGroupHelpHeader () const
                              { return fOptionsSubGroupHelpHeader; }

    optionsSubGroupDescriptionVisibilityKind
                          getOptionsSubGroupIsHiddenByDefault () const
                              {
                                return
                                  fOptionsSubGroupDescriptionVisibilityKind;
                              }

    // services
    // ------------------------------------------------------

    void                  underlineHeader (ostream& os) const;

    void                  registerOptionsSubGroupInHandler (
                            S_optionsHandler optionsHandler);

    void                  appendOptionsItem (
                            S_optionsItem optionsItem);

    S_optionsElement      fetchOptionElement (
                            string optiontElementName);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printOptionsSubGroupForcedHelp (
                            ostream& os) const;

    void                  printOptionsItemForcedHelp (
                            ostream&         os,
                            S_optionsItem targetOptionsItem) const;

    void                  printHelpSummary (ostream& os) const;

    void                  printSpecificSubGroupHelp (
                            ostream& os,
                            S_optionsSubGroup
                                     optionsSubGroup) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    S_optionsGroup        fOptionsGroupUplink;

    string                fOptionsSubGroupHelpHeader;

    optionsSubGroupDescriptionVisibilityKind
                          fOptionsSubGroupDescriptionVisibilityKind;

    list<S_optionsItem>   fOptionsSubGroupItemsList;
};
typedef SMARTP<optionsSubGroup> S_optionsSubGroup;
EXP ostream& operator<< (ostream& os, const S_optionsSubGroup& elt);

// options groups
//_______________________________________________________________________________
class optionsGroup : public optionsElement
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsGroup> create (
      string optionsGroupHelpHeader,
      string optionGroupShortName,
      string optionGroupLongName,
      string optionGroupDescription,
      S_optionsHandler
             optionsHandlerUplink);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsGroup (
      string optionsGroupHelpHeader,
      string optionGroupShortName,
      string optionGroupLongName,
      string optionGroupDescription,
      S_optionsHandler
             optionsHandlerUplink);

    virtual ~optionsGroup ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setOptionsHandlerUplink (
                            S_optionsHandler optionsHandler);

    S_optionsHandler      getOptionsHandlerUplink () const
                              { return fOptionsHandlerUplink; }

    string                getOptionsGroupHelpHeader () const
                              { return fOptionsGroupHelpHeader; }

  public:

    // consistency check
    // ------------------------------------------------------

    void                  checkOptionsConsistency ();

  public:

    // services
    // ------------------------------------------------------

    void                  underlineHeader (ostream& os) const;

    void                  registerOptionsGroupInHandler (
                            S_optionsHandler optionsHandler);

    void                  appendOptionsSubGroup (
                            S_optionsSubGroup optionsSubGroup);

    S_optionsElement      fetchOptionElement (
                            string optiontElementName);

    virtual S_optionsItem handleOptionsItem (
                            ostream&      os,
                            S_optionsItem item);

    virtual void          handleOptionsItemValue (
                            ostream&      os,
                            S_optionsItem item,
                            string        theString);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printOptionsSubGroupForcedHelp (
                            ostream&             os,
                            S_optionsSubGroup targetOptionsSubGroup) const;

    void                  printOptionsItemForcedHelp (
                            ostream&          os,
                            S_optionsSubGroup targetOptionsSubGroup,
                            S_optionsItem     targetOptionsItem) const;

    void                  printHelpSummary (ostream& os) const;

    void                  printSpecificSubGroupHelp (
                            ostream& os,
                            S_optionsSubGroup
                                     optionsSubGroup) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // uplink
    // ------------------------------------------------------

    S_optionsHandler      fOptionsHandlerUplink;

  private:

    // fields
    // ------------------------------------------------------

    string                fOptionsGroupHelpHeader;

    list<S_optionsSubGroup>
                          fOptionsGroupSubGroupsList;
};
typedef SMARTP<optionsGroup> S_optionsGroup;
EXP ostream& operator<< (ostream& os, const S_optionsGroup& elt);

// options prefixes
//______________________________________________________________________________
class optionsPrefix;
typedef SMARTP<optionsPrefix> S_optionsPrefix;

class optionsPrefix : public smartable
/*
An options prefix 'trace' --> 'trace-' allows:
  -trace=abc,def,gh
to be developped into :
  -trace-abc -trace-def -trace-gh
*/
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<optionsPrefix> create (
      string optionsPrefixName,
      string optionsPrefixErsatz,
      string optionsPrefixDescription);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsPrefix (
      string optionsPrefixName,
      string optionsPrefixErsatz,
      string optionsPrefixDescription);

    virtual ~optionsPrefix ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsPrefixName () const
                              { return fOptionsPrefixName; }

    string                getOptionsPrefixErsatz () const
                              { return fOptionsPrefixErsatz; }

    string                getOptionsPrefixDescription () const
                              { return fOptionsPrefixDescription; }

  public:

    // public services
    // ------------------------------------------------------

  private:

    // private services
    // ------------------------------------------------------

    string                optionsPrefixNames () const;
    string                optionsPrefixNamesInColumns (
                            int subGroupsShortNameFieldWidth) const;

    string                optionsPrefixNamesBetweenParentheses () const;
    string                optionsPrefixNamesInColumnsBetweenParentheses (
                            int subGroupsShortNameFieldWidth) const;

    string                operator () () const
                              { return fOptionsPrefixErsatz; }

/* JMI
    S_optionsPrefix       fetchOptionElement (
                            string optiontElementName);
                            */

  public:

    // print
    // ------------------------------------------------------

    virtual void          printHeader (ostream& os) const;

    virtual void          printElementEssentials (
                            ostream& os,
                            int      fieldWidth) const;

    virtual void          print (ostream& os) const;

    virtual void          printHelp (ostream& os) const;

  protected:

    // fields
    // ------------------------------------------------------

    string                fOptionsPrefixName;
    string                fOptionsPrefixErsatz;
    string                fOptionsPrefixDescription;
};
EXP ostream& operator<< (ostream& os, const S_optionsPrefix& elt);

// options handlers
//_______________________________________________________________________________
class EXP optionsHandler : public optionsElement
{
  public:

    // creation
    // ------------------------------------------------------
/* JMI this a pure virtual class
    static SMARTP<optionsHandler> create (
      string           optionsHandlerHelpHeader,
      string           optionsHandlerValuesHeader,
      string           optionHandlerHelpShortName,
      string           optionHandlerHelpLongName,
      string           optionHandlerHelpSummaryShortName,
      string           optionHandlerHelpSummaryLongName,
      string           optionHandlerPreamble,
      string           optionHandlerDescription,
      indentedOstream& optionsHandlerLogIOstream);
*/

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    optionsHandler (
      string           optionsHandlerHelpHeader,
      string           optionsHandlerValuesHeader,
      string           optionHandlerHelpShortName,
      string           optionHandlerHelpLongName,
      string           optionHandlerHelpSummaryShortName,
      string           optionHandlerHelpSummaryLongName,
      string           optionHandlerPreamble,
      string           optionHandlerDescription,
      indentedOstream& optionsHandlerLogIOstream);

    virtual ~optionsHandler ();

  private:

    // initialization
    // ------------------------------------------------------

    virtual void          initializeOptionsHandler (
                            string executableName) = 0;

  public:

    // set and get
    // ------------------------------------------------------

    string                getOptionsHandlerHelpHeader () const
                              { return fOptionsHandlerHelpHeader; }

    string                getOptionsHandlerValuesHeader () const
                              { return fOptionsHandlerValuesHeader; }

    string                getOptionHandlerHelpSummaryShortName () const
                              { return fOptionHandlerHelpSummaryShortName; }

    string                getOptionHandlerHelpSummaryLongName () const
                              { return fOptionHandlerHelpSummaryLongName; }

    string                getOptionHandlerPreamble () const
                              { return fOptionHandlerPreamble; }

    const indentedOstream&
                          getOptionsHandlerLogIOstream ()
                              { return fOptionsHandlerLogIOstream; }

    string                getExecutableName () const
                              { return fExecutableName; }

    const list<S_optionsElement>&
                          getCommandOptionsElements () const
                              { return fCommandOptionsElements; }

    string                getCommandLineWithShortOptions () const
                              { return fCommandLineWithShortOptions; }

    string                getCommandLineWithLongOptions () const
                              { return fCommandLineWithLongOptions; }

    int                   getMaximumSubGroupsHelpHeadersSize () const
                              { return fMaximumSubGroupsHelpHeadersSize; }

    int                   getMaximumShortNameWidth () const
                              { return fMaximumShortNameWidth; }

    int                   getMaximumLongNameWidth () const
                              { return fMaximumLongNameWidth; }

    int                   getMaximumDisplayNameWidth () const
                              { return fMaximumDisplayNameWidth; }

  public:

    // public services
    // ------------------------------------------------------

    void                  appendOptionsPrefixToHandler (
                            S_optionsPrefix prefix);

    void                  appendOptionsGroupToHandler (
                            S_optionsGroup optionsGroup);

    void                  registerOptionsElementInHandler (
                            S_optionsElement optionsElement);

    void                  registerOptionsHandlerInItself ();

    S_optionsPrefix       fetchOptionsPrefixFromMap (
                            string optionsElementName) const;

    S_optionsElement      fetchOptionsElementFromMap (
                            string optionsElementName) const;

    const vector<string>  decipherOptionsAndArguments (
                            int   argc,
                            char* argv[]);

  public:

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printHelpSummary (ostream& os) const;
    void                  printHelpSummary () const
                              {
                                printHelpSummary (
                                  fOptionsHandlerLogIOstream);
                              }

    void                  printSpecificSubGroupHelp (
                            ostream& os,
                            S_optionsSubGroup
                                     optionsSubGroup) const;

    void                  printSpecificItemHelp (
                            ostream& os,
                            string   optionsItemName) const;

    void                  printAllOptionsValues (
                            ostream& os) const;

  private:

    // private services
    // ------------------------------------------------------

    string                helpNamesBetweenParentheses () const; // JMI ???

    void                  registerOptionsNamesInHandler (
                            string           optionShortName,
                            string           optionLongName,
                            S_optionsElement optionsElement);

    void                  printKnownOptionsPrefixes ();
    void                  printKnownOptionsElements ();

    S_optionsElement      fetchOptionElement (
                            string optiontElementName);

    void                  handleOptionsItemName (
                            string optionsItemName);

    void                  handleOptionsHandlerItemName (
                            S_optionsHandler handler,
                            string           optionsItemName);

    void                  handleOptionsGroupItemName (
                            S_optionsGroup group,
                            string         optionsItemName);

    void                  handleOptionsSubGroupItemName (
                            S_optionsSubGroup subGroup,
                            string            optionsItemName);

    void                  handleOptionsItemItemName (
                            S_optionsItem item,
                            string        optionsItemName);

    void                  handleOptionsHelpUsageItemName (
                            S_optionsHelpUsageItem helpUsageItem,
                            string                 optionsItemName);

    void                  handleOptionsHelpSummaryItemName (
                            S_optionsHelpSummaryItem helpSummaryItem,
                            string                   optionsItemName);

    void                  handleOptionsCombinedItemsItemName (
                            S_optionsCombinedItemsItem combinedItemsItem,
                            string                     optionsItemName);

    void                  handleOptionsBooleanItemItemName (
                            S_optionsBooleanItem booleanItem,
                            string               optionsItemName);

    void                  handleOptionsTwoBooleansItemItemName (
                            S_optionsTwoBooleansItem twoBooleansItem,
                            string                   optionsItemName);

    void                  handleOptionsThreeBooleansItemItemName (
                            S_optionsThreeBooleansItem threeBooleansItem,
                            string                     optionsItemName);

    void                  handleOptionsItemHelpItemName (
                            S_optionsItemHelpItem itemHelpItem,
                            string                optionsItemName);

    void                  handleOptionsIntegerItemItemName (
                            S_optionsIntegerItem integerItem,
                            string               optionsItemName);

    void                  handleOptionsFloatItemItemName (
                            S_optionsFloatItem floatItem,
                            string             optionsItemName);

    void                  handleOptionsStringItemItemName (
                            S_optionsStringItem stringItem,
                            string              optionsItemName);

    void                  handleOptionsRationalItemItemName (
                            S_optionsRationalItem rationalItem,
                            string              optionsItemName);

    void                  handleOptionsNumbersSetItemItemName (
                            S_optionsNumbersSetItem numbersSetItem,
                            string                  optionsItemName);

    void                  handleOptionsItemValueOrArgument (
                            string theString);

    void                  handleOptionsItemHelpValue (
                            S_optionsItemHelpItem itemHelpItem,
                            string                theString);

    void                  handleOptionsItemIntegerValue (
                            S_optionsIntegerItem integerItem,
                            string               theString);

    void                  handleOptionsItemFloatValue (
                            S_optionsFloatItem floatItem,
                            string             theString);

    void                  handleOptionsItemStringValue (
                            S_optionsStringItem stringItem,
                            string              theString);

    void                  handleOptionsItemRationalValue (
                            S_optionsRationalItem rationalItem,
                            string                theString);

    void                  handleOptionsItemNumbersSetValue (
                            S_optionsNumbersSetItem numbersSetItem,
                            string                  theString);

    virtual void          checkOptionsAndArguments () = 0;

  protected:

    // fields
    // ------------------------------------------------------

    string                fOptionsHandlerHelpHeader;
    string                fOptionsHandlerValuesHeader;

    string                fOptionHandlerHelpSummaryShortName;
    string                fOptionHandlerHelpSummaryLongName;

    string                fOptionHandlerPreamble;

    S_optionsItem         fPendingOptionsItem;

    vector<string>        fArgumentsVector;

    map<string, S_optionsPrefix>
                          fOptionsPrefixesMap;

    list<S_optionsGroup>  fOptionsHandlerOptionsGroupsList;

    map<string, S_optionsElement>
                          fOptionsElementsMap;

    int                   fMaximumSubGroupsHelpHeadersSize;

    int                   fMaximumShortNameWidth;
    int                   fMaximumLongNameWidth;

    int                   fMaximumDisplayNameWidth;

    list<S_optionsElement>
                          fCommandOptionsElements;

    string                fExecutableName;

    string                fCommandLineWithShortOptions;
    string                fCommandLineWithLongOptions;

    indentedOstream&      fOptionsHandlerLogIOstream;
};
typedef SMARTP<optionsHandler> S_optionsHandler;
EXP ostream& operator<< (ostream& os, const S_optionsHandler& elt);


}


#endif
