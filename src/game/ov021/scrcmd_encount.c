/*
 * file:     scrcmd_encount.c
 * unit:     yes
 * function: SCRCMD_PROC_FLD_StoreRandomUniqueEntry, SCRCMD_PROC_FLD_RestoreCamera, SCRCMD_PROC_FLD_RestoreCameraTask, SCRCMD_PROC_FLD_SaveCamera, SCRCMD_PROC_FLD_RestoreCameraCmd, SCRCMD_PROC_FLD_StopCameraTargetTrace, SCRCMD_PROC_FLD_ResumeCameraTargetTrace, SCRCMD_PROC_FLD_StartCameraMoveFromStream, SCRCMD_PROC_FLD_StartCameraMoveFromArchive, SCRCMD_PROC_FLD_StartCameraMoveToSaved, SCRCMD_PROC_FLD_StartCameraMoveToSetting, SCRCMD_PROC_FLD_WaitCameraIdle, SCRCMD_PROC_FLD_StartCameraShake, SCRCMD_PROC_FLD_PollCameraSaveReady, SCRCMD_PROC_FLD_PollCameraIdle, SCRCMD_PROC_FLD_CallOv056Event, SCRCMD_PROC_FLD_SetCameraSettingFromFkDemoSlot, SCRCMD_PROC_FLD_StartFkDemoSubProc
 * address:  0x021B51BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_proc_fld.c by tools/splitfile.py.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELD_ENCOUNT_ST_LoadEncountData  0x0215E2B8  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   d_021DE234     0x021DE234  data  a1
 *   d_021D98D0     0x021D98D0  data  a2
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FIELD_CAMERA_StartMoveToSetting  0x0218FA40  thumb  ov021
 *   FIELD_CAMERA_CreateShakeTask  0x021D2D50  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELD_FK_DEMO_StartEvent  0x021F36C0  thumb  ov056
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   FIELD_FK_DEMO_GetCameraSettingId  0x021F36C8  thumb  ov056
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   ov56_id        0x00000038  data  a1
 *   g_021F4344     0x021F4344  data  ov056  a4
 *   g_021F4374     0x021F4374  data  ov056  a4
 *   g_021F438C     0x021F438C  data  ov056  a4
 *   g_021F435C     0x021F435C  data  ov056  a4
 *   SCRCMD_PROC_FLD_AddUniqueU16 0x021B5190 thumb ov021
 */
#include "scrcmd_proc_fld_types.h"
#include "fieldmap_types.h"
#include "scrcmd_proc_fld_shared_types.h"

struct Blk021D2D50;

/* One wild encounter entry: species and form in 4 bytes. */
typedef struct EncounterSlot {
    u16 species : 11;
    u16 form : 5;
    u16 reserved;
} EncounterSlot;

/* 0xE8-byte encounter table record filled by FIELD_ENCOUNT_ST_LoadEncountData. */
typedef struct EncounterRecord {
    u8  reserved00[5];
    u8  hasSetA;
    u8  hasSetB;
    u8  reserved07[0xc0 - 7];
    EncounterSlot setA[5];
    EncounterSlot setB[5];
} EncounterRecord;

/* Field region record read from archive 0xA3 (0x2C bytes). */
typedef struct FieldRegionRecord {
    u16 areaWidth;
    u16 areaHeight;
    u32 areaFlags;
    VecFx32 origin;
    LayerFlags layers;
} FieldRegionRecord;

/* Field region parameter block (0x48 bytes) handed to the field region object. */
typedef struct FieldRegionParam {
    u32 reserved00[3];
    VecFx32 origin;         /* 0x0c */
    u32 reserved18[3];
    u16 areaWidth;          /* 0x24 */
    u16 areaHeight;         /* 0x26 */
    u32 areaFlags;          /* 0x28 */
    u32 reserved2C;
    LayerFlags layers;      /* 0x30: six layer enable flags */
} FieldRegionParam;

/* Custom event record built from eight script values. */
typedef struct CustomEventParam {
    u16 eventId;            /* 0x00 */
    u16 eventKind;          /* 0x02 */
    u16 mapX;               /* 0x04 */
    u16 mapY;               /* 0x06 */
    u16 mapZ;               /* 0x08 */
    u16 reserved0A;         /* 0x0a */
    u16 facing;             /* 0x0c */
    u8 kind;                /* 0x0e */
    u8 kindCopy;            /* 0x0f */
    u32 scriptId;           /* 0x10 */
    u32 reserved14;         /* 0x14 */
} CustomEventParam;

