/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F377C, func_021F3798, func_021F37A4, func_021F37C8, func_021F37EC
 * address:  0x021F36C0
 * region:   ov040
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   d_021F38D4     0x021F38D4  data  a4
 *   d_021F38EC     0x021F38EC  data  a4
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_021F381C 0x021F381C thumb ov040
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F377C(struct FieldMap *fieldMap);
void func_021F3798(struct FieldMap *fieldMap);
void func_021F37A4(struct FieldMap *fieldMap);
int func_021F37C8(struct FieldMap *fieldMap);
struct GameEvent *func_021F37EC(struct GameSystem *gameSystem, u32 modelIndex);

extern Gimmick40ModelPos d_021F38D4;
extern G3dUtilSetup d_021F38EC;

/* Set up the model and show its animation at the last frame when it was played before. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    Gimmick40Save *save;
    FldExpObjAnime *anime;
    VecFx32 pos;

    expObj = func_02188D2C(fieldMap);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), 4);
    func_021897BC(fieldMap, 1);
    func_021BE310(expObj, &d_021F38EC, 0);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 3);
    pos.x = d_021F38D4.x;
    pos.y = 0;
    pos.z = d_021F38D4.z;
    func_021BE480(expObj, 0, 0)->trans = pos;
    anime = func_021BE674(expObj, 0, 0, 0);
    func_021BE6B0(anime, 1);
    func_021BE6B8(anime, 0);
    if (save->animeDone[0] != 0) {
        func_021BE700(expObj, 0, 0, 0, 1);
        func_021BE6CC(expObj, 0, 0, 0, func_021BE748(anime));
    }
}

void func_021F377C(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F3798(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Script command: set the gimmick flag. */
void func_021F37A4(struct FieldMap *fieldMap)
{
    Gimmick40Save *save;

    func_021897BC(fieldMap, 1);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 3);
    save->flag = 1;
}

/*
 * extent: 34 code bytes followed by two zero alignment bytes.
 */
int func_021F37C8(struct FieldMap *fieldMap)
{
    Gimmick40Save *save;

    func_021897BC(fieldMap, 1);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 3);
    return save->flag;
}

/* Create the event that plays the animation of one model; null for an unknown model. */
struct GameEvent *func_021F37EC(struct GameSystem *gameSystem, u32 modelIndex)
{
    Gimmick40Work *work = func_021897BC(func_0201210C(gameSystem), 1);
    struct GameEvent *event;

    if (modelIndex >= 1)
        return 0;
    event = func_020122C0(gameSystem, 0, func_021F381C, 0);
    work->modelIndex = modelIndex;
    return event;
}
