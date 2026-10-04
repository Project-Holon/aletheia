/*
 * function: func_0216E160
 * address:  0x0216E160
 * packet:   pkt_0216E160
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216E40C  0x0216E40C  thumb  ov010
 */
#include "../include/Obj17853.h"
#include "../include/Obj17854.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0216E3C4(void *p);
extern u32 func_0216E40C(int i);

int func_0216E160(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_0216E3C4((void *)a0);
loc_0216E168:
a0 = ((struct Obj17854 *)p)->f3;
    a0 = func_0216E40C(a0);
loc_0216E16E:
t4 = t4 + 0x90;
((struct Obj17853 *)((char *)t4))->f0 = a0;
    return a0;}
