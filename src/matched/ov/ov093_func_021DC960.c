/*
 * function: BTL_ABILITY_RattledRaiseSpeedOnHit
 * address:  0x021DC960
 * packet:   pkt_ov093_021DC960
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
#include "../include/Obj06263.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void BTL_ABILITY_RattledRaiseSpeedOnHit(int a, void *b, int c)
{
    u8 *m;
    u8 k;

    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0) {
        k = BTL_EVENT_GetVar(0x16);
        if (k == 0x10 || k == 6 || k == 7) {
            m = (u8 *)func_021C88A4(b, 0xe, c);
            ((struct Obj06263 *)m)->f0 |= 2 << 22;
            m[0xf] = 1;
            m[0x10] = c;
            ((struct Obj06263 *)m)->f4 = 5;
            m[0xc] = 1;
            func_021C88C8(b, m);
        }
    }
}
