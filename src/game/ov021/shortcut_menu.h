#ifndef GAME_OV021_SHORTCUT_MENU_H
#define GAME_OV021_SHORTCUT_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shortcut_menu.c, prototypes copied from their definitions. */

struct ShortcutMenu;
struct MsgBank;
struct GfFont;
struct PrintSys;
struct ClactActor;
typedef struct ShortcutMenu ShortcutMenu;

#include "../types.h"

ShortcutMenu *SHORTCUT_MENU_Create(void *gameSystem, int mode, const u16 *savedState, u16 textHeapId, u16 heapId);
void SHORTCUT_MENU_Delete(ShortcutMenu *menu);
void SHORTCUT_MENU_Main(ShortcutMenu *menu);
int SHORTCUT_MENU_RunPrint(ShortcutMenu *menu);
void SHORTCUT_MENU_Start(ShortcutMenu *menu);
void SHORTCUT_MENU_RequestClose(ShortcutMenu *menu);
int SHORTCUT_MENU_IsWaitingInput(ShortcutMenu *menu);
u32 SHORTCUT_MENU_GetResult(ShortcutMenu *menu, u32 *outValue);
void SHORTCUT_MENU_InitList(ShortcutMenu *menu, const u16 *savedState, struct MsgBank *msgBank, struct GfFont *font, struct PrintSys *printSys, void *menuData, struct ClactActor **actors, u16 heapId);
void SHORTCUT_MENU_FreeList(ShortcutMenu *menu, u16 *savedState);
void SHORTCUT_MENU_OnKeyUp(ShortcutMenu *menu, int cursor, u32 itemCount, u32 *done);
void SHORTCUT_MENU_OnKeyDown(ShortcutMenu *menu, int cursor, int itemCount, int *done);
void SHORTCUT_MENU_UpdateInput(ShortcutMenu *menu);
int SHORTCUT_MENU_FinishPrint(ShortcutMenu *menu);
int SHORTCUT_MENU_GetSelection(ShortcutMenu *menu);
void SHORTCUT_MENU_ListMoveCallback(void *list);
void SHORTCUT_MENU_UpdateCursorBg(void *list, int unused0, int unused1);
void SHORTCUT_MENU_ClampListWindow(u16 *scroll, u16 *cursor, u16 itemCount);
void SHORTCUT_MENU_CreateList(ShortcutMenu *menu, u16 scroll, u16 cursor, u32 heapId);
int SHORTCUT_MENU_DeleteList(ShortcutMenu *menu, u16 *outScroll, u16 *outCursor);
void SHORTCUT_MENU_ScrollStep(void *task, ShortcutMenu *menu);
void SHORTCUT_MENU_SetActorsY(ShortcutMenu *menu, int offsetY);
/* END mkheaders: generated region */

#endif
