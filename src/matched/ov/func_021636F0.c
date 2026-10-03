/*
 * function: func_021636F0
 * address:  0x021636F0
 * packet:   pkt_021636F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021636A8  0x021636A8  thumb  ov010
 *   func_021636C8  0x021636C8  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021636A8(int a0, int a1);
extern int func_021636C8();
extern int func_0216D57C();
extern int func_021AC2C0();
extern int func_0216D568();

void func_021636F0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_021636A8(a0, a1);
loc_021636FA:
    if (a0 != 1) goto loc_02163728;
loc_021636FE:
a0 = t4 + 0;
    a0 = func_021636C8(a0);
loc_02163704:
    if (a0 != 1) goto loc_02163728;
loc_02163708:
t6 = 1;
t6 = t6 << 0xe;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_0216D57C(a0, a1);
loc_02163714:
    if (a0 != 0) goto loc_02163728;
loc_02163718:
a1 = *(int *)((char *)t4 + 0x14);
a0 = t5 + 0;
    a0 = func_021AC2C0(a0, a1);
loc_02163720:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_0216D568(a0, a1);
loc_02163728:
    return;}
