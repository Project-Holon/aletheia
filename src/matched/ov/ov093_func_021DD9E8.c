/*
 * function: BTL_ITEM_RaiseStat
 * address:  0x021DD9E8
 * packet:   pkt_ov093_021DD9E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07818.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void BTL_ITEM_RaiseStat(void *a, int b, int c, int d)
{
    u8 *p;
    if (b == BTL_EVENT_GetVar(2)) {
        p = func_021C88A4(a, 0xe, b);
        ((struct Obj07818 *)p)->f4 = c;
        p[0xc] = d;
        p[0xf] = 1;
        p[0x10] = b;
        func_021C88C8(a, p);
    }
}
