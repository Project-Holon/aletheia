/*
 * function: func_021C0844
 * address:  0x021C0844
 * packet:   pkt_ov021_021C0844
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021C09B0  0x021C09B0  thumb  ov021
 *   func_021C09A8  0x021C09A8  thumb  ov021
 *   func_021C0A10  0x021C0A10  thumb  ov021
 *   func_021C0A48  0x021C0A48  thumb  ov021
 *   func_021C0A70  0x021C0A70  thumb  ov021
 *   func_021C0988  0x021C0988  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02012374  0x02012374  thumb
 */
#include "../include/Obj00707.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C09B0(u8 *p);
extern void func_021C09A8(u8 *p, int *st, int v);
extern void func_021C0A10(u8 *p);
extern void func_021C0A48(u8 *p);
extern int func_021C0A70(u8 *p);
extern void func_021C0988(u8 *p);
struct Evt;
extern void *func_02188C80(void *p);
extern void *func_02029830(void *a, u32 b);
extern void *func_02029620(void *a, u16 b, u16 c);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_021C0844(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00707 *)p)->f16 % 15 == 0) {
            func_021C09B0(p);
            if (p[0x14] <= p[0x15]) {
                func_021C09A8(p, st, 1);
            }
        }
        break;
    case 1:
        if (((struct Obj00707 *)p)->f16 > 10) {
            func_021C0A10(p);
            func_02012374((struct Evt *)a, func_02029830(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0x514));
            func_021C09A8(p, st, 2);
        }
        break;
    case 2:
        if (func_021C0A70(p) != 0) {
            func_021C0A48(p);
            func_021C09A8(p, st, 3);
        }
        break;
    case 3:
        func_02012374((struct Evt *)a, func_02029620(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0, 6));
        func_021C09A8(p, st, 4);
        break;
    case 4:
        func_021C0988(p);
        return 1;
    }
    ((struct Obj00707 *)p)->f16 = ((struct Obj00707 *)p)->f16 + 1;
    return 0;
}
