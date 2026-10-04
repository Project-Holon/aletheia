/*
 * function: func_0216BFD4
 * address:  0x0216BFD4
 * packet:   pkt_ov010_0216BFD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. func_02045838 takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045838  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 */
#include "../include/Obj03544.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern char d_02172A60[];

int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x37);
    func_02082BCC(p, 0, 0x2c);
    p[0] = a1;
    p[6] = s0;
    ((struct Obj03544 *)p)->f4 = a2;
    ((struct Obj03544 *)p)->f6 = a3;
    p[10] = s2;
    p[8] = (int)func_020457B0(0xb, a0);
    if (s1)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)s1);
    return p;
}
