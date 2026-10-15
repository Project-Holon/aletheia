/*
 * function: func_021D4BFC
 * address: 0x021D4BFC
 * packet: pkt_ov115_021D4BFC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0203159C leaves its allocation in r0, read here despite legacy void.
 * 021D4D38 r2 is explicitly loaded here and retained in the extern.
 * symbols:
 *   d_021D65D0 0x021D65D0 data a1
 *   func_02034714 0x02034714 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021D4D38 0x021D4D38 thumb ov115
 *   func_021D5984 0x021D5984 thumb ov115
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetField1A0 0x0201283C thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   func_021D497C 0x021D497C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 */
#include "../include/Obj01719.h"
#include "../include/Obj04465.h"
#include "../include/Obj22596.h"
#include "../include/Obj22597.h"
#include "../include/Obj22598.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021D65D0[];
extern void func_02034714(const char *,u32,const char *);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u8 *func_021D4D38(u16,u32,int);
struct Big;
struct BigObj;
extern u8 *func_021D5984(u32 heap, u32 bank, u32 mode);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_STATE_SetWifiError(void),GFL_NET_STATE_ClearErrorMode(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void func_021D497C(u8 *);
extern void func_021D5CCC(u8 *,u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
int func_021D4BFC(void *ctx,int unused,u8 *q)
{
    u8 *p;
    if(((struct Obj04465 *)q)->fC==0) func_02034714(d_021D65D0,0,d_021D65D0);
    GFL_HEAP_CreateChildHeap(1,120,0x18000);
    p=PROCSYS_AllocProcWork(ctx,72,120);
    MI_CpuFill8(p,0,72);
    ((struct Obj01719 *)p)->fC=120;
    ((struct Obj01719 *)p)->f44=((struct Obj04465 *)q)->f0;
    ((struct Obj01719 *)p)->f34=func_021D4D38(((struct Obj01719 *)p)->fC,((struct Obj04465 *)q)->f4,((struct Obj04465 *)q)->f8);
    ((struct Obj01719 *)p)->f38=func_021D5984(((struct Obj01719 *)p)->fC,232,((struct Obj04465 *)q)->f8);
    ((struct Obj01719 *)p)->f2C=GAME_DATA_GetSaveControl(((struct Obj04465 *)q)->f0);
    ((struct Obj01719 *)p)->f3C=GAME_DATA_GetField1A0(((struct Obj04465 *)q)->f0);
    WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj01719 *)p)->fC);
    *(u8 * *)&((struct Obj01719 *)p)->f40=q;
    if(GFL_NET_GetRunState()) {
        GFL_NET_STATE_SetWifiError();
        GFL_NET_STATE_ClearErrorMode();
        func_0200FBB0();
        func_0200FBA0();
    }
    WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D497C);
    if(((struct Obj22596 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f4==0) {
        func_021D5CCC(*(u8 * *)&((struct Obj01719 *)p)->f38,35);
        if(((struct Obj22597 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f18==0) GFL_USE_CancelChangeAndPlayBgm(1153,65535);
    } else {
        if(((struct Obj22598 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f18==0) GFL_USE_CancelChangeAndPlayBgm(1155,65535);
    }
    return 1;
}
