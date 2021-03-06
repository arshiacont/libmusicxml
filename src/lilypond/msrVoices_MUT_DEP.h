/*
  This file is to be included only by msrMutualDependencies.h,
  to satisfy declarations mutual dependencies.
*/

//______________________________________________________________________________
class msrVoice : public msrElement
{
  public:

    // constants
    // ------------------------------------------------------

    #define K_NO_VOICE_NUMBER                     -99
    #define K_VOICE_HARMONY_VOICE_BASE_NUMBER      20
    #define K_VOICE_FIGURED_BASS_VOICE_BASE_NUMBER 40

    // data types
    // ------------------------------------------------------

    enum msrVoiceKind {
      kVoiceRegular,
      kVoiceHarmony,       // for MusicXML <harmony/>, LilyPond ChordNames
      kVoiceFiguredBass }; // for MusicXML <figured-bass/>, LilyPond FiguredBass

    static string voiceKindAsString (
      msrVoiceKind voiceKind);

    enum msrVoiceRepeatPhaseKind {
      kVoiceRepeatPhaseNone,
      kVoiceRepeatPhaseAfterCommonPart,
      kVoiceRepeatPhaseAfterHookedEnding,
      kVoiceRepeatPhaseAfterHooklessEnding };

    static string voiceRepeatPhaseKindAsString (
      msrVoiceRepeatPhaseKind
        afterRepeatComponentPhaseKind);

    enum msrVoiceFinalizationStatusKind { // JMI ???
      kKeepVoice,
      kEraseVoice };

    static string voiceFinalizationStatusKindAsString (
      msrVoiceFinalizationStatusKind voiceFinalizationStatusKind);

    enum msrVoiceCreateInitialLastSegmentKind {
      kCreateInitialLastSegmentYes, kCreateInitialLastSegmentNo };

    // creation from MusicXML
    // ------------------------------------------------------

    static SMARTP<msrVoice> create (
      int          inputLineNumber,
      msrVoiceKind voiceKind,
      int          voiceNumber,
      msrVoiceCreateInitialLastSegmentKind
                   voiceCreateInitialLastSegmentKind,
      S_msrStaff   voiceStaffUpLink);

    SMARTP<msrVoice> createVoiceNewbornClone (
      S_msrStaff containingStaff);

    SMARTP<msrVoice> createVoiceDeepCopy (
      int          inputLineNumber,
      msrVoiceKind voiceKind,
      int          voiceNumber,
      S_msrStaff   containingStaff);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    // for regular voices
    msrVoice (
      int          inputLineNumber,
      msrVoiceKind voiceKind,
      int          voiceNumber,
      msrVoiceCreateInitialLastSegmentKind
                   voiceCreateInitialLastSegmentKind,
      S_msrStaff   voiceStaffUpLink);

    // destructor
    virtual ~msrVoice ();

  private:

    // initialisation
    // ------------------------------------------------------

    void                  initializeVoice (
                            msrVoiceCreateInitialLastSegmentKind
                             voiceCreateInitialLastSegmentKind);

  public:

    // set and get
    // ------------------------------------------------------

    // upLinks

    S_msrStaff            getVoiceStaffUpLink () const
                              { return fVoiceStaffUpLink; }

    // voice kind

    void                  setVoiceKind (msrVoiceKind voiceKind)
                            { fVoiceKind = voiceKind; }

    msrVoiceKind          getVoiceKind () const
                              { return fVoiceKind; }

    // voice numbers

    void                  setVoiceNumber (int voiceNumber)
                              { fVoiceNumber = voiceNumber; }

    int                   getVoiceNumber () const
                              { return fVoiceNumber; }

    void                  setRegularVoiceStaffSequentialNumber (
                            int regularVoiceStaffSequentialNumber);

    int                   getRegularVoiceStaffSequentialNumber () const
                              { return fRegularVoiceStaffSequentialNumber; }

    // voice name

    void                  setVoiceNameFromNumber (
                            int inputLineNumber,
                            int voiceNumber);

    string                getVoiceName () const
                              { return fVoiceName; }

    // harmonies

