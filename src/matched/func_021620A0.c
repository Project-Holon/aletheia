/*
 * function: func_021620A0
 * address:  0x021620A0
 * packet:   pkt_021620A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02162358  0x02162358  thumb  ov010
 *   func_021622F4  0x021622F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02162358();
extern int func_021622F4();

int func_021620A0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02162358(a0);
loc_021620A8:
a0 = t4 + 0;
    a0 = func_021622F4(a0);
loc_021620AE:
    return a0;}
