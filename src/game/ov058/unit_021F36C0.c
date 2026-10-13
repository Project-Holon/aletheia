/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3714, func_021F373C, func_021F38F4
 * address:  0x021F36C0
 * region:   ov058
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   d_021F3B60  0x021F3B60  data  ov058  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3038 0x021A3038 thumb ov021
 *   func_02012A30 0x02012A30 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_02006148 0x02006148 thumb
 *   func_02006224 0x02006224 thumb
 *   func_02028A7C 0x02028A7C thumb
 *   func_021F391C  0x021F391C  thumb  ov058
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern Gimmick58Work *func_021897BC(struct FieldMap *fieldMap, int id);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void func_021BE418(FldExpObjCnt *expObj, u16 unitIndex);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *pos);
extern void *func_02012A30(struct GameData *gameData);
extern u32 func_020056EC(u32 range);
extern int func_02006148(u32 seId);
extern int func_02006224(int seSlot);
extern void func_02028A7C(void *fieldSound, u32 seId);
extern void func_021F391C(Gimmick58Work *work, struct FieldMap *fieldMap, int leadModel, int trailModel);

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F3714(struct FieldMap *fieldMap);
void func_021F373C(struct FieldMap *fieldMap);
void func_021F38F4(Gimmick58Work *work, struct FieldMap *fieldMap);

extern G3dUtilSetup d_021F3B60;

/* Allocate the work, add the train models and put them at their start. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    Gimmick58Work *work;

    func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), 0x20);
    work = func_021897BC(fieldMap, 1);
    func_021BE760(expObj, &d_021F3B60, 0);
    func_021F38F4(work, fieldMap);
}

void func_021F3714(struct FieldMap *fieldMap)
{
    func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_021BE418(func_02188D2C(fieldMap), 0);
    func_021897A0(fieldMap, 1);
}

/* Per frame: move both trains, restart them after a run, play the pass sound. */
void func_021F373C(struct FieldMap *fieldMap)
{
    VecFx32 playerPos;
    int eastLeadX;
    int westLeadX;
    struct GameData *gameData;
    FldExpObjCnt *expObj;
    Gimmick58Work *work;
    Gimmick58Train *train;
    int modelIndex;
    G3dObjectStatus *model;
    void *fieldSound;
    int delta;

    gameData = func_020120F4(func_02188C80(fieldMap));
    func_02012EC4(gameData);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);

    train = &work->eastbound;
    if (train->waitFrames != 0) {
        train->waitFrames--;
    } else {
        modelIndex = train->lane * GIMMICK58_MODELS_PER_LANE;
        train->step++;
        model = func_021BE480(expObj, 0, (u16)modelIndex);
        model->trans.x = (train->step << 16) + GIMMICK58_TRACK_MIN_X;
        if (model->trans.x >= GIMMICK58_TRACK_MAX_X) {
            train->step = 0;
            work->eastSoundPlayed = 0;
            train->waitFrames = func_020056EC(30) + 30;
            train->lane = func_020056EC(3);
        }
        eastLeadX = model->trans.x;
        model = func_021BE480(expObj, 0, (u16)(modelIndex + 1));
        model->trans.x = (train->step << 16) + (GIMMICK58_TRACK_MIN_X - GIMMICK58_TRAIL_GAP);
        if (model->trans.x >= GIMMICK58_TRACK_MAX_X)
            train->step = 0;
    }

    train = &work->westbound;
    if (train->waitFrames != 0) {
        train->waitFrames--;
    } else {
        modelIndex = train->lane * GIMMICK58_MODELS_PER_LANE + 2;
        train->step++;
        model = func_021BE480(expObj, 0, (u16)modelIndex);
        model->trans.x = GIMMICK58_TRACK_MAX_X - (train->step << 16);
        if (model->trans.x <= GIMMICK58_TRACK_MIN_X) {
            train->step = 0;
            work->westSoundPlayed = 0;
            train->waitFrames = func_020056EC(30);
            train->lane = func_020056EC(3);
        }
        westLeadX = model->trans.x;
        model = func_021BE480(expObj, 0, (u16)(modelIndex + 1));
        model->trans.x = (GIMMICK58_TRACK_MAX_X + GIMMICK58_TRAIL_GAP) - (train->step << 16);
        if (model->trans.x <= GIMMICK58_TRACK_MIN_X)
            train->step = 0;
    }

    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    if (playerPos.z >= GIMMICK58_HEAR_MIN_Z && playerPos.z <= GIMMICK58_HEAR_MAX_Z) {
        fieldSound = func_02012A30(gameData);
        delta = playerPos.x - eastLeadX;
        if (delta >= 0 && delta <= GIMMICK58_HEAR_DISTANCE && work->eastSoundPlayed == 0) {
            if (func_02006224(func_02006148(0x77e)) == 0) {
                work->eastSoundPlayed = 1;
                func_02028A7C(fieldSound, 0x77e);
            }
        }
        delta = westLeadX - playerPos.x;
        if (delta >= 0 && delta <= GIMMICK58_HEAR_DISTANCE && work->westSoundPlayed == 0) {
            if (func_02006224(func_02006148(0x77f)) == 0) {
                work->westSoundPlayed = 1;
                func_02028A7C(fieldSound, 0x77f);
            }
        }
    }
}

/* Put the three sets of train models at their start. */
void func_021F38F4(Gimmick58Work *work, struct FieldMap *fieldMap)
{
    func_021F391C(work, fieldMap, 0, 1);
    func_021F391C(work, fieldMap, 4, 5);
    func_021F391C(work, fieldMap, 8, 9);
}
