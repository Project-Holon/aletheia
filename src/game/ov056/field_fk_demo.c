/*
 * file:     field_fk_demo.c
 * unit:     yes
 * function: FIELD_FK_DEMO_StartEvent, FIELD_FK_DEMO_GetCameraSettingId, FIELD_FK_DEMO_GetAnimeEndFrame, FIELD_FK_DEMO_UploadModelTask, FIELD_FK_DEMO_CreateEvent, FIELD_FK_DEMO_EventMain, FIELD_FK_DEMO_InitBuildAnime, FIELD_FK_DEMO_DeleteBuildAnime, FIELD_FK_DEMO_StartBuildAnime, FIELD_FK_DEMO_IsBuildAnimeDone, FIELD_FK_DEMO_InitCamera, FIELD_FK_DEMO_ExitCamera, FIELD_FK_DEMO_StepCamera, FIELD_FK_DEMO_ApplyCameraAnime, FIELD_FK_DEMO_InitModel, FIELD_FK_DEMO_CreateModelObject, FIELD_FK_DEMO_DeleteModel, FIELD_FK_DEMO_StepModel, FIELD_FK_DEMO_SetPlayerHidden, FIELD_FK_DEMO_UploadModelOnce, FIELD_FK_DEMO_DrawModel, FIELD_FK_DEMO_DrawProc, FIELD_FK_DEMO_CreateSoundAnime, FIELD_FK_DEMO_DeleteSoundAnime, FIELD_FK_DEMO_StepSoundAnime, FIELD_FK_BUILD_SOUND_Init, FIELD_FK_BUILD_SOUND_Exit, FIELD_FK_BUILD_SOUND_Update
 * address:  0x021F36C0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Boundary audit (wave 16): kept as one file. The FIELD_FK_DEMO_ and FIELD_FK_BUILD_SOUND_ data alternate: gFkBuildSoundTriggerFrame 0x021F4258, gFkDemoEndDir 0x021F4264, gFkDemoOrigin 0x021F426C, gFkBuildSoundModelPos 0x021F4278, gFkDemoHasBuildAnime 0x021F4290. field_fk_sound_anime.c (anchor 021F4040) is the separate file that follows.
 *
 * symbols:
 *   gFkDemoCameraSettingId  0x021F42B0  data
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   FIELD_SUBPROC_GetWork  0x021BBA6C  thumb  ov021
 *   FIELD_SUBPROC_End  0x021BBA1C  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 *   gFkDemoDrawTemplate     0x021F42C0  data  a4
 *   FIELD_BUILDMODEL_CreateNodeNearPos  0x0218C7D8  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   gFkDemoHasBuildAnime  0x021F4290  data  ov056  a4
 *   gFkDemoBuildModelPos  0x021F42D8  data  ov056  a4
 *   FIELD_BUILDMODEL_DeleteNode 0x0218C860 thumb ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim 0x0218C69C thumb ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot 0x0218C88C thumb ov021
 *   FIELD_BUILDMODEL_TryOpenNodeSlot 0x0218C8B0 thumb ov021
 *   ICA_ANIME_CreateStream  0x02011510  thumb
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_GetAreasEnabled  0x0218F1B4  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   FIELD_CAMERA_GetG3dUp  0x0218ED20  thumb  ov021
 *   gFkDemoCameraUp     0x021F4338  data  a4
 *   FX_SinCosTable_  0x020A1B38  data
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetG3dUp  0x0218ED14  thumb  ov021
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   ICA_ANIME_SetFrame  0x020115EC  thumb
 *   ICA_ANIME_SetCameraStatus  0x02011B8C  thumb
 *   G3D_CAMERA_GetCamUp  0x02048B0C  arm
 *   VEC_Add  0x0207C9D0  arm
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   gFkDemoOrigin     0x021F426C  data  a4
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   MTX_Identity33_  0x0207ADC4  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_AllocVramTexture  0x02047180  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   gFkDemoEndTile     0x021F4308  data  a4
 *   gFkDemoEndDir     0x021F4264  data  a2
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   G3D_SYSTEM_TransAllocatedTexture  0x02047204  arm
 *   FIELD_FK_SOUND_ANIME_Create  0x021F4040  thumb  ov056
 *   MI_CpuFill8    0x02082BCC  arm
 *   gFkDemoHasSoundAnime     0x021F42A0  data  a4
 *   gFkSoundAnimeSoundIds     0x021F43A4  data  a4
 *   FIELD_FK_SOUND_ANIME_Delete  0x021F408C  thumb  ov056
 *   FIELD_FK_SOUND_ANIME_Step  0x021F40A0  thumb  ov056
 *   FIELD_BUILDMODEL_GetEntrySlotFrame  0x0218C6F4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   gFkBuildSoundModelPos  0x021F4278  data  ov056  a4
 *   gFkBuildSoundTriggerFrame  0x021F4258  data  ov056  a4
 *   FIELD_SOUND_SYSTEM_ReleaseSlot  0x02028B50  thumb
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 */
#include "field_fk_demo_types.h"

