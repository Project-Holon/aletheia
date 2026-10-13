/*
 * function: func_021D6568
 * address: 0x021D6568
 * packet: pkt_ov120_021D6568
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj00218.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
struct CodeIn;
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0207D63C(void *,int,int,int,int);
void func_021D6568(u8 *p)
{
    int i;
    void *t;
    t=func_020490F4((u32)((void *)144),((struct Obj00218 *)p)->fF4);
    func_02049B68(t,3,4,0,192,((struct Obj00218 *)p)->fF4);
    func_02049B68(t,1,4,0,64,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f8=func_02049740(t,6,7,0,0,((struct Obj00218 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,17,7,0,(u16)(((struct Obj00218 *)p)->f8),0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f0=func_02049740(t,8,4,0,0,((struct Obj00218 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,18,4,0,(u16)(((struct Obj00218 *)p)->f0),0,0,((struct Obj00218 *)p)->fF4);
    func_02049B68(t,1,0,0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f4=func_02049740(t,6,0,0,0,((struct Obj00218 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,12,0,0,(u16)(((struct Obj00218 *)p)->f4),0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f70=(void *)CLACT_RegisterCharacter(t,5,0,1,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f24=(void *)CLACT_RegisterPaletteEx(t,0,1,320,0,1,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->fBC=(void *)CLACT_RegisterCellAnim(t,10,22,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f28=(void *)CLACT_RegisterCharacter(t,7,0,1,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f18=(void *)CLACT_RegisterPaletteEx(t,2,1,256,0,8,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f74=(void *)CLACT_RegisterCellAnim(t,11,23,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f2C=(void *)CLACT_RegisterCharacter(t,7,0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f1C=(void *)CLACT_RegisterPaletteEx(t,2,0,0,0,8,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f78=(void *)CLACT_RegisterCellAnim(t,11,23,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->fF8=BLINK_PALANM_Create(0,16,0,((struct Obj00218 *)p)->fF4);
    BLINK_PALANM_LoadPalettes(((struct Obj00218 *)p)->fF8,t,1,0,16);
    ((struct Obj00218 *)p)->fFC=BLINK_PALANM_Create(0,16,7,((struct Obj00218 *)p)->fF4);
    BLINK_PALANM_LoadPalettes(((struct Obj00218 *)p)->fFC,t,1,0,16);
    ARC_TOOL_DeleteHandle(t);
    t=func_020490F4((u32)((void *)32),((struct Obj00218 *)p)->fF4);
    for(i=0;i<16;i++) {
        *(void **)(p+i*4+0x30)=(void *)CLACT_RegisterCharacter(t,i+1,0,1,((struct Obj00218 *)p)->fF4);
        *(void **)(p+i*4+0x7c)=(void *)CLACT_RegisterCellAnim(t,i*2+17,i*2+18,((struct Obj00218 *)p)->fF4);
    }
    ((struct Obj00218 *)p)->f20=(void *)CLACT_RegisterPaletteEx(t,0,1,0,0,8,((struct Obj00218 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    func_0207D63C((void *)0x04001050,5,24,15,9);
}
