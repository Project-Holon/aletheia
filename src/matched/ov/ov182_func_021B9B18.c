/*
 * function: THE_END_GRAPHIC_VBlankActors
 * address: 0x021B9B18
 * packet: pkt_ov182_021B9B18
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void CLACT_VBlankSystem(void);
void THE_END_GRAPHIC_VBlankActors(void *a0) { CLACT_VBlankSystem(); }