extern struct G3dAnmObjHead *G3D_SYSTEM_GetAnimeObj(struct G3dAnime *anime);
struct FieldSubprocTemplate;
struct FieldSubprocMgr;
struct FieldSubproc;
extern struct FieldSubproc *FIELD_SUBPROC_Start(s32 overlayId, struct FieldSubprocMgr *mgr, struct FieldSubprocTemplate *tmpl);
extern FkDemoDrawWork *FIELD_SUBPROC_GetWork(const struct FieldSubproc *proc);
extern void FIELD_SUBPROC_End(struct FieldSubproc *proc);
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, FkDemoEventFunc func, u32 workSize);
extern void *GAME_EVENT_GetWork(struct GameEvent *event);
struct Tcb;
extern struct Tcb *GFL_USE_AddMainTask(FkDemoTcbFunc callback, void *work, u32 priority);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void FIELD_CAMERA_EndDelay(struct FieldCamera *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(struct FieldCamera *camera);
extern struct BuildModelNode *FIELD_BUILDMODEL_CreateNodeNearPos(struct BuildModelMan *man, int kind, const VecFx32 *pos);
extern void FIELD_BUILDMODEL_DeleteNode(struct BuildModelNode *node);
extern void FIELD_BUILDMODEL_PlayEntryAnim(struct BuildModelMan *man, struct BuildModelEntry *entry, int slot, int mode);
extern void FIELD_BUILDMODEL_PlayNodeSlot(struct BuildModelNode *node, int slot, int mode);
extern int FIELD_BUILDMODEL_TryOpenNodeSlot(struct BuildModelNode *node, int slot);
extern struct IcaAnime *ICA_ANIME_CreateStream(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);
extern struct G3dCamera *FIELD_CAMERA_GetG3dCamera(struct FieldCamera *camera);
extern void G3D_CAMERA_GetCamTarget(struct G3dCamera *g3dCamera, VecFx32 *out);
extern void G3D_CAMERA_GetEye(struct G3dCamera *g3dCamera, VecFx32 *out);
extern void G3D_CAMERA_GetCamUp(struct G3dCamera *g3dCamera, VecFx32 *out);
extern struct G3dCamera *G3D_CAMERA_Create(int projType, s16 fovySin, s16 fovyCos, int aspect, int right, int nearClip, int farClip, int scaleW,
                                       VecFx32 *position, VecFx32 *up, VecFx32 *target, int heapId);
extern u32 FIELD_CAMERA_GetMode(struct FieldCamera *camera);
extern void FIELD_CAMERA_SetMode(struct FieldCamera *camera, u32 mode);
extern u8 FIELD_CAMERA_GetAreasEnabled(struct FieldCamera *camera);
extern void FIELD_CAMERA_SetAreasEnabled(struct FieldCamera *camera, u32 enabled);
extern void FIELD_CAMERA_StopTargetTrace(struct FieldCamera *camera);
extern void FIELD_CAMERA_GetTargetShift(struct FieldCamera *camera, VecFx32 *out);
extern void FIELD_CAMERA_SetTargetShift(struct FieldCamera *camera, const VecFx32 *shift);
extern void FIELD_CAMERA_GetG3dUp(struct FieldCamera *camera, VecFx32 *out);
extern void FIELD_CAMERA_ResumeTargetTrace(struct FieldCamera *camera);
extern const VecFx32 *FIELD_CAMERA_GetTraceTarget(struct FieldCamera *camera);
extern void FIELD_CAMERA_SetTarget(struct FieldCamera *camera, const VecFx32 *target);
extern void FIELD_CAMERA_SetG3dUp(struct FieldCamera *camera, const VecFx32 *up);
extern void FIELD_CAMERA_SetSetting(struct FieldCamera *camera, u32 settingId);
extern void FIELD_CAMERA_RestartDelay(struct FieldCamera *camera);
extern void FIELD_CAMERA_SetEyeRaw(struct FieldCamera *camera, const VecFx32 *eye);
extern u32 G3D_CAMERA_Delete(void *camera);
extern void ICA_ANIME_SetCameraStatus(void *camera, struct IcaAnime *anime);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern void MTX_Identity33_(MtxFx33 *matrix);
struct ArcHandle;
struct G3dResource;
extern struct G3dResource *G3D_SYSTEM_CreateResourceArcHandle(struct ArcHandle *arc, u32 dataId);
extern int G3D_SYSTEM_AllocVramTexture(struct G3dResource *res);
extern void ARC_TOOL_DeleteHandle(void *handle);
extern struct G3dRender *G3D_SYSTEM_CreateRender(struct G3dResource *modelRes, u32 modelIndex, struct G3dResource *texRes);
extern struct G3dAnime *G3D_SYSTEM_CreateAnime(struct G3dRender *render, struct G3dResource *anmRes, u32 anmIdx);
extern struct G3dObject *G3D_SYSTEM_CreateObject(struct G3dRender *render, struct G3dAnime **animeTable, int animeCount);
extern s32 G3D_SYSTEM_SetObjectAnimeFrame(struct G3dObject *object, u16 animeIndex, s32 *frame);
extern s32 G3D_SYSTEM_EnableObjectAnime(struct G3dObject *object, u32 animeIndex);
extern void G3D_SYSTEM_DeleteObject(struct G3dObject *object);
extern void G3D_SYSTEM_DeleteAnime(struct G3dAnime *anime);
extern void G3D_SYSTEM_DeleteRender(struct G3dRender *render);
extern int G3D_SYSTEM_FreeVramTexture(struct G3dResource *res);
extern void G3D_SYSTEM_DeleteResource(struct G3dResource *res);
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, s32 flag);
extern void FLDMMDL_InitGridPosition(struct Mmdl *mmdl, unsigned int tileX, unsigned int tileY, unsigned int tileZ, u16 dir);
extern int FLDMMDL_MOVE_UpdateHeight(struct Mmdl *mmdl);
struct MmdlVec;
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern void FIELD_PLAYER_SetPos(struct FieldPlayer *player, const VecFx32 *pos);
extern void FLDMMDL_SetMoveBitReflect(struct Mmdl *mmdl, int value);
extern s32 G3D_SYSTEM_TransAllocatedTexture(struct G3dResource *res);
extern void G3D_SYSTEM_DrawObject(struct G3dObject *object, G3dObjectStatus *status);
extern const s16 FX_SinCosTable_[];

