#ifndef GAME_OV204_INTRO_PARTICLE_H
#define GAME_OV204_INTRO_PARTICLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intro_particle.c, prototypes copied from their definitions. */

#include "../types.h"

char *INTRO_PARTICLE_Create(void *owner,unsigned heap);
void INTRO_PARTICLE_Delete(char *a);
void INTRO_PARTICLE_Main(void *unused);
void INTRO_PARTICLE_StartEffect(void **work, u32 x, u32 y, u32 z);
/* END mkheaders: generated region */

#endif
