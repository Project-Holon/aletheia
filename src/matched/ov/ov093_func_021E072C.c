/*
 * unit: yes
 * function: func_021E072C, func_021E080C
 * address: 0x021E072C
 * packet: pkt_ov093_021E072C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E080C store-return stub included.
 * volatile: 021E079E,021E07AC,021E07BA,021E07C8,021E07D6,021E07E4,021E07F2 reread byte +4
 * symbols:
 *   data_021F2B70 0x021F2B70 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj06266.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct Record { u32 f0; volatile u8 f4; u8 f5; u8 f6; u8 f7; };
extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
void func_021E072C(int unused, void *q, int id)
{
    u8 target;
    u8 *r;
    struct Record *e;
    u32 i;
    if (id == BTL_EVENT_GetVar(3)) {
        target = BTL_EVENT_GetVar(6);
        if (BTL_POKEPARAM_HasSubstitute(func_021C7CF4(q, target)) == 0) {
            r = func_021C88A4(q, 14, id);
            ((struct Obj06266 *)r)->f4 = 7;
            ((struct Obj06266 *)r)->fC = -1;
            r[14] = 1;
            r[15] = 1;
            r[16] = target;
            func_021C88C8(q, r);
        }
        e = (struct Record *)func_021C88A4(q, 26, id);
        e->f7 = func_021B9A40(target);
        e->f4 = 3;
        for (i = 1; i < 3; i++) ((u8 *)e)[4 + i] = 0;
        if (e->f4 > 1) e->f5 |= 1;
        if (e->f4 > 1) e->f5 |= 2;
        if (e->f4 > 1) e->f5 |= 8;
        if (e->f4 > 1) e->f5 |= 4;
        if (e->f4 > 1) e->f5 |= 64;
        if (e->f4 > 1) e->f5 |= 128;
        if (e->f4 > 2) e->f6 |= 1;
        func_021C88C8(q, e);
    }
}
extern u32 data_021F2B70[];
u32 *func_021E080C(u32 *p)
{
    *p = 3;
    return data_021F2B70;
}
