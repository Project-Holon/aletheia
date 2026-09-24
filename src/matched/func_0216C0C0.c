/*
 * function: func_0216C0C0
 * address:  0x0216C0C0
 * packet:   pkt_0216C0C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02045808();
extern int func_020307B0();

int func_0216C0C0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x20);
    a0 = func_02045808(a0);
loc_0216C0CA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0216C0D0:
    return a0;}
