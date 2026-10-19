/*
 * file:     event_field_menu.c
 * unit:     yes
 * function: EVENT_FIELD_MENU_Create, EVENT_FIELD_MENU_CreateForZone, EVENT_FIELD_MENU_Main, EVENT_FIELD_MENU_GetProcKindOfButton, EVENT_FIELD_MENU_OnUpdate, EVENT_FIELD_MENU_OnClose, EVENT_FIELD_MENU_OnFinish
 * address:  0x0215FC40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_network.c by tools/splitfile.py.
 *
 * symbols:
 *   EVENT_SHORTCUT_MENU_CreateProcEvent  0x0216075C  thumb  ov010
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   FIELD_SUBSCREEN_ResolveMode  0x021A0EE4  thumb  ov021
 *   UI_SetInputMode  0x020355D8  arm
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   ZONEDATA_IsZone96Pair 0x02013CE0 thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   FIELD_SUBSCREEN_ClearPanelResult  0x021A0FA8  thumb  ov021
 *   FIELD_SUBSCREEN_GetMenuSelectedButton  0x021A12A4  thumb  ov021
 *   FIELD_COMM_ACTOR_CreateSubscreenChangeEvent  0x021945A4  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   MOVE_POKEMON_InitSkillInfo  0x0215E840  thumb  ov010
 *   MOVE_POKEMON_InitSkillTarget  0x0215EA30  thumb  ov010
 *   MOVE_POKEMON_CreateSkillEvent  0x0215EA38  thumb  ov010
 *   FIELD_LINK_EVENT_Create  0x021644F4  thumb  ov010
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_DATA_SetFieldMenuCursor  0x020129D0  thumb
 *   SCRCMD_NETWORK_sProcKindOfButton     0x021712AC  data
 *   FIELD_SUBSCREEN_SetMenuSelectedButton   0x021A12BC  thumb
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_network_shared_types.h"
#include "event_wifi_proc_shared_types.h"

struct MoveModelSys;

/* Skill (hidden move) structs shared with move_pokemon.c. */
typedef struct FieldSkillInfo {
    u16 zoneId;                     /* 0x00 */
    u16 usableMask;                 /* 0x02 */
    u32 playerState;                /* 0x04 */
    struct GameSystem *gameSystem;  /* 0x08 */
    void *playerObj;                /* 0x0C */
    struct FieldMap *fieldMap;      /* 0x10 */
} FieldSkillInfo;

typedef struct FieldSkillTarget {
    u16 partySlot;                  /* 0x00 */
    u16 skillIndex;                 /* 0x02 */
    u32 targetParam;                /* 0x04 */
} FieldSkillTarget;

struct FieldMenuWork;

/*
 * Request object that the field menu event hands to the shortcut menu
 * event (event_shortcut_menu.c reads kind/detail/result/next). It sits at
 * 0x1C inside FieldMenuWork and is 0x34 bytes.
 */
typedef struct ShortcutRequest {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    struct GameEvent *event;        /* 0x08 */
    u32 kind;                       /* 0x0C */
    int detail;                     /* 0x10: -1 */
    int (*onUpdate)(struct ShortcutRequest *request, struct FieldMenuWork *work);  /* 0x14 */
    int (*onClose)(struct ShortcutRequest *request, struct FieldMenuWork *work);   /* 0x18 */
    int (*onFinish)(struct ShortcutRequest *request, struct FieldMenuWork *work);  /* 0x1C */
    struct FieldMenuWork *work;    /* 0x20 */
    u32 result;                     /* 0x24: set by the menu */
    u32 next;                       /* 0x28: chosen menu entry */
    u32 partySlot;                  /* 0x2C */
    u32 targetParam;                /* 0x30 */
} ShortcutRequest;

/* Work of the field menu event (X button menu, 0x5C bytes). */
typedef struct FieldMenuWork {
    u16 id;                         /* 0x00 */
    u8 pad02[2];
    struct GameEvent *event;        /* 0x04 */
    struct GameSystem *gameSystem;  /* 0x08 */
    struct FieldMap *fieldMap;      /* 0x0C */
    u32 selectedButton;             /* 0x10: button chosen in the field menu */
    u32 state;                      /* 0x14 */
    int linkMode;                   /* 0x18: 3, 4, 2 or 5 */
    ShortcutRequest request;        /* 0x1C */
    u8 pad50[0x5C - 0x50];
} FieldMenuWork;

/* game system, game event, game data */
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, void *parent, EventTaskFn taskFn, u32 workSize);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

extern void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *next);

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);

extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);

extern void GAME_DATA_SetSubscreenType(struct GameData *gameData, u32 subscreenType);

extern void GAME_DATA_SetFieldMenuCursor(struct GameData *gameData, u8 cursor);

extern void MI_CpuFill8(void *dst, int value, int size);

