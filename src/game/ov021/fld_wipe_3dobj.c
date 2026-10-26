/*
 * file:     fld_wipe_3dobj.c
 * unit:     yes
 * function: FLD_WIPE_3DOBJ_Create, FLD_WIPE_3DOBJ_Delete, FLD_WIPE_3DOBJ_Draw, SCRCMD_StartFld3dCi, SCRCMD_StartFld3dCiByVar, SCRCMD_RunFld3dCiMain, SCRCMD_StartFld3dCiByTable, FLD_WIPE_3DOBJ_CreateMapChangeEvent, FLD_WIPE_3DOBJ_MapChangeEventMain, FLD_WIPE_3DOBJ_FadeOutEventMain
 * address:  0x021C8018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_flash.c, pleasure_boat.c by tools/splitfile.py.
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FADE_Start  0x0204E720  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   gFldWipe3dObjFileName  0x021DE520  data  ov021  a4
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_GetLookAt  0x02046AFC  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   MI_Copy36B  0x02082B60  arm
 *   G3D_SYSTEM_GetRenderObj  0x0204755C  arm
 *   NNS_G3dMdlSetMdlLightEnableFlag  0x0206E394  arm
 *   NNS_G3dMdlSetMdlPolygonID  0x0206E4FC  arm
 *   NNS_G3dMdlSetMdlCullMode  0x0206E484  arm
 *   NNS_G3dMdlSetMdlAlpha  0x0206E574  arm
 *   NNS_G3dMdlSetMdlPolygonMode  0x0206E40C  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLD3D_CI_StartSequence  0x021C1CB0  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLD3D_CI_StartPartyMemberSequence  0x021C1D68  thumb  ov021
 *   FLD3D_CI_StartMessageSequence  0x021C30B8  thumb  ov021
 *   gFld3dCiKeyTable     0x021DAAE0  data  a2
 *   gFld3dCiIdTable     0x021DAAE2  data  a2
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   FIELD_CAMERA_PushStateConstrained  0x0218F848  thumb  ov021
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent  0x021BEA30  thumb  ov021
 *   EVENT_MAPCHANGE_CreateWarpEventToLocation  0x021854CC  thumb  ov020
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   FIELD_PLACE_NAME_ShowForZone  0x021BC578  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FADE_IsActive  0x0204E804  arm
 */
#include "field_flash_shared_types.h"
#include "../arm9/g3d_system.h"
#include "../arm9/game_event.h"
#include "../arm9/mi_memory.h"
#include "../arm9/g3d_system_types.h"
#include "fld_wipe_3dobj_shared_types.h"


typedef struct ScriptSystem ScriptSystem;


typedef struct MyStatus MyStatus;

/* Wipe event work (wipe with a 3D cut-in and a map change). */
typedef struct CameraAnimFlags {
    u32 apply[6];
} CameraAnimFlags;

typedef struct CameraAnimParam {
    u32 padding0[3];
    VecFx32 targetPos;
    VecFx32 targetOffset;
    u16 pitch;
    u16 yaw;
    u32 distance;
    u16 fovy;
    u16 pad2E;
    CameraAnimFlags flags;
} CameraAnimParam;

typedef struct WipeMapChangeWork {
    GameSystem *gameSystem;
    const VecFx32 *savedCameraTarget;
    u32 zoneId;
    Location startLocation;
    u32 cutInIdBefore;
    u32 cutInIdAfter;
} WipeMapChangeWork;

#include "fieldmap.h"


#include "field_player.h"

#include "../ov010/fldmmdl.h"


#include "../arm9/fade.h"

#include "../arm9/fx_vec.h"

#include "../arm9/gfl_heap_wrap.h"


struct G3dResource;

struct G3dRender;

struct G3dAnime;
struct G3dObject;








#include "../arm9/nns_g3d_glb.h"



struct ResMdl;
extern void NNS_G3dMdlSetMdlLightEnableFlag(struct ResMdl *mdl, u32 a, u32 b);
extern void NNS_G3dMdlSetMdlPolygonID(struct ResMdl *mdl, u32 a, u32 b);
extern void NNS_G3dMdlSetMdlCullMode(struct ResMdl *mdl, u32 a, u32 b);
extern void NNS_G3dMdlSetMdlAlpha(struct ResMdl *mdl, u32 a, u32 b);
extern void NNS_G3dMdlSetMdlPolygonMode(struct ResMdl *mdl, u32 a, u32 b);

struct ScrcmdWork;
struct GameSystem;

#include "../ov010/scrcmd_work.h"

#include "../arm9/gamesystem.h"


