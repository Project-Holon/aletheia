#ifndef GAME_OV225_MANUAL_LIST_H
#define GAME_OV225_MANUAL_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_list.c, prototypes copied from their definitions. */

struct ManualData;
struct ManualListWork;

#include "../types.h"

struct TcbTask;

void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data);
void MANUAL_COMMON_DeleteListWork(char *work);
int MANUAL_COMMON_UpdateListWork(char *work);
void MANUAL_COMMON_ListWorkTaskNoop(struct TcbTask *unused0, void *unused1);
void MANUAL_COMMON_LoadListWorkAssets(char *work);
void MANUAL_COMMON_CreateListWorkMenu(char *work);
void MANUAL_COMMON_SetListWorkBgMode(struct ManualListWork *work);
void MANUAL_COMMON_DeleteListWorkAssets(char *work);
void MANUAL_COMMON_DeleteListWorkMenu(char *work);
int MANUAL_COMMON_UpdateListWorkInput(char *work);
int MANUAL_COMMON_UpdateListWorkDrag(char *work);
void MANUAL_COMMON_BuildListRects(u8 *rect);
u16 MANUAL_COMMON_GetCursorIndex(u16 **work);
u16 MANUAL_COMMON_GetLastVisible(u16 **work);
u16 MANUAL_COMMON_GetVisibleCount(u16 **work);
u16 MANUAL_COMMON_GetScrollTop(u16 **work);
void MANUAL_COMMON_RebuildListWindows(char *work);
u16 MANUAL_COMMON_HitToIndex(void *unused, u16 count, u16 value);
u16 MANUAL_COMMON_IndexToY(void *unused, u16 count, u16 index);
/* END mkheaders: generated region */

#endif
