/*
 * function: ZUKAN_TOROKU_GRAPHIC_Draw
 * address: 0x0220B40C
 * packet: pkt_ov207_0220B40C
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ZUKAN_TOROKU_GRAPHIC_DrawActors 0x0220B548 thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_UpdateBg 0x0220B4E0 thumb ov207
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void ZUKAN_TOROKU_GRAPHIC_DrawActors(void*),ZUKAN_TOROKU_GRAPHIC_UpdateBg(void*);
void ZUKAN_TOROKU_GRAPHIC_Draw(u8*p){ZUKAN_TOROKU_GRAPHIC_DrawActors(p+4);ZUKAN_TOROKU_GRAPHIC_UpdateBg(p);}
