/*
 * file:     field_gimmick_sound_objs.c
 * unit:     yes
 * function: FIELD_GIMMICK_SOUND_OBJS_Init, FIELD_GIMMICK_SOUND_OBJS_Exit, FIELD_GIMMICK_SOUND_OBJS_Update, FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs, FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits, FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade, FIELD_GIMMICK_SOUND_OBJS_SaveAnimeFrames, FIELD_GIMMICK_SOUND_OBJS_RestoreAnimeFrames, FIELD_GIMMICK_SOUND_OBJS_StartWait, FIELD_GIMMICK_SOUND_OBJS_RestartAnime, FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume, FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade, FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume, FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume, FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume, FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe, FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe
 * address:  0x021F36C0
 * region:   ov053
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
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   sGimmick53UnitSetup     0x021F3D60  data  a4
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   SOUND_OBJ_Delete  0x021C4DA8  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb  ov021
 *   FIELD_CAMERA_GetTargetRaw  0x0218ECB4  thumb  ov021
 *   ISS_3DS_SYS_SetCamera  0x0202B93C  thumb
 *   SOUND_OBJ_AdvanceAnime  0x021C4DE4  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe  0x021F3B40  thumb  ov053
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   SOUND_OBJ_CreateNoSource  0x021C4D7C  thumb  ov021
 *   SOUND_OBJ_SetAnime  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   sGimmick53WaitMembers     0x021F3CF0  data  a4
 *   ARC_TOOL_ReadMemberRange 0x02048F74 arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   SOUND_OBJ_GetAnimeFrame 0x021C4E20 thumb ov021
 *   SOUND_OBJ_SetAnimeFrame 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 *   _fflt  0x0209BDBC  arm
 *   _fdiv  0x0209CE10  arm
 *   _fleq  0x0209BC0C  arm
 *   _fls   0x0209BC74  arm
 *   _fsub  0x0209CB8C  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02082A7C 0x02082A7C arm
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GFL_USE_SetSeSlotVolume  0x020062BC  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_PLAYER_GetFormSlot  0x021A34EC  thumb  ov021
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_sound_objs_types.h"

void FIELD_GIMMICK_SOUND_OBJS_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs(Gimmick53Work *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits(Gimmick53Work *work);
void FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade(Gimmick53Work *work);
void FIELD_GIMMICK_SOUND_OBJS_SaveAnimeFrames(Gimmick53Work *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_RestoreAnimeFrames(Gimmick53Work *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_StartWait(Gimmick53Work *work, int index);
void FIELD_GIMMICK_SOUND_OBJS_RestartAnime(Gimmick53Work *work, int index);
void FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume(Gimmick53Work *work);
void FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade(Gimmick53Work *work, struct FieldMap *fieldMap);
int FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume(Gimmick53Work *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(Gimmick53Work *work, int target);
void FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume(Gimmick53Work *work, int target);
void FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(Gimmick53SlideSe *slideSe);

extern G3dUtilSetup sGimmick53UnitSetup;
extern Gimmick53WaitMembers sGimmick53WaitMembers;
struct FieldCamera;
struct FieldPlayer;
extern int GFL_USE_GetSeSlot(u32 seId);
extern int GFL_USE_IsSeSlotBusy(u32 slot);
extern void GFL_USE_StopSeSlot(int slot);
extern void GFL_USE_SetSeSlotVolume(int slot, u32 volume);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern void FIELD_CAMERA_GetEyeRaw(struct FieldCamera *camera, VecFx32 *eye);
extern int FIELD_PLAYER_GetFormSlot(struct FieldPlayer *fieldPlayer);

/* Gimmick init: adds the expansion unit, creates the sound objects and starts them at the saved frames. */
void FIELD_GIMMICK_SOUND_OBJS_Init(struct FieldMap *fieldMap)
{
    u32 heapId;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;
    Gimmick53Work *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sGimmick53UnitSetup, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 4, 0, 1);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 4, 0);
    FLD_EXP_OBJ_SetAnimePaused(anime, 0);
    FLD_EXP_OBJ_SetAnimeLoop(anime, 1);
    work = FIELDMAP_AllocCommonWork(fieldMap, 0, heapId, sizeof(Gimmick53Work));
    FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs(work, fieldMap);
    FIELD_GIMMICK_SOUND_OBJS_RestoreAnimeFrames(work, fieldMap);
    ISS_3DS_SYS_SetVolume(work->iss3ds, FIELD_GIMMICK_SOUND_OBJS_BGM_VOLUME_MAX);
}

