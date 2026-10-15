/*
 * function: ZUKAN_IsNationalMode
 * address: 0x021C9348
 * packet: pkt_ov212_021C9348
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *);
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *, u16);
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *, u16);
int ZUKAN_IsNationalMode(struct Blk37 *p) {
    if (ZUKAN_SAVE_GetViewMode(p) == 1) return 1;
    if (ZUKAN_SAVE_IsCaught(p,494) == 1 || ZUKAN_SAVE_IsSeen(p,494) == 1) return 1;
    return 0;
}
