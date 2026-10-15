/*
 * function: ZUKAN_TOROKU_GRAPHIC_VBlank
 * address: 0x0220B434
 * packet: pkt_ov207_0220B434
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ZUKAN_TOROKU_GRAPHIC_ResetDisplay 0x0220B4E4 thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_VBlankActors 0x0220B550 thumb ov207
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(void*),ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*);
void ZUKAN_TOROKU_GRAPHIC_VBlank(void*unused,u8*p){ZUKAN_TOROKU_GRAPHIC_ResetDisplay(p);ZUKAN_TOROKU_GRAPHIC_VBlankActors(p+4);}
