/*
 * function: GSYNC_DISP_Init
 * address: 0x021D5D94
 * packet: pkt_ov123_021D5D94
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 * symbols:
 *   ov067_id 0x00000043 data
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   GSYNC_DISP_InitBgLayers 0x021D5F4C thumb ov123
 *   GSYNC_DISP_LoadResources 0x021D614C thumb ov123
 *   GSYNC_DISP_CreatePokeIconActor 0x021D6CD8 thumb ov123
 *   GSYNC_DISP_CreateBackdropActors 0x021D6D5C thumb ov123
 *   GSYNC_DISP_VBlankTask 0x021D60F8 thumb ov123
 *   gGsyncDispAllocSource 0x021DAB68 data a1
 *   gGsyncDispClactParam 0x021DAA9C data a4
 *   gGsyncClactConfig 0x020A1464 data a4
 *   gGsyncDispDisplayConfig 0x021DAA78 data a4
 */
#include "../include/Obj04498.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern const char gGsyncDispAllocSource[];
extern char ov067_id[];
extern const u32 gGsyncDispClactParam[], gGsyncClactConfig[], gGsyncDispDisplayConfig[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
struct Bank;
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16 heapId);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void GSYNC_DISP_InitBgLayers(u8 *);
extern void GSYNC_DISP_LoadResources(u8 *);
extern void GSYNC_DISP_CreatePokeIconActor(u8 *);
extern void GSYNC_DISP_CreateBackdropActors(u8 *);
extern void GSYNC_DISP_VBlankTask(void *,u8 *);
extern void *func_020056A0(void *,void *,int);
u8 *GSYNC_DISP_Init(u32 heap)
{
    u8 *p;
    p=func_02030734(heap,0x4568,1,gGsyncDispAllocSource,0xfe);
    ((struct Obj04498 *)p)->f43C4=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0); BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct Obj04498 *)p)->f43C4);
    CLACT_InitSystem((const struct Cfg *)gGsyncClactConfig,(u32)gGsyncDispClactParam,((struct Obj04498 *)p)->f43C4);
    ((struct Obj04498 *)p)->fC=CLACT_CreateUnit(40,0,((struct Obj04498 *)p)->f43C4);
    BG_SYS_SetVramBanks((const struct DispVram *)gGsyncDispClactParam); func_0203FC28((struct DispConfig *)gGsyncDispDisplayConfig);
    GSYNC_DISP_InitBgLayers(p); GSYNC_DISP_LoadResources(p); GSYNC_DISP_CreatePokeIconActor(p); GSYNC_DISP_CreateBackdropActors(p);
    ((struct Obj04498 *)p)->f10=func_020056A0(GSYNC_DISP_VBlankTask,p,0);
    ((struct Obj04498 *)p)->f455C=200;
    BG_SYS_SetSubVisiblePlanes(31); BG_SYS_SetMainVisiblePlanes(27);
    return p;
}
