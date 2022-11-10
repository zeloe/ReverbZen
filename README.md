# ReverbZen 
 A Reverb written with Faust 
## Download Faust 
[faustgitub](https://github.com/grame-cncm/faust) and follow the instructions inside the downloaded release.
## Compiling the Faust Code 
[fausteffect](https://faustdoc.grame.fr/workshops/2020-04-10-faust-juce/#simple-audio-effect-plug-in) Tutorial for using faust code as effect. \
inside terminal launch:
> faust -i -a faustMinimal.h reverb.dsp -o reverb.h 

## How it works
<img width="361" alt="predelay" src="https://user-images.githubusercontent.com/54742442/201081263-fe1e42e5-5fca-48f1-995f-e41c0a991895.png">

x-axis = PreDelayDelayTime  \
y-axis = LowpassFilterCutoffFrequency  \
Points = representation of signals

<img width="444" alt="EarlyReflections" src="https://user-images.githubusercontent.com/54742442/201081816-474ced07-1407-476c-a086-ac37e645dfb0.png">

x-axis = EarlyReflectionsDelayTime  \
y-axis = Damping (LowpassFilterCutoffFrequency) factor  \
Points = representation of signals

### Other Parameters

Mix = Dry<->Wet Mix \
Eramp = parameter for adding EarlyReflections to Output \
Highpass = high pass filter cutoff frequency  \
Bypass = bypass high pass filter \
Pre / Post = Pre or Post routing of high pass filter \
Decay = Feedback Amount



## Further reading
for instructions on how to integrate your code inside JUCE [FAUST_Tutorial](https://faustdoc.grame.fr/workshops/2020-04-10-faust-juce/#simple-audio-effect-plug-in) \
further reading on reverbs [SchroederReverberators](https://ccrma.stanford.edu/~jos/pasp/Schroeder_Reverberators.html) \
This project was based on SchroederReverberators.

## How it looks

<img width="855" alt="Full" src="https://user-images.githubusercontent.com/54742442/201083605-d49d008e-1a35-48da-bace-931e8e4fe1ba.png">

