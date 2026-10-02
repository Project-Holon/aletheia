/*
 * function: func_021C3BB8
 * address: 0x021C3BB8
 * packet: pkt_ov093_021C3BB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C3BE0 0x021C3BE0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021EF8A4(u32, u32);
extern void func_021CD4B0(void *, u32, ...);
extern void func_021C3BE0(u8 *, u32);
void func_021C3BB8(u8 *p, u32 a, u32 b)
{
    func_021EF8A4(a, b);
    func_021CD4B0(*(void **)(p + 12), 0x3f, a, b);
    func_021C3BE0(p, a);
}
