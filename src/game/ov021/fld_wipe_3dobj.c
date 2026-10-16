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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   gFldWipe3dObjFileName  0x021DE520  data  ov021  a4
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   func_02046EFC  0x02046EFC  arm
 *   G3D_SYSTEM_GetLookAt  0x02046AFC  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   func_02082B60  0x02082B60  arm
 *   G3D_SYSTEM_GetRenderObj  0x0204755C  arm
 *   func_0206E394  0x0206E394  arm
 *   func_0206E4FC  0x0206E4FC  arm
 *   func_0206E484  0x0206E484  arm
 *   func_0206E574  0x0206E574  arm
 *   func_0206E40C  0x0206E40C  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   ICA_ANIME_GetField20  0x0201210C  thumb
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
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
 *   BMP_GetVisiblePlane  0x02043658  arm
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
#include "fld_wipe_3dobj_shared_types.h"

typedef struct MmdlSys MmdlSys;

typedef struct ScriptSystem ScriptSystem;

typedef struct Fld3dCi Fld3dCi;

typedef struct MyStatus MyStatus;

typedef struct ZoneStartLocation {
    u8 data[0x1C];
} ZoneStartLocation;

typedef struct G3dLookAt {
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 target;
} G3dLookAt; /* same layout as G3dLookAt in arm9/g3d_system_types.h */

typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct Mtx43 {
    int m[12];
} Mtx43;

typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    Mtx33 rotate;
} G3dObjectStatus; /* same layout as G3dObjectStatus in arm9/g3d_system_types.h */

typedef struct G3dRenderRef {
    int magic;
    void *rndObj;
} G3dRenderRef;

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
    u32 savedCameraBits;
    u32 zoneId;
    ZoneStartLocation startLocation;
    u32 cutInIdBefore;
    u32 cutInIdAfter;
} WipeMapChangeWork;

extern FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);

extern FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);

extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);

extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int direction);

extern void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *pos);

extern void FADE_Start(u32 mode, u32 start, u32 end, u32 wait);

extern void VEC_Subtract(VecFx32 *a, VecFx32 *b, VecFx32 *out);

extern u32 func_020307B0(void *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *dst, int value, int size);

extern void *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 mode);

extern void *G3D_SYSTEM_CreateRender(void *resArc, u32 index, void *param);

extern void *G3D_SYSTEM_CreateObject(void *render, u32 *anime, int count);

extern void func_02046EFC(void *resArc);

extern void G3D_SYSTEM_DeleteRender(void *render);

extern void G3D_SYSTEM_DeleteObject(void *object);

extern void *G3D_SYSTEM_GetObjectRender(void *object);

extern void G3D_SYSTEM_GetLookAt(G3dLookAt *dst);

extern void VEC_Normalize(VecFx32 *src, VecFx32 *dst);

extern u32 *NNS_G3dGlbGetInvCameraMtx(void);

extern void func_02082B60(Mtx43 *src, Mtx33 *dst);

extern G3dRenderRef *G3D_SYSTEM_GetRenderObj(void *render);

extern void func_0206E394(void *mdl, int a, int b);

extern void func_0206E4FC(void *mdl, int a, int b);

extern void func_0206E484(void *mdl, int a, int b);

extern void func_0206E574(void *mdl, int a, int b);

extern void func_0206E40C(void *mdl, int a, int b);

extern void G3D_SYSTEM_DrawObject(void *object, G3dObjectStatus *status);

extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrCmdWork *work);

extern FieldMap *ICA_ANIME_GetField20(GameSystem *gameSystem);

extern Fld3dCi *FIELDMAP_GetFld3dCi(FieldMap *fieldMap);

extern u16 VM_ReadU16(ScriptVm *vm);

extern ScriptSystem *SCRCMD_WORK_GetScriptWork(ScrCmdWork *work);

extern GameEvent *FLD3D_CI_StartSequence(GameSystem *gameSystem, Fld3dCi *ci, int id);

extern void SCRIPT_SYS_CallEvent(ScriptSystem *scriptSys, GameEvent *event);

extern unsigned int SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrCmdWork *work);

extern GameEvent *FLD3D_CI_StartPartyMemberSequence(GameSystem *gameSystem, Fld3dCi *ci, int value);

extern GameEvent *FLD3D_CI_StartMessageSequence(GameSystem *gameSystem, Fld3dCi *ci, unsigned int value);

extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, int (*main)(), unsigned int workSize);

extern void *func_020124E8(GameEvent *event);

extern void *ICA_ANIME_GetField1C(GameSystem *gameSystem);

extern MyStatus *GAME_DATA_GetMyStatus(void *gameData);

extern u8 func_02008550(const MyStatus *myStatus);

