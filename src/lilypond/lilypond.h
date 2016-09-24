/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef __lilypond__
#define __lilypond__

#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <map>

#include "utilities.h"
#include "exports.h"
#include "typedefs.h"
#include "smartpointer.h"
#include "rational.h"

namespace MusicXML2 
{

/*!
\addtogroup lilypond
@{
*/

class lilypondvisitor;

class lilypondelement;
class lilypondpart;
class lilypondlyrics;
class lilypondnoteduration;
class lilyponddynamics;
class lilypondwedge;
class lilypondchord;
class lilypondnote;

class lilypondpaper;
class lilypondlayout;

typedef SMARTP<lilypondelement>      Slilypondelement;
typedef SMARTP<lilypondpart>         Slilypondpart;
typedef SMARTP<lilypondlyrics>       Slilypondlyrics;
typedef SMARTP<lilypondnoteduration> Slilypondnoteduration;
typedef SMARTP<lilyponddynamics>     Slilyponddynamics;
typedef SMARTP<lilypondwedge>        Slilypondwedge;
typedef SMARTP<lilypondchord>        Slilypondchord;
typedef SMARTP<lilypondnote>         Slilypondnote;

typedef SMARTP<lilypondpaper>        Slilypondpaper;
typedef SMARTP<lilypondlayout>       Slilypondlayout;

EXP std::ostream& operator<< (std::ostream& os, const Slilypondelement& elt);
EXP std::ostream& operator<< (std::ostream& os, const Slilypondnoteduration& dur);
EXP std::ostream& operator<< (std::ostream& os, const Slilyponddynamics& dyn);
EXP std::ostream& operator<< (std::ostream& os, const Slilypondwedge& wdg);
EXP std::ostream& operator<< (std::ostream& os, const Slilypondchord& chrd);
EXP std::ostream& operator<< (std::ostream& os, const Slilypondnote& chrd);

EXP std::ostream& operator<< (std::ostream& os, const Slilypondpaper& chrd);
EXP std::ostream& operator<< (std::ostream& os, const Slilypondlayout& chrd);


/*!
\brief A generic lilypond element representation.

  An element is represented by its name and the
  list of its enclosed elements plus optional parameters.
*/
//______________________________________________________________________________
class EXP lilypondelement : public smartable {
  public:
 
    static SMARTP<lilypondelement> create(bool debug);
    
    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:
 
    static haendel hdl;
    
    lilypondelement(bool debug);
    virtual ~lilypondelement();

  private:
  
    bool fDebug;
};

/*!
\brief A lilypond note duration representation.

  A note duration is represented by a numerator 
    (denotes the number of beats), a denominator (denotes the beat value)
     and optional dots.
     Triplets are repesented as 1/3, 1/6, ... quintuplets, septuplets and so on
     are handled analogously.
*/
//______________________________________________________________________________
class EXP lilypondnoteduration : public lilypondelement {
  public:
  
    static SMARTP<lilypondnoteduration> create(int num, int denom, int dots=0);
    
    lilypondnoteduration(int num, int denom, int dots=0);
    virtual ~lilypondnoteduration();
    
    void scaleNumByFraction (int num, int denom);
    void sett (int num, int denom, int dots=0);
        
    lilypondnoteduration& operator= (const lilypondnoteduration& dur)
      {
        fNum=dur.fNum; fDenom=dur.fDenom; fDots=dur.fDots; 
        return *this;
      }
          
    bool operator!= (const lilypondnoteduration& dur) const 
      { 
        return
          (fNum!=dur.fNum) || (fDenom!=dur.fDenom) || (fDots!=dur.fDots);
      }
    
    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  private:

    int  fNum;
    int  fDenom;
    int  fDots;
};
typedef SMARTP<lilypondnoteduration> Slilypondnoteduration;

/*!
\brief A lilypond note representation.

  A note is represented by its name, optional accidentals,
    duration (in the form of numerator/denominator) and optional dots.
*/
//______________________________________________________________________________
class EXP lilypondnote : public lilypondelement {
  public:

    enum DiatonicNote {
      kA, kB, kC, kD, kE, kF, kG, kRest, kNoDiatonicNote};
    
