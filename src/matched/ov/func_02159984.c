/*
 * function: SCRIPT_WORK_WaitKeyAny
 * address:  0x02159984
 * packet:   pkt_02159984
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

int SCRIPT_WORK_WaitKeyAny(int a0, int a1)
{

    a0 = func_020362DC();
loc_0215998A:
a1 = 0xf3;
    if ((a0 & a1) == 0) goto loc_02159994;
loc_02159990:
a0 = 1;
    return a0;
loc_02159994:
a0 = 0;
    return a0;}
