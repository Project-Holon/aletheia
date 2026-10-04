/*
 * function: func_021B6628
 * address:  0x021B6628
 * packet:   pkt_ov021_021B6628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The else arm zero is an array initialiser: `u16 s[1] = {0}` keeps &s in r6
 * for the call argument while the result store gets a fresh add sp.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_0215A5DC  0x0215A5DC  thumb ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012FD8  0x02012FD8  thumb
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02158F7C  0x02158F7C  thumb ov010
 *   func_02158F74  0x02158F74  thumb ov010
 *   func_0200E740  0x0200E740  thumb
 *   func_0200E7AC  0x0200E7AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
struct Strbuf;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012FD8(void **p);
extern u32 func_02159B10(void *, void *);
extern u32 func_02158F7C(u8 *p);
extern void *func_02158F74(void *);
extern u32 func_0200E740(const void *obj, u32 idx);
extern void *func_0200E7AC(void *obj, u32 idx);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(void *, u32, void *, int, int, int);

int func_021B6628(void *a, void *b)
{
    void *t;
    void *w;
    u32 i;
    u32 j;
    void *x;
    void *y;

    t = func_0215A5F4(b);
    w = func_02012FD8(func_020120F4(func_0215A5DC(b)));
    i = func_02159B10(a, b);
    j = func_02159B10(a, b);
    x = (void *)func_02158F7C(t);
    y = func_02158F74(t);
    if (func_0200E740(w, i)) {
        func_02045924(x, func_0200E7AC(w, i));
    } else {
        u16 s[1] = {0};
        s[0] = func_02045A98();
        func_02045924(x, s);
    }
    func_0201EE0C(y, j, x, 0, 1, 2);
    return 0;
}