    enum Alteration { // kDoubleFlat=-2 as in MusicXML, to help testing
      kDoubleFlat=-2, kFlat, kNatural, kSharp, kDoubleSharp, kNoAlteration};
        
    // the following is a series of Cs with increasing pitches:
    // \relative c'' { ceseh ces ceh c cih cis cisih }

    enum LilypondNote {
      k_aeseh, k_aes, k_aeh, k_a, k_aih, k_ais, k_aisih,
      k_beseh, k_bes, k_beh, k_b, k_bih, k_bis, k_bisih, 
      k_ceseh, k_ces, k_ceh, k_c, k_cih, k_cis, k_cisih,
      k_deseh, k_des, k_deh, k_d, k_dih, k_dis, k_disih,
      k_eeseh, k_ees, k_eeh, k_e, k_eih, k_eis, k_eisih, 
      k_feseh, k_fes, k_feh, k_f, k_fih, k_fis, k_fisih,
      k_geseh, k_ges, k_geh, k_g, k_gih, k_gis, k_gisih,
      k_NoLilypondNote};
      
    static SMARTP<lilypondnote> create();// JMI  Note note, int voice) 

    // for regular notes
    void updateNote( 
          bool                  fCurrentStepIsRest,
          DiatonicNote          diatonicNote,
          Alteration            alteration,
          int                   octave,
          Slilypondnoteduration dur,
          LilypondNote          lilypondNote,
          int                   voice,
          bool                  noteBelongsToAChord);
    
    // for tuplet elements
    void updateNoteDuration (int actualNotes, int normalNotes);
          
    void setNoteBelongsToAChord ();
    
    void              addDynamics (Slilyponddynamics dyn);
    void              addWedge    (Slilypondwedge    wdg);

    Slilyponddynamics removeFirstDynamics ();
    Slilypondwedge    removeFirstWedge ();

    std::list<Slilyponddynamics> getNoteDynamics () { return fNoteDynamics; };
    std::list<Slilypondwedge>    getNoteWedges   () { return fNoteWedges; };

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:
 
    lilypondnote();
    
    virtual ~lilypondnote();
    
  private:

    // MusicXML informations
    bool                 fCurrentStepIsRest;
    DiatonicNote         fDiatonicNote;
    Alteration           fAlteration;
    int                  fOctave;

    // MusicXML durations are in in divisions per quarter note,
    // LilyPond durations are in whole notes, hence the "*4" multiplication
    Slilypondnoteduration fLilypondnoteduration;

    // LilyPond informations
    LilypondNote         fLilypondNote;
    
    std::list<Slilyponddynamics> fNoteDynamics;
    std::list<Slilypondwedge>    fNoteWedges;
    
    bool                 fNoteBelongsToAChord;

    int                  fVoice;
};
typedef SMARTP<lilypondnote> Slilypondnote;

/*!
\brief The lilypond parallel element
*/
//______________________________________________________________________________
class EXP lilypondparallel : public lilypondelement {
  public:
    
    enum ElementsSeparator { kEndOfLine, kSpace };

    static SMARTP<lilypondparallel> create(ElementsSeparator elementsSeparator);

    void             addElementToParallel (Slilypondelement elem) { fParallelElements.push_back(elem); }
    Slilypondelement getLastElementOfParallel() { return fParallelElements.back(); }
    void             removeLastElementOfParallel () { fParallelElements.pop_back(); }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondparallel(ElementsSeparator elementsSeparator);
    virtual ~lilypondparallel();
    
  private:
  
    std::vector<Slilypondelement> fParallelElements;
    ElementsSeparator             fElementsSeparator;

};
typedef SMARTP<lilypondparallel> Slilypondparallel;

/*!
\brief The lilypond sequence element
*/
//______________________________________________________________________________
class EXP lilypondsequence : public lilypondelement {
  public:
    
    enum ElementsSeparator { kEndOfLine, kSpace };

    static SMARTP<lilypondsequence> create(ElementsSeparator elementsSeparator);

    void             addElementToSequence (Slilypondelement elem) { fSequenceElements.push_back(elem); }
    Slilypondelement getLastElementOfSequence() { return fSequenceElements.back(); }
    void             removeLastElementOfSequence () { fSequenceElements.pop_back(); }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondsequence(ElementsSeparator elementsSeparator);
    virtual ~lilypondsequence();
    