typedef enum { B_FALSE, B_TRUE } Bool;
struct ScrcmdWork;
struct ScriptWork;

#include "../ov010/scrcmd_work.h"
struct GameSystem;


#include "../arm9/gamesystem.h"
struct FieldMap;
struct FieldCamera;

#include "fieldmap.h"

extern void FIELD_CAMERA_EndDelay(struct FieldCamera *camera);

extern u32 FIELD_CAMERA_IsDelayEnabled(struct FieldCamera *camera);

extern int FIELD_CAMERA_IsMoving(struct FieldCamera *camera);
struct FieldCameraMoveChannels;

extern void FIELD_CAMERA_StartMoveToSaved(struct FieldCamera *camera, struct FieldCameraMoveChannels *channels, u16 frames);

extern void FIELD_CAMERA_ResumeTargetTrace(struct FieldCamera *camera);

extern void FIELD_CAMERA_RestartDelay(struct FieldCamera *camera);

extern void FIELD_CAMERA_PopState(struct FieldCamera *camera);

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"

struct ScriptVm;

#include "../ov010/script_work_cmd.h"
struct GameData;


#include "../ov010/script_sys.h"



extern int FIELD_ENCOUNT_ST_LoadEncountData(EncounterRecord *r, void *h, u32 k, u32 x);

#include "../arm9/game_data.h"
#include "../arm9/vm.h"
#include "../ov056/field_fk_demo.h"

#include "../arm9/gfl_use.h"

#include "../ov010/script_work.h"



extern int FIELD_CAMERA_HasDelay(struct FieldCamera *camera);

#include "field_nogrid_mapper.h"


#include "../arm9/game_event.h"

extern void FIELD_CAMERA_PushState(struct FieldCamera *camera);

extern void FIELD_CAMERA_StopTargetTrace(struct FieldCamera *camera);



extern void FIELD_CAMERA_StartMove(u8 *a, void *p, int n);


extern void FIELD_CAMERA_StartMoveToSetting(struct FieldCamera *camera, u16 frames);
struct CameraShakeParams;
struct GameEvent;

#include "scrcmd_misc.h"




extern void FIELD_CAMERA_SetSetting(struct FieldCamera *camera, u32 settingId);
struct FieldmapFunc;

struct FieldSubprocTemplate;
struct FieldSubprocMgr;
struct FieldSubproc;

#include "fieldmap_func.h"

#include "scrcmd_proc_fld.h"

