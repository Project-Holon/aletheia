/*
 * function: BTL_REC_SEL_GRAPHIC_Draw
 * address: 0x021BB27C
 * packet: pkt_ov214_021BB27C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_REC_SEL_GRAPHIC_DrawClact 0x021BB3C8 thumb ov214
 *   BTL_REC_SEL_GRAPHIC_Noop 0x021BB360 thumb ov214
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_REC_SEL_GRAPHIC_DrawClact(void *),BTL_REC_SEL_GRAPHIC_Noop(void *);
void BTL_REC_SEL_GRAPHIC_Draw(u8 *p) { BTL_REC_SEL_GRAPHIC_DrawClact(p+4);BTL_REC_SEL_GRAPHIC_Noop(p); }
