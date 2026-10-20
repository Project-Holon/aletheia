#ifndef GAME_OV112_MUS_POKE_DRAW_H
#define GAME_OV112_MUS_POKE_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_poke_draw.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/mus_poke_draw_shared_types.h"

void *MUSICAL_MCSS_CreateRenderObj(u32 heap);
void MUSICAL_MCSS_DeleteRenderObj(int a);
void MUSICAL_MCSS_TickAnim(u8 *p);
void MUSICAL_MCSS_DrawRenderObj(void **p);
u8 *MUSICAL_MCSS_SetupRenderObj(MusPokeDrawScene *p,const u8 *b,int c);
void MUSICAL_MCSS_FreeRenderObj(int a, int b);
void MUSICAL_MCSS_SetRenderPos(int *p, int *q);
void MUSICAL_MCSS_SetRenderScale(int *p, int *q);
void MUSICAL_MCSS_SetRenderFrame(int *p, unsigned short v);
void MUSICAL_MCSS_SetRenderVisible(int *p,int b);
int MUSICAL_MCSS_IsRenderVisible(u8 **p);
void MUSICAL_MCSS_ResumeRenderAnim(void **p);
void MUSICAL_MCSS_PauseRenderAnim(void *a);
void MUSICAL_MCSS_SetRenderAnim(void *a, u32 n);
void MUSICAL_MCSS_ResetRender(int a);
void MUSICAL_MCSS_ResetRender2(int a,int b);
void MUSICAL_MCSS_SetRenderDrawOffset(void *slot, int isLarge);
void MUSICAL_MCSS_SetRenderCellVramBase(void **p,int b);
void MUSICAL_MCSS_SetRenderAnimVramBase(u8 *p, int a);
u8 *MUSICAL_MCSS_GetRenderElem(u8 *p, int i);
u8 *MUSICAL_MCSS_GetRenderFlags(u8 *p);
char *MUSICAL_MCSS_GetRenderMatrix(char *p);
void MUSICAL_MCSS_SetMatrix(unsigned mode, McssMatrixInput *in, MusPokeDrawBig *p);
void MUSICAL_MCSS_GetPokemonArcs(u8 *mon, u32 *out, u32 k);
/* END mkheaders: generated region */

#endif
