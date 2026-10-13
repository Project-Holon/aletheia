/*
 * function: ENCEFF_UpdateModelScene
 * address: 0x021F5324
 * packet: pkt_ov076_021F5324
 * region: ov076
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding.
 * symbols:
 *   ENCEFF_GetWork 0x021CF560 thumb ov021
 *   SCREENTEX_SetupCamera 0x0202E688 thumb
 */
typedef unsigned int u32;
extern u32 ENCEFF_GetWork(u32 *);
extern void SCREENTEX_SetupCamera(u32);
void ENCEFF_UpdateModelScene(u32 *p) { SCREENTEX_SetupCamera(*(u32 *)(ENCEFF_GetWork(p) + 0x28)); }
