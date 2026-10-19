#ifndef GAME_ARM9_APP_TASKMENU_H
#define GAME_ARM9_APP_TASKMENU_H

/* Public functions of app_taskmenu.c, prototypes copied from their definitions. */

struct TaskMenuWork;
struct TaskMenuInitWork;
struct TaskMenuRes;
struct BmpWin;
struct GFont;
struct PrintQueue;
struct TaskMenuWin;
typedef struct TaskMenuWork TaskMenuWork;
typedef struct TaskMenuInitWork TaskMenuInitWork;
typedef struct TaskMenuRes TaskMenuRes;
typedef struct TaskMenuWin TaskMenuWin;

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

#endif
