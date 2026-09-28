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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216E3C4();
extern int func_0216E40C();

int func_0216E160(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216E3C4(a0);
loc_0216E168:
a0 = *(u8 *)((char *)a0 + 3);
    a0 = func_0216E40C(a0);
loc_0216E16E:
t4 = t4 + 0x90;
*(int *)((char *)t4) = a0;
    return a0;}
