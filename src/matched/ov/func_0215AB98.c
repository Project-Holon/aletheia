/*
 * function: func_0215AB98
 * address:  0x0215AB98
 * packet:   pkt_0215AB98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02169100  0x02169100  thumb  ov010
 *   func_02169110  0x02169110  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02169100(int a0);
extern int func_02169110(int a0);

int func_0215AB98(int a0, int a1)
{
    int t4;
    int t7;
    u16 *q;
    u16 *dst;
    void *v0;

t7 = a1 + 0;
t4 = a0 + 0;
a0 = t7 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ABA4:
a0 = t4 + 0;
a1 = t7 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABAE:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABB8:
    a0 = func_02169100((int)v0);
loc_0215ABC0:
*q = a0;
    a0 = func_02169110((int)v0);
loc_0215ABC8:
*dst = a0;
a0 = 0;
    return a0;}
