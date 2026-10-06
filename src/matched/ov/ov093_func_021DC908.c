/*
 * function: func_021DC908
 * address:  0x021DC908
 * packet:   pkt_ov093_021DC908
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06262.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DC908(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D775C(0x16) == 0x10) {
        m = (u8 *)func_021C88A4(b, 0xe, c);
        ((struct Obj06262 *)m)->f0 |= 4 << 21;
        m[0xf] = 1;
        m[0x10] = c;
        ((struct Obj06262 *)m)->f4 = 1;
        m[0xc] = 1;
        func_021C88C8(b, m);
    }
}
