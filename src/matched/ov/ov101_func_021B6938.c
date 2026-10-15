/*
 * function: IRC_COMPATIBLE_ProcInit
 * address: 0x021B6938
 * packet: pkt_ov101_021B6938
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   IRC_COMPATIBLE_StepRunnerInit 0x021B6BE4 thumb ov101
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   COMPATIBLE_IRC_SYS_Create 0x021B6100 thumb ov101
 *   IRC_COMPATIBLE_SetHandler 0x021B6A3C thumb ov101
 *   IRC_COMPATIBLE_HandleEntry 0x021B6A4C thumb ov101
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
#include "../include/Obj04421.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void IRC_COMPATIBLE_StepRunnerInit(u8 *,int);
struct Ctx;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *COMPATIBLE_IRC_SYS_Create(int,int,int,int);
extern void IRC_COMPATIBLE_SetHandler(u8 *,u32);
extern void IRC_COMPATIBLE_HandleEntry(u8 *p, u16 *state);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern const char IRC_COMPATIBLE_SourceFileName[];
int IRC_COMPATIBLE_ProcInit(struct Obj0203159C *a,int b,int c)
{
    u8 *p;
    int handle;
    GFL_HEAP_CreateChildHeap(1,58,0x8000);
    p=PROCSYS_AllocProcWork(a,64,58);
    MI_CpuFill8(p,0,64);
    handle=0;
    ((struct Obj04421 *)p)->f10=c;
    ((struct Obj04421 *)p)->f3C=func_02030734(58,44,0,IRC_COMPATIBLE_SourceFileName,0x119);
    MI_CpuFill8(((struct Obj04421 *)p)->f3C,0,44);
    IRC_COMPATIBLE_StepRunnerInit(p+4,58);
    if(*(int *)((struct Obj04421 *)p)->f10) handle=(int)ICA_ANIME_GetField1C((const struct Ctx *)(*(int *)((struct Obj04421 *)p)->f10));
    ((struct Obj04421 *)p)->f0=COMPATIBLE_IRC_SYS_Create(-1,handle,58,0);
    ((struct Obj04421 *)p)->f34=1;
    IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleEntry);
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    return 1;
}
