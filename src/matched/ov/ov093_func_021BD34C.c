/*
 * function: func_021BD34C
 * address:  0x021BD34C
 * packet:   pkt_ov093_021BD34C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB878  0x021BB878  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 */
#include "../include/Obj13306.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern u8 *func_021BB878(u8 *p, u32 i);
struct S2;
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_021D5B68(void *p);

int func_021BD34C(u8 *p, u8 **q, u8 **out)
{
    u8 *m;
    u8 *x;
    u8 n;
    int f;
    if (p[2] != 0) return 0;
    *out = (u8 *)func_021B9BF0((struct S2 *)(*(u8 **)(func_021BB85C(*q, p[0]) + 4)), p[1]);
    p[1]++;
    while (p[0] < 4) {
        m = func_021BB878(*q, p[0]);
        if (m) {
            n = p[3] == 0 ? m[9] : 3;
            for (; p[1] < n; p[1]++) {
                x = (u8 *)func_021B9BF0((struct S2 *)(*(u8 * *)&((struct Obj13306 *)m)->f4), p[1]);
                if (x) f = func_021D5B68(x) == 0;
                else f = 0;
                if (f) return 1;
            }
        }
        p[0]++;
        p[1] = 0;
    }
    p[2] = 1;
    return 1;
}
