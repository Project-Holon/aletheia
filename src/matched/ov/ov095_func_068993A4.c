/*
 * unit: yes
 * function: HAND_SIDE_GetHandlersWideGuard
 * address: 0x068993A4
 * packet: pkt_ov095_068993A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled store-and-return follower after veneer 0x06899394.
 * symbols:
 *   gHandSideWideGuardHandlers 0x0689D700 data a4
 */
typedef unsigned int u32;
extern u32 gHandSideWideGuardHandlers;
void *HAND_SIDE_GetHandlersWideGuard(u32 *p) { *p = 1; return &gHandSideWideGuardHandlers; }
