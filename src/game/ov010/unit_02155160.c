/*
 * file:     unit_02155160.c
 * unit:     yes
 * function: func_02155160, func_0215518C, func_02155200, func_02155224, func_02155244, func_02155328
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
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   func_0201A9C8  0x0201A9C8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D1C  0x02009D1C  thumb
 *   func_02009BB8  0x02009BB8  thumb
 *   func_02009B80  0x02009B80  thumb
 *   d_0216FED8     0x0216FED8  data  ov010  a1
 *   d_0216FEDC     0x0216FEDC  data  a1
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

extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *party, u32 index);
extern void func_02019CA0(void *pokemon, u32 level);
extern void *func_0200BAC8(void *saveControl);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern void *func_02012934(const struct GameData *gameData);
extern u32 func_02017E1C(void *pokemon, u32 paramId, u32 defaultValue);
extern u32 func_0201A98C(struct Party *party, const struct Pokemon *pokemon);
extern void *func_0200BAF4(int battleBox, int heapId);
extern void func_0201AC2C(const struct Party *src, struct Party *dst);
extern u32 func_020307B0(void *memory);
extern void POKE_TOOL_HealParty(void *party);
extern u32 func_0201A9C8(struct Party *party, s32 index);
extern struct NetHandle *func_020399A8(void);
extern u32 func_0203D1A4(struct NetHandle *handle);
extern struct PlayerStatus *func_02012950(struct GameData *gameData, u32 playerIndex);
extern struct WifiList *func_0201283C(const struct GameData *gameData);
extern int func_02009D1C(struct WifiList *wifiList, struct PlayerStatus *playerStatus, u32 *outFriendSlot);
extern void func_02009BB8(struct WifiList *wifiList, int friendSlot, int wins, int losses, int trades);
extern void func_02009B80(struct WifiList *wifiList, int friendSlot);
void func_02155160(void *party);
void func_0215518C(int partySource, struct MusicalEventWork *work);
void func_02155200(void *party);
void func_02155224(struct MusicalEventWork *work);
void func_02155244(struct MusicalEventWork *work, struct GameData *gameData);
void func_02155328(struct MusicalEventWork *work, struct GameSystem *gameSystem);
extern const PositionRemap2 d_0216FED8;
extern const PositionRemap4 d_0216FEDC;


/*
 * Sets every Pokemon of the party to level 50.
 */
void func_02155160(void *party)
{
    int i;

    for (i = 0; i < (int)func_0201AA18(party); i++)
        func_02019CA0(func_0201AB28(party, i), 50);
}


/*
 * Rebuilds the event party at +0x38: either from the player's own party
 * (partySource 0, skipping entries whose parameter 0x4c, the egg flag, is
 * set) or from the Battle Box, then heals it and sets it to level 50.
 * func_0200BAC8 is a tail-calling wrapper whose result is
 * used here, so this unit declares it returning a value.
 */
void func_0215518C(int partySource, struct MusicalEventWork *work)
{
    int battleBox;
    void *member;
    int i;
    void *ownParty;
    void *boxParty;
    battleBox = (int)func_0200BAC8(work->saveControl);
    if (partySource == 0) {
        ownParty = func_02012934(func_020120F4(work->gameSystem));
        for (i = 0; i < (int)func_0201AA18(ownParty); i++) {
            member = func_0201AB28(ownParty, i);
            if (func_02017E1C(member, 0x4c, 0) == 0)
                func_0201A98C(work->party, member);
        }
    } else {
        boxParty = func_0200BAF4(battleBox, 4);
        func_0201AC2C(boxParty, work->party);
        func_020307B0(boxParty);
    }
    POKE_TOOL_HealParty(work->party);
    func_02155160(work->party);
}


/*
 * Trims a party to its first three entries by removing entry 3 until only three remain.
 */
void func_02155200(void *party)
{
    int i;
    int count;

    count = func_0201AA18(party);
    for (i = 3; i < count; i++)
        func_0201A9C8(party, 3);
}


/*
 * Trims the event party at +0x38 and the four participant parties at +0x3c to three entries each.
 */
void func_02155224(struct MusicalEventWork *work)
{
    int i;

    func_02155200(work->party);
    for (i = 0; i < 4; i++)
        func_02155200(work->participantParties[i]);
}


/*
 * Updates the Wi-Fi friend list entries of the other participants after the
 * event: the partner slot only gets its last-played date refreshed; the
 * others get a win or a loss counted according to battleResult (0 win,
 * 1 loss, else date only).
 */
void func_02155244(struct MusicalEventWork *work, struct GameData *gameData)
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
        localPosition = work->participantPosition[func_0203D1A4(func_020399A8())];
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
        playerStatus = func_02012950(gameData, i);
        if (i != func_0203D1A4(func_020399A8()) && playerStatus != 0
            && func_02009D1C(func_0201283C(gameData), playerStatus, (u32 *)(&friendSlot)) != 0) {
            if (i == partnerSlot) {
                func_02009B80(func_0201283C(gameData), friendSlot);
            } else if (work->battleResult == 0) {
                func_02009BB8(func_0201283C(gameData), friendSlot, 1, 0, 0);
            } else if (work->battleResult == 1) {
                func_02009BB8(func_0201283C(gameData), friendSlot, 0, 1, 0);
            } else {
                func_02009B80(func_0201283C(gameData), friendSlot);
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
 * length (func_0216FEAC ends in the 2-byte pop at 0x0216FED6).
 */
void func_02155328(struct MusicalEventWork *work, struct GameSystem *gameSystem)
{
    PositionRemap4 remap4;
    PositionRemap2 remap2;
    int i;

    if (work->entryInfo->isFourPlayer != 0) {
        if (work->participantPosition[func_0203D1A4(func_020399A8())] < 2) {
            for (i = 0; i < 4; i++) {
                work->slot[work->participantPosition[i]].partyList = work->participantParties[i];
                work->slot[work->participantPosition[i]].playerStatus = func_02012950(func_020120F4(gameSystem), i);
            }
        } else {
            i = 0;
            remap4 = d_0216FEDC;
            for (; i < 4; i++) {
                work->slot[remap4.v[work->participantPosition[i]]].partyList = work->participantParties[i];
                work->slot[remap4.v[work->participantPosition[i]]].playerStatus = func_02012950(func_020120F4(gameSystem), i);
            }
        }
    } else {
        if (func_0203D1A4(func_020399A8()) == 0) {
            for (i = 0; i < 2; i++) {
                work->slot[work->participantPosition[i]].partyList = work->participantParties[i];
                work->slot[work->participantPosition[i]].playerStatus = func_02012950(func_020120F4(gameSystem), i);
            }
        } else {
            i = 0;
            remap2 = d_0216FED8;
            for (; i < 2; i++) {
                work->slot[remap2.v[work->participantPosition[i]]].partyList = work->participantParties[i];
                work->slot[remap2.v[work->participantPosition[i]]].playerStatus = func_02012950(func_020120F4(gameSystem), i);
            }
        }
    }
}
