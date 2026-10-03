/*
 * function: func_0216932C
 * address:  0x0216932C
 * packet:   pkt_0216932C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02169308  0x02169308  thumb  ov010
 *   func_02169520  0x02169520  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02169308();
extern int func_02169520(int a0, int a1);

int func_0216932C(int a0, int a1)
{
    int v0;
    int t4;
    int t5;
t5 = a0 + 0;
a0 = 1;
*(u16 *)((char *)t5 + 2) = a0;
t4 = (int)&v0;
loc_02169336:
a0 = t5 + 0;
    a0 = func_02169308(a0);
loc_0216933C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02169520(a0, a1);
loc_02169344:
    a0 = v0;
a0 = *(u16 *)((char *)a0);
    if (a0 != 0) goto loc_02169336;
loc_0216934C:
a0 = 0;
*(u16 *)((char *)t5 + 2) = a0;
    return a0;
}
