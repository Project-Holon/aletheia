/*
 * function: BTL_REC_SEL_GRAPHIC_VBlank
 * address: 0x021BB2B4
 * packet: pkt_ov214_021BB2B4
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_REC_SEL_GRAPHIC_TickDisplay 0x021BB364 thumb ov214
 *   BTL_REC_SEL_GRAPHIC_VBlankClact 0x021BB3D0 thumb ov214
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_REC_SEL_GRAPHIC_TickDisplay(void *),BTL_REC_SEL_GRAPHIC_VBlankClact(void *);
void BTL_REC_SEL_GRAPHIC_VBlank(void *unused,u8 *p) { BTL_REC_SEL_GRAPHIC_TickDisplay(p);BTL_REC_SEL_GRAPHIC_VBlankClact(p+4); }
