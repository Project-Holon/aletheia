/*
 * unit: no
 * function: func_021DFFC8
 * address: 0x021DFFC8
 * packet: pkt_ov137_021DFFC8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
#include "../include/Obj03842.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void CLACT_ReleaseCharacter(u32),CLACT_ReleasePalette(u32),CLACT_ReleaseCellAnim(u32);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void func_021DFFC8(u8 *p){CLACT_ReleaseCharacter(((struct Obj03842 *)p)->fD6C);CLACT_ReleasePalette(((struct Obj03842 *)p)->fD70);CLACT_ReleaseCellAnim(((struct Obj03842 *)p)->fD74);CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj03842 *)p)->fD68);CLACT_ExitSystem();}
