/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor
 * address: 0x021BA028
 * packet: pkt_ov222_021BA028
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue 0x021BA158 thumb ov222
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p) { return ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue((const u32 *)(p+4)); }
