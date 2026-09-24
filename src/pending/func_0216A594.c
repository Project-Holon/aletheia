/*
 * function: func_0216A594
 * address:  0x0216A594
 * packet:   pkt_0216A594
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0AB8  0x021D0AB8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02012F50();
extern int func_02159B10();
extern int func_021D0AB8();

int func_0216A594(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5F4(a0);
loc_0216A5A0:
a0 = t6 + 0;
    a0 = func_0215A5DC(a0);
loc_0216A5A6:
    a0 = func_020120F4();
loc_0216A5AA:
    a0 = func_02012F50();
loc_0216A5AE:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_0216A5B8:
a1 = a0 + 0;
a0 = *(int *)((char *)t4);
    a0 = func_021D0AB8(a0, a1);
loc_0216A5C0:
a0 = 0;
    return a0;}
