/*
 * function: ENCEFF_StepGridColumnFlip
 * address:  0x021F5AE8
 * packet:   pkt_ov080_021F5AE8
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09916.h"

typedef unsigned char u8;
typedef unsigned short u16;

void ENCEFF_StepGridColumnFlip(u8 *w)
{
    int *c = (int *)(w + 0x3000);

    if (c[0] < ((struct Obj09916 *)w)->f3008) {
        if (c[1] == 0) {
            int i;

            for (i = 0; i < ((struct Obj09916 *)w)->f300A; i++)
                *(int *)(w + (c[0] + i * ((struct Obj09916 *)w)->f3008) * 64 + 0x34) = 1;
            c[0]++;
            c[1] = 1;
        } else {
            c[1]--;
        }
    }
}
