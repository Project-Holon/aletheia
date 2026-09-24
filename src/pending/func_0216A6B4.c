/*
 * function: func_0216A6B4
 * address:  0x0216A6B4
 * packet:   pkt_0216A6B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 56 compiled 54
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021D0FE0  0x021D0FE0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02012F50();
extern int func_02159AE8();
extern int func_021D0FE0();

int func_0216A6B4(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5F4(a0);
loc_0216A6C0:
a0 = t6 + 0;
    a0 = func_0215A5DC(a0);
loc_0216A6C6:
t7 = a0 + 0;
    a0 = func_020120F4();
loc_0216A6CC:
    a0 = func_02012F50();
loc_0216A6D0:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0216A6DA:
t5 = a0 + 0;
a1 = *(int *)((char *)t4);
a0 = t7 + 0;
    a0 = func_021D0FE0(a0, a1);
loc_0216A6E4:
*(u16 *)((char *)t5) = a0;
a0 = 0;
    return a0;}
