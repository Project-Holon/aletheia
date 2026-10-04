/*
 * function: func_021D440C
 * address:  0x021D440C
 * packet:   pkt_021D440C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (hidden in the pool run after func_021D43E0): if the
 * object at d_021F3B88 has byte +0xa set, copies its 32-byte aggregate
 * at +0x18 into dst and returns 1, else returns 0.
 *
 * symbols:
 *   d_021F3B88  0x021F3B88  data
 */
#include "../include/Obj18400.h"

typedef struct {
    int w[8];
} S32;

extern int d_021F3B88;

int func_021D440C(S32 *dst)
{
    char *p = (char *)d_021F3B88;

    if (((struct Obj18400 *)p)->fA != 0) {
        *dst = *(S32 *)(p + 0x18);
        return 1;
    }
    return 0;
}