int SCRCMD_PROC_FLD_StoreRandomUniqueEntry(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void SCRCMD_PROC_FLD_RestoreCamera(void *fieldMap, void *fieldRegion);

int SCRCMD_PROC_FLD_RestoreCameraTask(void **eventWork);

int SCRCMD_PROC_FLD_SaveCamera(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_RestoreCameraCmd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StopCameraTargetTrace(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_ResumeCameraTargetTrace(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartCameraMoveFromStream(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartCameraMoveFromArchive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartCameraMoveToSaved(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartCameraMoveToSetting(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_WaitCameraIdle(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartCameraShake(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_PollCameraSaveReady(void *event);

int SCRCMD_PROC_FLD_PollCameraIdle(void *event);

int SCRCMD_PROC_FLD_CallOv056Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_SetCameraSettingFromFkDemoSlot(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartFkDemoSubProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

extern const char d_021DE234[];

extern const u16 d_021D98D0[];

extern u8 ov56_id[];

extern u32 g_021F4344[];

extern u32 g_021F4374[];

extern u32 g_021F438C[];

extern u32 g_021F435C[];

/*
 * FIELD_ENCOUNT_ST_LoadEncountData clears and fills a 0xE8-byte record (its own memset size).
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_StoreRandomUniqueEntry(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    EncounterRecord record;
    u32 season;
    u16 tableIndex;
    void *archive;
    u16 *resultVar;
    void *gameData;
    u16 *speciesList;
    u16 slot;
    u16 count;

    count = 0;
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    season = GAME_DATA_GetSeason(gameData);
    archive = ARC_TOOL_CreateHandle(0x7e, 0x8015);
    speciesList = GFL_HEAP_Alloc(0x8015, 0x78, 1, d_021DE234, 0xf8);
    for (tableIndex = 0; tableIndex < 6; tableIndex++) {
        if (FIELD_ENCOUNT_ST_LoadEncountData(&record, archive, d_021D98D0[tableIndex], season)) {
            if (record.hasSetA) {
                for (slot = 0; slot < 5; slot++) {
                    count = SCRCMD_PROC_FLD_AddUniqueU16(speciesList, count, record.setA[slot].species);
                }
            }
            if (record.hasSetB) {
                for (slot = 0; slot < 5; slot++) {
                    count = SCRCMD_PROC_FLD_AddUniqueU16(speciesList, count, record.setB[slot].species);
                }
            }
        }
    }
    *resultVar = speciesList[GFL_USE_GetRandomBelow(count)];
    GFL_HEAP_Free(speciesList);
    ARC_TOOL_DeleteHandle(archive);
    return 0;
}

void SCRCMD_PROC_FLD_RestoreCamera(void *fieldMap, void *fieldRegion)
{
FIELD_CAMERA_PopState(fieldRegion);
if (FIELD_CAMERA_HasDelay(fieldRegion) != 0) {
    FIELD_CAMERA_RestartDelay(fieldRegion);
}
if (FIELDMAP_GetMoveKind(fieldMap) == 1) {
    FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(fieldMap), 1);
}
SCRIPT_WORK_ResetCheckFlag(0);
}

int SCRCMD_PROC_FLD_RestoreCameraTask(void **eventWork)
{
    void *fieldMap = GAMESYSTEM_GetFieldMap(eventWork[0]);

    SCRCMD_PROC_FLD_RestoreCamera(fieldMap, FIELDMAP_GetCamera(fieldMap));
    return 1;
}

int SCRCMD_PROC_FLD_SaveCamera(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *fieldMap;
    void *fieldRegion;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    fieldRegion = FIELDMAP_GetCamera(fieldMap);
    SCRIPT_WORK_SetCheckFlag(0);
    if (FIELD_CAMERA_HasDelay(fieldRegion) != 0) {
        FIELD_CAMERA_EndDelay(fieldRegion);
        fieldRegion = SCRCMD_WORK_GetScriptWork(cmdWork);
        SCRIPT_SYS_CallEvent(fieldRegion, GAME_EVENT_Create(gameSystem, 0, (void *)SCRCMD_PROC_FLD_PollCameraSaveReady, 0));
        if (FIELDMAP_GetMoveKind(fieldMap) == 1) {
            FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(fieldMap), 0);
        }
    } else {
        FIELD_CAMERA_PushState(fieldRegion);
    }
    return 1;
}

int SCRCMD_PROC_FLD_RestoreCameraCmd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));

    SCRCMD_PROC_FLD_RestoreCamera(fieldMap, FIELDMAP_GetCamera(fieldMap));
    return 0;
}

int SCRCMD_PROC_FLD_StopCameraTargetTrace(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
FIELD_CAMERA_StopTargetTrace(FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))));
return 0;
}

int SCRCMD_PROC_FLD_ResumeCameraTargetTrace(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
FIELD_CAMERA_ResumeTargetTrace((struct FieldCamera *)FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))));
return 0;
}

int SCRCMD_PROC_FLD_StartCameraMoveFromStream(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldRegionParam param;
    void *fieldRegion;

    fieldRegion = FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    param.areaWidth = VM_ReadU16(vm);
    param.areaHeight = VM_ReadU16(vm);
    param.areaFlags = VM_GetU32(vm);
    param.origin.x = VM_GetU32(vm);
    param.origin.y = VM_GetU32(vm);
    param.origin.z = VM_GetU32(vm);
    param.layers.flag[0] = 0;
    param.layers.flag[1] = 1;
    param.layers.flag[2] = 1;
    param.layers.flag[3] = 1;
    param.layers.flag[4] = 0;
    param.layers.flag[5] = 1;
    FIELD_CAMERA_StartMove(fieldRegion, &param, VM_ReadU16(vm));
    return 0;
}

int SCRCMD_PROC_FLD_StartCameraMoveFromArchive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldRegionRecord record;
    FieldRegionParam param;
    void *fieldRegion;
    int memberIndex;
    int regionIndex;

    fieldRegion = FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    memberIndex = VM_ReadU16(vm);
    regionIndex = VM_ReadU16(vm);
    ARC_TOOL_ReadMember(&record, 0xa3, memberIndex);
    param.areaWidth = record.areaWidth;
    param.areaHeight = record.areaHeight;
    param.areaFlags = record.areaFlags;
    param.origin = record.origin;
    param.layers = record.layers;
    FIELD_CAMERA_StartMove(fieldRegion, &param, regionIndex);
    return 0;
}

int SCRCMD_PROC_FLD_StartCameraMoveToSaved(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    LayerFlags layers;
    void *fieldRegion = FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    u16 regionIndex = VM_ReadU16(vm);

    layers.flag[0] = 1;
    layers.flag[1] = 1;
    layers.flag[2] = 1;
    layers.flag[3] = 1;
    layers.flag[4] = 1;
    layers.flag[5] = 1;
    FIELD_CAMERA_StartMoveToSaved(fieldRegion, (struct FieldCameraMoveChannels *)&layers, regionIndex);
    return 0;
}

int SCRCMD_PROC_FLD_StartCameraMoveToSetting(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
FIELD_CAMERA_StartMoveToSetting(FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), VM_ReadU16(vm));
return 0;
}

int SCRCMD_PROC_FLD_WaitCameraIdle(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)SCRCMD_PROC_FLD_PollCameraIdle, 0));
    return 1;
}

int SCRCMD_PROC_FLD_StartCameraShake(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int eventId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int eventKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int scriptId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int kind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int mapX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int mapY = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int mapZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int facing = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *scriptWork;
    void *gameSystem;
    CustomEventParam param;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    param.eventId = eventId;
    param.eventKind = eventKind;
    param.scriptId = scriptId;
    param.kindCopy = kind;
    param.kind = kind;
    param.reserved14 = 0;
    param.mapX = mapX;
    param.mapY = mapY;
    param.mapZ = mapZ;
    param.reserved0A = 0;
    param.facing = facing;
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_CAMERA_CreateShakeTask(gameSystem, (struct CameraShakeParams *)(&param)));
    return 1;
}

int SCRCMD_PROC_FLD_PollCameraSaveReady(void *event)
{
    u8 *fieldRegion = (u8 *)FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event)));

    if (FIELD_CAMERA_IsDelayEnabled((struct FieldCamera *)fieldRegion) == 0) {
        FIELD_CAMERA_PushState((struct FieldCamera *)fieldRegion);
        return 1;
    }
    return 0;
}

int SCRCMD_PROC_FLD_PollCameraIdle(void *event)
{
    int busy = FIELD_CAMERA_IsMoving(FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event))));

    return busy != 0 ? B_FALSE : B_TRUE;
}

int SCRCMD_PROC_FLD_CallOv056Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    unsigned int slotNumber = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, FIELD_FK_DEMO_StartEvent(gameSystem, (struct FieldMap *)fieldMap, (u16)(slotNumber - 1)));
    return 1;
}

/*
 * FIELD_FK_DEMO_GetCameraSettingId is the ov056 slot-table lookup (src/matched/ov/FIELD_FK_DEMO_GetCameraSettingId.c).
 */
int SCRCMD_PROC_FLD_SetCameraSettingFromFkDemoSlot(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    unsigned int slotNumber = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 *fieldRegion = (u32 *)FIELDMAP_GetCamera(fieldMap);

    FIELD_CAMERA_SetSetting((struct FieldCamera *)fieldRegion, FIELD_FK_DEMO_GetCameraSettingId((u16)(slotNumber - 1)));
    return 0;
}

int SCRCMD_PROC_FLD_StartFkDemoSubProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int regionTable = (sptr)FIELDMAP_GetMapFunc(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));

    switch (SCRIPT_WORK_ReadWorkValue(vm, cmdWork)) {
    case 0:
        break;
    case 1:
        FIELD_SUBPROC_Start((sptr)ov56_id, (struct FieldSubprocMgr *)regionTable, (struct FieldSubprocTemplate *)g_021F4344);
        break;
    case 2:
        FIELD_SUBPROC_Start((sptr)ov56_id, (struct FieldSubprocMgr *)regionTable, (struct FieldSubprocTemplate *)g_021F4374);
        break;
    case 3:
        FIELD_SUBPROC_Start((sptr)ov56_id, (struct FieldSubprocMgr *)regionTable, (struct FieldSubprocTemplate *)g_021F438C);
        break;
    case 4:
        FIELD_SUBPROC_Start((sptr)ov56_id, (struct FieldSubprocMgr *)regionTable, (struct FieldSubprocTemplate *)g_021F435C);
        break;
    }
    return 0;
}