    S_msrVoice            getHarmonyVoiceForRegularVoiceForwardLink () const
                              { return fHarmonyVoiceForRegularVoiceForwardLink; }

    S_msrVoice            getRegularVoiceForHarmonyVoiceBackwardLink () const
                              { return fRegularVoiceForHarmonyVoiceBackwardLink; }

    // figured bass

    S_msrVoice            getFiguredBassVoiceForRegularVoiceForwardLink () const
                              { return fFiguredBassVoiceForRegularVoiceForwardLink; }

    S_msrVoice            getRegularVoiceForFiguredBassVoiceBackwardLink () const
                              { return fRegularVoiceForFiguredBassVoiceBackwardLink; }

    // stanzas

    const map<string, S_msrStanza>&
                          getVoiceStanzasMap () const
                              { return fVoiceStanzasMap; }

    // voice last segment

    void                  setVoiceLastSegmentInVoiceClone (
                            S_msrSegment segment);

    void                  appendSegmentToVoiceClone (
                            S_msrSegment segment);

    S_msrSegment          getVoiceLastSegment () const
                              { return fVoiceLastSegment; }

    // voice last appended note

    S_msrNote             getVoiceLastAppendedNote () const
                              { return fVoiceLastAppendedNote; }

    // voice shortest note

    rational              getVoiceShortestNoteDuration () const
                              { return fVoiceShortestNoteDuration; }

    rational              getVoiceShortestNoteTupletFactor () const
                              { return fVoiceShortestNoteTupletFactor; }

    // counters

    int                   getVoiceActualNotesCounter () const
                              { return fVoiceActualNotesCounter; }

    int                   getVoiceRestsCounter () const
                              { return fVoiceRestsCounter; }

    int                   getVoiceSkipsCounter () const
                              { return fVoiceSkipsCounter; }

    int                   getVoiceActualHarmoniesCounter () const
                              { return fVoiceActualHarmoniesCounter; }

    int                   getVoiceActualFiguredBassesCounter () const
                              { return fVoiceActualFiguredBassesCounter; }

    // has music been inserted in the voice?

    void                  setMusicHasBeenInsertedInVoice ()
                              { fMusicHasBeenInsertedInVoice = true; }

    bool                  getMusicHasBeenInsertedInVoice () const
                              { return fMusicHasBeenInsertedInVoice; }

    // regular measure ends detection

    void                  setWholeNotesSinceLastRegularMeasureEnd (
                            int      inputLineNumber,
                            rational value);

    rational              getWholeNotesSinceLastRegularMeasureEnd () const
                              { return fWholeNotesSinceLastRegularMeasureEnd; }

    // incomplete measures after repeats detection

    void                  setCurrentVoiceRepeatPhaseKind (
                            int      inputLineNumber,
                            msrVoiceRepeatPhaseKind
                                     afterRepeatComponentPhaseKind);

    msrVoiceRepeatPhaseKind
                          getCurrentVoiceRepeatPhaseKind () const
                              { return fCurrentVoiceRepeatPhaseKind; }


    // rests measures

    void                  setVoiceContainsRestMeasures (
                            int inputLineNumber);

    bool                  getVoiceContainsRestMeasures () const
                              { return fVoiceContainsRestMeasures; }

    // measures repeats

    void                  setVoiceContainsMeasuresRepeats (
                            int inputLineNumber);

    bool                  getVoiceContainsMeasuresRepeats () const
                              { return fVoiceContainsMeasuresRepeats; }

    // measures flat list
    const list<S_msrMeasure>&
                          getVoiceMeasuresFlatList () const
                              { return fVoiceMeasuresFlatList; }

  public:

    // public services
    // ------------------------------------------------------

    // upLinks

    S_msrPart             fetchVoicePartUpLink () const;

    // identity

    void                  changeVoiceIdentity ( // after a deep copy
                            int voiceNumber);

    // measures

