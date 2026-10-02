/*
 * function: func_0215B824
 * address:  0x0215B824
 * packet:   pkt_0215B824
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4DC  0x0215B4DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159B10();
extern int func_0215B4DC();

int func_0215B824(int a0, int a1, int a2)
{
    int t5;
    int t6;
    u16 *q;

t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B82E:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215B838:
a1 = a0 + 0;
a0 = t5 + 0;
a2 = 0x6f;
    a0 = func_0215B4DC(a0, a1, a2);
loc_0215B842:
*q = a0;
a0 = 0;
    return a0;}
