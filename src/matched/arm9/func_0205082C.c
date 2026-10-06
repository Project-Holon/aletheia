/*
 * function: func_0205082C
 * address:  0x0205082C
 * packet:   pkt_0205082C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj02611.h"
#include "../include/Obj16157.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020500A0(int p0);

void func_0205082C(void *p, int idx, u16 h)
{
    char *e = (char *)(((struct Obj16157 *)p)->f18 + idx * 40);
    ((struct Obj02611 *)e)->fE = h;
    func_020500A0((int)e);
}
