/*
 * file:     event_poke_status.c
 * unit:     yes
 * function: EVENT_POKE_STATUS_CreatePokeSelectEvent, EVENT_POKE_STATUS_CreatePokeSelectMoveEvent, EVENT_POKE_STATUS_CreatePokeSelectStatusEvent, EVENT_POKE_STATUS_PokeSelectEvent, EVENT_POKE_STATUS_CreateMoveSelectEvent, EVENT_POKE_STATUS_MoveSelectEvent, func_0215A438, func_0215A460, func_0215A480, func_0215A490, func_0215A4A0, func_0215A4B4, func_0215A4C8, func_0215A4D8, func_0215A4EC, func_0215A500
 * address:  0x0215A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Range 0x0215A438..0x0215A500 is from an unknown original file; it stays here
 * until its home is known.
 *
 * symbols:
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021728CC  0x021728CC  data
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov131_id       0x00000083  data
 *   gPokeStatusProcData     0x021DC800  data  ov131
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 */
#include "../ov131/p_status_types.h"
struct BigObj;
struct Ctx;
struct Obj;
struct Desc;
struct Blk37;
struct Evt;
struct IcaAnime;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

#include "field_event_types.h"

/* Work of the Pokemon pick event (0x18 bytes). */
typedef struct PokeListEventWork {
    void *gameSystem;           /* 0x00 */
    void *fieldMap;             /* 0x04 */
    PokeListParam *listParam;   /* 0x08 */
    PStatusParam *statusParam;  /* 0x0C: status screen parameter, 0 when the event shows only the list */
    u16 *retDecided;            /* 0x10: 1 = a Pokemon was picked */
    u16 *retSlot;               /* 0x14: party slot picked */
} PokeListEventWork;

/* Work of the move-select event: the status screen opened in mode 2/3. */
typedef struct MoveSelectEventWork {
    void *gameSystem;
    void *fieldMap;
    PStatusParam *param;
    u16 *retDecided;    /* 1 = a move slot was picked */
    u16 *retMovePos;
} MoveSelectEventWork;

typedef struct RecordHead24 {
    int word[6];
} RecordHead24;
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern void ZONEDATA_SetEventFlag(char *, int);
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_0201AA18(void *p);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *, void *, int, int);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *, void *, int, int, int, int, int);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern int SCRIPT_SYS_GetEventScriptWork(int);
extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);
extern u32 func_0202A230(void *a, u32 idx);
int EVENT_POKE_STATUS_PokeSelectEvent(void *event, u32 *seq, PokeListEventWork *work);
/*
 * Case 2 loads 0x00000083 from the pool: an absolute symbol (overlay id),
 * see docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 */
int EVENT_POKE_STATUS_MoveSelectEvent(void *event, u32 *seq, MoveSelectEventWork *work);
extern const char d_021728CC[];
extern u8 ov131_id[];
extern u8 gPokeStatusProcData[];

void *EVENT_POKE_STATUS_CreatePokeSelectEvent(int gameSystem, u16 *retDecided, u16 *retSlot)
{
    void *party = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((void *)gameSystem));
    PokeListParam *listParam = func_02030734(4, 0x98, 1, d_021728CC, 0x40);
    void *event;
    PokeListEventWork *work;
    listParam->party = party;
    listParam->listMode = 3;
    listParam->listArg = 0;
    listParam->selectedSlot = 0;
    event = func_020122C0((void *)gameSystem, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    work = func_020124E8(event);
    work->gameSystem = (void *)gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap((void *)gameSystem);
    work->listParam = listParam;
    work->statusParam = 0;
    work->retDecided = retDecided;
    work->retSlot = retSlot;
    return event;
}

void *EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(int gameSystem, int retDecided, int retSlot, int fieldIndex, unsigned short moveId)
{
    void *party = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((const struct Ctx *)gameSystem));
    PokeListParam *listParam = func_02030734(4, 0x98, 1, d_021728CC, 0x66);
    void *event;
    PokeListEventWork *work;
    listParam->party = party;
    listParam->listMode = 0x18;
    listParam->listArg = 0;
    listParam->selectedSlot = 0;
    listParam->fieldIndex = fieldIndex;
    listParam->argValue2 = moveId;
    event = func_020122C0((void *)gameSystem, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    work = func_020124E8(event);
    work->gameSystem = (void *)gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap((void *)gameSystem);
    work->listParam = listParam;
    work->statusParam = 0;
    work->retDecided = (u16 *)retDecided;
    work->retSlot = (u16 *)retSlot;
    return event;
}

