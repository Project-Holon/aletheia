/*
 * function: func_0215AB18
 * address:  0x0215AB18
 * packet:   pkt_0215AB18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021690B4  0x021690B4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021690B4();

int func_0215AB18(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB24:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB2E:
    a0 = func_021690B4(v0);
loc_0215AB36:
*q = a0;
a0 = 0;
    return a0;}
