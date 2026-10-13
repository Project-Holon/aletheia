/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3838, func_021F38D4, func_021F3A04, func_021F3A28, func_021F3A88, func_021F3AD0, func_021F3B18, func_021F3B5C, func_021F3BC8, func_021F3BE8, func_021F3BFC, func_021F3C8C, func_021F3D40, func_021F3DE8, func_021F3EFC, func_021F3FA8, func_021F4020, func_021F4064, func_021F4078, func_021F40D8
 * address:  0x021F36C0
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F40D8  0x021F40D8  thumb  ov046
 *   d_021F4120     0x021F4120  data  a4
 *   d_021F4108     0x021F4108  data  a2
 *   d_021F4194     0x021F4194  data  a4
 *   d_021F4170     0x021F4170  data  a4
 *   d_021F4204     0x021F4204  data  a4
 *   d_021F41B8     0x021F41B8  data  a4
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   d_021F41C4  0x021F41C4  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_021A3044  0x021A3044  thumb  ov021
 *   d_021F4130  0x021F4130  data  a4
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3DC  0x021BB3DC  thumb  ov021
 *   d_021F4430  0x021F4430  data  ov046  a4
 */
#include "unit_021F36C0_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldSave;
struct FldExpObj;
struct FldExpAnime;
struct FldExpUnitDesc;
struct FieldPlayer;
struct FldMmdlSys;
struct Mmdl;
struct NogridMapper;
struct GameEvent;

typedef int (*GameEventFunc)(struct GameEvent *event, int *state);

