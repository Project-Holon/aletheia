/*
 * function: MYSTERY_ALBUM_GetEntryIconX
 * address: 0x021DC03C
 * packet: pkt_ov121_021DC03C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   MYSTERY_ALBUM_GetEntryEggFlag 0x021DC030 thumb ov121
 *   d_021DF838 0x021DF838 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *);
extern int MYSTERY_ALBUM_GetEntryEggFlag(u32 p);
extern const int d_021DF838[];
int MYSTERY_ALBUM_GetEntryIconX(void *p) { int i,add; i=MYSTERY_ALBUM_GetEntryKind(p); add=MYSTERY_ALBUM_GetEntryEggFlag((u32)p) ? 0 : 5; return add+d_021DF838[i]; }
