/*
 * function: func_0216D3B4
 * address:  0x0216D3B4
 * packet:   pkt_0216D3B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_02197C78  0x02197C78  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D67C();
extern int func_0216D948();
extern int func_02197C78();

int func_0216D3B4(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D67C(a0);
loc_0216D3BC:
    a0 = func_0216D948(a0);
loc_0216D3C0:
    if (a0 != 1) goto loc_0216D3CA;
loc_0216D3C4:
a0 = t4 + 0;
    a0 = func_02197C78(a0);
loc_0216D3CA:
    return a0;}
