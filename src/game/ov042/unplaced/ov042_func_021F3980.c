/*
 * function: func_021F3980
 * address:  0x021F3980
 * packet:   pkt_ov042_021F3980
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
#include "../unit_021F36C0_types.h"

/* Event: play the animation of a one-shot model once, then record it in the save area. */
int func_021F3980(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick42Work *work;
    Gimmick42Save *save;
    FldExpObjAnime *anime;
    u8 modelIndex;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 4);
    switch (*seq) {
    case 0:
        modelIndex = work->oneShotIndex + GIMMICK42_ONE_SHOT_FIRST_MODEL;
        func_021BE700(expObj, 0, modelIndex, 0, 1);
        anime = func_021BE674(expObj, 0, modelIndex, 0);
        func_021BE6B0(anime, 0);
        func_021BE6CC(expObj, 0, modelIndex, 0, 0);
        func_021BE6B8(anime, 0);
        (*seq)++;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674(expObj, 0, (u8)(work->oneShotIndex + GIMMICK42_ONE_SHOT_FIRST_MODEL), 0))) {
            save->oneShotPlayed[work->oneShotIndex] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
