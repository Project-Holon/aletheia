/*
 * packet: pkt_ov115_021D5598
 * region: ov115
 * function: WIFILOGIN_DISP_CreateActors
 * address: 0x021D5598
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * status: EXACT
 * lang: c99
 * lever: an enum zero assigned after archive allocation and passed only in full-width outgoing zero slots preserves the independent literal register zeros.
 * checks: fixed one EXACT with all 26 relocations resolved; earlier typed permuter consumed and not repeated.
 * ABI: 49990 fifth argument is explicitly truncated16; B294 result
 *   is consumed by stores and setters despite its legacy void spelling.
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   sub_02049238 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_0207D63C 0x0207D63C arm
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   WIFILOGIN_DISP_ScanlineEffect 0x021D58B4 thumb ov115
 *   PMSI_PARAM_MakeSineTable 0x02024230 thumb
 */
#include "../include/Obj00198.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Rect { s16 x,y; u16 z; u8 kind,mode; };
struct Obj;
typedef signed int     s32;
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void sub_02049238(void *);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void func_0207D63C(void *,int,int,int,int);
extern void *GFL_USE_AddHBlankTask(u32,u32,u32);
extern void WIFILOGIN_DISP_ScanlineEffect(void *,u8 *);
extern void PMSI_PARAM_MakeSineTable(s16 *,u32,u16,int);

void WIFILOGIN_DISP_CreateActors(u8 *p)
{
    enum { Zero=0 } zero;
    u32 res;
    struct Rect a,b;
    res = (u32)ARC_TOOL_CreateHandle((u32)((void *)143), ((struct Obj00198 *)p)->fC);
    zero=Zero;
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)res),0,4,zero,0,((struct Obj00198 *)p)->fC);
    ((struct Obj00198 *)p)->f0 = ARC_UTIL_RegisterObjCharFromHandle((void *)((u32)res),7,4,zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),18,4,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),19,6,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),20,7,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)res),0,0,zero,0,((struct Obj00198 *)p)->fC);
    ((struct Obj00198 *)p)->f4 = ARC_UTIL_RegisterObjCharFromHandle((void *)((u32)res),6,0,zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),15,0,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),16,1,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),17,2,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f990 = CLACT_RegisterCharacter((void *)((u32)res),9,0,1,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f98C = CLACT_RegisterPaletteEx((void *)((u32)res),3,1,0,0,3,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f994 = CLACT_RegisterCellAnim((void *)((u32)res),12,25,((struct Obj00198 *)p)->fC);
    sub_02049238((void *)res);
    a.x=128; a.y=96; a.z=10; a.kind=0; a.mode=2;
    *(struct Obj * *)&((struct Obj00198 *)p)->f99C = CLACT_CreateActor((void *)((struct Obj00198 *)p)->f980,((struct Obj00198 *)p)->f990,((struct Obj00198 *)p)->f98C,((struct Obj00198 *)p)->f994,&a,1,((struct Obj00198 *)p)->fC);
    CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj00198 *)p)->f99C,1);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00198 *)p)->f99C,1);
    b.x=128; b.y=96; b.z=11; b.kind=1; b.mode=2;
    *(struct Obj * *)&((struct Obj00198 *)p)->f9A0 = CLACT_CreateActor((void *)((struct Obj00198 *)p)->f980,((struct Obj00198 *)p)->f990,((struct Obj00198 *)p)->f98C,((struct Obj00198 *)p)->f994,&b,1,((struct Obj00198 *)p)->fC);
    CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj00198 *)p)->f9A0,1);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00198 *)p)->f9A0,1);
    func_0207D63C((void *)0x04000050,4,3,6,16);
    func_0207D63C((void *)0x04001050,8,21,6,16);
    ((struct Obj00198 *)p)->f988 = GFL_USE_AddHBlankTask((u32)WIFILOGIN_DISP_ScanlineEffect,(u32)p,0);
    PMSI_PARAM_MakeSineTable((s16 *)(p+0x9ca),192,1456,6144);
    ((struct Obj00198 *)p)->fB4A = 10;
}