  private:
  
    std::vector<Slilypondelement> fSequenceElements;
    ElementsSeparator             fElementsSeparator;

};
typedef SMARTP<lilypondsequence> Slilypondsequence;

/*!
\brief The lilypond chord element
*/
//______________________________________________________________________________
class EXP lilypondchord : public lilypondelement {
  public:

    static SMARTP<lilypondchord> create(Slilypondnoteduration chordduration);
    
    void addNoteToChord (Slilypondnote note) { fChordNotes.push_back(note); }

    void addDynamics (Slilyponddynamics dyn);
    void addWedge    (Slilypondwedge    wdg);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondchord (Slilypondnoteduration chordduration);
    virtual ~lilypondchord();
  
  private:
  
    std::vector<Slilypondnote>   fChordNotes;
    
    Slilypondnoteduration        fChordDuration;

    
    std::list<Slilyponddynamics> fChordDynamics;
    std::list<Slilypondwedge>    fChordWedges;
};
typedef SMARTP<lilypondchord> Slilypondchord;

/*!
\brief A lilypond command representation.

  A command is represented by its name and optional parameters.
  A range command contains enclosed elements. //USER ???
*/
//______________________________________________________________________________
class EXP lilypondcmd : public lilypondelement {
  public:

    enum BackSlashPrefix { kWithBackslash, kWithoutBackslash };

    static SMARTP<lilypondcmd> create(
      std::string name, 
      BackSlashPrefix backslashPrefix=kWithBackslash);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondcmd(std::string name, BackSlashPrefix backslashPrefix=kWithBackslash);
    virtual ~lilypondcmd();
};
typedef SMARTP<lilypondcmd> Slilypondcmd;

/*!
\brief A lilypond variable/value association representation.
*/
//______________________________________________________________________________
class EXP lilypondvariablevalueassociation : public lilypondelement {
  public:

    enum VarValSeparator   { kSpace, kEqualSign };
    enum QuotesKind        { kQuotesAroundValue, kNoQuotesAroundValue };
    enum CommentedKind     { kCommented, kUncommented };

    static SMARTP<lilypondvariablevalueassociation> create(
              std::string     variableName,
              std::string     value, 
              VarValSeparator varValSeparator,
              QuotesKind      quotesKind,
              CommentedKind   commentKind );
    
    void    changeAssociation (std::string value);
    
    std::string getVariableValue () const { return fVariableValue; };

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondvariablevalueassociation(
              std::string     variableName,
              std::string     value, 
              VarValSeparator varValSeparator,
              QuotesKind      quotesKind,
              CommentedKind   commentedKind );
    virtual ~lilypondvariablevalueassociation();
  
  private:

    std::string     fVariableName;
    std::string     fVariableValue;
    VarValSeparator fVarValSeparator;
    QuotesKind      fQuotesKind;
    CommentedKind   fCommentedKind;
};
typedef SMARTP<lilypondvariablevalueassociation> Slilypondvariablevalueassociation;

/*!
\brief A lilypond Scheme variable/value association representation.
*/
//______________________________________________________________________________
class EXP lilypondschemevariablevalueassociation : public lilypondelement {
  public:

    enum CommentedKind     { kCommented, kUncommented };

    static SMARTP<lilypondschemevariablevalueassociation> create(
              std::string     variableName,
              std::string     value, 
              CommentedKind   commentKind );
    
    void    changeAssociation (std::string value);
    
    std::string getVariableValue () const { return fVariableValue; };

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondschemevariablevalueassociation(
              std::string     variableName,
              std::string     value, 
              CommentedKind   commentedKind );
    virtual ~lilypondschemevariablevalueassociation();
  
  private:

    std::string     fVariableName;
    std::string     fVariableValue;
    CommentedKind   fCommentedKind;
};
typedef SMARTP<lilypondschemevariablevalueassociation> Slilypondschemevariablevalueassociation;

/*!
\brief A lilypond global settings representation.

  A global setting is represented by a variable/value association
*/
//______________________________________________________________________________
class EXP lilypondglobalsettings : public lilypondelement {
  public:

