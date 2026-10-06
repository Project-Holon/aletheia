/*
 * function: func_0215BFD4
 * address:  0x0215BFD4
 * packet:   pkt_0215BFD4
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
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0216F948  0x0216F948  thumb  ov010
 *   func_0216FAA0  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 func_0215A5CC(void *a0);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u16 *func_0216F948(void *mon, u32 heap);
extern int func_0216FAA0(u16 *p);
extern int func_020307B0();

int func_0215BFD4(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    void *buf;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BFDE:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BFE8:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5CC((void *)a0);
loc_0215BFF0:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BFFC:
    if (a0 != 1) goto loc_0215C016;
loc_0215C000:
    a0 = v0;
a1 = t7 + 0;
    buf = func_0216F948((void *)a0, a1);
loc_0215C008:
    a0 = func_0216FAA0(buf);
loc_0215C00E:
*q = a0;
    a0 = func_020307B0(buf);
loc_0215C016:
a0 = 0;
    return a0;
}
