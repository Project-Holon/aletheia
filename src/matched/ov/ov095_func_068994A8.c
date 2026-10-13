/*
 * unit: yes
 * function: HAND_SIDE_GetHandlersQuickGuard
 * address: 0x068994A8
 * packet: pkt_ov095_068994A8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled store-and-return follower after veneer 0x06899498.
 * symbols:
 *   gHandSideQuickGuardHandlers 0x0689D718 data a4
 */
typedef unsigned int u32;
extern u32 gHandSideQuickGuardHandlers;
void *HAND_SIDE_GetHandlersQuickGuard(u32 *p) { *p = 1; return &gHandSideQuickGuardHandlers; }
