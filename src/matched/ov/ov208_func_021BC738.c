/*
 * function: func_021BC738
 * address: 0x021BC738
 * packet: pkt_ov208_021BC738
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021660 0x02021660 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Gfx { int f0; int f4; void *gfx; };
extern void func_02021660(void *gfx, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g)
{
    func_02021660(p->gfx, a, b, c, d, e, f, g);
}
