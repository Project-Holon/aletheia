#ifndef GAME_OV112_MUS_POKE_DRAW_H
#define GAME_OV112_MUS_POKE_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_poke_draw.c, prototypes copied from their definitions. */

#include "../ov112/mus_poke_draw_shared_types.h"
#include "../types.h"

MusPokeDrawScene *MUSICAL_MCSS_CreateRenderObj(u32 heap);
void MUSICAL_MCSS_DeleteRenderObj(MusPokeDrawScene *a);
void MUSICAL_MCSS_TickAnim(MusPokeDrawScene *p);
void MUSICAL_MCSS_DrawRenderObj(MusPokeDrawScene *p);
MusPokeDrawSlot *MUSICAL_MCSS_SetupRenderObj(MusPokeDrawScene *p,const u8 *b,int c);
void MUSICAL_MCSS_FreeRenderObj(MusPokeDrawScene *a, MusPokeDrawSlot *b);
void MUSICAL_MCSS_SetRenderPos(MusPokeDrawSlot *p, int *q);
void MUSICAL_MCSS_SetRenderScale(MusPokeDrawSlot *p, int *q);
void MUSICAL_MCSS_SetRenderFrame(MusPokeDrawSlot *p, unsigned short v);
void MUSICAL_MCSS_SetRenderVisible(MusPokeDrawSlot *p,int b);
int MUSICAL_MCSS_IsRenderVisible(MusPokeDrawSlot *p);
void MUSICAL_MCSS_ResumeRenderAnim(MusPokeDrawSlot *p);
void MUSICAL_MCSS_PauseRenderAnim(MusPokeDrawSlot *a);
void MUSICAL_MCSS_SetRenderAnim(MusPokeDrawSlot *a, u32 n);
void MUSICAL_MCSS_ResetRender(MusPokeDrawSlot *a);
void MUSICAL_MCSS_ResetRender2(MusPokeDrawSlot *a,int b);
void MUSICAL_MCSS_SetRenderDrawOffset(MusPokeDrawSlot *slot, int isLarge);
void MUSICAL_MCSS_SetRenderCellVramBase(MusPokeDrawScene *p,int b);
void MUSICAL_MCSS_SetRenderAnimVramBase(MusPokeDrawScene *p, int a);
MusPokeDrawTrack *MUSICAL_MCSS_GetRenderElem(MusPokeDrawSlot *p, int i);
u8 *MUSICAL_MCSS_GetRenderFlags(MusPokeDrawSlot *p);
char *MUSICAL_MCSS_GetRenderMatrix(MusPokeDrawSlot *p);
void MUSICAL_MCSS_SetMatrix(unsigned mode, McssMatrixInput *in, MusPokeDrawSlot *p);
void MUSICAL_MCSS_GetPokemonArcs(u8 *mon, u32 *out, u32 k);
/* END mkheaders: generated region */

#endif
