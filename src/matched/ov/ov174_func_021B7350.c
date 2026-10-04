/*
 * function: func_021B7350
 * address:  0x021B7350
 * packet:   pkt_021B7350
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj24210.h"

struct Cfg;
extern void func_02045374(struct Cfg *cfg);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);

void func_021B7350(int a, int *p)
{
    func_02045374((struct Cfg *)(((struct Obj24210 *)p)->f18));
    func_02041B6C(0);
}
