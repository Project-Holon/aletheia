/*
 * function: ov021_func_021A1050
 * address:  0x021A1050
 * packet:   pkt_ov021_021A1050
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
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F27D8  0x021F27D8  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern unsigned char abs_id_1d[];
struct Big;
struct Ctx;
struct Sub02009210Obj;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_02009200(u32, u32);
struct Ctx;
extern u32 func_0201214C(const struct Ctx *p);
extern u32 func_02012204(const struct Ctx *p);
extern void func_02012210(struct Ctx *p);
extern int func_02034AC4(int);
extern char *func_021F27D8(int a0, int a1, int a2, void (*cb)(int), int arg, int flag);

void ov021_func_021A1050(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)func_02188C80((void *)p[5]);
    b = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    func_02034AC4((int)abs_id_1d);
    c = func_0201214C((const struct Ctx *)a);
    d = (u32)func_02009210((void *)b);
    p[8] = (u32)func_021F27D8(d, (int)p, (int)func_02188C80((void *)p[5]), (void (*)(int))p[6], p[7], c);
    func_02009200(d, c);
    if (func_02012204((const struct Ctx *)a) != 0)
        func_02012210((struct Ctx *)a);
    p[0] = 0;
    p[1] = 0;
}
