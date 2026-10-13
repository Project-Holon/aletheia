/*
 * function: func_021B6D00
 * address: 0x021B6D00
 * packet: pkt_ov174_021B6D00
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03860.h"
struct Obj;struct Descriptor;extern void CLACT_DeleteActor(struct Obj *);extern void CLACT_ReleasePalette(unsigned),CLACT_ReleaseCharacter(unsigned),CLACT_ReleaseCellAnim(unsigned);extern void BMP_WIN_Delete(struct Descriptor *);extern void func_020307B0(void *);
void func_021B6D00(unsigned char *unused,char *p) {CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03860 *)p)->f28);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03860 *)p)->f2C);CLACT_ReleasePalette(((struct Obj03860 *)p)->f1C);CLACT_ReleaseCharacter(((struct Obj03860 *)p)->f20);CLACT_ReleaseCellAnim(((struct Obj03860 *)p)->f24);BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj03860 *)p)->f18);if(((struct Obj03860 *)p)->f10)func_020307B0(((struct Obj03860 *)p)->f10);func_020307B0(p);}
