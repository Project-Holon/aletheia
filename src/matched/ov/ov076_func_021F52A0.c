/*
 * function: ENCEFF_BuildModelSceneKind31
 * address: 0x021F52A0
 * packet: pkt_ov076_021F52A0
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
void *ENCEFF_BuildModelSceneKind31(void *a, u32 b, int c) { return ENCEFF_StartModelScene(a,b,1,0,c); }
