/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37F8, func_021F381C, func_021F384C, func_021F3888, func_021F38C4, func_021F3908, func_021F3938, func_021F39A8, func_021F39B8
 * address:  0x021F36C0
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B50     0x021F3B50  data  ov045
 *   d_021F3B80     0x021F3B80  data  ov045  a4
 *   d_021F3BA4     0x021F3BA4  data  ov045  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_021F3A68 0x021F3A68 thumb ov045
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CF0  0x02188CF0  thumb  ov021
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_021A6DC4  0x021A6DC4  thumb  ov021
 *   d_021F3B60  0x021F3B60  data  ov045
 *   d_021F3B62  0x021F3B62  data
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */
#include "unit_021F36C0_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldSave;
struct FldExpObj;
struct FldExpAnime;
struct FldExpUnitDesc;
struct GameEvent;

typedef int (*GameEventFunc)(struct GameEvent *event, int *state);

extern struct FldExpObj *func_02188D2C(struct FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldSave *func_02012EC4(struct GameData *gameData);
extern Gimmick45Save *func_0200B3A4(struct FieldSave *fieldSave, u32 blockId);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02189764(struct FieldMap *fieldMap, int workId, int heapId, int size);
extern void func_021BE760(struct FldExpObj *expObj, struct FldExpUnitDesc *desc, int unitIndex);
extern Vec3Fx *func_021BE480(struct FldExpObj *expObj, int unitIndex, u16 modelIndex);
extern void func_021BE4A4(struct FldExpObj *expObj, int unitIndex, int modelIndex, int cullDraw);
extern struct FldExpAnime *func_021BE674(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex);
extern void func_021BE6B8(struct FldExpAnime *anime, int loop);
extern void func_021BE6B0(struct FldExpAnime *anime, int paused);
extern Gimmick45Work *func_021897BC(struct FieldMap *fieldMap, int workId);
extern void func_021897A0(struct FieldMap *fieldMap, int workId);
extern void func_021BE418(struct FldExpObj *expObj, u16 unitIndex);
extern void func_021BE580(struct FldExpObj *expObj);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc proc, u32 size);
extern int func_021F3A68(struct GameEvent *event, int *state);
extern int func_02188CF0(struct FieldMap *fieldMap);
extern void *func_02188CA4(struct FieldMap *fieldMap);
extern void func_021A6DC4(void *ctrlWork, struct FieldMap *fieldMap);
extern void func_021BE700(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int enabled);
extern void func_021BE6CC(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int frame);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern int func_021BE6BC(struct FldExpAnime *anime);

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F37F8(struct FieldMap *fieldMap);
void func_021F381C(struct FieldMap *fieldMap);
struct GameEvent *func_021F384C(struct GameSystem *gameSystem, int switchIndex);
struct GameEvent *func_021F3888(struct GameSystem *gameSystem, int switchIndex);
void func_021F38C4(struct GameSystem *gameSystem, int requirementIndex);
int func_021F3908(Gimmick45Save *save, int requirementIndex);
void func_021F3938(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel);
int func_021F39A8(Gimmick45Save *save, int switchIndex);
int func_021F39B8(struct GameEvent *event, int *state);

extern struct FldExpUnitDesc d_021F3B50;
extern Vec3Fx d_021F3B80[];
extern Vec3Fx d_021F3BA4[];
/* Requirement table: entry n is (switch index, required state). The ROM
 * data layout splits the two columns into two objects, so the code reaches
 * them through two symbols. */
extern u16 d_021F3B60[];
extern u16 d_021F3B62[];


void func_021F36C0(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;
    Gimmick45Save *save;
    struct FldExpAnime *anime;
    Vec3Fx *modelPos;
    int switchIdx;
    int secondaryIdx;
    int animIdx;

    expObj = func_02188D2C(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), sizeof(Gimmick45Work));
    func_021BE760(expObj, &d_021F3B50, 0);
    for (switchIdx = 0; switchIdx < GIMMICK45_SWITCH_COUNT; switchIdx++) {
        modelPos = func_021BE480(expObj, 0, switchIdx);
        *modelPos = d_021F3B80[switchIdx];
        func_021BE4A4(expObj, 0, (u16)switchIdx, 1);
        for (animIdx = 0; animIdx < 2; animIdx++) {
            anime = func_021BE674(expObj, 0, switchIdx, animIdx);
            func_021BE6B8(anime, 0);
            func_021BE6B0(anime, 1);
        }
        secondaryIdx = switchIdx + GIMMICK45_SECONDARY_MODEL_OFFSET;
        modelPos = func_021BE480(expObj, 0, secondaryIdx);
        *modelPos = d_021F3BA4[switchIdx];
        func_021BE4A4(expObj, 0, (u16)secondaryIdx, 1);
        for (animIdx = 0; animIdx < 2; animIdx++) {
            anime = func_021BE674(expObj, 0, secondaryIdx, animIdx);
            func_021BE6B8(anime, 0);
            func_021BE6B0(anime, 1);
        }
        func_021F3938(expObj, save->switchOn[switchIdx], switchIdx, 1);
        func_021F3938(expObj, save->switchOn[switchIdx], switchIdx, 0);
    }
}

