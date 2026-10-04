/*
 * function: func_021F374C
 * address:  0x021F374C
 * packet:   pkt_ov060_021F374C
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_021F3938  0x021F3938  thumb  ov060
 *   func_021F3850  0x021F3850  thumb  ov060
 *   func_021F3880  0x021F3880  thumb  ov060
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021F39F4  0x021F39F4  thumb  ov060
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u16 lo : 3;
} Bf;

struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int func_02188D2C(int *p);
extern u8 *func_021897BC(void *p, int i);
struct Ctx;
extern u32 func_02012138(const struct Ctx *a);
extern void *func_021F3938(void *p);
extern void func_021F3850(u32 p);
extern u8 func_021F3880(void *a, void *b, void *unused);
extern void func_021BE580(void *p);
extern void func_021F39F4(u8 *a, void *b);

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
    q = func_021897BC(o, 0);
    v = func_021F3938((void *)func_02012138((const struct Ctx *)c));
    if (v != 0) {
        if (((Bf *)((u8 *)v + 0x86))->lo != *q) {
            func_021F3850((u32)s);
            *q = func_021F3880((void *)h, s, v);
        }
    }
    func_021BE580(s);
    if (q[1] != 0) {
        func_021F39F4(q, s);
    }
}
