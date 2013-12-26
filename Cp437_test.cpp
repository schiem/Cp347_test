#include <iostream>
#include <SDL/SDL.h>
#include "ASCII_Lib.h"


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO );

    //Set up screen
    SDL_Surface* screen = SDL_SetVideoMode( 100, 100, 32, SDL_SWSURFACE );
    
    //Load ascii characters
    SDL_Surface* asciiBase = SDL_LoadBMP( "ascii.bmp" );
    
    //Create an optimized image
    SDL_Surface* ascii = SDL_DisplayFormat( asciiBase );

    //Free the old image
    SDL_FreeSurface( asciiBase );
    
    //Map the color key
    Uint32 colorkey = SDL_MapRGB( ascii->format, 0xFF, 0, 0xFF );

    //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
    SDL_SetColorKey( ascii, SDL_SRCCOLORKEY, colorkey );
    SDL_SetColorKey( ascii, SDL_SRCCOLORKEY, colorkey );

    bool running = true;

    if(argc<2)
    {
        std::cout << "No option specified" << std::endl;
    }
    else
    {
        int number;
        sscanf(argv[1], "%d", &number);
        SDL_Event e;
        while(running)
        {
           while(SDL_PollEvent(&e))
           {
               switch(e.type)
               {
                   case SDL_QUIT:
                       running = false;
               }
           }
           drawChr(5, 5, number, ascii, screen, BROWN);  
           SDL_Flip(screen);
           SDL_Delay(50);
       }
    
    }
    SDL_Quit();
    return 0;
}

