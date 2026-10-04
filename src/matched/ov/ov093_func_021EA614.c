/*
 * function: func_021EA614
 * address:  0x021EA614
 * packet:   pkt_ov093_021EA614
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EA55C  0x021EA55C  thumb  ov093
 *   func_021EA730  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned char u8;

struct H {
    u8 b0[2];
    u8 b2;
};

extern void func_021EA55C(struct H *p, int a);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021EA730(char *p, u32 a, u16 b, u32 c);

void func_021EA614(char *p, struct H *h)
{
    func_021EA55C(h, ((struct Obj01899 *)p)->fAC);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, h->b2, 0);
}
