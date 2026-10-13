/*
 * function: func_021E97BC
 * address:  0x021E97BC
 * packet:   pkt_ov093_021E97BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021E97F8  0x021E97F8  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E9884  0x021E9884  thumb  ov093
 */
#include "../include/Obj06280.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021E97F8(void *a, u8 *b, int c);
struct QU;
extern void func_021E9728(struct QU *p, u32 v);
extern int func_021E9884(void *p);

void func_021E97BC(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj06280 *)p)->fBC = a;
    ((struct Obj06280 *)p)->fC0 = BTL_POKEPARAM_GetPokeId(a);
    ((struct Obj06280 *)p)->fB8 = b;
    func_021E97F8(((struct Obj06280 *)p)->f180, *(u8 * *)&((struct Obj06280 *)p)->fBC, b);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}
