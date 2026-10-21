/*
 * file:     symbol_map.c
 * unit:     yes
 * function: SYMBOL_MAP_FindGridIndex, SYMBOL_MAP_GetCellTileId, SYMBOL_MAP_GetNeighborCellId, SYMBOL_MAP_GetSelection, SYMBOL_MAP_GetSelectionGrid, SYMBOL_MAP_CreateLinkRecord, SYMBOL_MAP_GetSelectedCellTile, SYMBOL_MAP_GetSelectedNeighborCell, SYMBOL_MAP_IsHomeCell, SYMBOL_MAP_IsBlankCell, SYMBOL_MAP_IsPlainCell, SYMBOL_MAP_GetEventStateEntryValue, SYMBOL_MAP_CreateRecordTask, SYMBOL_MAP_DeleteLinkRecord, SYMBOL_MAP_RecordTaskMain, SYMBOL_MAP_GetLastResult, SYMBOL_MAP_StoreResult, SYMBOL_MAP_ScrCmdGetEventStateValue, SYMBOL_MAP_ScrCmdStartRecordTask, SYMBOL_MAP_GetSyncBlockItem, SYMBOL_MAP_GetSyncBlockHeader, SYMBOL_MAP_CreatePickerTask, SYMBOL_MAP_PickerTaskMain, SYMBOL_MAP_ScrCmdGetSyncBlockItem, SYMBOL_MAP_ScrCmdGetSyncBlockHeader, SYMBOL_MAP_ScrCmdStartPicker, SYMBOL_MAP_UpdateBg2Scale, SYMBOL_MAP_StartBg2Scale, SYMBOL_MAP_StopBg2Scale, SYMBOL_MAP_PokeEventTaskMain, SYMBOL_MAP_CreatePokeEventTask, SYMBOL_MAP_ResolveZoneId, SYMBOL_MAP_CheckEventFlag, SYMBOL_MAP_ScrCmdStartPmsInput, SYMBOL_MAP_PmsInputTaskMain, SYMBOL_MAP_ScrCmdSetSubscreenMode
 * address:  0x0216630C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from symbol_map_work.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   SYMBOL_MAP_GetSymbolIndex  0x021673C4  thumb  ov010
 *   SYMBOL_MAP_GetGroup  0x021673A8  thumb  ov010
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetPartnerSymbolPage  0x02176880  thumb  ov011
 *   g_SymbolMapGridTable 0x02171EF4 data a4
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   SYMBOL_MAP_GetEntryPage  0x0216749C  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   g_SymbolMapFileName     0x021729EC  data  a1
 *   EVENT_FIELD_PROCLINK_StartCommProc 0x02161CDC thumb ov010
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   ov203_id 0x000000CB data a1
 *   gDemo3dProcData 0x021BFB3C data ov203 a4
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb ov010
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb ov010
 *   VM_ReadU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb ov010
 *   PLEASURE_BOAT_GetPassengerParam  0x021C87A0  thumb ov021
 *   PLEASURE_BOAT_GetPassengerType  0x021C87AC  thumb ov021
 *   PLEASURE_BOAT_GetPassengerExtra  0x021C87B8  thumb ov021
 *   PLEASURE_BOAT_GetPassengerOccupied  0x021C87C8  thumb ov021
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   WIFI_HISTORY_IsCountryVisited  0x02009794  thumb
 *   WIFI_HISTORY_GetFirstFreeEntry  0x020095C8  thumb
 *   WIFI_HISTORY_GetEntry  0x0200973C  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 *   ov218_id  0x000000DA  data
 *   gUnSelectProcData  0x021BAB5C  data  a4 ov218
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   g_Bg2ScaleState  0x02172BA4  data  ov010  a4
 *   g_Bg2ScaleStep  0x021729FC  data  ov010  a4
 *   MTX_Scale22_  0x0207AD58  thumb
 *   G2x_SetBGyAffine_  0x0207D59C  arm
 *   GFL_USE_SetVBlankHook  0x02005654  thumb
 *   MTX_Identity22_ 0x0207AD40 arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_BEACON_SEARCH_SetSymbolMapPoke  0x0216559C  thumb  ov010
 *   ov215_id       0x000000D7  data   a1
 *   gEggDemoViewProcData     0x021F7118  data   ov215  a4
 *   ZONEDATA_GetParentZoneId  0x02013E40  thumb
 *   GAME_DATA_GetSpecialLocation  0x02012894  thumb
 *   g_ZoneRemapTable  0x02171F2C  data  ov010  a4
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WIFI_HISTORY_GetDisplayCount  0x02009590  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   PMSI_PARAM_Create  0x02024044  thumb
 *   GREETING_SAVEDATA_GetFromSave  0x0200E6F0  thumb
 *   GREETING_SAVEDATA_GetSentence  0x0200E6FC  thumb
 *   PMSI_PARAM_SetSentence  0x02024108  thumb
 *   PMSI_PARAM_CheckCanceled  0x0202411C  thumb
 *   PMSI_PARAM_GetWords  0x02024128  thumb
 *   PMSI_PARAM_GetWord  0x02024124  thumb
 *   PMSI_PARAM_GetSentence  0x02024134  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GREETING_SAVEDATA_SetSentence  0x0200E714  thumb
 *   PMSI_PARAM_Delete  0x020240FC  thumb
 *   ov110_id       0x0000006E  data   a1
 *   gPmsSelectProcData     0x021C39B8  data   ov110  a4
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   WEATHER_GetZoneWeatherId  0x0202C794  thumb
 *   WEATHER_RequestChangeNoFade  0x021A1BE4  thumb  ov021
 *   WEATHER_RequestChange  0x021A1BDC  thumb  ov021
 *   GAME_DATA_SetWeatherId  0x020129A0  thumb
 *   GFL_USE_ClearVBlankHook  0x0200566C  thumb  arm9
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "symbol_map_shared_types.h"
#include "../sdk_ioreg.h"

#include "../types.h"

struct ScriptVm;

struct SymbolMapSave;

struct SymbolMapSaveEntry;

struct Pokemon;

/* Holder of the link record pointer (first field of the owner struct). */
typedef struct SymbolMapOwner {
    SymbolMapLinkRecord *linkRecord;
} SymbolMapOwner;

