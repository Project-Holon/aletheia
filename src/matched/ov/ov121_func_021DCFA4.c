/*
 * function: MYSTERY_ALBUM_UpdateIconSprite
 * address: 0x021DCFA4
 * packet: pkt_ov121_021DCFA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
void MYSTERY_ALBUM_UpdateIconSprite(u8 *p,int b,int c,u16 d) {MYSTERY_UTIL_BlendPaletteRange((void *)b,(u16 *)p,d,c,(const u16 *)(p+32),(const u16 *)(p+64));}
