#ifndef GAME_OV131_P_STA_SUB_H
#define GAME_OV131_P_STA_SUB_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of p_sta_sub.c, prototypes copied from their definitions. */

struct PStaSubWork;
struct StaSubStroke;
typedef struct PStaSubWork PStaSubWork;
typedef struct StaSubStroke StaSubStroke;

#include "../ov131/p_status_types.h"
#include "../types.h"
#include "../sdk_fx.h"

void *P_STA_SUB_Create(PStatusWork *wk);
void P_STA_SUB_Delete(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_Main(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_LoadArcGraphics(PStatusWork *wk, struct PStaSubWork *unused, void *arc);
void P_STA_SUB_Exit(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_CreateObjects(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_DeleteObjects(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_InitWindows(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_Refresh(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_FreeWindows(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_HideSprite(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_PrintWindows(PStatusWork *wk, PStaSubWork *work, void *mon);
void P_STA_SUB_UpdatePet(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_StartPetReaction(PStatusWork *wk, PStaSubWork *work);
int P_STA_SUB_StepPetTimer(PStatusWork *wk, PStaSubWork *work, u8 *strokeTurns);
int P_STA_SUB_PetWiggle(PStatusWork *wk, PStaSubWork *work);
int P_STA_SUB_PetHop(PStatusWork *wk, PStaSubWork *work);
int P_STA_SUB_PetRise(PStatusWork *wk, PStaSubWork *work, int isRising);
void P_STA_SUB_UpdateTouch(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_TrackStrokes(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_ResetStroke(StaSubStroke *stroke, u32 x, u32 y);
void P_STA_SUB_AddStrokeTurn(StaSubStroke *stroke, u32 x, u32 y, int dir);
void P_STA_SUB_UpdateLapFrames(PStatusWork *wk, PStaSubWork *work, int lapDone);
void P_STA_SUB_CreateMcss(PStatusWork *wk, PStaSubWork *work, void *mon);
void P_STA_SUB_DeleteMcss(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_SetPetOffset(PStatusWork *wk, PStaSubWork *work, int radius);
void P_STA_SUB_ApplyMcssOffset(PStatusWork *wk, PStaSubWork *work, VecFx32 *baseOfs);
void P_STA_SUB_GetSpeciesAdjust(PStatusWork *wk, PStaSubWork *work, VecFx32 *extraOfs, VecFx32 *frontScale);
/* END mkheaders: generated region */

#endif
