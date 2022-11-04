import("stdfaust.lib");

hipfilter(ct) = fi.highpass(1,fc)
with {
    fc = ct;
};



filters(dp) = fi.lowpass(1,fc1) , fi.lowpass(1,fc2), fi.lowpass(1,fc3), fi.lowpass(1,fc4),fi.lowpass(1,fc5), fi.lowpass(1,fc6), fi.lowpass(1,fc7), fi.lowpass(1,fc8)
with {
fc1 = (10000) * dp + 100;
fc2 = 9000 * dp + 90;
fc3 = 8500 * dp + 85;
fc4 = 8900 * dp + 89;
fc5 = 10000 * dp + 100;
fc6 = 8666 * dp + 86;
fc7 = 9500 * dp + 95;
fc8 = 9999 * dp + 99; 
};

delay(pd) = de.delay(30000,d) , de.delay(30000,d2), de.delay(30000,d3), de.delay(30000,d4) , de.delay(30000,d5), de.delay(30000,d6), de.delay(30000,d7) ,de.delay(30000,d8)
with {
d = pd * ma.SR * 0.001 * 500 + 10;
d2 =  pd * ma.SR * 0.001 * 520 + 20;
d3 = pd * ma.SR * 0.001 * 510 + 30;
d4 =  pd * ma.SR * 0.001 * 500 + 10;
d5 = pd * ma.SR * 0.001 * 520 + 20;
d6 =  pd * ma.SR * 0.001 * 590 + 20;
d7 = pd * ma.SR * 0.001 * 510 + 10;
d8 =  pd * ma.SR * 0.001 * 520 + 20;
};

allpass(erd) = fi.fb_comb(30000,d,.85, 1-.85), fi.fb_comb(30000,d2,.85, 1- .85), fi.fb_comb(30000,d3,.55, 1-.55), fi.fb_comb(30000,d4,.84, 1-.84) , fi.fb_comb(30000,d5,.89, 1-.89 ), fi.fb_comb(30000,d6,.75, 1-.75), fi.fb_comb(30000,d7,.89, 1-.89 ),fi.fb_comb(30000,d8,.93,1-.93), _
with {
 d = erd * ma.SR * 0.001 * 550 + 10;
 d2 = erd * ma.SR * 0.001 * 530 +5;
 d3 = erd * ma.SR * 0.001 * 540 + 8;
 d4 = erd * ma.SR * 0.001 * 550 +16;
 d5 = erd * ma.SR * 0.001 * 530 + 20;
 d6 = erd * ma.SR * 0.001 * 560 + 10;
 d7 = erd * ma.SR * 0.001 * 540 + 8;
 d8 = erd * ma.SR * 0.001 * 530 + 5;
};

feedback(fbd) = fi.fbcombfilter(10000,d,0.85), fi.fbcombfilter(10000,d2,0.75),fi.fbcombfilter(10000,d3,0.85),fi.fbcombfilter(10000,d4,0.84),
fi.fbcombfilter(10000,d5,0.75), fi.fbcombfilter(10000,d6,0.85) , fi.fbcombfilter(10000,d7,0.85) , fi.fbcombfilter(10000,d8,0.75) ,_
with {
d = fbd * ma.SR * 0.001 * 122 + 10;
 d2 = fbd * ma.SR * 0.001 * 120 +5;
 d3 = fbd * ma.SR * 0.001 * 130 + 8;
 d4 = fbd * ma.SR * 0.001 * 140 +16;
 d5 = fbd * ma.SR * 0.001 * 130 + 20;
 d6 = fbd * ma.SR * 0.001 * 140 + 10;
 d7 = fbd * ma.SR * 0.001 * 130 + 8;
 d8 = fbd * ma.SR * 0.001 * 110 + 5;
};


matrix = mix_mtx
with {
    mix_mtx = _,_,_,_,_,_,_,_ :> _,_ :> _ * .125;

};
matrix2(er) = mix_mtx
with {
    mix_mtx = _,_,_,_,_,_,_,_,_ * er:> _;

};








predelay = nentry("predelay",1.0,0,1,0.01) : si.smoo;
highpass = nentry("highpasscutoff", 5000,20,20000,1) : si.smoo;
erdelay = nentry("erdelay",1.0,0,1,0.01) : si.smoo;
eramp = nentry("eramp",1.0,0,1,0.01) : si.smoo;
reflectionsdelay = nentry("reflectionsdelay",1.0,0,1,0.01) : si.smoo;
decaydelay = nentry("decaydelay",1.0,0,1,0.01) : si.smoo;
delaywet = nentry("delaywet",1.0,0,1,0.01) : si.smoo;
damping = nentry("damp", 1.0,0,1,0.01) : si.smoo;
mixhighpassin = nentry("mixhighpassin", 0.5,0,1,0.01) :si.smoo;
mixhighpassout = nentry("mixhighpassout", 0.5,0,1,0.01) :si.smoo;
process(x) = par(i,2, x : hipfilter(highpass) * mixhighpassin + x * (1 - mixhighpassin) :> _ <: filters(damping) : delay(predelay) : matrix <: allpass(erdelay) : feedback(decaydelay): matrix2(eramp)  <: hipfilter(highpass) * mixhighpassout, _ *(1-mixhighpassout)  :> _ * delaywet + x *(1- delaywet)) : _,_;
