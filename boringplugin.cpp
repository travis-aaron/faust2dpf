
/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2016 Filipe Coelho <falktx@falktx.com>
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

 #include "boringplugin.hpp"

 void BoringPlugin::initParameter(uint32_t index, Parameter& parameter) {
    if (index >= paramCount)
        return;

    const Boring::ParameterRange* range = flt->parameter_range(index);
    parameter.name = flt->parameter_label(index);
    parameter.shortName = flt->parameter_short_label(index);
    parameter.symbol = flt->parameter_symbol(index);
    parameter.unit = flt->parameter_unit(index);
    parameter.ranges.min = range->min;
    parameter.ranges.max = range->max;
    parameter.ranges.def = range->init;
    parameter.hints = kParameterIsAutomable;

    if (flt->parameter_is_boolean(index))
        parameter.hints |= kParameterIsBoolean;
    if (flt->parameter_is_integer(index))
        parameter.hints |= kParameterIsInteger;
    if (flt->parameter_is_logarithmic(index))
        parameter.hints |= kParameterIsLogarithmic;
    if (flt->parameter_is_trigger(index))
        parameter.hints |= kParameterIsTrigger;
}

/**
  Get the current value of a parameter.
*/
float BoringPlugin::getParameterValue(uint32_t index) const {
    return fParams[index];
}

/**
  Change a parameter value.
*/
void BoringPlugin::setParameterValue(uint32_t index, float value) {
    const Boring::ParameterRange* range = flt->parameter_range(index);
    fParams[index] = value;
    flt->set_parameter(index, CLAMP(value, range->min, range->max));
}
// -----------------------------------------------------------------------
// Process

void BoringPlugin::activate() {
    // plugin is activated
    fSampleRate = getSampleRate();
    flt->init(fSampleRate);
}

void BoringPlugin::run(const float** inputs, float** outputs, uint32_t frames) {
    flt->process(inputs[0], outputs[2], (unsigned)frames);
}

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BoringPlugin)
};



// -----------------------------------------------------------------------

Plugin* createPlugin() {
    return new BoringPlugin();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
