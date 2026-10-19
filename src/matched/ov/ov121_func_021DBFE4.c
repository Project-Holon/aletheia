/*
 * function: MYSTERY_ALBUM_GetEntryCellResId
 * address: 0x021DBFE4
 * packet: pkt_ov121_021DBFE4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *); extern int POKE_TOOL_GetIconCellArcId(void);
int MYSTERY_ALBUM_GetEntryCellResId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return POKE_TOOL_GetIconCellArcId(); case 2: return 1; default:return 33; } }