struct GameEvent *FIELD_FK_DEMO_StartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant);
u32 FIELD_FK_DEMO_GetCameraSettingId(u32 variant);
int FIELD_FK_DEMO_GetAnimeEndFrame(struct G3dAnime *anime);
void FIELD_FK_DEMO_UploadModelTask(struct Tcb *tcb, FkDemoWork *work);
struct GameEvent *FIELD_FK_DEMO_CreateEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant);
int FIELD_FK_DEMO_EventMain(struct GameEvent *event, int *seq, FkDemoWork *work);
void FIELD_FK_DEMO_InitBuildAnime(FkBuildModelAnime *anime, struct BuildModelMan *man, int variant);
void FIELD_FK_DEMO_DeleteBuildAnime(FkBuildModelAnime *anime);
void FIELD_FK_DEMO_StartBuildAnime(FkBuildModelAnime *anime);
int FIELD_FK_DEMO_IsBuildAnimeDone(FkBuildModelAnime *anime);
void FIELD_FK_DEMO_InitCamera(FkDemoCamera *demoCamera, struct FieldCamera *fieldCamera, int heapId, int variant);
void FIELD_FK_DEMO_ExitCamera(FkDemoCamera *demoCamera);
int FIELD_FK_DEMO_StepCamera(FkDemoCamera *demoCamera);
void FIELD_FK_DEMO_ApplyCameraAnime(FkDemoCamera *demoCamera);
void FIELD_FK_DEMO_InitModel(FkDemoModel *model, struct FieldPlayer *player, struct MyStatus *myStatus, int heapId, int variant);
void FIELD_FK_DEMO_CreateModelObject(FkDemoModel *model);
void FIELD_FK_DEMO_DeleteModel(FkDemoModel *model);
int FIELD_FK_DEMO_StepModel(FkDemoModel *model);
void FIELD_FK_DEMO_SetPlayerHidden(FkDemoModel *model, int hide);
void FIELD_FK_DEMO_UploadModelOnce(FkDemoModel *model);
void FIELD_FK_DEMO_DrawModel(FkDemoModel *model);
void FIELD_FK_DEMO_DrawProc(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkDemoDrawWork *work);
void FIELD_FK_DEMO_CreateSoundAnime(FkSoundAnime **out, int variant, u16 heapId);
void FIELD_FK_DEMO_DeleteSoundAnime(FkSoundAnime **soundAnime);
int FIELD_FK_DEMO_StepSoundAnime(FkSoundAnime **soundAnime);
void FIELD_FK_BUILD_SOUND_Init(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work);
void FIELD_FK_BUILD_SOUND_Exit(struct FieldSubproc *proc, struct FieldMap *fieldMap);
void FIELD_FK_BUILD_SOUND_Update(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work);

