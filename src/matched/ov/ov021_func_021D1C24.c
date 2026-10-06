/*
 * function: func_021D1C24
 * address:  0x021D1C24
 * packet:   pkt_ov021_021D1C24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_021D1C8C  0x021D1C8C  thumb  ov021
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02007AC8Entry;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021D1C8C(void *proc, int *seq, void *w);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02188C54(u8 *p);

u32 func_021D1C24(u32 a, u32 b, u32 c)
{
    u32 r;
    u32 *p;

    r = (u32)func_020122C0((void *)a, 0, func_021D1C8C, 0x58);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x58);
    p[1] = a;
    p[2] = (u32)func_020120F4((const struct Ctx *)a);
    p[0] = (u32)func_02007B44(func_02012EBC((struct Big *)p[2]));
    p[3] = b;
    p[4] = (u32)func_02188CB4((void *)b);
    p[5] = (u32)func_0201AB28(func_02012934((void *)p[2]), c);
    p[7] = func_02188C54((u8 *)p[3]);
    *((u8 *)p + 0x4e) = c;
    p[0x15] = 0;
    return r;
}
