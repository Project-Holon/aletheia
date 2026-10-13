/*
 * function: BTL_ABILITY_GetIndirectGuardCause6Handlers
 * address: 0x021D9234
 * packet: pkt_ov093_021D9234
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
 *   gIndirectGuardCause6HandlerTable 0x021F0890 data ov093 a4
 */

int *BTL_ABILITY_GetIndirectGuardCause6Handlers(int *p);

/* 021D9240  shifted 4-arg wrapper -> BTL_ABILITY_BlockIndirectDamage(..., 0x6) */
extern int gIndirectGuardCause6HandlerTable[];

int *BTL_ABILITY_GetIndirectGuardCause6Handlers(int *p)
{
    *p = 2;
    return gIndirectGuardCause6HandlerTable;
}
