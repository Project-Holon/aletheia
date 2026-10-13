/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3738
 * address:  0x021F36C0
 * region:   ov062
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   d_021F3768     0x021F3768  data  a4
 *   d_021F3790     0x021F3790  data  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 */
#include "unit_021F36C0_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;

extern struct GameSystem *func_02188C80(void *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern s32 *func_0200B3A4(struct GimmickWork *gimmickWork, u32 slot);
extern void *func_02188D2C(void *fieldMap);
extern void func_021BE760(void *expObj, void *unitDesc, int b);
extern VecFx32 *func_021BE480(void *expObj, unsigned unit, int model);
extern void func_021BE4A4(void *expObj, int unit, int model, int visible);
extern void func_021BE700(void *expObj, int unit, int model, int animeIdx, int enabled);
extern void func_021BE4B4(void *expObj, int unit, int model, int hidden);
extern void func_021BE418(void *expObj, unsigned short unit);
void func_021F36C0(void *fieldMap);
void func_021F3738(void *fieldMap);
extern VecFx32 d_021F3768;
extern VecFx32 d_021F3790;

void func_021F36C0(void *fieldMap)
{
    s32 *hideFlag;
    void *expObj;

    hideFlag = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK62_WORK_SLOT);
    expObj = func_02188D2C(fieldMap);
    func_021BE760(expObj, &d_021F3768, 0);
    *func_021BE480(expObj, 0, 0) = d_021F3790;
    func_021BE4A4(expObj, 0, 0, 1);
    func_021BE700(expObj, 0, 0, 0, 1);
    if (*hideFlag != 0)
        func_021BE4B4(expObj, 0, 0, 1);
}

void func_021F3738(void *fieldMap)
{
    func_021BE418(func_02188D2C(fieldMap), 0);
}