extern struct FldExpObj *func_02188D2C(struct FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldSave *func_02012EC4(struct GameData *gameData);
extern Gimmick46Save *func_0200B3A4(struct FieldSave *fieldSave, u32 blockId);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern Gimmick46Work *func_02189764(struct FieldMap *fieldMap, int workId, int heapId, int size);
extern void func_021BE760(struct FldExpObj *expObj, struct FldExpUnitDesc *desc, int unitIndex);
extern void func_021BE700(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int enabled);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern void func_021A3038(struct FieldPlayer *player, Vec3Fx *outPos);
extern FldExpModel *func_021BE480(struct FldExpObj *expObj, unsigned int unitIndex, int modelIndex);
extern void func_021BE4A4(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, int cullDraw);
extern struct FldExpAnime *func_021BE674(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex);
extern void func_021BE6B8(struct FldExpAnime *anime, int loop);
extern void func_021BE6B0(struct FldExpAnime *anime, int paused);
extern void func_0207AF1C(int *matrix, int sinValue, int cosValue);
extern void func_021BE6CC(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int frame);
extern int func_021BE748(struct FldExpAnime *anime);
extern Gimmick46Work *func_021897BC(struct FieldMap *fieldMap, int workId);
extern void func_021897A0(struct FieldMap *fieldMap, int workId);
extern void func_021BE418(struct FldExpObj *expObj, u16 unitIndex);
extern void func_021BE580(struct FldExpObj *expObj);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc proc, u32 size);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern int func_021BE6BC(struct FldExpAnime *anime);
extern void func_020061E4(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void func_021A3044(struct FieldPlayer *player, Vec3Fx *pos);
extern void func_021BE4B4(struct FldExpObj *expObj, int unitIndex, int modelIndex, u32 hidden);
extern struct FldMmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern int func_0216DD1C(struct FldMmdlSys *mmdlSys, struct Mmdl **outMmdl, u32 *iterator);
extern u16 func_0216D588(struct Mmdl *mmdl);
extern void func_0216DAC8(struct Mmdl *mmdl, u32 vanish);
extern struct NogridMapper *func_02188C5C(struct FieldMap *fieldMap);
extern void func_021BB3DC(struct NogridMapper *mapper, int lineIndex, int enabled);

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F3838(struct FldExpObj *expObj, int modelIndex, Vec3Fx *pos, u16 *angle, int animCount, int cullDraw);
void func_021F38D4(Gimmick46Save *save, struct FldExpObj *expObj, int unitIndex);
void func_021F3A04(struct FieldMap *fieldMap);
void func_021F3A28(struct FieldMap *fieldMap);
void func_021F3A88(struct GameSystem *gameSystem, int unitIndex, int side);
void func_021F3AD0(struct GameSystem *gameSystem, int unitIndex, int side);
void func_021F3B18(struct GameSystem *gameSystem, int unitIndex);
struct GameEvent *func_021F3B5C(struct GameSystem *gameSystem, int direction);
int func_021F3BC8(Gimmick46Unit *unit);
int func_021F3BE8(Gimmick46Unit *unit, int newPose);
int func_021F3BFC(struct GameEvent *event, int *state);
int func_021F3C8C(struct GameEvent *event, int *state);
int func_021F3D40(struct GameEvent *event, int *state);
int func_021F3DE8(struct GameEvent *event, int *state);
int func_021F3EFC(struct GameEvent *event, int *state);
void func_021F3FA8(struct FldExpObj *expObj, struct FieldMap *fieldMap, u32 hidden);
struct Mmdl *func_021F4020(struct FieldMap *fieldMap, int objId);
void func_021F4064(struct FieldMap *fieldMap, int objId, u32 vanish);
void func_021F4078(struct FieldMap *fieldMap, int unitIndex, int pose);
int func_021F40D8(Vec3Fx *pos);

extern struct FldExpUnitDesc d_021F4120;
extern u16 d_021F4108[];         /* initial angle per unit */
extern Vec3Fx d_021F4194[];      /* body position per unit */
extern Vec3Fx d_021F4170[];      /* lever position per unit (both levers) */
extern Vec3Fx d_021F4204[];      /* button position, two per unit */
extern Vec3Fx d_021F41B8;        /* position of the extra model */
extern s16 d_020A1B38[];         /* sine and cosine pairs */
extern int d_021F41C4[][4];      /* body animation for (old pose, new pose) plus 5 */
extern int d_021F4130[];         /* height offsets of the hop, in tiles */
extern int d_021F4430[][4][6];   /* walk lines (line, enabled) per (unit, pose) */


void func_021F36C0(struct FieldMap *fieldMap)
{
    Vec3Fx extraPos;
    Vec3Fx playerPos;
    u16 angle;
    int unitIdx;
    struct FldExpObj *expObj;
    Gimmick46Save *save;
    Gimmick46Work *work;
    int firstModel;
    int inside;

    expObj = func_02188D2C(fieldMap);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = func_02189764(fieldMap, 1, func_02188C84(fieldMap), sizeof(Gimmick46Work));
    func_021BE760(expObj, &d_021F4120, 0);
    for (unitIdx = 0; unitIdx < GIMMICK46_UNIT_COUNT; unitIdx++) {
        /* Cleared and then set: the first store is in the original code. */
        angle = 0;
        angle = d_021F4108[unitIdx];
        firstModel = unitIdx * GIMMICK46_MODELS_PER_UNIT;
        func_021F3838(expObj, firstModel, &d_021F4194[unitIdx], &angle, 8, 0);
        func_021F3838(expObj, firstModel + 1, &d_021F4170[unitIdx], &angle, 2, 0);
        func_021F3838(expObj, firstModel + 2, &d_021F4170[unitIdx], &angle, 2, 0);
        func_021F3838(expObj, firstModel + 3, &d_021F4204[unitIdx * 2], 0, 1, 1);
        func_021F3838(expObj, firstModel + 4, &d_021F4204[unitIdx * 2 + 1], 0, 1, 1);
        func_021F38D4(save, expObj, unitIdx);
    }
    /* The position is copied to a local first; passing the table row
     * directly changes the stack frame. */
    extraPos = d_021F41B8;
    func_021F3838(expObj, GIMMICK46_MODEL_EXTRA, &extraPos, 0, 0, 0);
    func_021BE700(expObj, 0, GIMMICK46_MODEL_EXTRA, 0, 1);
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    inside = func_021F40D8(&playerPos) != 0 ? 1 : 0;
    func_021F3FA8(expObj, fieldMap, inside);
    work->playerInside = inside;
    for (unitIdx = 0; unitIdx < GIMMICK46_UNIT_COUNT; unitIdx++)
        func_021F4078(fieldMap, unitIdx, save->units[unitIdx].pose);
}



void func_021F3838(struct FldExpObj *expObj, int modelIndex, Vec3Fx *pos, u16 *angle, int animCount, int cullDraw)
{
    FldExpModel *model;
    struct FldExpAnime *anime;
    int animIdx;
    int tableIdx;

    model = func_021BE480(expObj, (int)0, (u16)modelIndex);
    model->pos = *pos;
    if (angle) {
        tableIdx = (*angle >> 4) * 2;
        func_0207AF1C(model->rotation, d_020A1B38[tableIdx], d_020A1B38[tableIdx + 1]);
    }
    func_021BE4A4(expObj, 0, modelIndex, cullDraw);
    for (animIdx = 0; animIdx < animCount; animIdx++) {
        anime = func_021BE674(expObj, 0, modelIndex, animIdx);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, modelIndex, animIdx, 0);
    }
}









