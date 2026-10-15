/*
 * function: HAND_WAZA_GetPledgeHandlers
 * address: 0x021E83C0
 * packet: pkt_ov093_021E83C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8384.c and filed here.
 *
 * symbols:
 *   gPledgeHandlers 0x021F2F68 data ov093 a4
 */

int *HAND_WAZA_GetPledgeHandlers(int *p);
extern int gPledgeHandlers[];

/*
 * Return r0 from BOX2_SEQ_GetActorDrawEnable and BOX2_SEQ_ResetEntryB is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int *HAND_WAZA_GetPledgeHandlers(int *p)
{
    *p = 6;
    return gPledgeHandlers;
}
