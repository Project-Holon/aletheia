/*
 * function: func_021B9DEC
 * address: 0x021B9DEC
 * packet: pkt_ov225_021B9DEC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9F8C 0x021B9F8C thumb ov225
 *   func_021B9E80 0x021B9E80 thumb ov225
 *   func_021B9F20 0x021B9F20 thumb ov225
 *   func_021B9BA4 0x021B9BA4 thumb ov225
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MANUAL_GRAPHIC_DeleteScreen 0x021B99A0 thumb ov225
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01787.h"
struct Rec;struct PrintSys;
extern void func_021B9F8C(char *p);
extern void func_021B9E80(char *,unsigned);
extern void func_021B9F20(void *);
extern void func_021B9BA4(char *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void MANUAL_GRAPHIC_DeleteScreen(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021B9DEC(char *p)
{
    func_021B9F8C(((struct Obj01787 *)p)->f34);func_021B9E80(p,0xffff);func_021B9F20(p);
    func_021B9BA4(((struct Obj01787 *)p)->f2C);ARC_TOOL_DeleteHandle(((struct Obj01787 *)p)->f24);ARC_TOOL_DeleteHandle(((struct Obj01787 *)p)->f28);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj01787 *)p)->f1C);MSGDATA_Delete(*(struct Rec * *)&((struct Obj01787 *)p)->f20);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);
    GF_FONT_Delete(((struct Obj01787 *)p)->fC);MANUAL_GRAPHIC_DeleteScreen(*(char * *)&((struct Obj01787 *)p)->f8);func_020307B0(p);
}
