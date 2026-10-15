/*
 * unit: yes
 * function: MYSTERY_GRAPHIC_VBlankClact, MYSTERY_GRAPHIC_GetFirstWord
 * address: 0x021D98E8
 * packet: pkt_ov121_021D98E8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: tail wrapper plus unlabelled getter follower; seed 021D98F0.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void MYSTERY_GRAPHIC_VBlankClact(void *a0) { CLACT_VBlankSystem(); }
unsigned MYSTERY_GRAPHIC_GetFirstWord(unsigned *p) { return *p; }
