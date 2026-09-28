/*
 * function: func_0215D14C
 * address:  0x0215D14C
 * packet:   pkt_ov010_0215D14C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C34F8  0x021C34F8  thumb
 *   func_0215D198  0x0215D198  thumb  ov010
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_0215A5DC(void *);
extern void *func_0201210C(void *);
extern void *func_02188D50(void *);
extern u16 *func_02159AE8(void *, void *);
extern int func_02159B10(void *, void *);
extern void *func_021C34F8(void *, int);
extern int func_0215D198(void *);

int func_0215D14C(void *a, void *b)
{
    int f;
    u16 *p;
    void *r;
    void *s = func_02188D50(func_0201210C(func_0215A5DC(b)));
    p = func_02159AE8(a, b);
    f = func_02159B10(a, b);
    r = func_021C34F8(s, func_02159B10(a, b));
    if (f == 0)
        *p = func_0215D198(r);
    else
        *p = 0;
    return 0;
}
