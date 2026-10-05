/*
 * function: func_0216E1A4
 * address:  0x0216E1A4
 * packet:   pkt_0216E1A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 */
#include "../include/Obj09167.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_0216D588(void *p);
extern u16 func_0216D598(void *p);
extern u16 func_0216D590(void *p);

int func_0216E1A4(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1AE:
((struct Obj09167 *)((char *)t4))->f0 = a0;
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1B6:
((struct Obj09167 *)t4)->f2 = a0;
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1BE:
((struct Obj09167 *)t4)->f4 = a0;
    return a0;}
