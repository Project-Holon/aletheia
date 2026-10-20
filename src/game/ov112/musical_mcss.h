#ifndef GAME_OV112_MUSICAL_MCSS_H
#define GAME_OV112_MUSICAL_MCSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_mcss.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/mus_poke_draw_shared_types.h"
#include "../ov112/mus_poke_draw_shared_types.h"

void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap);
void MUSICAL_MCSS_FreeRenderPool(char *renderPool);
void MUSICAL_MCSS_TickMCAnim(char *renderPool);
void MUSICAL_MCSS_DrawMC(int *p, void (*arg)(unsigned, McssMatrixInput *, MusPokeDrawBig *));
char *MUSICAL_MCSS_LoadMC(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g);
void MUSICAL_MCSS_FreeMC(char *a, char *mcAnim);
void MUSICAL_MCSS_SetCameraBack(void *renderPool);
void MUSICAL_MCSS_SetCellVramBase(char *renderPool,int b);
void MUSICAL_MCSS_SetAnimVramBase(u8 *renderPool, int a);
void MUSICAL_MCSS_SetMCAnimPos(char *mcAnim, int *q);
void MUSICAL_MCSS_SetMCAnimScale(char *mcAnim, int *q);
void MUSICAL_MCSS_SetMCAnimFrame(char *mcAnim, unsigned short v);
void MUSICAL_MCSS_EnableDrawOffset(u8 *p);
void MUSICAL_MCSS_DisableDrawOffset(u8 *p);
void MUSICAL_MCSS_PauseMCAnim(u8 *p);
void MUSICAL_MCSS_ResumeMCAnim(char *mcAnim);
void MUSICAL_MCSS_SetMCAnim(char *mcAnim,u32 n);
u32 MUSICAL_MCSS_IsMCAnimHidden(u8 *mcAnim);
void MUSICAL_MCSS_HideMCAnim(char *mcAnim);
void MUSICAL_MCSS_ShowMCAnim(char *mcAnim);
void MUSICAL_MCSS_CopyField(MusPokeDrawObject *a,MusPokeDrawObject *b);
void MUSICAL_MCSS_LoadCellBank(u8 *renderPool,int index,u32 *res,u32 mode);
void MUSICAL_MCSS_FreeCellBank(void *a, void **p);
void MUSICAL_MCSS_InitMCAnim(char *mcAnim, int kind);
void MUSICAL_MCSS_SetupG3(void);
void MUSICAL_MCSS_CalcMatrix(const int *p, const int *m, u32 *out, u32 *w);
int MUSICAL_MCSS_GetMonValue(void *p);
/* END mkheaders: generated region */

#endif
