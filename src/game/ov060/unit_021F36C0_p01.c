/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F3724, func_021F374C
 * address:  0x021F36C0
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021F3850  0x021F3850  thumb  ov060
 *   func_021F3880  0x021F3880  thumb  ov060
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021F39F4  0x021F39F4  thumb  ov060
 */
struct Big;
struct Ctx;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct {
    u16 lo : 3;
} Bf;

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u32 func_02012138(const struct Ctx *a);
extern void *func_021F3938(void *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE310(void *a, void *b, int c);
extern void func_021F37E4(u8 *out, void *b, void *c, void *d);
extern void func_021F3950(void *a, void *b);
extern void func_021BE418(unsigned char *p, unsigned short i);
extern void func_021897A0(unsigned char *p, int id);
extern int *func_021897BC(char *p, int idx);
extern void func_021F3850(char *p);
extern u8 func_021F3880(void *a, void *b, void *unused);
extern void func_021BE580(void *p);
extern void func_021F39F4(u8 *a, void *b);
void func_021F36C0(void *a);
void func_021F3724(unsigned char *p);
void func_021F374C(void *o);
extern char d_021F3A34[];


void func_021F36C0(void *a)
{
    u32 r6;
    void *s;
    u32 c;
    u32 h;
    void *v;
    void *o;

    r6 = func_02188C84(a);
    s = (void *)func_02188D2C(a);
    c = (u32)func_02188C80(a);
    h = (u32)func_020120F4((const struct Ctx *)c);
    func_02012EC4((struct Big *)h);
    v = func_021F3938((void *)func_02012138((const struct Ctx *)c));
    o = func_02189764(a, 0, r6, 4);
    func_021BE310(s, d_021F3A34, 0);
    func_021F37E4(o, a, (void *)h, v);
    func_021F3950(o, s);
}


void func_021F3724(unsigned char *p)
{
    func_02012EC4(func_020120F4(func_02188C80(p)));
    func_021BE418((unsigned char *)func_02188D2C((int *)p), 0);
    func_021897A0(p, 0);
}


void func_021F374C(void *o)
{
    u32 c;
    u32 h;
    void *s;
    u8 *q;
    void *v;

    c = (u32)func_02188C80(o);
    h = (u32)func_020120F4((const struct Ctx *)c);
    func_02012EC4((struct Big *)h);
    s = (void *)func_02188D2C(o);
    q = (u8 *)func_021897BC(o, 0);
    v = func_021F3938((void *)func_02012138((const struct Ctx *)c));
    if (v != 0) {
        if (((Bf *)((u8 *)v + 0x86))->lo != *q) {
            func_021F3850((char *)s);
            *q = func_021F3880((void *)h, s, v);
        }
    }
    func_021BE580(s);
    if (q[1] != 0) {
        func_021F39F4(q, s);
    }
}
