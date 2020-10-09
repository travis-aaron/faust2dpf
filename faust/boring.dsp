import ("stdfaust.lib");
declare name "boring";
declare description "an lv2 instrument template for the DPF framework";
declare author "travis-aaron";
declare copyright "travis-aaron";
declare version "1.0";
declare licence "MIT";
declare nvoices "16";

gate = button("gate") : en.adsr(0.01,0.01,0.9,0.1);
gain = hslider("gain",0.1,0,1,0.01);
freq = hslider("freq",440,50,1000,0.01);

process = (gate*gain),os.sawtooth(freq):*<:ef.stereo_width(.5);
