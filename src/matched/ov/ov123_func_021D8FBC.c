/*
 * function: GSYNC_STATE_ProcInit
 * address: 0x021D8FBC
 * packet: pkt_ov123_021D8FBC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 * symbols:
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   func_020092EC 0x020092EC thumb
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSendParsedRequest 0x021D87F8 thumb ov123
 *   GSYNC_STATE_StateStoreReceivedMon 0x021D8EC4 thumb ov123
 *   GSYNC_STATE_StatePrintFinalMessage 0x021D88A0 thumb ov123
 *   GSYNC_DISP_Init 0x021D5D94 thumb ov123
 *   GSYNC_MESSAGE_InitSystem 0x021D54F4 thumb ov123
 *   GSYNC_STATE_DestroyHttpConnection 0x021D8F3C thumb ov123
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   gGsyncStateAssertTag 0x021DABA4 data a1
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj01059.h"
#include "../include/Obj03799.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov114_id[];
extern const char gGsyncStateAssertTag[];
extern int func_02034AC4(signed int);
extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u8,u32);
struct Big;
struct BigObj;
struct Sub02009448Obj;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
struct Sub02009210Obj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSendParsedRequest(char *);
extern void GSYNC_STATE_StateStoreReceivedMon(char *);
extern void GSYNC_STATE_StatePrintFinalMessage(char *);
extern u8 *NHTTP_RAP_Create(int,int,int);
extern void DWC_RAP_SetErrorCallback(int,int);
extern u8 *GSYNC_DISP_Init(u32);
extern u8 *GSYNC_MESSAGE_InitSystem(u32,u32);
extern void GSYNC_STATE_DestroyHttpConnection(char *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
int GSYNC_STATE_ProcInit(void *a,int b,char *q)
{
    char *p;
    int value;
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,98,0x88000);
    p=PROCSYS_AllocProcWork(a,0xb0,98);
    MI_CpuFill8(p,0,0xb0);
    ((struct Obj01059 *)p)->f0=98;
    if (!q) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
    if (q) {
        *(char * *)&((struct Obj01059 *)p)->f20=q;
        ((struct Obj01059 *)p)->f2C=((struct Obj03799 *)q)->f4;
        ((struct Obj01059 *)p)->f28=GAME_DATA_GetSaveControl(((struct Obj03799 *)q)->f4);
        value=func_0200853C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj03799 *)q)->f4));
        ((struct Obj01059 *)p)->f24=GAME_DATA_GetBoxManager(((struct Obj03799 *)q)->f4);
        ((struct Obj01059 *)p)->f48=((struct Obj03799 *)q)->f1D0;
        ((struct Obj01059 *)p)->f4C=((struct Obj03799 *)q)->f1D2;
        ((struct Obj01059 *)p)->fAC=func_020092EC((const struct Sub02009210Obj *)func_02009448(((struct Obj01059 *)p)->f28));
        ((struct Obj01059 *)p)->fAF=((struct Obj01059 *)p)->fAC;
        func_02009448(((struct Obj01059 *)p)->f28);
        switch (((struct Obj03799 *)q)->f1C8) {
        case 0:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendParsedRequest,0xa89);
            break;
        case 1:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateStoreReceivedMon,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateStoreReceivedMon,0xa91);
            break;
        case 3:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendParsedRequest,0xa95);
            break;
        case 4:
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StatePrintFinalMessage,0xa98);
            break;
        }
        if (*(int *)&((struct Obj03799 *)q)->f1C8!=4) {
            ((struct Obj01059 *)p)->f10=NHTTP_RAP_Create(98,value,(int)(q+0x54));
            DWC_RAP_SetErrorCallback((int)GSYNC_STATE_DestroyHttpConnection,(int)p);
        }
    }
    ((struct Obj01059 *)p)->f14=GSYNC_DISP_Init(((struct Obj01059 *)p)->f0);
    ((struct Obj01059 *)p)->f18=GSYNC_MESSAGE_InitSystem(((struct Obj01059 *)p)->f0,39);
    WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj01059 *)p)->f0);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj01059 *)p)->f0);
    return 1;
}