/* Entry of the script command that starts the demo of a variant; returns the event the script waits for. */
struct GameEvent *FIELD_FK_DEMO_StartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant)
{
    return FIELD_FK_DEMO_CreateEvent(gameSystem, fieldMap, variant);
}

/*
 * Field camera setting (word table gFkDemoCameraSettingId, {0x1C, 0x1D, 0x1E, 0x1F}) of a
 * variant, the table FIELD_FK_DEMO_InitCamera also indexes. Region ov056: of the 33
 * overlays mapped at this address it is the only one with a function entry
 * here (the bytes before are the tail-call thunk at 0x021F36C0 and its pool
 * word); ov036..ov065 except ov056 are mid-function at 0x021F36C8, ov107 is
 * ARM. Its ov021 caller SCRCMD_PROC_FLD_SetOv056Slot passes a 1-based slot minus one (wave A1
 * witness).
 *
 * Addresses are Black-image addresses.
 */
u32 FIELD_FK_DEMO_GetCameraSettingId(u32 variant)
{
    return gFkDemoCameraSettingId[variant];
}

/* Length of a model animation in fx32 frames. */
int FIELD_FK_DEMO_GetAnimeEndFrame(struct G3dAnime *anime)
{
    return G3D_SYSTEM_GetAnimeObj(anime)->res->frameCount << 12;
}

/*
 * Per frame task: uploads the stand-in model once. Unlabelled tail-call leaf:
 * forwards the work plus 0x3c (the model).
 */
void FIELD_FK_DEMO_UploadModelTask(struct Tcb *tcb, FkDemoWork *work)
{
    FIELD_FK_DEMO_UploadModelOnce(&work->model);
}

/* Creates the demo event and the task that uploads the model. */
struct GameEvent *FIELD_FK_DEMO_CreateEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant)
{
    struct GameEvent *event;
    FkDemoWork *work;

    FIELDMAP_GetHeapId(fieldMap);
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_FK_DEMO_EventMain, sizeof(FkDemoWork));
    work = GAME_EVENT_GetWork(event);
    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->variant = variant;
    work->uploadTcb = GFL_USE_AddMainTask(FIELD_FK_DEMO_UploadModelTask, work, 0);
    return event;
}

/*
 * Event function of the demo.
 *   0: set up the stand-in player model
 *   1: tell the field camera to end its delay
 *   2: wait for the delay, then set up camera, sound anime, building animation and the draw proc
 *   3: run the animations until all of them end
 *   4: put everything back
 */
int FIELD_FK_DEMO_EventMain(struct GameEvent *event, int *seq, FkDemoWork *work)
{
    u16 heapId;
    struct FieldCamera *fieldCamera;
    struct MyStatus *myStatus;
    int cameraDone;
    int buildAnimeDone;
    int soundAnimeDone;

    heapId = FIELDMAP_GetHeapId(work->fieldMap);
    switch (*seq) {
    case 0:
        myStatus = GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(work->gameSystem));
        FIELD_FK_DEMO_InitModel(&work->model, FIELDMAP_GetFieldPlayer(work->fieldMap), myStatus, heapId, work->variant);
        (*seq)++;
        break;
    case 1:
        FIELD_CAMERA_EndDelay(FIELDMAP_GetCamera(work->fieldMap));
        (*seq)++;
        break;
    case 2:
        fieldCamera = FIELDMAP_GetCamera(work->fieldMap);
        if (FIELD_CAMERA_IsDelayEnabled(fieldCamera) != 0) {
            break;
        }
        FIELD_FK_DEMO_InitCamera(&work->camera, fieldCamera, heapId, work->variant);
        FIELD_FK_DEMO_CreateSoundAnime(&work->soundAnime, work->variant, heapId);
        FIELD_FK_DEMO_InitBuildAnime(&work->buildAnime, FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(work->fieldMap)), work->variant);
        FIELD_FK_DEMO_CreateModelObject(&work->model);
        work->drawProc = FIELD_SUBPROC_Start(-1, (struct FieldSubprocMgr *)(FIELDMAP_GetMapFunc(work->fieldMap)), (struct FieldSubprocTemplate *)(&gFkDemoDrawTemplate));
        FIELD_SUBPROC_GetWork(work->drawProc)->model = &work->model;
        FIELD_FK_DEMO_SetPlayerHidden(&work->model, 1);
        FIELD_FK_DEMO_StartBuildAnime(&work->buildAnime);
        (*seq)++;
        break;
    case 3:
        cameraDone = FIELD_FK_DEMO_StepCamera(&work->camera);
        FIELD_FK_DEMO_StepModel(&work->model);
        soundAnimeDone = FIELD_FK_DEMO_StepSoundAnime(&work->soundAnime);
        buildAnimeDone = FIELD_FK_DEMO_IsBuildAnimeDone(&work->buildAnime);
        if (cameraDone && buildAnimeDone && soundAnimeDone) {
            (*seq)++;
        }
        break;
    case 4:
        FIELD_FK_DEMO_SetPlayerHidden(&work->model, 0);
        FIELD_SUBPROC_End(work->drawProc);
        TCB_DeleteTask((struct TcbTask *)work->uploadTcb);
        FIELD_FK_DEMO_DeleteModel(&work->model);
        FIELD_FK_DEMO_DeleteSoundAnime(&work->soundAnime);
        FIELD_FK_DEMO_ExitCamera(&work->camera);
        FIELD_FK_DEMO_DeleteBuildAnime(&work->buildAnime);
        return 1;
    }
    return 0;
}

