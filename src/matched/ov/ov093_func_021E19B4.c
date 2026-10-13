/*
 * function: HAND_WAZA_AddMetalBurst
 * address: 0x021E19B4
 * packet: pkt_ov093_021E19B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E18EC.c and filed here.
 *
 * symbols:
 *   gMetalBurstHandlers 0x021F2C30 data ov093 a4
 */

int *HAND_WAZA_AddMetalBurst(int *p);

/* 021E19C0  shifted 4-arg wrapper -> HAND_WAZA_RetaliateOnMoveFailCheck(..., 0x0) */
extern int gMetalBurstHandlers[];

int *HAND_WAZA_AddMetalBurst(int *p)
{
    *p = 3;
    return gMetalBurstHandlers;
}
