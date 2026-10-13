/*
 * function: PMS_INPUT_GetMaxTopRow
 * address: 0x021BF7B8
 * packet: pkt_ov110_021BF7B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * body: tail-forwards p+0x54 to EDE8, whose complete four-byte body is
 *   ldrh r0,[r0,#2]; bx lr. Widening that unsigned return preserves every bit.
 * symbols:
 *   PMS_WORDLIST_GetMaxTopRow 0x021BEDE8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 PMS_WORDLIST_GetMaxTopRow(u8 *);
unsigned PMS_INPUT_GetMaxTopRow(u8 *p) { return PMS_WORDLIST_GetMaxTopRow(p+0x54); }
