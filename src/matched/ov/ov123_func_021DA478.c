/*
 * function: func_021DA478
 * address: 0x021DA478
 * packet: pkt_ov123_021DA478
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 * symbols:
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021B9800 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   func_021DA45C 0x021DA45C thumb ov123
 *   func_021D9958 0x021D9958 thumb ov123
 *   func_021D92CC 0x021D92CC thumb ov123
 *   func_021DA308 0x021DA308 thumb ov123
 *   func_021DA434 0x021DA434 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj02478.h"
#include "../include/Obj03275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov114_id[];
extern int func_02034AC4(int);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u8,u32);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern int GFL_NET_GetRunState(void);
extern u8 *func_021B9800(int,int,int);
extern void DWC_RAP_SetErrorCallback(int,int);
extern void func_021DA45C(char *);
extern char *func_021D9958(int);
extern u8 *func_021D92CC(u32,u32);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void func_021DA308(char *);
extern void func_021DA434(char *);
extern void func_021DA034(char *,int,int);
int func_021DA478(void *a,int unused,char *q)
{
    char *p;
    func_02034AC4((int)ov114_id);
    p=PROCSYS_AllocProcWork(a,0x74,((struct Obj03275 *)q)->f8);
    MI_CpuFill8(p,0,0x74);
    ((struct Obj02478 *)p)->f0=((struct Obj03275 *)q)->f8;
    ((struct Obj02478 *)p)->f1C=GAME_DATA_GetSaveControl(((struct Obj03275 *)q)->f0);
    ((struct Obj02478 *)p)->f20=((struct Obj03275 *)q)->f0;
    ((struct Obj02478 *)p)->f28=func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj03275 *)q)->f0));
    if(GFL_NET_GetRunState()) {
        ((struct Obj02478 *)p)->f8=func_021B9800(((struct Obj03275 *)q)->f8,((struct Obj02478 *)p)->f28,((struct Obj03275 *)q)->f4);
        DWC_RAP_SetErrorCallback((int)func_021DA45C,(int)p);
    }
    ((struct Obj02478 *)p)->fC=func_021D9958(((struct Obj02478 *)p)->f0);
    ((struct Obj02478 *)p)->f10=func_021D92CC(((struct Obj02478 *)p)->f0,87);
    WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj02478 *)p)->f0);
    GFL_USE_CancelChangeAndPlayBgm(0x483,0xffff);
    switch(((struct Obj03275 *)q)->fC) {
    case 0: func_021DA034(p,(int)func_021DA308,0x276); break;
    case 1: func_021DA034(p,(int)func_021DA434,0x279); break;
    }
    ((struct Obj03275 *)q)->f10=0;
    return 1;
}
