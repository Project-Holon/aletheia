#ifndef GAME_ARM9_TIME_ICON_H
#define GAME_ARM9_TIME_ICON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of time_icon.c, prototypes copied from their definitions. */

struct TimeIcon;
struct TcbList;
struct BmpWin;
struct TcblList;
struct TcbTask;
struct TcblTask;

#include "../types.h"

struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId);
struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);
void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);
struct TimeIcon *TIME_ICON_Alloc(u32 heapId);
void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval);
void TIME_ICON_Delete(struct TimeIcon *icon);
void TIME_ICON_TaskMain(struct TcbTask *tcb, void *work);
void TIME_ICON_NodeMain(struct TcblTask *node, void *work);
void TIME_ICON_Update(struct TimeIcon *icon);
/* END mkheaders: generated region */

#endif
