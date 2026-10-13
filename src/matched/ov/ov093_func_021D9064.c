/*
 * function: HAND_TOKUSEI_GetFlowerGiftHandlers
 * address: 0x021D9064
 * packet: pkt_ov093_021D9064
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8D40.c and filed here.
 *
 * symbols:
 *   gFlowerGiftHandlers 0x021F0E1C data ov093 a4
 */

int *HAND_TOKUSEI_GetFlowerGiftHandlers(int *p);
extern int gFlowerGiftHandlers[];

int *HAND_TOKUSEI_GetFlowerGiftHandlers(int *p)
{
    *p = 11;
    return gFlowerGiftHandlers;
}
