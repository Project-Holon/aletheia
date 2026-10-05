/*
 * function: func_0215F2A0
 * address:  0x0215F2A0
 * packet:   pkt_0215F2A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201213C  0x0201213C  thumb
 *   func_020121CC  0x020121CC  thumb
 */
#include "../include/Obj17704.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201213C();
struct IcaAnime;
extern u32 func_020121CC(struct IcaAnime *p);

int func_0215F2A0(int a0, int a1)
{
    int t4;

t4 = ((struct Obj17704 *)((char *)a0))->f0;
a1 = 0;
a0 = t4 + 0;
    a0 = func_0201213C(a0, a1);
loc_0215F2AC:
a0 = t4 + 0;
    a0 = func_020121CC((struct IcaAnime *)a0);
loc_0215F2B2:
a0 = 1;
    return a0;}
