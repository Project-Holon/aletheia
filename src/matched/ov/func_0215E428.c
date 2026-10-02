/*
 * function: func_0215E428
 * address:  0x0215E428
 * packet:   pkt_0215E428
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215E404  0x0215E404  thumb  ov010
 *   func_0200D45C  0x0200D45C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215E404(int a0);
extern int func_0200D45C();

void func_0215E428(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0215E404(a0);
loc_0215E432:
    if (a0 == 0) goto loc_0215E43E;
loc_0215E436:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D45C(a0, a1);
loc_0215E43E:
    return;}