void *EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(int gameSystem, int retDecided, int retSlot)
{
    void *gameData = GAMESYSTEM_GetGameData((const struct Ctx *)gameSystem);
    void *party = GAME_DATA_GetMyParty(gameData);
    int zukanSave = (int)func_0200CA1C(gameData);
    PokeListParam *listParam = func_02030734(4, 0x98, 1, d_021728CC, 0x90);
    PStatusParam *statusParam;
    void *event;
    PokeListEventWork *work;
    listParam->party = party;
    listParam->listMode = 0x19;
    listParam->listArg = 0;
    listParam->selectedSlot = 0;
    statusParam = func_02030734(4, 0x28, 1, d_021728CC, 0x97);
    statusParam->ppd = party;
    statusParam->config = gameData;
    statusParam->ppt = 1;
    statusParam->mode = 1;
    statusParam->max = func_0201AA18(party);
    statusParam->page = 0;
    statusParam->isNationalDex = func_0200CA38((struct Blk37 *)zukanSave);
    statusParam->canUseButtons = 0;
    event = func_020122C0((void *)gameSystem, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    work = func_020124E8(event);
    work->gameSystem = (void *)gameSystem;
    work->fieldMap = GAMESYSTEM_GetFieldMap((void *)gameSystem);
    work->listParam = listParam;
    work->statusParam = statusParam;
    work->retDecided = (u16 *)retDecided;
    work->retSlot = (u16 *)retSlot;
    return event;
}

int EVENT_POKE_STATUS_PokeSelectEvent(void *event, u32 *seq, PokeListEventWork *work)
{
    u32 step = *seq;
    void *gameSystem = work->gameSystem;
    int slot;
    switch (step) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        *seq = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)work->fieldMap));
        *seq = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, func_02014910(gameSystem, (int)work->fieldMap, (int)work->listParam, (int)work->statusParam));
        *seq = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        *seq = 4;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 5;
        break;
    case 5:
        slot = work->listParam->selectedSlot;
        if (slot <= 5) {
            *work->retSlot = slot;
            *work->retDecided = 1;
        } else {
            *work->retSlot = 0;
            *work->retDecided = 0;
        }
        func_020307B0(work->listParam);
        if (work->statusParam != 0)
            func_020307B0(work->statusParam);
        return 1;
    }
    return 0;
}

int EVENT_POKE_STATUS_CreateMoveSelectEvent(int gameSystem, int fieldMap, int pos, int retDecided, int retMovePos, int mode, unsigned short newMove)
{
    int gameData = (int)GAMESYSTEM_GetGameData((const struct Ctx *)gameSystem);
    void *party = GAME_DATA_GetMyParty((void *)gameData);
    PStatusParam *param = (PStatusParam *)func_02030734(4, 0x98, 1, (const char *)&d_021728CC, 0x11d);
    int event;
    MoveSelectEventWork *work;

    param->ppd = party;
    param->ppt = 1;
    param->max = func_0201AA18(party);
    param->pos = pos;
    param->page = 1;
    param->newMove = newMove;
    param->mode = (mode == 1) ? 3 : 2;
    param->canUseButtons = 0;
    param->config = (void *)gameData;
    event = (int)func_020122C0((void *)gameSystem, 0, EVENT_POKE_STATUS_MoveSelectEvent, 0x14);
    work = func_020124E8((struct Obj *)event);
    work->gameSystem = (void *)gameSystem;
    work->fieldMap = (void *)fieldMap;
    work->param = param;
    work->retDecided = (u16 *)retDecided;
    work->retMovePos = (u16 *)retMovePos;
    return event;
}

/*
 * Case 2 loads 0x00000083 from the pool: an absolute symbol (overlay id),
 * see docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 */
int EVENT_POKE_STATUS_MoveSelectEvent(void *event, u32 *seq, MoveSelectEventWork *work)
{
    u32 step = *seq;
    void *gameSystem = work->gameSystem;
    switch (step) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        *seq = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)work->fieldMap));
        *seq = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov131_id, gPokeStatusProcData, work->param);
        *seq = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        *seq = 4;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 5;
        break;
    case 5:
        if (work->param->retSel == 0) {
            *work->retMovePos = work->param->retMovePos;
            *work->retDecided = 1;
        } else {
            *work->retMovePos = 0;
            *work->retDecided = 0;
        }
        func_020307B0(work->param);
        return 1;
    }
    return 0;
}

void func_0215A438(int scrcmdWork, int index, RecordHead24 *src)
{
    int *entry = (int *)SCRIPT_WORK_GetTrainerEntry((char *)SCRIPT_SYS_GetEventScriptWork(scrcmdWork), index);

    *(RecordHead24 *)entry = *src;
    entry[6] = 0;
}

/*
 * Map a tick count onto a 3000/5000 ms window, truncated to 16 bits.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215A460(u32 ticks)
{
    if (ticks < 5000)
        return (u16)(ticks - 3000);
    return (u16)(ticks - 5000);
}

u16 func_0215A480(unsigned id) { return id + 3000; }

/*
 * extent: includes unlabelled range-test func_0215A4A0; function-start seed.
 */
u16 func_0215A490(unsigned id) { return id + 5000; }

int func_0215A4A0(unsigned id) { if (id >= 5000) return 1; return 0; }

int func_0215A4B4(int saveData)
{
    if (func_0202A230((void *)saveData, 2) == 1)
        return 1;
    return 0;
}

int func_0215A4C8(int saveData)
{
    return (u8)func_0202A230((void *)saveData, 2);
}

/*
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 */
unsigned func_0215A4D8(void *flagSet, unsigned flagOffset) { return ZONEDATA_CheckEventFlag(flagSet, (u16)(flagOffset + 1420)); }

void func_0215A4EC(char *flagSet, unsigned flagOffset) { ZONEDATA_SetEventFlag(flagSet, (u16)(flagOffset + 1420)); }

void func_0215A500(char *flagSet, unsigned flagOffset) { ZONEDATA_ResetEventFlag(flagSet, (u16)(flagOffset + 1420)); }
