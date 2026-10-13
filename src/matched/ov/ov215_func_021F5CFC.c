/*
 * function: func_021F5CFC
 * address: 0x021F5CFC
 * packet: pkt_ov215_021F5CFC
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_021F67B0 0x021F67B0 thumb ov215
 *   func_021F62C8 0x021F62C8 thumb ov215
 *   func_021F6114 0x021F6114 thumb ov215
 *   func_021F5E38 0x021F5E38 thumb ov215
 *   func_021F5DA8 0x021F5DA8 thumb ov215
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021F6474 0x021F6474 thumb ov215
 * Empty 5DA8 still receives both visibly loaded arguments.
 */
#include "../include/Obj05549.h"
typedef unsigned int u32;
struct Node;
struct PrintSys;
extern void func_021F67B0(char *p);
extern void func_021F62C8(int a0, char *a1);
extern void func_021F6114(void *unused, char *p);
extern void func_021F5E38(void *unused, char *p);
extern void func_021F5DA8(int a0, char *a1);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021F6474(char *p);
void func_021F5CFC(u32 a,char *p)
{
    func_021F67B0((char *)(((struct Obj05549 *)p)->f80));
    func_021F62C8(a,p);
    func_021F6114((void *)a,p);
    func_021F5E38((void *)a,p);
    func_021F5DA8(a,p);
    func_02030EAC((struct Node *)(((struct Obj05549 *)p)->f28));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj05549 *)p)->fC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj05549 *)p)->fC));
    GF_FONT_Delete((void *)(((struct Obj05549 *)p)->f8));
    func_021F6474((char *)(((struct Obj05549 *)p)->f4));
}