#include "../arm9/vm.h"
struct ScriptWork;


#include "fld3d_ci.h"

#include "../ov010/script_sys.h"
struct ScriptVm;

#include "../ov010/script_work_cmd.h"




struct GameData;


#include "../arm9/game_data.h"

#include "../arm9/mystatus.h"
struct Location;

#include "../arm9/zonedata.h"
struct FieldMap;
struct FieldNogridMapper;


#include "field_camera.h"
struct FieldCamera;




#include "field_nogrid_mapper.h"



struct FieldCameraMoveRequest;
struct FieldCamera;






struct Mmdl;


struct GameEvent;

#include "event_fieldmap_control.h"

/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define EVENT_MAPCHANGE_CreateWarpEventToLocation EVENT_MAPCHANGE_CreateWarpEventToLocation_header
#endif
#include "../ov020/event_mapchange.h"
#ifdef __MWERKS__
#undef EVENT_MAPCHANGE_CreateWarpEventToLocation
extern GameEvent * EVENT_MAPCHANGE_CreateWarpEventToLocation(GameSystem *, FieldMap *, u16, const Location *, u16);
#endif
struct FieldPlaceName;


#include "field_place_name.h"

#include "../arm9/bg_sys.h"




struct FieldCameraMoveChannels;






extern char gFldWipe3dObjFileName[];

extern unsigned short gFld3dCiKeyTable[];

extern unsigned short gFld3dCiIdTable[];

FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId);

int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj);

void FLD_WIPE_3DOBJ_Draw(FldWipe3dObj *obj, int size, int alpha);

int SCRCMD_StartFld3dCi(ScriptVm *vm, ScrCmdWork *work);

int SCRCMD_StartFld3dCiByVar(ScriptVm *vm, ScrCmdWork *work);

int SCRCMD_RunFld3dCiMain(ScriptVm *vm, ScrCmdWork *work);

int SCRCMD_StartFld3dCiByTable(ScriptVm *vm, ScrCmdWork *work);

GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId);

int FLD_WIPE_3DOBJ_MapChangeEventMain(struct GameEvent *event, int *seq, void *work);

int FLD_WIPE_3DOBJ_FadeOutEventMain(struct GameEvent *event, int *seq, void *work);

FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId)
{
    FldWipe3dObj *obj = GFL_HEAP_Alloc(heapId, sizeof(FldWipe3dObj), 1, gFldWipe3dObjFileName, 0x24);
    obj->resArc = G3D_SYSTEM_CreateResourceArc(0x4a, 0);
    obj->object = G3D_SYSTEM_CreateObject(G3D_SYSTEM_CreateRender(obj->resArc, 0, 0), 0, 0);
    return obj;
}

int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj)
{
    G3D_SYSTEM_DeleteRender(G3D_SYSTEM_GetObjectRender(obj->object));
    G3D_SYSTEM_DeleteObject(obj->object);
    G3D_SYSTEM_DeleteResource(obj->resArc);
    return GFL_HEAP_Free(obj);
}

/* Draws the mask model as a camera-facing billboard of the given size and alpha. */
void FLD_WIPE_3DOBJ_Draw(FldWipe3dObj *obj, int size, int alpha)
{
    G3dObjectStatus status;
    G3dLookAt lookAt;
    VecFx32 viewDir;
    int viewY;
    void *mdl;
    if (size == 0) {
        return;
    }
    G3D_SYSTEM_GetLookAt(&lookAt);
    status.trans = lookAt.camPos;
    VEC_Subtract(&lookAt.target, &lookAt.camPos, &viewDir);
    VEC_Normalize(&viewDir, &viewDir);
    viewY = viewDir.y;
    if (viewY <= 0) {
        viewY = -viewY;
    }
    status.scale.x = size;
    status.scale.y = (int)(((long long)size * viewY + 0x800) >> 12);
    status.scale.z = 0x4000;
    MI_Copy36B(NNS_G3dGlbGetInvCameraMtx(), &status.rotate);
    mdl = (void *)G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(obj->object))->resMdl;
    NNS_G3dMdlSetMdlLightEnableFlag(mdl, 0, 0);
    NNS_G3dMdlSetMdlPolygonID(mdl, 0, 0);
    NNS_G3dMdlSetMdlCullMode(mdl, 0, 2);
    NNS_G3dMdlSetMdlAlpha(mdl, 0, alpha);
    NNS_G3dMdlSetMdlPolygonMode(mdl, 0, 0);
    G3D_SYSTEM_DrawObject(obj->object, &status);
}

