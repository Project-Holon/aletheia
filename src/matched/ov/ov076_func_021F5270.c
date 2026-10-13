/*
 * function: ENCEFF_BuildModelSceneKind01
 * address: 0x021F5270
 * packet: pkt_ov076_021F5270
 * region: ov076
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ENCEFF_StartModelScene 0x021F52D8 thumb ov076
 */
typedef unsigned int u32;
extern void *ENCEFF_StartModelScene(void *, u32, u32, u32, int);
void *ENCEFF_BuildModelSceneKind01(void *a, u32 b, int c) { return ENCEFF_StartModelScene(a,b,9,8,c); }
