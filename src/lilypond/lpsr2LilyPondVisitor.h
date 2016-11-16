/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef __lpsr2LilyPondVisitor__
#define __lpsr2LilyPondVisitor__

#include <map>
#include <vector>

#include "lpsr.h"

//#include "musicxml2msr.h"

namespace MusicXML2
{

/*!
\addtogroup visitors
@{
*/

/*!
\brief Produces a summary of a MusicXML part.

  A part summary consists in 
  - a number of staves
  - a map that associates each stave with the corresponding number of notes
  - a map that associates each stave with the corresponding voices and notes
  - a map that associates each stave with the correcponding lyricss
*/
class lpsr2LilyPondVisitor :

  // LPSR
  
  public visitor<S_lpsrScore>,
  
  public visitor<S_lpsrVarValAssoc>,
  public visitor<S_lpsrSchemeVarValAssoc>,

  public visitor<S_lpsrHeader>,
  public visitor<S_lpsrPaper>,
  public visitor<S_lpsrLayout>,
  
  public visitor<S_lpsrScoreCommand>,

  public visitor<S_lpsrParallelMusic>,

  public visitor<S_lpsrNewStaffCommand>,
  public visitor<S_lpsrNewStaffgroupCommand>,
  public visitor<S_lpsrUseVoiceCommand>,
  public visitor<S_lpsrNewlyricsCommand>,
  public visitor<S_lpsrVariableUseCommand>,
  
  public visitor<S_lpsrContext>,
  
  public visitor<S_lpsrBarCommand>,

  public visitor<S_lpsrComment>,

  // MSR
  
  public visitor<S_msrScore>,
  
  public visitor<S_msrPartgroup>,
  
  public visitor<S_msrPart>,
  
  public visitor<S_msrStaff>,
  
  public visitor<S_msrVoice>,

  public visitor<S_msrLyrics>,
  public visitor<S_msrLyricschunk>,
  
  public visitor<S_msrClef>,
  public visitor<S_msrKey>,
  public visitor<S_msrTime>,
  public visitor<S_msrTempo>,
  
  public visitor<S_msrSequentialMusic>,
  
  public visitor<S_msrDuration>,
  
  public visitor<S_msrArticulation>,

  public visitor<S_msrDynamics>,
  public visitor<S_msrWedge>,
  
  public visitor<S_msrNote>,
  public visitor<S_msrBeam>,
    
  public visitor<S_msrChord>,
  
  public visitor<S_msrTuplet>,
  
  public visitor<S_msrSlur>,
  
  public visitor<S_msrBarLine>,
  public visitor<S_msrBarNumberCheck>,
  public visitor<S_msrBreak>,
  
  public visitor<S_msrRepeat>,
      
