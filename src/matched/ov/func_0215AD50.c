/*
 * function: func_0215AD50
 * address:  0x0215AD50
 * packet:   pkt_0215AD50
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
 *   func_02159F84  0x02159F84  thumb  ov010
 *   func_02012900  0x02012900  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern int func_02159B10();
extern int func_02159F84();
extern int func_02012900();

int func_0215AD50(int a0, int a1)
{    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AD5C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215AD66:
t5 = a0 + 0;
    a0 = func_02159F84(a0);
loc_0215AD6C:
    if (a0 != 1) goto loc_0215AD78;
loc_0215AD70:
a1 = t5 + 0;
    a0 = func_02012900(v0, a1);
loc_0215AD78:
a0 = 0;
    return a0;}
