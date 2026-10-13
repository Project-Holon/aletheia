/*
 * function: func_021F381C
 * address:  0x021F381C
 * packet:   pkt_ov040_021F381C
 * region:   ov040
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
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
#include "../unit_021F36C0_types.h"

/* Gimmick event: play the animation of the model, then record that it was played. */
int func_021F381C(struct GameEvent *event, int *seq, void *work)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick40Work *gimmickWork;
    Gimmick40Save *save;
    FldExpObjAnime *anime;
    u8 modelIndex;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    gimmickWork = func_021897BC(fieldMap, 1);
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), 3);
    switch (*seq) {
    case 0:
        modelIndex = gimmickWork->modelIndex;
        func_021BE700(expObj, 0, modelIndex, 0, 1);
        func_021BE6B0(func_021BE674(expObj, 0, modelIndex, 0), 0);
        func_021BE6CC(expObj, 0, modelIndex, 0, 0);
        (*seq)++;
        break;
    case 1:
        anime = func_021BE674(expObj, 0, (u8)gimmickWork->modelIndex, 0);
        if (func_021BE6BC(anime) && func_021BE6BC(anime)) {
            save->animeDone[gimmickWork->modelIndex] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
