/*
 * function: func_0216B60C
 * address:  0x0216B60C
 * packet:   pkt_0216B60C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 48 compiled 46
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216BB18  0x0216BB18  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_02159AE8();
extern int func_0216BB18();

int func_0216B60C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0216B618:
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_0216B61E:
    a0 = func_02012EBC(a0);
loc_0216B622:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0216B62C:
t4 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0216BB18(a0);
loc_0216B634:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
