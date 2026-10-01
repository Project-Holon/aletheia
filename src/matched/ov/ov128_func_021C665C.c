/*
 * function: func_021C665C
 * address: 0x021C665C
 * packet: pkt_ov128_021C665C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: preserves incoming r0 at the tail call; callers load its argument
 *   even though func_0204A648's own body ignores that register.
 * symbols:
 *   func_0204A648 0x0204A648 arm
 */
extern void func_0204A648(void *);
void func_021C665C(void *p) { func_0204A648(p); }
