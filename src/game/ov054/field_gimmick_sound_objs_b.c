/*
 * file:     field_gimmick_sound_objs_b.c
 * unit:     yes
 * function: FIELD_GIMMICK_SOUND_OBJS_B_Init, FIELD_GIMMICK_SOUND_OBJS_B_Exit, FIELD_GIMMICK_SOUND_OBJS_B_Update, FIELD_GIMMICK_SOUND_OBJS_B_CreateSoundObjs, FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits, FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames, FIELD_GIMMICK_SOUND_OBJS_B_ExitSoundObjs, FIELD_GIMMICK_SOUND_OBJS_B_StartWait, FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime
 * address:  0x021F36C0
 * region:   ov054
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   sSoundObjsBUnitSetup     0x021F39A0  data  a4
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   SOUND_OBJ_Delete 0x021C4DA8 thumb ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   ISS_3DS_SYS_SetCamera  0x0202B93C  thumb
 *   SOUND_OBJ_AdvanceAnime  0x021C4DE4  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime  0x021F393C  thumb  ov054
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   SOUND_OBJ_SetAnime  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   sSoundObjsBWaitMembers 0x021F394C data a4
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   SOUND_OBJ_GetAnimeFrame 0x021C4E20 thumb ov021
 *   SOUND_OBJ_SetAnimeFrame 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_sound_objs_b_types.h"

void FIELD_GIMMICK_SOUND_OBJS_B_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_CreateSoundObjs(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits(FieldGimmickSoundObjsBWork *work);
void FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_ExitSoundObjs(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_StartWait(FieldGimmickSoundObjsBWork *work, int index);

extern G3dUtilSetup sSoundObjsBUnitSetup;
extern FieldGimmickSoundObjsBWaitMembers sSoundObjsBWaitMembers;
/* Sound object and gimmick work of field_gimmick_sound_objs_b.c; only the fields used here. */
struct SoundObj;
extern void SOUND_OBJ_SetAnimeFrame(struct SoundObj *obj, int frame);

/* Gimmick init: adds the expansion unit, creates the sound objects and starts them at the saved frames. */
void FIELD_GIMMICK_SOUND_OBJS_B_Init(struct FieldMap *fieldMap)
{
    unsigned heapId;
    FieldGimmickSoundObjsBWork *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    FLD_EXP_OBJ_AddUnit(FIELDMAP_GetExpObj(fieldMap), &sSoundObjsBUnitSetup, 0);
    work = FIELDMAP_AllocCommonWork(fieldMap, 0, heapId, sizeof(FieldGimmickSoundObjsBWork));
    FIELD_GIMMICK_SOUND_OBJS_B_CreateSoundObjs(work, fieldMap);
    FIELD_GIMMICK_SOUND_OBJS_B_ExitSoundObjs(work, fieldMap);
    ISS_3DS_SYS_SetVolume(work->iss3ds, 0x7f);
}

/* Gimmick exit: silences the sound system, saves the frames and deletes the sound objects. */
void FIELD_GIMMICK_SOUND_OBJS_B_Exit(struct FieldMap *fieldMap)
{
    int i;
    FieldGimmickSoundObjsBWork *work = FIELDMAP_GetCommonWork(fieldMap, 0);

    ISS_3DS_SYS_SetVolume(work->iss3ds, 0);
    FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames(work, fieldMap);
    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT; i++)
        SOUND_OBJ_Delete(work->soundObj[i]);
    FIELDMAP_FreeCommonWork(fieldMap, 0);
}

/* Gimmick update: moves the listener to the camera and runs the wait or the animation of each sound object. */
void FIELD_GIMMICK_SOUND_OBJS_B_Update(struct FieldMap *fieldMap)
{
    int i;
    FieldGimmickSoundObjsBWork *work;
    struct G3dCamera *camera;
    VecFx32 eye;
    VecFx32 target;

    work = FIELDMAP_GetCommonWork(fieldMap, 0);
    camera = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera(fieldMap));
    G3D_CAMERA_GetEye(camera, &eye);
    G3D_CAMERA_GetUp(camera, &target);
    ISS_3DS_SYS_SetCamera(work->iss3ds, &eye, &target);
    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT; i++) {
        if (work->waitFrames[i] > 0) {
            work->waitFrames[i]--;
            if (work->waitFrames[i] <= 0)
                FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime(work, i);
        } else if (SOUND_OBJ_AdvanceAnime(work->soundObj[i], 0x1000)) {
            FIELD_GIMMICK_SOUND_OBJS_B_StartWait(work, i);
        }
    }
}

/* Creates the two sound objects on the models of the unit; their parameters come from the sound archive. */
void FIELD_GIMMICK_SOUND_OBJS_B_CreateSoundObjs(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    struct SoundObj *soundObj;
    int heapId;
    int *params;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work->heapId = heapId;
    work->iss3ds = func_0202B57C(GAMESYSTEM_GetIssSystem(FIELDMAP_GetGameSystem(fieldMap)));
    params = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_B_ARC_ID, 1, heapId);
    soundObj = func_021C4D14(fieldMap, &FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->trans, 8, params[0] << 12, params[1]);
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_B_ARC_ID, 3, 10);
    work->soundObj[0] = soundObj;
    func_020307B0(params);
    params = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_B_ARC_ID, 2, heapId);
    soundObj = func_021C4D14(fieldMap, &FLD_EXP_OBJ_GetModelStatus(expObj, 0, 1)->trans, 9, params[0] << 12, params[1]);
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_B_ARC_ID, 4, 10);
    work->soundObj[1] = soundObj;
    func_020307B0(params);
    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT; i++)
        work->waitFrames[i] = 0;
    FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits(work);
}

/* Reads the wait limits of each object from the sound archive. */
void FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits(FieldGimmickSoundObjsBWork *work)
{
    FieldGimmickSoundObjsBWaitMembers members = sSoundObjsBWaitMembers;
    int i;

    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT; i++) {
        int *limits = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_B_ARC_ID, members.member[i], work->heapId);
        work->minWait[i] = limits[0];
        work->maxWait[i] = limits[1];
        func_020307B0(limits);
    }
}

/* Saves the animation frame of each sound object in the gimmick work. */
void FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap)
{
    FieldGimmickSoundObjsBSave *save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_SOUND_OBJS_B_SAVE_SLOT);
    int i;

    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT; i++) {
        int frame = SOUND_OBJ_GetAnimeFrame(work->soundObj[i]);
        save->animeFrame[i] = frame >> 12;
    }
}

/* Sets the animation of each sound object to the saved frame. */
void FIELD_GIMMICK_SOUND_OBJS_B_ExitSoundObjs(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap)
{
    FieldGimmickSoundObjsBSave *save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_SOUND_OBJS_B_SAVE_SLOT);
    int i;

    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT; i++)
        SOUND_OBJ_SetAnimeFrame(work->soundObj[i], (int)((unsigned)save->animeFrame[i] << 12));
}

/* Starts the wait before the next play of one sound object: a random time between its limits. */
void FIELD_GIMMICK_SOUND_OBJS_B_StartWait(FieldGimmickSoundObjsBWork *work, int index)
{
    work->waitFrames[index] = work->minWait[index] +
        func_02005728(work->maxWait[index] - work->minWait[index] + 1);
}

/* Restarts the animation of one sound object at its first frame. */
void FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime(FieldGimmickSoundObjsBWork *work, int index)
{
    SOUND_OBJ_SetAnimeFrame(work->soundObj[index], 0);
}