  public visitor<S_msrMidi>

{
  public:
  
    lpsr2LilyPondVisitor (
      S_msrOptions&  msrOpts,
      S_lpsrOptions& lpsrOpts,
      ostream&       os,
      S_lpsrScore    lpScore);
        
    virtual ~lpsr2LilyPondVisitor ();

    void generateLilyPondCodeFromLpsrScore ();

    S_lpsrScore getLpsrScore () const
        { return fLpsrScore; };
    
  protected:
      
    // LPSR
  
    virtual void visitStart (S_lpsrScore& elt);
    virtual void visitEnd   (S_lpsrScore& elt);

    virtual void visitStart (S_lpsrVarValAssoc& elt);
    virtual void visitEnd   (S_lpsrVarValAssoc& elt);

    virtual void visitStart (S_lpsrSchemeVarValAssoc& elt);
    virtual void visitEnd   (S_lpsrSchemeVarValAssoc& elt);

    virtual void visitStart (S_lpsrHeader& elt);
    virtual void visitEnd   (S_lpsrHeader& elt);

    virtual void visitStart (S_lpsrPaper& elt);
    virtual void visitEnd   (S_lpsrPaper& elt);

    virtual void visitStart (S_lpsrLayout& elt);
    virtual void visitEnd   (S_lpsrLayout& elt);

    virtual void visitStart (S_lpsrScoreCommand& elt);
    virtual void visitEnd   (S_lpsrScoreCommand& elt);

    virtual void visitStart (S_lpsrParallelMusic& elt);
    virtual void visitEnd   (S_lpsrParallelMusic& elt);

    virtual void visitStart (S_lpsrNewStaffgroupCommand& elt);
    virtual void visitEnd   (S_lpsrNewStaffgroupCommand& elt);
    
    virtual void visitStart (S_lpsrNewStaffCommand& elt);
    virtual void visitEnd   (S_lpsrNewStaffCommand& elt);
    
    virtual void visitStart (S_lpsrUseVoiceCommand& elt);
    virtual void visitEnd   (S_lpsrUseVoiceCommand& elt);
  
    virtual void visitStart (S_lpsrNewlyricsCommand& elt);
    virtual void visitEnd   (S_lpsrNewlyricsCommand& elt);
    
    virtual void visitStart (S_lpsrVariableUseCommand& elt);
    virtual void visitEnd   (S_lpsrVariableUseCommand& elt);
    
    virtual void visitStart (S_lpsrContext& elt);
    virtual void visitEnd   (S_lpsrContext& elt);
  
    virtual void visitStart (S_lpsrBarCommand& elt);
    virtual void visitEnd   (S_lpsrBarCommand& elt);

    virtual void visitStart (S_lpsrComment& elt);
    virtual void visitEnd   (S_lpsrComment& elt);

    // MSR

    virtual void visitStart (S_msrScore& elt);
    virtual void visitEnd   (S_msrScore& elt);

    virtual void visitStart (S_msrPartgroup& elt);
    virtual void visitEnd   (S_msrPartgroup& elt);

    virtual void visitStart (S_msrPart& elt);
    virtual void visitEnd   (S_msrPart& elt);

    virtual void visitStart (S_msrStaff& elt);
    virtual void visitEnd   (S_msrStaff& elt);

    virtual void visitStart (S_msrVoice& elt);
    virtual void visitEnd   (S_msrVoice& elt);

    virtual void visitStart (S_msrLyrics& elt);
    virtual void visitEnd   (S_msrLyrics& elt);

    virtual void visitStart (S_msrLyricschunk& elt);
    virtual void visitEnd   (S_msrLyricschunk& elt);

    virtual void visitStart (S_msrClef& elt);
    virtual void visitEnd   (S_msrClef& elt);

    virtual void visitStart (S_msrKey& elt);
    virtual void visitEnd   (S_msrKey& elt);

    virtual void visitStart (S_msrTime& elt);
    virtual void visitEnd   (S_msrTime& elt);

    virtual void visitStart (S_msrTempo& elt);
    virtual void visitEnd   (S_msrTempo& elt);

    virtual void visitStart (S_msrSequentialMusic& elt);
    virtual void visitEnd   (S_msrSequentialMusic& elt);

    virtual void visitStart (S_msrDuration& elt);
    virtual void visitEnd   (S_msrDuration& elt);

    virtual void visitStart (S_msrArticulation& elt);
    virtual void visitEnd   (S_msrArticulation& elt);

    virtual void visitStart (S_msrDynamics& elt);
    virtual void visitEnd   (S_msrDynamics& elt);

    virtual void visitStart (S_msrWedge& elt);
    virtual void visitEnd   (S_msrWedge& elt);

    virtual void visitStart (S_msrNote& elt);
    virtual void visitEnd   (S_msrNote& elt);

    virtual void visitStart (S_msrBeam& elt);
    virtual void visitEnd   (S_msrBeam& elt);

    virtual void visitStart (S_msrChord& elt);
    virtual void visitEnd   (S_msrChord& elt);

    virtual void visitStart (S_msrTuplet& elt);
    virtual void visitEnd   (S_msrTuplet& elt);

    virtual void visitStart (S_msrSlur& elt);
    virtual void visitEnd   (S_msrSlur& elt);

    virtual void visitStart (S_msrBarLine& elt);
    virtual void visitEnd   (S_msrBarLine& elt);

    virtual void visitStart (S_msrBarNumberCheck& elt);
    virtual void visitEnd   (S_msrBarNumberCheck& elt);

    virtual void visitStart (S_msrBreak& elt);
    virtual void visitEnd   (S_msrBreak& elt);

    virtual void visitStart (S_msrRepeat& elt);
    virtual void visitEnd   (S_msrRepeat& elt);

    virtual void visitStart (S_msrMidi& elt);
    virtual void visitEnd   (S_msrMidi& elt);

    string noteMsrPitchAsLilyPondString (S_msrNote& note);
    
  private:
                     
    S_msrOptions         fMsrOptions;
    S_lpsrOptions        fLpsrOptions;
    ostream&             fOstream;
    S_lpsrScore          fVisitedLpsrScore;

    // the LPSR score we're building
    // ------------------------------------------------------
    S_lpsrScore          fLpsrScore;

    // score
    // ------------------------------------------------------
    S_msrScore           fCurrentMsrScoreClone;
    bool                 fOnGoingScoreCommand;
    
    // part groups
    // ------------------------------------------------------
    S_msrPartgroup       fCurrentMsrPartGroupClone;
    
    // parts
    // ------------------------------------------------------
    S_msrPart            fCurrentMsrPartClone;
    
    // staves
    // ------------------------------------------------------
    S_msrStaff           fCurrentMsrStaffClone;
    // prevent clef, key and time from being handled twice
    bool                 fOnGoingStaff;

    // voices
    // ------------------------------------------------------
    S_msrVoice           fCurrentMsrVoiceClone;
    
    // lyrics
    // ------------------------------------------------------
    S_msrLyrics          fCurrentMsrLyricsClone;

    // lyrics chunks
    // ------------------------------------------------------
    S_msrLyricschunk     fCurrentMsrLyricschunkClone;

    // sequential music
    // ------------------------------------------------------
// JMI    S_msrSequentialMusic fCurrentMsrSequentialMusicClone;
    
    // chords
    // ------------------------------------------------------
// JMI     S_msrChord           fCurrentMsrChordClone;
    
    // tuplets
    // ------------------------------------------------------
// JMI     S_msrTuplet          fCurrentMsrTupletClone;

    // header handling
    // ------------------------------------------------------
    bool                 fOnGoingHeader;

};

/*
    // the score we're building
    // ------------------------------------------------------
    S_msrScore              fMsrScore;

    // part group handling
    // ------------------------------------------------------
    int                     fCurrentPartgroupNumber;
    string                  fCurrentPartgroupType;
    string                  fCurrentPartgroupName;
    string                  fCurrentPartgroupAbbreviation;
    string                  fCurrentPartgroupSymbol;
    int                     fCurrentPartgroupSymbolDefaultX;
    string                  fCurrentPartgroupBarline;

    // an implicit part group has to be created
    // if none is specified in the MusicXML data,
    // in which case a part group "stop" has to be forced later
    S_msrPartgroup          fImplicitPartgroup;
    S_msrPartgroup          createImplicitMSRPartgroup (
                              int inputLineNumber);
    
    // part groups numbers can be re-used, they're no identifier
    // we use a map to access them by part group number
    msrPartgroupsMap        fPartgroupsMap;
    S_msrPartgroup          fetchPartgroupInThisVisitor (
                              int partGroupNumber);

    // MusicXML allows part groups to overlap,
    // we use a list in which part groups are orderd by
    // increasing part group <default-x>
    // (all of them they are negative)    
    // the current part group is the front of the list
    
    msrPartgroupsList       fPartgroupsList;
    void                    showPartgroupsData (string context);
    void                    handlePartgroupStart (
                              int                               inputLineNumber,
                              msrPartgroup::PartgroupSymbolKind partGroupSymbol,
                              bool                              partGroupBarline);
    void                    handlePartgroupStop (
                              int inputLineNumber);

    // staff handling
    // ------------------------------------------------------
    int                     fCurrentStaffNumber;
    S_msrStaff              fCurrentStaff;

    // part handling
    // ------------------------------------------------------
    string                  fCurrentPartMusicXMLID;
    string                  fCurrentPartName;
    string                  fCurrentPartAbbreviation;
    string                  fCurrentPartInstrumentName;

    msrPartsMap             fPartsMap;
    S_msrPart               fCurrentPart;

    // voice handling
    // ------------------------------------------------------
    int                     fCurrentVoiceNumber;
    S_msrVoice              fCurrentVoice;
    
    // key handling
    // ------------------------------------------------------
    int                     fCurrentKeyStaffNumber;
    int                     fCurrentFifths;
    int                     fCurrentCancel;
    string                  fCurrentMode;

    // clef handling
    // ------------------------------------------------------
    string                  fCurrentClefSign;
    int                     fCurrentClefLine;
    int                     fCurrentClefOctaveChange; // JMI
    int                     fCurrentClefStaffNumber;

    // direction handling
    // ------------------------------------------------------
    string fCurrentDirectionPlacement;
    string fCurrentDirectionWords;
    bool   fOnGoingDirection;
  
    // metronome handling
    // ------------------------------------------------------
    vector<musicXMLBeatData>
                            fBeatsData;
    int                     fPerMinute;
    musicXMLBeatData        fCurrentBeat;
    bool                    fParentheses;

    // time handling
    // ------------------------------------------------------
    int                     fCurrentTimeStaffNumber;
    string                  fCurrentTimeSymbol;
    int                     fCurrentTimeBeats;
    int                     fCurrentTimeBeatType;
    bool                    fCurrentTimeSenzaMisura;

    // lyrics handling
    // ------------------------------------------------------
    // the last sysllabic spec met (single, begin, middle or end)
    string                  fCurrentSyllabic;
    msrLyricschunk::LyricschunkType
                            fCurrentLyricschunkType;
    // the last lyrics fragment met
    string                  fCurrentText;
    bool                    fCurrentElision;
    
    int                     fCurrentLyricsNumber;
    bool                    fCurrentNoteHasLyrics;
    S_msrLyrics             fCurrentLyrics;
    bool                    fCurrentLyricsHasText;
    void                    handleLyricsText (
                              int inputLineNumber);

    // repeat handling
    // ------------------------------------------------------
    string                  fCurrentBarlineLocation;
    string                  fCurrentBarStyle;
    string                  fCurrentRepeatDirection;
    string                  fCurrentEndingType;
    int                     fCurrentEndingNumber;

    // dividing quater notes in MusicXML
    // ------------------------------------------------------
    int                     fCurrentMusicXMLDivisions;

    // description of the current MusicXML note
    musicXMLNoteData        fMusicXMLNoteData;

    // unpitched notes handling
    // ------------------------------------------------------
    char                    fDisplayStep;
    int                     fDisplayOctave;

    // stem handling
    // ------------------------------------------------------
    enum StemDirection { kStemNeutral, kStemUp, kStemDown };
    
    string                  fCurrentStem;
    StemDirection           fCurrentStemDirection;

    // beam handling
    // ------------------------------------------------------
    string                  fCurrentBeam;
    int                     fCurrentBeamNumber; 

    // note/rest handling
    // ------------------------------------------------------
    void                    handleStandaloneNoteOrRest (
                              S_msrNote newNote);

    // ------------------------------------------------------
    // chord handling
    S_msrChord              fCurrentChord; // cannot be local to a method? JMI
    bool                    fOnGoingChord;
    S_msrChord              createChordFromCurrentNote ();
    void                    handleNoteBelongingToAChord (
                              S_msrNote newNote);
    
    // ------------------------------------------------------
    // articulations handling
    list<S_msrArticulation> fCurrentArticulations;
    
    // dynamics and wedges remain pending until the next note
    // (they precede the note in MusicXML but follow it in LilyPond)
    msrDynamicssList        fPendingDynamics;
    msrWedgesList           fPendingWedges;
    void                    attachPendingDynamicsAndWedgesToNote (
                              S_msrNote note);
       
    // description of the current MSR note
    // ------------------------------------------------------
    string                  fCurrentNoteType;
    S_msrNote               fCurrentNote;
    bool                    fOnGoingNote;

    // tuplet handling
     // ------------------------------------------------------
    int                     fCurrentActualNotes;
    int                     fCurrentNormalNotes;
    string                  fCurrentNormalNoteType;
    // embedded tuplets are numbered 1, 2, ...
    int                     fCurrentTupletNumber;
    msrTuplet::TupletKind   fCurrentTupletKind;
    // remains true until a S_tuplet of type "stop" is met
    bool                    fOnGoingTuplet;
    msrTupletsStack         fCurrentTupletsStack;

    void                    createTupletFromItsecondNote (
                              S_msrNote note);
    void                    finalizeTuplet (
                              S_msrNote note);
    void                    handleNoteBelongingToATuplet (
                              S_msrNote newNote);
         
    // another name for fCurrentNote, fCurrentChord, fCurrentTuplet
    // and the like
// JMI    S_msrElement           fCurrentElement;

    // ties handling
    // ------------------------------------------------------
    string                  fCurrentTiedType;
    string                  fCurrentTiedOrientation;

    // slurs handling
    // ------------------------------------------------------
    int                     fCurrentSlurNumber;
    string                  fCurrentSlurType;
    string                  fCurrentSlurPlacement;
    msrSlur::SlurKind       fCurrentSlurKind;
    bool                    fOnGoingSlur;

    // backup handling
    // ------------------------------------------------------
    int                     fCurrentBackupDuration;
    bool                    fOnGoingBackup;

    // forward handling
    // ------------------------------------------------------
    int                     fCurrentForwardDuration;
    int                     fCurrentForwardVoiceNumber;
    int                     fCurrentForwardStaffNumber;
    bool                    fOnGoingForward;
    */

/*! @} */

}

#endif