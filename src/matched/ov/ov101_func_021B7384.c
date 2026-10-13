/*
 * function: func_021B7384
 * address: 0x021B7384
 * packet: pkt_ov101_021B7384
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj06364.h"
extern void CLACT_ReleaseCellAnim(unsigned); extern void CLACT_ReleaseCharacter(unsigned); extern void CLACT_ReleasePalette(unsigned);
void func_021B7384(unsigned p) { CLACT_ReleaseCellAnim(((struct Obj06364 *)p)->f38); CLACT_ReleaseCharacter(((struct Obj06364 *)p)->f34); CLACT_ReleasePalette(((struct Obj06364 *)p)->f30); }
