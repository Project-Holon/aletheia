/*
 * function: EGG_DEMO_MAIN_DeleteResources
 * address: 0x021F5CFC
 * packet: pkt_ov215_021F5CFC
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   EGG_DEMO_VIEW_Delete 0x021F67B0 thumb ov215
 *   EGG_DEMO_MENU_Noop 0x021F62C8 thumb ov215
 *   EGG_DEMO_MENU_Delete 0x021F6114 thumb ov215
 *   EGG_DEMO_MAIN_DeleteActors 0x021F5E38 thumb ov215
 *   EGG_DEMO_MAIN_Noop 0x021F5DA8 thumb ov215
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   EGG_DEMO_GRAPHIC_Delete 0x021F6474 thumb ov215
 * Empty 5DA8 still receives both visibly loaded arguments.
 */
#include "../include/Obj05549.h"
typedef unsigned int u32;
struct Node;
struct PrintSys;
extern void EGG_DEMO_VIEW_Delete(char *p);
extern void EGG_DEMO_MENU_Noop(int a0, char *a1);
extern void EGG_DEMO_MENU_Delete(void *unused, char *p);
extern void EGG_DEMO_MAIN_DeleteActors(void *unused, char *p);
extern void EGG_DEMO_MAIN_Noop(int a0, char *a1);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void EGG_DEMO_GRAPHIC_Delete(char *p);
void EGG_DEMO_MAIN_DeleteResources(u32 a,char *p)
{
    EGG_DEMO_VIEW_Delete((char *)(((struct Obj05549 *)p)->f80));
    EGG_DEMO_MENU_Noop(a,p);
    EGG_DEMO_MENU_Delete((void *)a,p);
    EGG_DEMO_MAIN_DeleteActors((void *)a,p);
    EGG_DEMO_MAIN_Noop(a,p);
    func_02030EAC((struct Node *)(((struct Obj05549 *)p)->f28));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj05549 *)p)->fC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj05549 *)p)->fC));
    GF_FONT_Delete((void *)(((struct Obj05549 *)p)->f8));
    EGG_DEMO_GRAPHIC_Delete((char *)(((struct Obj05549 *)p)->f4));
}
