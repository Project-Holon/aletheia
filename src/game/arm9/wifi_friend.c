/*
 * file:     wifi_friend.c
 * unit:     yes
 * function: GFL_NET_ERR_PollNetState, GFL_NET_IsWifiGameKind, WIFILIST_CompareFriendData, WIFILIST_SearchFriendSlot, WIFILIST_FindFriendByKey, WIFILIST_UpdateFriendRecord, WIFILIST_StoreFriendProfile, WIFILIST_StoreFriendRecord, WIFILIST_InsertFriend
 * address:  0x0200F2D4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from net_err.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_GetGameKind  0x0203D5D4  arm
 *   DWC_IsEqualFriendData  0x02059A5C  arm
 *   GFL_NET_GetWifiUserData   0x0203D5EC  arm
 *   GFL_NET_GetFriendList   0x0203D610  arm
 *   GFL_NET_GetFriendListNum   0x0203D634  arm
 *   WIFILIST_GetWork           0x02009860  thumb
 *   WIFILIST_GetDwcFriendData            0x020099C8  thumb
 *   WIFILIST_CountFriends           0x02009A34  thumb
 *   DWC_CheckFriendKey      0x02059354  arm
 *   DWC_CreateFriendKeyToken 0x02059980 arm
 *   DWC_GetGsProfileId      0x020598EC  arm
 *   DWC_IsValidFriendData   0x020596D8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MYSTATUS_CreateNameStrbuf   0x02008510  thumb
 *   MYSTATUS_GetId   0x02008530  thumb
 *   MYSTATUS_GetProfileId   0x0200853C  thumb
 *   MYSTATUS_GetSex   0x02008550  thumb
 *   MYSTATUS_GetTrainerView   0x02008554  thumb
 *   WIFILIST_SetFriendInfoField   0x02009918  thumb
 *   WIFILIST_StoreFriendNameFromStrbuf   0x02009A00  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetWifiList   0x0201283C  thumb
 *   WIFILIST_IsFriendDataValid           0x02009A1C  thumb
 *   sWifiPollLatch    0x02146178  data
 *   GFL_NET_Main  0x0203CF5C  arm
 */
#include "wifi_friend_shared_types.h"

struct DWCstAccUserData;

struct WifiFriendSave;

struct WifiFriendRecord;

struct PlayerProfileSrc;

struct SaveData;

#include "../types.h"

#include "wifilist_types.h"

#ifdef __MWERKS__
extern int GFL_NET_GetGameKind(void); /* original prototype; the definition differs in return type */
extern void *GFL_NET_GetWifiUserData(void);
extern void *GFL_NET_GetFriendList(void);
extern u32 GFL_NET_GetFriendListNum(void);
#else
#include "net.h"
#endif

#include "dwc_account.h"


struct WifiList;

#include "wifilist.h"






#include "mi_memory.h"
struct Strbuf;

#include "mystatus.h"
struct MyStatus;





struct U16Vec;


#include "strbuf.h"
struct GameData;
struct FieldState;

#include "game_data.h"


#ifdef __MWERKS__
extern u32 GFL_NET_Main(); /* original prototype; the DS passes an argument the definition does not take */
#endif

int GFL_NET_ERR_PollNetState(void);

int GFL_NET_IsWifiGameKind(void);

int WIFILIST_CompareFriendData(void *candidate, void *userData, void *existing);

int WIFILIST_SearchFriendSlot(void *friendData, int *outSlot);

int WIFILIST_FindFriendByKey(void *saveBlock, u64 friendKey, int *outSlot);

int WIFILIST_UpdateFriendRecord(void *friendData);

void WIFILIST_StoreFriendProfile(void *saveBlock, void *profile, int slot, int heapId, int copyName);

void WIFILIST_StoreFriendRecord(void *saveData, void *profile, void *friendData, int slot, int heapId, int mode);

int WIFILIST_InsertFriend(void *saveData, void *profile, void *friendData, u32 heapId);

extern unsigned char sWifiPollLatch;

/* Wi-Fi state poll with a one-shot latch: state 2 toggles the latch (the first
 * call passes it to GFL_NET_Main, the next one clears it). */
