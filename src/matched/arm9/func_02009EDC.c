/*
 * function: func_02009EDC
 * address:  0x02009EDC
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj11227.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082BCC(void *p, int c, u32 n);
struct Obj;
extern void func_0200A480(struct Obj *p);

void func_02009EDC(void *a0)
{
    u8 buf[12];

    func_02082BCC(buf, 0, 0xc);
    ((struct Obj11227 *)buf)->f0 = a0;
    ((struct Obj11227 *)buf)->f4 = 1;
    func_02082BCC(a0, 0, 0xa94);
    func_0200A480((struct Obj *)buf);
}
