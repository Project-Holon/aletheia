/*
 * file:     event_poke_status.c
 * unit:     yes
 * function: EVENT_POKE_STATUS_CreatePokeSelectEvent, EVENT_POKE_STATUS_CreatePokeSelectMoveEvent, EVENT_POKE_STATUS_CreatePokeSelectStatusEvent, EVENT_POKE_STATUS_PokeSelectEvent, EVENT_POKE_STATUS_CreateMoveSelectEvent, EVENT_POKE_STATUS_MoveSelectEvent
 * address:  0x0215A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from event_poke_status.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   d_021728CC  0x021728CC  data
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateSubProcListEvent  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov131_id       0x00000083  data
 *   gPokeStatusProcData     0x021DC800  data  ov131
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 */
#include "../ov131/p_status_types.h"
#include "field_event_types.h"
#include "event_poke_status_shared_types.h"

struct BigObj;

struct Ctx;

struct Obj;

struct Desc;

struct Blk37;

struct Evt;

struct IcaAnime;

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

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);

extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void *GAME_DATA_GetMyParty(const struct BigObj *p);

extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);

extern void *GAME_EVENT_GetWork(struct Obj *p);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);

extern u32 POKEPARTY_GetCount(void *p);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *, void *, int, int);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *, void *, int, int, int, int, int);

extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);

extern void *FIELD_STATUS_CreateSubProcListEvent(char *anime, int slot, int config, int target);

extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);

extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);

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
    PokeListParam *listParam = GFL_HEAP_Alloc(4, 0x98, 1, d_021728CC, 0x40);
    void *event;
    PokeListEventWork *work;
    listParam->party = party;
    listParam->listMode = 3;
    listParam->listArg = 0;
    listParam->selectedSlot = 0;
    event = GAME_EVENT_Create((void *)gameSystem, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    work = GAME_EVENT_GetWork(event);
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
    PokeListParam *listParam = GFL_HEAP_Alloc(4, 0x98, 1, d_021728CC, 0x66);
    void *event;
    PokeListEventWork *work;
    listParam->party = party;
    listParam->listMode = 0x18;
    listParam->listArg = 0;
    listParam->selectedSlot = 0;
    listParam->fieldIndex = fieldIndex;
    listParam->argValue2 = moveId;
    event = GAME_EVENT_Create((void *)gameSystem, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    work = GAME_EVENT_GetWork(event);
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
    int zukanSave = (int)ZUKAN_SAVE_GetFromGameData(gameData);
    PokeListParam *listParam = GFL_HEAP_Alloc(4, 0x98, 1, d_021728CC, 0x90);
    PStatusParam *statusParam;
    void *event;
    PokeListEventWork *work;
    listParam->party = party;
    listParam->listMode = 0x19;
    listParam->listArg = 0;
    listParam->selectedSlot = 0;
    statusParam = GFL_HEAP_Alloc(4, 0x28, 1, d_021728CC, 0x97);
    statusParam->ppd = party;
    statusParam->config = gameData;
    statusParam->ppt = 1;
    statusParam->mode = 1;
    statusParam->max = POKEPARTY_GetCount(party);
    statusParam->page = 0;
    statusParam->isNationalDex = ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)zukanSave);
    statusParam->canUseButtons = 0;
    event = GAME_EVENT_Create((void *)gameSystem, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    work = GAME_EVENT_GetWork(event);
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
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcListEvent(gameSystem, (int)work->fieldMap, (int)work->listParam, (int)work->statusParam));
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
        GFL_HEAP_Free(work->listParam);
        if (work->statusParam != 0)
            GFL_HEAP_Free(work->statusParam);
        return 1;
    }
    return 0;
}

int EVENT_POKE_STATUS_CreateMoveSelectEvent(int gameSystem, int fieldMap, int pos, int retDecided, int retMovePos, int mode, unsigned short newMove)
{
    int gameData = (int)GAMESYSTEM_GetGameData((const struct Ctx *)gameSystem);
    void *party = GAME_DATA_GetMyParty((void *)gameData);
    PStatusParam *param = (PStatusParam *)GFL_HEAP_Alloc(4, 0x98, 1, (const char *)&d_021728CC, 0x11d);
    int event;
    MoveSelectEventWork *work;

    param->ppd = party;
    param->ppt = 1;
    param->max = POKEPARTY_GetCount(party);
    param->pos = pos;
    param->page = 1;
    param->newMove = newMove;
    param->mode = (mode == 1) ? 3 : 2;
    param->canUseButtons = 0;
    param->config = (void *)gameData;
    event = (int)GAME_EVENT_Create((void *)gameSystem, 0, EVENT_POKE_STATUS_MoveSelectEvent, 0x14);
    work = GAME_EVENT_GetWork((struct Obj *)event);
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
        GFL_HEAP_Free(work->param);
        return 1;
    }
    return 0;
}
