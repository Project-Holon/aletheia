/*
 * function: func_0216480C
 * address:  0x0216480C
 * packet:   pkt_0216480C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02049238();

int func_0216480C(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 8);
    a0 = func_02049238(a0);
loc_02164816:
a0 = 0;
*(int *)((char *)t4 + 8) = a0;
    return a0;}
