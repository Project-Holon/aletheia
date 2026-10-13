/*
 * function: func_021D53D0
 * address: 0x021D53D0
 * packet: pkt_ov123_021D53D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_021D4A64 0x021D4A64 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 */
#include "../include/Obj00772.h"
#include "../include/Obj22940.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Bank;
struct Descriptor;
struct Node;
struct Obj;
struct PrintSys;
struct Rec3;
struct S02031140;
struct S020315D4;
struct TaskMenu;
struct TaskMenuState;
extern u32 WIPE_SYS_EndCheck(void);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void TIME_ICON_Delete(u8 *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_021D4A64(char *);
extern u32 func_020307B0(void *p);
extern int APP_KEYCURSOR_Delete(int a0);
extern void func_020403F4(u32 i);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
int func_021D53D0(void *a,int b,u8 *out,char *p)
{
    int i;
    if(!WIPE_SYS_EndCheck()) return 0;
    for(i=0;i<3;i++) CLACT_DeleteActor(*(void **)(p+i*4+0x2a0));
    CLACT_ReleasePalette((u32)(((struct Obj00772 *)p)->f290));
    CLACT_ReleaseCharacter((u32)(((struct Obj00772 *)p)->f294));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00772 *)p)->f298));
    func_02030EAC(((struct Obj00772 *)p)->f2B0);
    CLACT_DeleteUnit(((struct Obj00772 *)p)->f2AC); CLACT_ExitSystem();
    if(((struct Obj00772 *)p)->f288) { TIME_ICON_Delete(((struct Obj00772 *)p)->f288); ((struct Obj00772 *)p)->f288=0; }
    if(((struct Obj00772 *)p)->f228) PRINTSYS_PrintStreamDelete(((struct Obj00772 *)p)->f228);
    if(((struct Obj00772 *)p)->f238) { APP_TASKMENU_CloseMenu(((struct Obj00772 *)p)->f238); ((struct Obj00772 *)p)->f238=0; }
    func_021D4A64(p);
    ((struct Obj22940 *)out)->f1C8=((struct Obj00772 *)p)->f8;
    func_020307B0(((struct Obj00772 *)p)->f280); func_020307B0(((struct Obj00772 *)p)->f284);
    APP_KEYCURSOR_Delete((int)(((struct Obj00772 *)p)->f22C)); func_020403F4(5);
    PRINTSYS_QUE_Clear(((struct Obj00772 *)p)->f234); PRINTSYS_QUE_Delete(((struct Obj00772 *)p)->f234);
    if(((struct Obj00772 *)p)->f224) BMP_WIN_Delete(((struct Obj00772 *)p)->f224);
    TCBL_Destroy(((struct Obj00772 *)p)->f230); APP_TASKMENU_RES_Delete(((struct Obj00772 *)p)->f254);
    BMP_WIN_Exit(); func_0203F9B4(); func_020315D4(a); func_020306F0(31);
    return 1;
}
