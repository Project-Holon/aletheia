/*
 * file:     irc_battle_task.c
 * unit:     yes
 * function: IRC_BATTLE_TASK_Main, IRC_BATTLE_TASK_Create, IRC_BATTLE_TASK_SetFormationOnce, IRC_BATTLE_TASK_Empty0, IRC_BATTLE_TASK_Empty1, IRC_BATTLE_TASK_Empty2, IRC_BATTLE_TASK_Empty3
 * address:  0x0215739C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_program.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_SetupCommMulti  0x020137F0  thumb
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_REC_SAVE_Start  0x021550A0  thumb  ov008
 *   ov008_id       0x00000008  data
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 */
#include "../arm9/btl_setup_types.h"
#include "event_ircbattle_shared_types.h"

/* Slot description handed to the battle recorder (0x50 bytes). */
typedef struct IrcBattleSlotInfo {
    u8 data[0x48];
    int formation;                      /* 0x48 */
    int flag;                           /* 0x4C */
} IrcBattleSlotInfo;

typedef struct IrcBattleRequest {
    void *party;                        /* 0x00 */
    u8 pad04[0xC];
    u16 bgmBattle;                      /* 0x10 */
    u8 multiTeam;                       /* 0x12 */
    u8 pad13;
    void *regulation;                   /* 0x14 */
    IrcBattleSlotInfo slot;             /* 0x18 */
} IrcBattleRequest;

/* Work of the IR battle task (0xFC bytes). */
typedef struct IrcBattleTaskWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    struct BattleSetupParam setup;      /* 0x08 */
    IrcBattleSlotInfo *slot;            /* 0xF8 */
} IrcBattleTaskWork;
struct GameEvent;

struct GameSystem;
struct GameData;

#include "../arm9/gamesystem.h"
struct GFLNetHandle;

#include "../arm9/net_handle.h"

#include "../arm9/btl_setup.h"




struct Party;




#include "../arm9/field_status.h"
struct FieldMap;

#include "../ov021/event_fieldmap_control.h"

#include "../ov008/event_battle_rec_save.h"



#include "../arm9/field_sound_system.h"



struct Regulation;


#include "../arm9/gf_panic.h"
#include "../arm9/game_event.h"

/* Overlay ids (absolute linker symbols) and data of other overlays. */
extern u8 ov008_id[];

extern u8 d_0217277C[];

int IRC_BATTLE_TASK_Main(struct GameEvent *event, int *state, void *work);

struct GameEvent *IRC_BATTLE_TASK_Create(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request);

void IRC_BATTLE_TASK_SetFormationOnce(int *formation, int value);

void IRC_BATTLE_TASK_Empty0(void);

void IRC_BATTLE_TASK_Empty1(void);

void IRC_BATTLE_TASK_Empty2(void);

void IRC_BATTLE_TASK_Empty3(void);

/*
 * Task callback of the IR battle task: a 10-state sequence that closes the
 * field, runs the battle (the ov008 runner gets the setup, the slot record
 * and a zero word) and returns 1 when done.
 */
int IRC_BATTLE_TASK_Main(struct GameEvent *event, int *state, void *workPtr)
{
    IrcBattleTaskWork *work = workPtr;
    void *gameSys = work->gameSys;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSys, work->setup.bgmBattle));
        (*state)++;
        break;
    case 4: {
        BattleRecSaveArgs args;

        args.setup = &work->setup;
        args.slotData = work->slot;
        args.flag = 0;
        GAME_EVENT_CallEvent(event, GAME_EVENT_CreateOverlayEvent(gameSys, (uptr)ov008_id, EVENT_BATTLE_REC_SAVE_Start, &args));
        (*state)++;
        break;
    }
    case 5:
        BTL_SETUP_FreeSlots(&work->setup);
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSys));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSys));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSys, work->gameData, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSys));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}

/*
 * Creates the IR battle task: allocates it with IRC_BATTLE_TASK_Main as its
 * callback, picks the formation slot for battle kinds 4..23 (four kinds per
 * rule, the first matching case wins through IRC_BATTLE_TASK_SetFormationOnce), runs the
 * matching setup builder and returns the event.
 */
struct GameEvent *IRC_BATTLE_TASK_Create(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request)
{
    int formation = 0x29;
    struct GameEvent *event = GAME_EVENT_Create(gameSys, 0, IRC_BATTLE_TASK_Main, sizeof(IrcBattleTaskWork));
    IrcBattleTaskWork *work = GAME_EVENT_GetWork(event);
    struct BattleSetupParam *setup;
    void *sysData;

    work->gameSys = gameSys;
    work->gameData = gameData;
    work->slot = &request->slot;
    setup = &work->setup;
    switch (kind) {
    case 5:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 0);
    case 4:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 2);
    case 7:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 1);
    case 6:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 3);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommSingle(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 9:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 4);
    case 8:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 6);
    case 11:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 5);
    case 10:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 7);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommDouble(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 13:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 8);
    case 12:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 10);
    case 15:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 9);
    case 14:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 11);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommTriple(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 17:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 12);
    case 16:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 14);
    case 19:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 13);
    case 18:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 15);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommRotation(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 21:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 16);
    case 20:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 18);
    case 23:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 17);
    case 22:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 19);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommMulti(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, request->multiTeam, 4);
        break;
    default:
        GF_PANIC_Fail((const char *)d_0217277C, 0, (const char *)d_0217277C);
        return 0;
    }
    BTL_SETUP_SetParty(setup, request->party, 0);
    BTL_SETUP_ApplyRegulation(setup, request->regulation, 4);
    setup->bgmBattle = request->bgmBattle;
    work->slot->formation = formation;
    work->slot->flag = 0;
    BTL_SETUP_AllocRecordBuffer(setup, 1);
    return event;
}

/*
 * Stores value into *formation only while it still holds the unset
 * sentinel 0x29, so the first call wins.
 */
void IRC_BATTLE_TASK_SetFormationOnce(int *formation, int value)
{
    if (*formation == 0x29)
        *formation = value;
}

/* Four empty leaves (unused callback slots). */
void IRC_BATTLE_TASK_Empty0(void)
{
}

void IRC_BATTLE_TASK_Empty1(void)
{
}

void IRC_BATTLE_TASK_Empty2(void)
{
}

void IRC_BATTLE_TASK_Empty3(void)
{
}
