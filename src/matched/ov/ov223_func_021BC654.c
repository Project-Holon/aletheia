/*
 * function: func_021BC654, func_021BC65C
 * address: 0x021BC654
 * packet: pkt_ov223_021BC654
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * extent: tail-call stub followed by unlabelled 021BC65C load-return.
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void func_021BC654(void *a0) { CLACT_VBlankSystem(); }
u32 func_021BC65C(const u32 *p) { return *p; }