    S_msrMeasure          createMeasureAndAppendItToVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            msrMeasure::msrMeasureImplicitKind
                                   measureImplicitKind);

    void                  setNextMeasureNumberInVoice (
                            int    inputLineNumber,
                            string nextMeasureNumber);

    // forward

    void                  appendPaddingNoteToVoice (
                            int      inputLineNumber,
                            rational forwardStepLength);

    // backup and padding

    void                  padUpToPositionInMeasureInVoice (
                            int      inputLineNumber,
                            rational wholeNotesPositionInMeasure);

    void                  backupByWholeNotesStepLengthInVoice (
                            int      inputLineNumber,
                            rational backupTargetMeasureElementPositionInMeasure);

    // clef, key, time

    void                  appendClefToVoice (S_msrClef clef);

    void                  appendKeyToVoice  (S_msrKey  key);

    void                  appendTimeToVoice (S_msrTime time);
    void                  appendTimeToVoiceClone (S_msrTime time);

    // notes

    S_msrNote             fetchVoiceFirstNonGraceNote () const;

    void                  registerShortestNoteIfRelevant (S_msrNote note);

    void                  registerNoteAsVoiceLastAppendedNote (S_msrNote note);

    // harmonies

    S_msrVoice            createHarmonyVoiceForRegularVoice (
                            int    inputLineNumber,
                            string currentMeasureNumber);

    // figured bass

    S_msrVoice            createFiguredBassVoiceForRegularVoice (
                            int    inputLineNumber,
                            string currentMeasureNumber);

    // transpose

    void                  appendTransposeToVoice (
                            S_msrTranspose transpose);

    // part name display

    void                  appendPartNameDisplayToVoice (
                            S_msrPartNameDisplay partNameDisplay);

    // part abbreviation display

    void                  appendPartAbbreviationDisplayToVoice (
                            S_msrPartAbbreviationDisplay partAbbreviationDisplay);

    // staff details

    void                  appendStaffDetailsToVoice (
                            S_msrStaffDetails staffDetails);

    // tempo

    void                  appendTempoToVoice (S_msrTempo tempo);

    // rehearsals

    void                  appendRehearsalToVoice (
                            S_msrRehearsal rehearsal);

    // octave shifts

    void                  appendOctaveShiftToVoice (
                            S_msrOctaveShift octaveShift);

    // scordaturas

    void                  appendScordaturaToVoice (
                            S_msrScordatura scordatura);

    // accordion registration

    void                  appendAccordionRegistrationToVoice (
                            S_msrAccordionRegistration
                              accordionRegistration);

    // harp pedals tuning

    void                  appendHarpPedalsTuningToVoice (
                            S_msrHarpPedalsTuning
                              harpPedalsTuning);

    // staff change

    void                  appendVoiceStaffChangeToVoice (
                            S_msrVoiceStaffChange voiceStaffChange);

    // notes

    void                  appendNoteToVoice      (S_msrNote note);
    void                  appendNoteToVoiceClone (S_msrNote note);

    // tremolos

    void                  appendDoubleTremoloToVoice (
                            S_msrDoubleTremolo doubleTremolo);

    // chords

    void                  appendChordToVoice  (S_msrChord chord);

    // tuplets

    void                  appendTupletToVoice (S_msrTuplet tuplet);

    // harmonies

    void                  appendHarmonyToVoice (
                            S_msrHarmony harmony);

    void                  appendHarmonyToVoiceClone (
                            S_msrHarmony harmony);

    // figured bass

    void                  appendFiguredBassToVoice (
                            S_msrFiguredBass figuredBass);

    void                  appendFiguredBassToVoiceClone (
                            S_msrFiguredBass figuredBass);

    // frames

    void                  appendFrameToVoice (
                            S_msrFrame frame);

    void                  appendFrameToVoiceClone (
                            S_msrFrame frame);

    // grace notes

    void                  addGraceNotesGroupBeforeAheadOfVoiceIfNeeded (
                            S_msrGraceNotesGroup graceNotesGroup);

    /*
    void                  appendGraceNotesToVoice (
                            S_msrGraceNotes graceNotes);

    void                  appendAfterGraceNotesToVoice (
                            S_msrAfterGraceNotes afterGraceNotes);

    void                  prependAfterGraceNotesToVoice (
                            S_msrAfterGraceNotes afterGraceNotes);
                            */

    // lyrics

    void                  appendSyllableToVoice ( // JMI
                            int           inputLineNumber,
                            string        stanzaNumber,
                            string        stanzaName,
                            S_msrSyllable syllable);

    // bar checks

    void                  appendBarCheckToVoice (
                            S_msrBarCheck barCheck);

    // bar number checks

    void                  appendBarNumberCheckToVoice (
                            S_msrBarNumberCheck barNumberCheck);

    // breaks

    void                  appendLineBreakToVoice (S_msrLineBreak lineBreak);
    void                  appendPageBreakToVoice (S_msrPageBreak pageBreak);

    // bar lines

    void                  prependBarlineToVoice (S_msrBarline barline);
    void                  appendBarlineToVoice (S_msrBarline barline);

    // segno

    void                  appendSegnoToVoice (S_msrSegno segno);

    // coda

    void                  appendCodaToVoice (S_msrCoda coda);

    // eyeglasses

    void                  appendEyeGlassesToVoice (
                            S_msrEyeGlasses eyeGlasses);

    // pedal

    void                  appendPedalToVoice (S_msrPedal pedal);

    // damp

    void                  appendDampToVoice (S_msrDamp damp);

    // damp all

    void                  appendDampAllToVoice (S_msrDampAll dampAll);

    // other elements

    void                  prependOtherElementToVoice (
                            S_msrMeasureElement elem);
    void                  appendOtherElementToVoice (
                            S_msrMeasureElement elem);
                            // for other types of elements not known
                            // in this header file, such as LPSR elements

    // last measure in voice

    S_msrMeasure          fetchVoiceLastMeasure (
                            int inputLineNumber) const;

    // last element in voice

    S_msrMeasureElement   fetchVoiceLastElement ( // JMI ???
                            int inputLineNumber) const;

    // removing elements from voice

    void                  removeNoteFromVoice (
                            int       inputLineNumber,
                            S_msrNote note);

    void                  removeElementFromVoice (
                            int          inputLineNumber,
                            S_msrElement element);

    S_msrMeasure          removeLastMeasureFromVoice (
                            int inputLineNumber);

    // segments

    void                  createNewLastSegmentForVoice (
                            int    inputLineNumber,
                            string context);

    void                  createNewLastSegmentFromItsFirstMeasureForVoice (
                            int          inputLineNumber,
                            S_msrMeasure firstMeasure,
                            string       context);

    // repeats

    void                  handleRepeatEndInVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            int    repeatTimes);

    void                  handleRepeatEndingStartInVoice (
                            int inputLineNumber);

    void                  handleRepeatEndingEndInVoice (
                            int       inputLineNumber,
                            string    repeatEndingNumber, // may be "1, 2"
                            msrRepeatEnding::msrRepeatEndingKind
                                      repeatEndingKind);

    void                  handleRepeatCommonPartStartInVoiceClone (
                            int inputLineNumber);

    void                  handleRepeatCommonPartEndInVoiceClone (
                            int inputLineNumber);

    void                  handleRepeatEndingStartInVoiceClone (
                            int       inputLineNumber,
                            msrRepeatEnding::msrRepeatEndingKind
                                      repeatEndingKind,
                            string    repeatEndingNumber); // may be "1, 2"

    void                  handleRepeatEndingEndInVoiceClone (
                            int       inputLineNumber,
                            string    repeatEndingNumber, // may be "1, 2"
                            msrRepeatEnding::msrRepeatEndingKind
                                      repeatEndingKind);

    void                  handleSegmentCloneEndInVoiceClone (
                            int          inputLineNumber,
                            S_msrSegment segmentClone);

