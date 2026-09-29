/*
 * function: func_021D799C
 * address:  0x021D799C
 * packet:   pkt_ov093_021D799C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8D0C  0x021E8D0C  thumb  ov093
 *   func_021E8DA8  0x021E8DA8  thumb  ov093
 *   func_021D794C  0x021D794C  thumb  ov093
 *   func_021D79E8  0x021D79E8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021E8D0C(int v, u8 *a, u8 *b);
extern int func_021E8DA8(int v);
extern int func_021D794C(int a, int b);
extern int func_021D79E8(int a, int b);

int func_021D799C(int a, int v)
{
    u8 t[2];
    int x;

    func_021E8D0C(v, &t[1], &t[0]);
    if (func_021E8DA8(v))
        return func_021D794C(a, t[1]);
    x = func_021D794C(a, t[1]);
    return func_021D79E8(x, func_021D794C(a, t[0]));
}
