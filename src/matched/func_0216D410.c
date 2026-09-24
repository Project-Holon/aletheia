/*
 * function: func_0216D410
 * address:  0x0216D410
 * packet:   pkt_0216D410
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D7C0();
extern int func_0216D7C8();
extern int func_0216D568();
extern int func_0216D570();

void func_0216D410(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_0216D7C0();
loc_0216D418:
a0 = t5 + 0;
a1 = 0;
    a0 = func_0216D7C8(a0, a1);
loc_0216D420:
t4 = 2;
t4 = t4 << 8;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216D568(a0, a1);
loc_0216D42C:
a0 = t5 + 0;
a1 = t4 << 1;
    a0 = func_0216D570(a0, a1);
loc_0216D434:
    return;}