/* JMI
    void                  finalizeRepeatEndInVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            int    repeatTimes);
                            */

    void                  handleRepeatStartInVoice (
                            int inputLineNumber);

    void                  handleRepeatStartInVoiceClone (
                            int         inputLineNumber,
                            S_msrRepeat repeat);

    void                  handleRepeatEndInVoiceClone (
                            int inputLineNumber);

    void                  appendRepeatCloneToVoiceClone (
                            int         inputLineNumber,
                            S_msrRepeat repeatCLone);

    void                  appendRepeatEndingCloneToVoice (
                            S_msrRepeatEnding repeatEndingClone);

    // rest measures

    void                  appendRestMeasuresToVoiceElementsList (
                            S_msrRestMeasures restMeasures);

    void                  createRestMeasuresInVoice (
                            int inputLineNumber,
                            int restMeasuresNumber);

    void                  appendRestMeasuresToVoice (
                            int               inputLineNumber,
                            S_msrRestMeasures restMeasures);

    void                  appendPendingRestMeasuresToVoice (
                            int inputLineNumber);

    void                  handleRestMeasuresStartInVoiceClone (
                            int               inputLineNumber,
                            S_msrRestMeasures restMeasures);

    void                  handleRestMeasuresEndInVoiceClone (
                            int inputLineNumber);

    void                  handleRestMeasuresContentsStartInVoiceClone (
                            int inputLineNumber);

    void                  handleRestMeasuresContentsEndInVoiceClone (
                            int inputLineNumber);

    void                  appendRestMeasuresCloneToVoiceClone ( // JMI ???
                            int               inputLineNumber,
                            S_msrRestMeasures restMeasuresClone);

    // measures repeats

    void                  appendMeasuresRepeatToVoiceElementsList (
                            S_msrMeasuresRepeat beatsRepeat);

    void                  appendMeasuresRepeatReplicaToVoice (
                            int inputLineNumber);

    void                  createMeasuresRepeatFromItsFirstMeasuresInVoice (
                            int inputLineNumber,
                            int beatsRepeatMeasuresNumber,
                            int beatsRepeatSlashesNumber);

    void                  appendMeasuresRepeatToVoice (
                            int                 inputLineNumber,
                            S_msrMeasuresRepeat beatsRepeat);

    void                  appendPendingMeasuresRepeatToVoice (
                            int inputLineNumber);

    void                  createMeasuresRepeatAndAppendItToVoiceClone (
                            int inputLineNumber,
                            int beatsRepeatMeasuresNumber,
                            int beatsRepeatSlashesNumber);

    void                  handleMeasuresRepeatStartInVoiceClone (
                            int                 inputLineNumber,
                            S_msrMeasuresRepeat beatsRepeat);

    void                  handleMeasuresRepeatEndInVoiceClone (
                            int inputLineNumber);

    void                  handleMeasuresRepeatPatternStartInVoiceClone (
                            int inputLineNumber);

    void                  handleMeasuresRepeatPatternEndInVoiceClone (
                            int inputLineNumber);

    void                  handleMeasuresRepeatReplicasStartInVoiceClone (
                            int inputLineNumber);

    void                  handleMeasuresRepeatReplicasEndInVoiceClone (
                            int inputLineNumber);

    void                  appendMeasuresRepeatCloneToVoiceClone ( // JMI ???
                            int                 inputLineNumber,
                            S_msrMeasuresRepeat beatsRepeatClone);

    // stanzas

    S_msrStanza           addStanzaToVoiceByItsNumber (
                            int    inputLineNumber,
                            string stanzaNumber);

    void                  addStanzaToVoiceWithoutCatchUp ( // JMI
                            S_msrStanza stanza);

    void                  addStanzaToVoice (
                            S_msrStanza stanza);

    S_msrStanza           createStanzaInVoiceIfNotYetDone (
                            int    inputLineNumber,
                            string stanzaNumber,
                            string stanzaName);

    S_msrStanza           fetchStanzaInVoice (
                            int    inputLineNumber,
                            string stanzaNumber,
                            string stanzaName);

    // strings

    // finalization

    void                  finalizeCurrentMeasureInVoice (
                            int inputLineNumber);

    void                  finalizeVoice (
                            int inputLineNumber);

    void                  collectVoiceMeasuresIntoFlatList (
                            int inputLineNumber);

  private:

    // private services
    // ------------------------------------------------------

    // voice last segment

    void                  appendVoiceLastSegmentToInitialVoiceElements (
                            int          inputLineNumber,
                            string       context);

    void                  moveVoiceLastSegmentToInitialVoiceElementsIfRelevant (
                            int          inputLineNumber,
                            string       context);

    // harmonies

    void                  appendHarmonyToHarmonyVoice (
                            S_msrHarmony harmony);

    // figured basses

    void                  appendFiguredBassToFiguredBassVoice (
                            S_msrFiguredBass figuredBass);

    // repeats

    S_msrRepeat           createARepeatAndStackIt (
                            int    inputLineNumber,
                            string context);

    S_msrRepeat           createARepeatCloneAndStackIt (
                            int         inputLineNumber,
                            S_msrRepeat repeat,
                            string      context);

    void                  popRepeatFromRepeatDescrsStack (
                            int         inputLineNumber,
                            S_msrRepeat repeat,
                            string      context);

    void                  pushRepeatOntoRepeatDescrsStack (
                            int         inputLineNumber,
                            S_msrRepeat repeat,
                            string      context);

    void                  appendRepeatToInitialVoiceElements (
                            int         inputLineNumber,
                            S_msrRepeat repeat,
                            string      context);

    void                  appendRepeatCloneToInitialVoiceElements (
                            int         inputLineNumber,
                            S_msrRepeat repeatCLone,
                            string      context);

    void                  handleVoiceLevelRepeatStartInVoice (
                            int inputLineNumber);

    void                  handleNestedRepeatStartInVoice (
                            int inputLineNumber);

    void                  handleVoiceLevelRepeatEndWithoutStartInVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            int    repeatTimes);

    void                  handleVoiceLevelContainingRepeatEndWithoutStartInVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            int    repeatTimes);

    void                  handleVoiceLevelRepeatEndWithStartInVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            int    repeatTimes);

    void                  handleVoiceLevelRepeatEndingStartWithoutExplicitStartInVoice (
                            int         inputLineNumber,
                            S_msrRepeat currentRepeat);

    void                  handleVoiceLevelRepeatEndingStartWithExplicitStartInVoice (
                            int inputLineNumber);

    void                  nestContentsIntoNewRepeatInVoice (
                            int inputLineNumber);

    void                  handleNestedRepeatEndingStartInVoice (
                            int inputLineNumber);

    void                  handleNestedRepeatEndInVoice (
                            int    inputLineNumber,
                            string measureNumber,
                            int    repeatTimes);

    void                  moveVoiceInitialElementsToRepeatCommonPart (
                            int                   inputLineNumber,
                            S_msrRepeatCommonPart repeatCommonPart,
                            string                context);

    void                  moveVoiceLastSegmentToRepeatCommonPart (
                            int                   inputLineNumber,
                            S_msrRepeatCommonPart repeatCommonPart,
                            string                context);

    void                  moveAllVoiceContentsToRepeatCommonPart (
                            int                   inputLineNumber,
                            S_msrRepeatCommonPart repeatCommonPart,
                            string                context);

    void                  moveVoiceLastSegmentToRepeatEnding (
                            int               inputLineNumber,
                            S_msrRepeatEnding repeatEnding,
                            string            context);

    void                  handleHookedRepeatEndingEndInVoice (
                            int       inputLineNumber,
                            string    repeatEndingNumber); // may be "1, 2"

    void                  handleHooklessRepeatEndingEndInVoice (
                            int       inputLineNumber,
                            string    repeatEndingNumber); // may be "1, 2"

    void                  handleHookedRepeatEndingEndInVoiceClone (
                            int       inputLineNumber,
                            string    repeatEndingNumber); // may be "1, 2"

    void                  handleHooklessRepeatEndingEndInVoiceClone (
                            int       inputLineNumber,
                            string    repeatEndingNumber); // may be "1, 2"

    // rest measures

    void                  appendRestMeasuresToInitialVoiceElements (
                            int               inputLineNumber,
                            S_msrRestMeasures restMeasures,
                            string            context);

    // measures repeats

    void                  appendMeasuresRepeatToInitialVoiceElements (
                            int                 inputLineNumber,
                            S_msrMeasuresRepeat measuresRepeat,
                            string              context);

    // beats repeats

    void                  appendBeatsRepeatToInitialVoiceElements (
                            int              inputLineNumber,
                            S_msrBeatsRepeat beatsRepeat,
                            string           context);

  public:

    // visitors
    // ------------------------------------------------------

    virtual void          acceptIn  (basevisitor* v);
    virtual void          acceptOut (basevisitor* v);

    virtual void          browseData (basevisitor* v);

  public:

    // print
    // ------------------------------------------------------

    string                voiceKindAsString () const;

    string                voiceNumberAsString () const;

    string                regularVoiceStaffSequentialNumberAsString () const;

    string                asShortString () const;
    string                asString () const;

    void                  displayVoice (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceRepeatsStackRestMeasuresMeasuresRepeatAndVoice (
                            int    inputLineNumber,
                            string context);

    virtual void          print (ostream& os) const;

  private:

    // fields
    // ------------------------------------------------------

    // upLinks

    S_msrStaff            fVoiceStaffUpLink;

    // two-way links
    S_msrVoice            fHarmonyVoiceForRegularVoiceForwardLink;
    S_msrVoice            fRegularVoiceForHarmonyVoiceBackwardLink;

    S_msrVoice            fFiguredBassVoiceForRegularVoiceForwardLink;
    S_msrVoice            fRegularVoiceForFiguredBassVoiceBackwardLink;

    // voice kind

    msrVoiceKind          fVoiceKind;

    // voice numbers

    // voice numbers in MusicXML may be greater than 4
    // and there can be holes
    int                   fVoiceNumber;

    // there can only be 4 regular voices in a staff
    // (those that can contain beamed notes)
    // and we need a number for the orientation of beams
    int                   fRegularVoiceStaffSequentialNumber;

    // voice name

    string                fVoiceName;


    // counters

    static int            gVoicesCounter;

    int                   fVoiceActualNotesCounter;
    int                   fVoiceRestsCounter;
    int                   fVoiceSkipsCounter;
    int                   fVoiceActualHarmoniesCounter;
    int                   fVoiceActualFiguredBassesCounter;

    // musically empty voices

    bool                  fMusicHasBeenInsertedInVoice;

    // regular measure ends detection

    rational              fWholeNotesSinceLastRegularMeasureEnd;

    // incomplete measures after repeats detection
    msrVoiceRepeatPhaseKind
                          fCurrentVoiceRepeatPhaseKind;

    // voice internal handling

    list<S_msrVoiceElement>
                          fInitialVoiceElementsList;

     // stanzas

    map<string, S_msrStanza>
                          fVoiceStanzasMap;

   // segments

    // fVoiceLastSegment contains the music
    // not yet stored in fVoiceInitialElementsList,
    // it is thus logically the end of the latter,
    // and is created implicitly for every voice.
    // It is needed 'outside' of the 'list<S_msrElement>'
    // because it is not a mere S_msrElement, but a S_msrSegment
    S_msrSegment          fVoiceLastSegment;

    // fVoiceFirstSegment is used to work around LilyPond issue 34
    S_msrSegment          fVoiceFirstSegment;

    // measures

    // fVoiceFirstMeasure is used to number voice upbeats as measure 0
    S_msrMeasure          fVoiceFirstMeasure;

    // measures flat list
    // i.e. without segments nor repeats,
    // gathered from fVoiceInitialElementsList and fVoiceLastSegment
    // by finalizeMeasure()
    list<S_msrMeasure>    fVoiceMeasuresFlatList;

    // notes

    // fVoiceLastAppendedNote is used to build chords upon their second note
    S_msrNote             fVoiceLastAppendedNote;
    rational              fVoiceShortestNoteDuration;

    // fVoiceShortestNoteDuration and fVoiceShortestNoteTupletFactor
    // are used to compute a number of divisions per quarter note
    // if needed, such as when generating MusicXML from MSR
    rational              fVoiceShorftestNoteDuration;
    rational              fVoiceShortestNoteTupletFactor;

    // repeats

  public:

    // public work services
    // ------------------------------------------------------

    // clef, key, time

    void                  setVoiceCurrentClef (S_msrClef clef);

    S_msrClef             getVoiceCurrentClef () const
                              { return fVoiceCurrentClef; }

    S_msrClef             getVoiceFirstClef () const
                              { return fVoiceFirstClef; }

    void                  setVoiceCurrentKey (S_msrKey key);

    S_msrKey              getVoiceCurrentKey  () const
                              { return fVoiceCurrentKey; }

    void                  setVoiceCurrentTime (S_msrTime time);

    S_msrTime             getVoiceCurrentTime () const
                              { return fVoiceCurrentTime; }

    // measures

    const string          getVoiceCurrentMeasureNumber () const
                              { return fVoiceCurrentMeasureNumber; }

    void                  incrementVoiceCurrentMeasurePuristNumber (
                            int    inputLineNumber,
                            string context);

    void                  setVoiceCurrentMeasurePuristNumber (
                            int measurePuristNumber)
                              { fVoiceCurrentMeasureNumber = measurePuristNumber; }

    const int             getVoiceCurrentMeasurePuristNumber () const
                              { return fVoiceCurrentMeasurePuristNumber; }

    void                  setVoiceFirstMeasure (
                            S_msrMeasure measure)
                              { fVoiceFirstMeasure = measure; }

    const S_msrMeasure    getVoiceFirstMeasure () const
                              { return fVoiceFirstMeasure; }

    void                  appendMeasureCloneToVoiceClone (
                            int          inputLineNumber,
                            S_msrMeasure measureClone);

  private:

    // private work services
    // ------------------------------------------------------

    void                  displayVoiceRepeatsStackSummary (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceRepeatsStack (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceRepeatsStackAndVoice (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceRestMeasures (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceRestMeasuresAndVoice (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceMeasuresRepeat (
                            int    inputLineNumber,
                            string context);

    void                  displayVoiceMeasuresRepeatAndVoice (
                            int    inputLineNumber,
                            string context);

  private:

    // work fields
    // ------------------------------------------------------

    // clef, key, time
    // needed at the voice level, because adding such to voice clones
    // is done directly, without going down the part-staff-voice hierarchy
    S_msrClef             fVoiceCurrentClef;

    S_msrKey              fVoiceCurrentKey;

    S_msrTime             fVoiceCurrentTime;

    // the first in the voice is handled specifically for LilyPond code generation
    S_msrClef             fVoiceFirstClef;

    // measures

    string                fVoiceCurrentMeasureNumber;

    int                   fVoiceCurrentMeasurePuristNumber;
                            // this is a 'purist' measure number,
                            // that starts at 0 if there is an anacrusis,
                            // and 1 otherwise,
                            // and is shared by incomplete (sub)measure fragments

    // fVoiceCurrentMeasure contains the last measure append to the voice
    S_msrMeasure          fVoiceCurrentMeasure;

    // a stack is needed to handle pending repeats, which can be nested
    list<S_msrRepeatDescr>
                          fVoicePendingRepeatDescrsStack;

    // rest measures

    // fVoicePendingRestMeasures is either null
    // or the last msrRestMeasures created,
    // but not yet appended to the voice
    S_msrRestMeasures     fVoicePendingRestMeasures;

    // fVoiceRestMeasuresWaitingForItsNextMeasureNumber is either null
    // or the last msrRestMeasures created and appended to the voice,
    // but with its next measure number not yet set
    S_msrRestMeasures     fVoiceRestMeasuresWaitingForItsNextMeasureNumber;
    int                   fVoiceRemainingRestMeasures;

    bool                  fVoiceContainsRestMeasures;

    // measure repeats

    // fVoicePendingMeasuresRepeat is either null
    // or the last msrMeasuresRepeat created,
    // but not yet appended to the voice
    S_msrMeasuresRepeat   fVoicePendingMeasuresRepeat;

    bool                  fVoiceContainsMeasuresRepeats;

    // voice finalization

    bool                  fVoiceHasBeenFinalized;
};
EXP ostream& operator<< (ostream& os, const S_msrVoice& elt);

