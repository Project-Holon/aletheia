/*
 * function: DUP_FITTING_Delete
 * address: 0x021B6294
 * packet: pkt_ov133_021B6294
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   MUSICAL_SAVE_ClearNewProps 0x0200A6F8 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   DUP_FITTING_DeleteText 0x021B9BD0 thumb ov133
 *   DUP_FITTING_DeleteActors 0x021B9F24 thumb ov133
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   DUP_FITTING_FreeElements 0x021B7498 thumb ov133
 *   MUSICAL_MCSS_FreeRenderObj 0x021F5330 thumb ov112
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01941.h"
#include "../include/Obj23308.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Big;struct Obj;struct Descriptor;struct Bank;struct Node;
extern void func_020355D8(u8);
extern void MUSICAL_SAVE_ClearNewProps(struct Big *);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void DUP_FITTING_DeleteText(unsigned char *p);
extern void DUP_FITTING_DeleteActors(unsigned char *p);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void DUP_FITTING_FreeElements(u8 *p);
extern void MUSICAL_MCSS_FreeRenderObj(int,int);
extern void MUSICAL_MCSS_DeleteRenderObj(int a);
extern void func_02030EAC(struct Node *);
extern void BILLBOARD_Delete(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern u32 func_020307B0(void *p);
void DUP_FITTING_Delete(char *p)
{
    u8 i;
    func_020355D8(1);
    MUSICAL_SAVE_ClearNewProps(*(struct Big * *)&((struct Obj23308 *)(*(char * *)&((struct Obj01941 *)p)->f4))->f8);
    GFL_USE_CancelChangeAndStopBgm();
    DUP_FITTING_DeleteText((unsigned char *)p);
    DUP_FITTING_DeleteActors((unsigned char *)p);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f184C);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f1850);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f1854);
    for(i=0;i<=2;i++) CLACT_ReleasePalette(*(u32 *)(p+0x1858+i*4));
    for(i=3;i<=5;i++) CLACT_ReleaseCharacter(*(u32 *)(p+0x1858+i*4));
    for(i=6;i<=8;i++) CLACT_ReleaseCellAnim(*(u32 *)(p+0x1858+i*4));
    if(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC) BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC);
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj01941 *)p)->f1848);
    CLACT_ExitSystem();
    DUP_FITTING_FreeElements((u8 *)p);
    MUSICAL_MCSS_FreeRenderObj(*(int *)&((struct Obj01941 *)p)->f187C,((struct Obj01941 *)p)->f1880);
    MUSICAL_MCSS_DeleteRenderObj(((struct Obj01941 *)p)->f187C);
    func_02030EAC(*(struct Node * *)&((struct Obj01941 *)p)->f8);
    BILLBOARD_Delete(((struct Obj01941 *)p)->f188C);
    G3D_CAMERA_Delete(((struct Obj01941 *)p)->f1888);
    G3D_SYSTEM_Exit();
    func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
    func_020403F4(4);func_020403F4(6);func_020403F4(5);func_020403F4(7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    func_020307B0(p);
}
