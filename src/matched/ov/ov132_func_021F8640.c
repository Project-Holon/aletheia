/*
 * function: STA_ACTING_Delete
 * address: 0x021F8640
 * packet: pkt_ov132_021F8640
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware display register 0x04000000 read at 0x021F868C.
 * symbols:
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_StopSeqAndUnload 0x02006504 thumb
 *   GFL_USE_ClearPreloadedBgmBuffers 0x02006518 thumb
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   STA_ACTING_DeleteAnimHandle 0x021F9D08 thumb ov132
 *   STA_ACT_SCRIPT_Delete 0x021FAB58 thumb ov132
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   STA_ACT_BUTTON_Delete 0x021FA64C thumb ov132
 *   STA_ACT_AUDIENCE_Delete 0x021FA04C thumb ov132
 *   STA_ACT_LIGHT_DeleteModel 0x021F6F4C thumb ov112
 *   STA_ACT_LIGHT_DeleteUnit 0x021F6C7C thumb ov112
 *   STA_ACT_EFFECT_Delete 0x021F9E94 thumb ov132
 *   STA_ACT_OBJ_Delete 0x021F6A24 thumb ov112
 *   STA_ACT_LIGHT_DeleteBillboardImage 0x021F7120 thumb ov112
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   MUSICAL_MCSS_DeleteActorPool 0x021F4948 thumb ov112
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_02030EAC 0x02030EAC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00675.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_StopSeqAndUnload(void);
extern void GFL_USE_ClearPreloadedBgmBuffers(void);
extern void GXx_SetMasterBrightness_(volatile u16 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void STA_ACTING_DeleteAnimHandle(char *);
extern void STA_ACT_SCRIPT_Delete(char *);
typedef unsigned char  u8;
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern void STA_ACT_BUTTON_Delete(char *);
extern void STA_ACT_AUDIENCE_Delete(u8 *p);
extern void STA_ACT_LIGHT_DeleteModel(u8 *p);
extern void STA_ACT_LIGHT_DeleteUnit(char *p);
extern void STA_ACT_EFFECT_Delete(u8 *p);
extern void STA_ACT_OBJ_Delete(char *p);
extern void STA_ACT_LIGHT_DeleteBillboardImage(char *p);
extern void MUSICAL_MCSS_DeleteRenderObj(int a);
extern void MUSICAL_MCSS_DeleteActorPool(u8 *p);
extern void CLACT_ExitSystem(void);
extern void BILLBOARD_Delete(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
void STA_ACTING_Delete(char *p)
{
    if(((struct Obj00675 *)p)->f2C==1)GFL_USE_CancelChangeAndStopBgm();
    if(((struct Obj00675 *)p)->f28==1)GFL_USE_StopSeqAndUnload();
    if(((struct Obj00675 *)p)->f24==1)GFL_USE_ClearPreloadedBgmBuffers();
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006c,-16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    STA_ACTING_DeleteAnimHandle(p);
    STA_ACT_SCRIPT_Delete(((struct Obj00675 *)p)->fB0);
    if(((struct Obj00675 *)p)->fE0!=0)STRBUF_Delete(((struct Obj00675 *)p)->fE0);
    PRINTSYS_QUE_Clear(((struct Obj00675 *)p)->fE8);
    PRINTSYS_QUE_Delete(((struct Obj00675 *)p)->fE8);
    MSGDATA_Delete(((struct Obj00675 *)p)->fDC);
    BMP_WIN_Delete(((struct Obj00675 *)p)->fD0);
    GF_FONT_Delete(((struct Obj00675 *)p)->fD4);
    TCBL_Destroy(((struct Obj00675 *)p)->fCC);
    STA_ACT_BUTTON_Delete(*(char * *)&((struct Obj00675 *)p)->fA4);
    STA_ACT_AUDIENCE_Delete(((struct Obj00675 *)p)->fB8);
    STA_ACT_LIGHT_DeleteModel(((struct Obj00675 *)p)->f3C);
    STA_ACT_LIGHT_DeleteUnit(((struct Obj00675 *)p)->f90);
    STA_ACT_EFFECT_Delete(((struct Obj00675 *)p)->f6C);
    STA_ACT_OBJ_Delete(((struct Obj00675 *)p)->f54);
    STA_ACT_LIGHT_DeleteBillboardImage(((struct Obj00675 *)p)->f40);
    MUSICAL_MCSS_DeleteRenderObj((int)(((struct Obj00675 *)p)->f34));
    MUSICAL_MCSS_DeleteActorPool(((struct Obj00675 *)p)->f38);
    CLACT_ExitSystem();
    BILLBOARD_Delete(((struct Obj00675 *)p)->fAC);
    G3D_CAMERA_Delete(((struct Obj00675 *)p)->fA8);
    G3D_SYSTEM_Exit();
    func_020403F4(0);
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    func_020403F4(5);
    func_020403F4(7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    func_02030EAC(((struct Obj00675 *)p)->f20);
    ARC_TOOL_DeleteHandle(((struct Obj00675 *)p)->f18);
    func_020307B0(p);
}
