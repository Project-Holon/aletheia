/*
 * file:     scrcmd_sodateya.c
 * unit:     yes
 * function: SCRCMD_SODATEYA_RunPartyMenuEvent, SCRCMD_SODATEYA_Create
 * address:  0x0215D1E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_proc.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   func_020307B0  0x020307B0  arm
 *   FIELD_STATUS_CreateFieldOpenEvent   0x020145CC  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02030734  0x02030734  arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateSubProcListEvent  0x02014910  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   sAllocSiteScrcmdSodateya     0x02172900  data
 */
#include "scrcmd_proc_shared_types.h"

typedef struct PartyMenuParam {
    void *party;        /* 0x00 */
    u32 pad04[2];
    u32 listWork;       /* 0x0C */
    u32 pad10[9];
    u32 menuType;       /* 0x34 */
    u32 cursorPos;      /* 0x38 */
    u32 selectedPos;    /* 0x3C */
} PartyMenuParam;

typedef struct PartyMenuState {
    void *party;        /* 0x00 */
    u32 listWork;       /* 0x04 */
    u32 gameData;       /* 0x08 */
    u8 enabled;         /* 0x0C */
    u8 cursor;          /* 0x0D */
    u8 partyCount;      /* 0x0E */
    u8 selectedPos;     /* 0x0F */
    u8 reserved10;      /* 0x10 */
    u8 pad11[7];
    u32 zukanSave;      /* 0x18 */
} PartyMenuState;

typedef struct DaycareEventWork {
    void *gameSystem;           /* 0x00 */
    void *fieldMap;             /* 0x04 */
    PartyMenuParam *menuParam;  /* 0x08 */
    PartyMenuState *menuState;  /* 0x0C */
    u16 *resultVar;             /* 0x10 */
} DaycareEventWork;

extern void *GAME_DATA_GetMyParty(const struct GameData *);

extern u32 POKEPARTY_GetCount(void *);

extern void *GAMESYSTEM_GetGameData(const struct GameSystem *);

extern void *ZUKAN_SAVE_GetFromGameData(void *);

extern u32 func_020307B0(void *);

extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);

extern int FIELD_STATUS_CreateFieldCloseEvent(int, int);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *, void *, int, int);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *, void *, int, int, int, int, int);

extern void GAME_EVENT_CallEvent(struct GameEvent *evt, struct GameEvent **out);

extern void *FIELD_STATUS_CreateSubProcListEvent(char *, int, int, int);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *);

extern struct GameEvent *func_020122C0(void *owner, void *, void *, u32 size);

extern void *func_020124E8(struct GameEvent *);

int SCRCMD_SODATEYA_RunPartyMenuEvent(void *event, u32 *seq, DaycareEventWork *work);

void *SCRCMD_SODATEYA_Create(void *gameSystem, void *fieldMap, u16 *resultVar);

extern const char sAllocSiteScrcmdSodateya[];

int SCRCMD_SODATEYA_RunPartyMenuEvent(void *event, u32 *seq, DaycareEventWork *work)
{
    u32 seqValue = *seq;
    void *gameSystem = work->gameSystem;
    switch (seqValue) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        *seq = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)work->fieldMap));
        work->menuParam->selectedPos = work->menuState->selectedPos;
        *seq = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcListEvent(gameSystem, (int)work->fieldMap, (int)work->menuParam, (int)work->menuState));
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
        *work->resultVar = work->menuParam->selectedPos;
        func_020307B0(work->menuParam);
        func_020307B0(work->menuState);
        return 1;
    }
    return 0;
}

void *SCRCMD_SODATEYA_Create(void *gameSystem, void *fieldMap, u16 *resultVar)
{
    void *gameData = GAMESYSTEM_GetGameData(gameSystem);
    void *party = GAME_DATA_GetMyParty(gameData);
    u32 zukanSave = (u32)ZUKAN_SAVE_GetFromGameData(gameData);
    PartyMenuParam *menuParam = func_02030734(4, 0x98, 0, sAllocSiteScrcmdSodateya, 0x22B);
    PartyMenuState *menuState;
    DaycareEventWork *work;
    void *event;
    menuParam->party = party;
    menuParam->menuType = 0x12;
    menuParam->cursorPos = 0;
    menuParam->selectedPos = 0;
    menuState = func_02030734(4, 0x28, 0, sAllocSiteScrcmdSodateya, 0x232);
    menuState->party = menuParam->party;
    menuState->listWork = menuParam->listWork;
    menuState->gameData = (u32)gameData;
    menuState->enabled = 1;
    menuState->partyCount = POKEPARTY_GetCount(party);
    menuState->cursor = 0;
    menuState->reserved10 = 0;
    menuState->selectedPos = 0;
    menuState->zukanSave = ZUKAN_SAVE_IsNationalDexEnabled((struct ZukanSave *)zukanSave);
    event = func_020122C0(gameSystem, 0, (void *)SCRCMD_SODATEYA_RunPartyMenuEvent, 0x14);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->menuParam = menuParam;
    work->menuState = menuState;
    work->resultVar = resultVar;
    return event;
}
