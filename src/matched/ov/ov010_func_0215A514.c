/*
 * function: func_0215A514
 * address:  0x0215A514
 * packet:   pkt_ov010_0215A514
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   d_021728E0     0x021728E0  data  ov010  a4
 */

extern void *func_02030734(int, int, int, void *, int);
extern int func_02158F54(int);
extern int func_020120F4(void);
extern int func_02012964(void);
extern int d_021728E0;

void *func_0215A514(int a, int heap)
{
    int *p = (int *)func_02030734(heap, 0x110, 1, &d_021728E0, 0x78);

    p[0] = a;
    p[1] = func_02158F54(a);
    p[2] = func_020120F4();
    p[3] = func_02012964();
    *((char *)p + 0x104) = 7;
    return p;
}
