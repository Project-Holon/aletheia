/*
 * function: HAND_POS_GetHandlersLunarDance
 * address: 0x068984BC
 * packet: pkt_ov095_068984BC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * extent: 12-byte unlabelled store-and-return follower after non-C veneer 068984AC; next function 068984C8 is already matched.
 * symbols:
 *   gHandPosLunarDanceHandlers 0x0689D6B8 data ov095 a4
 */
typedef unsigned int u32;
extern u32 gHandPosLunarDanceHandlers[];
u32 *HAND_POS_GetHandlersLunarDance(u32 *p) { *p=2; return gHandPosLunarDanceHandlers; }
