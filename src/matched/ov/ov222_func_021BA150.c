/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank, ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue
 * address: 0x021BA150
 * packet: pkt_ov222_021BA150
 * region: ov222
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: tail thunk plus unlabelled getter at 021BA158.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p) { CLACT_VBlankSystem(); }
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *p) { return *p; }
