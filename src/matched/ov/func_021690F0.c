/*
 * function: func_021690F0
 * address:  0x021690F0
 * packet:   pkt_021690F0
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

int func_021690F0(int a0)
{

    a0 = func_02012EBC();
loc_021690F6:
    a0 = func_02008B14();
loc_021690FA:
a0 = *(int *)((char *)a0 + 0x10);
    return a0;}
