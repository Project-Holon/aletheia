/*
 * function: func_021632F0
 * address:  0x021632F0
 * packet:   pkt_021632F0
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
 *   func_021636F0  0x021636F0  thumb  ov010
 *   func_021637E4  0x021637E4  thumb  ov010
 *   func_0216369C  0x0216369C  thumb  ov010
 *   func_021638C8  0x021638C8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021640B0(int a);
extern u32 func_0216D57C(void *p, u32 v);
extern int func_0216DB24(int a0);
extern int func_021631C0();
extern int func_021636F0();
extern int func_021637E4();
extern int func_0216369C();
extern int func_021638C8();

void func_021632F0(int a0, int a1)
{
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = func_021640B0(a0);
loc_021632FA:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163304:
    if (a0 != 0) goto loc_0216333C;
loc_02163308:
a0 = t5 + 0;
    a0 = func_0216DB24(a0);
loc_0216330E:
    if (a0 != 1) goto loc_0216333C;
loc_02163312:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021631C0(a0, a1);
loc_0216331C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021636F0(a0, a1);
loc_02163324:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021637E4(a0, a1);
loc_0216332C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216369C(a0, a1);
loc_02163334:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_021638C8(a0, a1);
loc_0216333C:
    return;
}
