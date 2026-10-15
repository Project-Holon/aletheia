/*
 * function: EGG_DEMO_MAIN_Create
 * address: 0x021F57E0
 * packet: pkt_ov215_021F57E0
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   EGG_DEMO_MAIN_Init 0x021F5C20 thumb ov215
 *   EGG_DEMO_MAIN_StartFadeOutBgm 0x021F5EB8 thumb ov215
 *   FADE_Start 0x0204E720 arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * Legacy void allocator/31324 returns consumed; preserve visible heap input.
 */
#include "../include/Obj03371.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void EGG_DEMO_MAIN_Init(int a, char *p);
extern int EGG_DEMO_MAIN_StartFadeOutBgm(int,char *);
extern void FADE_Start(u32,int,int,int);
extern void *PROCSYS_Create(int a0);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
int EGG_DEMO_MAIN_Create(void *a,int unused,u32 c)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,143,5<<16);
    p=PROCSYS_AllocProcWork(a,140,143);
    MI_CpuFill8(p,0,140);
    ((struct Obj03371 *)p)->f0=143;
    ((struct Obj03371 *)p)->f10=0;
    p[20]=5;
    ((struct Obj03371 *)p)->f18=0;
    ((struct Obj03371 *)p)->f1C=0;
    ((struct Obj03371 *)p)->f20=0;
    EGG_DEMO_MAIN_Init(c,p);
    EGG_DEMO_MAIN_StartFadeOutBgm(c,p);
    FADE_Start(3,16,16,0);
    ((struct Obj03371 *)p)->f88=(unsigned int)PROCSYS_Create(((struct Obj03371 *)p)->f0);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj03371 *)p)->f0);
    return 1;
}
