/*
 * function: func_021665F0
 * address:  0x021665F0
 * packet:   pkt_021665F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216649C  0x0216649C  thumb  ov010
 *   func_021663F4  0x021663F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0216649C();
extern int func_021663F4(u8 *list, int def, unsigned dir);

int func_021665F0(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *p;

t5 = a1 + 0;
t4 = a2 + 0;
    p = func_0216649C(a0);
loc_021665FA:
    if (p == 0) goto loc_02166614;
loc_021665FE:
a1 = t5 + 1;
a1 = a1 << 0x18;
a2 = t4 << 0x18;
a1 = (unsigned)a1 >> 0x18;
a2 = (unsigned)a2 >> 0x18;
    a0 = func_021663F4(p, a1, a2);
loc_0216660C:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
a0 = a0 - 1;
    return a0;
loc_02166614:
a0 = 4;
    return a0;}
