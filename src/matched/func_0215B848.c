/*
 * function: func_0215B848
 * address:  0x0215B848
 * packet:   pkt_0215B848
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB18  0x0201AB18  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_02159B10();
extern int func_0215A5E4();
extern int func_02012934();
extern int func_0201AB08();
extern int func_0201AB18();

int func_0215B848(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a0 + 0;
t5 = a1 + 0;
    a0 = func_02159AE8();
loc_0215B852:
t6 = a0 + 0;
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215B85C:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5E4(a0);
loc_0215B864:
    a0 = func_02012934();
loc_0215B868:
    if (t4 == 1) goto loc_0215B87A;
loc_0215B86C:
    if (t4 != 2) goto loc_0215B880;
loc_0215B870:
    a0 = func_0201AB08();
loc_0215B874:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    goto loc_0215B882;
loc_0215B87A:
    a0 = func_0201AB18();
loc_0215B87E:
    goto loc_0215B874;
loc_0215B880:
a0 = 0;
loc_0215B882:
*(u16 *)((char *)t6) = a0;
a0 = 0;
    return a0;}
