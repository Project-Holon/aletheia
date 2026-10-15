/*
 * function: COMM_BTL_DEMO_GRAPHIC_VBlank
 * address: 0x021BACA0
 * packet: pkt_ov213_021BACA0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * Preserve the pointer explicitly loaded before the no-op/global helper call.
 * symbols:
 *   COMM_BTL_DEMO_GRAPHIC_TickDisplay 0x021BAD50 thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_VBlankClact 0x021BADBC thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void COMM_BTL_DEMO_GRAPHIC_TickDisplay(void *);
extern void COMM_BTL_DEMO_GRAPHIC_VBlankClact(void *);
void COMM_BTL_DEMO_GRAPHIC_VBlank(void *unused,char *p) { COMM_BTL_DEMO_GRAPHIC_TickDisplay(p); COMM_BTL_DEMO_GRAPHIC_VBlankClact(p+4); }