/* Progress record updated by the ov203 task. */
typedef struct SymbolMapProgress {
    u8 pad00[4];
    s16 lastResult;               /* 0x04 */
    u8 pad06[2];
    int bestRank;                 /* 0x08 */
} SymbolMapProgress;

/* Work of the ov203 record task (created by SYMBOL_MAP_CreateRecordTask). */
typedef struct SymbolMapRecordWork {
    u32 linkWork[2];              /* 0x00, set up by the proc link starter */
    int lastResult;               /* 0x08 */
    u8 pad0C[4];
    u32 measuredValue;            /* 0x10, written by ov203 */
    u32 resultCode;               /* 0x14, 2 = completed */
    SymbolMapProgress *progress;  /* 0x18 */
    u16 *outCompleted;            /* 0x1C */
} SymbolMapRecordWork;

/* Header of the save sync block: a count and a list of byte items. */
typedef struct SaveSyncBlock {
    u8 type;                      /* 0x00 */
    u8 count;                     /* 0x01 */
    u8 variant;                   /* 0x02 */
    u8 items[1];                  /* 0x03, count entries */
} SaveSyncBlock;

/* Work of the ov218 picker task. ov218 writes the result bytes in the first 8 bytes. */
typedef struct SymbolMapPickerWork {
    u8 mode;                      /* 0x00 */
    u8 resultKind;                /* 0x01, written by ov218 */
    u16 resultValue;              /* 0x02, written by ov218 */
    int resultCode;               /* 0x04, 1 = picked */
    u16 candidateIds[20];         /* 0x08 */
    u8 ownedFlags[232];           /* 0x30, entries 1..232 */
    u8 pad118[4];
    u16 *outKind;                 /* 0x11C */
    u16 *outValue;                /* 0x120 */
    u16 *outPicked;               /* 0x124 */
} SymbolMapPickerWork;

/* One 0x1C-byte entry of the event state table; only the value at +0x14 is read. */
typedef struct EventStateEntry {
    u8 pad00[0x14];
    u32 value;                    /* 0x14 */
    u8 pad18[4];
} EventStateEntry;

/* Special location record: only the zone id is read. */
typedef struct SpecialLocation {
    u16 pad00[2];
    u16 zoneId;                   /* 0x04 */
} SpecialLocation;

typedef struct ZoneRemapEntry {
    u32 target;
    u32 source;
} ZoneRemapEntry;

/* Work of the ov215 task: runs the field close event, the ov215 proc and the field open event. */
typedef struct PokeEventWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameData *gameData;      /* 0x04 */
    u32 transitionArg;              /* 0x08, argument of the field close and open events */
    struct Pokemon *poke;           /* 0x0C */
    struct {
        struct GameData *gameData;
        struct Pokemon *poke;
    } procParam;                    /* 0x10 */
} PokeEventWork;

/* Work of the PMS input task. */
typedef struct PmsInputWork {
    u32 kind;                       /* 0x00 */
    u16 *outWord0;                  /* 0x04 */
    u16 *outWord1;                  /* 0x08 */
    u16 *outResult;                 /* 0x0C */
    void *pmsParam;                 /* 0x10 */
    u32 sentenceId;                 /* 0x14 */
    u32 hasSentence;                /* 0x18 */
} PmsInputWork;

typedef struct PmsInputWords {
    u16 first;
    u16 second;
} PmsInputWords;

#include "../arm9/pms_types.h"

#include "../arm9/gamesystem.h"
struct SaveControl;

#include "../arm9/game_data.h"

#include "../arm9/symbol_save.h"
struct GameComm;


#include "../ov011/intrude_comm.h"

#include "comm_player.h"

struct IntrudeCommSys;

#include "intrude_comm_query.h"



#include "../arm9/gfl_heap_wrap.h"
struct Entry32;


#include "../arm9/mi_memory.h"

struct GameEvent;

struct CommProcParam;

typedef int Bool;
#include "event_field_proclink.h"


struct ScrcmdWork;
struct ScriptWork;

#include "scrcmd_work.h"



#ifdef __MWERKS__
extern unsigned short SCRIPT_WORK_ReadWorkValue(void *vm, void *work); /* original prototype; the definition differs in pointer type, return type */
#else
extern unsigned short SCRIPT_WORK_ReadWorkValue(struct ScriptVm*, struct ScrcmdWork*);
#endif

#include "../arm9/vm.h"

extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct PleasureBoatWork;

#include "../ov021/pleasure_boat.h"




#include "script_sys.h"
struct WifiHistory;

#include "../arm9/wifi_history.h"


struct HistoryEntry;

struct MyStatus;

#include "../arm9/mystatus.h"



#include "../arm9/g2.h"


#include "../arm9/fx_mtx22.h"
extern void MTX_Identity22_(MtxFx22 *matrix);

struct PokemonParam;

#include "../arm9/poke_tool.h"
struct FieldMap;

#include "../arm9/field_status.h"




#include "../ov021/event_fieldmap_control.h"


#ifdef __MWERKS__
extern void GAME_BEACON_SEARCH_SetSymbolMapPoke(u16 species); /* original prototype; the definition differs in argument width */
#else
#include "game_beacon_set.h"
#endif
struct Location;

                             





struct EventWork;


#include "field_g3d_map_scr.h"


struct PmsiParam;


#include "../arm9/greeting_savedata.h"
#include "../arm9/game_event.h"
#include "../ov021/fieldmap.h"
#include "../arm9/zone_weather.h"
#include "../arm9/gfl_use.h"
#include "../arm9/pmsi_param.h"
#ifndef __MWERKS__
#include "../arm9/zonedata.h"
#endif
struct QuadRecord;
struct PmsData;










struct WeatherSys;

                              


                                 
                               
                             

#ifdef __MWERKS__
extern void WEATHER_RequestChangeNoFade(struct WeatherSys *sys, int weatherId); /* original prototype; the definition differs in return type, argument width */
#else
#include "../ov021/weather.h"
#endif

#ifdef __MWERKS__
extern void WEATHER_RequestChange(struct WeatherSys *sys, int weatherId); /* original prototype; the definition differs in argument width */
#else
#endif


u8 SYMBOL_MAP_FindGridIndex();

int SYMBOL_MAP_GetCellTileId(u8 *grid, int id);

