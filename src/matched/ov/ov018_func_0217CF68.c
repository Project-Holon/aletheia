/*
 * function: func_0217CF68
 * address: 0x0217CF68
 * packet: pkt_ov018_0217CF68
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_02012138 0x02012138 thumb
 *   func_0217BF84 0x0217BF84 thumb ov018
 */
extern void *func_0215A5DC(void *);
typedef unsigned int   u32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void func_0217BF84(void *);
int func_0217CF68(void *unused, void *p)
{
    void *sys;
    void *obj;
    sys = func_0215A5DC(p);
    obj = func_0201210C(sys);
    func_02012138(sys);
    func_0217BF84(obj);
    return 0;
}
