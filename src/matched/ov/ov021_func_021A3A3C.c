/*
 * function: func_021A3A3C
 * address:  0x021A3A3C
 * packet:   pkt_ov021_021A3A3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: relocation evidence, func_020508EC (0x020508EC, arm9 ARM leaf,
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --arm --region arm9:
 *   int func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 0x28;
 *       u16 v = *(u16 *)(e + 0x1C);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb
 *   func_02197C9C  0x02197C9C  thumb
 *   func_0219C648  0x0219C648  thumb
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_020508EC  0x020508EC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0216D67C();
extern void func_0216D520();
extern u32 func_0219C9DC();
extern int func_02197C9C();
extern int func_0219C648();
extern u32 func_0216D7A8();
extern int func_020508EC();

int func_021A3A3C(u32 *p)
{
    u16 v;
    u32 h;
    u32 k;

    func_0216D67C(p[7]);
    func_0216D520();
    h = func_0219C9DC();
    if (func_02197C9C(p[7]) == 1 && func_0219C648(p[7]) == 1)
        return 1;
    k = func_0216D7A8(p[7], 0);
    if (k != 0xFFFF && func_020508EC(h, (u16)k, &v) != 0 && v == (0xFFFF >> 2))
        return 1;
    return 0;
}
