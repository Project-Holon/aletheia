/*
 * function: BTL_ABILITY_GetRecklessHandlers
 * address: 0x021D9190
 * packet: pkt_ov093_021D9190
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9118.c and filed here.
 *
 * symbols:
 *   gRecklessHandlerTable 0x021F0720 data ov093 a4
 */

int *BTL_ABILITY_GetRecklessHandlers(int *p);
extern int gRecklessHandlerTable[];

int *BTL_ABILITY_GetRecklessHandlers(int *p)
{
    *p = 1;
    return gRecklessHandlerTable;
}
