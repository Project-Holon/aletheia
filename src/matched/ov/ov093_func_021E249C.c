/*
 * function: func_021E249C
 * address:  0x021E249C
 * packet:   pkt_ov093_021E249C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10078.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E249C(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_GetVar(0x51) == 0) {
            s = func_021C88A4((char *)a, 0xb, b);
            ((struct Obj10078 *)s)->f4 = 0x19;
            s[0x14] = 1;
            s[8] = b;
            func_021C88C8((void *)a, s);
        }
    }
}
