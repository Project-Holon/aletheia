/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_0215444C
 * address:  0x021542C0
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0200AEE8  0x0200AEE8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02013160  0x02013160  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012950 0x02012950 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_02013128 0x02013128 thumb
 */
#include "event_wificlub_types.h"

struct Reg;
struct BattleSetup;
struct PlayerStatusList;
struct Link;
struct TrainerRecordInfo;
struct PlayerStatusRecord;
typedef signed int     s32;

/* View of the battle setup block: only the trainer record pointer at +0x6C is written here. */
typedef struct BattleSetupView {
    u8 reserved[0x6C];
    void *trainerRecord;
} BattleSetupView;

extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern void func_0200AEE8(struct Reg *regulation, u32 id, s32 value);
extern void *func_020399A8(void);
extern void func_02013790(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void func_020137C0(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void func_02013864(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void func_02013894(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void func_02013980(void *battleSetup, u32 heapArg);
extern void func_02013160(void *battleSetup, void *regulation, u32 a);
extern void func_0201A2A8(void *dst, void *src);
extern void *func_02012F2C(struct GameData *gameData);
u32 func_0203D1A4(struct Link *netHandle);
void *func_02012950(void *gameData, u32 index);
const void *func_020084F4(const void *p);
u8 func_02008550(const void *playerRecord);
void func_0201A948(void *party);
void func_02013128(void *battleSetup, void *party, int a);
void func_021542C0(WifiClubEventWork *work, int menuIndex);
void func_0215444C(WifiClubEventWork *work, void *gameData);
void func_021544BC(WifiClubEventWork *work);


void func_021542C0(WifiClubEventWork *work, int menuIndex)
{
    struct GameData *gameData;
    u8 useAltRule;
    int battleKind;

    gameData = func_020120F4(work->gameSystem);
    useAltRule = work->session->useAltRule;
    if (useAltRule)
        func_0200AEE8(work->session->regulation, 0xd, 1);
    else
        func_0200AEE8(work->session->regulation, 0xd, 0);

    switch (menuIndex) {
    case 8:
        battleKind = 1;
        if (useAltRule)
            battleKind = 3;
        break;
    case 7:
        battleKind = 0;
        if (useAltRule)
            battleKind = 2;
        break;
    case 10:
        battleKind = 5;
        if (useAltRule)
            battleKind = 7;
        break;
    case 9:
        battleKind = 4;
        if (useAltRule)
            battleKind = 6;
        break;
    case 12:
        battleKind = 9;
        if (useAltRule)
            battleKind = 0xb;
        break;
    case 11:
        battleKind = 8;
        if (useAltRule)
            battleKind = 0xa;
        break;
    case 14:
        battleKind = 0xd;
        if (useAltRule)
            battleKind = 0xf;
        break;
    case 13:
        battleKind = 0xc;
        if (useAltRule)
            battleKind = 0xe;
        break;
    }
    work->startParam.battleKind = battleKind;
    work->startParam.reserved = 0;

    switch (menuIndex) {
    case 7:
    case 8:
        func_02013790(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    case 9:
    case 10:
        func_020137C0(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    case 11:
    case 12:
        func_02013864(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    case 13:
    case 14:
        func_02013894(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    }
    func_02013980(work->battleSetup, 1);
    func_02013160(work->battleSetup, work->session->regulation, 4);
    func_0201A2A8(work->session->regulation, work->session->party[0]);
    func_0201A2A8(work->session->regulation, work->session->party[1]);
    ((BattleSetupView *)work->battleSetup)->trainerRecord = func_02012F2C(func_020120F4(work->gameSystem));
}


/*
 * size: 136
 *
 * The lead is 110 bytes, followed by two padding bytes and the 24-byte
 * func_021544BC thunk. function_starts: 0x021544BC.
 * func_020084F4 is the bx-lr identity: the original retains the pointer
 * returned by func_02012950 in r0 across two loads, passes it to the
 * identity, and stores the unchanged result. Its prior (void) extern
 * dropped the live input and caused an 18-byte scheduling residue.
 * func_0203D1A4 explicitly returns only eight bits; the caller consumes
 * those bits without truncation. Indexed record reads retain modular
 * unsigned address arithmetic without assuming an index domain.
 */
void func_0215444C(WifiClubEventWork *work, void *gameData)
{
    int selfSide, partnerSide;
    void *partnerRecord;
    ClubBattleEntry *entry;
    WifiClubSession *session;

    selfSide = func_0203D1A4(func_020399A8());
    partnerSide = 1 - selfSide;
    partnerRecord = func_02012950(gameData, partnerSide);
    work->battleEntry.regulation = work->session->regulation;
    entry = &work->battleEntry;
    entry->ownParty = *(void **)((unsigned int)work->session + 0x14 + 4 * (unsigned int)selfSide);
    entry->partnerInfo = (void *)func_020084F4(partnerRecord);
    entry->partnerGender = func_02008550(partnerRecord);
    entry->partnerParty = *(void **)((unsigned int)work->session + 0x14 + 4 * (unsigned int)partnerSide);
    entry->gameData = gameData;
    entry->reserved18 = 0;
    func_0201A948(work->battleParty);
    entry->battleParty = work->battleParty;
    entry->partyA = work->session->party[0];
    entry->partyB = work->session->party[1];
}


void func_021544BC(WifiClubEventWork *work)
{
    func_02013128(work->battleSetup, work->battleParty, 0);
}