void func_021F38D4(Gimmick46Save *save, struct FldExpObj *expObj, int unitIdx)
{
    Gimmick46Unit *unit;
    int bodyModel;
    int bodyAnim;
    struct FldExpAnime *bodyAnime;
    int leverAnim0;
    int leverModel0;
    struct FldExpAnime *leverAnime0;
    int leverAnim1;
    int leverModel1;
    struct FldExpAnime *leverAnime1;

    unit = &save->units[unitIdx];
    switch (unit->pose) {
    case 0:
        bodyAnim = 1;
        break;
    case 1:
        bodyAnim = 5;
        break;
    case 3:
        bodyAnim = 0;
        break;
    case 2:
        bodyAnim = 2;
        break;
    default:
        bodyAnim = 1;
        break;
    }
    bodyModel = unitIdx * GIMMICK46_MODELS_PER_UNIT;
    bodyAnime = func_021BE674(expObj, 0, bodyModel, bodyAnim);
    func_021BE6B0(bodyAnime, 0);
    func_021BE700(expObj, 0, bodyModel, bodyAnim, 1);
    func_021BE6CC(expObj, 0, bodyModel, bodyAnim, func_021BE748(bodyAnime));
    leverAnim0 = 1;
    leverModel0 = bodyModel + 1;
    if (unit->leverOn[0] == 0)
        leverAnim0 = 0;
    leverAnime0 = func_021BE674(expObj, 0, leverModel0, leverAnim0);
    func_021BE6B0(leverAnime0, 0);
    func_021BE700(expObj, 0, leverModel0, leverAnim0, 1);
    func_021BE6CC(expObj, 0, leverModel0, leverAnim0, func_021BE748(leverAnime0));
    leverAnim1 = 1;
    leverModel1 = bodyModel + 2;
    if (unit->leverOn[1] == 0)
        leverAnim1 = 0;
    leverAnime1 = func_021BE674(expObj, 0, leverModel1, leverAnim1);
    func_021BE6B0(leverAnime1, 0);
    func_021BE700(expObj, 0, leverModel1, leverAnim1, 1);
    func_021BE6CC(expObj, 0, leverModel1, leverAnim1, func_021BE748(leverAnime1));
}








void func_021F3A04(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}









void func_021F3A28(struct FieldMap *fieldMap)
{
    Vec3Fx playerPos;
    struct FldExpObj *expObj = func_02188D2C(fieldMap);
    Gimmick46Work *work = func_021897BC(fieldMap, 1);
    int inside = 1;

    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    func_021BE580(expObj);
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    if (func_021F40D8(&playerPos) == 0)
        inside = 0;
    if (work->playerInside != inside) {
        func_021F3FA8(expObj, fieldMap, inside);
        work->playerInside = inside;
    }
}









void func_021F3A88(struct GameSystem *gameSystem, int unitIndex, int side)
{
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Save *save;
    Gimmick46Work *work;

    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = func_021897BC(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->side = side;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, func_021F3BFC, 0);
}









void func_021F3AD0(struct GameSystem *gameSystem, int unitIndex, int side)
{
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Save *save;
    Gimmick46Work *work;

    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = func_021897BC(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->side = side;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, func_021F3C8C, 0);
}









void func_021F3B18(struct GameSystem *gameSystem, int unitIndex)
{
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Save *save;
    Gimmick46Work *work;

    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = func_021897BC(fieldMap, 1);
    work->unitIndex = unitIndex;
    work->unit = &save->units[unitIndex];
    func_020122C0(gameSystem, 0, func_021F3D40, 0);
}









/*
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the hop data pointer is a separate local
 * that is formed after the func_020122C0 call.
 */
