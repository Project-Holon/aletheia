/*
 * function: func_02157938
 * address:  0x02157938
 * packet:   pkt_02157938
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02157938  0x02157938  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203CEAC  0x0203CEAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020307B0();
extern int func_0203CEAC(int a0);

int func_02157938(int a0)
{

    a0 = func_020307B0(a0);
loc_0215793E:
a0 = 0;
    a0 = func_0203CEAC(a0);
loc_02157944:
    return a0;}
