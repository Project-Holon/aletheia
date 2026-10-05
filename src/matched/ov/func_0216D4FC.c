/*
 * function: func_0216D4FC
 * address:  0x0216D4FC
 * packet:   pkt_0216D4FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj17777.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_0216D4FC(int a0)
{
    int a1;
a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 + 1;
((struct Obj17777 *)a0)->f6 = a1;
    return a0;}
