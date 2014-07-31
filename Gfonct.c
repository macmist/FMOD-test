/* Gfonct.c
--------------------

Par Macmist.

Contient les fonctions utilisées par la plupart des .c


--------------

Dernière modification le : 15 / 05 / 2011

 */

 #include "VerifFonctions.h"
 #include "Gfonct.h"
 #include "Sons.h"

void associeSon ( FMOD_SYSTEM *systeme , Batterie *type , const char* chemin ) /* fonction utilisee une seule fois par structures differentes */
{
    type->resultat = FMOD_System_CreateSound(systeme, chemin , FMOD_3D , 0 , &type->sonBatterie ) ;
     if (type -> resultat != FMOD_OK )
        {
            fprintf( stderr, "Impossible d'ouvrir %s" , chemin ) ;
            exit(EXIT_FAILURE);
        }
}

void associePos ( Batterie *type ) /* fonction utilisee une seule fois par structure differentes */
{
    type -> position . x = rand () % ((LONGUEUR - type -> texte -> w ) - 0 ) + 0 ;
    type -> position . y = rand () % ((LARGEUR - type -> texte -> h ) - 0 ) + 0 ;
}

void associeText ( Batterie *type , const char *chaine , TTF_Font *police ) /* fonction utilisee une seule fois par structure differentes */
{
    type -> texte = TTF_RenderText_Blended ( police , chaine ,  type -> couleur ) ;
    if (type -> texte == NULL )
    {
        fprintf( stderr, "Erreur pour le texte %s", chaine ) ;
        exit( EXIT_FAILURE ) ;
    }
}

void afficheTexte ( Batterie *type , SDL_Surface *ecran ) /* remets l'ecran en vert avant d'afficher le texte */
{
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12, 200, 37));
    SDL_Flip(ecran);

    SDL_BlitSurface(type->texte, NULL, ecran, &type->position);
    SDL_Flip(ecran);

}

void associeCouleur ( Batterie *type )
{
    SDL_Color couleurNoire = {0, 0, 0, 0 } ;
    SDL_Color violet = { 147 , 50 , 146 , 0 } ;
    SDL_Color vert = { 12 , 252 , 35 , 0 } ;
    SDL_Color bleu = { 0 , 224 , 253 , 0 } ;
    SDL_Color jaune = { 232 , 253 , 35 , 0 } ;
    SDL_Color rouge = { 156 , 0 , 0 , 0 } ;
    int i = 0 ;

    i = rand() % ( 6 - 0 ) + 0 ;
    switch (i)
    {
        case 0 : type->couleur = couleurNoire ;
            break ;
        case 1 : type->couleur = violet ;
            break ;
        case 2 : type->couleur = vert ;
            break ;
        case 3 : type->couleur = bleu ;
            break ;
        case 4 : type->couleur = jaune;
            break ;
        case 5 : type->couleur = rouge ;
            break ;
        default : break ;
    }
}

void liberation ( Batterie *type)
{
    FMOD_Sound_Release(type->sonBatterie) ;
    SDL_FreeSurface(type->texte);
}


void UpdateEvents(Input* in)
{
        SDL_Event event;
        int continuer =1;
        in->mousebuttons[SDL_BUTTON_WHEELUP] = 0;
        in->mousebuttons[SDL_BUTTON_WHEELDOWN] = 0;


	while(continuer)
	{
            SDL_WaitEvent(&event);
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    in->key[event.key.keysym.sym]=1;
                    break;
                case SDL_KEYUP:
                    in->key[event.key.keysym.sym]=0;
                    break;
                case SDL_MOUSEMOTION:
                    in->mousex=event.motion.x;
                    in->mousey=event.motion.y;
                    in->mousexrel=event.motion.xrel;
                    in->mouseyrel=event.motion.yrel;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    in->mousebuttons[event.button.button]=1;
                    break;
                case SDL_MOUSEBUTTONUP:
                        if (event.button.button!=SDL_BUTTON_WHEELUP && event.button.button!=SDL_BUTTON_WHEELDOWN)
                        in->mousebuttons[event.button.button]=0;
                    break;
                case SDL_QUIT:
                    in->quit = 1;
                    break;
                default:
                    break;
                }
            continuer = 0;

	}
}
