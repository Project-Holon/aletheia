/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, EVENT_WIFICLUB_BuildBattleEntry
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
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012950 0x02012950 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   BTL_SETUP_SetParty 0x02013128 thumb
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
extern void BTL_SETUP_SetupCommSingle(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void BTL_SETUP_SetupCommDouble(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void BTL_SETUP_SetupCommTriple(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void BTL_SETUP_SetupCommRotation(void *battleSetup, struct GameData *gameData, void *netHandle, u32 a, u16 b);
extern void BTL_SETUP_AllocRecordBuffer(void *battleSetup, u32 heapArg);
extern void BTL_SETUP_ApplyRegulation(void *battleSetup, void *regulation, u32 a);
extern void func_0201A2A8(void *dst, void *src);
extern void *func_02012F2C(struct GameData *gameData);
u32 func_0203D1A4(struct Link *netHandle);
void *func_02012950(void *gameData, u32 index);
const void *func_020084F4(const void *p);
u8 func_02008550(const void *playerRecord);
void POKEPARTY_Init(void *party);
void BTL_SETUP_SetParty(void *battleSetup, void *party, int a);
void func_021542C0(WifiClubEventWork *work, int menuIndex);
void EVENT_WIFICLUB_BuildBattleEntry(WifiClubEventWork *work, void *gameData);
void EVENT_WIFICLUB_SetBattleParty(WifiClubEventWork *work);


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
        BTL_SETUP_SetupCommSingle(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    case 9:
    case 10:
        BTL_SETUP_SetupCommDouble(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    case 11:
    case 12:
        BTL_SETUP_SetupCommTriple(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    case 13:
    case 14:
        BTL_SETUP_SetupCommRotation(work->battleSetup, gameData, func_020399A8(), 1, 4);
        break;
    }
    BTL_SETUP_AllocRecordBuffer(work->battleSetup, 1);
    BTL_SETUP_ApplyRegulation(work->battleSetup, work->session->regulation, 4);
    func_0201A2A8(work->session->regulation, work->session->party[0]);
    func_0201A2A8(work->session->regulation, work->session->party[1]);
    ((BattleSetupView *)work->battleSetup)->trainerRecord = func_02012F2C(func_020120F4(work->gameSystem));
}


/*
 * size: 136
 *
 * The lead is 110 bytes, followed by two padding bytes and the 24-byte
 * EVENT_WIFICLUB_SetBattleParty thunk. function_starts: 0x021544BC.
 * func_020084F4 is the bx-lr identity: the original retains the pointer
 * returned by func_02012950 in r0 across two loads, passes it to the
 * identity, and stores the unchanged result. Its prior (void) extern
 * dropped the live input and caused an 18-byte scheduling residue.
 * func_0203D1A4 explicitly returns only eight bits; the caller consumes
 * those bits without truncation. Indexed record reads retain modular
 * unsigned address arithmetic without assuming an index domain.
 */
void EVENT_WIFICLUB_BuildBattleEntry(WifiClubEventWork *work, void *gameData)
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
    POKEPARTY_Init(work->battleParty);
    entry->battleParty = work->battleParty;
    entry->partyA = work->session->party[0];
    entry->partyB = work->session->party[1];
}


void EVENT_WIFICLUB_SetBattleParty(WifiClubEventWork *work)
{
    BTL_SETUP_SetParty(work->battleSetup, work->battleParty, 0);
}
