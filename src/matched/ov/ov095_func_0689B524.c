/*
 * function: func_0689B524
 * address: 0x0689B524
 * packet: pkt_ov095_0689B524
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing 0689B546..0689B548 is Thumb alignment padding.
 * symbols:
 *   func_0689B548 0x0689B548 thumb ov095
 */
#include "../include/Obj21896.h"
typedef unsigned char u8;
extern int func_0689B548(void *, int, int);
int func_0689B524(void *p, u8 *q)
{
    int zero = 0;
    int value;
    value = func_0689B548(((struct Obj21896 *)p)->fB0, 0, 0);
    if (value != zero - 1) {
        *q = value;
        return 1;
    }
    return zero;
}
