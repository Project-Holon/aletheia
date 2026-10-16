/*
 * function: MICTEST_ExitActorSystem
 * address: 0x02183F98
 * packet: pkt_ov168_02183F98
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
extern void CLACT_ExitSystem(void);
void MICTEST_ExitActorSystem(void *a0) { CLACT_ExitSystem(); }
