/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC, func_021F3708, func_021F3714, func_021F3864
 * address:  0x021F36C0
 * region:   ov049
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
 *   func_021F3868 0x021F3868 thumb ov049
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3894     0x021F3894  data  ov049  a4
 *   d_021F38A4     0x021F38A4  data  a4
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F36EC(struct FieldMap *fieldMap);
void func_021F3708(struct FieldMap *fieldMap);
void func_021F3714(Gimmick49Work *work, struct FieldMap *fieldMap);
void func_021F3864(Gimmick49Work *work, struct FieldMap *fieldMap);
extern void func_021F3868(Gimmick49Work *work, struct FieldMap *fieldMap);

extern const G3dUtilSetup d_021F3894;
extern const VecFx32 d_021F38A4[GIMMICK49_MODEL_COUNT];

/* Gimmick setup: allocate the common work, then place the models. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    u16 heapId;
    Gimmick49Work *work;

    heapId = func_02188C84(fieldMap);
    work = func_02189764(fieldMap, 0, heapId, 2);
    work->heapId = heapId;
    func_021F3714(work, fieldMap);
    func_021F3864(work, fieldMap);
}

/* Gimmick exit: release the common work. */
void func_021F36EC(struct FieldMap *fieldMap)
{
    func_021F3868(func_021897BC(fieldMap, 0), fieldMap);
    func_021897A0(fieldMap, 0);
}

/* Gimmick update: advance the animations. */
void func_021F3708(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Load the unit, place the six models and start the animations of the models whose event flags are set. */
void func_021F3714(Gimmick49Work *work, struct FieldMap *fieldMap)
{
    int model2Lit;
    int model3Lit;
    int model4Lit;
    int model5Lit;
    struct EventWork *eventWork;
    FldExpObjCnt *expObj;
    int i;
    G3dObjectStatus *status;

    eventWork = func_0201296C(func_020120F4(func_02188C80(fieldMap)));
    model2Lit = func_020142E8(eventWork, GIMMICK49_FLAG_MODEL2);
    model3Lit = func_020142E8(eventWork, GIMMICK49_FLAG_MODEL3);
    model4Lit = func_020142E8(eventWork, GIMMICK49_FLAG_MODEL4);
    model5Lit = func_020142E8(eventWork, GIMMICK49_FLAG_MODEL5);
    expObj = func_02188D2C(fieldMap);
    func_021BE760(expObj, &d_021F3894, 0);
    for (i = 0; i < GIMMICK49_MODEL_COUNT; i++) {
        status = func_021BE480(expObj, 0, i);
        status->trans.x = d_021F38A4[i].x;
        status->trans.y = d_021F38A4[i].y;
        status->trans.z = d_021F38A4[i].z;
    }
    if (model2Lit && model3Lit && model4Lit && model5Lit) {
        func_021BE700(expObj, 0, 0, 0, 1);
        func_021BE700(expObj, 0, 1, 0, 1);
    }
    if (model2Lit)
        func_021BE700(expObj, 0, 2, 1, 1);
    else
        func_021BE700(expObj, 0, 2, 0, 1);
    if (model3Lit)
        func_021BE700(expObj, 0, 3, 1, 1);
    else
        func_021BE700(expObj, 0, 3, 0, 1);
    if (model4Lit)
        func_021BE700(expObj, 0, 4, 1, 1);
    else
        func_021BE700(expObj, 0, 4, 0, 1);
    if (model5Lit)
        func_021BE700(expObj, 0, 5, 1, 1);
    else
        func_021BE700(expObj, 0, 5, 0, 1);
}

/*
 * Empty function.
 */
void func_021F3864(Gimmick49Work *work, struct FieldMap *fieldMap)
{
}
