/*
 * function: func_0215AFF4
 * address:  0x0215AFF4
 * packet:   pkt_0215AFF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_0215A5E4();
extern int func_0200CA1C();
extern int func_0200CA38();

int func_0215AFF4(int a0, int a1)
{
    int t4;
    int t5;

t5 = a1 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215AFFC:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5E4(a0);
loc_0215B004:
    a0 = func_0200CA1C(a0);
loc_0215B008:
    a0 = func_0200CA38(a0);
loc_0215B00C:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