/* Script command: start the FLD3D_CI sequence whose id is the next script halfword. */
int SCRCMD_StartFld3dCi(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int ciId;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work);
    ci = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(gameSystem));
    ciId = VM_ReadU16(vm);
    scriptSys = (struct ScriptSystem *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
    event = FLD3D_CI_StartSequence(gameSystem, ci, (unsigned char)ciId);
    if (event) {
        SCRIPT_SYS_CallEvent(scriptSys, event);
    }
    return 1;
}

/* Script command: start the FLD3D_CI sequence whose id is read from a script value. */
int SCRCMD_StartFld3dCiByVar(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int ciId;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work);
    ci = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(gameSystem));
    ciId = SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)work);
    scriptSys = (struct ScriptSystem *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
    event = FLD3D_CI_StartPartyMemberSequence(gameSystem, ci, (unsigned char)ciId);
    if (event) {
        SCRIPT_SYS_CallEvent(scriptSys, event);
    }
    return 1;
}

/* Script command: run the FLD3D_CI main function with a script value. */
int SCRCMD_RunFld3dCiMain(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int value;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work);
    ci = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(gameSystem));
    value = (int)SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)work);
    scriptSys = (struct ScriptSystem *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
    event = FLD3D_CI_StartMessageSequence(gameSystem, ci, value);
    if (event) {
        SCRIPT_SYS_CallEvent(scriptSys, event);
    }
    return 1;
}

/* Script command: map a script value through the 17-entry key table to a FLD3D_CI id and start it. */
int SCRCMD_StartFld3dCiByTable(ScriptVm *vm, ScrCmdWork *work)
{
    GameSystem *gameSystem;
    Fld3dCi *ci;
    int value;
    int found;
    int i;
    ScriptSystem *scriptSys;
    unsigned short ciId;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work);
    ci = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(gameSystem));
    value = (int)SCRIPT_WORK_ReadWorkValue(vm, (struct ScrcmdWork *)work);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (value == gFld3dCiKeyTable[i * 2]) {
            found = 1;
            ciId = gFld3dCiIdTable[i * 2];
            break;
        }
    }
    if (found) {
        scriptSys = (struct ScriptSystem *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
        event = FLD3D_CI_StartSequence(gameSystem, ci, (unsigned char)ciId);
        if (event) {
            SCRIPT_SYS_CallEvent(scriptSys, event);
        }
    }
    return 1;
}

/* Creates the wipe event: picks the two FLD3D_CI ids by player outfit and remembers the destination zone. */
GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId)
{
    GameEvent *event;
    WipeMapChangeWork *work;
    int cutInIdAfter;
    event = GAME_EVENT_Create(gameSystem, 0, FLD_WIPE_3DOBJ_MapChangeEventMain, sizeof(WipeMapChangeWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(*work));
    work->gameSystem = gameSystem;
    work->zoneId = zoneId;
    if (MYSTATUS_GetSex(GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(gameSystem))) == 0) {
        work->cutInIdBefore = 11;
        cutInIdAfter = 12;
    } else {
        work->cutInIdBefore = 18;
        cutInIdAfter = 19;
    }
    work->cutInIdAfter = cutInIdAfter;
    ZONEDATA_SetZoneStartLocation(&work->startLocation, (unsigned short)zoneId);
    return event;
}