    enum VarValSeparator { kSpace, kEqualSign };

    static SMARTP<lilypondglobalsettings> create(VarValSeparator varValSeparator);
    
    void    setAssociation    (std::string var, std::string val);
    void    changeAssociation (std::string var, std::string val);
    
    std::map<std::string, std::string>
            getAssociations () const { return fAssociations; };

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondglobalsettings(VarValSeparator varValSeparator);
    virtual ~lilypondglobalsettings();
  
  private:

    std::map<std::string, std::string> fAssociations;
    VarValSeparator                    fVarValSeparator;
 
};
typedef SMARTP<lilypondglobalsettings> Slilypondglobalsettings;

/*!
\brief A lilypond Scheme global settings representation.

  A Scheme global setting is represented by a variable/value association
*/
//______________________________________________________________________________
class EXP lilypondschemeglobalsettings : public lilypondelement {
  public:

    enum VarValSeparator { kSpace, kEqualSign };

    static SMARTP<lilypondschemeglobalsettings> create();
    
    void    setAssociation    (std::string var, std::string val);
    void    changeAssociation (std::string var, std::string val);
    
    std::map<std::string, std::string>
            getAssociations () const { return fAssociations; };

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondschemeglobalsettings();
    virtual ~lilypondschemeglobalsettings();
  
  private:

    std::map<std::string, std::string> fAssociations;
 
};
typedef SMARTP<lilypondschemeglobalsettings> Slilypondschemeglobalsettings;

/*!
\brief A lilypond header representation.

  A header is represented by variable/value pairs
*/
//______________________________________________________________________________
class EXP lilypondheader : public lilypondelement {
  public:

    static SMARTP<lilypondheader> create();
    
    void                    setScorePartwise   (S_score_partwise val)   { fScorePartwise = val; }
    S_score_partwise        getScorePartwise   () const                 { return fScorePartwise; }

    void                    setWorkNumber      (S_work_number val)      { fWorkNumber = val; }
    S_work_number           getWorkNumber      () const                 { return fWorkNumber; }

    void                    setWorkTitle       (S_work_title val)       { fWorkTitle = val; }
    S_work_title            getWorkTitle       () const                 { return fWorkTitle; }

    void                    setMovementNumber  (S_movement_number val)  { fMovementNumber = val; }
    S_movement_number       getMovementNumber  () const                 { return fMovementNumber; }

    void                    setMovementTitle   (S_movement_title val)   { fMovementTitle = val; }
    S_movement_title        getMovementTitle   () const                 { return fMovementTitle; }

    void                    addCreator         (S_creator val)          { fCreators.push_back(val); }
    std::vector<S_creator>  getCreators        () const                 { return fCreators; };

    void                    setRights          (S_rights val)           { fRights = val; }
    S_rights                getRights          () const                 { return fRights; }

    void                    addSoftware        (S_software val)         { fSoftwares.push_back(val); }
    std::vector<S_software> getSoftwares       () const                 { return fSoftwares; };

    void                    setEncodingDate    (S_encoding_date val)    { fEncodingDate = val; }
    S_encoding_date         getEncodingDate    () const                 { return fEncodingDate; }

    void                    setScoreInstrument (S_score_instrument val) { fScoreInstrument = val; }
    S_score_instrument      getScoreInstrument () const                 { return fScoreInstrument; }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondheader();
    virtual ~lilypondheader();
  
  private:

    S_score_partwise        fScorePartwise; // may contain MusicXML version
    S_work_number           fWorkNumber;
    S_work_title            fWorkTitle;
    S_movement_number       fMovementNumber;
    S_movement_title        fMovementTitle;
    std::vector<S_creator>  fCreators;
    S_rights                fRights;
    std::vector<S_software> fSoftwares;
    S_encoding_date         fEncodingDate;
    S_score_instrument      fScoreInstrument;

};
typedef SMARTP<lilypondheader> Slilypondheader;

/*!
\brief A lilypond paper representation.

  A paper is represented by variable/value pairs
*/
//______________________________________________________________________________
class EXP lilypondpaper : public lilypondelement {
  public:

    static SMARTP<lilypondpaper> create();
    
    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondpaper();
    virtual ~lilypondpaper();
  
