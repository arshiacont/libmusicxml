/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

//======================================================================
// You should not modify this file!
// It is automatically generated from the MusicXML DTDs and from 
// template files (located in the templates folder). 
//======================================================================

#ifdef WIN32
# pragma warning (disable : 4786)
#endif

#include <iostream>

#include "elements.h"
#include "factory.h"
#include "types.h"

using namespace std; 

// libmxmllineno is outside of name space MusicXML2
extern int libmxmllineno;


namespace MusicXML2 
{

int currentInputLineNumber ()
  { return libmxmllineno; }
  
template<int elt>
class newElementFunctor : public functor<Sxmlelement>
{
  public:
  
    Sxmlelement operator ()()
      {
        return
          musicxml<elt>::new_musicxml (
            currentInputLineNumber ());
      }
};


Sxmlelement factory::create (const string& eltname) const
{ 
  map<std::string, functor<Sxmlelement>*>::const_iterator
    i = fMap.find (eltname);
      
  if (i != fMap.end()) {
    functor<Sxmlelement>* f = i->second;
    
    if (f) {
      Sxmlelement elt = (*f)();
      
      elt->setName (eltname);

      return elt;
    }
  }
  
  cerr <<
    endl <<
    "### Sxmlelement factory::create called with unknown element \"" <<
    eltname << "\"" << endl;
    
  return 0;
}

Sxmlelement factory::create (int type) const
{ 
  map<int, const char*>::const_iterator
    i =
      fType2Name.find (type);
      
  if (i != fType2Name.end()) {
    return create (i->second);
  }
  
  cerr <<
    endl <<
    "### Sxmlelement factory::create called with unknown type \"" <<
    type << "\"" << endl;
    
  return 0;
}


factory::factory() 
{
  fMap["comment"]   = new newElementFunctor<kComment>;
  fMap["pi"]  = new newElementFunctor<kProcessingInstruction>;
  fType2Name[kComment]        = "comment";
  fType2Name[kProcessingInstruction]  = "pi";
  fMap["accent"]  = new newElementFunctor<k_accent>;
  fMap["accidental"]  = new newElementFunctor<k_accidental>;
  fMap["accidental-mark"]   = new newElementFunctor<k_accidental_mark>;
  fMap["accidental-text"]   = new newElementFunctor<k_accidental_text>;
  fMap["accord"]  = new newElementFunctor<k_accord>;
  fMap["accordion-high"]  = new newElementFunctor<k_accordion_high>;
  fMap["accordion-low"]   = new newElementFunctor<k_accordion_low>;
  fMap["accordion-middle"]  = new newElementFunctor<k_accordion_middle>;
  fMap["accordion-registration"]  = new newElementFunctor<k_accordion_registration>;
  fMap["actual-notes"]  = new newElementFunctor<k_actual_notes>;
  fMap["alter"]   = new newElementFunctor<k_alter>;
  fMap["appearance"]  = new newElementFunctor<k_appearance>;
  fMap["arpeggiate"]  = new newElementFunctor<k_arpeggiate>;
  fMap["arrow"]   = new newElementFunctor<k_arrow>;
  fMap["arrow-direction"]   = new newElementFunctor<k_arrow_direction>;
  fMap["arrow-style"]   = new newElementFunctor<k_arrow_style>;
  fMap["articulations"]   = new newElementFunctor<k_articulations>;
  fMap["artificial"]  = new newElementFunctor<k_artificial>;
  fMap["attributes"]  = new newElementFunctor<k_attributes>;
  fMap["backup"]  = new newElementFunctor<k_backup>;
  fMap["bar-style"]   = new newElementFunctor<k_bar_style>;
  fMap["barline"]   = new newElementFunctor<k_barline>;
  fMap["barre"]   = new newElementFunctor<k_barre>;
  fMap["base-pitch"]  = new newElementFunctor<k_base_pitch>;
  fMap["bass"]  = new newElementFunctor<k_bass>;
  fMap["bass-alter"]  = new newElementFunctor<k_bass_alter>;
  fMap["bass-step"]   = new newElementFunctor<k_bass_step>;
  fMap["beam"]  = new newElementFunctor<k_beam>;
  fMap["beat-repeat"]   = new newElementFunctor<k_beat_repeat>;
  fMap["beat-type"]   = new newElementFunctor<k_beat_type>;
  fMap["beat-unit"]   = new newElementFunctor<k_beat_unit>;
  fMap["beat-unit-dot"]   = new newElementFunctor<k_beat_unit_dot>;
  fMap["beater"]  = new newElementFunctor<k_beater>;
  fMap["beats"]   = new newElementFunctor<k_beats>;
  fMap["bend"]  = new newElementFunctor<k_bend>;
  fMap["bend-alter"]  = new newElementFunctor<k_bend_alter>;
  fMap["bookmark"]  = new newElementFunctor<k_bookmark>;
  fMap["bottom-margin"]   = new newElementFunctor<k_bottom_margin>;
  fMap["bracket"]   = new newElementFunctor<k_bracket>;
  fMap["breath-mark"]   = new newElementFunctor<k_breath_mark>;
  fMap["caesura"]   = new newElementFunctor<k_caesura>;
  fMap["cancel"]  = new newElementFunctor<k_cancel>;
  fMap["capo"]  = new newElementFunctor<k_capo>;
  fMap["chord"]   = new newElementFunctor<k_chord>;
  fMap["chromatic"]   = new newElementFunctor<k_chromatic>;
  fMap["circular-arrow"]  = new newElementFunctor<k_circular_arrow>;
  fMap["clef"]  = new newElementFunctor<k_clef>;
  fMap["clef-octave-change"]  = new newElementFunctor<k_clef_octave_change>;
  fMap["coda"]  = new newElementFunctor<k_coda>;
  fMap["creator"]   = new newElementFunctor<k_creator>;
  fMap["credit"]  = new newElementFunctor<k_credit>;
  fMap["credit-image"]  = new newElementFunctor<k_credit_image>;
  fMap["credit-type"]   = new newElementFunctor<k_credit_type>;
  fMap["credit-words"]  = new newElementFunctor<k_credit_words>;
  fMap["cue"]   = new newElementFunctor<k_cue>;
  fMap["damp"]  = new newElementFunctor<k_damp>;
  fMap["damp-all"]  = new newElementFunctor<k_damp_all>;
  fMap["dashes"]  = new newElementFunctor<k_dashes>;
  fMap["defaults"]  = new newElementFunctor<k_defaults>;
  fMap["degree"]  = new newElementFunctor<k_degree>;
  fMap["degree-alter"]  = new newElementFunctor<k_degree_alter>;
  fMap["degree-type"]   = new newElementFunctor<k_degree_type>;
  fMap["degree-value"]  = new newElementFunctor<k_degree_value>;
  fMap["delayed-inverted-turn"]   = new newElementFunctor<k_delayed_inverted_turn>;
  fMap["delayed-turn"]  = new newElementFunctor<k_delayed_turn>;
  fMap["detached-legato"]   = new newElementFunctor<k_detached_legato>;
  fMap["diatonic"]  = new newElementFunctor<k_diatonic>;
  fMap["direction"]   = new newElementFunctor<k_direction>;
  fMap["direction-type"]  = new newElementFunctor<k_direction_type>;
  fMap["directive"]   = new newElementFunctor<k_directive>;
  fMap["display-octave"]  = new newElementFunctor<k_display_octave>;
  fMap["display-step"]  = new newElementFunctor<k_display_step>;
  fMap["display-text"]  = new newElementFunctor<k_display_text>;
  fMap["distance"]  = new newElementFunctor<k_distance>;
  fMap["divisions"]   = new newElementFunctor<k_divisions>;
  fMap["doit"]  = new newElementFunctor<k_doit>;
  fMap["dot"]   = new newElementFunctor<k_dot>;
  fMap["double"]  = new newElementFunctor<k_double>;
  fMap["double-tongue"]   = new newElementFunctor<k_double_tongue>;
  fMap["down-bow"]  = new newElementFunctor<k_down_bow>;
  fMap["duration"]  = new newElementFunctor<k_duration>;
  fMap["dynamics"]  = new newElementFunctor<k_dynamics>;
  fMap["effect"]  = new newElementFunctor<k_effect>;
  fMap["elevation"]   = new newElementFunctor<k_elevation>;
  fMap["elision"]   = new newElementFunctor<k_elision>;
  fMap["encoder"]   = new newElementFunctor<k_encoder>;
  fMap["encoding"]  = new newElementFunctor<k_encoding>;
  fMap["encoding-date"]   = new newElementFunctor<k_encoding_date>;
  fMap["encoding-description"]  = new newElementFunctor<k_encoding_description>;
  fMap["end-line"]  = new newElementFunctor<k_end_line>;
  fMap["end-paragraph"]   = new newElementFunctor<k_end_paragraph>;
  fMap["ending"]  = new newElementFunctor<k_ending>;
  fMap["ensemble"]  = new newElementFunctor<k_ensemble>;
  fMap["extend"]  = new newElementFunctor<k_extend>;
  fMap["eyeglasses"]  = new newElementFunctor<k_eyeglasses>;
  fMap["f"]   = new newElementFunctor<k_f>;
  fMap["falloff"]   = new newElementFunctor<k_falloff>;
  fMap["feature"]   = new newElementFunctor<k_feature>;
  fMap["fermata"]   = new newElementFunctor<k_fermata>;
  fMap["ff"]  = new newElementFunctor<k_ff>;
  fMap["fff"]   = new newElementFunctor<k_fff>;
  fMap["ffff"]  = new newElementFunctor<k_ffff>;
  fMap["fffff"]   = new newElementFunctor<k_fffff>;
  fMap["ffffff"]  = new newElementFunctor<k_ffffff>;
  fMap["fifths"]  = new newElementFunctor<k_fifths>;
  fMap["figure"]  = new newElementFunctor<k_figure>;
  fMap["figure-number"]   = new newElementFunctor<k_figure_number>;
  fMap["figured-bass"]  = new newElementFunctor<k_figured_bass>;
  fMap["fingering"]   = new newElementFunctor<k_fingering>;
  fMap["fingernails"]   = new newElementFunctor<k_fingernails>;
  fMap["first-fret"]  = new newElementFunctor<k_first_fret>;
  fMap["footnote"]  = new newElementFunctor<k_footnote>;
  fMap["forward"]   = new newElementFunctor<k_forward>;
  fMap["fp"]  = new newElementFunctor<k_fp>;
  fMap["frame"]   = new newElementFunctor<k_frame>;
  fMap["frame-frets"]   = new newElementFunctor<k_frame_frets>;
  fMap["frame-note"]  = new newElementFunctor<k_frame_note>;
  fMap["frame-strings"]   = new newElementFunctor<k_frame_strings>;
  fMap["fret"]  = new newElementFunctor<k_fret>;
  fMap["function"]  = new newElementFunctor<k_function>;
  fMap["fz"]  = new newElementFunctor<k_fz>;
  fMap["glass"]   = new newElementFunctor<k_glass>;
  fMap["glissando"]   = new newElementFunctor<k_glissando>;
  fMap["grace"]   = new newElementFunctor<k_grace>;
  fMap["group"]   = new newElementFunctor<k_group>;
  fMap["group-abbreviation"]  = new newElementFunctor<k_group_abbreviation>;
  fMap["group-abbreviation-display"]  = new newElementFunctor<k_group_abbreviation_display>;
  fMap["group-barline"]   = new newElementFunctor<k_group_barline>;
  fMap["group-name"]  = new newElementFunctor<k_group_name>;
  fMap["group-name-display"]  = new newElementFunctor<k_group_name_display>;
  fMap["group-symbol"]  = new newElementFunctor<k_group_symbol>;
  fMap["group-time"]  = new newElementFunctor<k_group_time>;
  fMap["grouping"]  = new newElementFunctor<k_grouping>;
  fMap["hammer-on"]   = new newElementFunctor<k_hammer_on>;
  fMap["handbell"]  = new newElementFunctor<k_handbell>;
  fMap["harmonic"]  = new newElementFunctor<k_harmonic>;
  fMap["harmony"]   = new newElementFunctor<k_harmony>;
  fMap["harp-pedals"]   = new newElementFunctor<k_harp_pedals>;
  fMap["heel"]  = new newElementFunctor<k_heel>;
  fMap["hole"]  = new newElementFunctor<k_hole>;
  fMap["hole-closed"]   = new newElementFunctor<k_hole_closed>;
  fMap["hole-shape"]  = new newElementFunctor<k_hole_shape>;
  fMap["hole-type"]   = new newElementFunctor<k_hole_type>;
  fMap["humming"]   = new newElementFunctor<k_humming>;
  fMap["identification"]  = new newElementFunctor<k_identification>;
  fMap["image"]   = new newElementFunctor<k_image>;
  fMap["instrument"]  = new newElementFunctor<k_instrument>;
  fMap["instrument-abbreviation"]   = new newElementFunctor<k_instrument_abbreviation>;
  fMap["instrument-name"]   = new newElementFunctor<k_instrument_name>;
  fMap["instrument-sound"]  = new newElementFunctor<k_instrument_sound>;
  fMap["instruments"]   = new newElementFunctor<k_instruments>;
  fMap["interchangeable"]   = new newElementFunctor<k_interchangeable>;
  fMap["inversion"]   = new newElementFunctor<k_inversion>;
  fMap["inverted-mordent"]  = new newElementFunctor<k_inverted_mordent>;
  fMap["inverted-turn"]   = new newElementFunctor<k_inverted_turn>;
  fMap["ipa"]   = new newElementFunctor<k_ipa>;
  fMap["key"]   = new newElementFunctor<k_key>;
  fMap["key-accidental"]  = new newElementFunctor<k_key_accidental>;
  fMap["key-alter"]   = new newElementFunctor<k_key_alter>;
  fMap["key-octave"]  = new newElementFunctor<k_key_octave>;
  fMap["key-step"]  = new newElementFunctor<k_key_step>;
  fMap["kind"]  = new newElementFunctor<k_kind>;
  fMap["laughing"]  = new newElementFunctor<k_laughing>;
  fMap["left-divider"]  = new newElementFunctor<k_left_divider>;
  fMap["left-margin"]   = new newElementFunctor<k_left_margin>;
  fMap["level"]   = new newElementFunctor<k_level>;
  fMap["line"]  = new newElementFunctor<k_line>;
  fMap["line-width"]  = new newElementFunctor<k_line_width>;
  fMap["link"]  = new newElementFunctor<k_link>;
  fMap["lyric"]   = new newElementFunctor<k_lyric>;
  fMap["lyric-font"]  = new newElementFunctor<k_lyric_font>;
  fMap["lyric-language"]  = new newElementFunctor<k_lyric_language>;
  fMap["measure"]   = new newElementFunctor<k_measure>;
  fMap["measure-distance"]  = new newElementFunctor<k_measure_distance>;
  fMap["measure-layout"]  = new newElementFunctor<k_measure_layout>;
  fMap["measure-numbering"]   = new newElementFunctor<k_measure_numbering>;
  fMap["measure-repeat"]  = new newElementFunctor<k_measure_repeat>;
  fMap["measure-style"]   = new newElementFunctor<k_measure_style>;
  fMap["membrane"]  = new newElementFunctor<k_membrane>;
  fMap["metal"]   = new newElementFunctor<k_metal>;
  fMap["metronome"]   = new newElementFunctor<k_metronome>;
  fMap["metronome-beam"]  = new newElementFunctor<k_metronome_beam>;
  fMap["metronome-dot"]   = new newElementFunctor<k_metronome_dot>;
  fMap["metronome-note"]  = new newElementFunctor<k_metronome_note>;
  fMap["metronome-relation"]  = new newElementFunctor<k_metronome_relation>;
  fMap["metronome-tuplet"]  = new newElementFunctor<k_metronome_tuplet>;
  fMap["metronome-type"]  = new newElementFunctor<k_metronome_type>;
  fMap["mf"]  = new newElementFunctor<k_mf>;
  fMap["midi-bank"]   = new newElementFunctor<k_midi_bank>;
  fMap["midi-channel"]  = new newElementFunctor<k_midi_channel>;
  fMap["midi-device"]   = new newElementFunctor<k_midi_device>;
  fMap["midi-instrument"]   = new newElementFunctor<k_midi_instrument>;
  fMap["midi-name"]   = new newElementFunctor<k_midi_name>;
  fMap["midi-program"]  = new newElementFunctor<k_midi_program>;
  fMap["midi-unpitched"]  = new newElementFunctor<k_midi_unpitched>;
  fMap["millimeters"]   = new newElementFunctor<k_millimeters>;
  fMap["miscellaneous"]   = new newElementFunctor<k_miscellaneous>;
  fMap["miscellaneous-field"]   = new newElementFunctor<k_miscellaneous_field>;
  fMap["mode"]  = new newElementFunctor<k_mode>;
  fMap["mordent"]   = new newElementFunctor<k_mordent>;
  fMap["movement-number"]   = new newElementFunctor<k_movement_number>;
  fMap["movement-title"]  = new newElementFunctor<k_movement_title>;
  fMap["mp"]  = new newElementFunctor<k_mp>;
  fMap["multiple-rest"]   = new newElementFunctor<k_multiple_rest>;
  fMap["music-font"]  = new newElementFunctor<k_music_font>;
  fMap["mute"]  = new newElementFunctor<k_mute>;
  fMap["natural"]   = new newElementFunctor<k_natural>;
  fMap["non-arpeggiate"]  = new newElementFunctor<k_non_arpeggiate>;
  fMap["normal-dot"]  = new newElementFunctor<k_normal_dot>;
  fMap["normal-notes"]  = new newElementFunctor<k_normal_notes>;
  fMap["normal-type"]   = new newElementFunctor<k_normal_type>;
  fMap["notations"]   = new newElementFunctor<k_notations>;
  fMap["note"]  = new newElementFunctor<k_note>;
  fMap["note-size"]   = new newElementFunctor<k_note_size>;
  fMap["notehead"]  = new newElementFunctor<k_notehead>;
  fMap["notehead-text"]   = new newElementFunctor<k_notehead_text>;
  fMap["octave"]  = new newElementFunctor<k_octave>;
  fMap["octave-change"]   = new newElementFunctor<k_octave_change>;
  fMap["octave-shift"]  = new newElementFunctor<k_octave_shift>;
  fMap["offset"]  = new newElementFunctor<k_offset>;
  fMap["open-string"]   = new newElementFunctor<k_open_string>;
  fMap["opus"]  = new newElementFunctor<k_opus>;
  fMap["ornaments"]   = new newElementFunctor<k_ornaments>;
  fMap["other-appearance"]  = new newElementFunctor<k_other_appearance>;
  fMap["other-articulation"]  = new newElementFunctor<k_other_articulation>;
  fMap["other-direction"]   = new newElementFunctor<k_other_direction>;
  fMap["other-dynamics"]  = new newElementFunctor<k_other_dynamics>;
  fMap["other-notation"]  = new newElementFunctor<k_other_notation>;
  fMap["other-ornament"]  = new newElementFunctor<k_other_ornament>;
  fMap["other-percussion"]  = new newElementFunctor<k_other_percussion>;
  fMap["other-play"]  = new newElementFunctor<k_other_play>;
  fMap["other-technical"]   = new newElementFunctor<k_other_technical>;
  fMap["p"]   = new newElementFunctor<k_p>;
  fMap["page-height"]   = new newElementFunctor<k_page_height>;
  fMap["page-layout"]   = new newElementFunctor<k_page_layout>;
  fMap["page-margins"]  = new newElementFunctor<k_page_margins>;
  fMap["page-width"]  = new newElementFunctor<k_page_width>;
  fMap["pan"]   = new newElementFunctor<k_pan>;
  fMap["part"]  = new newElementFunctor<k_part>;
  fMap["part-abbreviation"]   = new newElementFunctor<k_part_abbreviation>;
  fMap["part-abbreviation-display"]   = new newElementFunctor<k_part_abbreviation_display>;
  fMap["part-group"]  = new newElementFunctor<k_part_group>;
  fMap["part-list"]   = new newElementFunctor<k_part_list>;
  fMap["part-name"]   = new newElementFunctor<k_part_name>;
  fMap["part-name-display"]   = new newElementFunctor<k_part_name_display>;
  fMap["part-symbol"]   = new newElementFunctor<k_part_symbol>;
  fMap["pedal"]   = new newElementFunctor<k_pedal>;
  fMap["pedal-alter"]   = new newElementFunctor<k_pedal_alter>;
  fMap["pedal-step"]  = new newElementFunctor<k_pedal_step>;
  fMap["pedal-tuning"]  = new newElementFunctor<k_pedal_tuning>;
  fMap["per-minute"]  = new newElementFunctor<k_per_minute>;
  fMap["percussion"]  = new newElementFunctor<k_percussion>;
  fMap["pitch"]   = new newElementFunctor<k_pitch>;
  fMap["pitched"]   = new newElementFunctor<k_pitched>;
  fMap["play"]  = new newElementFunctor<k_play>;
  fMap["plop"]  = new newElementFunctor<k_plop>;
  fMap["pluck"]   = new newElementFunctor<k_pluck>;
  fMap["pp"]  = new newElementFunctor<k_pp>;
  fMap["ppp"]   = new newElementFunctor<k_ppp>;
  fMap["pppp"]  = new newElementFunctor<k_pppp>;
  fMap["ppppp"]   = new newElementFunctor<k_ppppp>;
  fMap["pppppp"]  = new newElementFunctor<k_pppppp>;
  fMap["pre-bend"]  = new newElementFunctor<k_pre_bend>;
  fMap["prefix"]  = new newElementFunctor<k_prefix>;
  fMap["principal-voice"]   = new newElementFunctor<k_principal_voice>;
  fMap["print"]   = new newElementFunctor<k_print>;
  fMap["pull-off"]  = new newElementFunctor<k_pull_off>;
  fMap["rehearsal"]   = new newElementFunctor<k_rehearsal>;
  fMap["relation"]  = new newElementFunctor<k_relation>;
  fMap["release"]   = new newElementFunctor<k_release>;
  fMap["repeat"]  = new newElementFunctor<k_repeat>;
  fMap["rest"]  = new newElementFunctor<k_rest>;
  fMap["rf"]  = new newElementFunctor<k_rf>;
  fMap["rfz"]   = new newElementFunctor<k_rfz>;
  fMap["right-divider"]   = new newElementFunctor<k_right_divider>;
  fMap["right-margin"]  = new newElementFunctor<k_right_margin>;
  fMap["rights"]  = new newElementFunctor<k_rights>;
  fMap["root"]  = new newElementFunctor<k_root>;
  fMap["root-alter"]  = new newElementFunctor<k_root_alter>;
  fMap["root-step"]   = new newElementFunctor<k_root_step>;
  fMap["scaling"]   = new newElementFunctor<k_scaling>;
  fMap["schleifer"]   = new newElementFunctor<k_schleifer>;
  fMap["scoop"]   = new newElementFunctor<k_scoop>;
  fMap["scordatura"]  = new newElementFunctor<k_scordatura>;
  fMap["score-instrument"]  = new newElementFunctor<k_score_instrument>;
  fMap["score-part"]  = new newElementFunctor<k_score_part>;
  fMap["score-partwise"]  = new newElementFunctor<k_score_partwise>;
  fMap["score-timewise"]  = new newElementFunctor<k_score_timewise>;
  fMap["segno"]   = new newElementFunctor<k_segno>;
  fMap["semi-pitched"]  = new newElementFunctor<k_semi_pitched>;
  fMap["senza-misura"]  = new newElementFunctor<k_senza_misura>;
  fMap["sf"]  = new newElementFunctor<k_sf>;
  fMap["sffz"]  = new newElementFunctor<k_sffz>;
  fMap["sfp"]   = new newElementFunctor<k_sfp>;
  fMap["sfpp"]  = new newElementFunctor<k_sfpp>;
  fMap["sfz"]   = new newElementFunctor<k_sfz>;
  fMap["shake"]   = new newElementFunctor<k_shake>;
  fMap["sign"]  = new newElementFunctor<k_sign>;
  fMap["slash"]   = new newElementFunctor<k_slash>;
  fMap["slash-dot"]   = new newElementFunctor<k_slash_dot>;
  fMap["slash-type"]  = new newElementFunctor<k_slash_type>;
  fMap["slide"]   = new newElementFunctor<k_slide>;
  fMap["slur"]  = new newElementFunctor<k_slur>;
  fMap["snap-pizzicato"]  = new newElementFunctor<k_snap_pizzicato>;
  fMap["software"]  = new newElementFunctor<k_software>;
  fMap["solo"]  = new newElementFunctor<k_solo>;
  fMap["sound"]   = new newElementFunctor<k_sound>;
  fMap["sounding-pitch"]  = new newElementFunctor<k_sounding_pitch>;
  fMap["source"]  = new newElementFunctor<k_source>;
  fMap["spiccato"]  = new newElementFunctor<k_spiccato>;
  fMap["staccatissimo"]   = new newElementFunctor<k_staccatissimo>;
  fMap["staccato"]  = new newElementFunctor<k_staccato>;
  fMap["staff"]   = new newElementFunctor<k_staff>;
  fMap["staff-details"]   = new newElementFunctor<k_staff_details>;
  fMap["staff-distance"]  = new newElementFunctor<k_staff_distance>;
  fMap["staff-layout"]  = new newElementFunctor<k_staff_layout>;
  fMap["staff-lines"]   = new newElementFunctor<k_staff_lines>;
  fMap["staff-size"]  = new newElementFunctor<k_staff_size>;
  fMap["staff-tuning"]  = new newElementFunctor<k_staff_tuning>;
  fMap["staff-type"]  = new newElementFunctor<k_staff_type>;
  fMap["staves"]  = new newElementFunctor<k_staves>;
  fMap["stem"]  = new newElementFunctor<k_stem>;
  fMap["step"]  = new newElementFunctor<k_step>;
  fMap["stick"]   = new newElementFunctor<k_stick>;
  fMap["stick-location"]  = new newElementFunctor<k_stick_location>;
  fMap["stick-material"]  = new newElementFunctor<k_stick_material>;
  fMap["stick-type"]  = new newElementFunctor<k_stick_type>;
  fMap["stopped"]   = new newElementFunctor<k_stopped>;
  fMap["stress"]  = new newElementFunctor<k_stress>;
  fMap["string"]  = new newElementFunctor<k_string>;
  fMap["string-mute"]   = new newElementFunctor<k_string_mute>;
  fMap["strong-accent"]   = new newElementFunctor<k_strong_accent>;
  fMap["suffix"]  = new newElementFunctor<k_suffix>;
  fMap["supports"]  = new newElementFunctor<k_supports>;
  fMap["syllabic"]  = new newElementFunctor<k_syllabic>;
  fMap["system-distance"]   = new newElementFunctor<k_system_distance>;
  fMap["system-dividers"]   = new newElementFunctor<k_system_dividers>;
  fMap["system-layout"]   = new newElementFunctor<k_system_layout>;
  fMap["system-margins"]  = new newElementFunctor<k_system_margins>;
  fMap["tap"]   = new newElementFunctor<k_tap>;
  fMap["technical"]   = new newElementFunctor<k_technical>;
  fMap["tenths"]  = new newElementFunctor<k_tenths>;
  fMap["tenuto"]  = new newElementFunctor<k_tenuto>;
  fMap["text"]  = new newElementFunctor<k_text>;
  fMap["thumb-position"]  = new newElementFunctor<k_thumb_position>;
  fMap["tie"]   = new newElementFunctor<k_tie>;
  fMap["tied"]  = new newElementFunctor<k_tied>;
  fMap["time"]  = new newElementFunctor<k_time>;
  fMap["time-modification"]   = new newElementFunctor<k_time_modification>;
  fMap["time-relation"]   = new newElementFunctor<k_time_relation>;
  fMap["timpani"]   = new newElementFunctor<k_timpani>;
  fMap["toe"]   = new newElementFunctor<k_toe>;
  fMap["top-margin"]  = new newElementFunctor<k_top_margin>;
  fMap["top-system-distance"]   = new newElementFunctor<k_top_system_distance>;
  fMap["touching-pitch"]  = new newElementFunctor<k_touching_pitch>;
  fMap["transpose"]   = new newElementFunctor<k_transpose>;
  fMap["tremolo"]   = new newElementFunctor<k_tremolo>;
  fMap["trill-mark"]  = new newElementFunctor<k_trill_mark>;
  fMap["triple-tongue"]   = new newElementFunctor<k_triple_tongue>;
  fMap["tuning-alter"]  = new newElementFunctor<k_tuning_alter>;
  fMap["tuning-octave"]   = new newElementFunctor<k_tuning_octave>;
  fMap["tuning-step"]   = new newElementFunctor<k_tuning_step>;
  fMap["tuplet"]  = new newElementFunctor<k_tuplet>;
  fMap["tuplet-actual"]   = new newElementFunctor<k_tuplet_actual>;
  fMap["tuplet-dot"]  = new newElementFunctor<k_tuplet_dot>;
  fMap["tuplet-normal"]   = new newElementFunctor<k_tuplet_normal>;
  fMap["tuplet-number"]   = new newElementFunctor<k_tuplet_number>;
  fMap["tuplet-type"]   = new newElementFunctor<k_tuplet_type>;
  fMap["turn"]  = new newElementFunctor<k_turn>;
  fMap["type"]  = new newElementFunctor<k_type>;
  fMap["unpitched"]   = new newElementFunctor<k_unpitched>;
  fMap["unstress"]  = new newElementFunctor<k_unstress>;
  fMap["up-bow"]  = new newElementFunctor<k_up_bow>;
  fMap["vertical-turn"]   = new newElementFunctor<k_vertical_turn>;
  fMap["virtual-instrument"]  = new newElementFunctor<k_virtual_instrument>;
  fMap["virtual-library"]   = new newElementFunctor<k_virtual_library>;
  fMap["virtual-name"]  = new newElementFunctor<k_virtual_name>;
  fMap["voice"]   = new newElementFunctor<k_voice>;
  fMap["volume"]  = new newElementFunctor<k_volume>;
  fMap["wavy-line"]   = new newElementFunctor<k_wavy_line>;
  fMap["wedge"]   = new newElementFunctor<k_wedge>;
  fMap["with-bar"]  = new newElementFunctor<k_with_bar>;
  fMap["wood"]  = new newElementFunctor<k_wood>;
  fMap["word-font"]   = new newElementFunctor<k_word_font>;
  fMap["words"]   = new newElementFunctor<k_words>;
  fMap["work"]  = new newElementFunctor<k_work>;
  fMap["work-number"]   = new newElementFunctor<k_work_number>;
  fMap["work-title"]  = new newElementFunctor<k_work_title>;

  fType2Name[k_accent]  = "accent";
  fType2Name[k_accidental]  = "accidental";
  fType2Name[k_accidental_mark]   = "accidental-mark";
  fType2Name[k_accidental_text]   = "accidental-text";
  fType2Name[k_accord]  = "accord";
  fType2Name[k_accordion_high]  = "accordion-high";
  fType2Name[k_accordion_low]   = "accordion-low";
  fType2Name[k_accordion_middle]  = "accordion-middle";
  fType2Name[k_accordion_registration]  = "accordion-registration";
  fType2Name[k_actual_notes]  = "actual-notes";
  fType2Name[k_alter]   = "alter";
  fType2Name[k_appearance]  = "appearance";
  fType2Name[k_arpeggiate]  = "arpeggiate";
  fType2Name[k_arrow]   = "arrow";
  fType2Name[k_arrow_direction]   = "arrow-direction";
  fType2Name[k_arrow_style]   = "arrow-style";
  fType2Name[k_articulations]   = "articulations";
  fType2Name[k_artificial]  = "artificial";
  fType2Name[k_attributes]  = "attributes";
  fType2Name[k_backup]  = "backup";
  fType2Name[k_bar_style]   = "bar-style";
  fType2Name[k_barline]   = "barline";
  fType2Name[k_barre]   = "barre";
  fType2Name[k_base_pitch]  = "base-pitch";
  fType2Name[k_bass]  = "bass";
  fType2Name[k_bass_alter]  = "bass-alter";
  fType2Name[k_bass_step]   = "bass-step";
  fType2Name[k_beam]  = "beam";
  fType2Name[k_beat_repeat]   = "beat-repeat";
  fType2Name[k_beat_type]   = "beat-type";
  fType2Name[k_beat_unit]   = "beat-unit";
  fType2Name[k_beat_unit_dot]   = "beat-unit-dot";
  fType2Name[k_beater]  = "beater";
  fType2Name[k_beats]   = "beats";
  fType2Name[k_bend]  = "bend";
  fType2Name[k_bend_alter]  = "bend-alter";
  fType2Name[k_bookmark]  = "bookmark";
  fType2Name[k_bottom_margin]   = "bottom-margin";
  fType2Name[k_bracket]   = "bracket";
  fType2Name[k_breath_mark]   = "breath-mark";
  fType2Name[k_caesura]   = "caesura";
  fType2Name[k_cancel]  = "cancel";
  fType2Name[k_capo]  = "capo";
  fType2Name[k_chord]   = "chord";
  fType2Name[k_chromatic]   = "chromatic";
  fType2Name[k_circular_arrow]  = "circular-arrow";
  fType2Name[k_clef]  = "clef";
  fType2Name[k_clef_octave_change]  = "clef-octave-change";
  fType2Name[k_coda]  = "coda";
  fType2Name[k_creator]   = "creator";
  fType2Name[k_credit]  = "credit";
  fType2Name[k_credit_image]  = "credit-image";
  fType2Name[k_credit_type]   = "credit-type";
  fType2Name[k_credit_words]  = "credit-words";
  fType2Name[k_cue]   = "cue";
  fType2Name[k_damp]  = "damp";
  fType2Name[k_damp_all]  = "damp-all";
  fType2Name[k_dashes]  = "dashes";
  fType2Name[k_defaults]  = "defaults";
  fType2Name[k_degree]  = "degree";
  fType2Name[k_degree_alter]  = "degree-alter";
  fType2Name[k_degree_type]   = "degree-type";
  fType2Name[k_degree_value]  = "degree-value";
  fType2Name[k_delayed_inverted_turn]   = "delayed-inverted-turn";
  fType2Name[k_delayed_turn]  = "delayed-turn";
  fType2Name[k_detached_legato]   = "detached-legato";
  fType2Name[k_diatonic]  = "diatonic";
  fType2Name[k_direction]   = "direction";
  fType2Name[k_direction_type]  = "direction-type";
  fType2Name[k_directive]   = "directive";
  fType2Name[k_display_octave]  = "display-octave";
  fType2Name[k_display_step]  = "display-step";
  fType2Name[k_display_text]  = "display-text";
  fType2Name[k_distance]  = "distance";
  fType2Name[k_divisions]   = "divisions";
  fType2Name[k_doit]  = "doit";
  fType2Name[k_dot]   = "dot";
  fType2Name[k_double]  = "double";
  fType2Name[k_double_tongue]   = "double-tongue";
  fType2Name[k_down_bow]  = "down-bow";
  fType2Name[k_duration]  = "duration";
  fType2Name[k_dynamics]  = "dynamics";
  fType2Name[k_effect]  = "effect";
  fType2Name[k_elevation]   = "elevation";
  fType2Name[k_elision]   = "elision";
  fType2Name[k_encoder]   = "encoder";
  fType2Name[k_encoding]  = "encoding";
  fType2Name[k_encoding_date]   = "encoding-date";
  fType2Name[k_encoding_description]  = "encoding-description";
  fType2Name[k_end_line]  = "end-line";
  fType2Name[k_end_paragraph]   = "end-paragraph";
  fType2Name[k_ending]  = "ending";
  fType2Name[k_ensemble]  = "ensemble";
  fType2Name[k_extend]  = "extend";
  fType2Name[k_eyeglasses]  = "eyeglasses";
  fType2Name[k_f]   = "f";
  fType2Name[k_falloff]   = "falloff";
  fType2Name[k_feature]   = "feature";
  fType2Name[k_fermata]   = "fermata";
  fType2Name[k_ff]  = "ff";
  fType2Name[k_fff]   = "fff";
  fType2Name[k_ffff]  = "ffff";
  fType2Name[k_fffff]   = "fffff";
  fType2Name[k_ffffff]  = "ffffff";
  fType2Name[k_fifths]  = "fifths";
  fType2Name[k_figure]  = "figure";
  fType2Name[k_figure_number]   = "figure-number";
  fType2Name[k_figured_bass]  = "figured-bass";
  fType2Name[k_fingering]   = "fingering";
  fType2Name[k_fingernails]   = "fingernails";
  fType2Name[k_first_fret]  = "first-fret";
  fType2Name[k_footnote]  = "footnote";
  fType2Name[k_forward]   = "forward";
  fType2Name[k_fp]  = "fp";
  fType2Name[k_frame]   = "frame";
  fType2Name[k_frame_frets]   = "frame-frets";
  fType2Name[k_frame_note]  = "frame-note";
  fType2Name[k_frame_strings]   = "frame-strings";
  fType2Name[k_fret]  = "fret";
  fType2Name[k_function]  = "function";
  fType2Name[k_fz]  = "fz";
  fType2Name[k_glass]   = "glass";
  fType2Name[k_glissando]   = "glissando";
  fType2Name[k_grace]   = "grace";
  fType2Name[k_group]   = "group";
  fType2Name[k_group_abbreviation]  = "group-abbreviation";
  fType2Name[k_group_abbreviation_display]  = "group-abbreviation-display";
  fType2Name[k_group_barline]   = "group-barline";
  fType2Name[k_group_name]  = "group-name";
  fType2Name[k_group_name_display]  = "group-name-display";
  fType2Name[k_group_symbol]  = "group-symbol";
  fType2Name[k_group_time]  = "group-time";
  fType2Name[k_grouping]  = "grouping";
  fType2Name[k_hammer_on]   = "hammer-on";
  fType2Name[k_handbell]  = "handbell";
  fType2Name[k_harmonic]  = "harmonic";
  fType2Name[k_harmony]   = "harmony";
  fType2Name[k_harp_pedals]   = "harp-pedals";
  fType2Name[k_heel]  = "heel";
  fType2Name[k_hole]  = "hole";
  fType2Name[k_hole_closed]   = "hole-closed";
  fType2Name[k_hole_shape]  = "hole-shape";
  fType2Name[k_hole_type]   = "hole-type";
  fType2Name[k_humming]   = "humming";
  fType2Name[k_identification]  = "identification";
  fType2Name[k_image]   = "image";
  fType2Name[k_instrument]  = "instrument";
  fType2Name[k_instrument_abbreviation]   = "instrument-abbreviation";
  fType2Name[k_instrument_name]   = "instrument-name";
  fType2Name[k_instrument_sound]  = "instrument-sound";
  fType2Name[k_instruments]   = "instruments";
  fType2Name[k_interchangeable]   = "interchangeable";
  fType2Name[k_inversion]   = "inversion";
  fType2Name[k_inverted_mordent]  = "inverted-mordent";
  fType2Name[k_inverted_turn]   = "inverted-turn";
  fType2Name[k_ipa]   = "ipa";
  fType2Name[k_key]   = "key";
  fType2Name[k_key_accidental]  = "key-accidental";
  fType2Name[k_key_alter]   = "key-alter";
  fType2Name[k_key_octave]  = "key-octave";
  fType2Name[k_key_step]  = "key-step";
  fType2Name[k_kind]  = "kind";
  fType2Name[k_laughing]  = "laughing";
  fType2Name[k_left_divider]  = "left-divider";
  fType2Name[k_left_margin]   = "left-margin";
  fType2Name[k_level]   = "level";
  fType2Name[k_line]  = "line";
  fType2Name[k_line_width]  = "line-width";
  fType2Name[k_link]  = "link";
  fType2Name[k_lyric]   = "lyric";
  fType2Name[k_lyric_font]  = "lyric-font";
  fType2Name[k_lyric_language]  = "lyric-language";
  fType2Name[k_measure]   = "measure";
  fType2Name[k_measure_distance]  = "measure-distance";
  fType2Name[k_measure_layout]  = "measure-layout";
  fType2Name[k_measure_numbering]   = "measure-numbering";
  fType2Name[k_measure_repeat]  = "measure-repeat";
  fType2Name[k_measure_style]   = "measure-style";
  fType2Name[k_membrane]  = "membrane";
  fType2Name[k_metal]   = "metal";
  fType2Name[k_metronome]   = "metronome";
  fType2Name[k_metronome_beam]  = "metronome-beam";
  fType2Name[k_metronome_dot]   = "metronome-dot";
  fType2Name[k_metronome_note]  = "metronome-note";
  fType2Name[k_metronome_relation]  = "metronome-relation";
  fType2Name[k_metronome_tuplet]  = "metronome-tuplet";
  fType2Name[k_metronome_type]  = "metronome-type";
  fType2Name[k_mf]  = "mf";
  fType2Name[k_midi_bank]   = "midi-bank";
  fType2Name[k_midi_channel]  = "midi-channel";
  fType2Name[k_midi_device]   = "midi-device";
  fType2Name[k_midi_instrument]   = "midi-instrument";
  fType2Name[k_midi_name]   = "midi-name";
  fType2Name[k_midi_program]  = "midi-program";
  fType2Name[k_midi_unpitched]  = "midi-unpitched";
  fType2Name[k_millimeters]   = "millimeters";
  fType2Name[k_miscellaneous]   = "miscellaneous";
  fType2Name[k_miscellaneous_field]   = "miscellaneous-field";
  fType2Name[k_mode]  = "mode";
  fType2Name[k_mordent]   = "mordent";
  fType2Name[k_movement_number]   = "movement-number";
  fType2Name[k_movement_title]  = "movement-title";
  fType2Name[k_mp]  = "mp";
  fType2Name[k_multiple_rest]   = "multiple-rest";
  fType2Name[k_music_font]  = "music-font";
  fType2Name[k_mute]  = "mute";
  fType2Name[k_natural]   = "natural";
  fType2Name[k_non_arpeggiate]  = "non-arpeggiate";
  fType2Name[k_normal_dot]  = "normal-dot";
  fType2Name[k_normal_notes]  = "normal-notes";
  fType2Name[k_normal_type]   = "normal-type";
  fType2Name[k_notations]   = "notations";
  fType2Name[k_note]  = "note";
  fType2Name[k_note_size]   = "note-size";
  fType2Name[k_notehead]  = "notehead";
  fType2Name[k_notehead_text]   = "notehead-text";
  fType2Name[k_octave]  = "octave";
  fType2Name[k_octave_change]   = "octave-change";
  fType2Name[k_octave_shift]  = "octave-shift";
  fType2Name[k_offset]  = "offset";
  fType2Name[k_open_string]   = "open-string";
  fType2Name[k_opus]  = "opus";
  fType2Name[k_ornaments]   = "ornaments";
  fType2Name[k_other_appearance]  = "other-appearance";
  fType2Name[k_other_articulation]  = "other-articulation";
  fType2Name[k_other_direction]   = "other-direction";
  fType2Name[k_other_dynamics]  = "other-dynamics";
  fType2Name[k_other_notation]  = "other-notation";
  fType2Name[k_other_ornament]  = "other-ornament";
  fType2Name[k_other_percussion]  = "other-percussion";
  fType2Name[k_other_play]  = "other-play";
  fType2Name[k_other_technical]   = "other-technical";
  fType2Name[k_p]   = "p";
  fType2Name[k_page_height]   = "page-height";
  fType2Name[k_page_layout]   = "page-layout";
  fType2Name[k_page_margins]  = "page-margins";
  fType2Name[k_page_width]  = "page-width";
  fType2Name[k_pan]   = "pan";
  fType2Name[k_part]  = "part";
  fType2Name[k_part_abbreviation]   = "part-abbreviation";
  fType2Name[k_part_abbreviation_display]   = "part-abbreviation-display";
  fType2Name[k_part_group]  = "part-group";
  fType2Name[k_part_list]   = "part-list";
  fType2Name[k_part_name]   = "part-name";
  fType2Name[k_part_name_display]   = "part-name-display";
  fType2Name[k_part_symbol]   = "part-symbol";
  fType2Name[k_pedal]   = "pedal";
  fType2Name[k_pedal_alter]   = "pedal-alter";
  fType2Name[k_pedal_step]  = "pedal-step";
  fType2Name[k_pedal_tuning]  = "pedal-tuning";
  fType2Name[k_per_minute]  = "per-minute";
  fType2Name[k_percussion]  = "percussion";
  fType2Name[k_pitch]   = "pitch";
  fType2Name[k_pitched]   = "pitched";
  fType2Name[k_play]  = "play";
  fType2Name[k_plop]  = "plop";
  fType2Name[k_pluck]   = "pluck";
  fType2Name[k_pp]  = "pp";
  fType2Name[k_ppp]   = "ppp";
  fType2Name[k_pppp]  = "pppp";
  fType2Name[k_ppppp]   = "ppppp";
  fType2Name[k_pppppp]  = "pppppp";
  fType2Name[k_pre_bend]  = "pre-bend";
  fType2Name[k_prefix]  = "prefix";
  fType2Name[k_principal_voice]   = "principal-voice";
  fType2Name[k_print]   = "print";
  fType2Name[k_pull_off]  = "pull-off";
  fType2Name[k_rehearsal]   = "rehearsal";
  fType2Name[k_relation]  = "relation";
  fType2Name[k_release]   = "release";
  fType2Name[k_repeat]  = "repeat";
  fType2Name[k_rest]  = "rest";
  fType2Name[k_rf]  = "rf";
  fType2Name[k_rfz]   = "rfz";
  fType2Name[k_right_divider]   = "right-divider";
  fType2Name[k_right_margin]  = "right-margin";
  fType2Name[k_rights]  = "rights";
  fType2Name[k_root]  = "root";
  fType2Name[k_root_alter]  = "root-alter";
  fType2Name[k_root_step]   = "root-step";
  fType2Name[k_scaling]   = "scaling";
  fType2Name[k_schleifer]   = "schleifer";
  fType2Name[k_scoop]   = "scoop";
  fType2Name[k_scordatura]  = "scordatura";
  fType2Name[k_score_instrument]  = "score-instrument";
  fType2Name[k_score_part]  = "score-part";
  fType2Name[k_score_partwise]  = "score-partwise";
  fType2Name[k_score_timewise]  = "score-timewise";
  fType2Name[k_segno]   = "segno";
  fType2Name[k_semi_pitched]  = "semi-pitched";
  fType2Name[k_senza_misura]  = "senza-misura";
  fType2Name[k_sf]  = "sf";
  fType2Name[k_sffz]  = "sffz";
  fType2Name[k_sfp]   = "sfp";
  fType2Name[k_sfpp]  = "sfpp";
  fType2Name[k_sfz]   = "sfz";
  fType2Name[k_shake]   = "shake";
  fType2Name[k_sign]  = "sign";
  fType2Name[k_slash]   = "slash";
  fType2Name[k_slash_dot]   = "slash-dot";
  fType2Name[k_slash_type]  = "slash-type";
  fType2Name[k_slide]   = "slide";
  fType2Name[k_slur]  = "slur";
  fType2Name[k_snap_pizzicato]  = "snap-pizzicato";
  fType2Name[k_software]  = "software";
  fType2Name[k_solo]  = "solo";
  fType2Name[k_sound]   = "sound";
  fType2Name[k_sounding_pitch]  = "sounding-pitch";
  fType2Name[k_source]  = "source";
  fType2Name[k_spiccato]  = "spiccato";
  fType2Name[k_staccatissimo]   = "staccatissimo";
  fType2Name[k_staccato]  = "staccato";
  fType2Name[k_staff]   = "staff";
  fType2Name[k_staff_details]   = "staff-details";
  fType2Name[k_staff_distance]  = "staff-distance";
  fType2Name[k_staff_layout]  = "staff-layout";
  fType2Name[k_staff_lines]   = "staff-lines";
  fType2Name[k_staff_size]  = "staff-size";
  fType2Name[k_staff_tuning]  = "staff-tuning";
  fType2Name[k_staff_type]  = "staff-type";
  fType2Name[k_staves]  = "staves";
  fType2Name[k_stem]  = "stem";
  fType2Name[k_step]  = "step";
  fType2Name[k_stick]   = "stick";
  fType2Name[k_stick_location]  = "stick-location";
  fType2Name[k_stick_material]  = "stick-material";
  fType2Name[k_stick_type]  = "stick-type";
  fType2Name[k_stopped]   = "stopped";
  fType2Name[k_stress]  = "stress";
  fType2Name[k_string]  = "string";
  fType2Name[k_string_mute]   = "string-mute";
  fType2Name[k_strong_accent]   = "strong-accent";
  fType2Name[k_suffix]  = "suffix";
  fType2Name[k_supports]  = "supports";
  fType2Name[k_syllabic]  = "syllabic";
  fType2Name[k_system_distance]   = "system-distance";
  fType2Name[k_system_dividers]   = "system-dividers";
  fType2Name[k_system_layout]   = "system-layout";
  fType2Name[k_system_margins]  = "system-margins";
  fType2Name[k_tap]   = "tap";
  fType2Name[k_technical]   = "technical";
  fType2Name[k_tenths]  = "tenths";
  fType2Name[k_tenuto]  = "tenuto";
  fType2Name[k_text]  = "text";
  fType2Name[k_thumb_position]  = "thumb-position";
  fType2Name[k_tie]   = "tie";
  fType2Name[k_tied]  = "tied";
  fType2Name[k_time]  = "time";
  fType2Name[k_time_modification]   = "time-modification";
  fType2Name[k_time_relation]   = "time-relation";
  fType2Name[k_timpani]   = "timpani";
  fType2Name[k_toe]   = "toe";
  fType2Name[k_top_margin]  = "top-margin";
  fType2Name[k_top_system_distance]   = "top-system-distance";
  fType2Name[k_touching_pitch]  = "touching-pitch";
  fType2Name[k_transpose]   = "transpose";
  fType2Name[k_tremolo]   = "tremolo";
  fType2Name[k_trill_mark]  = "trill-mark";
  fType2Name[k_triple_tongue]   = "triple-tongue";
  fType2Name[k_tuning_alter]  = "tuning-alter";
  fType2Name[k_tuning_octave]   = "tuning-octave";
  fType2Name[k_tuning_step]   = "tuning-step";
  fType2Name[k_tuplet]  = "tuplet";
  fType2Name[k_tuplet_actual]   = "tuplet-actual";
  fType2Name[k_tuplet_dot]  = "tuplet-dot";
  fType2Name[k_tuplet_normal]   = "tuplet-normal";
  fType2Name[k_tuplet_number]   = "tuplet-number";
  fType2Name[k_tuplet_type]   = "tuplet-type";
  fType2Name[k_turn]  = "turn";
  fType2Name[k_type]  = "type";
  fType2Name[k_unpitched]   = "unpitched";
  fType2Name[k_unstress]  = "unstress";
  fType2Name[k_up_bow]  = "up-bow";
  fType2Name[k_vertical_turn]   = "vertical-turn";
  fType2Name[k_virtual_instrument]  = "virtual-instrument";
  fType2Name[k_virtual_library]   = "virtual-library";
  fType2Name[k_virtual_name]  = "virtual-name";
  fType2Name[k_voice]   = "voice";
  fType2Name[k_volume]  = "volume";
  fType2Name[k_wavy_line]   = "wavy-line";
  fType2Name[k_wedge]   = "wedge";
  fType2Name[k_with_bar]  = "with-bar";
  fType2Name[k_wood]  = "wood";
  fType2Name[k_word_font]   = "word-font";
  fType2Name[k_words]   = "words";
  fType2Name[k_work]  = "work";
  fType2Name[k_work_number]   = "work-number";
  fType2Name[k_work_title]  = "work-title";
}
}