int SYMBOL_MAP_GetNeighborCellId();

int SYMBOL_MAP_GetSelection(void *gameSystem, u32 *outSymbolIndex, u32 *outSymbolGroup);

u8 *SYMBOL_MAP_GetSelectionGrid(void *gameSystem);

SymbolMapLinkRecord *SYMBOL_MAP_CreateLinkRecord(u16 heapId, void *gameSystem, u32 *outStart);

int SYMBOL_MAP_GetSelectedCellTile(void *gameSystem, int cellId);

int SYMBOL_MAP_GetSelectedNeighborCell(void *gameSystem, int cellId, int dir);

int SYMBOL_MAP_IsHomeCell(int cellId);

int SYMBOL_MAP_IsBlankCell(int cellId);

int SYMBOL_MAP_IsPlainCell(int cellId);

u32 SYMBOL_MAP_GetEventStateEntryValue(void *entries, u32 index);

void *SYMBOL_MAP_CreateRecordTask(void *gameSystem, void *progress, void *outCompleted);

void SYMBOL_MAP_DeleteLinkRecord(SymbolMapOwner *owner);

int SYMBOL_MAP_RecordTaskMain(void *task, u32 *state);

int SYMBOL_MAP_GetLastResult(void *progress);

void SYMBOL_MAP_StoreResult(SymbolMapProgress *progress, int value);

int SYMBOL_MAP_ScrCmdGetEventStateValue(void *vm, void *work);

int SYMBOL_MAP_ScrCmdStartRecordTask(void *vm, void *work);

int SYMBOL_MAP_GetSyncBlockItem(SaveSyncBlock *block, unsigned index);

int SYMBOL_MAP_GetSyncBlockHeader(SaveSyncBlock *block, int sel);

void *SYMBOL_MAP_CreatePickerTask(void *gameSystem, int mode, u32 outKind, u32 outValue, u32 outPicked);

int SYMBOL_MAP_PickerTaskMain(void *task, int *state);

int SYMBOL_MAP_ScrCmdGetSyncBlockItem(void *vm, void *work);

int SYMBOL_MAP_ScrCmdGetSyncBlockHeader(void *vm, void *work);

int SYMBOL_MAP_ScrCmdStartPicker(void *vm, void *work);

void SYMBOL_MAP_UpdateBg2Scale(void *unused);

void SYMBOL_MAP_StartBg2Scale(void);

void SYMBOL_MAP_StopBg2Scale(void);

u32 SYMBOL_MAP_PokeEventTaskMain(void *task, u32 *state, PokeEventWork *work);

void *SYMBOL_MAP_CreatePokeEventTask(void *gameSystem, void *transitionArg, void *poke);

u32 SYMBOL_MAP_ResolveZoneId(void *gameData, u32 zoneId);

int SYMBOL_MAP_CheckEventFlag(void *gameData, u32 flagId);

int SYMBOL_MAP_ScrCmdStartPmsInput(void *vm, void *work);

u32 SYMBOL_MAP_PmsInputTaskMain(void *task, u32 *state);

int SYMBOL_MAP_ScrCmdSetSubscreenMode(void *vm, void *work);

extern u8 *g_SymbolMapGridTable[];

extern const char g_SymbolMapFileName[];

extern u8 ov203_id[];

extern u8 gDemo3dProcData[];

extern char ov218_id[];

extern char gUnSelectProcData[];

extern float g_Bg2ScaleState[2];

extern float g_Bg2ScaleStep;

extern char ov215_id[];

extern char gEggDemoViewProcData[];

extern ZoneRemapEntry g_ZoneRemapTable[2];

extern char ov110_id[];

extern char gPmsSelectProcData[];

/*
 * Finds the position of a cell id in a 30-entry grid (three columns). The
 * result defaults to 1 when the id is absent.
 */
u8 SYMBOL_MAP_FindGridIndex(grid, id)
u8 *grid;
int id;
{
    int i;

    for (i = 0; i < 0x1e; i++) {
        if (id == grid[i])
            return (u8)i;
    }
    return 1;
}

/*
 * Picks the tile of a cell from the grid: id 1 and id 5 have their own
 * tiles, the others depend on the left, right, upper and lower neighbours.
 */
int SYMBOL_MAP_GetCellTileId(u8 *grid, int id)
{
    int pos = SYMBOL_MAP_FindGridIndex(grid, id);
    int left = 0;
    int col = pos % 3;
    int right;
    int up;
    int down;

    if (col != 0 && pos != 1) {
        left = 1;
    }
    right = 0;
    if (col != 2 && pos != 1) {
        right = 1;
    }
    up = 0;
    if (pos - 3 >= 0 && grid[pos - 3] != 0) {
        up = 1;
    }
    down = 0;
    if (pos + 3 < 30 && grid[pos + 3] != 0) {
        down = 1;
    }

    if (id == 1) {
        return 0x119;
    }
    if (id == 5) {
        return 0x118;
    }
    if (left && right) {
        return 0x11D;
    }
    if (left && !right) {
        if (up && down) {
            return 0x11E;
        }
        if (up) {
            return 0x120;
        }
        if (down) {
            return 0x11B;
        }
    }
    if (!left && right) {
        if (up && down) {
            return 0x11C;
        }
        if (up) {
            return 0x11F;
        }
        if (down) {
            return 0x11A;
        }
    }
    return 0x119;
}

/*
 * Finds the position of a cell id in a grid (SYMBOL_MAP_FindGridIndex) and returns the
 * cell a step away from it: 0 = three back, 1 = three on, 2 = one back,
 * 3 = one on; any other direction returns the cell id itself.
 */
int SYMBOL_MAP_GetNeighborCellId(grid, cellId, dir, extra)
u8 *grid;
int cellId;
unsigned dir;
int extra;
{
    int pos = SYMBOL_MAP_FindGridIndex((u8 *)grid, cellId, dir, extra);

    switch (dir) {
    case 0:
        return grid[pos - 3];
    case 1:
        return grid[pos + 3];
    case 2:
        return grid[pos - 1];
    case 3:
        return grid[pos + 1];
    }
    return cellId;
}

/*
 * Reads the symbol index and group of the current selection (two 4-bit
 * fields of the link record) into the out parameters, or takes them from
 * the two ov010 save accessors when the exchange state is 4.
 */
