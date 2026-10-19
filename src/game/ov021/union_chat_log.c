/*
 * file:     union_chat_log.c
 * unit:     yes
 * function: UNION_CHAT_LOG_Add, UNION_CHAT_LOG_TakeSlot, UNION_CHAT_LOG_GetLine, UNION_CHAT_LOG_IsNew
 * address:  0x021BBA70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from fieldmap_func.c at 021BBA70: the UNION_CHAT_LOG_ ring (union room chat log, data gUnionChatEmptyMac 0x021D9AE0 between the fldeff_gyoe.c data and the fldeff_footmark.c data). It shares no statics with the sub process manager before it and has no allocation; the cut rests on module prefix.
 *
 * symbols:
 *   GF_PANIC_Fail  0x02034714  arm
 *   MYSTATUS_CopyNameChars  0x020084F8  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   WORDSET_CopyString  0x0201F41C  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   UNION_CHARA_IsWifiFriendBeacon  0x0217F894  thumb  ov019
 *   MET_TRAINERS_Contains  0x0200EDC4  thumb
 *   gUnionChatEmptyMac     0x021D9AE0  data  a4
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../types.h"

#include "../sdk_fx.h"

#include "../ov012/union_comm_types.h"

/* ---- union chat log (union_comm_types.h UnionChatLog, ring part) ---- */

/* One line of the chat log (0x24 bytes), see UnionChatEntry. */
typedef struct UnionChatLine {
    u16 name[8];               /* 0x00 sender name */
    u16 chatPms[4];            /* 0x10 easy chat sentence */
    u16 chatCount;             /* 0x18 */
    u8 senderMac[6];           /* 0x1A */
    u8 sex;                    /* 0x20 */
    u8 chatType;               /* 0x21 */
    u8 relation;               /* 0x22 0 stranger, 1 wifi friend, 2 known trainer */
    u8 pad23;
} UnionChatLine;

/* UnionChatLog with the two slot counters kept in pad438. */
typedef struct UnionChatRing {
    UnionChatLine line[UNION_CHAT_LOG_MAX]; /* 0x000 */
    u8 startSlot;              /* 0x438 slot of the oldest line */
    u8 endSlot;                /* 0x439 slot the next line goes to */
    u8 pad43A[2];
    int newestIndex;           /* 0x43C absolute index of the newest line, -1 empty */
    int oldestIndex;           /* 0x440 absolute index of the oldest kept line */
} UnionChatRing;

extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

void MYSTATUS_CopyNameChars(u16 *src, u16 *dest, u32 n);
struct MyStatus;

u8 MYSTATUS_GetSex(struct MyStatus *mystatus);

void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

void OS_GetMacAddress(u8 *outMac);

void MI_CpuCopy8(const void *src, void *dst, int n);
struct GameSystem;
struct GameData;

struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
struct FieldState;

struct FieldState *GAME_DATA_GetWifiList(struct GameData *gameData);
struct SaveControl;

struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);

void *MET_TRAINERS_GetFromSave(void *saveControl);
struct UnionBeaconPc;

int UNION_CHARA_IsWifiFriendBeacon(void *wifiFriends, struct UnionBeaconPc *beaconPc);
struct MetTrainersSave;

int MET_TRAINERS_Contains(struct MetTrainersSave *list, u32 value);

extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

void UNION_CHAT_LOG_Add(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType);

UnionChatLine *UNION_CHAT_LOG_TakeSlot(UnionChatRing *ring);

UnionChatLine *UNION_CHAT_LOG_GetLine(UnionChatRing *ring, u32 index);

int UNION_CHAT_LOG_IsNew(UnionChatRing *ring, const void *mac, u16 chatCount);

extern char gUnionChatEmptyMac[];

/*
 * Adds one line to the chat log: from a received beacon, or (beaconPc zero)
 * from the own player with the sentence in chatPms.
 */
