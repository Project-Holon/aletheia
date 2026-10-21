#ifndef GAME_OV091_PLIST_MENU_H
#define GAME_OV091_PLIST_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of plist_menu.c, prototypes copied from their definitions. */

struct Strbuf;
struct PokelistWork;

#include "../ov091/plist_menu_types.h"
#include "../ov091/pokelist_types.h"
#include "../types.h"

PlistMenu *PLIST_MENU_Create(PokelistWork *work);
void PLIST_MENU_Delete(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_Open(PokelistWork *work, PlistMenu *menu, int *items);
void PLIST_MENU_OpenFixed(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_Close(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_Update(PokelistWork *work, PlistMenu *menu);
unsigned int PLIST_MENU_GetSelectedCommand(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_BuildCommandList(PokelistWork *work, PlistMenu *menu, int *items);
struct Strbuf *PLIST_MENU_CreateCommandLabel(PokelistWork *work, PlistMenu *menu, int id);
void *PLIST_MENU_CreateButtonWindow(PokelistWork *work, struct PlistMenu *unused, int id, int x, u8 y, int disabled);
void PLIST_MENU_DeleteTaskMenuWin(void *win);
void PLIST_MENU_UpdateTaskMenuWin(void *win);
void PLIST_MENU_SetTaskMenuWinActive(void *win, int active);
void PLIST_MENU_ButtonWinSetDecide(void *win, int value);
int PLIST_MENU_GetItemUseKind(int itemId);
int PLIST_MENU_IsSpecialItemKind(PokelistWork *work, int itemId);
int PLIST_MENU_ItemRestoresHp(PokelistWork *work, u32 itemId);
int PLIST_MENU_FindItemTarget(PokelistWork *work);
int PLIST_MENU_GetItemUseMessage(PokelistWork *work, int itemId);
void PLIST_MENU_ApplyArceusPlateForm(void *unused, void *mon, int itemId);
void PLIST_MENU_ApplyGenesectDriveForm(struct PokelistWork *unused, void *mon, int itemId);
void PLIST_MENU_ShowItemUsedThenClose(PokelistWork *work);
void PLIST_MENU_ShowItemUsedThenContinue(PokelistWork *work);
int PLIST_MENU_StartItemUse(PokelistWork *work, int v);
void PLIST_MENU_ShowHpRestored(PokelistWork *work);
void PLIST_MENU_ShowItemResult(PokelistWork *work);
void PLIST_MENU_UseItemOnFoundTarget(PokelistWork *work);
void PLIST_MENU_BeginLevelUpMoveWait(PokelistWork *work);
void PLIST_MENU_BeginExitWait(PokelistWork *work);
void PLIST_MENU_UpdateLevelUp(PokelistWork *work);
int PLIST_MENU_HasMonParam(void *mon, int param, int unused);
void PLIST_MENU_ShowMonMessage(PokelistWork *work, int msgId);
void PLIST_MENU_ShowMonValueMessage(PokelistWork *work, int msgId, int value);
void PLIST_MENU_InitTimer(PokelistWork *work);
void PLIST_MENU_ExitTimer(PokelistWork *work);
void PLIST_MENU_UpdateTimer(PokelistWork *work);
void PLIST_MENU_CreateBank(PokelistWork *work);
void PLIST_MENU_DeleteBank(PokelistWork *work);
void PLIST_MENU_LoadResources(PokelistWork *work);
void PLIST_MENU_Nop(PokelistWork *work);
/* END mkheaders: generated region */

#endif