int GFL_NET_ERR_PollNetState(void)
{
    int linkState;
    int latched;
    int result;

    linkState = GFL_NET_GetGameKind();
    if ((unsigned int)linkState == (unsigned int)2) {
        if ((unsigned int)sWifiPollLatch == (unsigned int)0) {
            latched = GFL_NET_Main();
            sWifiPollLatch = (unsigned char)latched;
            return latched;
        } else {
            sWifiPollLatch = (unsigned char)0;
            return 0;
        }
    } else {
        result = GFL_NET_Main();
        return result;
    }
}

/*
 * Membership test on GFL_NET_GetGameKind()'s result: true for a scattered set of
 * values (12-16, 28, 31, 37, 38, 48), false otherwise. The 12-16 run is
 * lowered as a dense jump table. GFL_NET_GetGameKind must return a signed int: an
 * unsigned return type turns the range tests into unsigned compares.
 */
int GFL_NET_IsWifiGameKind(void)
{
    switch (GFL_NET_GetGameKind()) {
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 28:
    case 31:
    case 37:
    case 38:
    case 48:
        return 1;
    default:
        return 0;
    }
}

/*
 * Three-way friend comparison: returns 0 when candidate and existing are the
 * same friend (DWC_IsEqualFriendData), 1 when the candidate has a profile id and it
 * matches the one the existing record resolves to, 2 otherwise. The profile id
 * of the candidate is fetched twice, as in the original.
 */
int WIFILIST_CompareFriendData(void *candidate, void *userData, void *existing)
{
    if (DWC_IsEqualFriendData(candidate, existing) != 0) {
        return 0;
    }

    if (DWC_GetGsProfileId(userData, candidate) > 0) {
        int candidateProfileId = DWC_GetGsProfileId(userData, candidate);
        int existingProfileId = DWC_GetGsProfileId(userData, existing);
        if (candidateProfileId == existingProfileId) {
            return 1;
        }
    }
    return 2;
}

/*
 * Search the friend list for a slot for friendData; outSlot starts at -1.
 * Returns 3 when friendData is not valid, 0 when a record is the same friend
 * (outSlot = that slot), 1 when a record has the same profile id (outSlot =
 * that slot), 2 when the scan finishes. An invalid (free) record seen on the
 * way is kept in outSlot as the fallback.
 */
int WIFILIST_SearchFriendSlot(void *friendData, int *outSlot)
{
    int   i;
    void *userData = GFL_NET_GetWifiUserData();
    u8   *friendList = GFL_NET_GetFriendList();
    int   friendCount = GFL_NET_GetFriendListNum();

    *outSlot = -1;
    if (DWC_IsValidFriendData(friendData) == 0)
        return 3;
    for (i = 0; i < friendCount; i++) {
        int byteOffset = i * 12;

        if (DWC_IsEqualFriendData(friendData, friendList + byteOffset) != 0) {
            *outSlot = i;
            return 0;
        }
        if (DWC_GetGsProfileId(userData, friendData) > 0
            && DWC_GetGsProfileId(userData, friendData) == DWC_GetGsProfileId(userData, friendList + byteOffset)) {
            *outSlot = i;
            return 1;
        }
        if (*outSlot < 0 && DWC_IsValidFriendData(friendList + byteOffset) == 0)
            *outSlot = i;
    }
    return 2;
}

/*
 * Friend-list lookup by friend key: build the key token and compare its
 * profile id with every entry of the friend list. Returns 3 when the key or
 * the token is bad, 0 on a hit (outSlot = slot), 2 when the list was walked
 * without a hit; then outSlot holds the first invalid (free) slot, or -1.
 * The key is one u64, and the list is typed as 12-byte records indexed as
 * friends[i], which fixes the register allocation.
 */
int WIFILIST_FindFriendByKey(void *saveBlock, u64 friendKey, int *outSlot)
{
    void *userData;
    DWCFriendData *friends;
    int friendCount;
    int i;
    DWCFriendData token;

    userData = WIFILIST_GetWork(saveBlock);
    i = 0;
    friends = (DWCFriendData *)WIFILIST_GetDwcFriendData(saveBlock, 0);
    friendCount = WIFILIST_CountFriends(saveBlock);

    if (DWC_CheckFriendKey(userData, friendKey) == 0)
        return 3;

    DWC_CreateFriendKeyToken(&token, friendKey);
    if (DWC_GetGsProfileId(userData, &token) <= 0)
        return 3;

    *outSlot = i - 1;
    for (; i < friendCount; i++) {
        if (DWC_GetGsProfileId(userData, &token) == DWC_GetGsProfileId(userData, &friends[i])) {
            *outSlot = i;
            return 0;
        }
        if (*outSlot < 0 && DWC_IsValidFriendData(&friends[i]) == 0)
            *outSlot = i;
    }
    return 2;
}

