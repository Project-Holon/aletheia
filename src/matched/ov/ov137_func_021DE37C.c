/*
 * function: GURU2_RECEIPT_GetJoinedBits
 * address: 0x021DE37C
 * packet: pkt_ov137_021DE37C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern u8 UNION_APP_GetJoinedBits(u8 *);
unsigned GURU2_RECEIPT_GetJoinedBits(void *p) {return UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p));}
