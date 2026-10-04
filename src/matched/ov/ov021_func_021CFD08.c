/*
 * function: func_021CFD08
 * address:  0x021CFD08
 * packet:   pkt_ov021_021CFD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_021CFDBC  0x021CFDBC  thumb  ov021
 *   func_0200973C  0x0200973C  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02009634  0x02009634  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02025B64  0x02025B64  thumb
 *   func_021CFD88  0x021CFD88  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
struct Sub0200852CObj;
struct Sub02009470Ent;
struct Sub02009470Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_021CFDBC(void *ws, u32 h, u32 x);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_02012F38(int base);
extern u8 func_02025B64(u32 v);
extern int func_021CFD88(int a, u32 b, u32 c, int d, int e);

int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e)
{
    u32 v, t, w, s, x, g, h;
    u32 flag;

    flag = 0;
    h = (u32)func_020120F4((const struct Ctx *)b);
    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    if (d >= 5) {
        return 4;
    }
    x = ((u8 *)(c + d))[8];
    func_021CFDBC((void *)a, h, x);
    v = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    s = func_02008550((const struct Sub0200852CObj *)v);
    w = func_02009634((const struct Sub02009470Obj *)g, x, 4);
    t = func_02008530((const struct Sub0200852CObj *)v);
    if (func_02025B64(*((u8 *)func_02012F38(h)))) {
        flag = 1;
    }
    return func_021CFD88(s, t, w, e, flag);
}
