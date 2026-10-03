/*
 * function: func_0216D268
 * address:  0x0216D268
 * packet:   pkt_0216D268
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_02163010  0x02163010  thumb  ov010
 *   func_0219D6B8  0x0219D6B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D55C(int a0, int a1);
extern int func_02163010();
extern int func_0219D6B8();

int func_0216D268(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
a1 = 2;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = func_0216D55C(a0, a1);
loc_0216D276:
    if (a0 != 0) goto loc_0216D282;
loc_0216D27A:
a0 = t4 + 0;
    a0 = func_02163010(a0);
loc_0216D280:
    return a0;
loc_0216D282:
a0 = t4 + 0;
    a0 = func_0219D6B8(a0);
loc_0216D288:
    return a0;}
