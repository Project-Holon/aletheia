/*
 * function: func_021667E0
 * address: 0x021667E0
 * packet: pkt_ov010_021667E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The returned task remains live as func_0215897C's second argument.
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012ED0 0x02012ED0 thumb
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0216666C 0x0216666C thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 */
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
typedef unsigned short u16;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void **func_02012ED0(void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0216666C(void *, void *, void *);
extern void func_0215897C(void *, void *);

int func_021667E0(void *a, void *b)
{
    void *x = func_0215A5F4(b);
    void *y = func_0215A5DC(b);
    void **p;
    void *r;
    p = func_02012ED0(func_020120F4(y));
    r = func_0216666C(y, *p, func_02159AE8(a, b));
    if (r == 0)
        return 1;
    func_0215897C(x, r);
    return 1;
}
