/*
 * function: func_0216CD64
 * address:  0x0216CD64
 * packet:   pkt_0216CD64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030D28  0x02030D28  arm
 *   func_0219C5FC  0x0219C5FC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02030D28();
extern int func_0219C5FC();

int func_0216CD64(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x20);
    a0 = func_02030D28(a0);
loc_0216CD6E:
a0 = t4 + 0;
    a0 = func_0219C5FC(a0);
loc_0216CD74:
    return a0;}
