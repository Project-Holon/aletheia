/*
 * function: func_0215E804
 * address:  0x0215E804
 * packet:   pkt_0215E804
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200D488  0x0200D488  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0200D488();
extern int func_0200D4AC();
extern int func_0200D4B8();

int func_0215E804(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
loc_0215E80C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D488(a0, a1);
loc_0215E814:
    if (a0 == 0) goto loc_0215E830;
loc_0215E818:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D4AC(a0, a1);
loc_0215E820:
a1 = 4;
t7 = a0 + 0;
    a0 = func_0200D4B8(a0, a1);
loc_0215E828:
    if (t6 != a0) goto loc_0215E830;
loc_0215E82C:
a0 = t7 + 0;
    return a0;
loc_0215E830:
a0 = t4 + 1;
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
    if ((unsigned)t4 < (unsigned)2) goto loc_0215E80C;
loc_0215E83A:
a0 = 0;
    return a0;}
