/*
 * file:     scrcmd_sub_proc_events.c
 * unit:     yes
 * function: SCRCMD_CreateNameInEvent, SCRCMD_NameInEventMain, SCRCMD_CreateNicknameEvent, SCRCMD_NicknameEventMain, SCRCMD_CreateSubProcEvent, SCRCMD_SubProcEventMain
 * address:  0x021C5A28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_splash.c at 0x021C5A28 (lane FXC, CL129: script event helpers called by scrcmd_c03center.c and scrcmd_proc_fld.c; no home evidence, original unknown).
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   FIELD_STATUS_CreateSubProcNoFadeEvent  0x02014728  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   gNameInProcData     0x021F5580  data  ov194  a4
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   NAMEIN_SETUP_CreateArgs  0x0216BFD4  thumb  ov010
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   NAMEIN_SETUP_FreeArgs  0x0216C0C0  thumb  ov010
 *   ov171_id       0x000000AB  data  a1
 *   gSubProcTable    0x021DEA44  data  ov021  a1
 */
#include "../types.h"

#include "../ov010/namein_args.h"
#include "../arm9/poke_tool_param.h"

struct GameEvent;
struct GameSystem;
struct GameData;
struct SaveControl;
struct NameSave;
struct TrainerRecord;
struct Pokeparty;
struct PartyMon;

/* Work of the name entry event (0x10 bytes). */
typedef struct NameInEventWork {
    void *gameSystem;                     /* 0x00 */
    void *fieldMap;                       /* 0x04 */
    NameInArgs *nameIn;                  /* 0x08 */
    u32 mode;                             /* 0x0C: selects which proc starter runs */
} NameInEventWork;

/* Work of the nickname event (0x18 bytes). */
typedef struct NicknameEventWork {
    void *gameSystem;                     /* 0x00 */
    void *fieldMap;                       /* 0x04 */
    NameInArgs *nameIn;                  /* 0x08 */
    void *mon;                            /* 0x0C: the party member being named */
    u16 *result;                          /* 0x10: script result, 1 when a name was set */
    int mode;                             /* 0x14 */
} NicknameEventWork;

/* Parameter block of the generic sub proc (written back by the proc). */
typedef struct SubProcParam {
    void *gameData;                       /* 0x00 */
    u16 procId;                           /* 0x04 */
    u16 resultCode;                       /* 0x06: written by the proc */
} SubProcParam;

/* Work of the sub proc event (0x14 bytes). */
typedef struct SubProcEventWork {
    void *gameSystem;                     /* 0x00 */
    void *fieldMap;                       /* 0x04 */
    SubProcParam param;                   /* 0x08 */
    u16 *result;                          /* 0x10 */
} SubProcEventWork;

#include "../arm9/game_data.h"
#include "../arm9/game_event.h"
struct FieldMap;
#include "../arm9/field_status.h"
#include "../arm9/gamesystem.h"
struct Party;
#include "../arm9/pokeparty.h"
struct PokemonParam;
struct MiscSave;
#include "../arm9/beacon.h"
#include "../arm9/poke_tool.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define NAMEIN_SETUP_CreateArgs NAMEIN_SETUP_CreateArgs_header
#endif
#include "../ov010/namein_setup.h"
#ifdef __MWERKS__
#undef NAMEIN_SETUP_CreateArgs
extern NameInArgs * NAMEIN_SETUP_CreateArgs(int, int, int, int, int, Strbuf *, void *);
#endif
#include "../arm9/record.h"
struct NameInArgs;

void *SCRCMD_CreateNameInEvent(void *gameSystem, void *fieldMap, NameInArgs *nameIn, u32 mode);
int SCRCMD_NameInEventMain(struct GameEvent *event, int *state, void *work);
struct GameEvent *SCRCMD_CreateNicknameEvent(void *gameSystem, u16 *result, int partyIndex, int mode);
int SCRCMD_NicknameEventMain(struct GameEvent *event, int *state, NicknameEventWork *work);
void *SCRCMD_CreateSubProcEvent(void *gameSystem, u32 procId, u16 *result);
int SCRCMD_SubProcEventMain(struct GameEvent *event, int *state, void *work);

/* Name entry proc table (ov194, proc id 0xC2) and the sub proc table of ov171. */
extern char gNameInProcData;
extern unsigned char abs_id_C2[];
extern char gSubProcTable[];
extern char ov171_id[];

/*
 * Spawns the SCRCMD_NameInEventMain task with a four-word work area.
 */
void *SCRCMD_CreateNameInEvent(void *gameSystem, void *fieldMap, NameInArgs *nameIn, u32 mode)
{
    void *task = GAME_EVENT_Create(gameSystem, 0, SCRCMD_NameInEventMain, sizeof(NameInEventWork));
    NameInEventWork *work = GAME_EVENT_GetWork(task);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->nameIn = nameIn;
    work->mode = mode;
    return task;
}

