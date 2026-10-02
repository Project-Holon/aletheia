/*
 * function: func_0215F2B8
 * address:  0x0215F2B8
 * packet:   pkt_0215F2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201214C  0x0201214C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0201214C();

int func_0215F2B8(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F2C4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215F2CE:
    a0 = func_0201214C(v0);
loc_0215F2D6:
*q = a0;
a0 = 0;
    return a0;}
