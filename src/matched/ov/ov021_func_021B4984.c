/*
 * function: func_021B4984
 * address:  0x021B4984
 * packet:   pkt_ov021_021B4984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B4878 0x021B4878 thumb ov021
 *   func_021B4894 0x021B4894 thumb ov021
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021B4878(u32 a);
extern void func_021B4894(u32 a, u32 b);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern int func_020212B0(u32 a);
extern void func_0201EF34(u32 a, u32 b, u32 c);

void func_021B4984(char *w, u32 a, u32 b, u32 c)
{
    func_021B4878(*(u32 *)(w + 0x17C));
    func_0201EFA4(*(u32 *)(w + 0x190), 0, b - 327, 2, 2, 1);
    func_0201EF34(*(u32 *)(w + 0x190), 1, func_020212B0(b));
    func_0201EFA4(*(u32 *)(w + 0x190), 2, c, 5, 0, 1);
    func_021B4894((u32)w, a);
}
