/*
 * function: func_021E98BC
 * address:  0x021E98BC
 * packet:   pkt_ov093_021E98BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E96C4  0x021E96C4  thumb  ov093
 */
#include "../include/Obj10105.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
struct QU;
extern void func_021E9728(struct QU *p, u32 v);
extern int func_021E96C4(char *p, int *st);

void func_021E98BC(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj10105 *)p)->fBC = a;
    ((struct Obj10105 *)p)->fC0 = func_021D5440(a);
    ((struct Obj10105 *)p)->fB8 = b;
    func_021E9728((struct QU *)p, (u32)func_021E96C4);
}
