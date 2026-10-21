#ifndef GAME_ARM9_APP_TASKMENU_H
#define GAME_ARM9_APP_TASKMENU_H

#include "../types.h"

struct Strbuf;
typedef struct TaskMenuWork TaskMenuWork;
typedef struct TaskMenuRes TaskMenuRes;
typedef struct TaskMenuWin TaskMenuWin;

/* One menu entry (0xC bytes). */
typedef struct TaskMenuItem {
    struct Strbuf *str;         /* +0x00 */
    u16 msgColor;               /* +0x04 print colour */
    u32 type;                   /* +0x08 frame style; 1 is the back/cancel entry */
} TaskMenuItem;

/* Caller-filled template of a task menu (0x14 bytes). */
typedef struct TaskMenuInitWork {
    u32 heapId;                 /* +0x00 */
    u8 itemNum;                 /* +0x04 */
    u8 pad_05[3];
    const TaskMenuItem *itemWork; /* +0x08 */
    u32 posType;                /* +0x0C 0: (charPosX, charPosY) is the top left; else the bottom right */
    u8 charPosX;                /* +0x10 */
    u8 charPosY;                /* +0x11 */
    u8 width;                   /* +0x12 in characters, 13 when 0 */
    u8 height;                  /* +0x13 per entry, 3 when 0 */
} TaskMenuInitWork;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of app_taskmenu.c, prototypes copied from their definitions. */

struct TaskMenuWork;
struct TaskMenuRes;
struct BmpWin;
struct GFont;
struct PrintQueue;
struct TaskMenuWin;
typedef struct TaskMenuWork TaskMenuWork;
typedef struct TaskMenuRes TaskMenuRes;
typedef struct TaskMenuWin TaskMenuWin;

#include "../types.h"

TaskMenuWork *APP_TASKMENU_OpenMenu(TaskMenuInitWork *init, TaskMenuRes *res);
TaskMenuWork *APP_TASKMENU_OpenMenuFastDecide(TaskMenuInitWork *init, TaskMenuRes *res);
void APP_TASKMENU_CloseMenu(TaskMenuWork *menu);
void APP_TASKMENU_TransWinAfterPrint(TaskMenuWork *menu);
void APP_TASKMENU_UpdateMenu(TaskMenuWork *menu);
u32 APP_TASKMENU_IsFinish(TaskMenuWork *menu);
u8 APP_TASKMENU_GetCursorPos(const TaskMenuWork *menu);
void APP_TASKMENU_SetCursorActive(TaskMenuWork *menu, u32 isActive);
u32 APP_TASKMENU_IsDecide(TaskMenuWork *menu);
void APP_TASKMENU_CreateWindows(TaskMenuWork *menu, TaskMenuRes *res);
void APP_TASKMENU_SetWinActive(struct BmpWin *win, TaskMenuRes *res, int isActive);
void APP_TASKMENU_UpdateCursorColor(u16 *colorPhase, u16 *color, u32 bgFrame, u32 palNo);
void APP_TASKMENU_UpdateCursorColorBlend(u16 *colorPhase, u16 *color, u16 bgFrame, u32 palNo, u16 color0, u16 color1);
void APP_TASKMENU_SetDisableKey(TaskMenuWork *menu, int isDisable);
void APP_TASKMENU_SetCursorPos(TaskMenuWork *menu, int pos);
void APP_TASKMENU_UpdateKey(TaskMenuWork *menu);
void APP_TASKMENU_UpdateTouch(TaskMenuWork *menu);
TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, struct GFont *font, struct PrintQueue *printQue, u16 heapId);
void APP_TASKMENU_RES_Delete(TaskMenuRes *res);
TaskMenuWin *APP_TASKMENU_WIN_Create(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u16 heapId);
TaskMenuWin *APP_TASKMENU_WIN_CreateEx(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);
TaskMenuWin *APP_TASKMENU_WIN_CreateExNoScreen(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);
TaskMenuWin *APP_TASKMENU_WIN_CreateCore(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);
void APP_TASKMENU_WIN_Delete(TaskMenuWin *win);
void APP_TASKMENU_WIN_DeleteNoClear(TaskMenuWin *win);
void APP_TASKMENU_WIN_Free(TaskMenuWin *win);
void APP_TASKMENU_WIN_Update(TaskMenuWin *win);
void APP_TASKMENU_WIN_SetActive(TaskMenuWin *win, u32 isActive);
void APP_TASKMENU_WIN_SetDecide(TaskMenuWin *win, int isDecide);
u32 APP_TASKMENU_WIN_IsFinish(TaskMenuWin *win);
u32 APP_TASKMENU_WIN_IsTouch(TaskMenuWin *win);
void APP_TASKMENU_WIN_ResetDecide(TaskMenuWin *win);
void APP_TASKMENU_WIN_ChangePalette(TaskMenuWin *win, TaskMenuRes *res, u32 palNo, u32 color0, u16 color1);
void APP_TASKMENU_DrawWinFrame(struct BmpWin *win, TaskMenuRes *res, u32 frameStyle);
void APP_TASKMENU_WIN_ClearScreen(TaskMenuWin *win);
void APP_TASKMENU_WIN_TransChar(TaskMenuWin *win);
u32 APP_TASKMENU_WIN_IsUpdateTrans(TaskMenuWin *win);
/* END mkheaders: generated region */

#endif