int SYMBOL_MAP_GetSelection(void *gameSystem, u32 *outSymbolIndex, u32 *outSymbolGroup)
{
    void *gameData;
    u8 *saveData;
    void *comm;
    SymbolMapLinkRecord *record;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    saveData = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    comm = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    if (INTRUDE_COMM_GetPartnerSlot(comm, gameData) == 4) {
        *outSymbolIndex = SYMBOL_MAP_GetSymbolIndex(saveData);
        *outSymbolGroup = SYMBOL_MAP_GetGroup(saveData);
        return 1;
    }
    comm = (void *)INTRUDE_COMM_GetWorkIfRunning((struct GameComm *)comm);
    if (comm == 0) {
        *outSymbolIndex = 0;
        *outSymbolGroup = 0;
        return 0;
    }
    record = (SymbolMapLinkRecord *)INTRUDE_COMM_GetPartnerSymbolPage(comm);
    *outSymbolIndex = record->symbolIndex;
    *outSymbolGroup = record->symbolGroup;
    return 1;
}

/*
 * Returns the grid of the current selection from the table of 7 symbols
 * per group, or 0 when there is no selection. A zero case with a default
 * continuation keeps the failure exit first.
 */
u8 *SYMBOL_MAP_GetSelectionGrid(void *gameSystem) {
    u32 symbolIndex;
    u32 symbolGroup;
    switch (SYMBOL_MAP_GetSelection(gameSystem, &symbolIndex, &symbolGroup)) {
    case 0: return 0;
    default: break;
    }
    return g_SymbolMapGridTable[symbolIndex + symbolGroup * 7u];
}

/*
 * Builds the 0x54-byte record sent over the link: locally from the
 * selected list page plus three packed status fields (with the page
 * start written to *outStart), or as a copy of the partner's record when
 * the exchange is not in state 4 (*outStart = 530).
 *
 * recoup 2026-10-05 (lane Y5): EXACT in c99 and c. The older draft was DIFF10/260: the
 * fifth argument store of the second allocation sat after the argument copies. Fix: the
 * heap id is u16 in this function and in the allocator prototype (both sides, as in the
 * ov010 and SDK callers that declare u16 heap). Plain literals 0x1DC and 530 already
 * derive 530 from the held 0x1DC; a constant local did not change the schedule.
 * Twin search: grep -rl -E "SYMBOL_MAP_GetEntryPage|SYMBOL_MAP_GetSymbolIndex|SYMBOL_MAP_GetGroup" src/matched src/pending
 * (hits ov010 02166434, 021673C4, 021673A8, 0216749C, ov011 02174D5C); ov010 02166434 has
 * the same front half and was the shape source. Callees return real types: INTRUDE_COMM_GetPartnerSlot u8,
 * GAME_DATA_GetSymbolMapFlag int, SYMBOL_MAP_GetEntryPage u16, SYMBOL_MAP_GetSymbolIndex/A8 u8, GFL_HEAP_Alloc void *.
 */
SymbolMapLinkRecord *SYMBOL_MAP_CreateLinkRecord(u16 heapId, void *gameSystem, u32 *outStart)
{
    void *gameData;
    void *saveData;
    void *comm;
    void *partnerLink;
    SymbolMapLinkRecord *record;
    u32 page;
    u8 count;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    saveData = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    comm = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    if (INTRUDE_COMM_GetPartnerSlot(comm, gameData) == 4) {
        page = GAME_DATA_GetSymbolMapFlag(gameData);
        record = GFL_HEAP_Alloc(heapId, sizeof(SymbolMapLinkRecord), 1, g_SymbolMapFileName, 0x1C9);
        *outStart = SYMBOL_MAP_GetEntryPage((struct Entry32 *)saveData, (struct Entry32 *)record->entries, 20, page, &count);
        record->entryCount = count;
        record->symbolIndex = SYMBOL_MAP_GetSymbolIndex(saveData);
        record->symbolGroup = SYMBOL_MAP_GetGroup(saveData);
        record->state = 4;
        record->page = page;
        return record;
    }
    partnerLink = (void *)INTRUDE_COMM_GetWorkIfRunning((struct GameComm *)comm);
    if (partnerLink == 0)
        return 0;
    record = GFL_HEAP_Alloc(heapId, sizeof(SymbolMapLinkRecord), 1, g_SymbolMapFileName, 0x1DC);
    MI_CpuCopy8(INTRUDE_COMM_GetPartnerSymbolPage(partnerLink), record, sizeof(SymbolMapLinkRecord));
    *outStart = 530;
    return record;
}

/* Tile of a cell of the current selection's grid (0x118 when there is no grid). */
int SYMBOL_MAP_GetSelectedCellTile(void *gameSystem, int cellId)
{
    u8 *grid = SYMBOL_MAP_GetSelectionGrid(gameSystem);

    if (grid != 0)
        return SYMBOL_MAP_GetCellTileId(grid, (u8)(cellId + 1));
    return 0x118;
}

/* Neighbour of a cell in a direction, as a 0-based id (4 when there is no grid). */
int SYMBOL_MAP_GetSelectedNeighborCell(void *gameSystem, int cellId, int dir)
{
    u8 *grid = SYMBOL_MAP_GetSelectionGrid(gameSystem);

    if (grid != 0)
        return (u8)SYMBOL_MAP_GetNeighborCellId(grid, (u8)(cellId + 1), (u8)dir) - 1;
    return 4;
}

/*
 * Unlabelled leaf: true when the argument plus one, truncated to a byte,
 * is 1 (the home cell).
 */
int SYMBOL_MAP_IsHomeCell(int cellId)
{
    if ((u8)(cellId + 1) == 1)
        return 1;
    return 0;
}

