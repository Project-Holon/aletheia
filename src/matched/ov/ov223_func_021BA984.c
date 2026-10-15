/*
 * function: PSEL_CreateUnits2
 * address: 0x021BA984
 * packet: pkt_ov223_021BA984
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PSEL_GRAPHIC_GetClactBank 0x021BC520 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   PSEL_SetActorPosition 0x021BAA5C thumb
 */
#include "../include/Obj00211.h"
typedef unsigned short u16;
typedef unsigned char u8;
struct Request {u16 x,y,z;u8 a,b;};
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterPaletteEx(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MI_CpuFill8(void *,int,unsigned);
extern unsigned PSEL_GRAPHIC_GetClactBank(unsigned char *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
typedef unsigned int   u32;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void PSEL_SetActorPosition(char *p, int flag);
void PSEL_CreateUnits2(char *p)
{
    void *object;
    struct Request request;
    object=func_020490F4(205,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f21C=CLACT_RegisterPaletteEx(object,11,0,0,0,1,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f218=CLACT_RegisterCharacter(object,17,0,0,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f220=CLACT_RegisterCellAnim(object,24,28,((struct Obj00211 *)p)->f0);
    ARC_TOOL_DeleteHandle(object);
    MI_CpuFill8(&request,0,8);
    request.x=66;request.y=39;request.z=0;request.a=0;request.b=2;
    ((struct Obj00211 *)p)->f224=CLACT_CreateActor((void *)PSEL_GRAPHIC_GetClactBank(((struct Obj00211 *)p)->f14),((struct Obj00211 *)p)->f218,((struct Obj00211 *)p)->f21C,((struct Obj00211 *)p)->f220,&request,0,((struct Obj00211 *)p)->f0);
    CLACT_SetActorAutoAnim(((struct Obj00211 *)p)->f224,1);
    PSEL_SetActorPosition(p,0);
}
