/*
 * function: func_021AFF7C
 * address:  0x021AFF7C
 * packet:   pkt_ov021_021AFF7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_02184D90  0x02184D90  thumb  ov020
 */

typedef unsigned short u16;
typedef short          s16;

typedef struct { u16 f0; u16 f2; s16 f4; u16 f6; } Q;

extern void *func_0215A5F4(void *p);
extern int func_02158F54();
extern void *func_0201210C(void *p);
extern int func_02011330();
extern int func_02012104();
extern int func_02012374(int a, void *b);
extern int func_02188C5C(void *p);
extern int func_021BB3E8();
extern void *func_02184D90(void *p, void *unused, int a, const Q *q, int s, int t);

int func_021AFF7C(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330(a0);
    c = func_02011330(a0);
    d = func_02011330(a0);
    e = func_02011330(a0);
    f = func_02011330(a0);
    w = func_02012104(h);
    func_021BB3E8(func_02188C5C(a), b, c, d, e, loc, 0x15);
    func_02012374(w, func_02184D90(h, a, b, (const Q *)loc, f, 0));
    return 1;
}
