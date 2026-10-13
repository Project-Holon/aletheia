/*
 * function: func_021C4514
 * address: 0x021C4514
 * packet: pkt_ov127_021C4514
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_021C4550 0x021C4550 thumb ov127
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj05372.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C4550(int *);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
void func_021C4514(char *p) { if(func_021C4550((int *)(p+0x2e0))==1) { CLACT_ReleaseCharacter(((struct Obj05372 *)p)->f2E0); ((struct Obj05372 *)p)->f2E0=-1; CLACT_ReleasePalette(((struct Obj05372 *)p)->f2E4); ((struct Obj05372 *)p)->f2E4=-1; CLACT_ReleaseCellAnim(((struct Obj05372 *)p)->f2E8); ((struct Obj05372 *)p)->f2E8=-1; } }
