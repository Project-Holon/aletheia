/*
 * file:     scrcmd_palpark.c
 * unit:     yes
 * function: SCRCMD_PALPARK_CallFallEvent, SCRCMD_PALPARK_CallPalParkProc, SCRCMD_PALPARK_GetSaveValue, SCRCMD_PALPARK_SetBeacon, SCRCMD_PALPARK_ClearExpiredGPower, SCRCMD_PALPARK_CallGPowerFlashEvent
 * address:  0x021CC544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): __FILE__ anchor 021CC5CC (d_021DE5A8 "scrcmd_palpark.c"); 021CC544 has the script-command (work, ctx) shape of 021CC6FC.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   NAMEIN_SETUP_StartFallEvent  0x0216C204  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FIELD_STATUS_CreateSubProcNoFadeCallbackEvent  0x02014840  thumb
 *   d_021DE5A8     0x021DE5A8  data
 *   ov107_id       0x0000006B  data
 *   d_021F6D78     0x021F6D78  data  ov107
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   MISC_GetRank  0x0200C1A4  thumb
 *   MISC_GetBestScore  0x0200C184  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_BEACON_SEARCH_SetItemFound  0x0216530C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetCountValue  0x02165534  thumb  ov010
 *   GAME_BEACON_SEARCH_SetFieldEvent  0x021653C4  thumb  ov010
 *   GAME_BEACON_SEARCH_SetSimpleEventA  0x021656A0  thumb  ov010
 *   GAME_BEACON_SEARCH_SetByteValue  0x021656D0  thumb  ov010
 *   GAME_BEACON_SEARCH_SetSimpleEventC  0x0216573C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetFacilityExit  0x02165604  thumb  ov010
 *   GAME_BEACON_SEARCH_SetWordValue  0x02165634  thumb  ov010
 *   GAME_BEACON_SEARCH_SetWordClear  0x0216566C  thumb  ov010
 *   GPOWER_GetExpiringPowerId  0x02010F18  thumb
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   GPOWER_ClearByPowerId  0x02010F40  thumb
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 *   GPOWER_EVENT_CreateFlashEvent  0x021F5340  thumb  ov083
 */
struct Ctx;
struct Big;
struct Blk34;

#include "../types.h"

/* Script virtual machine: the read pointer into the command stream. */
typedef struct ScriptVM {
    u8 pad0[0x14];
    u8 *pc;
} ScriptVM;

/* Parameter block of the ov107 Pal Park process (8 bytes). */
typedef struct PalParkProcParam {
    u8 result;
    void *gameData;
} PalParkProcParam;

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, char *site, unsigned short tag);
struct GameSystem;
extern void *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
struct GameSystem;
struct GameData;
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
struct ScrcmdWork;
struct ScriptWork;
extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *work);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *work);
struct FieldMap;
struct GameEvent;
extern struct GameEvent *NAMEIN_SETUP_StartFallEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern struct GameData *SCRCMD_WORK_GetGameData(struct ScrcmdWork *work);
extern void *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(char *gameSystem, int fieldMap, int overlayId, int procData, int procWork, int callback, int callbackWork);
struct ScriptVm;
extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct SaveControl;
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
struct MiscSave;
extern struct MiscSave *MISC_GetBlock(struct SaveControl *save);
extern u8 MISC_GetRank(struct MiscSave *beacon);
extern u32 MISC_GetBestScore(struct MiscSave *beacon);
extern unsigned int SCRIPT_WORK_ReadWorkValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void GAME_BEACON_SEARCH_SetItemFound(u32 itemNo);
extern void GAME_BEACON_SEARCH_SetCountValue(u32 count);
extern void GAME_BEACON_SEARCH_SetFieldEvent(void);
extern void GAME_BEACON_SEARCH_SetSimpleEventA(void);
extern void GAME_BEACON_SEARCH_SetByteValue(u8 a);
extern void GAME_BEACON_SEARCH_SetSimpleEventC(void);
extern void GAME_BEACON_SEARCH_SetFacilityExit(void);
extern void GAME_BEACON_SEARCH_SetWordValue(u32 value);
extern void GAME_BEACON_SEARCH_SetWordClear(void);
extern u8 GPOWER_GetExpiringPowerId(void);
struct GPowerData;
extern struct GPowerData *GPOWER_LoadPowerTable(u32 heap);
extern void GPOWER_ClearByPowerId(int powerId, struct GPowerData *table);
extern void GPOWER_FreePowerTable(struct GPowerData *table);
extern struct GameEvent *GPOWER_EVENT_CreateFlashEvent(struct GameSystem *gameSystem);

int SCRCMD_PALPARK_CallFallEvent(void *core, void *work);
int SCRCMD_PALPARK_CallPalParkProc(u32 core, u32 work);
int SCRCMD_PALPARK_GetSaveValue(ScriptVM *core, void *work);
int SCRCMD_PALPARK_SetBeacon(u32 core, u32 work);
int SCRCMD_PALPARK_ClearExpiredGPower(void *core, void *work);
int SCRCMD_PALPARK_CallGPowerFlashEvent(u32 unused, u32 work, u32 unused2, u32 unused3);