struct GameEvent *func_021F3B5C(struct GameSystem *gameSystem, int direction)
{
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Work *work;
    Gimmick46HopEvent *hop;
    struct GameEvent *hopEvent;
    Vec3Fx playerPos;

    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    work = func_021897BC(fieldMap, 1);
    hopEvent = func_020122C0(gameSystem, 0, func_021F3EFC, 0);
    hop = &work->event.hop;
    hop->step = 0;
    hop->speedX = GIMMICK46_HOP_SPEED;
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    hop->baseY = playerPos.y;
    if (direction == 2)
        hop->speedX = hop->speedX * 0xffffffff;
    return hopEvent;
}








int func_021F3BC8(Gimmick46Unit *unit)
{
    if (unit->leverOn[0] == 0) {
        if (unit->leverOn[1] == 0)
            return 0;
        return 3;
    }
    if (unit->leverOn[1] == 0)
        return 2;
    return 1;
}








/*
 * Unlabelled leaf (no lr push) between func_021F3BC8 and func_021F3BFC.
 */
int func_021F3BE8(Gimmick46Unit *unit, int newPose)
{
    return d_021F41C4[unit->pose][newPose] - 5;
}








/*
 * The 3/4 selector must be a ternary inside the sum with the ternary
 * first: an if-assigned local or `a0 * 5 + (...)` gets other registers.
 */
int func_021F3BFC(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = func_020124E4(event);
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Work *work;

    func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        work->event.anim.modelIndex = (work->side == 0 ? GIMMICK46_MODEL_BUTTON_BASE : GIMMICK46_MODEL_BUTTON_BASE + 1) + work->unitIndex * GIMMICK46_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = 0;
        work->event.anim.stopCount = 1;
        work->event.anim.startSe = GIMMICK46_SE_BUTTON;
        work->event.anim.endSe = GIMMICK46_SE_NONE;
        func_02012374(event, func_020122C0(gameSystem, 0, func_021F3DE8, 0));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






int func_021F3C8C(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = func_020124E4(event);
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Work *work;
    int newLeverState;

    func_02188D2C(fieldMap);
    newLeverState = 1;
    work = func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        if (work->unit->leverOn[work->side] != 0)
            newLeverState = 0;
        work->event.anim.modelIndex = (work->side == 0 ? GIMMICK46_MODEL_LEVER_BASE : GIMMICK46_MODEL_LEVER_BASE + 1) + work->unitIndex * GIMMICK46_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = newLeverState;
        work->event.anim.stopCount = 2;
        work->event.anim.startSe = GIMMICK46_SE_LEVER_START;
        work->event.anim.endSe = GIMMICK46_SE_LEVER_END;
        func_02012374(event, func_020122C0(gameSystem, 0, func_021F3DE8, 0));
        work->unit->leverOn[work->side] = newLeverState;
        (*state)++;
        break;
    case 1:
        return newLeverState;
    }
    return 0;
}





int func_021F3D40(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem = func_020124E4(event);
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    Gimmick46Work *work;
    int newPose;
    int bodyAnim;

    func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        newPose = func_021F3BC8(work->unit);
        bodyAnim = func_021F3BE8(work->unit, newPose);
        work->event.anim.modelIndex = work->unitIndex * GIMMICK46_MODELS_PER_UNIT;
        work->event.anim.startCount = 1;
        work->event.anim.animId[0] = bodyAnim;
        work->event.anim.stopCount = 8;
        work->event.anim.startSe = GIMMICK46_SE_ROTATE_START;
        work->event.anim.endSe = GIMMICK46_SE_ROTATE_END;
        func_02012374(event, func_020122C0(gameSystem, 0, func_021F3DE8, 0));
        work->unit->pose = newPose;
        (*state)++;
        break;
    case 1:
        func_021F4078(fieldMap, work->unitIndex, work->unit->pose);
        return 1;
    }
    return 0;
}




