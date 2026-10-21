#ifndef GAME_OV021_FIELD_MENU_H
#define GAME_OV021_FIELD_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_menu.c, prototypes copied from their definitions. */

struct FieldMenu;
struct TcbTask;
struct FieldMenuItem;
struct FieldMenuItemInit;
typedef struct FieldMenu FieldMenu;
typedef struct FieldMenuItem FieldMenuItem;
typedef struct FieldMenuItemInit FieldMenuItemInit;

#include "../types.h"

FieldMenu *FIELD_MENU_Create(u16 heapId, u16 subHeapId, void *parent, void *fieldMap, int slideIn);
void FIELD_MENU_NotifyParentOnExit(FieldMenu *menu);
void FIELD_MENU_Delete(FieldMenu *menu);
void FIELD_MENU_ShowBgLayers(void);
u32 FIELD_MENU_Update(FieldMenu *menu);
void FIELD_MENU_UpdateActorsForScroll(FieldMenu *menu);
void FIELD_MENU_ApplyBgScroll(FieldMenu *menu);
void FIELD_MENU_LoadGraphics(FieldMenu *menu, void *arcHandle, int layoutType, u32 mapInfo);
void FIELD_MENU_LoadFrameBg(int heapId, int hideFrame);
u32 FIELD_MENU_GetLayoutType(void *gameData, void *eventWork, u32 zoneId);
int FIELD_MENU_CountLayoutButtons(int layoutType);
void FIELD_MENU_CreateItems(FieldMenu *menu, void *arcHandle, int layoutType);
void FIELD_MENU_ColorTask(struct TcbTask *taskHandle, void *work);
void FIELD_MENU_SetScrolledOut(FieldMenu *menu);
int FIELD_MENU_GetSelectedButtonId(FieldMenu *menu);
void FIELD_MENU_SelectButton(FieldMenu *menu, u32 buttonId);
int FIELD_MENU_GetSlotIndex(u32 col, u32 row);
u32 FIELD_MENU_MoveCursor(FieldMenu *menu, u32 dir);
void FIELD_MENU_HandleKeys(FieldMenu *menu);
void FIELD_MENU_HandleTouch(FieldMenu *menu);
void FIELD_MENU_PlaceCursor(FieldMenu *menu, s16 x, s16 y);
void FIELD_MENU_StartLeave(FieldMenu *menu, int back);
void FIELD_MENU_UpdateSelection(FieldMenu *menu);
void FIELD_MENU_CreateItem(FieldMenu *menu, FieldMenuItem *item, const FieldMenuItemInit *init);
void FIELD_MENU_DeleteItem(FieldMenu *menu, FieldMenuItem *item);
void FIELD_MENU_ShowItemWindow(FieldMenu *menu, FieldMenuItem *item);
void FIELD_MENU_LoadScreen(u32 heapId, u32 layer);
/* END mkheaders: generated region */

#endif
