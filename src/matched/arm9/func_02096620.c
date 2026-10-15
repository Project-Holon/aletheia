/*
 * function: MSL_C_LIB_IncrementDigits
 * address:  0x02096620
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj11699.h"

typedef unsigned char u8;
typedef unsigned short u16;

void MSL_C_LIB_IncrementDigits(u8 *p, int idx)
{
    u8 *base = p + 5;
    u8 *cur = base + idx - 1;

    for (;;) {
        if (*cur < 9) {
            *cur = *cur + 1;
            return;
        }
        if (cur == base) {
            *cur = 1;
            ((struct Obj11699 *)p)->f2 = ((struct Obj11699 *)p)->f2 + 1;
            return;
        }
        *cur = 0;
        cur--;
    }
}
