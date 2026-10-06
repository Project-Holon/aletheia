/*
 * function: func_0215BAB0
 * address:  0x0215BAB0
 * packet:   pkt_0215BAB0
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
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215B500  0x0215B500  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern int func_0215B500(int a0, int a1);

int func_0215BAB0(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BABA:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BAC4:
t7 = a0 + 0;
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BACE:
a1 = a0 + 0;
a0 = 0;
*q = a0;
a0 = t5 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BADC:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAE0:
    a0 = v0;
a1 = t7 + 0;
    a0 = func_0215B500(a0, a1);
loc_0215BAE8:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAEC:
a0 = 1;
*q = a0;
loc_0215BAF0:
a0 = 0;
    return a0;
}
