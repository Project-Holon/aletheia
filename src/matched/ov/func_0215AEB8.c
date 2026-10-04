/*
 * function: func_0215AEB8
 * address:  0x0215AEB8
 * packet:   pkt_0215AEB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159F54  0x02159F54  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159F54(int a, int b);

int func_0215AEB8(int a0, int a1)
{
    int t4;
    int t5;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AEC4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215AECE:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AED8:
a1 = t7 + 0;
    a0 = func_02159F54((int)v0, a1);
loc_0215AEE2:
*q = a0;
a0 = 0;
    return a0;}
