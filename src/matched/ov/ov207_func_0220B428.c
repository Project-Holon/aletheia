/*
 * function: ZUKAN_TOROKU_GRAPHIC_GetDisplay
 * address: 0x0220B428
 * packet: pkt_ov207_0220B428
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_TOROKU_GRAPHIC_GetWord 0x0220B558 thumb ov207
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*);
u32 ZUKAN_TOROKU_GRAPHIC_GetDisplay(u8*p){return ZUKAN_TOROKU_GRAPHIC_GetWord((u32*)(p+4));}