/*
 * Event: starts the name entry proc (overlay 0xC2, table gNameInProcData in
 * ov194), with a fade unless mode is 0, and ends when it returns.
 */
int SCRCMD_NameInEventMain(struct GameEvent *event, int *state, void *workPtr)
{
    NameInEventWork *work = workPtr;
    sptr childEvent;

    switch (*state) {
    case 0:
        if (work->mode != 0) {
            childEvent = (sptr)FIELD_STATUS_CreateSubProcEvent((struct GameSystem *)work->gameSystem, (struct FieldMap *)work->fieldMap, (sptr)abs_id_C2, (void *)(&gNameInProcData), (void *)work->nameIn);
        } else {
            childEvent = (sptr)FIELD_STATUS_CreateSubProcNoFadeEvent((struct GameSystem *)work->gameSystem, (struct FieldMap *)work->fieldMap, (sptr)abs_id_C2, (void *)(&gNameInProcData), (void *)work->nameIn);
        }
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)childEvent);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

/* Creates the nickname event for a party member; returns the event. */
struct GameEvent *SCRCMD_CreateNicknameEvent(void *gameSystem, u16 *result, int partyIndex, int mode)
{
    struct GameEvent *event;
    NicknameEventWork *work;
    void *mon;
    void *gameData;
    void *nameSave;
    int species;
    int traits;

    if ((int)POKEPARTY_GetCount(GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(gameSystem))) <= partyIndex) {
        partyIndex = 0;
    }
    event = GAME_EVENT_Create(gameSystem, 0, (void *)SCRCMD_NicknameEventMain, sizeof(NicknameEventWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work->result = result;
    work->mode = mode;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex);
    nameSave = MISC_GetBlock(GAME_DATA_GetSaveControl(gameData));
    species = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_SPECIES, 0);
    traits = POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_FORM, 0) | (POKE_TOOL_GetPartyValue(mon, POKE_TOOL_PARAM_GENDER, 0) << 8);
    work->nameIn = (NameInArgs *)NAMEIN_SETUP_CreateArgs(4, 1, species, traits, 0xa, 0, nameSave);
    work->mon = mon;
    return event;
}

/* Event: runs the name entry, stores the nickname unless cancelled, sets the script result. */
int SCRCMD_NicknameEventMain(struct GameEvent *event, int *state, NicknameEventWork *work)
{
    NameInArgs *nameIn;
    int confirmed;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, SCRCMD_CreateNameInEvent(work->gameSystem, work->fieldMap, work->nameIn, work->mode));
        (*state)++;
        break;
    case 1:
        nameIn = work->nameIn;
        if (nameIn->canceled != 1) {
            POKE_TOOL_SetPartyValue(work->mon, POKE_TOOL_PARAM_NICKNAME_STRBUF, (uptr)nameIn->name);
        }
        confirmed = 1;
        if (work->nameIn->canceled == 1) {
            confirmed = 0;
        }
        *work->result = confirmed;
        if (*work->result == 1) {
            RECORD_AddOne(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(work->gameSystem)), 0x1e);
        }
        NAMEIN_SETUP_FreeArgs((struct NameInArgs *)work->nameIn);
        return 1;
    }
    return 0;
}

/*
 * Spawns the SCRCMD_SubProcEventMain task with a 0x14-byte work area.
 */
void *SCRCMD_CreateSubProcEvent(void *gameSystem, u32 procId, u16 *result)
{
    void *task = GAME_EVENT_Create(gameSystem, 0, SCRCMD_SubProcEventMain, sizeof(SubProcEventWork));
    SubProcEventWork *work = GAME_EVENT_GetWork(task);
    work->gameSystem = gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work->result = result;
    work->param.gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->param.procId = procId;
    return task;
}

/*
 * Event: runs a sub proc of overlay 171 (table gSubProcTable) and copies its
 * result code (0 or 1) to the script result.
 */
int SCRCMD_SubProcEventMain(struct GameEvent *event, int *state, void *workPtr)
{
    SubProcEventWork *work = workPtr;
    int value;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent((struct GameSystem *)work->gameSystem, (struct FieldMap *)work->fieldMap, (sptr)ov171_id, (void *)gSubProcTable, (void *)&work->param));
        *state = *state + 1;
        break;
    case 1:
        switch (work->param.resultCode) {
        case 0:
            value = 0;
            *work->result = value;
            break;
        case 1:
            value = 1;
            *work->result = value;
            break;
        }
        return 1;
    }
    return 0;
}
