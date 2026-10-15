/*
 * function: STA_ACT_LIGHT_DeleteUnit
 * address: 0x021F6C7C
 * packet: pkt_ov112_021F6C7C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj08024.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_ReleasePalette(u32);extern void CLACT_ReleaseCharacter(u32);extern void CLACT_ReleaseCellAnim(u32);extern void CLACT_DeleteUnit(void *);extern void func_020307B0(void *);
void STA_ACT_LIGHT_DeleteUnit(char *p) {CLACT_ReleasePalette(((struct Obj08024 *)p)->fAC);CLACT_ReleaseCharacter(((struct Obj08024 *)p)->fB0);CLACT_ReleaseCellAnim(((struct Obj08024 *)p)->fB4);CLACT_DeleteUnit(((struct Obj08024 *)p)->fA8);func_020307B0(p);}