/*
 * Look friendData up in the friend list (WIFILIST_SearchFriendSlot). On a profile id match
 * (1) overwrite friendData with the stored record; returns 1 when the list was
 * walked without a hit (2), 0 otherwise.
 */
int WIFILIST_UpdateFriendRecord(void *friendData)
{
    u32 slot;
    int result = 0;
    void *friendList = GFL_NET_GetFriendList();
    int searchResult = WIFILIST_SearchFriendSlot(friendData, (int *)(&slot));

    if (searchResult == 0) {
        /* nothing */
    } else if (searchResult == 1) {
        MI_CpuCopy8(friendData, (unsigned char *)friendList + slot * 0xc, 0xc);
    } else if (searchResult == 2) {
        result = 1;
    }
    return result;
}

/* Copy the profile fields (and, with copyName, the name) of profile into friend record slot. */
void WIFILIST_StoreFriendProfile(void *saveBlock, void *profile, int slot, int heapId, int copyName)
{
    if (copyName != 0) {
        void *name = MYSTATUS_CreateNameStrbuf(profile, heapId);
        WIFILIST_StoreFriendNameFromStrbuf(saveBlock, slot, name);
        STRBUF_Delete(name);
    }
    WIFILIST_SetFriendInfoField(saveBlock, slot, 9, MYSTATUS_GetSex(profile));
    WIFILIST_SetFriendInfoField(saveBlock, slot, 0, MYSTATUS_GetId(profile));
    WIFILIST_SetFriendInfoField(saveBlock, slot, 1, MYSTATUS_GetProfileId(profile));
    WIFILIST_SetFriendInfoField(saveBlock, slot, 8, MYSTATUS_GetTrainerView(profile));
}

/*
 * Store profile into friend record slot. mode 0: copy the old record out to
 * friendData and write profile with its name; mode 1: same without the name;
 * mode 2: keep friendData untouched and write only the last field.
 */
void WIFILIST_StoreFriendRecord(void *saveData, void *profile, void *friendData, int slot, int heapId, int mode)
{
    void *saveBlock = (void *)GAME_DATA_GetWifiList(saveData);
    void *record = WIFILIST_GetDwcFriendData(saveBlock, slot);

    if (mode != 2) {
        MI_CpuCopy8(friendData, record, 0xc);
    }
    if (mode == 0) {
        WIFILIST_StoreFriendProfile(saveBlock, profile, slot, heapId, 1);
    } else if (mode == 1) {
        WIFILIST_StoreFriendProfile(saveBlock, profile, slot, heapId, 0);
    }
    WIFILIST_SetFriendInfoField(saveBlock, slot, 8, MYSTATUS_GetTrainerView(profile));
}

/*
 * Insert one friend into the 32-entry friend list. The mode passed to
 * WIFILIST_StoreFriendRecord is 0 for the first free slot, 2 when WIFILIST_CompareFriendData reports the
 * same friend and 1 when it reports a matching profile id. Only the free-slot
 * arm returns 1.
 */
int WIFILIST_InsertFriend(void *saveData, void *profile, void *friendData, u32 heapId)
{
    void *saveBlock = (void *)GAME_DATA_GetWifiList(saveData);
    int i;

    if (DWC_IsValidFriendData(friendData) == 0) {
        return 0;
    }

    for (i = 0; i < 0x20; i++) {
        void *record = WIFILIST_GetDwcFriendData(saveBlock, i);
        int mode;

        if (WIFILIST_IsFriendDataValid(saveBlock, i) == 0) {
            WIFILIST_StoreFriendRecord(saveData, profile, friendData, i, heapId, 0);
            return 1;
        }
        mode = WIFILIST_CompareFriendData(friendData, WIFILIST_GetWork(saveBlock), record);
        if (mode == 0) {
            WIFILIST_StoreFriendRecord(saveData, profile, friendData, i, heapId, 2);
            return 0;
        }
        if (mode == 1) {
            WIFILIST_StoreFriendRecord(saveData, profile, friendData, i, heapId, 1);
            return 0;
        }
    }
    return 0;
}
