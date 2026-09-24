/*
 * function: func_021690A4
 * address:  0x021690A4
 * packet:   pkt_021690A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012EBC();
extern int func_02008B14();

int func_021690A4(int a0)
{

    a0 = func_02012EBC();
loc_021690AA:
    a0 = func_02008B14();
loc_021690AE:
a0 = a0 + 4;
    return a0;}
