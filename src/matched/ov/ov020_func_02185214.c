/*
 * function: func_02185214
 * address:  0x02185214
 * packet:   pkt_ov020_02185214
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Lever: func_0202648C reads its pointer argument in the matched ARM9
 * unit_02026454.c. The original forwards func_02012138(a) in r0 with
 * no intervening argument setup. Explicitly passing h restores the
 * return-value spill and all frame/register choices (DIFF22 -> EXACT).
 * Runs this retry: 2; the prior consumed permuter was not repeated.
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020128DC  0x020128DC  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026484  0x02026484  thumb
 *   func_02012B78  0x02012B78  thumb
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02185C4C  0x02185C4C  thumb  ov020
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_02158344  0x02158344  thumb  ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { int f00; u16 f04, f06; int f08[5]; } Rec;
struct Big;
struct BigObj;
struct Ctx;
void *func_020120F4(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
Rec *func_020128DC(void *p);
int func_02013DD0(int v);
void func_02014204(Rec *r, int v);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *p);
void *func_02012FCC(void *p);
u64 func_0200BFA4(u8 *p, void *x, u32 n);
u32 func_02012138(const struct Ctx *p);
u32 func_0202648C(void *p);
u32 func_02026454(void *obj);
void func_02026484(void *p);
void func_02012B78(struct BigObj *p, u8 v);
void func_02012B64(struct BigObj *p, u8 v);
void func_02012B8C(struct BigObj *p, u8 v);
void func_02012B4C(struct BigObj *p, u8 v);
void *func_02185C4C(void *p, void *a1, Rec *r);
void *func_02188CB4(u8 *p);
int func_021A3238(void *v);
void func_0217BCDC(u8 *a, void *b, int c, u8 d, u8 e);
int func_02158344(int a0);
static inline void create_result(void *a, void *r6, Rec *s, void **out)
{
    *out = func_02185C4C(a, r6, s);
}
static inline void *finish(void *a, void *r4, void *r6, void *ret)
{
    u16 *t;
    void *h;
    t = func_0200BE48(func_02012EBC(r4));
    func_0200BFA4((u8 *)t, func_02012FCC(r4), 1);
    h = (void *)func_02012138(a);
    func_0202648C(h);
    if (func_02026454(h) == 0)
        func_02026484(h);
    if (func_021A3238(func_02188CB4(r6)) == 0)
        func_0217BCDC(0, a, 0, 0, 0);
    func_02012B78(r4, 0);
    if (func_02158344(func_02012138(a)) == 0) {
        func_02012B64(r4, 0);
        func_02012B8C(r4, 0);
        func_02012B4C(r4, 1);
    }
    return ret;
}
void *func_02185214(void *a)
{
    void *r4;
    void *r6;
    Rec s;
    void *ret;
    r4 = func_020120F4(a);
    r6 = func_0201210C(a);
    s = *func_020128DC(r4);
    if (func_02013DD0(s.f04) == 1)
        func_02014204(&s, s.f04);
    create_result(a, r6, &s, &ret);
    return finish(a, r4, r6, ret);
}
