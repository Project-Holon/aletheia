/*
 * function: func_020507F0
 * address:  0x020507F0
 * packet:   pkt_020507F0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16154.h"
#include "../include/Obj16155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_020507F0(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16154 *)p)->f18 + idx * 40);
    ((struct Obj16155 *)e)->f18 = v;
}
