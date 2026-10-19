/*
 * function: MANUAL_COMMON_SetDialogBgMode
 * address: 0x021BB4F8
 * packet: pkt_ov225_021BB4F8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void BG_SYS_MarkTileDirty(u32);
void MANUAL_COMMON_SetDialogBgMode(char *a0) { BG_SYS_MarkTileDirty(4); }
