/*
 * function: func_021E9760
 * address:  0x021E9760
 * packet:   pkt_ov093_021E9760
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E964C  0x021E964C  thumb  ov093
 */
#include "../include/Obj06279.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021E9728(void *p, u32 v);
extern int func_021E964C(char *p, int *st);

void func_021E9760(char *p, u8 *a, int b, int c)
{
    *(u8 * *)&((struct Obj06279 *)p)->fBC = a;
    ((struct Obj06279 *)p)->fC0 = func_021D5440(a);
    ((struct Obj06279 *)p)->fB8 = c;
    ((struct Obj06279 *)p)->fC4 = 0;
    ((struct Obj06279 *)p)->f175 = b;
    func_021E9728(p, (u32)func_021E964C);
}
