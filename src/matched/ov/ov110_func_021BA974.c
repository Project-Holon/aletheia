/*
 * function: func_021BA974
 * address: 0x021BA974
 * packet: pkt_ov110_021BA974
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *, u8, int);
extern void func_021B9CBC(u8 *);
void func_021BA974(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 **)p;
    func_021BCF7C(*(u8 **)(q + 0x64), func_021BF71C(*(u8 **)(q + 0x18)), 1);
    func_021B9CBC(p);
}
