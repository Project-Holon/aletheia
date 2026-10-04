/*
 * function: func_0215AB60
 * address:  0x0215AB60
 * packet:   pkt_0215AB60
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
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);

int func_0215AB60(int a0, int a1)
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
loc_0215AB6C:
a0 = t4 + 0;
a1 = t7 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB76:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB80:
    a0 = func_021690D0((int)v0);
loc_0215AB88:
*q = a0;
    a0 = func_021690E0((int)v0);
loc_0215AB90:
*dst = a0;
a0 = 0;
    return a0;}
