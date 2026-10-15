/*
 * function: PMS_SELECT_GRAPHIC_ProcInit
 * address: 0x021C0134
 * packet: pkt_ov110_021C0134
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   overlay_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PMS_WORD_GetSaveData 0x02024988 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   PMS_SELECT_GRAPHIC_Setup 0x021C0490 thumb ov110
 */
#include "../include/Obj01713.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 overlay_id[];
typedef signed int     s32;
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
extern int func_02034AC4(s32 handle);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *PMS_WORD_GetSaveData(int a0);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *PROCSYS_Create(int a0);
extern void PMS_SELECT_GRAPHIC_Setup(u8 *);
int PMS_SELECT_GRAPHIC_ProcInit(void *owner,int unused,void **input) {
    u8 *p;
    func_02034AC4((unsigned)overlay_id);
    GXx_SetMasterBrightness_((void *)0x0400006c,-16);
    GXx_SetMasterBrightness_((void *)0x0400106c,-16);
    GFL_HEAP_CreateChildHeap(1,81,0x1c000);
    p=PROCSYS_AllocProcWork(owner,176,81);
    MI_CpuFill8(p,0,176);
    ((struct Obj01713 *)p)->f4=81;
    ((struct Obj01713 *)p)->f1C=*input;
    ((struct Obj01713 *)p)->f20=PMS_WORD_GetSaveData((int)(*input));
    *(void ** *)&((struct Obj01713 *)p)->f0=input;
    ((struct Obj01713 *)p)->f58=GF_FONT_Create(23,0,0,0,((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f60=func_02045B38(0,2,146,((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f5C=(void *)PRINTSYS_QUE_Create((void *)(((struct Obj01713 *)p)->f4));
    ((struct Obj01713 *)p)->fAC=PROCSYS_Create(((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f94=255;
    ((struct Obj01713 *)p)->f95=255;
    PMS_SELECT_GRAPHIC_Setup(p);
    return 1;
}
