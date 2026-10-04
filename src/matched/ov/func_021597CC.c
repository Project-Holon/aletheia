/*
 * function: func_021597CC
 * address:  0x021597CC
 * packet:   pkt_021597CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *, void *);

int func_021597CC(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021597D6:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021597E0:
a1 = *q;
a0 = a1 - a0;
*q = a0;
a0 = 0;
    return a0;}
