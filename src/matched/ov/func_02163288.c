/*
 * function: func_02163288
 * address:  0x02163288
 * packet:   pkt_02163288
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021640B0  0x021640B0  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_021631C0  0x021631C0  thumb  ov010
 *   func_021634FC  0x021634FC  thumb  ov010
 *   func_02163580  0x02163580  thumb  ov010
 *   func_02163650  0x02163650  thumb  ov010
 *   func_021636F0  0x021636F0  thumb  ov010
 *   func_0216377C  0x0216377C  thumb  ov010
 *   func_021637E4  0x021637E4  thumb  ov010
 *   func_021638C8  0x021638C8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021640B0();
extern int func_0216D57C();
extern int func_0216DB24();
extern int func_021631C0();
extern int func_021634FC();
extern int func_02163580();
extern int func_02163650();
extern int func_021636F0();
extern int func_0216377C();
extern int func_021637E4();
extern int func_021638C8();

void func_02163288(int a0, int a1)
{
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_02163292:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C(a0, a1);
loc_0216329C:
    if (a0 != 0) goto loc_021632EC;
loc_021632A0:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_021632A6:
    if (a0 != 1) goto loc_021632EC;
loc_021632AA:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_021632B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021634FC(a0, a1);
loc_021632BC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163580(a0, a1);
loc_021632C4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163650(a0, a1);
loc_021632CC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021636F0(a0, a1);
loc_021632D4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216377C(a0, a1);
loc_021632DC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637E4(a0, a1);
loc_021632E4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638C8(a0, a1);
loc_021632EC:
    return;
}
