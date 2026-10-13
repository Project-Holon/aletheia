/*
 * function: func_021B6294
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
 *   func_0200A6F8 0x0200A6F8 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_021B9BD0 0x021B9BD0 thumb ov133
 *   func_021B9F24 0x021B9F24 thumb ov133
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_021B7498 0x021B7498 thumb ov133
 *   func_021F5330 0x021F5330 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_0204ED24 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01941.h"
#include "../include/Obj23308.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Big;struct Obj;struct Descriptor;struct Bank;struct Node;
extern void func_020355D8(u8);
extern void func_0200A6F8(struct Big *);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021B9BD0(unsigned char *p);
extern void func_021B9F24(unsigned char *p);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_021B7498(u8 *p);
extern void func_021F5330(int,int);
extern void func_021F51B0(int a);
extern void func_02030EAC(struct Node *);
extern void func_0204ED24(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern u32 func_020307B0(void *p);
void func_021B6294(char *p)
{
    u8 i;
    func_020355D8(1);
    func_0200A6F8(*(struct Big * *)&((struct Obj23308 *)(*(char * *)&((struct Obj01941 *)p)->f4))->f8);
    GFL_USE_CancelChangeAndStopBgm();
    func_021B9BD0((unsigned char *)p);
    func_021B9F24((unsigned char *)p);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f184C);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f1850);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f1854);
    for(i=0;i<=2;i++) CLACT_ReleasePalette(*(u32 *)(p+0x1858+i*4));
    for(i=3;i<=5;i++) CLACT_ReleaseCharacter(*(u32 *)(p+0x1858+i*4));
    for(i=6;i<=8;i++) CLACT_ReleaseCellAnim(*(u32 *)(p+0x1858+i*4));
    if(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC) BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC);
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj01941 *)p)->f1848);
    CLACT_ExitSystem();
    func_021B7498((u8 *)p);
    func_021F5330(*(int *)&((struct Obj01941 *)p)->f187C,((struct Obj01941 *)p)->f1880);
    func_021F51B0(((struct Obj01941 *)p)->f187C);
    func_02030EAC(*(struct Node * *)&((struct Obj01941 *)p)->f8);
    func_0204ED24(((struct Obj01941 *)p)->f188C);
    G3D_CAMERA_Delete(((struct Obj01941 *)p)->f1888);
    G3D_SYSTEM_Exit();
    func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
    func_020403F4(4);func_020403F4(6);func_020403F4(5);func_020403F4(7);
    BMP_WIN_Exit();
    func_0203F9B4();
    func_020307B0(p);
}