/* Wipe event: camera swing and FLD3D_CI cut-in, map change, then the reverse cut-in. */
int FLD_WIPE_3DOBJ_MapChangeEventMain(struct GameEvent *event, int *seq, void *workPtr)
{
    WipeMapChangeWork *work = workPtr;
    FieldMap *fieldMap;
    FieldCamera *camera;
    Fld3dCi *ci;
    struct FieldNogridMapper *bg;
    GameEvent *child;
    void *msgBg;
    u32 visiblePlanes;
    Mmdl *mmdl;
    CameraAnimParam firstCameraParam;
    CameraAnimParam secondCameraParam;
    VecFx32 playerPos1;
    VecFx32 playerPos2;
    CameraAnimFlags flags;
    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSystem);
    camera = FIELDMAP_GetCamera(fieldMap);
    ci = FIELDMAP_GetFld3dCi(fieldMap);
    bg = FIELDMAP_GetNogridMapper(fieldMap);
    switch (*seq) {
    case 0:
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
        work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 1:
        if (work->savedCameraTarget != 0 && FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive((struct FieldNogridMapper *)bg, 0);
        FIELD_CAMERA_StopTargetTrace(camera);
        FIELD_CAMERA_PushState(camera);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos1);
        firstCameraParam.pitch = 0x25d8;
        firstCameraParam.yaw = 0;
        firstCameraParam.distance = 0xed000;
        firstCameraParam.targetOffset.x = 0;
        firstCameraParam.targetOffset.y = 0x4000;
        firstCameraParam.targetOffset.z = 0;
        firstCameraParam.targetPos = playerPos1;
        firstCameraParam.fovy = 0xe38;
        firstCameraParam.flags.apply[0] = 1;
        firstCameraParam.flags.apply[1] = 1;
        firstCameraParam.flags.apply[2] = 0;
        firstCameraParam.flags.apply[3] = 1;
        firstCameraParam.flags.apply[4] = 1;
        firstCameraParam.flags.apply[5] = 1;
        FIELD_CAMERA_StartMove(camera, (struct FieldCameraMoveRequest *)(&firstCameraParam), 10);
        (*seq)++;
    case 2:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        child = FLD3D_CI_StartSequence(work->gameSystem, ci, (u8)work->cutInIdBefore);
        if (child != 0)
            GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 3:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
        FIELD_CAMERA_PopState(camera);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(work->gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventToLocation(work->gameSystem, fieldMap, work->zoneId, &work->startLocation, 1));
        (*seq)++;
        break;
    case 5:
        FIELD_PLACE_NAME_Cancel(FIELDMAP_GetPlaceName(fieldMap));
        work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 6:
        if (work->savedCameraTarget != 0 && FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive((struct FieldNogridMapper *)bg, 0);
        FIELD_CAMERA_StopTargetTrace(camera);
        FIELD_CAMERA_PushStateConstrained(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos2);
        secondCameraParam.pitch = 0x25d8;
        secondCameraParam.yaw = 0;
        secondCameraParam.distance = 0xed000;
        secondCameraParam.targetOffset.x = 0;
        secondCameraParam.targetOffset.y = 0x4000;
        secondCameraParam.targetOffset.z = 0;
        secondCameraParam.targetPos = playerPos2;
        secondCameraParam.fovy = 0xe38;
        secondCameraParam.flags.apply[0] = 1;
        secondCameraParam.flags.apply[1] = 1;
        secondCameraParam.flags.apply[2] = 0;
        secondCameraParam.flags.apply[3] = 1;
        secondCameraParam.flags.apply[4] = 1;
        secondCameraParam.flags.apply[5] = 1;
        FIELD_CAMERA_StartMove(camera, (struct FieldCameraMoveRequest *)(&secondCameraParam), 1);
        (*seq)++;
    case 7:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
        visiblePlanes = BG_SYS_GetMainVisiblePlanes();
        FIELDMAP_SetBgMode();
        BG_SYS_SetMainVisiblePlanes(visiblePlanes);
        FIELDMAP_ResetBgAffineShowMsg(fieldMap);
        (*seq)++;
        break;
    case 8:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        child = FLD3D_CI_StartSequence(work->gameSystem, ci, (u8)work->cutInIdAfter);
        if (child != 0) {
            GAME_EVENT_CallEvent(event, child);
        } else {
            mmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
            FLDMMDL_SetStatusBitVanish(mmdl, 0);
            FLDMMDL_SetDirDispCheckPause(mmdl, 1);
            GAME_EVENT_CallEvent(event, GAME_EVENT_Create(work->gameSystem, event, FLD_WIPE_3DOBJ_FadeOutEventMain, 0));
        }
        (*seq)++;
        break;
    case 9:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        FIELD_PLACE_NAME_ShowForZone(FIELDMAP_GetPlaceName(fieldMap), work->zoneId);
        flags.apply[0] = 1;
        flags.apply[1] = 1;
        flags.apply[2] = 0;
        flags.apply[3] = 1;
        flags.apply[4] = 1;
        flags.apply[5] = 1;
        FIELD_CAMERA_StartMoveToSaved(camera, (struct FieldCameraMoveChannels *)(&flags), 10);
        (*seq)++;
    case 10:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        if (work->savedCameraTarget != 0)
            FIELD_CAMERA_SetTraceTarget(camera, work->savedCameraTarget);
        FIELD_CAMERA_RestartDelay(camera);
        FIELD_NOGRID_MAPPER_SetActive((struct FieldNogridMapper *)bg, 1);
        FIELD_CAMERA_PopState(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 1);
        return 1;
    }
    return 0;
}

/* Fades the screen out, then ends. */
int FLD_WIPE_3DOBJ_FadeOutEventMain(struct GameEvent *event, int *seq, void *work)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (*seq) {
    case 0:
        FADE_Start(3, 0x10, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
