/*
 * function: func_0216459C
 * address:  0x0216459C
 * packet:   pkt_0216459C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_021C5C64  0x021C5C64  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012AC8();
extern int func_02013E04();
extern int func_021C5C64();

int func_0216459C(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
a0 = a2 + 0;
t4 = a1 + 0;
    a0 = func_02012AC8(a0);
loc_021645A8:
    a0 = func_02013E04();
loc_021645AC:
    if (a0 != 0) goto loc_021645B4;
loc_021645B0:
a0 = 0;
    return a0;
loc_021645B4:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = 0;
    a0 = func_021C5C64(a0, a1, a2);
loc_021645BE:
    return a0;}
