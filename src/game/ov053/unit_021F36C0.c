/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3734, func_021F3778, func_021F3828, func_021F3978, func_021F39BC, func_021F39D0, func_021F3A04, func_021F3A38, func_021F3A5C, func_021F3A6C, func_021F3A7C, func_021F3AA0, func_021F3B10, func_021F3B20, func_021F3B30
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   d_021F3D60     0x021F3D60  data  a4
 *   func_021897BC  0x021897BC  thumb
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   func_021C4DA8  0x021C4DA8  thumb  ov021
 *   func_021897A0  0x021897A0  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218ECB4  0x0218ECB4  thumb  ov021
 *   ISS_3DS_SYS_SetCamera  0x0202B93C  thumb
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021F3B40  0x021F3B40  thumb  ov053
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4D7C  0x021C4D7C  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021F3CF0     0x021F3CF0  data  a4
 *   func_02048F74 0x02048F74 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 *   func_021C4E08 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 *   _fflt  0x0209BDBC  arm
 *   _fdiv  0x0209CE10  arm
 *   _fleq  0x0209BC0C  arm
 *   _fls   0x0209BC74  arm
 *   _fsub  0x0209CB8C  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02082A7C 0x02082A7C arm
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F3734(struct FieldMap *fieldMap);
void func_021F3778(struct FieldMap *fieldMap);
void func_021F3828(Gimmick53Work *work, struct FieldMap *fieldMap);
void func_021F3978(Gimmick53Work *work);
void func_021F39BC(Gimmick53Work *work);
void func_021F39D0(Gimmick53Work *work, struct FieldMap *fieldMap);
void func_021F3A04(Gimmick53Work *work, struct FieldMap *fieldMap);
void func_021F3A38(Gimmick53Work *work, int index);
void func_021F3A5C(Gimmick53Work *work, int index);
void func_021F3A6C(Gimmick53Work *work);
void func_021F3A7C(Gimmick53Work *work, struct FieldMap *fieldMap);
int func_021F3AA0(Gimmick53Work *work, struct FieldMap *fieldMap);
void func_021F3B10(Gimmick53Work *work, int target);
void func_021F3B20(Gimmick53Work *work, int target);
void func_021F3B30(Gimmick53SlideSe *slideSe);

extern G3dUtilSetup d_021F3D60;
extern Gimmick53WaitMembers d_021F3CF0;

/* Gimmick init: adds the expansion unit, creates the sound objects and starts them at the saved frames. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    u32 heapId;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;
    Gimmick53Work *work;

    heapId = func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    func_021BE760(expObj, &d_021F3D60, 0);
    func_021BE700(expObj, 0, 4, 0, 1);
    anime = func_021BE674(expObj, 0, 4, 0);
    func_021BE6B0(anime, 0);
    func_021BE6B8(anime, 1);
    work = func_02189764(fieldMap, 0, heapId, sizeof(Gimmick53Work));
    func_021F3828(work, fieldMap);
    func_021F3A04(work, fieldMap);
    ISS_3DS_SYS_SetVolume(work->iss3ds, GIMMICK53_BGM_VOLUME_MAX);
}

/* Gimmick exit: silences the sound system, saves the frames and deletes the sound objects. */
void func_021F3734(struct FieldMap *fieldMap)
{
    int i;
    Gimmick53Work *work = func_021897BC(fieldMap, 0);

    ISS_3DS_SYS_SetVolume(work->iss3ds, 0);
    GFL_USE_SetBgmTrackVolume(work->bgmFade.track, 0);
    func_021F39D0(work, fieldMap);
    for (i = 0; i < GIMMICK53_SOUND_OBJ_COUNT; i++)
        func_021C4DA8(work->soundObj[i]);
    func_021897A0(fieldMap, 0);
}

/* Gimmick update: moves the listener to the camera, runs the sound objects, the music fade and the sliding sound. */
void func_021F3778(struct FieldMap *fieldMap)
{
    int i;
    struct FieldCamera *camera;
    Gimmick53Work *work;
    VecFx32 eye;
    VecFx32 target;

    work = func_021897BC(fieldMap, 0);
    camera = func_02188C58(fieldMap);
    func_0218ECE4(camera, &eye);
    func_0218ECB4(camera, &target);
    ISS_3DS_SYS_SetCamera(work->iss3ds, &eye, &target);
    for (i = 0; i < GIMMICK53_SOUND_OBJ_COUNT; i++) {
        if (work->waitFrames[i] > 0) {
            if (--work->waitFrames[i] <= 0) {
                func_021F3A5C(work, i);
                switch (i) {
                case 0:
                    work->waitFrames[1] = 1;
                    break;
                case 2:
                    work->waitFrames[3] = 1;
                    break;
                }
            }
        } else if (func_021C4DE4(work->soundObj[i], 0x1000)) {
            func_021F3A38(work, i);
        }
    }
    func_021F3A7C(work, fieldMap);
    func_021F3A6C(work);
    func_021BE580(func_02188D2C(fieldMap));
    func_021F3B40(&work->slideSe, camera, func_02188CB4(fieldMap));
}

