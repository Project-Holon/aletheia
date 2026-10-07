/*
 * function: func_0217A178
 * address:  0x0217A178
 * packet:   pkt_ov015_0217A178
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P16 lane E4: libirc check on a packet length n. n == 1 returns 1 when the field at
 *           d_0217ABA8 + 0x24 is set, else whether the first receive byte is not 0xFC. n == 2 or 3 runs two empty
 *           delay loops (bottom-test form (i < n) ? 1 : 0, otherwise mwcc deletes them) and returns 1. Other n returns 0.
 *           The 2/3 test must be a switch after the if: `n == 2 || n == 3` folds to a range test and `n != 2 && n != 3`
 *           gives cmpne/movne. Called from func_0217A334 as int(u32).
 *
 * symbols:
 *   g_0217ABD8     0x0217ABD8  data  ov015
 *   d_0217ABA8     0x0217ABA8  data  ov015
 */

#include "../include/G_ov015_0217ABA8.h"

extern unsigned char g_0217ABD8[];
extern struct G_ov015_0217ABA8 d_0217ABA8;

int func_0217A178(unsigned long n)
{
    unsigned long i;

    if (n == 1) {
        if (*(int *)(((char *)&d_0217ABA8) + 0x24))
            return 1;
        return g_0217ABD8[0] != 0xFC;
    }
    switch (n) {
    case 2:
    case 3:
        for (i = 0; (i < 4) ? 1 : 0; i++)
            ;
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        return 1;
    }
    return 0;
}
