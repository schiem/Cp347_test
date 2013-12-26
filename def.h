#ifndef DEF_H
#define DEF_H
/*The process of making a color:

The Uint32 colors are stored in 32 bit integers. 
That gets divided into four segments of 8 bits each:
R - 0000 0000
G - 0000 0000
B - 0000 0000
A - 0000 0000

To find the Uint 32 color of a number, first find it's RGB.
Let's take yellow for example.  It has an RGB of (255, 255, 0)
So, we convert 255 to binary, which is:

1111 1111

giving us an RGB of:
R - 1111 1111
G - 1111 1111
B - 0000 0000
A - Ignore it :)

which gives a final binary number of :

1111 1111 1111 1111 0000 0000,

which translates to 16776960 in decimal, as you can see below.

There is a python file which will perform this conversion for you,
which can be obtained from https://github.com/schiem/RGBtoSDL
*/



#define YELLOW 16776960
#define BLUE 255
#define RED 16711680
#define GREEN 65280
#define WHITE 16777215
#define BLACK 0
#define DARK_RED 729808896  //I don't trust this value, it's: 00101011 10000000 00000000 00000000 whereas RED is:
//oopsie, good call.  It's supposed to be 32 bits, because of the alpha, but for some reason, the alpha channel doesn't get factored in like it's supposed to, so it ends up just being 24 bit.  The thread that I got the formula used 32 bit, but when I tried it it didn't work, and after experimentation I realized it was actually 24 bit.
#define DARKER_GREEN 2850816 //                               11111111 00000000 00000000. What's with the 32-bit vs 24-bit?
#define DARK_GREEN 3629312
#define BROWN 6371840
#define DARK_GRAY 3026478
#define LIGHT_GRAY 13158600
#define GRAY 6579300
#define PERSIAN_BLUE 5243032

#endif