/* field map link and moving models */
extern struct FieldCommLink *FIELDMAP_GetSubscreen(struct FieldMap *fieldMap);

extern struct MoveModelSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);

extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);

extern u32 ZONEDATA_IsZone96Pair(u32 zoneId);

extern u32 FIELD_SUBSCREEN_GetMode(struct FieldCommLink *link);

extern int FIELD_SUBSCREEN_ResolveMode(struct FieldCommLink *link, int a);

extern void UI_SetInputMode(u8 value);

extern int FIELD_SUBSCREEN_IsIdle(struct FieldCommLink *link);

extern int FIELD_SUBSCREEN_RequestMode(struct FieldCommLink *link, u32 a);

extern int FIELD_SUBSCREEN_GetPanelResult(struct FieldCommLink *link);

extern void FIELD_SUBSCREEN_ClearPanelResult(struct FieldCommLink *link);

extern u32 FIELD_SUBSCREEN_GetMenuSelectedButton(struct FieldCommLink *link);

extern void FIELD_SUBSCREEN_SetMenuSelectedButton(struct FieldCommLink *link, int button);

extern struct GameEvent *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 linkMode);

extern void FLDMMDL_SysPauseMove(struct MoveModelSys *moveModelSys);

extern u32 *FLDMMDL_SysResumeMove(struct MoveModelSys *moveModelSys);

extern void MOVE_POKEMON_InitSkillInfo(struct FieldMap *fieldMap, FieldSkillInfo *info);

extern void MOVE_POKEMON_InitSkillTarget(FieldSkillTarget *target, u16 partySlot, u16 skillIndex, u32 targetParam);

extern struct GameEvent *MOVE_POKEMON_CreateSkillEvent(int skillIndex, FieldSkillTarget *target, FieldSkillInfo *info);

extern struct GameEvent *FIELD_LINK_EVENT_Create(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);

extern struct GameEvent *EVENT_SHORTCUT_MENU_CreateProcEvent(ShortcutRequest *request, u16 id);

extern const u32 SCRCMD_NETWORK_sProcKindOfButton[];

struct GameEvent *EVENT_FIELD_MENU_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);

struct GameEvent *EVENT_FIELD_MENU_CreateForZone(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);

int EVENT_FIELD_MENU_Main(struct GameEvent *event, u32 *seq, void *workArg);

u32 EVENT_FIELD_MENU_GetProcKindOfButton(u32 button);

int EVENT_FIELD_MENU_OnUpdate(ShortcutRequest *request, FieldMenuWork *work);

int EVENT_FIELD_MENU_OnClose(ShortcutRequest *request, FieldMenuWork *work);

int EVENT_FIELD_MENU_OnFinish(ShortcutRequest *request, FieldMenuWork *work);

struct GameEvent *EVENT_FIELD_MENU_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id)
{
    struct FieldCommLink *link;
    int workSize = 0x5c;
    struct GameEvent *event;
    FieldMenuWork *work;
    int linkMode;

    link = FIELDMAP_GetSubscreen(fieldMap);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELD_MENU_Main, workSize);
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, workSize);
    work->gameSystem = gameSystem;
    work->event = event;
    work->fieldMap = fieldMap;
    work->id = id;
    work->state = 0;
    work->request.gameSystem = gameSystem;
    work->request.fieldMap = fieldMap;
    work->request.event = event;
    work->request.onUpdate = EVENT_FIELD_MENU_OnUpdate;
    work->request.onClose = EVENT_FIELD_MENU_OnClose;
    work->request.onFinish = EVENT_FIELD_MENU_OnFinish;
    work->request.work = work;
    work->request.detail = workSize - 0x5d;
    linkMode = FIELD_SUBSCREEN_GetMode(link);
    switch (linkMode) {
    case 3:
        linkMode = 3;
        break;
    case 4:
        linkMode = 4;
        break;
    default:
        linkMode = FIELD_SUBSCREEN_ResolveMode(FIELDMAP_GetSubscreen(work->fieldMap), 0);
        break;
    }
    work->linkMode = linkMode;
    UI_SetInputMode(1);
    return event;
}

struct GameEvent *EVENT_FIELD_MENU_CreateForZone(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id)
{
    struct GameEvent *event;
    FieldMenuWork *work;

    event = EVENT_FIELD_MENU_Create(gameSystem, fieldMap, id);
    work = GAME_EVENT_GetWork(event);
    work->linkMode = ZONEDATA_IsZone96Pair(FIELDMAP_GetZoneId(fieldMap)) == 1 ? 5 : 2;
    return event;
}

/*
 * Nine-state field menu (X button) task of the ov010 field (the extent ends at
 * 0x0215FEC6; 0x0215FEC8 is its unlabelled table-lookup leaf). State 3
 * keeps the call arm inside the negated test so the `return 1` block
 * follows it.
 */