/* Gimmick exit: silences the sound system, saves the frames and deletes the sound objects. */
void FIELD_GIMMICK_SOUND_OBJS_Exit(struct FieldMap *fieldMap)
{
    int i;
    Gimmick53Work *work = FIELDMAP_GetCommonWork(fieldMap, 0);

    ISS_3DS_SYS_SetVolume(work->iss3ds, 0);
    GFL_USE_SetBgmTrackVolume(work->bgmFade.track, 0);
    FIELD_GIMMICK_SOUND_OBJS_SaveAnimeFrames(work, fieldMap);
    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT; i++)
        SOUND_OBJ_Delete(work->soundObj[i]);
    FIELDMAP_FreeCommonWork(fieldMap, 0);
}

/* Gimmick update: moves the listener to the camera, runs the sound objects, the music fade and the sliding sound. */
void FIELD_GIMMICK_SOUND_OBJS_Update(struct FieldMap *fieldMap)
{
    int i;
    struct FieldCamera *camera;
    Gimmick53Work *work;
    VecFx32 eye;
    VecFx32 target;

    work = FIELDMAP_GetCommonWork(fieldMap, 0);
    camera = FIELDMAP_GetCamera(fieldMap);
    FIELD_CAMERA_GetEyeRaw(camera, &eye);
    FIELD_CAMERA_GetTargetRaw(camera, &target);
    ISS_3DS_SYS_SetCamera(work->iss3ds, &eye, &target);
    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT; i++) {
        if (work->waitFrames[i] > 0) {
            if (--work->waitFrames[i] <= 0) {
                FIELD_GIMMICK_SOUND_OBJS_RestartAnime(work, i);
                switch (i) {
                case 0:
                    work->waitFrames[1] = 1;
                    break;
                case 2:
                    work->waitFrames[3] = 1;
                    break;
                }
            }
        } else if (SOUND_OBJ_AdvanceAnime(work->soundObj[i], 0x1000)) {
            FIELD_GIMMICK_SOUND_OBJS_StartWait(work, i);
        }
    }
    FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade(work, fieldMap);
    FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume(work);
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
    FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe(&work->slideSe, camera, FIELDMAP_GetFieldPlayer(fieldMap));
}

/* Creates the five sound objects on the models of the unit; their parameters come from the sound archive. */
void FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int i;
    int heapId;
    FldExpObjCnt *expObj;
    struct SoundObj *soundObj;
    int *params;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work->heapId = heapId;
    work->bgmVolume = 0;
    work->iss3ds = func_0202B57C(GAMESYSTEM_GetIssSystem(FIELDMAP_GetGameSystem(fieldMap)));
    params = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 1, heapId);
    soundObj = func_021C4D14(fieldMap, &FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->trans, 8, params[0] << 12, params[1]);
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 3, 10);
    work->soundObj[0] = soundObj;
    func_020307B0(params);
    soundObj = SOUND_OBJ_CreateNoSource(fieldMap, FLD_EXP_OBJ_GetModelStatus(expObj, 0, 1));
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 5, 10);
    work->soundObj[1] = soundObj;
    params = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 6, heapId);
    soundObj = func_021C4D14(fieldMap, &FLD_EXP_OBJ_GetModelStatus(expObj, 0, 2)->trans, 9, params[0] << 12, params[1]);
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 8, 10);
    work->soundObj[2] = soundObj;
    func_020307B0(params);
    soundObj = SOUND_OBJ_CreateNoSource(fieldMap, FLD_EXP_OBJ_GetModelStatus(expObj, 0, 3));
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 10, 10);
    work->soundObj[3] = soundObj;
    params = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 12, heapId);
    soundObj = func_021C4D14(fieldMap, &FLD_EXP_OBJ_GetModelStatus(expObj, 0, 4)->trans, 7, params[0] << 12, params[1]);
    SOUND_OBJ_SetAnime(soundObj, FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 11, 10);
    work->soundObj[4] = soundObj;
    func_020307B0(params);
    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT; i++)
        work->waitFrames[i] = 0;
    FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits(work);
    FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade(work);
    FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(&work->slideSe);
}

