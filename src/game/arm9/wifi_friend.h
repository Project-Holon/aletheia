#ifndef GAME_ARM9_WIFI_FRIEND_H
#define GAME_ARM9_WIFI_FRIEND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifi_friend.c, prototypes copied from their definitions. */

#include "../types.h"

int GFL_NET_ERR_PollNetState(void);
int GFL_NET_IsWifiGameKind(void);
int WIFILIST_CompareFriendData(void *candidate, void *userData, void *existing);
int WIFILIST_SearchFriendSlot(void *friendData, int *outSlot);
int WIFILIST_FindFriendByKey(void *saveBlock, u64 friendKey, int *outSlot);
int WIFILIST_UpdateFriendRecord(void *friendData);
void WIFILIST_StoreFriendProfile(void *saveBlock, void *profile, int slot, int heapId, int copyName);
void WIFILIST_StoreFriendRecord(void *saveData, void *profile, void *friendData, int slot, void *heapId, int mode);
int WIFILIST_InsertFriend(void *saveData, void *profile, void *friendData, void *heapId);
/* END mkheaders: generated region */

#endif
