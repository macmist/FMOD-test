#ifndef GFONCT_H_INCLUDED
#define GFONCT_H_INCLUDED

    #define LONGUEUR 640
    #define LARGEUR 480

    #include "Sons.h"

        typedef struct
    {
        char key[SDLK_LAST];
        int mousex,mousey;
        int mousexrel,mouseyrel;
        char mousebuttons[8];
        char quit;
    } Input;

    void associeSon ( FMOD_SYSTEM *systeme , Batterie *type , const char* chemin  ) ;
    void associePos ( Batterie *type ) ;
    void associeText ( Batterie *type , const char *chaine , TTF_Font *police )  ;
    void afficheTexte ( Batterie *type , SDL_Surface *ecran ) ;
    void associeCouleur ( Batterie *type ) ;
    void liberation ( Batterie *type) ;



#endif /* GFONCT_H_INCLUDED*/
