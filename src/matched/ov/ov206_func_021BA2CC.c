/*
 * function: ZUKAN_INFO_Delete
 * address: 0x021BA2CC
 * packet: pkt_ov206_021BA2CC
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_Hide 0x021BA814 thumb ov206
 *   ZUKAN_INFO_ReleaseActor 0x021BB160 thumb ov206
 *   ZUKAN_INFO_ClearDisplay 0x021BA4CC thumb ov206
 *   ZUKAN_INFO_DeleteFormGfx 0x021BBA7C thumb ov206
 *   ZUKAN_INFO_DeleteIconActors 0x021BB480 thumb ov206
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_INFO_DeleteMainWindows 0x021BB0E4 thumb ov206
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   ZUKAN_INFO_FreeResources 0x021BC008 thumb ov206
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00173.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void ZUKAN_INFO_Hide(void *);
typedef unsigned int   u32;
struct Node;
struct PrintSys;
extern void ZUKAN_INFO_ReleaseActor(char *p, int i);
extern void ZUKAN_INFO_ClearDisplay(char *p);
extern void ZUKAN_INFO_DeleteFormGfx(char *p);
extern void ZUKAN_INFO_DeleteIconActors(char *p);
extern void func_02030EAC(struct Node *n);
extern void ZUKAN_INFO_DeleteMainWindows(char *p);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
struct S;
extern void ZUKAN_INFO_FreeResources(struct S *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 func_020307B0(void *p);
void ZUKAN_INFO_Delete(char *p)
{
    u8 i;
    ZUKAN_INFO_Hide(p);
    ((struct Obj00173 *)p)->f44=0;
    for(i=0;i<2;i++) ZUKAN_INFO_ReleaseActor(p,i);
    if(((struct Obj00173 *)p)->f18==2) ZUKAN_INFO_ClearDisplay(p);
    ZUKAN_INFO_DeleteFormGfx(p);
    ZUKAN_INFO_DeleteIconActors(p);
    func_02030EAC(((struct Obj00173 *)p)->f50);
    ZUKAN_INFO_DeleteMainWindows(p);
    if(((struct Obj00173 *)p)->f40!=0) {
        BG_SYS_FreeTileRun(((struct Obj00173 *)p)->f4E,(u16)((struct Obj00173 *)p)->f3C,(u16)(((struct Obj00173 *)p)->f3C>>16));
        ((struct Obj00173 *)p)->f40=0;
    }
    BG_SYS_FreeTileRun(((struct Obj00173 *)p)->f4E,(u16)((struct Obj00173 *)p)->f34,(u16)(((struct Obj00173 *)p)->f34>>16));
    BG_SYS_FreeTileRun(((struct Obj00173 *)p)->f4D,(u16)((struct Obj00173 *)p)->f30,(u16)(((struct Obj00173 *)p)->f30>>16));
    ZUKAN_INFO_FreeResources((struct S *)p);
    PRINTSYS_QUE_Clear(((struct Obj00173 *)p)->f2C);
    PRINTSYS_QUE_Delete(((struct Obj00173 *)p)->f2C);
    func_020307B0(p);
}