/* Reads the wait limits of each object from the sound archive. */
void FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits(Gimmick53Work *work)
{
    Gimmick53WaitMembers members = sGimmick53WaitMembers;
    int i;

    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT; i++) {
        int *limits = ARC_TOOL_LoadMember(FIELD_GIMMICK_SOUND_OBJS_ARC_ID, members.member[i], work->heapId);
        work->minWait[i] = limits[0];
        work->maxWait[i] = limits[1];
        func_020307B0(limits);
    }
}

/* Reads the music track and the camera heights of its fade from the sound archive. */
void FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade(Gimmick53Work *work)
{
    ARC_TOOL_ReadMemberRange(&work->bgmFade, FIELD_GIMMICK_SOUND_OBJS_ARC_ID, 0, 0, sizeof(Gimmick53BgmFade));
}

/* Saves the animation frame of each sound object in the gimmick work. */
void FIELD_GIMMICK_SOUND_OBJS_SaveAnimeFrames(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int i;
    Gimmick53Save *save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_SOUND_OBJS_SAVE_SLOT);

    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT; i++)
        save->animeFrame[i] = (int)SOUND_OBJ_GetAnimeFrame(work->soundObj[i]) >> 12;
}

/* Sets the animation of each sound object to the saved frame. */
void FIELD_GIMMICK_SOUND_OBJS_RestoreAnimeFrames(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int i;
    Gimmick53Save *save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_SOUND_OBJS_SAVE_SLOT);

    for (i = 0; i < FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT; i++)
        SOUND_OBJ_SetAnimeFrame(work->soundObj[i], (int)((unsigned)save->animeFrame[i] << 12));
}

/*
 * Starts the wait before the next play of one sound object: a random time
 * between its limits.
 * note: Inline random call keeps the returned value on the right of the add.
 *       The final two bytes of the handed extent are alignment padding.
 */
void FIELD_GIMMICK_SOUND_OBJS_StartWait(Gimmick53Work *work, int index)
{
    work->waitFrames[index] = work->minWait[index] +
        func_02005728(work->maxWait[index] - work->minWait[index] + 1);
}

/* Restarts the animation of one sound object at its first frame. */
void FIELD_GIMMICK_SOUND_OBJS_RestartAnime(Gimmick53Work *work, int index)
{
    SOUND_OBJ_SetAnimeFrame(work->soundObj[index], 0);
}

/* Applies the music volume to the fading track. */
void FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume(Gimmick53Work *work)
{
    GFL_USE_SetBgmTrackVolume(work->bgmFade.track, work->bgmVolume);
}

/* Moves the music volume one step towards the volume of the camera height. */
void FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int target = FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume(work, fieldMap);

    if (work->bgmVolume < target)
        FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(work, target);
    else if (target < work->bgmVolume)
        FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume(work, target);
}

/* Music volume of the camera height: 0 below the low height, the maximum above the high height, linear between. */
int FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    VecFx32 eye;
    float height;
    float range;

    FIELD_CAMERA_GetEyeRaw(FIELDMAP_GetCamera(fieldMap), &eye);
    height = eye.y / 4096.0f;
    if (height <= work->bgmFade.heightLow)
        return 0;
    if (work->bgmFade.heightHigh < height)
        return FIELD_GIMMICK_SOUND_OBJS_BGM_VOLUME_MAX;
    range = work->bgmFade.heightHigh - work->bgmFade.heightLow;
    return (int)(127.0f * (height - work->bgmFade.heightLow) / range);
}

