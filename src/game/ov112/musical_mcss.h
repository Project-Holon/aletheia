#ifndef GAME_OV112_MUSICAL_MCSS_H
#define GAME_OV112_MUSICAL_MCSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_mcss.c, prototypes copied from their definitions. */

struct McssRenderPool;
struct McssMcAnim;
struct MusPokeDrawSlot;
struct McssCellBankJob;
typedef struct McssRenderPool McssRenderPool;
typedef struct McssMcAnim McssMcAnim;
typedef struct McssCellBankJob McssCellBankJob;

#include "../types.h"
#include "../ov112/mus_poke_draw_shared_types.h"
#include "../ov112/mus_poke_draw_shared_types.h"

struct TcbTask;

McssRenderPool *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap);
void MUSICAL_MCSS_FreeRenderPool(McssRenderPool *renderPool);
void MUSICAL_MCSS_TickMCAnim(McssRenderPool *renderPool);
void MUSICAL_MCSS_DrawMC(McssRenderPool *p, void (*arg)(unsigned, McssMatrixInput *, MusPokeDrawSlot *));
McssMcAnim *MUSICAL_MCSS_LoadMC(McssRenderPool *a,u32 b,u32 c,u32 d,u32 *e,struct MusPokeDrawSlot *f,u32 g);
void MUSICAL_MCSS_FreeMC(McssRenderPool *a, McssMcAnim *mcAnim);
void MUSICAL_MCSS_SetCameraBack(McssRenderPool *renderPool);
void MUSICAL_MCSS_SetCellVramBase(McssRenderPool *renderPool,int b);
void MUSICAL_MCSS_SetAnimVramBase(McssRenderPool *renderPool, int a);
void MUSICAL_MCSS_SetMCAnimPos(McssMcAnim *mcAnim, int *q);
void MUSICAL_MCSS_SetMCAnimScale(McssMcAnim *mcAnim, int *q);
void MUSICAL_MCSS_SetMCAnimFrame(McssMcAnim *mcAnim, unsigned short v);
void MUSICAL_MCSS_EnableDrawOffset(McssMcAnim *p);
void MUSICAL_MCSS_DisableDrawOffset(McssMcAnim *p);
void MUSICAL_MCSS_PauseMCAnim(McssMcAnim *p);
void MUSICAL_MCSS_ResumeMCAnim(McssMcAnim *mcAnim);
void MUSICAL_MCSS_SetMCAnim(McssMcAnim *mcAnim,u32 n);
u32 MUSICAL_MCSS_IsMCAnimHidden(McssMcAnim *mcAnim);
void MUSICAL_MCSS_HideMCAnim(McssMcAnim *mcAnim);
void MUSICAL_MCSS_ShowMCAnim(McssMcAnim *mcAnim);
void MUSICAL_MCSS_CopyField(McssMcAnim *a,McssMcAnim *b);
void MUSICAL_MCSS_LoadCellBank(McssRenderPool *renderPool,int index,u32 *res,u32 mode);
void MUSICAL_MCSS_FreeCellBank(struct TcbTask *a, void *pArg);
void MUSICAL_MCSS_InitMCAnim(McssMcAnim *mcAnim, int kind);
void MUSICAL_MCSS_SetupG3(void);
void MUSICAL_MCSS_CalcMatrix(const int *p, const int *m, u32 *out, u32 *w);
int MUSICAL_MCSS_GetMonValue(void *p);
/* END mkheaders: generated region */

#endif
