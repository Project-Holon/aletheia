/*
 * function: func_021B7794
 * address:  0x021B7794
 * packet:   pkt_ov021_021B7794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_021B7640  0x021B7640  thumb
 *   func_021B7574  0x021B7574  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct Rec { unsigned short *f0; char pad04[4]; void *f8; char fC[4]; u16 f10; };

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Work;
extern void *func_020120F4(const struct Ctx *p);
struct Big;
struct Sub02009448Obj;
struct Obj;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
struct Pair;
extern u16 func_02188C84(u8 *p);
extern struct Pair *func_021B7640(u32 a, u32 b, u32 c, int *d);
extern int func_021B7574(void *task, int *st, struct Work *w);

void *func_021B7794(void *p)
{
    void *a;
    void *b;
    void *res;
    struct Rec *r;

    a = func_020120F4(p);
    b = func_02009448(func_02012EBC(a));
    res = func_020122C0(p, 0, (void *)func_021B7574, 0x14);
    r = func_020124E8(res);
    r->f0 = func_0201210C(p);
    r->f10 = 0;
    r->f8 = func_021B7640((u32)a, func_02188C84((u8 *)r->f0), (u32)b, (int *)r->fC);
    return res;
}
