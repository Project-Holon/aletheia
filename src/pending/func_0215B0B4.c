/*
 * function: func_0215B0B4
 * address:  0x0215B0B4
 * packet:   pkt_0215B0B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_0215A5E4();
extern int func_020127A4();
extern int func_02012EBC();
extern int func_020089C0();
extern int func_02008554();
extern int func_02025C88();
extern int func_020089F4();
extern int func_02008A00();

int func_0215B0B4(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02159AE8();
loc_0215B0BE:
t5 = a0 + 0;
a0 = t6 + 0;
a1 = t4 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215B0C8:
t7 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_0215B0D0:
t6 = a0 + 0;
    a0 = func_020127A4();
loc_0215B0D6:
t4 = a0 + 0;
a0 = t6 + 0;
    a0 = func_02012EBC(a0);
loc_0215B0DE:
    a0 = func_020089C0();
loc_0215B0E2:
t4 = t4 + 0x20;
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02008554(a0);
loc_0215B0EC:
    a0 = func_02025C88();
loc_0215B0F0:
*(u16 *)((char *)t7) = a0;
a0 = t6 + 0;
    a0 = func_020089F4(a0);
loc_0215B0F8:
*(u16 *)((char *)t5) = a0;
a0 = t6 + 0;
    a0 = func_02008A00(a0);
loc_0215B100:
a0 = 0;
    return a0;}
