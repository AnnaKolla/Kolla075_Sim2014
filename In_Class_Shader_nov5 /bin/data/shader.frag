uniform vec3      iResolution;           // viewport resolution (in pixels)
uniform float     iGlobalTime;           // shader playback time (in seconds)
//uniform float     iChannelTime[4];       // channel playback time (in seconds)
uniform vec3      iChannelResolution0; // channel resolution (in pixels)
uniform vec4      iMouse;                // mouse pixel coords. xy: current (if MLB down), zw: click
uniform sampler2D iChannel0;          // input channel. XX = 2D/Cube
//uniform vec4      iDate;                 // (year, month, day, time in seconds)
//uniform float     iSampleRate;           // sound sample rate (i.e., 44100)

const int iterations=12;

void main(void)
{
    
    vec2 z = gl_FragCoord.xy / iResolution.xy*2.0 - 1.0;
    
    //fixes aspect ratio in favor of symmety
    z.y*=iResolution.y/iResolution.x;
    
    //gloobywavez
    z.x += sin(z.y*1.0+iGlobalTime * .2)/10.0;
    
    //zooom
    z*= 1.2 + sin(iGlobalTime*.45);
    
    //pan
    z+=vec2(sin(iGlobalTime*.2),cos(iGlobalTime*.01));
    
    //rotate
    //z=vec2(z.x*cos(iGlobalTime*.2)-z.y*sin(iGlobalTime*.2),z.y*cos(iGlobalTime*.2)+z.x*sin(iGlobalTime*.2));
    
    //this is our "starting point" try numbers between 0 and 2 for both x and y
    vec2 c=vec2(1.5, 1.1);
    
    float average=0.;
    float l=length(z);
    float prevl;
    for (int i=0; i<iterations; i++)
    {
        //kaliset base form
        z=abs(z)/dot(z,z) -c;
        
        //this is another function that can be iterated to produce some different fractals
        //comment out the previous kaliset and experiment with values with this one!!
        //z = abs(z)/(z.x*z.y)-c;
        
        prevl=l;
        l=length(z);
        
        average+=abs(l-prevl);
    }
    
    //get the average length based upon the amount of iterations elapsed. multiply it to adjust "definition"
    average/=float(iterations) * 15.;
    
    //color fluctuation
    average+=iGlobalTime*0.02;
    
    vec3 myColor=vec3(0.2,0.21,.62);
    vec3 finalColor;
    
    //set the colors!
    finalColor.r = (fract(float(average)/myColor.r));
    finalColor.g = (fract(float(average)/myColor.g));
    finalColor.b = (fract(float(average)/myColor.b));
    
    gl_FragColor = vec4(finalColor,1.0);

}