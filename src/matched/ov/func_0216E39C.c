/*
 * function: func_0216E39C
 * address:  0x0216E39C
 * packet:   pkt_0216E39C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D550();
extern int func_0216E2E8();
extern int func_0216D548();

void func_0216E39C(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t6 = a2 + 0;
t5 = a0 + 0;
t4 = a1 + 0;
a0 = t6 + 0;
a1 = 1;
    a0 = func_0216D550(a0, a1);
loc_0216E3AC:
a2 = t6 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
a2 = a2 + 0xe4;
    a0 = func_0216E2E8(a0, a1, a2);
loc_0216E3B8:
a0 = t6 + 0;
a1 = 1;
    a0 = func_0216D548(a0, a1);
loc_0216E3C0:
    return;}
