/*
 * function: func_021BC730
 * address: 0x021BC730
 * packet: pkt_ov209_021BC730
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020056BC(void);
extern int func_0202173C(void *, u16, u16, short, u8, u8, u16, void *);
void func_021BC730(char *p, u8 a, u8 b)
{
    void *ctx;
    ctx = func_020056BC();
    func_0202173C(*(void **)(p + 12), 1, 0xBFFF, -14, a, b, 0, ctx);
    ctx = func_020056BC();
    func_0202173C(*(void **)(p + 12), 2, 0xFFEF, -14, a, b, 0, ctx);
    ctx = func_020056BC();
    func_0202173C(*(void **)(p + 12), 4, 0xF878, -14, a, b, 0, ctx);
    ctx = func_020056BC();
    func_0202173C(*(void **)(p + 12), 8, 0xBFFF, -14, a, b, 0, ctx);
}
