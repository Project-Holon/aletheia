/*
 * function: func_021F39F4
 * address:  0x021F39F4
 * packet:   pkt_ov060_021F39F4
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     closes docs/notes/ov060_func_021F39F4.c.txt: the Thumb callee at
 *           0x021BE6BC is ov021's leaf, now matched (ov021 token); the
 *           function is 52 bytes, the rest of the handed 492 is data.
 *
 * symbols:
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 */

#include "../unit_021F36C0_types.h"

extern u8 *func_021BE674(void *expObj, int unit, int model, int animeIdx);
extern int func_021BE6BC(u8 *anime);
extern void func_021BE4B4(void *expObj, int unit, int model, int hidden);

/* Ends the effect once its first anime has stopped: hides the model and clears the flag. */
void func_021F39F4(Gimmick60Work *work, void *expObj)
{
    if (work->effectActive != 0) {
        if (func_021BE6BC(func_021BE674(expObj, 0, GIMMICK60_EFFECT_MODEL, 0)) != 0) {
            func_021BE4B4(expObj, 0, GIMMICK60_EFFECT_MODEL, 1);
            work->effectActive = 0;
        }
    }
}
