/*
 * function: GTSNEGO_MSG_DeleteButtonsKeep
 * address: 0x021D7EC4
 * packet: pkt_ov120_021D7EC4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_DeleteButtons 0x021D7710 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void GTSNEGO_MSG_DeleteButtons(u8 *);
void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p) { GTSNEGO_MSG_DeleteButtons(p); }