/* Creates the five sound objects on the models of the unit; their parameters come from the sound archive. */
void func_021F3828(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int i;
    int heapId;
    FldExpObjCnt *expObj;
    struct SoundObj *soundObj;
    int *params;

    heapId = func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    work->heapId = heapId;
    work->bgmVolume = 0;
    work->iss3ds = func_0202B57C(func_02012134(func_02188C80(fieldMap)));
    params = func_02048F60(GIMMICK53_ARC_ID, 1, heapId);
    soundObj = func_021C4D14(fieldMap, &func_021BE480(expObj, 0, 0)->trans, 8, params[0] << 12, params[1]);
    func_021C4DC0(soundObj, GIMMICK53_ARC_ID, 3, 10);
    work->soundObj[0] = soundObj;
    func_020307B0(params);
    soundObj = func_021C4D7C(fieldMap, func_021BE480(expObj, 0, 1));
    func_021C4DC0(soundObj, GIMMICK53_ARC_ID, 5, 10);
    work->soundObj[1] = soundObj;
    params = func_02048F60(GIMMICK53_ARC_ID, 6, heapId);
    soundObj = func_021C4D14(fieldMap, &func_021BE480(expObj, 0, 2)->trans, 9, params[0] << 12, params[1]);
    func_021C4DC0(soundObj, GIMMICK53_ARC_ID, 8, 10);
    work->soundObj[2] = soundObj;
    func_020307B0(params);
    soundObj = func_021C4D7C(fieldMap, func_021BE480(expObj, 0, 3));
    func_021C4DC0(soundObj, GIMMICK53_ARC_ID, 10, 10);
    work->soundObj[3] = soundObj;
    params = func_02048F60(GIMMICK53_ARC_ID, 12, heapId);
    soundObj = func_021C4D14(fieldMap, &func_021BE480(expObj, 0, 4)->trans, 7, params[0] << 12, params[1]);
    func_021C4DC0(soundObj, GIMMICK53_ARC_ID, 11, 10);
    work->soundObj[4] = soundObj;
    func_020307B0(params);
    for (i = 0; i < GIMMICK53_SOUND_OBJ_COUNT; i++)
        work->waitFrames[i] = 0;
    func_021F3978(work);
    func_021F39BC(work);
    func_021F3B30(&work->slideSe);
}

/* Reads the wait limits of each object from the sound archive. */
void func_021F3978(Gimmick53Work *work)
{
    Gimmick53WaitMembers members = d_021F3CF0;
    int i;

    for (i = 0; i < GIMMICK53_SOUND_OBJ_COUNT; i++) {
        int *limits = func_02048F60(GIMMICK53_ARC_ID, members.member[i], work->heapId);
        work->minWait[i] = limits[0];
        work->maxWait[i] = limits[1];
        func_020307B0(limits);
    }
}

/* Reads the music track and the camera heights of its fade from the sound archive. */
void func_021F39BC(Gimmick53Work *work)
{
    func_02048F74(&work->bgmFade, GIMMICK53_ARC_ID, 0, 0, sizeof(Gimmick53BgmFade));
}

/* Saves the animation frame of each sound object in the gimmick work. */
void func_021F39D0(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int i;
    Gimmick53Save *save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK53_SAVE_SLOT);

    for (i = 0; i < GIMMICK53_SOUND_OBJ_COUNT; i++)
        save->animeFrame[i] = (int)func_021C4E20(work->soundObj[i]) >> 12;
}

/* Sets the animation of each sound object to the saved frame. */
void func_021F3A04(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int i;
    Gimmick53Save *save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK53_SAVE_SLOT);

    for (i = 0; i < GIMMICK53_SOUND_OBJ_COUNT; i++)
        func_021C4E08(work->soundObj[i], (int)((unsigned)save->animeFrame[i] << 12));
}

/*
 * Starts the wait before the next play of one sound object: a random time
 * between its limits.
 * note: Inline random call keeps the returned value on the right of the add.
 *       The final two bytes of the handed extent are alignment padding.
 */
void func_021F3A38(Gimmick53Work *work, int index)
{
    work->waitFrames[index] = work->minWait[index] +
        func_02005728(work->maxWait[index] - work->minWait[index] + 1);
}

/* Restarts the animation of one sound object at its first frame. */
void func_021F3A5C(Gimmick53Work *work, int index)
{
    func_021C4E08(work->soundObj[index], 0);
}

/* Applies the music volume to the fading track. */
void func_021F3A6C(Gimmick53Work *work)
{
    GFL_USE_SetBgmTrackVolume(work->bgmFade.track, work->bgmVolume);
}

/* Moves the music volume one step towards the volume of the camera height. */
void func_021F3A7C(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    int target = func_021F3AA0(work, fieldMap);

    if (work->bgmVolume < target)
        func_021F3B10(work, target);
    else if (target < work->bgmVolume)
        func_021F3B20(work, target);
}

/* Music volume of the camera height: 0 below the low height, the maximum above the high height, linear between. */
int func_021F3AA0(Gimmick53Work *work, struct FieldMap *fieldMap)
{
    VecFx32 eye;
    float height;
    float range;

    func_0218ECE4(func_02188C58(fieldMap), &eye);
    height = eye.y / 4096.0f;
    if (height <= work->bgmFade.heightLow)
        return 0;
    if (work->bgmFade.heightHigh < height)
        return GIMMICK53_BGM_VOLUME_MAX;
    range = work->bgmFade.heightHigh - work->bgmFade.heightLow;
    return (int)(127.0f * (height - work->bgmFade.heightLow) / range);
}

/* Raises the music volume by one step, up to the target. */
void func_021F3B10(Gimmick53Work *work, int target)
{
    work->bgmVolume += GIMMICK53_BGM_VOLUME_STEP;
    if (target < work->bgmVolume)
        work->bgmVolume = target;
}

/* Lowers the music volume by one step, down to the target. */
void func_021F3B20(Gimmick53Work *work, int target)
{
    work->bgmVolume -= GIMMICK53_BGM_VOLUME_STEP;
    if (work->bgmVolume < target)
        work->bgmVolume = target;
}

/* Clears the state of the sliding sound. */
void func_021F3B30(Gimmick53SlideSe *slideSe)
{
    func_02082A7C(0, slideSe, sizeof(Gimmick53SlideSe));
}
