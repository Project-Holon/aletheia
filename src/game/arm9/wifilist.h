#ifndef GAME_ARM9_WIFILIST_H
#define GAME_ARM9_WIFILIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifilist.c, prototypes copied from their definitions. */

struct WifiList;
struct WifiFriendInfo;
struct Strbuf;
struct U16Vec;
struct SaveControl;
struct MyStatus;

#include "../types.h"
#include "../arm9/wifilist_types.h"

u32 WIFILIST_GetWorkSize(void);
struct WifiList *WIFILIST_Create(int heapId);
void WIFILIST_Copy(const struct WifiList *src, struct WifiList *dest);
void WIFILIST_Init(struct WifiList *list);
struct WifiList *WIFILIST_GetWork(struct WifiList *list);
u32 WIFILIST_GetFriendInfoField(const struct WifiList *list, u32 index, u32 field);
void WIFILIST_SetFriendInfoField(struct WifiList *list, u32 index, u32 field, u32 value);
DWCFriendData *WIFILIST_GetDwcFriendData(struct WifiList *list, int index);
struct WifiFriendInfo *WIFILIST_GetFriendInfo(struct WifiList *list, int index);
void WIFILIST_CopyFriendNameToStrbuf(struct WifiList *list, int index, struct Strbuf *dest);
void WIFILIST_StoreFriendNameFromStrbuf(struct WifiList *list, int index, struct U16Vec *dest);
int WIFILIST_IsFriendDataValid(struct WifiList *list, u32 index);
u32 WIFILIST_CountFriends(struct WifiList *list);
u32 WIFILIST_GetFriendListEnd(struct WifiList *list);
void WIFILIST_RemoveFriendSlot(struct WifiList *list, u32 slot);
void WIFILIST_MoveFriendSlot(struct WifiList *list, u32 dest, u32 src);
void WIFILIST_CompactFriendList(struct WifiList *list);
void WIFILIST_SetFriendLastSeen(struct WifiList *list, int slot);
void WIFILIST_AddFriendBattleRecord(struct WifiList *list, int slot, int wins, int losses, int trades);
void WIFILIST_MergeFriendRecord(struct WifiList *list, int src, int dest);
void WIFILIST_CreateExchangeToken(void *userData, void *friendData);
void WIFILIST_MakeExchangeToken(struct WifiList *list, void *token);
int WIFILIST_GetGsProfileId(struct WifiList *list);
u32 WIFILIST_IsProfileValid(struct WifiList *list);
struct WifiList *WIFILIST_GetFromSave(struct SaveControl *save);
int WIFILIST_FindFriendByStatus(struct WifiList *list, struct MyStatus *status, u32 *outSlot);
int WIFILIST_FindFriendByStatusAndOutfit(struct WifiList *list, const void *name, u32 id, u32 outfitVariant, u32 *outSlot);
/* END mkheaders: generated region */

#endif
