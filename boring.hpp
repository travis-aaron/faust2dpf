
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: boring.dsp
// Name: boring
// Author: travis-aaron
// Copyright: travis-aaron
// License: 
// Version: 1.0
//------------------------------------------------------------------------------






#pragma once
#ifndef boring_Faust_pp_Gen_HPP_
#define boring_Faust_pp_Gen_HPP_

#include <memory>

class boring {
public:
    boring();
    ~boring();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 0 };
    enum { NumOutputs = 2 };
    enum { NumActives = 3 };
    enum { NumPassives = 0 };
    enum { NumParameters = 3 };

    enum Parameter {
        p_freq,
        p_gain,
        p_gate,
        
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_freq() const noexcept;
    
    float get_gain() const noexcept;
    
    float get_gate() const noexcept;
    
    
    void set_freq(float value) noexcept;
    
    void set_gain(float value) noexcept;
    
    void set_gate(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // boring_Faust_pp_Gen_HPP_