/* True when the cell id plus one, truncated to a byte, is 5 (the blank cell). */
int SYMBOL_MAP_IsBlankCell(int cellId)
{
    if ((u8)(cellId + 1) == 5)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf (sole blocker of ov018 INTRUDE_FIELD_SpawnSymbolMons): true when the
 * argument plus one, truncated to a byte, is 2, 3 or 4 (a plain cell).
 * Twin of SYMBOL_MAP_IsHomeCell.
 */
int SYMBOL_MAP_IsPlainCell(int cellId)
{
    u8 internalId = cellId + 1;

    if ((u8)(internalId + 0xFE) <= 2)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf (no lr save) called from SYMBOL_MAP_ScrCmdGetEventStateValue case 4; 18 bytes
 * plus 2 bytes of alignment padding before SYMBOL_MAP_CreateRecordTask. Reads the u32 at
 * +0x14 of a 0x1C-byte entry, or 10 when there is no table.
 */
u32 SYMBOL_MAP_GetEventStateEntryValue(void *entries, u32 index)
{
    if (entries == 0)
        return 10;
    return ((EventStateEntry *)entries)[index].value;
}

/*
 * Creates the ov203 record task: it links a comm proc, remembers the
 * progress record and the completion flag, and copies the last result.
 */
void *SYMBOL_MAP_CreateRecordTask(void *gameSystem, void *progress, void *outCompleted) {
    struct GameEvent *task;
    SymbolMapRecordWork *work;
    task = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)SYMBOL_MAP_RecordTaskMain, 32);
    work = GAME_EVENT_GetWork((struct GameEvent *)task);
    work->progress = progress;
    work->outCompleted = outCompleted;
    EVENT_FIELD_PROCLINK_StartCommProc((struct CommProcParam *)work, gameSystem, 1, 0);
    work->lastResult = SYMBOL_MAP_GetLastResult(progress);
    return task;
}

void SYMBOL_MAP_DeleteLinkRecord(SymbolMapOwner *owner)
{
    if (owner->linkRecord != 0) {
        GFL_HEAP_Free(owner->linkRecord);
        owner->linkRecord = 0;
    }
}

/* Task main of SYMBOL_MAP_CreateRecordTask: runs ov203, then stores its result and the completion flag. */
int SYMBOL_MAP_RecordTaskMain(void *task, u32 *state)
{
    SymbolMapRecordWork *work = GAME_EVENT_GetWork(task);
    switch (*state) {
    case 0:
        GAME_EVENT_CallProc(task, (uptr)ov203_id, (void *)gDemo3dProcData, (void *)work);
        *state = *state + 1;
        break;
    case 1:
        if (work->resultCode == 2) *work->outCompleted = 1;
        else *work->outCompleted = 0;
        SYMBOL_MAP_StoreResult(work->progress, work->measuredValue);
        return 1;
    }
    return 0;
}

/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_MAP_GetLastResult.c \
 *       --func SYMBOL_MAP_GetLastResult --addr 0x0216670C --region ov010 --cc dsi/1.1p1 --thumb
 */
int SYMBOL_MAP_GetLastResult(void *progress) { return ((SymbolMapProgress *)progress)->lastResult; }

/* Stores a result and raises the best rank when the result / 1350 beats it. */
void SYMBOL_MAP_StoreResult(SymbolMapProgress *progress, int value) {
    int rank;
    progress->lastResult = value;
    rank = progress->lastResult / 1350;
    if (progress->bestRank <= rank) progress->bestRank = rank;
}

/*
 * Script command: queries the event state by sub-command (4..8, the
 * others answer 0) and writes the answer to a script variable.
 *
 * The five unlabelled leaf callees are filed as their own shards
 * (matched witnesses): SYMBOL_MAP_GetEventStateEntryValue.c, ov021_func_021C87A0.c,
 * PLEASURE_BOAT_GetPassengerType.c, PLEASURE_BOAT_GetPassengerExtra.c, PLEASURE_BOAT_GetPassengerOccupied.c.
 * (ov128_func_021C87A0.c is a different overlay's function at that
 * address; ov010 runs with ov021 loaded.)
 * lever (wave 82 R8): each arm writes the store `*(u16 *)a = ...` out
 *   itself, case 8 included (`if (...) *a = 1; else *a = 0;`). Cross-jumping
 *   then leaves cases 5-8 branching onto case 4's `b` and case 8's else as a
 *   dead `b` onto default. A shared `v` stored after the switch is 170 B
 *   (36 bytes out); with case 8's `else v = 0;` it is 172 B but DIFF21
 *   (a/p colours swapped, direct branches). An inline switch helper is the
 *   same DIFF21.
 */
int SYMBOL_MAP_ScrCmdGetEventStateValue(void *vm, void *work)
{
    void **eventState;
    u32 index;
    u16 subCommand;
    u32 index2;
    u16 *out;

    SCRCMD_WORK_GetScriptWork(work);
    eventState = GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(work)));
    index = SCRIPT_WORK_ReadWorkValue(vm, work);
    subCommand = VM_ReadU16(vm);
    index2 = SCRIPT_WORK_ReadWorkValue(vm, work);
    out = SCRIPT_WORK_ReadWorkPointer(vm, work);
    switch (subCommand) {
    case 4:
        *out = SYMBOL_MAP_GetEventStateEntryValue(*(void **)eventState, index);
        break;
    case 5:
        *out = PLEASURE_BOAT_GetPassengerParam(*(void **)eventState, index);
        break;
    case 6:
        *out = PLEASURE_BOAT_GetPassengerType(*(void **)eventState, index);
        break;
    case 7:
        *out = PLEASURE_BOAT_GetPassengerExtra(*(void **)eventState, index, index2);
        break;
    case 8:
        if (PLEASURE_BOAT_GetPassengerOccupied(*(void **)eventState, index) != 0)
            *out = 1;
        else
            *out = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    default:
        *out = 0;
        break;
    }
    return 0;
}

/*
 * Script command: starts the ov203 record task for the progress record in
 * the event state. The returned task remains live as SCRIPT_SYS_CallEvent's second
 * argument.
 */
int SYMBOL_MAP_ScrCmdStartRecordTask(void *vm, void *work)
{
    void *scriptSystem = SCRCMD_WORK_GetScriptWork(work);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    void **eventState;
    void *task;
    eventState = GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(gameSystem));
    task = SYMBOL_MAP_CreateRecordTask(gameSystem, *eventState, SCRIPT_WORK_ReadWorkPointer(vm, work));
    if (task == 0)
        return 1;
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/* Reads item `index` of the save sync block, or 0xB when out of range. */
int SYMBOL_MAP_GetSyncBlockItem(SaveSyncBlock *block, unsigned index)
{
    if (index >= block->count)
        return 0xb;
    return block->items[index];
}

