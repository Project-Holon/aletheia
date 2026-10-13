/*
 * function: func_0220B0CC
 * address:  0x0220B0CC
 * packet:   pkt_0220B0CC
 * region:   ov187
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0203133C  0x0203133C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_0220B2E0     0x0220B2E0  data  ov187  a4
 */
#include "../include/Obj14488.h"
typedef unsigned int u32;

struct S020314B8;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203133C(struct S020314B8 *p);
extern void MI_CpuFill8(void *p, u32 v, u32 n);

void func_0220B0CC(int *p)
{
    if (((struct Obj14488 *)p)->f8 != 0)
        func_02034714((void *)0x0220b2e0, 0, (void *)0x0220b2e0);
    func_0203133C(((struct Obj14488 *)p)->f0);
    MI_CpuFill8(p, 0, 0x28);
}
