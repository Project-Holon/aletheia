/*
 * function: func_021753D0
 * address:  0x021753D0
 * packet:   pkt_ov011_021753D0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120D8  0x020120D8  thumb
 *   func_0217544C  0x0217544C  thumb ov011
 */
#include "../include/Obj03548.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct F86 {
    u16 lo : 9;
    u16 x : 6;
    u16 hi : 1;
} F86;

int func_020120D8(char *a);
void func_0217544C(u8 *p);

int func_021753D0(u8 *p, int i, u8 v)
{
    if (!(p[0x8FB] & (1 << i))) {
        (p + i)[0x945] = v;
        return 0;
    }
    if (((F86 *)(p + 0x86))->x == 0) {
        if (p[0x154] == 4 && p[0x158] == 0 && func_020120D8((char *)((struct Obj03548 *)p)->f0) == 0) {
            p[0x154] = i;
            p[0x156] = 1;
            p[0x158] = v;
            p[0x159] = v;
            func_0217544C(p);
            return 1;
        }
        (p + i)[0x945] = v;
    } else {
        (p + i)[0x945] = v;
    }
    return 0;
}
