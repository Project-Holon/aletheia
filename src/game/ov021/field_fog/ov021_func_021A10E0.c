/*
 * function: ov021_func_021A10E0
 * address:  0x021A10E0
 * packet:   pkt_ov021_021A10E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_021F2994  0x021F2994  thumb  ov029
 *   func_021F2848  0x021F2848  thumb  ov029
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_02009200(struct Sub020090B0Obj *obj, u8 value);
struct Ctx;
extern u32 func_0201214C(const struct Ctx *);
extern u32 func_02012204(const struct Ctx *p);
extern void func_02012210(struct Ctx *p);
extern int func_021F2994(int *p);
extern u32 func_021F2848(u32, u32);

u32 ov021_func_021A10E0(u32 *p, u32 x)
{
    u32 a, b;
    if (x != 0) {
        a = (u32)func_02188C80((void *)p[5]);
        b = (u32)func_02009210(func_02012EBC(func_020120F4((const struct Ctx *)a)));
        if (func_02012204((const struct Ctx *)a) != 0) {
            if (func_0201214C((const struct Ctx *)a) != 0) {
                func_02012210((struct Ctx *)a);
            } else if (func_021F2994((int *)p[8]) != 0) {
                func_02009200((struct Sub020090B0Obj *)b, 0);
                func_02012210((struct Ctx *)a);
            }
        }
    }
    return func_021F2848(p[8], x);
}
