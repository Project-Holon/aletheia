#ifndef GAME_OV203_DEMO3D_EXP_C_CRUISER_H
#define GAME_OV203_DEMO3D_EXP_C_CRUISER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of demo3d_exp_c_cruiser.c, prototypes copied from their definitions. */

struct Demo3dCruiserWork;
typedef struct Demo3dCruiserWork Demo3dCruiserWork;

void DEMO3D_EXP_C_CRUISER_LoadTextures(unsigned short heap);
void DEMO3D_EXP_C_CRUISER_Create(Demo3dCruiserWork *p);
void DEMO3D_EXP_C_CRUISER_Update(Demo3dCruiserWork *p);
void DEMO3D_EXP_C_CRUISER_DeleteActorGfx(Demo3dCruiserWork *work);
/* END mkheaders: generated region */

#endif
