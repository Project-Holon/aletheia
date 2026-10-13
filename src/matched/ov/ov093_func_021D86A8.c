/*
 * function: BTL_CALC_SteadfastOnFlinch
 * address:  0x021D86A8
 * packet:   pkt_ov093_021D86A8
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
#include "../include/Obj05216.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *func_021C88A4(char *p, int a, int b);
void func_021C88C8(void *a, void *b);

void BTL_CALC_SteadfastOnFlinch(void *a, int b, int c)
{
    u8 *p;

    if (BTL_EVENT_GetVar(0x22) == 6) {
        if (c == BTL_EVENT_GetVar(2)) {
            p = func_021C88A4((char *)b, 0xe, c);
            ((struct Obj05216 *)p)->f0 |= 2 << 22;
            ((struct Obj05216 *)p)->f4 = 5;
            p[0xc] = 1;
            p[0xe] = 0;
            p[0xf] = 1;
            p[0x10] = c;
            func_021C88C8((void *)b, p);
        }
    }
}
