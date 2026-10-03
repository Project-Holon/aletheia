/*
 * function: func_021665D0
 * address:  0x021665D0
 * packet:   pkt_021665D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216649C  0x0216649C  thumb  ov010
 *   func_02166324  0x02166324  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0216649C();
extern int func_02166324(u8 *grid, int id);

int func_021665D0(int a0, int a1)
{
    int t4;
    void *p;

t4 = a1 + 0;
    p = func_0216649C(a0);
loc_021665D8:
    if (p == 0) goto loc_021665E8;
loc_021665DC:
a1 = t4 + 1;
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = func_02166324(p, a1);
loc_021665E6:
    return a0;
loc_021665E8:
a0 = 0x46;
a0 = a0 << 2;
    return a0;}
