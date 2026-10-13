/*
 * function: PMS_INPUT_VIEW_Create
 * address: 0x021B9A50
 * packet: pkt_ov110_021B9A50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: 9BA4 tail-forwards three live arguments to ARM9 056A0, whose full
 *   body calls 30DA8 and returns its pointer; original 9ABA consumes r0.
 * symbols:
 *   gPmsInputViewHeapSite 0x021C3C20 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   gPmsInputVramBanks 0x021C3714 data a4
 *   func_02030734 0x02030734 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0207D534 0x0207D534 arm
 *   PMS_INPUT_GetTasks 0x021BF7D0 thumb ov110
 *   PMS_INPUT_VIEW_MainTask 0x021B9BAC thumb ov110
 *   func_02030DA8 0x02030DA8 arm
 *   PMS_INPUT_VIEW_VBlankTask 0x021B9BD0 thumb ov110
 *   PMS_INPUT_VIEW_AddVBlankTask 0x021B9BA4 thumb ov110
 *   func_020490F4 0x020490F4 arm
 */
#include "../include/Obj01920.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char gPmsInputViewHeapSite[];
extern const u8 gClActorInitParam[];
extern const u8 gPmsInputVramBanks[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 *PMS_INPUT_GetUiInputModePtr(u8 *);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 PMS_INPUT_GetTasks(u8 *);
extern void PMS_INPUT_VIEW_MainTask(int a, unsigned char *b);
extern void *func_02030DA8(u32,u32,void *,int);
extern void PMS_INPUT_VIEW_VBlankTask(int a, unsigned char *b);
extern void *PMS_INPUT_VIEW_AddVBlankTask(void (*fn)(void *, u8 *), u8 *p, int n);
extern void *func_020490F4(u32 id, u32 heap);
void *PMS_INPUT_VIEW_Create(u8 *context,void *arg) {
    u8 *p;
    int i;
    p=func_02030734(42,0x90,0,gPmsInputViewHeapSite,0xdf);
    if(p!=0) {
        ((struct Obj01920 *)p)->f64=0;
        ((struct Obj01920 *)p)->f7C=0;
        *(u8 * *)&((struct Obj01920 *)p)->f18=context;
        ((struct Obj01920 *)p)->f1C=arg;
        *(u8 * *)&((struct Obj01920 *)p)->f78=PMS_INPUT_GetUiInputModePtr(context);
        CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)gPmsInputVramBanks,42);
        ((struct Obj01920 *)p)->f20=CLACT_CreateUnit(128,0,42);
        func_0203F8F4(42);
        BMP_WIN_Init(42);
        func_0207D534((void *)0x0400006c,-16);
        func_0207D534((void *)0x0400106c,-16);
        ((struct Obj01920 *)p)->f0=func_02030DA8(PMS_INPUT_GetTasks(context),(u32)PMS_INPUT_VIEW_MainTask,p,2);
        ((struct Obj01920 *)p)->f4=PMS_INPUT_VIEW_AddVBlankTask((void (*)(void *, u8 *))PMS_INPUT_VIEW_VBlankTask,p,1);
        for(i=0;i<4;++i) *(void **)(p+8+i*4)=0;
        ((struct Obj01920 *)p)->f70=0;
        p[0x74]=0;
        ((struct Obj01920 *)p)->f84=0;
        ((struct Obj01920 *)p)->f88=0;
        ((struct Obj01920 *)p)->f8C=func_020490F4(43,42);
    }
    return p;
}
