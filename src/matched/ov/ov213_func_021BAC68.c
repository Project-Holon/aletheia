/*
 * function: COMM_BTL_DEMO_GRAPHIC_Draw
 * address: 0x021BAC68
 * packet: pkt_ov213_021BAC68
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * Preserve the pointer explicitly loaded before the no-op/global helper call.
 * symbols:
 *   COMM_BTL_DEMO_GRAPHIC_DrawClact 0x021BADB4 thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_Noop 0x021BAD4C thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void COMM_BTL_DEMO_GRAPHIC_DrawClact(void *);
extern void COMM_BTL_DEMO_GRAPHIC_Noop(void *);
void COMM_BTL_DEMO_GRAPHIC_Draw(char *p) { COMM_BTL_DEMO_GRAPHIC_DrawClact(p+4); COMM_BTL_DEMO_GRAPHIC_Noop(p); }
