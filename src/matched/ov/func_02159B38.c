/*
 * function: func_02159B38
 * address:  0x02159B38
 * packet:   pkt_02159B38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_020127A4();
extern int func_02012AC8();

int func_02159B38(int a0)
{

    a0 = func_0215A5E4(a0);
loc_02159B3E:
    a0 = func_020127A4(a0);
loc_02159B42:
    a0 = func_02012AC8(a0);
loc_02159B46:
    return a0;}
