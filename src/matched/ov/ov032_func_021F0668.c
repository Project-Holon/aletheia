/*
 * function: BEACON_VIEW_IsArrowAnimActive
 * address: 0x021F0668
 * packet: pkt_ov032_021F0668
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
typedef unsigned int u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *);
int BEACON_VIEW_IsArrowAnimActive(char *p, int i) { return CLACT_IsActorAnimActive(*(struct Actor **)(p + i * 4 + 0x2bc)); }
