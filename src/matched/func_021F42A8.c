/*
 * function: func_021F42A8
 * address:  0x021F42A8
 * packet:   pkt_021F42A8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb
 *   func_021897BC  0x021897BC  thumb
 *   func_02188C58  0x02188C58  thumb
 *   func_0218EC5C  0x0218EC5C  thumb
 *   func_0218EC54  0x0218EC54  thumb
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_021A3044  0x021A3044  thumb
 */

typedef unsigned char u8;

extern void *func_0201210C(void);
extern void *func_02188D2C(void);
extern void *func_021897BC(void *a, int b);
extern void *func_02188C58(void *a);
extern int   func_0218EC5C(void);
extern void  func_0218EC54(void *a);
extern void *func_021BE480(void *a, int b, int c);
extern void *func_02188CB4(void *a);
extern void  func_021A3038(void *a, void *b);
extern void  func_021A3044(void *a, void *b);

void func_021F42A8(void)
{
    void *a, *b, *c, *d, *e, *f;
    int tmp[3];

    a = func_0201210C();
    b = func_02188D2C();
    c = func_021897BC(a, 1);
    d = func_02188C58(a);
    *(int *)((u8 *)c + 0x10) = func_0218EC5C();
    func_0218EC54(d);
    e = func_021BE480(b, 0, 7);
    *(int *)((u8 *)e + 4) = 0x370000;
    f = func_02188CB4(a);
    func_021A3038(f, tmp);
    tmp[1] = 0x370000;
    func_021A3044(f, tmp);
}
