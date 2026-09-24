/*
 * function: func_0215AA90
 * address:  0x0215AA90
 * packet:   pkt_0215AA90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020083E4  0x020083E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_0200873C();
extern int func_02159AE8();
extern int func_020083E4();

int func_0215AA90(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5E4(a0);
loc_0215AA9C:
    a0 = func_02012EBC();
loc_0215AAA0:
    a0 = func_0200873C();
loc_0215AAA4:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215AAAE:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_020083E4(a0);
loc_0215AAB6:
*(u16 *)((char *)t5) = a0;
a0 = 0;
    return a0;}
