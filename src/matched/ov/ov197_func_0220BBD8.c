/*
 * function: B_BAG_MAIN_GetItemFlag
 * address: 0x0220BBD8
 * packet: pkt_ov197_0220BBD8
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Forward entry r0 as the key. The explicit result truncation requires a wide extern return.
 * symbols:
 *   ITEM_GFX_GetExtraValue 0x0202F144 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 ITEM_GFX_GetExtraValue(u32);
int B_BAG_MAIN_GetItemFlag(u32 key) { return (u16)ITEM_GFX_GetExtraValue(key); }
