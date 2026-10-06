/*
 * function: func_021EA678
 * address:  0x021EA678
 * packet:   pkt_ov093_021EA678
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEE80  0x021EEE80  thumb  ov093
 *   func_021EA730  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned short u16;

extern void func_021EEE80(unsigned int a, u16 k, unsigned int *p);
typedef unsigned int   u32;
extern void func_021EA730(char *p, u32 a, u16 b, u32 c);

void func_021EA678(char *p, u16 k, int *c)
{
    func_021EEE80(((struct Obj01899 *)p)->fAC, k, (unsigned int *)c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}
