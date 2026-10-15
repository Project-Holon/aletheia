/*
 * function: MYSTERY_ALBUM_GetEntrySpeciesId
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
 *   func_0201BC40 0x0201BC40 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *); extern int func_0201BC40(void);
int MYSTERY_ALBUM_GetEntrySpeciesId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return func_0201BC40(); case 2: return 1; default:return 33; } }