/* Reads a header byte of the save sync block: 0 = count, 1 = type, 2 = variant. */
int SYMBOL_MAP_GetSyncBlockHeader(SaveSyncBlock *block, int sel)
{
    switch (sel) {
    case 0:
        return block->count;
    case 1:
        return block->type;
    case 2:
        return block->variant;
    }
    return 0;
}

/*
 * Creates the ov218 picker task: it copies the mode and the three output
 * pointers, then fills a 232-entry owned-flag table (+0x30) and a 20-entry
 * halfword table (+0x08) from the save object, zero padding the halfwords.
 */
void *SYMBOL_MAP_CreatePickerTask(void *gameSystem, int mode, u32 outKind, u32 outValue, u32 outPicked)
{
    struct GameEvent *task;
    SymbolMapPickerWork *work;
    struct SymbolMapSave *save;
    int i;
    int count;
    int flagIndex;

    task = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)SYMBOL_MAP_PickerTaskMain, 0x128);
    work = GAME_EVENT_GetWork((struct GameEvent *)task);
    work->mode = mode;
    work->outPicked = (u16 *)outPicked;
    work->outKind = (u16 *)outKind;
    work->outValue = (u16 *)outValue;
    save = (struct SymbolMapSave *)WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem)));
    for (i = 1; i < 0xE9; i++) {
        flagIndex = i - 1;
        if (WIFI_HISTORY_IsCountryVisited((struct WifiHistory *)save, i))
            work->ownedFlags[flagIndex] = 1;
        else
            work->ownedFlags[flagIndex] = 0;
    }
    count = WIFI_HISTORY_GetFirstFreeEntry((struct WifiHistory *)save);
    if (count > 20)
        count = 20;
    for (i = 0; i < count; i++)
        work->candidateIds[i] = MYSTATUS_GetNation((struct MyStatus *)WIFI_HISTORY_GetEntry((struct WifiHistory *)save, i));
    for (; i < 20; i++)
        work->candidateIds[i] = 0;
    return task;
}

/*
 * Former blocker: ABS32 for 0x000000DA (overlay id 218) and 0x021BAB5C (its callback table) have no
 * witness outside this function; GAME_EVENT_CallProc is not a listed overlay-id consumer and the
 * word is referenced only from this pool. Every concrete byte matches.
 *
 * 2026-10-05 (D8 lane 15): the callback table gUnSelectProcData lives in ov218 (loaded by this function); the data line now carries the ov218 token and the relocation resolves.
 */
int SYMBOL_MAP_PickerTaskMain(void *task, int *state)
{
    SymbolMapPickerWork *work = GAME_EVENT_GetWork(task);
    switch (*state) {
    case 0:
        GAME_EVENT_CallProc(task, (uptr)ov218_id, (void *)gUnSelectProcData, (void *)work);
        *state = *state + 1;
        break;
    case 1:
        if (work->resultCode == 1) {
            *work->outPicked = 1;
            *work->outKind = work->resultKind;
            *work->outValue = work->resultValue;
        } else {
            *work->outPicked = 0;
            *work->outKind = 0;
            *work->outValue = 0;
        }
        return 1;
    }
    return 0;
}

/*
 * Script command: reads item `index` (u8-truncated sub-command) of the save
 * sync block into a script variable.
 */
int SYMBOL_MAP_ScrCmdGetSyncBlockItem(void *vm, void *work)
{
    SaveSyncBlock *block;
    int index;
    void *gameData;
    u16 *out;

    SCRCMD_WORK_GetScriptWork(work);
    gameData = SCRCMD_WORK_GetGameSystem(work);
    gameData = GAMESYSTEM_GetGameData(gameData);
    block = (struct SaveSyncBlock *)GAME_DATA_GetSaveSyncBlock(gameData);
    index = (u8)VM_ReadU16(vm);
    out = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *out = SYMBOL_MAP_GetSyncBlockItem(block, index);
    return 0;
}

/* Script command: reads a header byte of the save sync block into a script variable. */
int SYMBOL_MAP_ScrCmdGetSyncBlockHeader(void *vm, void *work)
{
    void *gameData;
    u16 *out;
    int sel;
    SaveSyncBlock *block;

    SCRCMD_WORK_GetScriptWork(work);
    gameData = SCRCMD_WORK_GetGameSystem(work);
    gameData = GAMESYSTEM_GetGameData(gameData);
    block = (struct SaveSyncBlock *)GAME_DATA_GetSaveSyncBlock(gameData);
    sel = SCRIPT_WORK_ReadWorkValue(vm, work);
    out = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *out = SYMBOL_MAP_GetSyncBlockHeader(block, sel);
    return 0;
}

/*
 * Script command: starts the ov218 picker task (mode and three output
 * variables from the script).
 */
int SYMBOL_MAP_ScrCmdStartPicker(void *vm, void *work)
{
    void *scriptSystem = SCRCMD_WORK_GetScriptWork(work);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    int mode;
    unsigned short *outKind;
    unsigned short *outValue;
    unsigned short *outPicked;
    sptr task;
    GAME_DATA_GetSaveSyncBlock(GAMESYSTEM_GetGameData(gameSystem));
    mode = SCRIPT_WORK_ReadWorkValue(vm, work);
    outKind = SCRIPT_WORK_ReadWorkPointer(vm, work);
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, work);
    outPicked = SCRIPT_WORK_ReadWorkPointer(vm, work);
    task = (sptr)SYMBOL_MAP_CreatePickerTask(gameSystem, mode, (uptr)outKind, (uptr)outValue, (uptr)outPicked);
    if (task == 0)
        return 1;
    SCRIPT_SYS_CallEvent(scriptSystem, (void *)task);
    return 1;
}

/* Per-frame callback: during VBlank, grows the BG2 scale and rewrites the BG2 matrix. */
void SYMBOL_MAP_UpdateBg2Scale(void *unused)
{
    int fixedScale;
    MtxFx22 matrix;
    float scale;
    float rounded;
    float zero = 0.0f;
    if (*(volatile u16 *)REG_DISPSTAT_ADDR & 1) {
        scale = g_Bg2ScaleState[0] + g_Bg2ScaleStep;
        g_Bg2ScaleState[0] = scale;
        if (1.0f / scale > zero)
            rounded = 4096.0f * (1.0f / scale) + 0.5f;
        else
            rounded = 4096.0f * (1.0f / scale) - 0.5f;
        fixedScale = (int)rounded;
        MTX_Scale22_(&matrix, fixedScale, fixedScale);
        G2x_SetBGyAffine_(REG_BG2PA_ADDR, &matrix, 0x80, 0x5c, 0, 0);
    }
}

