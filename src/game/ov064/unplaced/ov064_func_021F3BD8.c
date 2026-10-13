/*
 * function: func_021F3BD8
 * address:  0x021F3BD8
 * packet:   pkt_ov064_021F3BD8
 * region:   ov064
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
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */

#include "../unit_021F36C0_types.h"

extern void *func_020124E4(void *event);
extern void *func_0201210C(void *gameSystem);
extern void *func_02188D2C(void *fieldMap);
extern void *func_021BE674(void *expObj, int unit, unsigned int model, int animeIdx);
extern int func_021BE6BC(void *anime);

/* Event: ends once the first anime of the arc model has stopped. */
int func_021F3BD8(void *event, int *unusedSeq)
{
    void *expObj;

    expObj = func_02188D2C(func_0201210C(func_020124E4(event)));
    if (func_021BE6BC(func_021BE674(expObj, 0, GIMMICK64_ARC_MODEL, 0)) != 0) {
        return 1;
    }
    return 0;
}
