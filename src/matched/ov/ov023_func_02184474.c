/*
 * function: func_02184474
 * address:  0x02184474
 * packet:   pkt_ov023_02184474
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_02039338  0x02039338  arm
 *   func_021844D8  0x021844D8  thumb  ov023
 */
#include "../include/Obj09766.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02185AB0(char *p, int a, int b);
extern u16 func_02039338(void);
extern void func_021844D8(char *p, int a, int b);

void func_02184474(int a0, int a1, u8 *a2, char *p, int a4)
{
    if (((struct Obj09766 *)p)->f928A == 0) {
        func_02185AB0(p, 1, *a2);
        if (func_02039338() == 0 && ((struct Obj09766 *)p)->f194 == 1) {
            ((struct Obj09766 *)p)->f428C = 0;
            func_021844D8(p, 0, a4);
        }
    }
}
