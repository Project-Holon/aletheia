/*
 * function: func_021B6F88
 * address:  0x021B6F88
 * packet:   pkt_ov021_021B6F88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_021B6EE0  0x021B6EE0  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EED4  0x0201EED4  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern void *func_0215A5E4(void *a0);
typedef unsigned char  u8;
struct WordSet;
extern u8 *func_02012944(void *p);
extern int func_021B6EE0(u32 a, u32 b);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EEC4(struct WordSet *p, u32 i, u32 v);
struct WordSet;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0201EED4(struct WordSet *p, u32 i, void *mon);
extern void func_020307B0(void *p);

int func_021B6F88(int a, int b, int c)
{
    void *m;
    int h;
    int r;

    h = (int)func_02012944(func_0215A5E4((void *)c));
    m = (void *)func_021B6EE0(c, b);
    r = 5;
    func_0201F02C((struct WordSet *)a, 0, (void *)h);
    if (m == 0) {
        func_0201EEC4((struct WordSet *)a, 1, 0);
    } else {
        if (func_02017E1C(m, 0x4c, 0) == 1)
            r = 0xb;
        else
            func_0201EED4((void *)a, 1, m);
        func_020307B0(m);
    }
    return r;
}