/* Raises the music volume by one step, up to the target. */
void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(Gimmick53Work *work, int target)
{
    work->bgmVolume += FIELD_GIMMICK_SOUND_OBJS_BGM_VOLUME_STEP;
    if (target < work->bgmVolume)
        work->bgmVolume = target;
}

/* Lowers the music volume by one step, down to the target. */
void FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume(Gimmick53Work *work, int target)
{
    work->bgmVolume -= FIELD_GIMMICK_SOUND_OBJS_BGM_VOLUME_STEP;
    if (work->bgmVolume < target)
        work->bgmVolume = target;
}

/* Clears the state of the sliding sound. */
void FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(Gimmick53SlideSe *slideSe)
{
    func_02082A7C(0, slideSe, sizeof(Gimmick53SlideSe));
}

/*
 * Plays and fades a sound effect while the camera slides down. The effect
 * starts when the camera crosses one of two lines in z and its height fell
 * by 0x64000 over the last frames; which line and effect depends on the
 * player (FIELD_PLAYER_GetFormSlot). It fades out when the camera stops past 0x718000.
 */
void FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe(Gimmick53SlideSe *slideSe, struct FieldCamera *camera, struct FieldPlayer *fieldPlayer)
{
    VecFx32 eye;
    int zDelta;
    int i;
    int volume;
    int lineZ;
    u32 seId;

    if ((u16)(slideSe->state + 0xffff) <= 1) {
        if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x7eb)) == 0) {
            slideSe->state = FIELD_GIMMICK_SOUND_OBJS_SLIDE_IDLE;
        }
        if (slideSe->state == FIELD_GIMMICK_SOUND_OBJS_SLIDE_FADING) {
            slideSe->volume -= 16;
            volume = slideSe->volume;
            if (volume < 0) {
                GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(slideSe->seId));
                slideSe->state = FIELD_GIMMICK_SOUND_OBJS_SLIDE_IDLE;
            } else {
                GFL_USE_SetSeSlotVolume(GFL_USE_GetSeSlot(slideSe->seId), volume);
            }
        }
    }
    FIELD_CAMERA_GetEyeRaw(camera, &eye);
    zDelta = slideSe->prevZ;
    zDelta = eye.z - zDelta;
    if (zDelta < 0) {
        zDelta = -zDelta;
    }
    if (zDelta > 0) {
        volume = slideSe->count;
        if (volume < FIELD_GIMMICK_SOUND_OBJS_SLIDE_HISTORY) {
            i = (slideSe->head + volume) % FIELD_GIMMICK_SOUND_OBJS_SLIDE_HISTORY;
            slideSe->count = volume + 1;
        } else {
            i = slideSe->head;
            slideSe->head = (i + 1) % FIELD_GIMMICK_SOUND_OBJS_SLIDE_HISTORY;
        }
        slideSe->cameraY[i] = eye.y;
    } else {
        slideSe->count = 0;
        slideSe->head = 0;
        if (slideSe->state == FIELD_GIMMICK_SOUND_OBJS_SLIDE_PLAYING && eye.z > 0x718000) {
            slideSe->state = FIELD_GIMMICK_SOUND_OBJS_SLIDE_FADING;
            slideSe->volume = 0x7f;
        }
    }
    if (slideSe->count > 0) {
        if (FIELD_PLAYER_GetFormSlot(fieldPlayer) == 0) {
            lineZ = 0x75c000;
            seId = 0x7ed;
        } else {
            lineZ = 0x7bc000;
            seId = 0x7eb;
        }
        if ((eye.z < lineZ && slideSe->prevZ > lineZ) || (eye.z > lineZ && slideSe->prevZ < lineZ)) {
            if (slideSe->cameraY[slideSe->head] - eye.y >= 0x64000) {
                GFL_USE_PlaySeDefaultVolume(seId);
                slideSe->state = FIELD_GIMMICK_SOUND_OBJS_SLIDE_PLAYING;
                slideSe->seId = seId;
            }
        }
    }
    slideSe->prevZ = eye.z;
}
