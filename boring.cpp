
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







#include "boring.hpp"



#include <utility>
#include <cmath>

class boring::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef boring::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[2];
	float fConst3;
	float fConst4;
	int iRec1[2];
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "travis-aaron");
		m->declare("copyright", "travis-aaron");
		m->declare("description", "an lv2 instrument template for the DPF framework");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "boring.dsp");
		m->declare("licence", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "boring");
		m->declare("nvoices", "16");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
		m->declare("version", "1.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 0;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst2 = (1.0f / fConst1);
		fConst3 = (0.100000001f / fConst1);
		fConst4 = (0.899999976f / std::max<float>(1.0f, (0.100000001f * fConst0)));
		fConst5 = (1.0f / fConst0);
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.10000000000000001f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(440.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec1[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("boring");
		ui_interface->addHorizontalSlider("freq", &fHslider1, 440.0f, 50.0f, 1000.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("gain", &fHslider0, 0.100000001f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (1.5f * float(fHslider0));
		float fSlow1 = float(fButton0);
		int iSlow2 = (fSlow1 == 0.0f);
		float fSlow3 = std::max<float>(1.00000001e-07f, std::fabs(float(fHslider1)));
		float fSlow4 = (fConst5 * fSlow3);
		float fSlow5 = (1.0f - (fConst0 / fSlow3));
		for (int i = 0; (i < count); i = (i + 1)) {
			fVec0[0] = fSlow1;
			fRec0[0] = (fSlow1 + (fRec0[1] * float((fVec0[1] >= fSlow1))));
			iRec1[0] = (iSlow2 * (iRec1[1] + 1));
			float fTemp0 = (fSlow4 + (fRec2[1] + -1.0f));
			int iTemp1 = (fTemp0 < 0.0f);
			float fTemp2 = (fSlow4 + fRec2[1]);
			fRec2[0] = (iTemp1 ? fTemp2 : fTemp0);
			float fRec3 = (iTemp1 ? fTemp2 : (fSlow4 + (fRec2[1] + (fSlow5 * fTemp0))));
			float fTemp3 = (fSlow0 * (std::max<float>(0.0f, (std::min<float>((fConst2 * fRec0[0]), std::max<float>((1.10000002f - (fConst3 * fRec0[0])), 0.899999976f)) - (fConst4 * float(iRec1[0])))) * ((2.0f * fRec3) + -1.0f)));
			output0[i] = FAUSTFLOAT(fTemp3);
			output1[i] = FAUSTFLOAT(fTemp3);
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




boring::boring()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

boring::~boring()
{
}

void boring::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void boring::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void boring::process(
    
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *boring::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "freq";
    
    case 1:
        return "gain";
    
    case 2:
        return "gate";
    
    default:
        return 0;
    }
}

const char *boring::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    default:
        return 0;
    }
}

const char *boring::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "freq";
    
    case 1:
        return "gain";
    
    case 2:
        return "gate";
    
    default:
        return 0;
    }
}

const char *boring::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    default:
        return 0;
    }
}

const boring::ParameterRange *boring::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 440, 50, 1000 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 0.1, 0, 1 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool boring::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    case 2:
        return true;
    
    default:
        return false;
    }
}

bool boring::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    case 2:
        return true;
    
    default:
        return false;
    }
}

bool boring::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    case 2:
        return true;
    
    default:
        return false;
    }
}

bool boring::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float boring::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider1;
    
    case 1:
        return dsp.fHslider0;
    
    case 2:
        return dsp.fButton0;
    
    default:
        (void)dsp;
        return 0;
    }
}

void boring::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider1 = value;
        break;
    
    case 1:
        dsp.fHslider0 = value;
        break;
    
    case 2:
        dsp.fButton0 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float boring::get_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float boring::get_gain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float boring::get_gate() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fButton0;
}


void boring::set_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void boring::set_gain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void boring::set_gate(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fButton0 = value;
}