extern const char d_021DE5A8[];
extern const u8 ov107_id[];
extern u8 d_021F6D78[];

/* Script command: calls the event that ov010 NAMEIN_SETUP_StartFallEvent builds on the field map. */
int SCRCMD_PALPARK_CallFallEvent(void *core, void *work)
{
    void *script = SCRCMD_WORK_GetScriptWork(work);
    void *gsys = SCRCMD_WORK_GetGameSystem(work);
    SCRIPT_SYS_CallEvent(script, (void *)NAMEIN_SETUP_StartFallEvent((void *)gsys, (struct FieldMap *)GAMESYSTEM_GetFieldMap(gsys)));
    return 1;
}

/* Script command: runs the ov107 Pal Park process as a field sub-process. */
int SCRCMD_PALPARK_CallPalParkProc(u32 core, u32 work)
{
    void *script;
    void *gsys;
    void *gameData;
    void *fieldmap;
    PalParkProcParam *param;

    script = SCRCMD_WORK_GetScriptWork((void *)work);
    gsys = SCRCMD_WORK_GetGameSystem((void *)work);
    gameData = SCRCMD_WORK_GetGameData((void *)work);
    fieldmap = GAMESYSTEM_GetFieldMap((void *)gsys);
    param = GFL_HEAP_Alloc(4, 8, 0, (char *)d_021DE5A8, 0x44);
    param->result = 0;
    param->gameData = gameData;
    SCRIPT_SYS_CallEvent(script, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(gsys, (int)fieldmap, (u32)ov107_id, (int)d_021F6D78, (int)param, 0, (int)param));
    return 1;
}

/* Script command: mode byte, result variable; stores one of two values of a save block. */
int SCRCMD_PALPARK_GetSaveValue(ScriptVM *core, void *work)
{
    u8 mode;
    u16 *result;
    void *saveBlock;

    mode = *core->pc;
    core->pc++;
    result = SCRIPT_WORK_ReadWorkPointer((struct ScriptVm *)core, work);
    saveBlock = MISC_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(work)));
    switch (mode) {
    case 0:
        *result = MISC_GetRank(saveBlock);
        break;
    case 1:
        *result = MISC_GetBestScore(saveBlock);
        break;
    }
    return 0;
}

/*
 * Script command: sets one game beacon (kind 0..8) with one value.
 * GAMESYSTEM_GetGameData takes the SCRCMD_WORK_GetGameSystem result as its argument (r0 still
 * holds it at the bl), as at every other caller; the results are unused.
 */
int SCRCMD_PALPARK_SetBeacon(u32 core, u32 work)
{
    u32 kind;
    u32 value;
    void *gsys;

    kind = SCRIPT_WORK_ReadWorkValue((void *)core, (void *)work);
    value = SCRIPT_WORK_ReadWorkValue((void *)core, (void *)work);
    gsys = SCRCMD_WORK_GetGameSystem((void *)work);
    GAMESYSTEM_GetGameData(gsys);
    GAMESYSTEM_GetFieldMap((void *)gsys);
    SCRCMD_WORK_GetScriptWork((void *)work);
    switch (kind) {
    case 0:
        GAME_BEACON_SEARCH_SetItemFound((u32)value);
        break;
    case 1:
        GAME_BEACON_SEARCH_SetCountValue((u32)value);
        break;
    case 2:
        GAME_BEACON_SEARCH_SetFieldEvent();
        break;
    case 3:
        GAME_BEACON_SEARCH_SetSimpleEventA();
        break;
    case 4:
        GAME_BEACON_SEARCH_SetByteValue(value);
        break;
    case 5:
        GAME_BEACON_SEARCH_SetSimpleEventC();
        break;
    case 6:
        GAME_BEACON_SEARCH_SetFacilityExit();
        break;
    case 7:
        GAME_BEACON_SEARCH_SetWordValue((u32)value);
        break;
    case 8:
        GAME_BEACON_SEARCH_SetWordClear();
        break;
    }
    return 0;
}

/*
 * Script command: stores the expiring G power id (0x30 = none) and whether a
 * power is still active after that one is cleared.
 */
int SCRCMD_PALPARK_ClearExpiredGPower(void *core, void *work)
{
    u16 *powerId = SCRIPT_WORK_ReadWorkPointer(core, work);
    u16 *stillActive = SCRIPT_WORK_ReadWorkPointer(core, work);
    void *powerTable;

    *powerId = GPOWER_GetExpiringPowerId();
    if (*powerId != 0x30) {
        powerTable = GPOWER_LoadPowerTable(0x8015);
        GPOWER_ClearByPowerId(*powerId, powerTable);
        GPOWER_FreePowerTable(powerTable);
        *stillActive = (GPOWER_GetExpiringPowerId() != 0x30) ? 1 : 0;
    } else {
        *stillActive = 0;
    }
    return 0;
}

/* Script command: calls the event that ov083 GPOWER_EVENT_CreateFlashEvent builds. */
int SCRCMD_PALPARK_CallGPowerFlashEvent(u32 unused, u32 work, u32 unused2, u32 unused3)
{
    SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork((void *)work), GPOWER_EVENT_CreateFlashEvent(SCRCMD_WORK_GetGameSystem((void *)work)));
    return 1;
}
