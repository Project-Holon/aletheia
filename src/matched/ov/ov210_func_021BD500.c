/*
 * function: func_021BD500
 * address: 0x021BD500
 * packet: pkt_ov210_021BD500
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCAC8 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   func_021BC8B4 0x021BC8B4 thumb ov210
 *   func_021BE83C 0x021BE83C thumb ov210
 *   func_021C0234 0x021C0234 thumb ov210
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021BF480 0x021BF480 thumb ov210
 *   func_021BCAC8 0x021BCAC8 thumb ov210
 *   func_021BC5C8 0x021BC5C8 thumb ov210
 *   func_021BCD30 0x021BCD30 thumb ov210
 */
#include "../include/Obj06694.h"
typedef unsigned char u8;
extern void func_021BC8B4(int);
extern void func_021BE83C(u8 *);
extern void func_021C0234(char *ctx);
struct S;
extern int func_021B7A64(struct S *p);
extern void func_021BF480(int p);
extern void func_021BCAC8(u8 *);
extern void func_021BC5C8(void);
extern void func_021BCD30(u8 *);
int func_021BD500(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 0;
        func_021BC8B4(1);
        func_021BE83C(p);
        func_021C0234((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06694 *)p)->f1E0) == 0) {
            func_021BF480((int)p);
            func_021BCAC8(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 10;
        }
    }
    return 9;
}
