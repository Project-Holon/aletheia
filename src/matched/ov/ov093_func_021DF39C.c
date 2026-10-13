/*
 * function: BTL_HANDLER_ITEM_SmokeBall_AllowEscape
 * address: 0x021DF39C
 * packet: pkt_ov093_021DF39C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF370.c and filed here.
 *
 * symbols:
 *   BTLV_CORE_EventSetFlagIfAttacker 0x021E8878 thumb ov093
 */

void BTLV_CORE_EventSetFlagIfAttacker(int a, int b, int c, int d);
void BTL_HANDLER_ITEM_SmokeBall_AllowEscape(int a, int b, int c, int d);

void BTL_HANDLER_ITEM_SmokeBall_AllowEscape(int a, int b, int c, int d)
{
    BTLV_CORE_EventSetFlagIfAttacker(a, b, c, d);
}
