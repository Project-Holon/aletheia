#ifndef GAME_OV217_RESEARCH_LIST_RECOVERY_H
#define GAME_OV217_RESEARCH_LIST_RECOVERY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of research_list_recovery.c, prototypes copied from their definitions. */

struct ListViewState;

#include "../types.h"

u32 ListViewState_Create(u32 heapId);
void ListViewState_Destroy(void *state);
void ListViewState_Reset(struct ListViewState *state);
u32 ListViewState_GetMode(struct ListViewState *state);
u32 ListViewState_GetScrollX(struct ListViewState *state);
u32 ListViewState_GetScrollY(struct ListViewState *state);
void ListViewState_SetMode(struct ListViewState *state, u8 mode);
void ListViewState_SetScrollX(struct ListViewState *state, u32 scrollX);
void ListViewState_SetScrollY(struct ListViewState *state, u32 scrollY);
/* END mkheaders: generated region */

#endif
