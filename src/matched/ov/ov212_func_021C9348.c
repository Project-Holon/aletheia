/*
 * function: func_021C9348
 * address: 0x021C9348
 * packet: pkt_ov212_021C9348
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern u32 func_0200CA70(struct Blk37 *);
extern u32 func_0200CED4(struct Blk37 *, u16);
extern u32 func_0200D064(struct Blk37 *, u16);
int func_021C9348(struct Blk37 *p) {
    if (func_0200CA70(p) == 1) return 1;
    if (func_0200CED4(p,494) == 1 || func_0200D064(p,494) == 1) return 1;
    return 0;
}
