/*
 * function: func_021DD570
 * address: 0x021DD570
 * packet: pkt_ov137_021DD570
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
#include "../include/Obj10616.h"
#include "../include/Obj14207.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void func_021DD570(u8 *p) {int i;u8 *q;ARC_TOOL_DeleteHandle(((struct Obj10616 *)p)->f34);for(i=0;i<5;i++) {q=(u8 *)((u32)p+i*4);CLACT_ReleaseCharacter(((struct Obj14207 *)q)->f6C);CLACT_ReleasePalette(((struct Obj14207 *)q)->f80);}CLACT_ReleaseCellAnim(((struct Obj10616 *)p)->f94);CLACT_DeleteUnit(((struct Obj10616 *)p)->f68);CLACT_ExitSystem();}