void UNION_CHAT_LOG_Add(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType)
{
    UnionChatRing *ring = (UnionChatRing *)&work->chatLog;
    UnionChatLine *line;
    void *myStatus;
    void *wifiList;
    void *saveControl;
    int relation;

    if (beaconPc == 0 && chatPms == 0) {
        GF_PANIC_Fail((const char *)0x021DE308, 0, (const char *)0x021DE308);
    }
    if (beaconPc != 0 && UNION_CHAT_LOG_IsNew(ring, beaconPc->mac, beaconPc->beacon.chatCount) == 0) {
        return;
    }
    line = UNION_CHAT_LOG_TakeSlot(ring);
    if (beaconPc == 0) {
        myStatus = work->parent->myStatus;
        MYSTATUS_CopyNameChars(myStatus, line->name, 8);
        /* the re-test of chatPms inside the chatPms == 0 arm is the dead second bne */
        if (chatPms == 0) {
            if (chatPms != 0 || chatType == 0) {
                GF_PANIC_Fail((const char *)0x021DE308, 0, (const char *)0x021DE308);
            }
        }
        line->chatPms[0] = chatPms[0];
        line->chatPms[1] = chatPms[1];
        line->chatPms[2] = chatPms[2];
        line->chatPms[3] = chatPms[3];
        line->chatType = chatType;
        line->chatCount = 0;
        OS_GetMacAddress(line->senderMac);
        line->sex = MYSTATUS_GetSex(myStatus);
        line->relation = 0;
    } else {
        WORDSET_CopyString(beaconPc->beacon.name, line->name, 8);
        line->chatPms[0] = beaconPc->beacon.chatPms.word[0];
        line->chatPms[1] = beaconPc->beacon.chatPms.word[1];
        line->chatPms[2] = beaconPc->beacon.chatPms.word[2];
        line->chatPms[3] = beaconPc->beacon.chatPms.word[3];
        line->chatType = beaconPc->beacon.chatType;
        line->chatCount = beaconPc->beacon.chatCount;
        MI_CpuCopy8(beaconPc->mac, line->senderMac, 6);
        line->sex = beaconPc->beacon.sex;
        saveControl = GAMESYSTEM_GetGameData(work->parent->gameSystem);
        wifiList = GAME_DATA_GetWifiList(saveControl);
        saveControl = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(saveControl));
        if (UNION_CHARA_IsWifiFriendBeacon(wifiList, (struct UnionBeaconPc *)(&beaconPc->beacon)) == 1) {
            relation = 1;
        } else if (MET_TRAINERS_Contains(saveControl, beaconPc->beacon.trainerId) == 1) {
            relation = 2;
        } else {
            relation = 0;
        }
        line->relation = relation;
    }
    if (ring->newestIndex == ring->oldestIndex) {
        ring->oldestIndex++;
    }
    ring->newestIndex++;
    if (ring->newestIndex - ring->oldestIndex >= 30) {
        ring->oldestIndex = ring->newestIndex - 29;
    }
}

/* Takes the slot for the next line, dropping the oldest line when full. */
UnionChatLine *UNION_CHAT_LOG_TakeSlot(UnionChatRing *ring)
{
    int slot;
    UnionChatLine *line;
    if (ring->newestIndex > 0) {
        slot = ring->endSlot;
        if (slot == ring->startSlot) {
            ring->startSlot += 1;
            if (ring->startSlot >= 30) ring->startSlot = 0;
        }
    }
    line = &ring->line[ring->endSlot];
    ring->endSlot += 1;
    if (ring->endSlot >= 30) ring->endSlot = 0;
    return line;
}

/* Returns the line with the given absolute index, or zero when it is empty. */
UnionChatLine *UNION_CHAT_LOG_GetLine(UnionChatRing *ring, u32 index)
{
    UnionChatLine *line = &ring->line[index % 30];

    if (GF_STANDARD_CompareBytes(line->senderMac, (const u8 *)gUnionChatEmptyMac, 6) == 0) {
        line = 0;
    }
    return line;
}

/*
 * Returns 0 when a kept line from this sender has this chat count already.
 * A u16 chatCount (not int/u32) is what stores its spill before mac's.
 */
int UNION_CHAT_LOG_IsNew(UnionChatRing *ring, const void *mac, u16 chatCount)
{
    int i;
    UnionChatLine *line;

    for (i = ring->newestIndex; i > ring->newestIndex - 30; i--) {
        if (i < 0) return 1;
        line = UNION_CHAT_LOG_GetLine(ring, i);
        if (line != 0 && GF_STANDARD_CompareBytes(line->senderMac, mac, 6) == 0) {
            if (line->chatCount != chatCount) return 1;
            return 0;
        }
    }
    return 1;
}
