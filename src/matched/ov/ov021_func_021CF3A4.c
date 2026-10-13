/*
 * function: COMM_ENTRY_RecvCancel
 * address: 0x021CF3A4
 * packet: pkt_ov021_021CF3A4
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/trial_house.c and filed here.
 *
 * symbols:
 *   COMM_ENTRY_MENU_SetCancelFlag 0x021CE718 thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
extern void COMM_ENTRY_MENU_SetCancelFlag(u8 *p);
void COMM_ENTRY_RecvCancel(u32 a, u32 b, u32 c, u8 *d);

void COMM_ENTRY_RecvCancel(u32 a, u32 b, u32 c, u8 *d) { COMM_ENTRY_MENU_SetCancelFlag(d); }
