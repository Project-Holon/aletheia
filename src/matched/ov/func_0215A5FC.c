/*
 * function: func_0215A5FC
 * address:  0x0215A5FC
 * packet:   pkt_0215A5FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);

int func_0215A5FC(int a0)
{
    void *v0;

    v0 = func_0215A5F4((void *)a0);
loc_0215A602:
    a0 = func_02158F58((int)v0);
loc_0215A606:
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}