/* Finds the building model of the variant and creates its animation node; nothing for variants without one. */
void FIELD_FK_DEMO_InitBuildAnime(FkBuildModelAnime *anime, struct BuildModelMan *man, int variant)
{
    if (gFkDemoHasBuildAnime[variant] != 0) {
        anime->node = FIELD_BUILDMODEL_CreateNodeNearPos(man, 0, &gFkDemoBuildModelPos[variant]);
        anime->entry = FIELD_BUILDMODEL_GetFirstEntryNearPos(man, 0, &gFkDemoBuildModelPos[variant]);
        anime->man = man;
    } else {
        anime->node = 0;
        anime->entry = 0;
    }
}

/* Stops both animations of the building model and deletes its node. */
void FIELD_FK_DEMO_DeleteBuildAnime(FkBuildModelAnime *anime)
{
    if (anime->node) {
        FIELD_BUILDMODEL_DeleteNode(anime->node);
        FIELD_BUILDMODEL_PlayEntryAnim(anime->man, anime->entry, 0, 1);
        FIELD_BUILDMODEL_PlayEntryAnim(anime->man, anime->entry, 0, 3);
        anime->node = 0;
        anime->entry = 0;
        anime->man = 0;
    }
}

/* Starts the building animation (animation slot 0, mode 0). */
void FIELD_FK_DEMO_StartBuildAnime(FkBuildModelAnime *anime)
{
    if (anime->node) {
        FIELD_BUILDMODEL_PlayNodeSlot(anime->node, 0, 0);
    }
}

/* Returns 1 when the building animation ended or there is none. */
int FIELD_FK_DEMO_IsBuildAnimeDone(FkBuildModelAnime *anime)
{
    if (anime->node) {
        return FIELD_BUILDMODEL_TryOpenNodeSlot(anime->node, 0);
    }
    return 1;
}

/*
 * Saves the field camera, switches it to free mode without constraint areas
 * and builds the demo camera. The demo camera is driven by the ICA animation
 * of the variant.
 */
void FIELD_FK_DEMO_InitCamera(FkDemoCamera *demoCamera, struct FieldCamera *fieldCamera, int heapId, int variant)
{
    VecFx32 target;
    VecFx32 eye;
    s32 zeroShift[3]; /* stand-in: a VecFx32 local is addressed through sp, the original keeps a pointer register */
    VecFx32 up;
    struct G3dCamera *g3dCamera;
    VecFx32 *zeroShiftPtr;

    demoCamera->frame = 0;
    demoCamera->anime = ICA_ANIME_CreateStream(heapId, FK_DEMO_ARC_ID, variant + FK_DEMO_CAMERA_FILE, 10);
    g3dCamera = FIELD_CAMERA_GetG3dCamera(fieldCamera);
    G3D_CAMERA_GetCamTarget(g3dCamera, &target);
    G3D_CAMERA_GetEye(g3dCamera, &eye);
    up = gFkDemoCameraUp;
    /* perspective, half field of view index 0x1C6, aspect 4:3, near 1.0, far 1024.0 */
    demoCamera->g3dCamera = G3D_CAMERA_Create(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &eye, &up, &target, heapId);
    demoCamera->fieldCamera = fieldCamera;
    demoCamera->savedMode = FIELD_CAMERA_GetMode(demoCamera->fieldCamera);
    FIELD_CAMERA_SetMode(demoCamera->fieldCamera, FK_CAMERA_MODE_FREE);
    demoCamera->savedAreasEnabled = FIELD_CAMERA_GetAreasEnabled(demoCamera->fieldCamera);
    FIELD_CAMERA_SetAreasEnabled(demoCamera->fieldCamera, 0);
    FIELD_CAMERA_StopTargetTrace(demoCamera->fieldCamera);
    zeroShiftPtr = (VecFx32 *)zeroShift;
    zeroShiftPtr->x = 0;
    zeroShiftPtr->y = 0;
    zeroShiftPtr->z = 0;
    FIELD_CAMERA_GetTargetShift(demoCamera->fieldCamera, &demoCamera->savedTargetShift);
    FIELD_CAMERA_SetTargetShift(demoCamera->fieldCamera, zeroShiftPtr);
    FIELD_CAMERA_GetG3dUp(demoCamera->fieldCamera, &demoCamera->savedUp);
    FIELD_FK_DEMO_ApplyCameraAnime(demoCamera);
    demoCamera->endSettingId = gFkDemoCameraSettingId[variant];
}

