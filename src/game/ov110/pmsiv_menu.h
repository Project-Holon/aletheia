#ifndef GAME_OV110_PMSIV_MENU_H
#define GAME_OV110_PMSIV_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsiv_menu.c, prototypes copied from their definitions. */

struct PmsivMenu;
struct PmsInputView;
struct PmsInput;
struct PmsInputData;

#include "../types.h"

struct PmsivMenu *PMSIV_MENU_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
void PMSIV_MENU_Delete(struct PmsivMenu *menu);
void PMSIV_MENU_Update(struct PmsivMenu *menu);
void PMSIV_MENU_HideAll(struct PmsivMenu *menu);
void PMSIV_MENU_ShowEditEntries(struct PmsivMenu *menu);
void PMSIV_MENU_ShowWordEntries(struct PmsivMenu *menu);
void PMSIV_MENU_ShowOnlyBackButton(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateItemHighlight(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateEntryPalette(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateEntryPalettes(struct PmsivMenu *menu);
void PMSIV_MENU_PressEntry2(struct PmsivMenu *menu);
int PMSIV_MENU_IsEntry2Done(struct PmsivMenu *menu);
void PMSIV_MENU_PressBackItem(struct PmsivMenu *menu);
int PMSIV_MENU_IsBackItemDone(struct PmsivMenu *menu);
void PMSIV_MENU_FinishBackItem(struct PmsivMenu *menu);
void PMSIV_MENU_PressEntry1(struct PmsivMenu *menu);
int PMSIV_MENU_IsEntry1Done(struct PmsivMenu *menu);
void PMSIV_MENU_PressEntry0(struct PmsivMenu *menu);
int PMSIV_MENU_IsEntry0Done(struct PmsivMenu *menu);
void PMSIV_MENU_StartPress(struct PmsivMenu *menu, u32 mode);
void PMSIV_MENU_SelectItem(struct PmsivMenu *menu, int mode);
int PMSIV_MENU_IsPressDone(struct PmsivMenu *menu, u32 mode);
void PMSIV_MENU_FinishPress(struct PmsivMenu *menu, int i);
void PMSIV_MENU_SetActiveEntry(struct PmsivMenu *menu, int n, int v);
void PMSIV_MENU_SetDecideEntry(struct PmsivMenu *menu, u32 index, int value);
u32 PMSIV_MENU_IsEntryFinished(struct PmsivMenu *menu, u32 index);
int PMSIV_MENU_PressBackButton(struct PmsivMenu *menu);
int PMSIV_MENU_IsBackButtonDone(struct PmsivMenu *menu);
void PMSIV_MENU_CreateItems(struct PmsivMenu *menu);
void PMSIV_MENU_DeleteItems(struct PmsivMenu *menu);
void PMSIV_MENU_SetItemAnim(struct PmsivMenu *menu,int i,int flag);
void PMSIV_MENU_CreateExtraItems(struct PmsivMenu *menu);
void PMSIV_MENU_DeleteExtraItems(struct PmsivMenu *menu);
void PMSIV_MENU_CreateBackButton(struct PmsivMenu *menu);
void PMSIV_MENU_ShowBackButton(struct PmsivMenu *menu);
void PMSIV_MENU_ShowListEntries(struct PmsivMenu *menu);
void PMSIV_MENU_LoadBlendColors(struct PmsivMenu *menu);
void PMSIV_MENU_Reserved(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateBlend(struct PmsivMenu *menu);
void PMSIV_MENU_StartItemBlend(struct PmsivMenu *menu,int i);
void PMSIV_MENU_StopItemBlend(struct PmsivMenu *menu,int i);
/* END mkheaders: generated region */

#endif
