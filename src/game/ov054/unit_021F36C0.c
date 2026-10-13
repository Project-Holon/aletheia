/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3704, func_021F373C, func_021F37B4, func_021F3874, func_021F38B0, func_021F38E4, func_021F3918
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   d_021F39A0     0x021F39A0  data  a4
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021C4DA8 0x021C4DA8 thumb ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B30  0x02048B30  arm
 *   ISS_3DS_SYS_SetCamera  0x0202B93C  thumb
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021F393C  0x021F393C  thumb  ov054
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021F394C 0x021F394C data a4
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 *   func_021C4E08 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F3704(struct FieldMap *fieldMap);
void func_021F373C(struct FieldMap *fieldMap);
void func_021F37B4(Gimmick54Work *work, struct FieldMap *fieldMap);
void func_021F3874(Gimmick54Work *work);
void func_021F38B0(Gimmick54Work *work, struct FieldMap *fieldMap);
void func_021F38E4(Gimmick54Work *work, struct FieldMap *fieldMap);
void func_021F3918(Gimmick54Work *work, int index);

extern G3dUtilSetup d_021F39A0;
extern Gimmick54WaitMembers d_021F394C;

/* Gimmick init: adds the expansion unit, creates the sound objects and starts them at the saved frames. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    unsigned heapId;
    Gimmick54Work *work;

    heapId = func_02188C84(fieldMap);
    func_021BE310(func_02188D2C(fieldMap), &d_021F39A0, 0);
    work = func_02189764(fieldMap, 0, heapId, sizeof(Gimmick54Work));
    func_021F37B4(work, fieldMap);
    func_021F38E4(work, fieldMap);
    ISS_3DS_SYS_SetVolume(work->iss3ds, 0x7f);
}

/* Gimmick exit: silences the sound system, saves the frames and deletes the sound objects. */
void func_021F3704(struct FieldMap *fieldMap)
{
    int i;
    Gimmick54Work *work = func_021897BC(fieldMap, 0);

    ISS_3DS_SYS_SetVolume(work->iss3ds, 0);
    func_021F38B0(work, fieldMap);
    for (i = 0; i < GIMMICK54_SOUND_OBJ_COUNT; i++)
        func_021C4DA8(work->soundObj[i]);
    func_021897A0(fieldMap, 0);
}

/* Gimmick update: moves the listener to the camera and runs the wait or the animation of each sound object. */
void func_021F373C(struct FieldMap *fieldMap)
{
    int i;
    Gimmick54Work *work;
    struct G3dCamera *camera;
    VecFx32 eye;
    VecFx32 target;

    work = func_021897BC(fieldMap, 0);
    camera = func_0218EC2C(func_02188C58(fieldMap));
    func_02048AE8(camera, &eye);
    func_02048B30(camera, &target);
    ISS_3DS_SYS_SetCamera(work->iss3ds, &eye, &target);
    for (i = 0; i < GIMMICK54_SOUND_OBJ_COUNT; i++) {
        if (work->waitFrames[i] > 0) {
            work->waitFrames[i]--;
            if (work->waitFrames[i] <= 0)
                func_021F393C(work, i);
        } else if (func_021C4DE4(work->soundObj[i], 0x1000)) {
            func_021F3918(work, i);
        }
    }
}

/* Creates the two sound objects on the models of the unit; their parameters come from the sound archive. */
void func_021F37B4(Gimmick54Work *work, struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    struct SoundObj *soundObj;
    int heapId;
    int *params;

    heapId = func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    work->heapId = heapId;
    work->iss3ds = func_0202B57C(func_02012134(func_02188C80(fieldMap)));
    params = func_02048F60(GIMMICK54_ARC_ID, 1, heapId);
    soundObj = func_021C4D14(fieldMap, &func_021BE480(expObj, 0, 0)->trans, 8, params[0] << 12, params[1]);
    func_021C4DC0(soundObj, GIMMICK54_ARC_ID, 3, 10);
    work->soundObj[0] = soundObj;
    func_020307B0(params);
    params = func_02048F60(GIMMICK54_ARC_ID, 2, heapId);
    soundObj = func_021C4D14(fieldMap, &func_021BE480(expObj, 0, 1)->trans, 9, params[0] << 12, params[1]);
    func_021C4DC0(soundObj, GIMMICK54_ARC_ID, 4, 10);
    work->soundObj[1] = soundObj;
    func_020307B0(params);
    for (i = 0; i < GIMMICK54_SOUND_OBJ_COUNT; i++)
        work->waitFrames[i] = 0;
    func_021F3874(work);
}

/* Reads the wait limits of each object from the sound archive. */
void func_021F3874(Gimmick54Work *work)
{
    Gimmick54WaitMembers members = d_021F394C;
    int i;

    for (i = 0; i < GIMMICK54_SOUND_OBJ_COUNT; i++) {
        int *limits = func_02048F60(GIMMICK54_ARC_ID, members.member[i], work->heapId);
        work->minWait[i] = limits[0];
        work->maxWait[i] = limits[1];
        func_020307B0(limits);
    }
}

/* Saves the animation frame of each sound object in the gimmick work. */
void func_021F38B0(Gimmick54Work *work, struct FieldMap *fieldMap)
{
    Gimmick54Save *save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK54_SAVE_SLOT);
    int i;

    for (i = 0; i < GIMMICK54_SOUND_OBJ_COUNT; i++) {
        int frame = func_021C4E20(work->soundObj[i]);
        save->animeFrame[i] = frame >> 12;
    }
}

/* Sets the animation of each sound object to the saved frame. */
void func_021F38E4(Gimmick54Work *work, struct FieldMap *fieldMap)
{
    Gimmick54Save *save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK54_SAVE_SLOT);
    int i;

    for (i = 0; i < GIMMICK54_SOUND_OBJ_COUNT; i++)
        func_021C4E08(work->soundObj[i], (int)((unsigned)save->animeFrame[i] << 12));
}

/* Starts the wait before the next play of one sound object: a random time between its limits. */
void func_021F3918(Gimmick54Work *work, int index)
{
    work->waitFrames[index] = work->minWait[index] +
        func_02005728(work->maxWait[index] - work->minWait[index] + 1);
}