/* Gives the field camera back and deletes the demo camera. */
void FIELD_FK_DEMO_ExitCamera(FkDemoCamera *demoCamera)
{
    FIELD_CAMERA_ResumeTargetTrace(demoCamera->fieldCamera);
    FIELD_CAMERA_SetTarget(demoCamera->fieldCamera, FIELD_CAMERA_GetTraceTarget(demoCamera->fieldCamera));
    FIELD_CAMERA_SetTargetShift(demoCamera->fieldCamera, &demoCamera->savedTargetShift);
    FIELD_CAMERA_SetMode(demoCamera->fieldCamera, demoCamera->savedMode);
    FIELD_CAMERA_SetAreasEnabled(demoCamera->fieldCamera, demoCamera->savedAreasEnabled);
    FIELD_CAMERA_SetG3dUp(demoCamera->fieldCamera, &demoCamera->savedUp);
    FIELD_CAMERA_SetSetting(demoCamera->fieldCamera, demoCamera->endSettingId);
    FIELD_CAMERA_RestartDelay(demoCamera->fieldCamera);
    G3D_CAMERA_Delete(demoCamera->g3dCamera);
    ICA_ANIME_Delete(demoCamera->anime);
    MI_CpuFill8(demoCamera, 0, sizeof(FkDemoCamera));
}

/*
 * Advances the camera animation by one frame; returns 1 on the last frame.
 *
 * note:     twin of the head of FIELD_FK_SOUND_ANIME_Step (same clock read and clamp),
 *           with the frame counter at +0x28. EXACT* = 54 bytes of code plus
 *           2 bytes of alignment padding before matched FIELD_FK_DEMO_ApplyCameraAnime.
 */
int FIELD_FK_DEMO_StepCamera(FkDemoCamera *demoCamera)
{
    int done;
    s32 length = ICA_ANIME_GetFrameNum(demoCamera->anime) << 12;
    s32 nextFrame = demoCamera->frame + 0x1000;

    if (length <= nextFrame) {
        done = 1;
        demoCamera->frame = length - 0x1000;
    } else {
        done = 0;
        demoCamera->frame = nextFrame;
    }
    ICA_ANIME_SetFrame(demoCamera->anime, demoCamera->frame);
    FIELD_FK_DEMO_ApplyCameraAnime(demoCamera);
    return done;
}

/* Applies the ICA animation to the demo camera and copies its eye, target and up vector, moved by the demo origin, to the field camera. */
void FIELD_FK_DEMO_ApplyCameraAnime(FkDemoCamera *demoCamera)
{
    VecFx32 target;
    VecFx32 eye;
    VecFx32 up;

    ICA_ANIME_SetCameraStatus(demoCamera->g3dCamera, demoCamera->anime);
    G3D_CAMERA_GetEye(demoCamera->g3dCamera, &eye);
    G3D_CAMERA_GetCamTarget(demoCamera->g3dCamera, &target);
    G3D_CAMERA_GetCamUp(demoCamera->g3dCamera, &up);
    VEC_Add(&eye, &gFkDemoOrigin, &eye);
    VEC_Add(&target, &gFkDemoOrigin, &target);
    FIELD_CAMERA_SetEyeRaw(demoCamera->fieldCamera, &eye);
    FIELD_CAMERA_SetTarget(demoCamera->fieldCamera, &target);
    FIELD_CAMERA_SetG3dUp(demoCamera->fieldCamera, &up);
}

/*
 * Loads the stand-in player model and its two animations of the variant
 * from archive 0x96 (six files per variant, gender selects the model).
 */
