/*
 * function: ENCEFF_BuildModelSceneKind06
 * address: 0x021F5290
 * packet: pkt_ov076_021F5290
 * region: ov076
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding.
 * symbols:
 *   ENCEFF_StartModelScene 0x021F52D8 thumb ov076
 */
typedef unsigned int u32;
extern void *ENCEFF_StartModelScene(void *, u32, u32, u32, int);
void *ENCEFF_BuildModelSceneKind06(void *a, u32 b, int c) { return ENCEFF_StartModelScene(a,b,3,2,c); }
