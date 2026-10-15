/*
 * function: MYSTERY_ALBUM_GetEntryEggFlag
 * address: 0x021DC030
 * packet: pkt_ov121_021DC030
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 low:1; u8 flag:1; u8 rest:6; } Bits;
int MYSTERY_ALBUM_GetEntryEggFlag(u32 p) { return ((Bits *)(p+184))->flag; }
