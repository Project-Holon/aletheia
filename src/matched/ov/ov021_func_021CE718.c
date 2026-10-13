/*
 * function: COMM_ENTRY_MENU_SetCancelFlag
 * address: 0x021CE718
 * packet: pkt_ov021_021CE718
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/fld_trade_p03.c and filed here.
 */

typedef unsigned char u8;
void COMM_ENTRY_MENU_SetCancelFlag(u8 *p);

void COMM_ENTRY_MENU_SetCancelFlag(u8 *p)
{
    p[0x51A] = 1;
}
