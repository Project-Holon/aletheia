/*
 * function: func_021ADBB0
 * address:  0x021ADBB0
 * packet:   pkt_ov021_021ADBB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_021ADC04  0x021ADC04  thumb  ov021
 *   func_02047910  0x02047910  arm
 */
#include "../include/Obj05043.h"
#include "../include/Obj12797.h"
typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 func_021ABE14(u8 *p);
extern int func_02188BE8(void *a);
extern void func_021ADC04(u8 *w, u8 *o);
extern int func_02047910(void *a, int idx, int amount);

void func_021ADBB0(int a, u8 *w)
{
    int i;
    u8 *o = *(u8 * *)&((struct Obj05043 *)w)->f8;

    if (func_02188BE8((void *)func_021ABE14((u8 *)(((struct Obj12797 *)o)->f0))) != 0 && w[2] == 0) {
        func_021ADC04(w, o);
        for (i = 0; i < o[0x88]; i++) {
            func_02047910((void *)(*(int *)(o + 0x28 + w[0x1c] * 0x18)), (u16)i, 0x1000);
        }
    }
}
