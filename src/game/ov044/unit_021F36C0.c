/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK44_Exit, GIMMICK44_Update, GIMMICK44_CallEvent, GIMMICK44_LiftEventMain, GIMMICK44_IsLiftArrived, GIMMICK44_ShowIdleAnime
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
 *   sGimmick44ExpObjUnitDesc     0x021F39E8  data  ov044
 *   sGimmick44LiftStartPos     0x021F3A1C  data  a4
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
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 */
#include "unit_021F36C0_types.h"

struct GameEvent;

extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern u16 FIELDMAP_GetHeapId(u8 *fieldMap);
extern void *FIELDMAP_AllocCommonWork(unsigned char *fieldMap, int id, int a, int size);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *expObj, void *unitDesc, int b);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, unsigned unit, int model);
extern void FLD_EXP_OBJ_SetModelCullDraw(void *expObj, int unit, int model, int visible);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, unsigned int model, int animeIdx);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *anime, int paused);
extern void *FIELDMAP_GetCommonWork(void *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(void *fieldMap, int id);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *expObj, u16 unit);
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, int model, int animeIdx, int enabled);
extern struct GameEvent *func_020122C0(void *owner, void *a, void *eventFunc, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void *FIELDMAP_GetCamera(void *fieldMap);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *camera);
extern void FIELD_CAMERA_StopTargetTrace(u8 *camera);
extern void FIELD_CAMERA_SetTraceTarget(u8 *camera, int target);
extern void func_020061E4(u32 seId);
extern int FLD_EXP_OBJ_IsAnimeStopped(void *anime);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void FIELD_PLAYER_GetPos(unsigned char *player, VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *player, VecFx32 *pos);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *expObj, int unit, int model, int animeIdx, int frame);
void func_021F36C0(void *fieldMap);
void GIMMICK44_Exit(u8 *fieldMap);
void GIMMICK44_Update(void *fieldMap);
void GIMMICK44_CallEvent(void *gameSystem, int isDescending);
int GIMMICK44_LiftEventMain(void *event, int *seq);
int GIMMICK44_IsLiftArrived(Gimmick44Work *work);
void GIMMICK44_ShowIdleAnime(void *expObj);
extern int sGimmick44ExpObjUnitDesc;
extern VecFx32 sGimmick44LiftStartPos;


void func_021F36C0(void *fieldMap)
{
    void *expObj;
    VecFx32 *modelPos;
    void *anime;
    int animeIdx;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(Gimmick44Work));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sGimmick44ExpObjUnitDesc, 0);
    modelPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0);
    *modelPos = sGimmick44LiftStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, 0, 1);
    for (animeIdx = 0; animeIdx < 2; animeIdx++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, (u16)animeIdx);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    }
    GIMMICK44_ShowIdleAnime(expObj);
}

void GIMMICK44_Exit(u8 *fieldMap)
{
    void *expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}


void GIMMICK44_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}


void GIMMICK44_CallEvent(void *gameSystem, int isDescending)
{
    void *fieldMap;
    Gimmick44Work *work;
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
    func_020122C0(gameSystem, 0, GIMMICK44_LiftEventMain, 0);
}


/*
 * Once filed EXACT* because the extent ran into the unlabelled leaf GIMMICK44_IsLiftArrived
 * (filed as ov044_func_021F390C.c).
 */
int GIMMICK44_LiftEventMain(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    Gimmick44Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    switch (*seq) {
    case 0:
        if (work->isDescending != 0) {
            work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
            FIELD_CAMERA_StopTargetTrace(camera);
        }
        func_020061E4(work->isDescending == 0 ? 0x6da : 0x6ca);
        (*seq)++;
        break;
    case 1:
        work->curY += work->stepY;
        if (GIMMICK44_IsLiftArrived(work)) {
            work->curY = work->goalY;
            if (work->isDescending == 0) {
                func_020061E4(0x6cb);
            }
            (*seq)++;
        }
        FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->y = work->curY;
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
            GIMMICK44_ShowIdleAnime(expObj);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Unlabelled leaf called only from GIMMICK44_LiftEventMain.
 */
int GIMMICK44_IsLiftArrived(Gimmick44Work *work)
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


void GIMMICK44_ShowIdleAnime(void *expObj)
{
    void *anime;

    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 1, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, 0, 1, 0);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimePaused(anime, 1);
}