extern void ZONEDATA_SetZoneStartLocation(ZoneStartLocation *location, int zoneId);

extern u32 FIELDMAP_GetNogridMapper(FieldMap *fieldMap);

extern void FIELD_CAMERA_SetAreasEnabled(FieldCamera *camera, u32 value);

extern u32 FIELD_CAMERA_GetTraceTarget(FieldCamera *camera);

extern void FIELD_CAMERA_EndDelay(FieldCamera *camera);

extern u32 FIELD_CAMERA_IsDelayEnabled(FieldCamera *camera);

extern void FIELD_NOGRID_MAPPER_SetActive(u32 bg, u32 value);

extern void FIELD_CAMERA_StopTargetTrace(FieldCamera *camera);

extern void FIELD_CAMERA_PushState(FieldCamera *camera);

extern void FIELD_CAMERA_PushStateConstrained(FieldCamera *camera);

extern void FIELD_CAMERA_StartMove(FieldCamera *camera, CameraAnimParam *param, int frames);

extern int FIELD_CAMERA_IsMoving(FieldCamera *camera);

extern MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);

extern void FLDMMDL_SysPauseMove(MmdlSys *mmdlSys);

extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);

extern u32 *FLDMMDL_SysResumeMove(MmdlSys *mmdlSys);

extern void FLDMMDL_SetStatusBitVanish(Mmdl *mmdl, unsigned int vanish);

extern void FIELD_CAMERA_PopState(FieldCamera *camera);

extern GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(GameSystem *gameSystem, FieldMap *fieldMap, u32 a, u32 b);

extern GameEvent *EVENT_MAPCHANGE_CreateWarpEventToLocation(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, ZoneStartLocation *location, u16 flag);

extern void *FIELDMAP_GetPlaceName(FieldMap *fieldMap);

extern int FIELD_PLACE_NAME_Cancel(void *msgBg);

extern u32 BMP_GetVisiblePlane(void);

extern void FIELDMAP_SetBgMode(void);

extern void BG_SYS_SetMainVisiblePlanes(u32 planes);

extern void FIELDMAP_ResetBgAffineShowMsg(FieldMap *fieldMap);

extern void FIELD_PLACE_NAME_ShowForZone(void *msgBg, int zoneId);

extern void FIELD_CAMERA_StartMoveToSaved(FieldCamera *camera, CameraAnimFlags *flags, u16 frames);

extern void FIELD_CAMERA_SetTraceTarget(FieldCamera *camera, u32 bits);

extern void FIELD_CAMERA_RestartDelay(FieldCamera *camera);

extern GameSystem *GAME_EVENT_GetGameSystem(GameEvent *event);

extern int FADE_IsActive(void);

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

GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, int unused, int zoneId);

int FLD_WIPE_3DOBJ_MapChangeEventMain(GameEvent *event, int *seq, WipeMapChangeWork *work);

int FLD_WIPE_3DOBJ_FadeOutEventMain(GameEvent *event, int *seq);

FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId)
{
    FldWipe3dObj *obj = func_02030734(heapId, sizeof(FldWipe3dObj), 1, gFldWipe3dObjFileName, 0x24);
    obj->resArc = G3D_SYSTEM_CreateResourceArc(0x4a, 0);
    obj->object = G3D_SYSTEM_CreateObject(G3D_SYSTEM_CreateRender(obj->resArc, 0, 0), 0, 0);
    return obj;
}

int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj)
{
    G3D_SYSTEM_DeleteRender(G3D_SYSTEM_GetObjectRender(obj->object));
    G3D_SYSTEM_DeleteObject(obj->object);
    func_02046EFC(obj->resArc);
    return func_020307B0(obj);
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
    func_02082B60((Mtx43 *)NNS_G3dGlbGetInvCameraMtx(), &status.rotate);
    mdl = G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(obj->object))->rndObj;
    func_0206E394(mdl, 0, 0);
    func_0206E4FC(mdl, 0, 0);
    func_0206E484(mdl, 0, 2);
    func_0206E574(mdl, 0, alpha);
    func_0206E40C(mdl, 0, 0);
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
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(ICA_ANIME_GetField20(gameSystem));
    ciId = VM_ReadU16(vm);
    scriptSys = SCRCMD_WORK_GetScriptWork(work);
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
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(ICA_ANIME_GetField20(gameSystem));
    ciId = SCRIPT_WORK_ReadWorkValue(vm, work);
    scriptSys = SCRCMD_WORK_GetScriptWork(work);
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
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(ICA_ANIME_GetField20(gameSystem));
    value = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    scriptSys = SCRCMD_WORK_GetScriptWork(work);
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
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(ICA_ANIME_GetField20(gameSystem));
    value = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (value == gFld3dCiKeyTable[i * 2]) {
            found = 1;
            ciId = gFld3dCiIdTable[i * 2];
            break;
        }
    }
    if (found) {
        scriptSys = SCRCMD_WORK_GetScriptWork(work);
        event = FLD3D_CI_StartSequence(gameSystem, ci, (unsigned char)ciId);
        if (event) {
            SCRIPT_SYS_CallEvent(scriptSys, event);
        }
    }
    return 1;
}

