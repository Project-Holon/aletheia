/*
 * function: func_021754B4
 * address: 0x021754B4
 * packet: pkt_ov011_021754B4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj07331.h"
typedef unsigned char u8;
typedef struct { u8 low : 4; u8 flag : 1; u8 high : 3; } Flags;
int func_021754B4(u8 *p, int *out)
{
    int value;
    if (p == 0 || ((struct Obj07331 *)p)->f8 == 0) return 0;
    value = p[0x154];
    if (value != 4 && ((Flags *)(p + 0x8F8))->flag == 1) {
        *out = value;
        return 1;
    }
    return 0;
}