void FIELD_FK_DEMO_InitModel(FkDemoModel *model, struct FieldPlayer *player, struct MyStatus *myStatus, int heapId, int variant)
{
    struct ArcFile *arc;
    int fileBase;

    variant = (u32)variant; /* stand-in: the plain unsigned parameter gives other registers (checked) */
    arc = ARC_TOOL_CreateHandle(FK_DEMO_ARC_ID, (u16)((heapId & 0x7fff) | 0x8000));
    model->animeFrame = 0;
    model->playerHidden = 0;
    model->endTile = gFkDemoEndTile[variant];
    model->myStatus = myStatus;
    model->endDir = gFkDemoEndDir[variant];
    model->player = player;
    model->playerMmdl = FIELD_PLAYER_GetMmdl(player);
    model->status.trans = gFkDemoOrigin;
    model->status.scale.x = 0x1000;
    model->status.scale.y = 0x1000;
    model->status.scale.z = 0x1000;
    MTX_Identity33_(&model->status.rotate);
    if (MYSTATUS_GetSex(myStatus) == 0) {
        fileBase = variant * FK_DEMO_MODEL_FILE_STEP;
        model->modelRes = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)arc, fileBase + 3);
        model->genderAnimeRes = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)arc, fileBase + 4);
    } else {
        fileBase = variant * FK_DEMO_MODEL_FILE_STEP;
        model->modelRes = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)arc, fileBase + 1);
        model->genderAnimeRes = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)arc, fileBase + 2);
    }
    model->sharedAnimeRes = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)arc, fileBase + 5);
    G3D_SYSTEM_AllocVramTexture(model->modelRes);
    model->uploadPending = 1;
    ARC_TOOL_DeleteHandle(arc);
}

/* Builds the render object and the two animations of the model and starts both at frame 0. */
void FIELD_FK_DEMO_CreateModelObject(FkDemoModel *model)
{
    int i;
    int frame;

    i = 0;
    model->render = G3D_SYSTEM_CreateRender(model->modelRes, 0, model->modelRes);
    model->anime[0] = G3D_SYSTEM_CreateAnime(model->render, model->sharedAnimeRes, 0);
    model->anime[1] = G3D_SYSTEM_CreateAnime(model->render, model->genderAnimeRes, 0);
    model->object = G3D_SYSTEM_CreateObject(model->render, model->anime, 2);
    frame = 0;
    for (; i < 2; i++) {
        G3D_SYSTEM_SetObjectAnimeFrame(model->object, (u16)i, &frame);
        G3D_SYSTEM_EnableObjectAnime(model->object, (u16)i);
    }
}

/* Deletes the render object, the animations and the resources of the model. */
void FIELD_FK_DEMO_DeleteModel(FkDemoModel *model)
{
    G3D_SYSTEM_DeleteObject(model->object);
    G3D_SYSTEM_DeleteAnime(model->anime[0]);
    G3D_SYSTEM_DeleteAnime(model->anime[1]);
    G3D_SYSTEM_DeleteRender(model->render);
    G3D_SYSTEM_FreeVramTexture(model->modelRes);
    G3D_SYSTEM_DeleteResource(model->modelRes);
    G3D_SYSTEM_DeleteResource(model->sharedAnimeRes);
    G3D_SYSTEM_DeleteResource(model->genderAnimeRes);
}

/* Advances both model animations by one frame; returns 1 on the last frame. */
int FIELD_FK_DEMO_StepModel(FkDemoModel *model)
{
    int length;
    int limit;
    int done;

    length = FIELD_FK_DEMO_GetAnimeEndFrame(model->anime[0]);
    limit = model->animeFrame + 0x1000;
    if (length <= limit) {
        done = 1;
        model->animeFrame = length - 0x1000;
    } else {
        done = 0;
        model->animeFrame = limit;
    }
    G3D_SYSTEM_SetObjectAnimeFrame(model->object, 0, &model->animeFrame);
    G3D_SYSTEM_SetObjectAnimeFrame(model->object, 1, &model->animeFrame);
    return done;
}

/*
 * Hides the real player model while the demo runs. With hide 0 it shows it
 * again at the end tile and facing of the variant and moves the player there.
 */
