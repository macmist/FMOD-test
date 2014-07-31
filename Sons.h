#ifndef SONS_H_INCLUDED
#define SONS_H_INCLUDED

typedef struct Batterie Batterie;
struct Batterie
{
    FMOD_RESULT resultat;
    FMOD_SOUND *sonBatterie;
    SDL_Rect position;
    SDL_Surface *texte ;
    SDL_Color couleur ;

};

void sonBatterie ( SDL_Surface *ecran , Uint8 *keystate ) ;
void associeSon ( FMOD_SYSTEM *systeme , Batterie *type , const char* chemin  ) ;

#endif /* SONS_H_INCLUDED */
