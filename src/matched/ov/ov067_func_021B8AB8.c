/*
 * function: func_021B8AB8
 * address: 0x021B8AB8
 * packet: pkt_ov067_021B8AB8
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8A88 0x021B8A88 thumb ov067
 *   func_0202EE0C 0x0202EE0C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_021B8A88(u8 *, u8 *, u8 *);
extern int func_0202EE0C(int, int, int, int, int);
int func_021B8AB8(u8 *p)
{
    u8 b, a;
    func_021B8A88(p, &b, &a);
    return func_0202EE0C(*(u16 *)(p + 0x64), *(s16 *)(p + 0x62), b, a, p[0x12]);
}
