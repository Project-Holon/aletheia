/*
 * function: func_02158F18
 * address:  0x02158F18
 * packet:   pkt_02158F18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_0215A554  0x0215A554  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201ED04();
extern int func_02045808();
extern int func_0215A554();
extern int func_020307B0();

int func_02158F18(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = 0;
*(int *)((char *)t4) = a0;
a0 = *(int *)((char *)t4 + 0x2c);
    if (a0 == 0) goto loc_02158F2A;
loc_02158F26:
    a0 = func_0201ED04();
loc_02158F2A:
a0 = *(int *)((char *)t4 + 0x30);
    if (a0 == 0) goto loc_02158F34;
loc_02158F30:
    a0 = func_02045808();
loc_02158F34:
a0 = *(int *)((char *)t4 + 0x34);
    if (a0 == 0) goto loc_02158F3E;
loc_02158F3A:
    a0 = func_02045808();
loc_02158F3E:
a0 = 0x52;
a0 = a0 << 2;
a0 = *(int *)((char *)t4 + a0);
    a0 = func_0215A554(a0);
loc_02158F48:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02158F4E:
    return a0;}
