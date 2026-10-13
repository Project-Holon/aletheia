/*
 * function: BTL_ABILITY_GetMoldBreakerHandlers
 * address: 0x021D91FC
 * packet: pkt_ov093_021D91FC
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
 *   gMoldBreakerHandlerTable 0x021F0618 data ov093 a4
 */

int *BTL_ABILITY_GetMoldBreakerHandlers(int *p);

/* 021D9214  shifted 4-arg wrapper -> BTL_ABILITY_BlockIndirectDamage(..., 0x1) */
extern int gMoldBreakerHandlerTable[];

int *BTL_ABILITY_GetMoldBreakerHandlers(int *p)
{
    *p = 1;
    return gMoldBreakerHandlerTable;
}
