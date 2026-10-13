/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC, func_021F3708, func_021F3714, func_021F3744, func_021F3758, func_021F3788, func_021F37B8, func_021F3808, func_021F383C, func_021F3890
 * address:  0x021F36C0
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3894 0x021F3894 thumb ov050
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B8 0x021BE6B8 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_021BE4B4 0x021BE4B4 thumb ov021
 *   func_021BE760  0x021BE760  thumb
 *   func_021BE480  0x021BE480  thumb
 *   d_021F38A4     0x021F38A4  data  a4
 *   d_021F38B4     0x021F38B4  data  a4
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F36EC(struct FieldMap *fieldMap);
void func_021F3708(struct FieldMap *fieldMap);
void func_021F3714(struct FieldMap *fieldMap);
void func_021F3744(struct FieldMap *fieldMap);
int func_021F3758(struct FieldMap *fieldMap);
void func_021F3788(struct FieldMap *fieldMap);
void func_021F37B8(struct FieldMap *fieldMap);
int func_021F3808(struct FieldMap *fieldMap);
void func_021F383C(Gimmick50Work *work, struct FieldMap *fieldMap);
void func_021F3890(Gimmick50Work *work, struct FieldMap *fieldMap);
extern void func_021F3894(Gimmick50Work *work, struct FieldMap *fieldMap);

extern const G3dUtilSetup d_021F38A4;
extern const VecFx32 d_021F38B4[GIMMICK50_MODEL_COUNT];

/* Gimmick setup: allocate the common work, then place the models. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    u16 heapId;
    Gimmick50Work *work;

    heapId = func_02188C84(fieldMap);
    work = func_02189764(fieldMap, 1, heapId, 2);
    work->heapId = heapId;
    func_021F383C(work, fieldMap);
    func_021F3890(work, fieldMap);
}

/* Gimmick exit: release the common work. */
void func_021F36EC(struct FieldMap *fieldMap)
{
    func_021F3894(func_021897BC(fieldMap, 1), fieldMap);
    func_021897A0(fieldMap, 1);
}

/* Gimmick update: advance the animations. */
void func_021F3708(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Script command: start the animation of model 0 and let it stop at the last frame. */
void func_021F3714(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = func_02188D2C(fieldMap);

    func_021BE700(expObj, 0, 0, 0, 1);
    func_021BE6B8(func_021BE674(expObj, 0, 0, 0), 0);
}

/* Switch the animation of model 0 off. */
void func_021F3744(struct FieldMap *fieldMap)
{
    func_021BE700(func_02188D2C(fieldMap), 0, 0, 0, 0);
}

/* Script command: 1 when the animation of model 0 has stopped. */
int func_021F3758(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    for (i = 0; i < 1; i++) {
        if (func_021BE6BC(func_021BE674(expObj, 0, 0, i)) == 0)
            return 0;
    }
    return 1;
}

/* Hide model 1 and switch both of its animations off. */
void func_021F3788(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021BE4B4(expObj, 0, 1, 1);
    for (i = 0; i < 2; i++)
        func_021BE700(expObj, 0, 1, i, 0);
}

/* Script command: show model 1 and play both of its animations once. */
void func_021F37B8(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int i;
    int j;

    expObj = func_02188D2C(fieldMap);
    func_021BE4B4(expObj, 0, 1, 0);
    for (i = 0; i < 2; i++)
        func_021BE700(expObj, 0, 1, i, 1);
    for (j = 0; j < 2; j++)
        func_021BE6B8(func_021BE674(expObj, 0, 1, j), 0);
}

/*
 * Script command: 1 when both animations of model 1 have stopped.
 * note: two-byte alignment padding at 0x021F383A; index declared before pointer restores r4/r5.
 */
int func_021F3808(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    for (i = 0; i < 2; i++) {
        if (func_021BE6BC(func_021BE674(expObj, 0, 1, i)) == 0)
            return 0;
    }
    return 1;
}

/* Load the unit, place the two models, then switch off model 0 and hide model 1. */
void func_021F383C(Gimmick50Work *work, struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int i;
    G3dObjectStatus *status;
    const VecFx32 *pos;

    expObj = func_02188D2C(fieldMap);
    func_021BE760(expObj, &d_021F38A4, 0);
    for (i = 0; i < GIMMICK50_MODEL_COUNT; i++) {
        status = func_021BE480(expObj, 0, i);
        pos = &d_021F38B4[i];
        status->trans.x = pos->x;
        status->trans.y = pos->y;
        status->trans.z = pos->z;
    }
    func_021F3744(fieldMap);
    func_021F3788(fieldMap);
}

/*
 * Empty function.
 */
void func_021F3890(Gimmick50Work *work, struct FieldMap *fieldMap)
{
}
