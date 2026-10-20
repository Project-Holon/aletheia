#ifndef GAME_OV031_UNION_SUBDISP_H
#define GAME_OV031_UNION_SUBDISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_subdisp.c, prototypes copied from their definitions. */

struct GameSystem;

#include "../ov031/union_subdisp_types.h"
#include "../ov012/union_comm_types.h"
#include "../types.h"

UnionSubdispWork *UNION_SUBDISP_Create(struct GameSystem *gameSystem);
void UNION_SUBDISP_Delete(UnionSubdispWork *work);
void UNION_SUBDISP_Draw(UnionSubdispWork *work, int mode);
void UNION_SUBDISP_Update(UnionSubdispWork *work, int mode);
void UNION_SUBDISP_CreateSystems(UnionSubdispWork *work);
void UNION_SUBDISP_DeleteSystems(UnionSubdispWork *work);
void UNION_SUBDISP_InitBgs(UnionSubdispWork *work, void *archive);
void UNION_SUBDISP_ExitBgs(UnionSubdispWork *work);
void UNION_SUBDISP_LoadFrameBg(UnionSubdispWork *work);
void UNION_SUBDISP_FreeFrameBgChar(UnionSubdispWork *work);
void UNION_SUBDISP_CreateLineWindows(UnionSubdispWork *work);
void UNION_SUBDISP_DeleteLineWindows(UnionSubdispWork *work);
void UNION_SUBDISP_LoadActorRes(UnionSubdispWork *work, void *archive);
void UNION_SUBDISP_DeleteActorRes(UnionSubdispWork *work);
void UNION_SUBDISP_CreateActors(UnionSubdispWork *work, void *archive);
void UNION_SUBDISP_DeleteActors(UnionSubdispWork *work);
int UNION_SUBDISP_CheckTouch(UnionSubdispWork *work, UnionRoomWork *unionWork);
void UNION_SUBDISP_SelectAppeal(UnionSubdispWork *work, int sel);
void UNION_SUBDISP_UpdateChatLines(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_DrawChatLine(UnionSubdispWork *work, const UnionChatEntry *entry, u8 lineNo);
void UNION_SUBDISP_DrawVisibleChatLines(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_MoveChatLine(UnionSubdispWork *work, u8 srcLine, u8 dstLine, UnionChatLog *log, int oldBottomIndex);
void UNION_SUBDISP_ScrollChatLines(UnionSubdispWork *work, UnionChatLog *log, int delta);
int UNION_SUBDISP_UpdateKnobDrag(UnionSubdispWork *work);
void UNION_SUBDISP_SyncKnobAndScroll(UnionRoomWork *room, UnionSubdispWork *work);
void UNION_SUBDISP_SetScrollFromKnob(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_SetKnobFromScroll(UnionSubdispWork *work, UnionChatLog *log);
int UNION_SUBDISP_GetScrollRange(UnionChatLog *log);
u32 UNION_SUBDISP_GetKnobStep(void *unused, u32 range);
int UNION_SUBDISP_CheckTrackTouch(UnionSubdispWork *work);
int UNION_SUBDISP_CheckLineTouch(UnionRoomWork *room, UnionSubdispWork *work, UnionChatLog *log);
UnionSubdispLineSlot *UNION_SUBDISP_FindHighlightSlot(UnionSubdispWork *work, UnionChatLog *log, int entryIndex);
int UNION_SUBDISP_StartLineHighlight(UnionSubdispWork *work, UnionChatLog *log, int entryIndex);
void UNION_SUBDISP_UpdateLineHighlights(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_CancelOtherHighlights(UnionSubdispWork *work, UnionChatLog *unused, int entryIndex);
int UNION_SUBDISP_SetLinePalette(UnionSubdispWork *unused, int lineNo, int highlighted);
void UNION_SUBDISP_PageScrollByButtons(UnionSubdispWork *unused, UnionRoomWork *room);
/* END mkheaders: generated region */

#endif
