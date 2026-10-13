/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F380C, func_021F3828, func_021F3834, func_021F3888, func_021F38D4
 * address:  0x021F36C0
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3A58     0x021F3A58  data  a4
 *   d_021F3AD4     0x021F3AD4  data  a4
 *   d_021F3A68     0x021F3A68  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3980  0x021F3980  thumb
 *   func_020124E4  0x020124E4  thumb
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F380C(struct FieldMap *fieldMap);
void func_021F3828(struct FieldMap *fieldMap);
struct GameEvent *func_021F3834(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame);
struct GameEvent *func_021F3888(struct GameSystem *gameSystem, u32 oneShotIndex);
int func_021F38D4(struct GameEvent *event, int *seq, void *work);

/* Model positions; the tables are read in full, the gimmick uses a prefix of them. */
typedef struct Gimmick42PosTable {
    VecFx32 pos[GIMMICK42_STATE_MODEL_COUNT];
} Gimmick42PosTable;

extern G3dUtilSetup d_021F3A58;
extern Gimmick42PosTable d_021F3AD4;
extern Gimmick42PosTable d_021F3A68;

/* Load the models, place them, and show the one-shot models at their last frame when they were played. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    Gimmick42Save *save;
    FldExpObjAnime *anime;
    u32 i;
    u8 modelIndex;
    Gimmick42PosTable statePos;
    Gimmick42PosTable oneShotPos;

    expObj = func_02188D2C(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 4);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), 4);
    func_021BE760(expObj, &d_021F3A58, 0);
    statePos = d_021F3AD4;
    for (i = 0; i < GIMMICK42_STATE_MODEL_COUNT; i = (u8)(i + 1)) {
        func_021BE480(expObj, 0, (u8)i)->trans = statePos.pos[i];
        func_021BE4A4(expObj, 0, (u8)i, 1);
    }
    oneShotPos = d_021F3A68;
    for (i = 0; i < GIMMICK42_ONE_SHOT_COUNT; i = (u8)(i + 1)) {
        func_021BE480(expObj, 0, (u8)(i + GIMMICK42_ONE_SHOT_FIRST_MODEL))->trans = oneShotPos.pos[i];
        func_021BE4A4(expObj, 0, (u8)(i + GIMMICK42_ONE_SHOT_FIRST_MODEL), 1);
    }
    for (i = 0; i < GIMMICK42_ONE_SHOT_COUNT; i = (u8)(i + 1)) {
        if (save->oneShotPlayed[i]) {
            modelIndex = i + GIMMICK42_ONE_SHOT_FIRST_MODEL;
            func_021BE700(expObj, 0, modelIndex, 0, 1);
            anime = func_021BE674(expObj, 0, modelIndex, 0);
            func_021BE6B0(anime, 0);
            func_021BE6B8(anime, 0);
            func_021BE6CC(expObj, 0, modelIndex, 0, func_021BE748(anime));
        }
    }
}

void func_021F380C(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = func_02188D2C(fieldMap);

    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F3828(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Create the event that sets the state of one of the first nine models; null for an unknown model. */
struct GameEvent *func_021F3834(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    Gimmick42Save *save;
    struct GameEvent *event;

    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 4);
    if (stateModel >= GIMMICK42_STATE_MODEL_COUNT)
        return 0;
    event = func_020122C0(gameSystem, 0, func_021F38D4, 0);
    if (event != 0) {
        work->stateModel = stateModel;
        work->showLastFrame = showLastFrame;
    }
    return event;
}

/* Create the event that plays the animation of one one-shot model. */
struct GameEvent *func_021F3888(struct GameSystem *gameSystem, u32 oneShotIndex)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    Gimmick42Save *save;
    struct GameEvent *event;

    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 4);
    if (oneShotIndex > GIMMICK42_ONE_SHOT_COUNT)
        return 0;
    event = func_020122C0(gameSystem, 0, func_021F3980, 0);
    work->oneShotIndex = oneShotIndex;
    return event;
}

/* Event: show the model in its first or last animation frame. */
int func_021F38D4(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    FldExpObjAnime *anime;
    int frame;
    u8 modelIndex;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 4);
    switch (*seq) {
    case 0:
        modelIndex = work->stateModel;
        frame = 0;
        func_021BE700(expObj, 0, modelIndex, 0, 1);
        anime = func_021BE674(expObj, 0, modelIndex, 0);
        if (work->showLastFrame != 0) {
            func_021BE6B0(anime, frame);
            frame = func_021BE748(anime);
        } else {
            func_021BE6B0(anime, 1);
        }
        func_021BE6CC(expObj, 0, modelIndex, 0, frame);
        func_021BE6B8(anime, 0);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
