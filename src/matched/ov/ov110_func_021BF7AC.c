/*
 * function: PMS_INPUT_GetTopRow
 * address: 0x021BF7AC
 * packet: pkt_ov110_021BF7AC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: following twelve bytes are already-filed PMS_INPUT_GetMaxTopRow.
 * symbols:
 *   PMS_WORDLIST_GetTopRow 0x021BEDE4 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 PMS_WORDLIST_GetTopRow(u8 *);
unsigned PMS_INPUT_GetTopRow(u8 *p) { return PMS_WORDLIST_GetTopRow(p+0x54); }
