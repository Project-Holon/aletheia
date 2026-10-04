/*
 * function: func_021CB174
 * address: 0x021CB174
 * packet: pkt_ov093_021CB174
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021B8C50 forwards live r1/r2 to func_021B8C20 and returns r0.
 * symbols:
 *   func_021B8C50 0x021B8C50 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 func_021B8C50(char **p, u32 v, int k);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *, unsigned int);
struct S2;
extern u32 func_021B9BF0(struct S2 *p, u32 i);
void *func_021CB174(u8 *p, unsigned int n, int k)
{
    u8 out[2];
    func_021B8E28(*(u8 **)(p + 4), func_021B8C50(*(void **)(p + 4), n, k), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(func_021BB85C(*(u8 **)p, out[1]) + 4), out[0]);
}
