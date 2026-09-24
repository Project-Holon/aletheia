/*
 * function: func_0215F9EC
 * address:  0x0215F9EC
 * packet:   pkt_0215F9EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C3B8  0x0200C3B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012F08();
extern int func_0200C3B8();

int func_0215F9EC(int a0, int a1)
{

a0 = *(int *)((char *)a0 + 4);
    a0 = func_02012F08(a0);
loc_0215F9F4:
a1 = 0x5a;
a1 = a1 << 4;
    a0 = func_0200C3B8(a0, a1);
loc_0215F9FC:
    return a0;}