/*
 * Unlabelled leaf: stores 0x3F800000 and 0 into a two-word datum (scale
 * 1.0, unused 0), then tail-calls GFL_USE_SetVBlankHook(SYMBOL_MAP_UpdateBg2Scale, 0).
 */
void SYMBOL_MAP_StartBg2Scale(void)
{
    g_Bg2ScaleState[0] = 1.0f;
    g_Bg2ScaleState[1] = 0.0f;
    GFL_USE_SetVBlankHook(SYMBOL_MAP_UpdateBg2Scale, 0);
}

/* Resets the BG2 matrix to identity and stops the per-frame callback. */
void SYMBOL_MAP_StopBg2Scale(void) {
    MtxFx22 matrix;
    MTX_Identity22_(&matrix);
    G2x_SetBGyAffine_(REG_BG2PA_ADDR, &matrix, 128, 92, 0, 0);
    GFL_USE_ClearVBlankHook();
}

/*
 * Stage machine on *state, same family as ov002 EVENT_WIFIBATTLEMATCH_Main.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0xD7 (215), a linker overlay id for
 * ov215; the third, 0x021F7118, lies in its window. Skips straight to the
 * end unless the Pokemon is an egg that is not flagged invalid.
 */
u32 SYMBOL_MAP_PokeEventTaskMain(void *task, u32 *state, PokeEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = work->gameData;
    uptr transitionArg = work->transitionArg;

    switch (*state) {
    case 0:
        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)work->poke, 0x4C, 0) == 0 || POKE_TOOL_GetPartyValue((struct PokemonParam *)work->poke, 3, 0) == 1) {
            *state = 7;
        } else {
            *state = 1;
        }
        break;
    case 1:
        work->procParam.gameData = gameData;
        work->procParam.poke = work->poke;
        *state = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, (struct FieldMap *)transitionArg, 0, 0));
        *state = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, (struct FieldMap *)transitionArg));
        *state = 4;
        break;
    case 4:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov215_id, gEggDemoViewProcData, &work->procParam);
        *state = 5;
        break;
    case 5:
        GAME_EVENT_CallEvent(task, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        *state = 6;
        break;
    case 6:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (struct FieldMap *)transitionArg, 0, 0, 1, 0, 0));
        GAME_BEACON_SEARCH_SetSymbolMapPoke(POKE_TOOL_GetPartyValue((struct PokemonParam *)work->poke, 5, 0));
        *state = 7;
        break;
    case 7:
        return 1;
    }
    return 0;
}

/* Creates the ov215 task (see SYMBOL_MAP_PokeEventTaskMain). */
void *SYMBOL_MAP_CreatePokeEventTask(void *gameSystem, void *transitionArg, void *poke) {
    struct GameEvent *task;
    PokeEventWork *work;
    task = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)SYMBOL_MAP_PokeEventTaskMain, 24);
    work = GAME_EVENT_GetWork((struct GameEvent *)task);
    work->gameSystem = gameSystem;
    work->transitionArg = (uptr)transitionArg;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->poke = poke;
    return task;
}

/*
 * Maps a zone id to the zone it is shown as: the special location's zone
 * for zone 0x1A6, a table entry when the zone has one, else the zone
 * parent itself.
 *
 * stand-in: the goto and the word load plus u16 truncation of the table
 * entry are the only forms that give the original bytes; a break loop or
 * a halfword field access changes them.
 */
u32 SYMBOL_MAP_ResolveZoneId(void *gameData, u32 zoneId)
{
    u32 parentZone = ZONEDATA_GetParentZoneId(zoneId);
    u32 remapped;
    int i;
    if (parentZone == 0x1A6)
        return ZONEDATA_GetParentZoneId(GAME_DATA_GetSpecialLocation(gameData)->zoneId);
    for (i = 0; i < 2; i++) {
        if (g_ZoneRemapTable[i].source == parentZone) {
            remapped = (u16)*(u32 *)((char *)g_ZoneRemapTable + i * 8);
            goto done;
        }
    }
    remapped = 0xFFFF;
done:
    if (remapped != 0xFFFF)
        parentZone = (u16)remapped;
    return parentZone;
}

/*
 * Checks an event flag; 0xF000 asks whether the beacon trainer key is set
 * and 0xF001 whether the save object holds an entry, every other id is a
 * plain zone event flag.
 */
int SYMBOL_MAP_CheckEventFlag(void *gameData, u32 flagId)
{
    void *eventWork = (void *)GAME_DATA_GetEventWork(gameData);
    void *miscSave = GAME_DATA_GetMiscSave(gameData);
    void *myStatus = GAME_DATA_GetMyStatus(gameData);
    void *save;
    int result;
    save = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData));
    switch (flagId) {
    case 0xF000:
        return FIELD_G3D_MAP_CheckBeaconTrainerKey(miscSave, 1, myStatus);
    case 0xF001:
        result = 0;
        if (WIFI_HISTORY_GetDisplayCount(save, (struct MyStatus *)myStatus, 0) >= 1)
            result = 1;
        return result;
    }
    return ZONEDATA_CheckEventFlag(eventWork, flagId);
}

/*
 * Script command: reads a kind and three variable pointers, starts the
 * SYMBOL_MAP_PmsInputTaskMain task over a 0x1C-byte work, and for kinds 0..5 opens the
 * matching PMS input (PMSI_PARAM_Create), optionally filled with a sentence.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): byte-correct; the one
 * wildcard is the bl to arm9 0x02024108, a Thumb function (`ldrh r2, [r1]`
 * ...) with no witness outside this file (seed for the ARM9 session).
 */