  private:

 
};
typedef SMARTP<lilypondpaper> Slilypondpaper;

/*!
\brief A lilypond layout representation.

  A layout is represented by variable/value pairs
*/
//______________________________________________________________________________
class EXP lilypondlayout : public lilypondelement {
  public:

    static SMARTP<lilypondlayout> create();
    
    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondlayout();
    virtual ~lilypondlayout();
  
  private:
};
typedef SMARTP<lilypondlayout> Slilypondlayout;

/*!
\brief A lilypond part representation.

  A part is represented by a its string contents
*/
//______________________________________________________________________________
class EXP lilypondpart : public lilypondelement {
  public:

    static SMARTP<lilypondpart> create(
      std::string name, bool absoluteCode, bool generateNumericalTime);
    
    std::string       getPartName () const         { return fPartName; }
    bool              getAbsoluteCode () const     { return fPartAbsoluteCode; }
    Slilypondsequence getPartLilypondsequence () const  { return fPartLilypondsequence; }

    void              addLyricsToPart (Slilypondlyrics lyr) { fPartLyrics.push_back(lyr); }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondpart(std::string name, bool absoluteCode, bool generateNumericalTime);
    virtual ~lilypondpart();
  
  private:

    std::string       fPartName;
    bool              fPartAbsoluteCode;
    bool              fGenerateNumericalTime;
    
    // the implicit sequence containing the code generated for the part
    Slilypondsequence fPartLilypondsequence;
    
    // the lyrics stanzas, if any, associated with the part
    std::vector<Slilypondlyrics> fPartLyrics;
};
typedef SMARTP<lilypondpart> Slilypondpart;
typedef std::map<std::string, Slilypondpart> lilypondpartsmap;

/*!
\brief A lilypond barline representation.

  A barline is represented by the number of the next bar
*/
//______________________________________________________________________________
class EXP lilypondbarline : public lilypondelement {
  public:
    
    static SMARTP<lilypondbarline> create(int nextBarNumber);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondbarline(int nextBarNumber);
    virtual ~lilypondbarline();
  
  private:

    int fNextBarNumber;
};
typedef SMARTP<lilypondbarline> Slilypondbarline;

/*!
\brief A lilypond comment representation.

  A comment is represented by its contents
*/
//______________________________________________________________________________
class EXP lilypondcomment : public lilypondelement {
  public:
    
    enum GapKind { kGapAfterwards, kNoGapAfterwards };

    static SMARTP<lilypondcomment> create(std::string contents, GapKind gapKind = kNoGapAfterwards);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondcomment(std::string contents, GapKind gapKind = kNoGapAfterwards);
    virtual ~lilypondcomment();
  
  private:

    std::string fContents;
    GapKind     fGapKind;
};
typedef SMARTP<lilypondcomment> Slilypondcomment;

/*!
\brief A lilypond break representation.

  A break is represented by the number of the next bar
*/
//______________________________________________________________________________
class EXP lilypondbreak : public lilypondelement {
  public:
    
    static SMARTP<lilypondbreak> create(int nextBarNumber);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondbreak(int nextBarNumber);
    virtual ~lilypondbreak();
  
  private:

    int fNextBarNumber;
};
typedef SMARTP<lilypondbreak> Slilypondbreak;

/*!
\brief A lilypond barnumbercheck representation.

  A barnumbercheck is represented by the number of the next bar
*/
//______________________________________________________________________________
class EXP lilypondbarnumbercheck : public lilypondelement {
  public:
    
    static SMARTP<lilypondbarnumbercheck> create(int nextBarNumber);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondbarnumbercheck(int nextBarNumber);
    virtual ~lilypondbarnumbercheck();
  
  private:

    int fNextBarNumber;
};
typedef SMARTP<lilypondbarnumbercheck> Slilypondbarnumbercheck;

/*!
\brief A lilypond tuplet representation.

  A tuplet is represented by the number of actual notes and
  normal notes, i.e. a triplet is a tuplet with 3 actual notes
  played for the duration of 2 actual notes
*/
//______________________________________________________________________________
class EXP lilypondtuplet : public lilypondelement {
  public:
    
    static SMARTP<lilypondtuplet> create();

