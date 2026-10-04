/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov060_021F36C0
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_021F3938  0x021F3938  thumb  ov060
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_021F37E4  0x021F37E4  thumb  ov060
 *   func_021F3950  0x021F3950  thumb  ov060
 *   d_021F3A34     0x021F3A34  data  a4
 */

typedef unsigned int u32;

extern char d_021F3A34[];

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void *func_02188D2C(void *p);
extern u32 func_02188C80(void *p);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
struct Ctx;
extern u32 func_02012138(const struct Ctx *a);
extern void *func_021F3938(u32 a);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE310(void *a, void *b, int c);
extern void func_021F37E4(u8 *out, void *b, void *c, void *d);
extern void func_021F3950(void *a, void *b);

void func_021F36C0(void *a)
{
    u32 r6;
    void *s;
    u32 c;
    u32 h;
    void *v;
    void *o;

    r6 = func_02188C84(a);
    s = func_02188D2C(a);
    c = func_02188C80(a);
    h = func_020120F4(c);
    func_02012EC4(h);
    v = func_021F3938(func_02012138((const struct Ctx *)c));
    o = func_02189764(a, 0, r6, 4);
    func_021BE310(s, d_021F3A34, 0);
    func_021F37E4(o, a, (void *)h, v);
    func_021F3950(o, s);
}
