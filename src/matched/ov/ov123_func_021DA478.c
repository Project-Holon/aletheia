/*
 * function: PDWACC_STATE_ProcInit
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
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   PDWACC_STATE_DestroyHttpConnection 0x021DA45C thumb ov123
 *   PDWACC_DISP_Init 0x021D9958 thumb ov123
 *   PDWACC_MESSAGE_InitSystem 0x021D92CC thumb ov123
 *   PDWACC_STATE_StatePrintIntroMessage 0x021DA308 thumb ov123
 *   PDWACC_STATE_StatePrintResultMessage 0x021DA434 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj02478.h"
#include "../include/Obj03275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov114_id[];
extern int func_02034AC4(int);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u8,u32);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern int GFL_NET_GetRunState(void);
extern u8 *NHTTP_RAP_Create(int,int,int);
extern void DWC_RAP_SetErrorCallback(int,int);
extern void PDWACC_STATE_DestroyHttpConnection(char *);
extern char *PDWACC_DISP_Init(int);
extern u8 *PDWACC_MESSAGE_InitSystem(u32,u32);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void PDWACC_STATE_StatePrintIntroMessage(char *);
extern void PDWACC_STATE_StatePrintResultMessage(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
int PDWACC_STATE_ProcInit(void *a,int unused,char *q)
{
    char *p;
    func_02034AC4((int)ov114_id);
    p=PROCSYS_AllocProcWork(a,0x74,((struct Obj03275 *)q)->f8);
    MI_CpuFill8(p,0,0x74);
    ((struct Obj02478 *)p)->f0=((struct Obj03275 *)q)->f8;
    ((struct Obj02478 *)p)->f1C=GAME_DATA_GetSaveControl(((struct Obj03275 *)q)->f0);
    ((struct Obj02478 *)p)->f20=((struct Obj03275 *)q)->f0;
    ((struct Obj02478 *)p)->f28=func_0200853C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj03275 *)q)->f0));
    if(GFL_NET_GetRunState()) {
        ((struct Obj02478 *)p)->f8=NHTTP_RAP_Create(((struct Obj03275 *)q)->f8,((struct Obj02478 *)p)->f28,((struct Obj03275 *)q)->f4);
        DWC_RAP_SetErrorCallback((int)PDWACC_STATE_DestroyHttpConnection,(int)p);
    }
    ((struct Obj02478 *)p)->fC=PDWACC_DISP_Init(((struct Obj02478 *)p)->f0);
    ((struct Obj02478 *)p)->f10=PDWACC_MESSAGE_InitSystem(((struct Obj02478 *)p)->f0,87);
    WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj02478 *)p)->f0);
    GFL_USE_CancelChangeAndPlayBgm(0x483,0xffff);
    switch(((struct Obj03275 *)q)->fC) {
    case 0: PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintIntroMessage,0x276); break;
    case 1: PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintResultMessage,0x279); break;
    }
    ((struct Obj03275 *)q)->f10=0;
    return 1;
}
