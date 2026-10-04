/*
 * function: func_021637B0
 * address:  0x021637B0
 * packet:   pkt_021637B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AB2F8  0x021AB2F8  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_021C484C  0x021C484C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB2F8();
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u32 func_0216D8AC(void *p);
extern int func_021C484C();

int func_021637B0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(u16 *)((char *)t4 + 0xa);
    a0 = func_021AB2F8(a0);
loc_021637BC:
    if (a0 != 1) goto loc_021637E2;
loc_021637C0:
a0 = t5 + 0;
    a0 = func_0216D83C((void *)a0);
loc_021637C6:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D86C((void *)a0);
loc_021637CE:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D8AC((void *)a0);
loc_021637D6:
a3 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x14);
a1 = t6 + 0;
a2 = t7 + 0;
    a0 = func_021C484C(a0, a1, a2, a3);
loc_021637E2:
    return a0;}
