/*
 * file:     musical_event.c
 * unit:     yes
 * function: MUSICAL_EVENT_SetPartyLevel50, MUSICAL_EVENT_BuildParty, MUSICAL_EVENT_TrimPartyToThree, MUSICAL_EVENT_TrimAllPartiesToThree, MUSICAL_EVENT_UpdateFriendRecords, MUSICAL_EVENT_BindParticipantSlots
 * address:  0x02155160
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_SetLevelAndRecalc  0x02019CA0  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   BATTLE_BOX_CreateParty  0x0200BAF4  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   POKEPARTY_RemoveMember  0x0201A9C8  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIFILIST_FindFriendByStatus  0x02009D1C  thumb
 *   WIFILIST_AddFriendBattleRecord  0x02009BB8  thumb
 *   WIFILIST_SetFriendLastSeen  0x02009B80  thumb
 *   MUSICAL_EVENT_TwoPlayerPositionRemap     0x0216FED8  data  ov010  a1
 *   MUSICAL_EVENT_FourPlayerPositionRemap     0x0216FEDC  data  a1
 */
struct GameSystem;
struct GameData;
struct Party;
struct Pokemon;
struct NetHandle;
struct PlayerStatus;
struct WifiList;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

/* Entry data of the event; only the participant-mode byte is read here. */
struct MusicalEntryInfo {
    u8 pad00[0x22];
    u8 isFourPlayer;
};

/* One participant slot: the party list and the player status bound to it. */
struct MusicalParticipantSlot {
    void *partyList;
    struct PlayerStatus *playerStatus;
    u8 pad08[8];
};

/* Work block of the musical event (ctx of the event main sequence). */
struct MusicalEventWork {
    struct GameSystem *gameSystem;
    u8 pad04[0x34];
    struct Party *party;
    void *participantParties[4];
    void *saveControl;
    u8 pad50[0x28];
    u8 participantPosition[4];
    u8 pad7c[0x0c];
    struct MusicalEntryInfo *entryInfo;
    struct MusicalParticipantSlot slot[4];
    int battleResult;
};

typedef struct { u8 v[2]; } PositionRemap2;

typedef struct { u8 v[4]; } PositionRemap4;

extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern void POKE_TOOL_SetLevelAndRecalc(void *pokemon, u32 level);
extern void *BATTLE_BOX_GetFromSave(void *saveControl);
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern void *GAME_DATA_GetMyParty(const struct GameData *gameData);
extern u32 POKE_TOOL_GetPartyValue(void *pokemon, u32 paramId, u32 defaultValue);
extern u32 POKEPARTY_Add(struct Party *party, const struct Pokemon *pokemon);
extern void *BATTLE_BOX_CreateParty(int battleBox, int heapId);
extern void POKEPARTY_Copy(const struct Party *src, struct Party *dst);
extern u32 GFL_HEAP_Free(void *memory);
extern void POKE_TOOL_HealParty(void *party);
extern u32 POKEPARTY_RemoveMember(struct Party *party, s32 index);
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct NetHandle *handle);
extern struct PlayerStatus *GAME_DATA_GetPlayerStatus(struct GameData *gameData, u32 playerIndex);
extern struct WifiList *GAME_DATA_GetWifiList(const struct GameData *gameData);
extern int WIFILIST_FindFriendByStatus(struct WifiList *wifiList, struct PlayerStatus *playerStatus, u32 *outFriendSlot);
extern void WIFILIST_AddFriendBattleRecord(struct WifiList *wifiList, int friendSlot, int wins, int losses, int trades);
extern void WIFILIST_SetFriendLastSeen(struct WifiList *wifiList, int friendSlot);
void MUSICAL_EVENT_SetPartyLevel50(void *party);
void MUSICAL_EVENT_BuildParty(int partySource, struct MusicalEventWork *work);
void MUSICAL_EVENT_TrimPartyToThree(void *party);
void MUSICAL_EVENT_TrimAllPartiesToThree(struct MusicalEventWork *work);
void MUSICAL_EVENT_UpdateFriendRecords(struct MusicalEventWork *work, struct GameData *gameData);
void MUSICAL_EVENT_BindParticipantSlots(struct MusicalEventWork *work, struct GameSystem *gameSystem);
extern const PositionRemap2 MUSICAL_EVENT_TwoPlayerPositionRemap;
extern const PositionRemap4 MUSICAL_EVENT_FourPlayerPositionRemap;


/*
 * Sets every Pokemon of the party to level 50.
 */
void MUSICAL_EVENT_SetPartyLevel50(void *party)
{
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++)
        POKE_TOOL_SetLevelAndRecalc(POKEPARTY_GetMember(party, i), 50);
}


/*
 * Rebuilds the event party at +0x38: either from the player's own party
 * (partySource 0, skipping entries whose parameter 0x4c, the egg flag, is
 * set) or from the Battle Box, then heals it and sets it to level 50.
 * BATTLE_BOX_GetFromSave is a tail-calling wrapper whose result is
 * used here, so this unit declares it returning a value.
 */
void MUSICAL_EVENT_BuildParty(int partySource, struct MusicalEventWork *work)
{
    int battleBox;
    void *member;
    int i;
    void *ownParty;
    void *boxParty;
    battleBox = (int)BATTLE_BOX_GetFromSave(work->saveControl);
    if (partySource == 0) {
        ownParty = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(work->gameSystem));
        for (i = 0; i < (int)POKEPARTY_GetCount(ownParty); i++) {
            member = POKEPARTY_GetMember(ownParty, i);
            if (POKE_TOOL_GetPartyValue(member, 0x4c, 0) == 0)
                POKEPARTY_Add(work->party, member);
        }
    } else {
        boxParty = BATTLE_BOX_CreateParty(battleBox, 4);
        POKEPARTY_Copy(boxParty, work->party);
        GFL_HEAP_Free(boxParty);
    }
    POKE_TOOL_HealParty(work->party);
    MUSICAL_EVENT_SetPartyLevel50(work->party);
}


