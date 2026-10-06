/*
 * function: func_0217F098
 * address:  0x0217F098
 * packet:   pkt_ov019_0217F098
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_0217F020  0x0217F020  thumb  ov019
 *   func_02191558  0x02191558  thumb  ov021
 *   func_021915EC  0x021915EC  thumb  ov021
 *   d_021807F8     0x021807F8  data  a4
 */
#include "../include/Obj00484.h"

typedef unsigned char  u8;
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern unsigned int func_02188C54(u8 *p);
typedef unsigned int   u32;
extern int func_021904B0(u32 a, u32 b);
typedef unsigned short u16;
struct Fx;
struct R;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0217F020(unsigned char *p);
extern struct R *func_02191558(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
struct R;
extern void func_021915EC(struct R *r);
extern int d_021807F8[];

void func_0217F098(unsigned char *base, u8 *x)
{
    int r6;
    if (((struct Obj00484 *)base)->f280C == 0) {
        if (*(int *)&((struct Obj00484 *)base)->f2808 != 0)
            func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
        r6 = func_02188C54(x);
        *(int *)(base + 0x2808) = func_021904B0(r6, 200);
        *(int *)&((struct Obj00484 *)base)->f2820 = (int)func_020457B0(0x100, 0x41);
        *(int *)&((struct Obj00484 *)base)->f2824 = (int)func_020457B0(0x100, 0x41);
        func_0217F020(base);
        ((struct Obj00484 *)base)->f280C = (int)func_02191558((struct Fx *)r6, *(int *)(base + 0x2808), 0, 1, 0x13, 0x1e, 4);
    } else {
        func_021915EC((struct R *)(((struct Obj00484 *)base)->f280C));
    }
}
