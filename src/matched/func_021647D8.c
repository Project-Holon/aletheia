/*
 * function: func_021647D8
 * address:  0x021647D8
 * packet:   pkt_021647D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216480C  0x0216480C  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216480C();
extern int func_020307B0();

int func_021647D8(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216480C(a0);
loc_021647E0:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_021647E6:
    return a0;}
