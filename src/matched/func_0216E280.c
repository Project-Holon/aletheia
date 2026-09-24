/*
 * function: func_0216E280
 * address:  0x0216E280
 * packet:   pkt_0216E280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020490F4();

int func_0216E280(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = 0x30;
    a0 = func_020490F4(a0);
loc_0216E28A:
*(int *)((char *)t4 + 0x14) = a0;
    return a0;}
