/*
 * function: func_021B4918
 * address:  0x021B4918
 * packet:   pkt_ov021_021B4918
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The spilled third parameter is narrow (u16 here; s16/u8 give the same
 * bytes): as u32/int its entry spill `str r2, [sp, #8]` lands after the
 * `lsls` instead of before it.
 *
 * symbols:
 *   func_021B4878 0x021B4878 thumb ov021
 *   func_021B4894 0x021B4894 thumb ov021
 *   func_0201EF6C 0x0201EF6C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021B4878(u32 a);
struct WordSet;
extern void func_021B4894(char *w, u32 b);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

void func_021B4918(char *w, u32 a, u16 b, u32 c, u16 d)
{
    func_021B4878(*(u32 *)(w + 0x17C));
    func_0201EF6C((struct WordSet *)(*(u32 *)(w + 0x190)), 0, b, 0, 0);
    func_0201EFA4((struct WordSet *)(*(u32 *)(w + 0x190)), 1, d, 2, 0, 1);
    func_0201EFA4((struct WordSet *)(*(u32 *)(w + 0x190)), 2, d * c, 7, 0, 1);
    func_021B4894((char *)((u32)w), a);
}
