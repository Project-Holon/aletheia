/*
 * function: func_021588DC
 * address:  0x021588DC
 * packet:   pkt_021588DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215882C  0x0215882C  thumb  ov010
 *   func_02158F18  0x02158F18  thumb  ov010
 *   func_021588C0  0x021588C0  thumb  ov010
 *   func_021588B0  0x021588B0  thumb  ov010
 *   func_02158824  0x02158824  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215882C(int a0);
extern int func_02158F18(int a0);
extern int func_021588C0(int a0);
extern int func_021588B0();
extern int func_02158824();

int func_021588DC(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = *(int *)((char *)a2 + 4);
t6 = a0 + 0;
a0 = t5 + 0;
t4 = *(int *)((char *)a2);
    a0 = func_0215882C(a0);
loc_021588EA:
    if (a0 != 1) goto loc_021588F2;
loc_021588EE:
a0 = 0;
    return a0;
loc_021588F2:
a0 = t4 + 0;
    a0 = func_02158F18(a0);
loc_021588F8:
a0 = t5 + 0;
    a0 = func_021588C0(a0);
loc_021588FE:
    if (a0 != 1) goto loc_02158914;
loc_02158902:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_021588B0(a0, a1);
loc_0215890A:
a0 = t5 + 0;
    a0 = func_02158824(a0);
loc_02158910:
a0 = 0;
    return a0;
loc_02158914:
a0 = t5 + 0;
    a0 = func_02158824(a0);
loc_0215891A:
a0 = 1;
    return a0;}
