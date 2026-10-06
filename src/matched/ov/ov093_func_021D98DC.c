/*
 * function: func_021D98DC
 * address:  0x021D98DC
 * packet:   pkt_ov093_021D98DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 */
#include "../include/Obj13463.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D7B74(u8 *p, u32 k);

void func_021D98DC(int a, void *b, int c)
{
    int h;
    u8 *p;

    if (c == func_021D775C(2) && func_021D775C(0x39) == 1) {
        h = func_021D7B74(func_021C7CF4(b, c), 8);
        func_021C88B4(b, 2, c);
        p = func_021C88A4(b, 7, c);
        p[6] = c;
        ((struct Obj13463 *)p)->f4 = h;
        func_021C88C8(b, p);
        func_021C88B4(b, 3, c);
    }
}
