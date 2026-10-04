/*
 * function: func_0200ECF0
 * address:  0x0200ECF0
 * packet:   pkt_0200E9E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15609.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Src0200EC2C;
struct Dst0200EC2C;
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);

void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3)
{
    int v = ((struct Obj15609 *)a0)->f1554 - 1 - (int)a1;

    if (v < 0)
        v += 0xf;
    func_0200EC2C((const struct Src0200EC2C *)((u8 *)a0 + v * 0x16c), (int)a2, a3);
}
