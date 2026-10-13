/*
 * function: func_021E9808
 * address:  0x021E9808
 * packet:   pkt_ov093_021E9808
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021E9848  0x021E9848  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E9884  0x021E9884  thumb  ov093
 */
#include "../include/Obj06281.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021E9848(void *a, u32 *b, int c);
struct QU;
extern void func_021E9728(struct QU *p, u32 v);
extern int func_021E9884(char *p);

void func_021E9808(char *p, u32 *q, int c)
{
    u32 v = *q;

    ((struct Obj06281 *)p)->fBC = v;
    ((struct Obj06281 *)p)->fC0 = BTL_POKEPARAM_GetPokeId((u8 *)v);
    *(u32 * *)&((struct Obj06281 *)p)->f170 = q;
    ((struct Obj06281 *)p)->fB8 = c;
    func_021E9848(((struct Obj06281 *)p)->f180, q, c);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}
