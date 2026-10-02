/*
 * function: func_02159960
 * address:  0x02159960
 * packet:   pkt_02159960
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020362DC(void);

int func_02159960(int a0, int a1)
{

    a0 = func_020362DC();
loc_02159966:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_02159970;
loc_0215996C:
a0 = 1;
    return a0;
loc_02159970:
a0 = 0;
    return a0;}