/* Creates the wipe event: picks the two FLD3D_CI ids by player outfit and remembers the destination zone. */
GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, int unused, int zoneId)
{
    GameEvent *event;
    WipeMapChangeWork *work;
    int cutInIdAfter;
    event = func_020122C0(gameSystem, 0, FLD_WIPE_3DOBJ_MapChangeEventMain, 0x30);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 0x30);
    work->gameSystem = gameSystem;
    work->zoneId = zoneId;
    if (func_02008550(GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem))) == 0) {
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
int FLD_WIPE_3DOBJ_MapChangeEventMain(GameEvent *event, int *seq, WipeMapChangeWork *work)
{
    FieldMap *fieldMap;
    FieldCamera *camera;
    Fld3dCi *ci;
    u32 bg;
    GameEvent *child;
    void *msgBg;
    u32 visiblePlanes;
    Mmdl *mmdl;
    CameraAnimParam param1;
    CameraAnimParam param2;
    VecFx32 playerPos1;
    VecFx32 playerPos2;
    CameraAnimFlags flags;
    fieldMap = ICA_ANIME_GetField20(work->gameSystem);
    camera = FIELDMAP_GetCamera(fieldMap);
    ci = FIELDMAP_GetFld3dCi(fieldMap);
    bg = FIELDMAP_GetNogridMapper(fieldMap);
    switch (*seq) {
    case 0:
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
        work->savedCameraBits = FIELD_CAMERA_GetTraceTarget(camera);
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 1:
        if (work->savedCameraBits != 0 && FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive(bg, 0);
        FIELD_CAMERA_StopTargetTrace(camera);
        FIELD_CAMERA_PushState(camera);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos1);
        param1.pitch = 0x25d8;
        param1.yaw = 0;
        param1.distance = 0xed000;
        param1.targetOffset.x = 0;
        param1.targetOffset.y = 0x4000;
        param1.targetOffset.z = 0;
        param1.targetPos = playerPos1;
        param1.fovy = 0xe38;
        param1.flags.apply[0] = 1;
        param1.flags.apply[1] = 1;
        param1.flags.apply[2] = 0;
        param1.flags.apply[3] = 1;
        param1.flags.apply[4] = 1;
        param1.flags.apply[5] = 1;
        FIELD_CAMERA_StartMove(camera, &param1, 10);
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
        work->savedCameraBits = FIELD_CAMERA_GetTraceTarget(camera);
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 6:
        if (work->savedCameraBits != 0 && FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive(bg, 0);
        FIELD_CAMERA_StopTargetTrace(camera);
        FIELD_CAMERA_PushStateConstrained(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos2);
        param2.pitch = 0x25d8;
        param2.yaw = 0;
        param2.distance = 0xed000;
        param2.targetOffset.x = 0;
        param2.targetOffset.y = 0x4000;
        param2.targetOffset.z = 0;
        param2.targetPos = playerPos2;
        param2.fovy = 0xe38;
        param2.flags.apply[0] = 1;
        param2.flags.apply[1] = 1;
        param2.flags.apply[2] = 0;
        param2.flags.apply[3] = 1;
        param2.flags.apply[4] = 1;
        param2.flags.apply[5] = 1;
        FIELD_CAMERA_StartMove(camera, &param2, 1);
        (*seq)++;
    case 7:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
        visiblePlanes = BMP_GetVisiblePlane();
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
            GAME_EVENT_CallEvent(event, func_020122C0(work->gameSystem, event, FLD_WIPE_3DOBJ_FadeOutEventMain, 0));
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
        FIELD_CAMERA_StartMoveToSaved(camera, &flags, 10);
        (*seq)++;
    case 10:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        if (work->savedCameraBits != 0)
            FIELD_CAMERA_SetTraceTarget(camera, work->savedCameraBits);
        FIELD_CAMERA_RestartDelay(camera);
        FIELD_NOGRID_MAPPER_SetActive(bg, 1);
        FIELD_CAMERA_PopState(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 1);
        return 1;
    }
    return 0;
}

/* Fades the screen out, then ends. */
int FLD_WIPE_3DOBJ_FadeOutEventMain(GameEvent *event, int *seq)
{
    ICA_ANIME_GetField20(GAME_EVENT_GetGameSystem(event));
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
