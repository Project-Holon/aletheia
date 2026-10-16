/*
 * function: MICTEST_Create
 * address: 0x02183B60
 * packet: pkt_ov168_02183B60
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: 3159C's live allocator result is consumed; ED4's explicitly loaded heap argument retained; FC4 and 30734 narrowed at caller.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MICTEST_ResetDisplay 0x02183ED4 thumb ov168
 *   MICTEST_SetupVramBanks 0x02183F30 thumb ov168
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_020056A0 0x020056A0 thumb
 *   MICTEST_InitBg 0x0218414C thumb ov168
 *   MICTEST_InitBgTiles 0x021841F8 thumb ov168
 *   MICTEST_CreateWindows 0x021842BC thumb ov168
 *   MICTEST_InitActorSystem 0x02183F6C thumb ov168
 *   MICTEST_CreateActors 0x02183FC4 thumb ov168
 *   MICTEST_InitMic 0x02184398 thumb ov168
 *   MICTEST_InitStepMachine 0x02183D0C thumb ov168
 *   MICTEST_VBlank 0x02183F40 thumb ov168
 *   MICTEST_OnMicEvent 0x021844C8 thumb ov168
 *   MICTEST_StepWipeIn 0x02183D4C thumb ov168
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   d_02184A20 0x02184A20 data a4
 */
#include "../include/Obj02210.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum {OBJECT_SIZE=0x150} Size;
extern const char d_02184A20[];
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void MICTEST_ResetDisplay(int);
extern void MICTEST_SetupVramBanks(void);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
struct Ctx;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020056A0(u32,u32,u32);
extern void MICTEST_InitBg(char *,int);
extern void MICTEST_InitBgTiles(void *,int);
extern void MICTEST_CreateWindows(void **,int);
extern void MICTEST_InitActorSystem(int,u32);
extern void MICTEST_CreateActors(char *,u16);
extern void MICTEST_InitMic(u8 *p, int heap, u32 b, u32 c);
extern void MICTEST_InitStepMachine(int *,int,int);
extern void MICTEST_VBlank(void *unused, char *p);
extern void MICTEST_OnMicEvent(int event, char *p);
extern void MICTEST_StepWipeIn(int a, int *state);
extern void GFL_USE_FadeOutBgm(u32 a);
enum Result {DONE=1};
enum Result MICTEST_Create(void *obj)
{
    u8 *p;
    Size size;
    int result=1;
    GFL_HEAP_CreateChildHeap(1,73,0x70000);
    size=OBJECT_SIZE;
    p=PROCSYS_AllocProcWork(obj,size,73);
    MI_CpuFill8(p,0,size);
    ((struct Obj02210 *)((unsigned)p))->f14C=73;
    MICTEST_ResetDisplay(73);
    MICTEST_SetupVramBanks();
    ((struct Obj02210 *)p)->f140=func_02030734((u16)((struct Obj02210 *)((unsigned)p))->f14C,func_02030CB0(5),0,d_02184A20,0x21d);
    ((struct Obj02210 *)((unsigned)p))->f144=func_02030CBC(5,((struct Obj02210 *)p)->f140);
    ((struct Obj02210 *)((unsigned)p))->f148=func_020056A0((u32)MICTEST_VBlank,(u32)p,1);
    MICTEST_InitBg((char *)p+0xe4,((struct Obj02210 *)((unsigned)p))->f14C);
    MICTEST_InitBgTiles(p+0xe4,((struct Obj02210 *)((unsigned)p))->f14C);
    MICTEST_CreateWindows((void **)(p+0xe4),((struct Obj02210 *)((unsigned)p))->f14C);
    MICTEST_InitActorSystem((int)p,*(u32 *)&((struct Obj02210 *)((unsigned)p))->f14C);
    MICTEST_CreateActors((char *)p,((struct Obj02210 *)((unsigned)p))->f14C);
    MICTEST_InitMic((u8 *)(p+0xf8),((struct Obj02210 *)((unsigned)p))->f14C,(int)MICTEST_OnMicEvent,(int)p);
    MICTEST_InitStepMachine((int *)((unsigned)p+0x130),(int)p,(int)MICTEST_StepWipeIn);
    GFL_USE_FadeOutBgm(10);
    return result;
}
