/*
 * function: func_021BA2CC
 * address: 0x021BA2CC
 * packet: pkt_ov206_021BA2CC
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BB160 0x021BB160 thumb ov206
 *   func_021BA4CC 0x021BA4CC thumb ov206
 *   func_021BBA7C 0x021BBA7C thumb ov206
 *   func_021BB480 0x021BB480 thumb ov206
 *   func_02030EAC 0x02030EAC arm
 *   func_021BB0E4 0x021BB0E4 thumb ov206
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   func_021BC008 0x021BC008 thumb ov206
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00173.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021BA814(void *);
typedef unsigned int   u32;
struct Node;
struct PrintSys;
extern void func_021BB160(char *p, int i);
extern void func_021BA4CC(char *p);
extern void func_021BBA7C(char *p);
extern void func_021BB480(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_021BB0E4(char *p);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
struct S;
extern void func_021BC008(struct S *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 func_020307B0(void *p);
void func_021BA2CC(char *p)
{
    u8 i;
    func_021BA814(p);
    ((struct Obj00173 *)p)->f44=0;
    for(i=0;i<2;i++) func_021BB160(p,i);
    if(((struct Obj00173 *)p)->f18==2) func_021BA4CC(p);
    func_021BBA7C(p);
    func_021BB480(p);
    func_02030EAC(((struct Obj00173 *)p)->f50);
    func_021BB0E4(p);
    if(((struct Obj00173 *)p)->f40!=0) {
        BG_SYS_DeleteHalf(((struct Obj00173 *)p)->f4E,(u16)((struct Obj00173 *)p)->f3C,(u16)(((struct Obj00173 *)p)->f3C>>16));
        ((struct Obj00173 *)p)->f40=0;
    }
    BG_SYS_DeleteHalf(((struct Obj00173 *)p)->f4E,(u16)((struct Obj00173 *)p)->f34,(u16)(((struct Obj00173 *)p)->f34>>16));
    BG_SYS_DeleteHalf(((struct Obj00173 *)p)->f4D,(u16)((struct Obj00173 *)p)->f30,(u16)(((struct Obj00173 *)p)->f30>>16));
    func_021BC008((struct S *)p);
    PRINTSYS_QUE_Clear(((struct Obj00173 *)p)->f2C);
    PRINTSYS_QUE_Delete(((struct Obj00173 *)p)->f2C);
    func_020307B0(p);
}
