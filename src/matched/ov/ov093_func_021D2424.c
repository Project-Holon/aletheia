/*
 * function: func_021D2424
 * address:  0x021D2424
 * packet:   pkt_ov093_021D2424
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8590  0x021B8590  thumb  ov093
 *   func_021EA7D8  0x021EA7D8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 */
#include "../include/Obj05207.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u8 b);
extern u8 func_021B8E70(u8 *p, u32 k);
extern u32 func_021CD9E0(u8 *p);
extern unsigned int func_021B8590(unsigned char *p);
extern void func_021EA7D8(void *ctx, int a);
extern int func_021EA7E8(void *w, u32 v);

int func_021D2424(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05207 *)p)->f0, func_021B8D8C(((struct Obj05207 *)p)->f0, ((struct Obj05207 *)p)->f4, *c));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05207 *)p)->f0))
            return 1;
        func_021EA7D8(((struct Obj05207 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05207 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}
