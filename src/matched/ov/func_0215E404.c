/*
 * function: func_0215E404
 * address:  0x0215E404
 * packet:   pkt_0215E404
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200D488  0x0200D488  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0200D488();

int func_0215E404(int a0)
{
    int a1;
    int t4;
    int t5;

t4 = a0 + 0;
t5 = 0;
loc_0215E40A:
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = func_0200D488(a0, a1);
loc_0215E412:
    if (a0 == 0) goto loc_0215E41A;
loc_0215E416:
a0 = 1;
    return a0;
loc_0215E41A:
a0 = t5 + 1;
a0 = a0 << 0x18;
t5 = (unsigned)a0 >> 0x18;
    if ((unsigned)t5 < (unsigned)2) goto loc_0215E40A;
loc_0215E424:
a0 = 0;
    return a0;}