int func_021F3DE8(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick46AnimEvent *anim;
    u8 modelIdx;
    int i;
    u8 animIdx;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    anim = &func_021897BC(fieldMap, 1)->event.anim;
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        modelIdx = anim->modelIndex;
        for (i = 0; i < anim->stopCount; i++) {
            func_021BE6B0(func_021BE674(expObj, 0, modelIdx, i), 1);
            func_021BE700(expObj, 0, modelIdx, (u8)i, 0);
        }
        for (i = 0; i < anim->startCount; i++) {
            animIdx = anim->animId[i];
            func_021BE6B0(func_021BE674(expObj, 0, modelIdx, animIdx), 0);
            func_021BE700(expObj, 0, modelIdx, (u8)animIdx, 1);
            func_021BE6CC(expObj, 0, modelIdx, animIdx, 0);
            func_020061E4(anim->startSe);
        }
        (*state)++;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674(expObj, 0, anim->modelIndex, anim->animId[0]))) {
            GFL_USE_StopAllSe();
            if (anim->endSe != GIMMICK46_SE_NONE)
                func_020061E4(anim->endSe);
            return 1;
        }
        break;
    }
    return 0;
}




int func_021F3EFC(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    Gimmick46HopEvent *hop;
    int done = 1;
    struct FieldPlayer *player;
    Vec3Fx pos;

    fieldMap = func_0201210C(func_020124E4(event));
    func_02188D2C(fieldMap);
    hop = &func_021897BC(fieldMap, 1)->event.hop;
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK46_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        func_020061E4(GIMMICK46_SE_HOP_START);
        (*state)++;
        break;
    case 1:
        player = func_02188CB4(fieldMap);
        func_021A3038(player, &pos);
        pos.x = pos.x + hop->speedX;
        pos.y = hop->baseY + (d_021F4130[hop->step] << 12);
        func_021A3044(player, &pos);
        hop->step = hop->step + 1;
        if (hop->step >= GIMMICK46_HOP_STEPS) {
            func_020061E4(GIMMICK46_SE_HOP_END);
            return done;
        }
        break;
    }
    return 0;
}




void func_021F3FA8(struct FldExpObj *expObj, struct FieldMap *fieldMap, u32 hidden)
{
    func_021BE4B4(expObj, 0, 15, hidden);
    func_021BE4B4(expObj, 0, 10, hidden);
    func_021BE4B4(expObj, 0, 11, hidden);
    func_021BE4B4(expObj, 0, 12, hidden);
    func_021BE4B4(expObj, 0, 13, hidden);
    func_021BE4B4(expObj, 0, 14, hidden);
    func_021F4064(fieldMap, 4, hidden);
    func_021F4064(fieldMap, 5, hidden);
    func_021F4064(fieldMap, 9, hidden);
    func_021F4064(fieldMap, 6, hidden);
}




struct Mmdl *func_021F4020(struct FieldMap *fieldMap, int objId)
{
    u32 iterator = 0;
    struct Mmdl *mmdl;
    struct FldMmdlSys *mmdlSys = func_02188C7C(fieldMap);

    while (func_0216DD1C(mmdlSys, &mmdl, &iterator) == 1) {
        if (objId == func_0216D588(mmdl))
            return mmdl;
    }
    return 0;
}



void func_021F4064(struct FieldMap *fieldMap, int objId, u32 vanish)
{
    struct Mmdl *mmdl;

    mmdl = func_021F4020(fieldMap, objId);
    if (mmdl)
        func_0216DAC8(mmdl, vanish);
}




/*
 * The table row is indexed inside the loop; the compiler hoists the
 * invariant row address (the register of pose is reused for it). A
 * `t = d[unit][pose]` local before the loop colours pose and the counter
 * apart. func_021BB3DC is ov021's thunk (reads r0-r2); ov214's label at the
 * same address is a different two-argument function.
 */
void func_021F4078(struct FieldMap *fieldMap, int unitIndex, int pose)
{
    int lines[6];
    int enabled[6];
    struct NogridMapper *mapper = func_02188C5C(fieldMap);
    int i;

    for (i = 0; i < 6; i++) {
        lines[i] = d_021F4430[unitIndex][pose][i];
        enabled[i] = 0;
    }
    if (pose != 1) {
        enabled[0] = 1;
        enabled[1] = 1;
    }
    for (i = 0; i < 6; i++)
        func_021BB3DC(mapper, lines[i], enabled[i]);
}

int func_021F40D8(Vec3Fx *pos)
{
    if (pos->y > 0x40000)
        return 0;
    if (pos->x >= 0x100000 && pos->z >= 0x1e0000)
        return 1;
    return 0;
}
