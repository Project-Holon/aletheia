/*
 * function: func_0216A3F8
 * address:  0x0216A3F8
 * packet:   pkt_0216A3F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_021D096C  0x021D096C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02012F50();
extern int func_021D096C();

int func_0216A3F8(int a0, int a1)
{
    int t4;
    int t5;

a0 = a1 + 0;
    a0 = func_0215A5DC(a0);
loc_0216A400:
t5 = a0 + 0;
    a0 = func_020120F4();
loc_0216A406:
    a0 = func_02012F50();
loc_0216A40A:
t4 = a0 + 0;
a0 = *(int *)((char *)t4);
    if (a0 != 0) goto loc_0216A41A;
loc_0216A412:
a0 = t5 + 0;
    a0 = func_021D096C(a0);
loc_0216A418:
*(int *)((char *)t4) = a0;
loc_0216A41A:
a0 = 0;
    return a0;}
