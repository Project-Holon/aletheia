/*
 * function: WIFIBATTLEMATCH_NET_TakeRegBuffer
 * address:  0x021DC240
 * packet:   pkt_021DC240
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_REGULATION_GetDataSize  0x0201A918  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Takes and clears the +0x144 block; when there was one, calls
 *     0x0201A918(0) and hands its result to 0x02082D44 together with the
 *     object's +0x218 port block and the caller's second argument.  Returns
 *     the block it took.
 */
#include "../include/Obj14345.h"

typedef unsigned long u32;

extern int POKE_REGULATION_GetDataSize(void);
extern void MI_CpuCopy8(char *dst, u32 arg, u32 src);

u32 WIFIBATTLEMATCH_NET_TakeRegBuffer(char *obj, u32 arg)
{
    u32 v = ((struct Obj14345 *)obj)->f144;

    if (v != 0) {
        ((struct Obj14345 *)obj)->f144 = 0;
        MI_CpuCopy8(obj + 0x218, arg, POKE_REGULATION_GetDataSize());
    }
    return v;
}

/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x0201A918
 * The call at +0x14 targets 0x0201A918, which has no label in the ARM9
 * listings and no branch to it from outside this function, so it fails
 * both the `label` and `sole-ref/code` classes.  Bytes are exact.
 */
