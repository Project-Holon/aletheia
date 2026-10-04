/*
 * function: func_021EB820
 * address:  0x021EB820
 * packet:   pkt_ov093_021EB820
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 */
#include "../include/Obj07851.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021BA1A8(char **p, int m);

int func_021EB820(u8 *a)
{
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 4) != 0) {
        return 6;
    }
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 8) != 0) {
        return 3;
    }
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 0x80) != 0) {
        return 4;
    }
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 0x10) != 0) {
        return 5;
    }
    return 1;
}
