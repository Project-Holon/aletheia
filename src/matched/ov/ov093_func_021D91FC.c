/*
 * function: HAND_TOKUSEI_GetSkillLinkHandlers
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
 *   gMoldBreakerFlagHandlers 0x021F0618 data ov093 a4
 */

int *HAND_TOKUSEI_GetSkillLinkHandlers(int *p);

/* 021D9214  shifted 4-arg wrapper -> HAND_TOKUSEI_BlockIndirectDamage(..., 0x1) */
extern int gMoldBreakerFlagHandlers[];

int *HAND_TOKUSEI_GetSkillLinkHandlers(int *p)
{
    *p = 1;
    return gMoldBreakerFlagHandlers;
}
