/*
 * function: func_021BA150, func_021BA158
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
void func_021BA150(void *p) { CLACT_VBlankSystem(); }
u32 func_021BA158(const u32 *p) { return *p; }
