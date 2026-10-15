/*
 * function: func_021F8640
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
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021F9D08 0x021F9D08 thumb ov132
 *   func_021FAB58 0x021FAB58 thumb ov132
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_021FA64C 0x021FA64C thumb ov132
 *   func_021FA04C 0x021FA04C thumb ov132
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F9E94 0x021F9E94 thumb ov132
 *   STA_ACT_OBJ_Delete 0x021F6A24 thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_0204ED24 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
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
extern void func_0207D534(volatile u16 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021F9D08(char *);
extern void func_021FAB58(char *);
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
extern void func_021FA64C(char *);
extern void func_021FA04C(u8 *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F6C7C(char *p);
extern void func_021F9E94(u8 *p);
extern void STA_ACT_OBJ_Delete(char *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *p);
extern void CLACT_ExitSystem(void);
extern void func_0204ED24(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
void func_021F8640(char *p)
{
    if(((struct Obj00675 *)p)->f2C==1)GFL_USE_CancelChangeAndStopBgm();
    if(((struct Obj00675 *)p)->f28==1)GFL_USE_StopSeqAndUnload();
    if(((struct Obj00675 *)p)->f24==1)GFL_USE_ClearPreloadedBgmBuffers();
    func_0207D534((volatile u16 *)0x0400006c,-16);
    func_0207D534((volatile u16 *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    func_021F9D08(p);
    func_021FAB58(((struct Obj00675 *)p)->fB0);
    if(((struct Obj00675 *)p)->fE0!=0)STRBUF_Delete(((struct Obj00675 *)p)->fE0);
    PRINTSYS_QUE_Clear(((struct Obj00675 *)p)->fE8);
    PRINTSYS_QUE_Delete(((struct Obj00675 *)p)->fE8);
    MSGDATA_Delete(((struct Obj00675 *)p)->fDC);
    BMP_WIN_Delete(((struct Obj00675 *)p)->fD0);
    GF_FONT_Delete(((struct Obj00675 *)p)->fD4);
    TCBL_Destroy(((struct Obj00675 *)p)->fCC);
    func_021FA64C(*(char * *)&((struct Obj00675 *)p)->fA4);
    func_021FA04C(((struct Obj00675 *)p)->fB8);
    func_021F6F4C(((struct Obj00675 *)p)->f3C);
    func_021F6C7C(((struct Obj00675 *)p)->f90);
    func_021F9E94(((struct Obj00675 *)p)->f6C);
    STA_ACT_OBJ_Delete(((struct Obj00675 *)p)->f54);
    func_021F7120(((struct Obj00675 *)p)->f40);
    func_021F51B0((int)(((struct Obj00675 *)p)->f34));
    func_021F4948(((struct Obj00675 *)p)->f38);
    CLACT_ExitSystem();
    func_0204ED24(((struct Obj00675 *)p)->fAC);
    G3D_CAMERA_Delete(((struct Obj00675 *)p)->fA8);
    G3D_SYSTEM_Exit();
    func_020403F4(0);
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    func_020403F4(5);
    func_020403F4(7);
    BMP_WIN_Exit();
    func_0203F9B4();
    func_02030EAC(((struct Obj00675 *)p)->f20);
    ARC_TOOL_DeleteHandle(((struct Obj00675 *)p)->f18);
    func_020307B0(p);
}
