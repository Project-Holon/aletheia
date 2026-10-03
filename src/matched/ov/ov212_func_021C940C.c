/*
 * function: func_021C940C
 * address: 0x021C940C
 * packet: pkt_ov212_021C940C
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B294(u32,u32,u32,u32,u32,u16,u16);
void func_021C940C(u32 bank, const u8 *t, u16 heap) {
    func_0204B294(bank,*(const u32 *)(t+8),*(const u32 *)(t+12),*(const u32 *)(t+16),(u32)t,*(const u16 *)(t+22),heap);
}
