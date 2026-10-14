/*
 * function: GURU2_RECEIPT_GetKeyTrg
 * address: 0x021DE7F4
 * packet: pkt_ov137_021DE7F4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
u32 GURU2_RECEIPT_GetKeyTrg(void) { return KEY_GetTrg(); }
