/*
 * function: GSYNC_MENU_ProcInit
 * address: 0x021D5128
 * packet: pkt_ov123_021D5128
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: sole callback blocker ov123 021D5120 filed and verified before
 * caller recheck; ABS32 at +01E0 now resolves through its matched shard.
 * volatile: display register 04001000 read/write at 021D5198/021D519C.
 * interface: 0203159C leaves its allocation result in r0, which is used
 * throughout this caller; its legacy matched definition is void.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020355D8 0x020355D8 arm
 *   GSYNC_MENU_VBlank 0x021D5120 thumb ov123
 *   GSYNC_MENU_InitBgLayers 0x021D424C thumb ov123
 *   GSYNC_MENU_LoadResources 0x021D4884 thumb ov123
 *   GSYNC_MENU_StateSetupButtons 0x021D4A04 thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   d_021DA9F0 0x021DA9F0 data a4
 *   d_021DA680 0x021DA680 data a4
 *   d_021DA658 0x021DA658 data a4
 *   d_021DAA20 0x021DAA20 data a1
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 */
#include "../include/Obj00590.h"
#include "../include/Obj06459.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Config { u32 words[4]; };
extern const struct Config d_021DA680;
extern const u32 d_021DA9F0[], d_021DA658[];
extern const char d_021DAA20[];
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u8,u32);
struct Bank;
struct R;
struct Tcbl;
extern void func_0204363C(u32 swap);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16 heapId);
extern void BMP_WIN_Init(u16);
extern void func_0201DD60(void);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020056A0(void *,void *,int);
extern void GSYNC_MENU_VBlank(void);
extern void GSYNC_MENU_InitBgLayers(char *);
extern void GSYNC_MENU_LoadResources(char *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *,int,int,int,int);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void GSYNC_MENU_ChangeState(char *,void *,int);
extern void GSYNC_MENU_StateSetupButtons(char *);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_020355D8(u8 v);
int GSYNC_MENU_ProcInit(void *a,int b,u8 *q)
{
    char *p;
    int bright;
    int color;
    struct Config cfg;
    GFL_HEAP_CreateChildHeap(1,31,0x18000);
    p=PROCSYS_AllocProcWork(a,0x2b4,31);
    MI_CpuFill8(p,0,0x2b4);
    ((struct Obj00590 *)p)->fC=31;
    ((struct Obj00590 *)p)->f260=((struct Obj06459 *)q)->f4; ((struct Obj00590 *)p)->f264=((struct Obj06459 *)q)->f0;
    func_0204363C(1);
    if(((struct Obj06459 *)q)->f2C8) bright=16; else bright=-16;
    GXx_SetMasterBrightness_((void *)0x0400006c,bright); GXx_SetMasterBrightness_((void *)0x0400106c,bright);
    *(volatile u32 *)0x04001000|=0x10000; GX_DispOn();
    BG_SYS_Create(((struct Obj00590 *)p)->fC); BMP_WIN_Init(((struct Obj00590 *)p)->fC); func_0201DD60();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DA9F0);
    cfg=d_021DA680; func_0203FC28((struct DispConfig *)(&cfg));
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)d_021DA658,(u32)d_021DA9F0,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f2AC=CLACT_CreateUnit(40,0,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f2B0=func_020056A0(GSYNC_MENU_VBlank,p,0);
    GSYNC_MENU_InitBgLayers(p); GSYNC_MENU_LoadResources(p);
    ((struct Obj00590 *)p)->f280=func_02030734(((struct Obj00590 *)p)->fC,0x200,0,d_021DAA20,0x5a6);
    ((struct Obj00590 *)p)->f284=func_02030734(((struct Obj00590 *)p)->fC,0x200,0,d_021DAA20,0x5a7);
    ((struct Obj00590 *)p)->f230=TCBL_Create(((struct Obj00590 *)p)->fC,((struct Obj00590 *)p)->fC,3,0);
    ((struct Obj00590 *)p)->f22C=func_02028590(15,0,1,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f234=PRINTSYS_QUE_Create((void *)(u32)((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f254=APP_TASKMENU_RES_Create(5,9,((struct Obj00590 *)p)->f30,((struct Obj00590 *)p)->f234,((struct Obj00590 *)p)->fC);
    func_0207D63C((void *)0x04001050,4,1,15,4);
    color=0; if(((struct Obj06459 *)q)->f2C8) color=0x7fff;
    WIPE_SYS_Start(0,1,1,(u16)color,6,1,((struct Obj00590 *)p)->fC);
    *(u32 *)&((struct Obj06459 *)q)->f2C8=0; BG_SYS_SetSubVisiblePlanes(31);
    GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateSetupButtons,0x5bf);
    ((struct Obj00590 *)p)->f258=q;
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00590 *)p)->fC); func_020355D8(1);
    return 1;
}
