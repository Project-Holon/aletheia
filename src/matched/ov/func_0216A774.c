/*
 * function: func_0216A774
 * address:  0x0216A774
 * packet:   pkt_0216A774
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021D1028  0x021D1028  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021D1028();

int func_0216A774(int a0, int a1)
{
    int t4;
    int t5;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A780:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A786:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A790:
    a0 = func_021D1028(v1);
loc_0216A798:
*q = a0;
a0 = 0;
    return a0;}
