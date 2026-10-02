/*
 * function: func_02174D10
 * address: 0x02174D10
 * packet: pkt_ov012_02174D10
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021750C8 0x021750C8 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021750C8(u8 *, u32);
void func_02174D10(u32 a, u32 b, u32 *c, u8 *d)
{
    u8 *w = *(u8 **)(d + 0x355c);
    if (w == 0 || *(u32 *)w == 0) return;
    func_021750C8(w, *c);
}
