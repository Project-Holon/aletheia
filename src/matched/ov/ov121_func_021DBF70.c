/*
 * function: MYSTERY_ALBUM_GetEntryIconPalette
 * address: 0x021DBF70
 * packet: pkt_ov121_021DBF70
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   MYSTERY_ALBUM_GetEntryCard 0x021DC02C thumb ov121
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 */
#include "../include/Obj08097.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *); extern char *MYSTERY_ALBUM_GetEntryCard(void *); extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
u32 MYSTERY_ALBUM_GetEntryIconPalette(void *p) { char *q; if (MYSTERY_ALBUM_GetEntryKind(p)==1) { q=MYSTERY_ALBUM_GetEntryCard(p); return POKE_TOOL_CalcIconPalette(((struct Obj08097 *)q)->f1A,((struct Obj08097 *)q)->f1C,((struct Obj08097 *)q)->f35,((struct Obj08097 *)q)->f5C); } return 0; }
