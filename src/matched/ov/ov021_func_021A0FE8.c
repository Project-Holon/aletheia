/*
 * function: ov021_func_021A0FE8
 * address:  0x021A0FE8
 * packet:   pkt_ov021_021A0FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02009208  0x02009208  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F279C  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern unsigned char abs_id_1d[];
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern u8 func_02009208(const struct Sub020090B0Obj *obj);
extern void func_02009200(u32, u32);
struct Ctx;
extern u32 func_0201214C(const struct Ctx *);
extern u32 func_02012204(const struct Ctx *p);
extern void func_02012210(struct Ctx *p);
extern int func_02034AC4(int);
extern void *func_021F279C(int a, int b, int c, int d);

void ov021_func_021A0FE8(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)func_02188C80((void *)p[5]);
    b = (u32)func_02009210(func_02012EBC(func_020120F4((const struct Ctx *)a)));
    func_02034AC4((int)abs_id_1d);
    c = func_02009208((const struct Sub020090B0Obj *)b);
    d = func_0201214C((const struct Ctx *)a);
    p[8] = (u32)func_021F279C(b, (int)p, a, d == 1 && c == 0);
    func_02009200(b, d);
    if (func_02012204((const struct Ctx *)a) != 0)
        func_02012210((struct Ctx *)a);
}
