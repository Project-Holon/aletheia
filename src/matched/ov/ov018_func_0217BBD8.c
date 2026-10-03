/*
 * function: func_0217BBD8
 * address:  0x0217BBD8
 * packet:   pkt_ov018_0217BBD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0217B94C  0x0217B94C  thumb  ov018
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159BBC  0x02159BBC  thumb
 *   func_0218CD20  0x0218CD20  thumb  ov021
 */

typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;

extern int func_02188C98(int);
extern int func_02188C9C(int);
extern void *func_02188CB4(unsigned char *p);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern void func_021A3038(void *, Vec *);
extern int func_0217B94C(Vec *);
extern int func_02159B48(int);
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern void func_02159BBC(int);
extern void func_0218CD20(int, int, int);

void func_0217BBD8(int a, int b, u8 *c)
{
    Vec v;
    int n;
    void *h;
    int buf;

    if (c == 0 || a == 0)
        return;
    if (func_02188C98(a) == 0)
        return;
    if (func_02013D5C(func_02188C9C(a)) == 0)
        return;
    n = c[0x902] - 1;
    if (n <= 0)
        n = 1;
    if (((unsigned)(c[0x8f8] << 26) >> 31) == 1)
        n = 1;
    if (c[0x901] >= n)
        return;
    h = func_02188CB4((void *)a);
    if (h == 0)
        return;
    func_021A3038(h, &v);
    v.x = v.x % 0x400000;
    if (func_0217B94C(&v) == 1)
        return;
    buf = func_02159B48(0x8015);
    func_02159B94(buf, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        func_0218CD20(a, func_02188C98(a), buf);
        c[0x901]++;
    } while (c[0x901] < n);
    func_02159BBC(buf);
}
