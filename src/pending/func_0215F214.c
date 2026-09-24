/*
 * function: func_0215F214
 * address:  0x0215F214
 * packet:   pkt_0215F214
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 20 compiled 18
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0202EB44  0x0202EB44  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_0202EB44();

int func_0215F214(int a0)
{
    int t4;

    a0 = func_02159AE8();
loc_0215F21A:
t4 = a0 + 0;
    a0 = func_0202EB44();
loc_0215F220:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