void FIELD_FK_DEMO_SetPlayerHidden(FkDemoModel *model, int hide)
{
    VecFx32 pos;

    if (hide) {
        model->playerHidden = 1;
        FLDMMDL_SetStatusBitVanish(model->playerMmdl, 1);
        return;
    }
    model->playerHidden = 0;
    FLDMMDL_SetStatusBitVanish(model->playerMmdl, 0);
    FLDMMDL_InitGridPosition(model->playerMmdl, (s16)(model->endTile.x), (s16)(model->endTile.y),
                  (s16)(model->endTile.z), model->endDir);
    FLDMMDL_MOVE_UpdateHeight(model->playerMmdl);
    FLDMMDL_GetPos(model->playerMmdl, (struct MmdlVec *)(&pos));
    FIELD_PLAYER_SetPos(model->player, &pos);
    FLDMMDL_SetMoveBitReflect(model->playerMmdl, 0);
}

/* Uploads the model resource once (called by the task every frame until then). */
void FIELD_FK_DEMO_UploadModelOnce(FkDemoModel *model)
{
    if (model->uploadPending != 0) {
        G3D_SYSTEM_TransAllocatedTexture(model->modelRes);
        model->uploadPending = 0;
    }
}

/* Draws the stand-in model. */
void FIELD_FK_DEMO_DrawModel(FkDemoModel *model)
{
    G3D_SYSTEM_DrawObject(model->object, &model->status);
}

/*
 * Draw callback of the draw proc (template gFkDemoDrawTemplate).
 *
 * Addresses are Black-image addresses.
 */
void FIELD_FK_DEMO_DrawProc(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkDemoDrawWork *work)
{
    FIELD_FK_DEMO_DrawModel(work->model);
}

/*
 * Creates the sound anime of the variant, or clears the slot for a variant
 * without one.
 *
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of FIELD_FK_SOUND_ANIME_Create's u16 parameter (an int heap adds lsls/lsrs).
 */
void FIELD_FK_DEMO_CreateSoundAnime(FkSoundAnime **out, int variant, u16 heapId)
{
    if (gFkDemoHasSoundAnime[variant] != 0) {
        *out = FIELD_FK_SOUND_ANIME_Create(gFkSoundAnimeSoundIds[variant], FK_DEMO_ARC_ID, variant + FK_SOUND_ANIME_FILE, 10, heapId);
        return;
    }
    MI_CpuFill8(out, 0, 4);
}

/* Deletes the sound anime and clears the slot. */
void FIELD_FK_DEMO_DeleteSoundAnime(FkSoundAnime **soundAnime)
{
    if (*soundAnime != 0) {
        FIELD_FK_SOUND_ANIME_Delete(*soundAnime);
    }
    MI_CpuFill8(soundAnime, 0, 4);
}

/* Steps the sound anime; returns 1 when it ended or there is none. */
int FIELD_FK_DEMO_StepSoundAnime(FkSoundAnime **soundAnime)
{
    int done = 1;

    if (*soundAnime != 0) {
        done = FIELD_FK_SOUND_ANIME_Step(*soundAnime);
    }
    return done;
}

/*
 * Init of the proc that ties sounds to the animation of a building model
 * (template gFkBuildSoundTemplate): starts the loop sound and finds the first trigger
 * frame that lies ahead.
 */
void FIELD_FK_BUILD_SOUND_Init(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work)
{
    struct BuildModelMan *man;
    u32 i;
    int frame;

    man = FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(fieldMap));
    i = 0;
    work->entry = FIELD_BUILDMODEL_GetFirstEntryNearPos(man, 0, &gFkBuildSoundModelPos);
    work->man = man;
    frame = FIELD_BUILDMODEL_GetEntrySlotFrame(man, work->entry, 1);
    work->triggerFrame = 0x6000;
    work->triggerIndex = i;
    for (; i < 1; i++) {
        if (frame < gFkBuildSoundTriggerFrame[i]) {
            work->triggerFrame = gFkBuildSoundTriggerFrame[i];
            work->triggerIndex = i;
            break;
        }
    }
    FIELD_SOUND_SYSTEM_ClaimSlot(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FK_SE_BUILD_ANIME_LOOP);
}

/* Exit of that proc: stops the loop sound. */
void FIELD_FK_BUILD_SOUND_Exit(struct FieldSubproc *proc, struct FieldMap *fieldMap)
{
    FIELD_SOUND_SYSTEM_ReleaseSlot(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FK_SE_BUILD_ANIME_LOOP);
}

/* Update of that proc: plays the hit sound when the building animation reaches the trigger frame. */
void FIELD_FK_BUILD_SOUND_Update(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work)
{
    struct FieldSoundSystem *soundSys;

    if (work->triggerFrame == FIELD_BUILDMODEL_GetEntrySlotFrame(work->man, work->entry, 1)) {
        soundSys = GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
        work->triggerIndex = 0;
        work->triggerFrame = gFkBuildSoundTriggerFrame[work->triggerIndex];
        FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, FK_SE_BUILD_ANIME_HIT);
    }
}
