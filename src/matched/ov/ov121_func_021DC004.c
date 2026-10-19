/*
 * function: MYSTERY_ALBUM_GetEntryCellAnimResId
 * address: 0x021DC004
 * packet: pkt_ov121_021DC004
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *); extern int POKE_TOOL_GetIconCellEntryId(void);
int MYSTERY_ALBUM_GetEntryCellAnimResId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return POKE_TOOL_GetIconCellEntryId(); case 2: return 0; default:return 36; } }
