/*
 * function: func_0215A920
 * address:  0x0215A920
 * packet:   pkt_0215A920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021909BC  0x021909BC  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021909BC();
extern int func_02045C04();
extern int func_02045808();

int func_0215A920(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a0 + 0;
a0 = *(int *)((char *)t6 + 0x1c);
    a0 = func_021909BC(a0);
loc_0215A92A:
a0 = *(int *)((char *)t6 + 0x10);
    if (a0 != 1) goto loc_0215A936;
loc_0215A930:
a0 = *(int *)((char *)t6 + 0x14);
    a0 = func_02045C04(a0);
loc_0215A936:
t4 = 0;
t7 = t4 + 0;
loc_0215A93A:
a0 = t4 << 2;
t5 = t6 + a0;
a0 = *(int *)((char *)t5 + 0x20);
    if (a0 == 0) goto loc_0215A94A;
loc_0215A944:
    a0 = func_02045808(a0);
loc_0215A948:
*(int *)((char *)t5 + 0x20) = t7;
loc_0215A94A:
t4 = t4 + 1;
    if (t4 < 0x20) goto loc_0215A93A;
loc_0215A950:
    return a0;}
