/*
 * function: func_0217E00C
 * address: 0x0217E00C
 * packet: pkt_ov176_0217E00C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A574 0x0203A574 arm
 *   d_0217E634 0x0217E634 data a1
 *   d_0217E544 0x0217E544 data a4
 */
#include "../include/Obj24433.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned);
extern int func_0203CD98(void);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern const char d_0217E634[];
extern const unsigned d_0217E544[];
void *func_0217E00C(int unused, int heap)
{
    char *p = func_02030734(heap, 0x1020, 0, d_0217E634, 0x8E);
    func_02082BCC(p, 0, 0x1020);
    ((struct Obj24433 *)p)->f4 = heap;
    if (func_0203CD98())
        func_0203A574(0x1F00, (u32)d_0217E544, 4, (u32)p);
    return p;
}
