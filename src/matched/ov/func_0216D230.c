/*
 * function: func_0216D230
 * address:  0x0216D230
 * packet:   pkt_0216D230
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 20 compiled 18
 *
 * symbols:
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E400  0x0216E400  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D5A0();
extern int func_0216E400();

int func_0216D230(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D5A0(a0);
loc_0216D238:
    a0 = func_0216E400(a0);
loc_0216D23C:
t4 = t4 + 0x8c;
*(int *)((char *)t4) = a0;
    return a0;}