void func_021F37F8(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj = func_02188D2C(fieldMap);

    func_021897BC(fieldMap, 1);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F381C(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    func_021BE580(expObj);
}

struct GameEvent *func_021F384C(struct GameSystem *gameSystem, int switchIndex)
{
    struct FieldMap *fieldMap;
    Gimmick45Work *work;

    fieldMap = func_0201210C(gameSystem);
    func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    work = func_021897BC(fieldMap, 1);
    if (switchIndex >= GIMMICK45_SWITCH_COUNT)
        return 0;
    work->switchIndex = switchIndex;
    return func_020122C0(gameSystem, 0, func_021F39B8, 0);
}

struct GameEvent *func_021F3888(struct GameSystem *gameSystem, int switchIndex)
{
    struct FieldMap *fieldMap;
    Gimmick45Work *work;

    fieldMap = func_0201210C(gameSystem);
    func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    work = func_021897BC(fieldMap, 1);
    if (switchIndex >= GIMMICK45_SWITCH_COUNT)
        return 0;
    work->switchIndex = switchIndex;
    return func_020122C0(gameSystem, 0, func_021F3A68, 0);
}


void func_021F38C4(struct GameSystem *gameSystem, int requirementIndex)
{
    struct FieldMap *fieldMap;
    int ctrlType;
    Gimmick45Save *save;

    fieldMap = func_0201210C(gameSystem);
    ctrlType = func_02188CF0(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    if (requirementIndex < GIMMICK45_REQUIREMENT_COUNT && ctrlType == GIMMICK45_CTRL_TYPE_HYBRID) {
        if (func_021F3908(save, requirementIndex)) {
            func_021A6DC4(func_02188CA4(fieldMap), fieldMap);
        }
    }
}


int func_021F3908(Gimmick45Save *save, int requirementIndex)
{
    u16 switchIsOn = (u16)(save->switchOn[d_021F3B60[requirementIndex * 2]] != 0);

    return switchIsOn == d_021F3B62[requirementIndex * 2];
}


void func_021F3938(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel)
{
    int onAnim, offAnim;

    if (switchOn) {
        onAnim = 1;
        offAnim = 0;
    } else {
        onAnim = 0;
        offAnim = 1;
    }
    if (usePrimaryModel != 1) {
        switchIndex += GIMMICK45_SECONDARY_MODEL_OFFSET;
    }
    func_021BE700(expObj, 0, switchIndex, onAnim, 1);
    func_021BE700(expObj, 0, switchIndex, offAnim, 0);
    func_021BE6CC(expObj, 0, (u16)switchIndex, (u16)onAnim, 0);
    func_021BE6B0(func_021BE674(expObj, 0, switchIndex, onAnim), 1);
}

int func_021F39A8(Gimmick45Save *save, int switchIndex)
{
    return save->switchOn[switchIndex] != 0;
}


int func_021F39B8(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick45Work *work;
    Gimmick45Save *save;
    int newState;
    int switchIdx;
    u8 curState;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    newState = 1;
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        switchIdx = work->switchIndex;
        curState = func_021F39A8(save, switchIdx);
        func_021BE6B0(func_021BE674(expObj, 0, (u8)(switchIdx + GIMMICK45_SECONDARY_MODEL_OFFSET), curState), 0);
        *state = *state + 1;
        break;
    case 1:
        switchIdx = work->switchIndex;
        curState = func_021F39A8(save, switchIdx);
        if (func_021BE6BC(func_021BE674(expObj, 0, (u8)(switchIdx + GIMMICK45_SECONDARY_MODEL_OFFSET), curState))) {
            if (save->switchOn[work->switchIndex]) {
                newState = 0;
            }
            func_021F3938(expObj, newState, work->switchIndex, 0);
            return 1;
        }
        break;
    }
    return 0;
}
