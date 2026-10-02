/*
 * function: func_02159570
 * address:  0x02159570
 * packet:   pkt_02159570
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159B38  0x02159B38  thumb  ov010
 *   func_021589A0  0x021589A0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern int func_02011330();
extern int func_02159B38();
extern int func_021589A0();

int func_02159570(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t5 = a1 + 0;
t4 = a0 + 0;
a0 = t5 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215957C:
a0 = t5 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_02159582:
a0 = t4 + 0;
    a0 = func_02011330(a0);
loc_0215958A:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02159B38(a0);
loc_02159592:
a1 = a0 + 0;
a2 = t4 + 0;
    a0 = func_021589A0(v1, a1, a2);
loc_0215959C:
a0 = 1;
    return a0;}
