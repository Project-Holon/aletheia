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

extern u32 func_02188C80(void *p);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern void *func_02188D2C(void *p);
extern u8 *func_021897BC(void *p, int i);
struct Ctx;
extern u32 func_02012138(const struct Ctx *a);
extern void *func_021F3938(u32 a);
extern void func_021F3850(void *p);
extern u8 func_021F3880(u32 a, void *b, void *c);
extern void func_021BE580(void *p);
extern void func_021F39F4(u8 *a, void *b);

void func_021F374C(void *o)
{
    u32 c;
    u32 h;
    void *s;
    u8 *q;
    void *v;

    c = func_02188C80(o);
    h = func_020120F4(c);
    func_02012EC4(h);
    s = func_02188D2C(o);
    q = func_021897BC(o, 0);
    v = func_021F3938(func_02012138((const struct Ctx *)c));
    if (v != 0) {
        if (((Bf *)((u8 *)v + 0x86))->lo != *q) {
            func_021F3850(s);
            *q = func_021F3880(h, s, v);
        }
    }
    func_021BE580(s);
    if (q[1] != 0) {
        func_021F39F4(q, s);
    }
}
