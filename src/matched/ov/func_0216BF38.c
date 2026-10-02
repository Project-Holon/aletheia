/*
 * function: func_0216BF38
 * address:  0x0216BF38
 * packet:   pkt_0216BF38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 60 compiled 58
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_0200D418();
extern int func_02159B10();
extern int func_02159AE8();
extern int func_0200D468();

int func_0216BF38(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5E4(a0);
loc_0216BF44:
    a0 = func_02012EBC(a0);
loc_0216BF48:
    a0 = func_0200D418(a0);
loc_0216BF4C:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_0216BF56:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0216BF62:
t5 = a0 + 0;
a0 = t7 + 0;
a1 = t4 + 0;
    a0 = func_0200D468(a0, a1);
loc_0216BF6C:
*(u16 *)((char *)t5) = a0;
a0 = 0;
    return a0;}