int EVENT_FIELD_MENU_Main(struct GameEvent *event, u32 *seq, void *workArg)
{
    FieldMenuWork *work = workArg;
    FieldSkillTarget target;
    FieldSkillInfo info;
    struct MoveModelSys *moveModelSys;
    struct GameData *gameData;
    struct GameEvent *skillEvent;
    u32 selectedButton;
    int linkState;

    switch (work->state) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(work->fieldMap)) == 1) {
            moveModelSys = FIELDMAP_GetMmdlSys(work->fieldMap);
            gameData = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(event));
            FLDMMDL_SysPauseMove(moveModelSys);
            GAME_DATA_SetFieldMenuCursor(gameData, 1);
            FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(work->fieldMap), 1);
            work->state = 1;
        }
        break;
    case 1:
        linkState = FIELD_SUBSCREEN_GetPanelResult(FIELDMAP_GetSubscreen(work->fieldMap));
        if (linkState == 3) {
            work->state = 2;
            FIELD_SUBSCREEN_ClearPanelResult(FIELDMAP_GetSubscreen(work->fieldMap));
        } else if (linkState == 4) {
            work->state = 3;
            FIELD_SUBSCREEN_ClearPanelResult(FIELDMAP_GetSubscreen(work->fieldMap));
        }
        break;
    case 2:
        gameData = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(event));
        selectedButton = FIELD_SUBSCREEN_GetMenuSelectedButton(FIELDMAP_GetSubscreen(work->fieldMap));
        GAME_DATA_SetFieldMenuCursor(gameData, selectedButton);
        work->selectedButton = FIELD_SUBSCREEN_GetMenuSelectedButton(FIELDMAP_GetSubscreen(work->fieldMap));
        work->request.kind = EVENT_FIELD_MENU_GetProcKindOfButton(selectedButton);
        work->state = 5;
        break;
    case 3:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        if (work->request.result != 1 && work->request.result != 4) {
            GAME_EVENT_ChangeEvent(event, FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(GAME_EVENT_GetGameSystem(event), work->fieldMap, work->linkMode));
            return 0;
        }
        return 1;
    case 4:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        MOVE_POKEMON_InitSkillInfo(GAMESYSTEM_GetFieldMap(work->gameSystem), &info);
        MOVE_POKEMON_InitSkillTarget(&target, work->request.partySlot, work->request.next, work->request.targetParam);
        skillEvent = MOVE_POKEMON_CreateSkillEvent(work->request.next, &target, &info);
        if (skillEvent == 0)
            return 1;
        GAME_EVENT_ChangeEvent(work->event, skillEvent);
        break;
    case 5:
        GAME_EVENT_CallEvent(event, EVENT_SHORTCUT_MENU_CreateProcEvent(&work->request, work->id));
        work->state = 6;
        break;
    case 6:
        if (work->request.result == 0)
            work->state = 1;
        else if (work->request.result == 1)
            work->state = 3;
        else if (work->request.result == 3)
            work->state = 7;
        else if (work->request.result == 2)
            work->state = 4;
        else if (work->request.result == 4)
            work->state = 3;
        break;
    case 7:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        GAME_EVENT_CallEvent(event, FIELD_LINK_EVENT_Create(work->request.next, work->gameSystem, work->fieldMap));
        work->state = 8;
        break;
    case 8:
        return 1;
    }
    return 0;
}

/*
 * Unlabelled leaf after EVENT_FIELD_MENU_Main (bl from 0x0215FDD0): the request
 * kind (menu proc) of a field menu button, from the table in the overlay data.
 */
u32 EVENT_FIELD_MENU_GetProcKindOfButton(u32 button)
{
    return SCRCMD_NETWORK_sProcKindOfButton[button];
}

/*
 * Writes the selected button back to the subscreen when the menu closed on result 0; the first
 * call's result is the first operand either way.
 */
int EVENT_FIELD_MENU_OnUpdate(ShortcutRequest *request, FieldMenuWork *work)
{
    struct FieldCommLink *link = FIELDMAP_GetSubscreen(work->fieldMap);

    if (request->result == 0)
        FIELD_SUBSCREEN_SetMenuSelectedButton(link, work->selectedButton);

    return 1;
}

/*
 * Unlabelled leaf: returns 1.
 */
int EVENT_FIELD_MENU_OnClose(ShortcutRequest *request, FieldMenuWork *work)
{
    return 1;
}

int EVENT_FIELD_MENU_OnFinish(ShortcutRequest *request, FieldMenuWork *work)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(work->gameSystem);

    switch (request->result) {
    case 4:
        GAME_DATA_SetSubscreenType(gameData, 6);
        break;
    case 0:
        GAME_DATA_SetSubscreenType(gameData, 1);
        break;
    case 1:
    case 2:
    case 3:
        GAME_DATA_SetSubscreenType(gameData, (u8)work->linkMode);
        break;
    default:
        break;
    }
    return 1;
}
