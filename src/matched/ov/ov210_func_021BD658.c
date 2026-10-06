/*
 * function: func_021BD658
 * address: 0x021BD658
 * packet: pkt_ov210_021BD658
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCAF8 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   func_021BC8B4 0x021BC8B4 thumb ov210
 *   func_021BE8F8 0x021BE8F8 thumb ov210
 *   func_021C02DC 0x021C02DC thumb ov210
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021BF728 0x021BF728 thumb ov210
 *   func_021BF4A4 0x021BF4A4 thumb ov210
 *   func_021BCAF8 0x021BCAF8 thumb ov210
 *   func_021BC5C8 0x021BC5C8 thumb ov210
 *   func_021BCD30 0x021BCD30 thumb ov210
 */
#include "../include/Obj06695.h"
typedef unsigned char u8;
extern void func_021BC8B4(int);
extern void func_021BE8F8(u8 *);
extern void func_021C02DC(char *ctx);
struct S;
extern int func_021B7A64(struct S *p);
extern void func_021BF728(u8 *, int);
extern void func_021BF4A4(char *p);
extern void func_021BCAF8(u8 *);
extern void func_021BC5C8(void);
extern void func_021BCD30(u8 *);
int func_021BD658(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 1;
        func_021BC8B4(1);
        func_021BE8F8(p);
        func_021C02DC((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06695 *)p)->f1E0) == 0) {
            func_021BF728(p, 0);
            func_021BF4A4((char *)p);
            func_021BCAF8(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 13;
        }
    }
    return 12;
}
