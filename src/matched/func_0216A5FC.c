/*
 * function: func_0216A5FC
 * address:  0x0216A5FC
 * packet:   pkt_0216A5FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008E78  0x02008E78  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02159AE8();
extern int func_02012EBC();
extern int func_02008C58();
extern int func_02008E78();

int func_0216A5FC(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0216A608:
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0216A60E:
    a0 = func_020120F4();
loc_0216A612:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0216A61C:
t4 = a0 + 0;
a0 = t6 + 0;
    a0 = func_02012EBC(a0);
loc_0216A624:
    a0 = func_02008C58();
loc_0216A628:
    a0 = func_02008E78();
loc_0216A62C:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
