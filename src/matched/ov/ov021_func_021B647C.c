/*
 * function: func_021B647C
 * address:  0x021B647C
 * packet:   pkt_ov021_021B647C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021CBFB0  0x021CBFB0  thumb  ov021
 *   func_021CC040  0x021CC040  thumb  ov021
 *   func_021CC060  0x021CC060  thumb  ov021
 *   func_021CC068  0x021CC068  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02159B10(void *, void *);
struct BigObj;
struct Ctx;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u16 func_02188C84(u8 *p);
extern struct Obj *func_021CBFB0(u32 a, u32 b);
extern void func_021CC040(struct Obj *o);
extern u32 func_021CC060(u8 *p);
extern u32 func_021CC068(u8 *p);

int func_021B647C(void *a, void *b)
{
    void *sys;
    void *w;
    u32 heap;
    u16 *out;
    u32 i2;
    u32 idx;
    void *mon;
    void *obj;
    u32 v;

    func_0215A5F4(b);
    sys = func_0215A5DC(b);
    w = func_020120F4(sys);
    heap = func_02188C84(func_0201210C(sys));
    out = func_02159AE8(a, b);
    i2 = func_02159B10(a, b);
    idx = func_02159B10(a, b);
    mon = func_0201AB28(func_02012934(w), idx);
    obj = func_021CBFB0(heap, i2);
    *out = 0;
    if (*out == 0 && func_02017E1C(mon, 0x4c, 0) == 1) {
        *out = 1;
    }
    if (*out == 0) {
        v = func_02017E1C(mon, 5, 0);
        if (v != func_021CC060(obj)) {
            *out = 2;
        }
    }
    if (*out == 0 && func_021CC068(obj) != 2) {
        v = func_02017E1C(mon, 0x6e, 0);
        if (v != func_021CC068(obj)) {
            *out = 3;
        }
    }
    func_021CC040(obj);
    return 0;
}
