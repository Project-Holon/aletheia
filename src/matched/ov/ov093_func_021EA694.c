/*
 * function: func_021EA694
 * address:  0x021EA694
 * packet:   pkt_ov093_021EA694
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEEF4  0x021EEEF4  thumb  ov093
 *   func_021EA730  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned short u16;

extern void func_021EEEF4(unsigned int a, u16 b, unsigned int c);
typedef unsigned int   u32;
extern void func_021EA730(char *p, u32 a, u16 b, u32 c);

void func_021EA694(char *p, u16 k, int *c)
{
    func_021EEEF4(((struct Obj01899 *)p)->fAC, k, (unsigned int)c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}
