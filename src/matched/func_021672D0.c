/*
 * function: func_021672D0
 * address:  0x021672D0
 * packet:   pkt_021672D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EC0  0x02012EC0  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C224  0x0200C224  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012EC0();
extern int func_0200C0E8();
extern int func_0200C224();

int func_021672D0(int a0)
{

a0 = *(int *)((char *)a0 + 8);
    a0 = func_02012EC0(a0);
loc_021672D8:
    a0 = func_0200C0E8(a0);
loc_021672DC:
    a0 = func_0200C224(a0);
loc_021672E0:
    return a0;}
