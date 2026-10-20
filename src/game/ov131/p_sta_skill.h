#ifndef GAME_OV131_P_STA_SKILL_H
#define GAME_OV131_P_STA_SKILL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of p_sta_skill.c, prototypes copied from their definitions. */

struct PStaSkillWork;
struct PStaSkillSlot;
typedef struct PStaSkillWork PStaSkillWork;
typedef struct PStaSkillSlot PStaSkillSlot;

#include "../ov131/p_status_types.h"
#include "../types.h"

PStaSkillWork *P_STA_SKILL_Create(PStatusWork *wk);
void P_STA_SKILL_Delete(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_Main(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_LoadArcGraphics(PStatusWork *wk, PStaSkillWork *work, void *arc);
void P_STA_SKILL_Exit(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_CreateObjects(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_DeleteObjects(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_InitStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ShowStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_FreeStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HideStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_PrintStatsPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ApplyStatsScreen(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_RefreshMoveDetail(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ApplyMovesScreen(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_PrintStats(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_DrawHpBar(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_PrintMoveDetail(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_InitMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_ShowMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_FreeMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HideMovesPage(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_UpdateInput(PStatusWork *wk, PStaSkillWork *work);
int P_STA_SKILL_HandleKeys(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HandleTouch(PStatusWork *wk, PStaSkillWork *work);
int P_STA_SKILL_HandleKeysForget(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_HandleTouchForget(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_StepCursor(PStatusWork *wk, PStaSkillWork *work);
void P_STA_SKILL_SetCursor(PStatusWork *wk, PStaSkillWork *work, u8 newSlot, int forceRefresh);
void P_STA_SKILL_SwapMoves(PStatusWork *wk, PStaSkillWork *work, u32 slotA, u32 slotB);
void P_STA_SKILL_SetNewMoveHeld(PStatusWork *wk, PStaSkillWork *work, int isNewMoveHeld);
void P_STA_SKILL_ShowCantForgetMsg(PStatusWork *wk, PStaSkillWork *work, int result);
u16 P_STA_SKILL_GetNatureStatColor(PStatusWork *wk, PStaSkillWork *work, unsigned char nature, u32 statIndex);
void P_STA_SKILL_CreateSlotObjects(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot, u8 index);
void P_STA_SKILL_DeleteSlotObjects(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_UpdateSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_InitSlotText(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_ShowSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_FreeSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_HideSlot(PStatusWork *wk, PStaSkillWork *work, PStaSkillSlot *slot);
void P_STA_SKILL_GetSlotTouchRect(PStaSkillSlot *slot, StaTouchRect *rect);
void P_STA_SKILL_GetSlotPos(PStaSkillSlot *slot, StaOamPoint *out);
void P_STA_SKILL_SetSlotAnim(PStaSkillSlot *slot, int animOffset);
/* END mkheaders: generated region */

#endif