    enum TupletKind {
      kStartTuplet, kContinueTuplet, kStopTuplet, 
      k_NoTuplet };

    void updateTuplet (int number, int actualNotes, int normalNotes);
    
    int getTupletNumber () const { return fTupletNumber; }

    void addElementToTuplet (Slilypondelement elem) { fTupletContents.push_back(elem); }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondtuplet();
    virtual ~lilypondtuplet();
  
  private:

    int fTupletNumber;
    
    int fActualNotes;
    int fNormalNotes;
    
    std::vector<Slilypondelement> fTupletContents;
};
typedef SMARTP<lilypondtuplet> Slilypondtuplet;

/*!
\brief A lilypond beam representation.

  A beam is represented by a BeamKind value
*/
//______________________________________________________________________________
class EXP lilypondbeam : public lilypondelement {
  public:

    enum BeamKind {
            kBeginBeam, kContinueBeam, kEndBeam, 
            k_NoBeam };
    
    static SMARTP<lilypondbeam> create(int number, BeamKind kind);

    BeamKind getBeamKind () const { return fBeamKind; }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondbeam(int number, BeamKind kind);
    virtual ~lilypondbeam();
  
  private:

    int      fBeamNumber;
    BeamKind fBeamKind;
};
typedef SMARTP<lilypondbeam> Slilypondbeam;

/*!
\brief A lilypond dynamics representation.

  A dynamics is represented by a DynamicsKind value
*/
//______________________________________________________________________________
class EXP lilyponddynamics : public lilypondelement {
  public:

    enum DynamicsKind {
            kFDynamics, kPDynamics, 
            k_NoDynamics };
    
    static SMARTP<lilyponddynamics> create(DynamicsKind kind);

    DynamicsKind getDynamicsKind () const { return fDynamicsKind; }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilyponddynamics(DynamicsKind kind);
    virtual ~lilyponddynamics();
  
  private:

    DynamicsKind fDynamicsKind;
};
typedef SMARTP<lilyponddynamics> Slilyponddynamics;

/*!
\brief A lilypond wedge representation.

  A wedge is represented by a WedgeKind value (hairpins in LilyPond)
*/
//______________________________________________________________________________
class EXP lilypondwedge : public lilypondelement {
  public:

    enum WedgeKind { kCrescendoWedge, kDecrescendoWedge, kStopWedge };
    
    static SMARTP<lilypondwedge> create(WedgeKind kind);

    WedgeKind getWedgeKind () const        { return fWedgeKind; }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondwedge(WedgeKind kind);
    virtual ~lilypondwedge();
  
  private:

    WedgeKind fWedgeKind;
};
typedef SMARTP<lilypondwedge> Slilypondwedge;

/*!
\brief A lilypond lyrics representation.

  A lyrics is represented by a its string contents
*/
//______________________________________________________________________________
class EXP lilypondlyrics : public lilypondelement {
  public:

    static SMARTP<lilypondlyrics> create(std::string name, std::string contents);
    
    std::string getContents () const { return fLyricsContents; }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondlyrics(std::string name, std::string contents);
    virtual ~lilypondlyrics();
  
  private:

    std::string fLyricsName, fLyricsContents;
};
typedef SMARTP<lilypondlyrics> Slilypondlyrics;



/*!
\brief A lilypond time representation.

  A time is represented by the numerator and denominator
*/
//______________________________________________________________________________
class EXP lilypondtime : public lilypondelement {
  public:
    
    static SMARTP<lilypondtime> create(int numerator, int denominator, bool generateNumericalTime);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondtime(int numerator, int denominator, bool generateNumericalTime);
    virtual ~lilypondtime();
  
  private:

    // JMI int fNumerator, fDenominator;
    rational fRational;
    bool     fGenerateNumericalTime;
};
typedef SMARTP<lilypondtime> Slilypondtime;

/*!
\brief A lilypond clef representation.

  A clef is represented by its name
*/
//______________________________________________________________________________
class EXP lilypondclef : public lilypondelement {
  public:
    
    static SMARTP<lilypondclef> create(std::string clefName);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondclef(std::string clefName);
    virtual ~lilypondclef();
  
  private:

