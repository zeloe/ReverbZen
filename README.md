# ReverbZen 
A Reverb written with Faust and JUCE, based on [SchroederReverberators](https://ccrma.stanford.edu/~jos/pasp/Schroeder_Reverberators.html). \
This reverb effect uses different stages. It splits input signal in parallel and uses different types of delaylines. \
Different filters are provided to get rid of unwanted resonances. \
Check out [reverb.dsp](/Source/reverb.dsp) file to get more detailed insight.
## Download Faust 
[faustgitub](https://github.com/grame-cncm/faust) and follow the instructions inside the downloaded release.
## Compiling the Faust Code 
[fausteffect](https://faustdoc.grame.fr/workshops/2020-04-10-faust-juce/#simple-audio-effect-plug-in) Tutorial for using faust code as effect. \
inside terminal launch:
> faust -i -a faustMinimal.h reverb.dsp -o reverb.h 

## How it works
<img width="361" alt="predelay" src="https://user-images.githubusercontent.com/54742442/201920106-9751508a-4099-4ff4-bbad-d915a9d63bb2.png">

x-axis = PreDelayDelayTime  \
y-axis = LowpassFilterCutoffFrequency  \
Points = representation of signals

<img width="444" alt="EarlyReflections" src="https://user-images.githubusercontent.com/54742442/201081816-474ced07-1407-476c-a086-ac37e645dfb0.png">

x-axis = EarlyReflectionsDelayTime  \
y-axis = Damping (LowpassFilterCutoffFrequency) factor  \
Points = representation of signals

### Other Parameters

Mix = Dry<->Wet Mix \
Width = Mid <-> Side Mix \
Highpass = high pass filter cutoff frequency  \
Bypass = bypass high pass filter \
Pre / Post = Pre or Post routing of high pass filter \
Decay = Feedback Amount



## Further reading
for instructions on how to integrate your code inside JUCE [FAUST_Tutorial](https://faustdoc.grame.fr/workshops/2020-04-10-faust-juce/#simple-audio-effect-plug-in) 
## For more amazing projects
[Made-With-Faust](https://faust.grame.fr/community/powered-by-faust/)
## How it looks

<img width="855" alt="Full" src="https://user-images.githubusercontent.com/54742442/201920268-3ac9950b-2e27-47a6-a175-31a548666332.png">


