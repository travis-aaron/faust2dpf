/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2018 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef PLUGIN_BORING_H
#define PLUGIN_BORING_H

#include "DistrhoPlugin.hpp"
#include "boring.hpp"

START_NAMESPACE_DISTRHO

/* ------------------------------------------------------------------------------------------------------------
 * DPF Plugin */

class BoringPlugin : public Plugin {
public:

enum Parameters {
   paramFreq,
   paramGate,
   paramGain
   };
   BoringPlugin();
    ~BoringPlugin();


   /* --------------------------------------------------------------------------------------------------------
    * Information */

    const char* getLabel() const noexcept {
      return "Boring";
      }
   /**
      Get an extensive comment/description about the plugin.@n
      Optional, returns nothing by default.
    */
    const char* getDescription() const {
    return "An lv2 template for creating UIs";
     }

   /**
      Get the plugin author/maker.
    */
    const char* getMaker() const noexcept {
    return "travis-aaron";
    }

   /**
      Get the plugin homepage.@n
      Optional, returns nothing by default.
    */
    const char* getHomePage() const {
      return DISTRHO_PLUGIN_URI;
      }

   /**
      Get the plugin license (a single line of text or a URL).@n
      For commercial plugins this should return some short copyright information.
    */
    const char* getLicense() const noexcept {
    return "https://spdx.org/licenses/MIT";
    }

    uint32_t getVersion() const noexcept {
      return d_version(1, 0, 0);
      }
   /**
      Get the plugin unique Id.@n
      This value is used by LADSPA, DSSI and VST plugin formats.
      @see d_cconst()
    */
    int64_t getUniqueId() const noexcept{
    return d_cconst('Z', 'a', 'K', 'b');
    }

   /* --------------------------------------------------------------------------------------------------------
    * Init */


    void initParameter(uint32_t index, Parameter& parameter);

   /* --------------------------------------------------------------------------------------------------------
    * Internal data */

   /**
      Get the current value of a parameter.@n
      The host may call this function from any context, including realtime processing.
    */
  float getParameterValue(uint32_t index) const;

   /**
      Change a parameter value.@n
      The host may call this function from any context, including realtime processing.@n
      When a parameter is marked as automable, you must ensure no non-realtime operations are performed.
      @note This function will only be called for parameter inputs.
    */
   void setParameterValue(uint32_t index, float value);

   /* --------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */

   /**
      Activate this plugin.
    */
    void activate();

   /**
      Deactivate this plugin.
    */
    void deactivate();

#if DISTRHO_PLUGIN_WANT_MIDI_INPUT
   /**
      Run/process function for plugins with MIDI input.
      @note Some parameters might be null if there are no audio inputs/outputs or MIDI events.
    */
    void run(const float** inputs, float** outputs, uint32_t frames,
                     const MidiEvent* midiEvents, uint32_t midiEventCount);
#else
   /**
      Run/process function for plugins without MIDI input.
      @note Some parameters might be null if there are no audio inputs or outputs.
    */
    void run(const float** inputs, float** outputs, uint32_t frames);
#endif



    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BoringPlugin)
};




// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // $ifndef PLUGIN_BORING_H
