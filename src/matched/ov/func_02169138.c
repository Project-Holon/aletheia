/*
 * function: func_02169138
 * address:  0x02169138
 * packet:   pkt_02169138
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
 *   func_02008BD0  0x02008BD0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012EBC();
extern int func_02008B14();
extern int func_02008BD0();

int func_02169138(int a0)
{

    a0 = func_02012EBC(a0);
loc_0216913E:
    a0 = func_02008B14(a0);
loc_02169142:
    a0 = func_02008BD0(a0);
loc_02169146:
    return a0;}
