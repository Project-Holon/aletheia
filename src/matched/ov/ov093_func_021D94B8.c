/*
 * function: BTL_TOKUSEI_GetFreezeGuardHandlers
 * address: 0x021D94B8
 * packet: pkt_ov093_021D94B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gFreezeGuardHandlers 0x021F0C4C data ov093 a4
 */

int *BTL_TOKUSEI_GetFreezeGuardHandlers(int *p);

/* 021D94C4  shape F5: out-param store of BTL_TOKUSEI_BlockSickIfTargeted(..., 5) */
extern int gFreezeGuardHandlers[];

/*
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 */
int *BTL_TOKUSEI_GetFreezeGuardHandlers(int *p)
{
    *p = 5;
    return gFreezeGuardHandlers;
}
