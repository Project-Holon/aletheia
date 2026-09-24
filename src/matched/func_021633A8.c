/*
 * function: func_021633A8
 * address:  0x021633A8
 * packet:   pkt_021633A8
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
 *   func_02163418  0x02163418  thumb  ov010
 *   func_021637B0  0x021637B0  thumb  ov010
 *   func_02163650  0x02163650  thumb  ov010
 *   func_02163868  0x02163868  thumb  ov010
 *   func_0216372C  0x0216372C  thumb  ov010
 *   func_0216355C  0x0216355C  thumb  ov010
 *   func_0216375C  0x0216375C  thumb  ov010
 *   func_021638AC  0x021638AC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021640B0();
extern int func_0216D57C();
extern int func_0216DB24();
extern int func_021631C0();
extern int func_02163418();
extern int func_021637B0();
extern int func_02163650();
extern int func_02163868();
extern int func_0216372C();
extern int func_0216355C();
extern int func_0216375C();
extern int func_021638AC();

void func_021633A8(int a0, int a1)
{
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0();
loc_021633B2:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C(a0, a1);
loc_021633BC:
    if (a0 != 0) goto loc_02163414;
loc_021633C0:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_021633C6:
    if (a0 != 1) goto loc_02163414;
loc_021633CA:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_021633D4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163418(a0, a1);
loc_021633DC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637B0(a0, a1);
loc_021633E4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163650(a0, a1);
loc_021633EC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02163868(a0, a1);
loc_021633F4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216372C(a0, a1);
loc_021633FC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216355C(a0, a1);
loc_02163404:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216375C(a0, a1);
loc_0216340C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638AC(a0, a1);
loc_02163414:
    return;
}
