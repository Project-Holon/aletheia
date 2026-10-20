/*
 * file:     field_gimmick_lift.c
 * unit:     yes
 * function: FIELD_GIMMICK_LIFT_Init, FIELD_GIMMICK_LIFT_Exit, FIELD_GIMMICK_LIFT_Update, FIELD_GIMMICK_LIFT_CallEvent, FIELD_GIMMICK_LIFT_LiftEventMain, FIELD_GIMMICK_LIFT_IsLiftArrived, FIELD_GIMMICK_LIFT_ShowIdleAnime, FIELD_GIMMICK_LIFT_SnapLiftToBottom
 * address:  0x021F36C0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sLiftExpObjUnitDesc     0x021F39E8  data  ov044
 *   sLiftLiftStartPos     0x021F3A1C  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetWork 0x0200B3A4 thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 */
#include "field_gimmick_lift_types.h"

struct GameEvent;
struct FieldMap;
struct FldExpObjCnt;

#include "../ov021/fieldmap.h"
struct FldExpObjAnime;
#include "../ov021/fld_exp_obj.h"
struct FldExpObjAnime;
struct GameSystem;
#include "../arm9/gamesystem.h"
struct FieldCamera;
#include "../ov021/field_camera.h"
#include "../arm9/gfl_use.h"
#include "../ov021/field_player.h"
#include "../arm9/game_event.h"
void FIELD_GIMMICK_LIFT_Init(void *fieldMap);
void FIELD_GIMMICK_LIFT_Exit(u8 *fieldMap);
void FIELD_GIMMICK_LIFT_Update(void *fieldMap);
struct GameEvent *FIELD_GIMMICK_LIFT_CallEvent(struct GameSystem *gameSystem, int isDescending);
int FIELD_GIMMICK_LIFT_LiftEventMain(void *event, int *seq);
int FIELD_GIMMICK_LIFT_IsLiftArrived(FieldGimmickLiftWork *work);
void FIELD_GIMMICK_LIFT_ShowIdleAnime(void *expObj);
extern int sLiftExpObjUnitDesc;
extern VecFx32 sLiftLiftStartPos;

void FIELD_GIMMICK_LIFT_Init(void *fieldMap)
{
    void *expObj;
    VecFx32 *modelPos;
    void *anime;
    int animeIdx;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(FieldGimmickLiftWork));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, (const struct G3dUtilSetup *)&sLiftExpObjUnitDesc, 0);
    modelPos = ((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0));
    *modelPos = sLiftLiftStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, 0, 1);
    for (animeIdx = 0; animeIdx < 2; animeIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    }
    FIELD_GIMMICK_LIFT_ShowIdleAnime(expObj);
}

void FIELD_GIMMICK_LIFT_Exit(u8 *fieldMap)
{
    void *expObj = FIELDMAP_GetExpObj((struct FieldMap *)fieldMap);
    FIELDMAP_GetCommonWork((struct FieldMap *)fieldMap, 1);
    FIELDMAP_FreeCommonWork((struct FieldMap *)fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}


void FIELD_GIMMICK_LIFT_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}


struct GameEvent *FIELD_GIMMICK_LIFT_CallEvent(struct GameSystem *gameSystem, int isDescending)
{
    void *fieldMap;
    FieldGimmickLiftWork *work;
    void *expObj;
    int step;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->isDescending = isDescending;
    if (isDescending) {
        work->curY = 0;
        work->goalY = -0x50000;
    } else {
        work->curY = -0x50000;
        work->goalY = 0;
        expObj = FIELDMAP_GetExpObj(fieldMap);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 1, 0);
    }
    step = work->goalY - work->curY;
    if (step < 0) {
        step = -0x2000;
    } else {
        step = 0x2000;
    }
    work->stepY = step;
    return GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FIELD_GIMMICK_LIFT_LiftEventMain, 0);
}


/*
 * Once filed EXACT* because the extent ran into the unlabelled leaf FIELD_GIMMICK_LIFT_IsLiftArrived
 * (filed as FIELD_GIMMICK_LIFT_IsLiftArrived.c).
 */
int FIELD_GIMMICK_LIFT_LiftEventMain(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    FieldGimmickLiftWork *work;
    struct FieldCamera *camera;
    void *player;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = (struct FieldCamera *)FIELDMAP_GetCamera(fieldMap);
    switch (*seq) {
    case 0:
        if (work->isDescending != 0) {
            work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
            FIELD_CAMERA_StopTargetTrace(camera);
        }
        GFL_USE_PlaySeDefaultVolume(work->isDescending == 0 ? 0x6da : 0x6ca);
        (*seq)++;
        break;
    case 1:
        work->curY += work->stepY;
        if (FIELD_GIMMICK_LIFT_IsLiftArrived(work)) {
            work->curY = work->goalY;
            if (work->isDescending == 0) {
                GFL_USE_PlaySeDefaultVolume(0x6cb);
            }
            (*seq)++;
        }
        ((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0))->y = work->curY;
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_GetPos(player, &pos);
        pos.y = work->curY;
        FIELD_PLAYER_SetPos(player, &pos);
        break;
    case 2:
        if (work->isDescending != 0) {
            return 1;
        }
        if (work->savedCameraTarget != 0) {
            FIELD_CAMERA_SetTraceTarget(camera, work->savedCameraTarget);
        }
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 0), 0);
        (*seq)++;
        break;
    case 3:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 0))) {
            FIELD_GIMMICK_LIFT_ShowIdleAnime(expObj);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Unlabelled leaf called only from FIELD_GIMMICK_LIFT_LiftEventMain.
 */
int FIELD_GIMMICK_LIFT_IsLiftArrived(FieldGimmickLiftWork *work)
{
    if (work->stepY < 0) {
        if (work->goalY >= work->curY) {
            return 1;
        }
    } else {
        if (work->goalY <= work->curY) {
            return 1;
        }
    }
    return 0;
}


void FIELD_GIMMICK_LIFT_ShowIdleAnime(void *expObj)
{
    void *anime;

    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 1, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, 0, 1, 0);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimePaused(anime, 1);
}

/* Puts the lift at its lower end without the ride: the model and the player
 * are set to the bottom height and the camera is detached. */
void FIELD_GIMMICK_LIFT_SnapLiftToBottom(void *gameSystem)
{
    void *fieldMap;
    void *expObj;
    FieldGimmickLiftWork *work;
    struct FieldCamera *camera;
    void *player;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = (struct FieldCamera *)FIELDMAP_GetCamera(fieldMap);
    work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
    FIELD_CAMERA_StopTargetTrace(camera);
    ((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0))->y = -0x50000;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELD_PLAYER_GetPos(player, &pos);
    pos.y = -0x50000;
    FIELD_PLAYER_SetPos(player, &pos);
}
