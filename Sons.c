/* Son.c
--------------------

Par Macmist.

Contiens les fonctions de gestion du son


--------------

Dernière modification le : 15 / 05 / 2011

 */

#include "VerifFonctions.h"
#include "Gfonct.h"
#include <time.h>


void sonBatterie ( SDL_Surface *ecran , Uint8 *keystate )
{
    int continuer = 1 , i = 0 ;
    Input in;

    char fichier [50]  ;
    SDL_Event jouerSon ;

    TTF_Font *police = NULL ;


    FMOD_SYSTEM *systeme = NULL ;
    Batterie batterie[9], symbale[11], caisseClaire, grosseCaisse ;


    TTF_Init() ;
    police = TTF_OpenFont("jellb.ttf", 65) ;

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12, 200, 37)) ;
    SDL_Flip(ecran);

    FMOD_System_Create(&systeme);
	FMOD_System_Init(systeme, 32, FMOD_INIT_NORMAL, NULL) ;

    associeSon ( systeme , &caisseClaire , "Sons/Caisse_Claire.mp3" ) ;
    associeCouleur ( &caisseClaire ) ;
    associeText (&caisseClaire , "Tchak !" , police ) ;
    caisseClaire.position.x = ecran -> w / 2 - caisseClaire.texte -> w / 2 ;
    caisseClaire.position.y = ecran -> h / 2 - caisseClaire.texte -> h / 2 ;

    associeSon ( systeme , &grosseCaisse , "Sons/Grosse_Caisse.mp3" ) ;
    associeCouleur ( &grosseCaisse) ;
    associeText (&grosseCaisse , "Poum !" , police ) ;
    grosseCaisse.position.x = ecran -> w / 2 - grosseCaisse.texte -> w / 2 ;
    grosseCaisse.position.y = ecran -> h - grosseCaisse.texte -> h ;


    for ( i = 0 ; i < 9 ; i++ )
    {
        sprintf(fichier, "Sons/son%d.wav",  i);
        associeSon ( systeme , &batterie[i] , fichier ) ;
        associeCouleur ( &batterie [i] ) ;
        associeText ( &batterie[i] , "BAM" , police ) ;
        associePos ( &batterie [i] ) ;
        puts ( fichier ) ;
    }

    for ( i = 0 ; i < 11 ; i++ )
    {
        sprintf(fichier, "Sons/symb%d.wav",  i);
        associeSon ( systeme , &symbale[i] , fichier ) ;
        associeCouleur ( &symbale [i] ) ;
        associeText ( &symbale [i] , "Schlaf !" , police ) ;
        associePos ( &symbale [i] ) ;
        puts ( fichier ) ;
    }


    memset(&in,0,sizeof(in));
    while(!in.key[SDLK_ESCAPE] && !in.quit)
	{
	    UpdateEvents(&in);


            if (in.quit)
                continuer = 0;


         if(in.key[SDLK_ESCAPE] )continuer = 0;



         if (in.key[SDLK_RETURN])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, caisseClaire.sonBatterie, 0, 0 );
             afficheTexte( &caisseClaire , ecran ) ;
         }
         if (in.key[SDLK_SPACE])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, grosseCaisse.sonBatterie, 0, 0 ) ;
             afficheTexte( &grosseCaisse , ecran ) ;
         }
         if (in.key[SDLK_p])
            {
                FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[0].sonBatterie, 0, 0);
                afficheTexte ( &batterie[0] , ecran ) ;
            }
         if (in.key[SDLK_o])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[1].sonBatterie, 0, 0);
             afficheTexte ( &batterie[1] , ecran ) ;
         }
         if (in.key[SDLK_i])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[2].sonBatterie, 0, 0);
             afficheTexte ( &batterie[2] , ecran ) ;
         }
         if (in.key[SDLK_u])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[3].sonBatterie, 0, 0);
             afficheTexte ( &batterie[3] , ecran ) ;
         }
         if (in.key[SDLK_y])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[4].sonBatterie, 0, 0);
             afficheTexte ( &batterie[4] , ecran ) ;
         }
         if (in.key[SDLK_t])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[5].sonBatterie, 0, 0);
             afficheTexte ( &batterie[5] , ecran ) ;
         }
         if (in.key[SDLK_r])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[6].sonBatterie, 0, 0);
             afficheTexte ( &batterie[6] , ecran ) ;
         }
         if (in.key[SDLK_e])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[7].sonBatterie, 0, 0);
             afficheTexte ( &batterie[7] , ecran ) ;
         }
         if (in.key[SDLK_w])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, batterie[8].sonBatterie, 0, 0);
             afficheTexte ( &batterie[8] , ecran ) ;
         }
         if (in.key[SDLK_m])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[0].sonBatterie, 0, 0);
             afficheTexte ( &symbale[0] , ecran ) ;
         }
         if (in.key[SDLK_l])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[1].sonBatterie, 0, 0);
             afficheTexte ( &symbale[1] , ecran ) ;
         }
         if (in.key[SDLK_k])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[2].sonBatterie, 0, 0);
             afficheTexte ( &symbale[2] , ecran ) ;
         }
         if (in.key[SDLK_j])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[3].sonBatterie, 0, 0);
             afficheTexte ( &symbale[3] , ecran ) ;
         }
         if (in.key[SDLK_h])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[4].sonBatterie, 0, 0);
             afficheTexte ( &symbale[4] , ecran ) ;
         }
         if (in.key[SDLK_g])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[5].sonBatterie, 0, 0);
             afficheTexte ( &symbale[5] , ecran ) ;
         }
         if (in.key[SDLK_f])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[6].sonBatterie, 0, 0);
             afficheTexte ( &symbale[6] , ecran ) ;
         }
         if (in.key[SDLK_d])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[7].sonBatterie, 0, 0);
             afficheTexte ( &symbale[7] , ecran ) ;
         }
         if (in.key[SDLK_s])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[8].sonBatterie, 0, 0);
             afficheTexte ( &symbale[8] , ecran ) ;
         }
         if (in.key[SDLK_a])
         {
             FMOD_System_PlaySound(systeme, FMOD_CHANNEL_FREE, symbale[9].sonBatterie, 0, 0);
             afficheTexte ( &symbale[9] , ecran ) ;
         }

	}

    for (i = 0 ; i < 9 ; i++ )
    {
        liberation ( &batterie[i] ) ;
    }

    for (i = 0 ; i < 11 ; i++)
    {
        liberation ( &symbale[i] ) ;
    }

    liberation ( &grosseCaisse ) ;
    liberation ( &caisseClaire ) ;

    FMOD_System_Close(systeme);
	FMOD_System_Release(systeme);



    TTF_CloseFont(police);
    TTF_Quit();

}


