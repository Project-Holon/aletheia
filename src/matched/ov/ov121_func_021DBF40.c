/*
 * function: MYSTERY_ALBUM_GetEntryPaletteResId
 * address: 0x021DBF40
 * packet: pkt_ov121_021DBF40
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: FILE_UTIL_Get item is u16 here, matching caller truncation before the call.
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   MYSTERY_ALBUM_GetEntryCard 0x021DC02C thumb ov121
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *); extern char *MYSTERY_ALBUM_GetEntryCard(void *); extern int POKE_TOOL_GetIconPaletteArcId(void); extern u32 FILE_UTIL_Get(u16,u32);
u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1:return POKE_TOOL_GetIconPaletteArcId(); case 2:return FILE_UTIL_Get(*(u32 *)MYSTERY_ALBUM_GetEntryCard(p),2); default:return 3; } }
