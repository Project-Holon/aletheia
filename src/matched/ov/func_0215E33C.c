/*
 * function: func_0215E33C
 * address:  0x0215E33C
 * packet:   pkt_0215E33C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CE8  0x02188CE8  thumb
 *   func_021AA7DC  0x021AA7DC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02188CE8();
extern int func_021AA7DC();

int func_0215E33C(int a0, int a1)
{

    a0 = func_02188CE8(a0);
loc_0215E342:
a1 = *(int *)((char *)a0 + 0x10);
    a0 = func_021AA7DC(a0, a1);
loc_0215E348:
    return a0;}