    std::string fClefName;
};
typedef SMARTP<lilypondclef> Slilypondclef;

/*!
\brief A lilypond key representation.

  A key is represented by the tonic and major/minor
*/
//______________________________________________________________________________
class EXP lilypondkey : public lilypondelement {
  public:
    
    enum KeyMode { kMajor, kMinor };

    static SMARTP<lilypondkey> create(std::string tonicNote, KeyMode keyMode);

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondkey(std::string tonicNote, KeyMode keyMode);
    virtual ~lilypondkey();
  
  private:

    std::string   fTonicNote;
    KeyMode       fKeyMode;
};
typedef SMARTP<lilypondkey> Slilypondkey;

/*!
\brief A lilypond midi representation.

  A midi is represented by variable/value pairs

*/
//______________________________________________________________________________
class EXP lilypondmidi : public lilypondelement {
  public:

    static SMARTP<lilypondmidi> create();

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondmidi();
    virtual ~lilypondmidi();
  
  private:
  
};
typedef SMARTP<lilypondmidi> Slilypondmidi;

/*!
\brief A lilypond score representation.

  A score is represented by parallel music, score layout and midi
*/
//______________________________________________________________________________
class EXP lilypondscore : public lilypondelement {
  public:

    static SMARTP<lilypondscore> create();
     
    Slilypondparallel getScoreParallelMusic () const { return fScoreParallelMusic; }
    Slilypondlayout   getScoreLayout        () const { return fScoreLayout; }
    Slilypondmidi     getScoreMidi          () const { return fScoreMidi; }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondscore();
    virtual ~lilypondscore();
  
  private:
  
    Slilypondparallel fScoreParallelMusic;
    Slilypondlayout   fScoreLayout;
    Slilypondmidi     fScoreMidi;    
};
typedef SMARTP<lilypondscore> Slilypondscore;

/*!
\brief A lilypond new staff representation.

  A new staff is represented by a sequence of elements
*/
//______________________________________________________________________________
class EXP lilypondnewstaffcmd : public lilypondelement {
  public:

    static SMARTP<lilypondnewstaffcmd> create();
     
    void addElementToNewStaff (Slilypondelement elem) { fNewStaffElements.push_back(elem); }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondnewstaffcmd();
    virtual ~lilypondnewstaffcmd();
  
  private:
  
    std::vector<Slilypondelement> fNewStaffElements;
};
typedef SMARTP<lilypondnewstaffcmd> Slilypondnewstaffcmd;

/*!
\brief A lilypond new lyrics representation.

  A new lyrics is represented by a sequence of strings
*/
//______________________________________________________________________________
class EXP lilypondnewlyricscmd : public lilypondelement {
  public:

    static SMARTP<lilypondnewlyricscmd> create();
     
    void addElementToNewStaff (Slilypondelement elem) { fNewStaffElements.push_back(elem); }

    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondnewlyricscmd();
    virtual ~lilypondnewlyricscmd();
  
  private:
  
    std::vector<Slilypondelement> fNewStaffElements;
};
typedef SMARTP<lilypondnewlyricscmd> Slilypondnewlyricscmd;

/*!
\brief A lilypond new lyrics representation.

  A new lyrics is represented by a sequence of strings
*/
//______________________________________________________________________________
class EXP lilypondvariableusecmd : public lilypondelement {
  public:

    static SMARTP<lilypondvariableusecmd> create(std::string variableName);
    
    virtual void printStructure (std::ostream& os);
    virtual void printLilyPondCode (std::ostream& os);

  protected:

    lilypondvariableusecmd(std::string variableName);
    virtual ~lilypondvariableusecmd();
  
  private:
  
    std::string fVariableName;
};
typedef SMARTP<lilypondvariableusecmd> Slilypondvariableusecmd;


/*! @} */

}

  /*
  Duration is a positive number specified in division units.
 
  Musical notation duration is commonly represented as fractions. 
  The divisions element indicates how many divisions per quarter note are used to indicate a note's duration. 
  For example, if duration = 1 and divisions = 2, this is an eighth note duration. 
  */ 
   
  // MusicXML durations are in in divisions per quarter note,
  // LilyPond durations are in whole notes, hence the "*4" multiplication

#endif
