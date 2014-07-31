/* main.c

-----------------

Par Macmist.

Gère l'affichage du menu principal et permet d'accéder à toutes les fonctions

-----------------

dernière modification : 15 / 05 / 2011

*/
#include "VerifFonctions.h"
#include "Sons.h"


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL , *menu = NULL ;
    SDL_Rect posMenu;
    SDL_Event event;
    int continuer = 1;
    Uint8 *keystate = SDL_GetKeyState(NULL) ;

    posMenu.x=0;
    posMenu.y=0;


    SDL_Init(SDL_INIT_VIDEO) ;
    ecran = SDL_SetVideoMode(640 , 480 , 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption( "Application qui émet un son lors-ce qu'on appuie sur une touche", NULL);

    menu = IMG_Load("Images/Menup.jpg");
    SDL_BlitSurface(menu, NULL, ecran, &posMenu);
    SDL_Flip(ecran);

    srand(time(NULL)) ;

    while (continuer)
	{
		SDL_WaitEvent(&event);


		switch(event.type)
		{
		case SDL_QUIT:
			continuer = 0;
			break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

                case SDLK_ESCAPE:
                    continuer = 0 ;
                        break;
                case SDLK_KP1 :
                     sonBatterie( ecran , keystate ) ;
                     SDL_BlitSurface(menu, NULL, ecran, &posMenu);
                     SDL_Flip(ecran) ;
                    break;
                    case SDLK_1 :
                     sonBatterie( ecran , keystate ) ;
                     SDL_BlitSurface(menu, NULL, ecran, &posMenu);
                     SDL_Flip(ecran) ;
                    break;
                default:
                        break;
            }
        default : break;
        		}
	}


    SDL_Quit();


    return EXIT_SUCCESS;
}