/*
 * Trims a party to its first three entries by removing entry 3 until only three remain.
 */
void MUSICAL_EVENT_TrimPartyToThree(void *party)
{
    int i;
    int count;

    count = POKEPARTY_GetCount(party);
    for (i = 3; i < count; i++)
        POKEPARTY_RemoveMember(party, 3);
}


/*
 * Trims the event party at +0x38 and the four participant parties at +0x3c to three entries each.
 */
void MUSICAL_EVENT_TrimAllPartiesToThree(struct MusicalEventWork *work)
{
    int i;

    MUSICAL_EVENT_TrimPartyToThree(work->party);
    for (i = 0; i < 4; i++)
        MUSICAL_EVENT_TrimPartyToThree(work->participantParties[i]);
}


/*
 * Updates the Wi-Fi friend list entries of the other participants after the
 * event: the partner slot only gets its last-played date refreshed; the
 * others get a win or a loss counted according to battleResult (0 win,
 * 1 loss, else date only).
 */
void MUSICAL_EVENT_UpdateFriendRecords(struct MusicalEventWork *work, struct GameData *gameData)
{
    int partnerSlot;
    int participantCount;
    int friendSlot;
    int i;
    int targetPosition;
    u32 localPosition;
    struct PlayerStatus *playerStatus;

    partnerSlot = 0;
    if (work->entryInfo->isFourPlayer == 0) {
        partnerSlot = partnerSlot - 1;
        participantCount = 2;
    } else {
        localPosition = work->participantPosition[GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())];
        if (localPosition < 2) {
            targetPosition = 1;
        } else {
            localPosition -= 2;
            targetPosition = 3;
        }
        targetPosition = targetPosition - localPosition;
        for (i = 0; i < 4; i++) {
            if (targetPosition == work->participantPosition[i]) {
                partnerSlot = i;
                break;
            }
        }
        participantCount = 4;
    }

    for (i = 0; i < participantCount; i++) {
        playerStatus = GAME_DATA_GetPlayerStatus(gameData, i);
        if (i != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) && playerStatus != 0
            && WIFILIST_FindFriendByStatus(GAME_DATA_GetWifiList(gameData), playerStatus, (u32 *)(&friendSlot)) != 0) {
            if (i == partnerSlot) {
                WIFILIST_SetFriendLastSeen(GAME_DATA_GetWifiList(gameData), friendSlot);
            } else if (work->battleResult == 0) {
                WIFILIST_AddFriendBattleRecord(GAME_DATA_GetWifiList(gameData), friendSlot, 1, 0, 0);
            } else if (work->battleResult == 1) {
                WIFILIST_AddFriendBattleRecord(GAME_DATA_GetWifiList(gameData), friendSlot, 0, 1, 0);
            } else {
                WIFILIST_SetFriendLastSeen(GAME_DATA_GetWifiList(gameData), friendSlot);
            }
        }
    }
}


/*
 * Binds each participant's party list (+0x3c) and player status into the
 * 16-byte slot records at +0x8c, indexed through the position byte at +0x78,
 * remapped through a small constant table when the local player is not
 * on the first side. The two tables are the unit's rodata copied into
 * locals ({1, 0} at 0x0216FED8, {2, 3, 0, 1} at 0x0216FEDC).
 *
 * The ABS32 to 0x0216FED8 resolves as sole-ref/data since
 * overlay_data_structure() ends each extent at its last instruction's real
 * length (TOWN_MAP_SPOT_CountVisited ends in the 2-byte pop at 0x0216FED6).
 */
void MUSICAL_EVENT_BindParticipantSlots(struct MusicalEventWork *work, struct GameSystem *gameSystem)
{
    PositionRemap4 remap4;
    PositionRemap2 remap2;
    int i;

    if (work->entryInfo->isFourPlayer != 0) {
        if (work->participantPosition[GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())] < 2) {
            for (i = 0; i < 4; i++) {
                work->slot[work->participantPosition[i]].partyList = work->participantParties[i];
                work->slot[work->participantPosition[i]].playerStatus = GAME_DATA_GetPlayerStatus(GAMESYSTEM_GetGameData(gameSystem), i);
            }
        } else {
            i = 0;
            remap4 = MUSICAL_EVENT_FourPlayerPositionRemap;
            for (; i < 4; i++) {
                work->slot[remap4.v[work->participantPosition[i]]].partyList = work->participantParties[i];
                work->slot[remap4.v[work->participantPosition[i]]].playerStatus = GAME_DATA_GetPlayerStatus(GAMESYSTEM_GetGameData(gameSystem), i);
            }
        }
    } else {
        if (GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) == 0) {
            for (i = 0; i < 2; i++) {
                work->slot[work->participantPosition[i]].partyList = work->participantParties[i];
                work->slot[work->participantPosition[i]].playerStatus = GAME_DATA_GetPlayerStatus(GAMESYSTEM_GetGameData(gameSystem), i);
            }
        } else {
            i = 0;
            remap2 = MUSICAL_EVENT_TwoPlayerPositionRemap;
            for (; i < 2; i++) {
                work->slot[remap2.v[work->participantPosition[i]]].partyList = work->participantParties[i];
                work->slot[remap2.v[work->participantPosition[i]]].playerStatus = GAME_DATA_GetPlayerStatus(GAMESYSTEM_GetGameData(gameSystem), i);
            }
        }
    }
}
