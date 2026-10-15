/*
 * function: GURU2_MAIN_ProcInit
 * address: 0x021DE7FC
 * packet: pkt_ov137_021DE7FC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototypes: 0203159C returns live allocated r0 here; 0203D7B0/BC receive visible r0=1.
 * symbols:
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   func_020490F4 0x020490F4 arm
 *   GURU2_MAIN_SetupAll 0x021DF800 thumb ov137
 *   func_020056A0 0x020056A0 thumb
 *   GURU2_MAIN_VBlank 0x021DF7E8 thumb ov137
 *   G3D_UTIL_Create 0x02047CFC arm
 *   GURU2_MAIN_AddBackgroundUnit 0x021E0640 thumb ov137
 *   GURU2_MAIN_AddPlayerUnits 0x021E06E0 thumb ov137
 *   GURU2_MAIN_AddCenterUnit 0x021E04E0 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   GURU2_MAIN_CreateBounceEffectTask 0x021E0DE8 thumb ov137
 *   GURU2_MAIN_CreateSettleEffectTask 0x021E0F20 thumb ov137
 *   GURU2_MAIN_CreateWobbleEffectTask 0x021E104C thumb ov137
 *   GURU2_MAIN_CreateEntranceEffectTask 0x021E11B4 thumb ov137
 *   GURU2_MAIN_CreateScreenFlashTask 0x021E13BC thumb ov137
 *   GURU2_MAIN_CreatePulseEffectTask 0x021E1488 thumb ov137
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   gGuru2SlotAngleTable 0x021E1FA0 data a2
 *   gGuru2MainAllocFileName 0x021E22B8 data a1
 */
#include "../include/Obj02208.h"
#include "../include/Obj08213.h"
#include "../include/Obj23739.h"
#include "../include/Obj23740.h"
#include "../include/Obj23741.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void GURU2_MAIN_SetupAll(char *p);
extern void GURU2_MAIN_AddBackgroundUnit(u8 *);
extern void GURU2_MAIN_AddPlayerUnits(char *p);
extern void GURU2_MAIN_AddCenterUnit(u8 *);
extern void GURU2_MAIN_CreateBounceEffectTask(char *p);
extern void GURU2_MAIN_CreateSettleEffectTask(char *p);
extern void GURU2_MAIN_CreateWobbleEffectTask(char *p);
extern void GURU2_MAIN_CreateEntranceEffectTask(char *p);
extern void GURU2_MAIN_CreateScreenFlashTask(char *p);
extern void GURU2_MAIN_CreatePulseEffectTask(char *p);
extern void *func_020056A0(void (*)(int,void *),void *,u32);
extern void GURU2_MAIN_VBlank(void *arg, char *p);
extern void *G3D_UTIL_Create(u16,u16,u16);
struct Ctx;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern const u16 gGuru2SlotAngleTable[][5];
extern const u8 gGuru2MainAllocFileName[];
int GURU2_MAIN_ProcInit(void *obj,int unused,u8 *q)
{
    u8 *p,*s;
    void *r;
    int i,n,player;
    GFL_NET_SetAutoExit(1);
    GFL_HEAP_CreateChildHeap(1,114,0x80000);
    p=PROCSYS_AllocProcWork(obj,0xdac,114);
    i=0;
    MI_CpuFill8(p,0,0xdac);
    *(u8 * *)&((struct Obj08213 *)q)->f1C=p;
    *(u8 * *)&((struct Obj02208 *)p)->fD8=q;
    ((struct Obj02208 *)p)->fDC=((struct Obj08213 *)q)->f18;
    ((struct Obj02208 *)p)->f24=GAME_DATA_GetMyParty(((struct Obj23740 *)(*(u8 * *)&((struct Obj23739 *)(*(u8 * *)&((struct Obj02208 *)p)->fD8))->f14))->f4);
    ((struct Obj02208 *)p)->fD58=func_020490F4(183,114);
    GURU2_MAIN_SetupAll((char *)p);
    ((struct Obj02208 *)p)->fD9C=func_020056A0((void (*)(int,  void *))GURU2_MAIN_VBlank,p,1);
    ((struct Obj02208 *)p)->fAF4=G3D_UTIL_Create(20,11,114);
    GURU2_MAIN_AddBackgroundUnit(p);GURU2_MAIN_AddPlayerUnits((char *)p);GURU2_MAIN_AddCenterUnit(p);
    n=0;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    s=p+0xe0;
    q=*(u8 * *)&((struct Obj02208 *)p)->fD8;
    for(;i<5;i++) {
        if(((struct Obj08213 *)q)->fC&(1<<i)) {if(i==player) break;n++;}
    }
    ((struct Obj23741 *)s)->f40=gGuru2SlotAngleTable[((struct Obj08213 *)q)->f8][n]<<12;
    r=func_02030734(0x8072,func_02030CB0(32),0,(const char *)gGuru2MainAllocFileName,0x4ec);
    ((struct Obj02208 *)p)->fD94=r;
    ((struct Obj02208 *)p)->fD98=func_02030CBC(32,r);
    GURU2_MAIN_CreateBounceEffectTask((char *)p);GURU2_MAIN_CreateSettleEffectTask((char *)p);GURU2_MAIN_CreateWobbleEffectTask((char *)p);GURU2_MAIN_CreateEntranceEffectTask((char *)p);GURU2_MAIN_CreateScreenFlashTask((char *)p);GURU2_MAIN_CreatePulseEffectTask((char *)p);
    WIPE_SYS_Start(0,1,1,0,8,1,114);
    GFL_NET_SetLoginOption(1);
    return 1;
}