int SYMBOL_MAP_ScrCmdStartPmsInput(void *vm, void *work)
{
    u8 sentenceBuf[8];
    u16 *outResult;
    u16 *outWord1;
    u16 *outWord0;
    void *gameSystem;
    void *gameData;
    void *scriptSystem;
    PmsInputWork *inputWork;
    struct GameEvent *task;
    u16 kind;
    u32 mode;

    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    gameData = SCRCMD_WORK_GetGameData(work);
    scriptSystem = SCRCMD_WORK_GetScriptWork(work);
    kind = SCRIPT_WORK_ReadWorkValue(vm, work);
    outWord0 = SCRIPT_WORK_ReadWorkPointer(vm, work);
    outWord1 = SCRIPT_WORK_ReadWorkPointer(vm, work);
    outResult = SCRIPT_WORK_ReadWorkPointer(vm, work);
    mode = 0;
    task = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)SYMBOL_MAP_PmsInputTaskMain, sizeof(PmsInputWork));
    inputWork = GAME_EVENT_GetWork((struct GameEvent *)task);
    MI_CpuFill8(inputWork, 0, sizeof(PmsInputWork));
    inputWork->kind = kind;
    inputWork->outWord0 = outWord0;
    inputWork->outWord1 = outWord1;
    inputWork->outResult = outResult;
    *outResult = 0;
    switch (kind) {
    case 0:
        inputWork->sentenceId = 1;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 1:
        inputWork->sentenceId = 2;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 2:
        inputWork->sentenceId = 3;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 3:
        inputWork->sentenceId = 4;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 4:
        inputWork->hasSentence = 0;
        break;
    case 5:
        inputWork->hasSentence = 0;
        mode = 1;
        break;
    default:
        inputWork->pmsParam = 0;
        SCRIPT_SYS_CallEvent(scriptSystem, task);
        return 1;
    }
    inputWork->pmsParam = PMSI_PARAM_Create(mode, 0, 0, 0, GAME_DATA_GetSaveControl(gameData), 1);
    if (inputWork->hasSentence) {
        GREETING_SAVEDATA_GetSentence((struct QuadRecord *)(GREETING_SAVEDATA_GetFromSave((uptr)GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem)))), inputWork->sentenceId, (struct QuadRecord *)sentenceBuf);
        PMSI_PARAM_SetSentence(inputWork->pmsParam, (struct PmsData *)sentenceBuf);
    }
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/*
 * Two-stage task: stage 0 starts an ov110 sub-task (pooled 0x6E is the
 * overlay id, 0x021C39B8 a table in its window) on the PMS parameter at +0x10;
 * stage 1 reads back its result by the kind at +0x00 into the u16 outputs
 * at +0x04/+0x08 and flags +0x0C, then frees the parameter.
 *
 * Byte-correct (lane B5, run 1).  7 of 14 sites unresolved, no C change helps:
 *   - ov110_id 0x6E: overlay_id refuses, GAME_EVENT_CallProc is not in
 *     OVERLAY_ID_CONSUMERS (it stores a1 in a descriptor for the state
 *     machine GAME_EVENT_CallProcSeq rather than passing it straight to a loader).
 *   - gPmsSelectProcData: with the ov110 token the hint is "contested" and no
 *     overlay_id site loads ov110; without it, "no witness".  Resolves once
 *     ov110_id does.
 *   - arm9 unlabelled leaves 0x0202411C, 0x02024124, 0x02024128,
 *     0x02024134 (a .word run in asm/arm9/main.s after PMSI_PARAM_Delete) and
 *     0x0200E714: no witness outside this range; each needs its own EXACT
 *     arm9 entry (matched class).
 * Same blocker family as SYMBOL_MAP_PickerTaskMain / SCRCMD_SYMBOL_ViewEventMain.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
u32 SYMBOL_MAP_PmsInputTaskMain(void *task, u32 *state)
{
    PmsInputWork *work = GAME_EVENT_GetWork(task);
    void *pmsParam = work->pmsParam;
    PmsInputWords words;
    PmsData sentence;
    u16 second;
    u16 result;

    switch (*state) {
    case 0:
        if (pmsParam == 0) {
            return 1;
        }
        GAME_EVENT_CallProc(task, (uptr)ov110_id, (void *)gPmsSelectProcData, (void *)pmsParam);
        (*state)++;
        break;
    case 1:
        if (PMSI_PARAM_CheckCanceled(pmsParam) != 0) {
            result = 0;
        } else {
            if (work->kind == 5) {
                PMSI_PARAM_GetWords(pmsParam, (u16 *)&words);
                *work->outWord0 = words.first;
                second = words.second;
            } else if (work->kind == 4) {
                *work->outWord0 = PMSI_PARAM_GetWord(pmsParam);
                second = 0;
            } else {
                PMSI_PARAM_GetSentence(pmsParam, &sentence);
                if (work->hasSentence != 0) {
                    GREETING_SAVEDATA_SetSentence((struct QuadRecord *)(GREETING_SAVEDATA_GetFromSave((uptr)GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(task))))), work->sentenceId, (struct QuadRecord *)((&sentence)));
                }
                *work->outWord0 = sentence.word[0];
                second = sentence.word[1];
            }
            *work->outWord1 = second;
            result = 1;
        }
        *work->outResult = result;
        PMSI_PARAM_Delete(work->pmsParam);
        return 1;
    }
    return 0;
}

/*
 * Script command: reads a sub-screen id (0xFFFF = default) and an enable
 * flag, calls one of two field map functions and sets the sub-screen mode.
 */
int SYMBOL_MAP_ScrCmdSetSubscreenMode(void *vm, void *work)
{
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    sptr fieldState;
    int modeId;
    int enable;
    SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    gameData = SCRCMD_WORK_GetGameData(work);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    fieldState = (sptr)FIELDMAP_GetWeather(fieldMap);
    modeId = SCRIPT_WORK_ReadWorkValue(vm, work);
    enable = SCRIPT_WORK_ReadWorkValue(vm, work);
    if (modeId == 0xFFFF)
        modeId = WEATHER_GetZoneWeatherId(gameSystem, FIELDMAP_GetZoneId(fieldMap));
    if (enable != 0)
        WEATHER_RequestChangeNoFade((struct WeatherSys *)fieldState, modeId);
    else
        WEATHER_RequestChange((struct WeatherSys *)fieldState, modeId);
    GAME_DATA_SetWeatherId(gameData, modeId & 0xff);
    return 0;
}
