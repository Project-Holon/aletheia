#ifndef GAME_OV021_PARTY_SELECT_LIST_H
#define GAME_OV021_PARTY_SELECT_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of party_select_list.c, prototypes copied from their definitions. */

struct PartySelectList;
struct BmpMenuList;
typedef struct PartySelectList PartySelectList;

#include "../types.h"

PartySelectList *PARTY_SELECT_LIST_Create(void *owner, void *firstParty, void *secondParty, u32 sideFlagFirst, u32 sideFlagSecond, u16 heapId);
u32 PARTY_SELECT_LIST_Delete(PartySelectList *list, u32 *outFlag);
int PARTY_SELECT_LIST_Main(PartySelectList *list);
u32 PARTY_SELECT_LIST_GetResult(PartySelectList *list, u32 *outFlag);
void PARTY_SELECT_LIST_LoadMonIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_FreeMonIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_CreateMonIcons(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteMonIcons(PartySelectList *list);
void PARTY_SELECT_LIST_SetMonIconsVisible(PartySelectList *list, int side);
void PARTY_SELECT_LIST_LoadStatusIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_FreeStatusIconResources(PartySelectList *list);
void PARTY_SELECT_LIST_CreateStatusIcons(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteStatusIcons(PartySelectList *list);
void PARTY_SELECT_LIST_SetStatusIconsVisible(PartySelectList *list, int side);
void PARTY_SELECT_LIST_InitMessageResources(PartySelectList *list);
int PARTY_SELECT_LIST_FreeMessageResources(PartySelectList *list);
void PARTY_SELECT_LIST_CreateMenu(PartySelectList *list);
void PARTY_SELECT_LIST_ProcessMenu(PartySelectList *list);
u32 PARTY_SELECT_LIST_GetMenuResult(PartySelectList *list);
void PARTY_SELECT_LIST_MenuMoveCallback(struct BmpMenuList *menu, u32 sel);
void PARTY_SELECT_LIST_MenuSelectCallback(struct BmpMenuList *menu, int k);
void PARTY_SELECT_LIST_CreateTextWindow(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteTextWindow(PartySelectList *list);
void PARTY_SELECT_LIST_PrintText(PartySelectList *list, u32 msgId);
int PARTY_SELECT_LIST_IsTextDone(PartySelectList *list);
void PARTY_SELECT_LIST_CreateListWindow(PartySelectList *list);
void PARTY_SELECT_LIST_DeleteListWindow(PartySelectList *list);
void PARTY_SELECT_LIST_PrintPartyNames(PartySelectList *list, void *party);
void PARTY_SELECT_LIST_ShowParty(PartySelectList *list, u32 sel);
void PARTY_SELECT_LIST_HideParty(PartySelectList *list);
/* END mkheaders: generated region */

#endif
