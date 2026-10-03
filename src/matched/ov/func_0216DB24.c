/*
 * function: func_0216DB24
 * address:  0x0216DB24
 * packet:   pkt_0216DB24
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
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D67C();
extern int func_0216D948(int a0);
extern int func_0216DAA0();

int func_0216DB24(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D67C(a0);
loc_0216DB2C:
    a0 = func_0216D948(a0);
loc_0216DB30:
    if (a0 != 0) goto loc_0216DB38;
loc_0216DB34:
a0 = 0;
    return a0;
loc_0216DB38:
a0 = t4 + 0;
    a0 = func_0216DAA0(a0);
loc_0216DB3E:
    if (a0 == 0) goto loc_0216DB46;
loc_0216DB42:
a0 = 1;
    return a0;
loc_0216DB46:
a0 = 0;
    return a0;}
