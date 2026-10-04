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
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_021C940C(u32 bank, const u8 *t, u16 heap) {
    func_0204B294((void *)bank,*(const u32 *)(t+8),*(const u32 *)(t+12),*(const u32 *)(t+16),t,*(const u16 *)(t+22),heap);
}
