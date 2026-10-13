/*
 * function: func_02212FD8
 * address: 0x02212FD8
 * packet: pkt_ov199_02212FD8
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_02213D04 0x02213D04 data a1 ov199
 */
#include "../include/Obj08370.h"
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, int, int);
extern const char d_02213D04[];
int *func_02212FD8(int unused, unsigned heap, char *ctx)
{
    int zero = 0;
    int *p = func_02030734(heap, 0x28, zero, d_02213D04, 0x588);
    MI_CpuFill8(p, zero, 0x28);
    p[0] = ((struct Obj08370 *)ctx)->f4;
    p[1] = zero;
    p[2] = 1;
    p[4] = (int)(ctx + 0x40);
    if (((struct Obj08370 *)ctx)->fC == 0) p[3] = 0x24;
    else p[3] = 0x34;
    if (((struct Obj08370 *)ctx)->f220) {
        ((struct Obj08370 *)ctx)->f220 = zero;
        p[5] = 1;
    } else p[5] = zero;
    return p;
}
