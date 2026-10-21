/*
 * file:     mystery_net.c
 * unit:     yes
 * function: MYSTERY_NET_Create, MYSTERY_NET_Delete, MYSTERY_NET_Step, MYSTERY_NET_SetAction, MYSTERY_NET_GetAction, MYSTERY_NET_GetResult, MYSTERY_NET_GetReceivedData, MYSTERY_NET_UpdateWifiError, MYSTERY_NET_Exit, MYSTERY_NET_HandleWifiError, MYSTERY_NET_ShowWifiError, MYSTERY_NET_ShowWifiErrorDw, MYSTERY_NET_NoopHandler, MYSTERY_NET_StartSession, MYSTERY_NET_StopSession, MYSTERY_NET_PollWihStatus, MYSTERY_NET_StartBeacon, MYSTERY_NET_DeleteBeacon, MYSTERY_NET_RunBeacon, MYSTERY_NET_StartIrc, MYSTERY_NET_DeleteIrc, MYSTERY_NET_RunIrc, MYSTERY_NET_RunNdDownload, MYSTERY_NET_EndDownload, MYSTERY_NET_SetNdState, MYSTERY_NET_AbortNd, MYSTERY_NET_InitTask, MYSTERY_NET_ClearTask, MYSTERY_NET_Dispatch, MYSTERY_NET_SetHandler, MYSTERY_NET_IsHandler, MYSTERY_NET_GetBuffer, MYSTERY_NET_GetBufferSize, MYSTERY_NET_IsEqual, MYSTERY_NET_FlagExit, MYSTERY_NET_OnNdAsyncDone, MYSTERY_NET_MarkNdDone, MYSTERY_NET_ParseHexValue, MYSTERY_NET_IsZeroBlock, MYSTERY_NET_GetErrorHookState, MYSTERY_NET_ImportRecords, MYSTERY_NET_BuildPokemonFromRecord
 * address:  0x021DE2A0
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from mystery_net.c at 0x021DE2A0 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021DFBC0 0x021DFBC0 data ov121 a1
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   GFL_NET_ERR_ResetState 0x0200FBA0 thumb
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   DWC_ClearError 0x02059F18 arm
 *   GFL_NET_ERR_WaitLinkClosed 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   GFL_NET_ERR_HaltIfActive 0x0200FA84 thumb
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   WIH_DWC_Create 0x02010360 thumb
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   d_021DFABC 0x021DFABC data a4
 *   GFL_NET_Exit 0x0203CEAC arm
 *   DELIVERY_BEACON_Create 0x021576D0 thumb ov010
 *   DELIVERY_BEACON_Start 0x021578A0 thumb ov010
 *   GAME_LANGUAGE_Code 0x0209DF0C data
 *   DELIVERY_BEACON_Delete 0x02157938 thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   DELIVERY_BEACON_RunStep 0x02157928 thumb ov010
 *   DELIVERY_BEACON_TryComplete 0x02157910 thumb ov010
 *   DELIVERY_IRC_Create 0x02157DD8 thumb ov010
 *   DELIVERY_IRC_Start 0x02157E34 thumb ov010
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   DELIVERY_IRC_Main 0x02157E78 thumb ov010
 *   DELIVERY_IRC_GetResult 0x02157E6C thumb ov010
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   DWC_NdGetFileListAsync 0x021C5C38 arm ov114
 *   DWC_NdGetFileAsync 0x021C5CFC arm ov114
 *   DWC_NdProcess 0x021C5AB8 arm ov114
 *   DWC_NdGetProgress 0x021C5E14 arm ov114
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   d_021DFBD8 0x021DFBD8 data a4
 *   d_021DFBD0 0x021DFBD0 data a4
 *   d_021DFBF8 0x021DFBF8 data a4
 *   d_021DFBEC 0x021DFBEC data a4
 *   d_021DFC00 0x021DFC00 data a4
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 *   d_021DFA8C 0x021DFA8C data a1
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   MYSTERY_NET_BuildPokemonFromRecord 0x021DEFAC thumb ov121
 *   WIH_DWC_PollStatus  0x0201058C  thumb  arm9
 *   SAVE_EVENT_WriteWithDate  0x0202F2AC  thumb  arm9
 *   MSGDATA_AllocString  0x02045EC0  arm  arm9
 *   WIH_DWC_TickTimers  0x02010498  thumb  arm9
 *   GFL_USE_GetRandom  0x020056EC  thumb  arm9
 *   MYSTATUS_GetName  0x020084F4  thumb  arm9
 *   MYSTATUS_GetId  0x02008530  thumb  arm9
 *   MYSTATUS_GetSex  0x02008550  thumb  arm9
 *   GAME_DATA_GetMyStatus        0x02012944  thumb
 *   POKE_TOOL_AddMove            0x0201808C  thumb
 *   POKE_TOOL_CastToBoxParam              0x020185F0  thumb
 *   POKE_TOOL_GetPartyValue      0x02017E1C  thumb
 *   POKE_TOOL_RecalcParam        0x020185C4  thumb
 *   POKE_TOOL_SetAbility         0x02018A00  thumb
 *   POKE_TOOL_SetDefaultMoves    0x02017FA8  thumb
 *   POKE_TOOL_SetPartyValue      0x02017E40  thumb
 *   _u32_div_f                   0x0209C2B0  arm
 *   _ull_mul                     0x0209C054  arm
 *   g0209DF08                    0x0209DF08  data
 *   g0209DF0C                    0x0209DF0C  data
 *   gSpeciesNameBank             0x020A7370  data
 */

#include "../types.h"
#include "../arm9/item.h"

#include "../arm9/gfl_heap_wrap.h"

#define Q(k) (*(u32 *)(q+(k)))
#define W(k) (*(u32 *)(p+(k)))
#include "../version.h"
#include "mystery_net_types.h"
struct Req;
struct MysteryNetRec;

typedef struct { u32 kind;u8 flag,pad;u16 heap;u32 bytes;void *data;u32 lang,align;u8 reserved[96];u32 last;} MysteryNetConfig;

typedef struct MysteryNetDescriptor {
    int kind;
    u16 zero, heap;
    int size;
    void *data;
    int setting;
    int flags;
    u8 pad[0x60];
    int enabled;
} MysteryNetDescriptor;

typedef struct { char pad[0x6e0];u32 flag; } Flag;

typedef enum { NO_DIGIT = -1 } Digit;
#include "../arm9/mi_memory.h"
#include "../arm9/net.h"
struct WihContext;
#include "../arm9/wih_dwc.h"
#include "../arm9/net_err.h"
#include "../arm9/net_state.h"
#include "../arm9/dwc_error.h"
#include "../arm9/bg_sys.h"
struct DeliveryBeaconParam;
struct DeliveryBeacon;
#include "../ov010/delivery_beacon.h"
struct DeliveryIrcParam;
#include "../ov010/delivery_irc.h"
struct DeliveryIrcWork;
#include "../ov009/dwc_rap.h"
#include "../ov114/dwc_nd.h"
#include "../arm9/gf_standard.h"
#include "../arm9/strbuf.h"
extern int MYSTERY_NET_BuildPokemonFromRecord(struct MysteryNetRec *r, void *gs, u16 heap);
void *MYSTERY_NET_Create(void *arg,int heap);
void MYSTERY_NET_Delete(u8 *p);
void MYSTERY_NET_Step(char *p);
void MYSTERY_NET_SetAction(char *p, unsigned action);
int MYSTERY_NET_GetAction(void *p);
void *MYSTERY_NET_GetResult(char *p);
int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
int MYSTERY_NET_UpdateWifiError(void *p);
void MYSTERY_NET_Exit(char *p);
int MYSTERY_NET_HandleWifiError(char *p);
int MYSTERY_NET_ShowWifiError(void *work);
int MYSTERY_NET_ShowWifiErrorDw(void *work);
void MYSTERY_NET_NoopHandler(void);
void MYSTERY_NET_StartSession(void *a, int *state, char *p);
void MYSTERY_NET_StopSession(void *a, int *state, char *p);
void MYSTERY_NET_PollWihStatus(int a, int b, char *c);
void MYSTERY_NET_StartBeacon(void *a,int *state,char *p);
void MYSTERY_NET_DeleteBeacon(void *a, int *state, char *p);
void MYSTERY_NET_RunBeacon(void *a,int b,char *p);
void MYSTERY_NET_StartIrc(void *a, int *state, char *p);
void MYSTERY_NET_DeleteIrc(void *a, int *state, char *p);
void MYSTERY_NET_RunIrc(void *a, int *state, char *p);
void MYSTERY_NET_RunNdDownload(void *task,int *state,char *p);
void MYSTERY_NET_EndDownload(void *a, int *state, char *p);
void MYSTERY_NET_SetNdState(char *p, int *state, int value);
void MYSTERY_NET_AbortNd(u32 p,int a,int *state,int b,int c);
void MYSTERY_NET_InitTask(void *p, int a, void *b);
void MYSTERY_NET_ClearTask(void *p);
void MYSTERY_NET_Dispatch(char *p);
void MYSTERY_NET_SetHandler(u32 *p,void *f);
int MYSTERY_NET_IsHandler(int *p, int value);
void *MYSTERY_NET_GetBuffer(char *p);
int MYSTERY_NET_GetBufferSize(void);
int MYSTERY_NET_IsEqual(int a, int b);
void MYSTERY_NET_FlagExit(void *userArg);
void MYSTERY_NET_OnNdAsyncDone(int a, int b);
void MYSTERY_NET_MarkNdDone(void);
int MYSTERY_NET_ParseHexValue(const signed char *p);
int MYSTERY_NET_IsZeroBlock(const unsigned *p, unsigned size);
int MYSTERY_NET_GetErrorHookState(char *p, int unused, int type);
int MYSTERY_NET_ImportRecords(char *p, void *a, unsigned short b);
extern const char d_021DFBC0[];
extern unsigned d_021DFABC[];
extern u8 GAME_LANGUAGE_Code;
extern char d_021DFBD8[],d_021DFBD0[],d_021DFBF8[],d_021DFBEC[];
extern int d_021DFC00[];
extern const signed char d_021DFA8C[][2];

void *MYSTERY_NET_Create(void *arg,int heap)
{
    char *p;
    p=GFL_HEAP_Alloc(heap,0x17a8,0,d_021DFBC0,315);
    MI_CpuFill8(p,0,0x17a8);
    ((MysteryNetWork *)p)->heapId=heap;
    ((MysteryNetWork *)p)->param=arg;
    MYSTERY_NET_InitTask(p,(sptr)p,MYSTERY_NET_NoopHandler);
    return p;
}

/*
 * Addresses are Black-image addresses.
 */
void MYSTERY_NET_Delete(u8 *p)
{
    MYSTERY_NET_ClearTask(p);
    GFL_HEAP_Free(p);
}

void MYSTERY_NET_Step(char *p) {MYSTERY_NET_Dispatch(p);}

void MYSTERY_NET_SetAction(char *p, unsigned action)
{
    switch (action) {
    case 1:
        if (MYSTERY_NET_IsHandler((int *)p, (sptr)MYSTERY_NET_NoopHandler)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartSession);
        break;
    case 3:
        if (MYSTERY_NET_IsHandler((int *)p, (sptr)MYSTERY_NET_PollWihStatus)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StopSession);
        break;
    case 4:
        if (MYSTERY_NET_IsHandler((int *)p, (sptr)MYSTERY_NET_NoopHandler)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_RunNdDownload);
        break;
    case 5:
        if (MYSTERY_NET_IsHandler((int *)p, (sptr)MYSTERY_NET_RunNdDownload)) ((MysteryNetWork *)p)->nd.done = 1;
        break;
    case 6: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_EndDownload); break;
    case 7: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartBeacon); break;
    case 9: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_DeleteBeacon); break;
    case 10: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartIrc); break;
    case 12: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_DeleteIrc); break;
    case 0: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_NoopHandler); break;
    }
}

int MYSTERY_NET_GetAction(void *p)
{
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_NoopHandler)) return 0;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_StartSession)) return 1;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_PollWihStatus)) return 2;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_StopSession)) return 3;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_RunNdDownload)) return 4;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_EndDownload)) return 6;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_StartBeacon)) return 7;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_RunBeacon)) return 8;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_DeleteBeacon)) return 9;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_StartIrc)) return 10;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_RunIrc)) return 11;
    if (MYSTERY_NET_IsHandler(p, (sptr)MYSTERY_NET_DeleteIrc)) return 12;
    return 0;
}

void *MYSTERY_NET_GetResult(char *p)
{
    return ((MysteryNetWork *)p)->result;
}

int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b)
{
    int s = *(int *)(p + 0x17A4);
    if (s == 1) {
        MI_CpuCopy8(p + 0x7A4, a, b);
        return 1;
    }
    return s;
}

int MYSTERY_NET_UpdateWifiError(void *p)
{
    int result=0;
    if (GFL_NET_GetRunState()) {
        switch (*((unsigned char *)GFL_NET_GetInitParam() + 0x65)) {
        case 0: case 5: result=MYSTERY_NET_ShowWifiError(p); break;
        case 1: result=MYSTERY_NET_HandleWifiError(p); break;
        case 3: result=MYSTERY_NET_ShowWifiErrorDw(p); break;
        case 2: case 4: default: break;
        }
    }
    return result;
}

void MYSTERY_NET_Exit(char *p) {if(*(u8 * *)&((MysteryNetWork *)p)->wihHandle) {WIH_DWC_Delete((struct WihContext *)(*(u8 * *)&((MysteryNetWork *)p)->wihHandle)); *(int *)&((MysteryNetWork *)p)->wihHandle=0;} MYSTERY_NET_SetAction(p,0); GFL_NET_ERR_ResetState();}

int MYSTERY_NET_HandleWifiError(char *p)
{
    int result=0;
    if (GFL_NET_ERR_GetErrorLevel()) {
        switch (*(unsigned *)(GFL_NET_STATE_GetError()+4)) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            if (((MysteryNetWork *)p)->nd.busy==1) return result;
            GFL_NET_STATE_SetWifiError();
            DWC_ClearError();
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_ERR_ShowSimpleScreen();
            GFL_NET_ERR_ResetState();
            result=1; break;
        case 7:
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_HaltIfActive();
            result=3; break;
        case 0: default: break;
        }
    }
    return result;
}

int MYSTERY_NET_ShowWifiError(void *work) {int r=0; if(GFL_NET_ERR_GetErrorLevel()) {GFL_NET_ERR_WaitLinkClosed();GFL_NET_ERR_ShowSimpleScreen();GFL_NET_ERR_ResetState();r=1;} return r;}

int MYSTERY_NET_ShowWifiErrorDw(void *work) {int r=0; if(GFL_NET_ERR_GetErrorLevel()) {GFL_NET_ERR_WaitLinkClosed();GFL_NET_ERR_ShowSimpleScreen();GFL_NET_ERR_ResetState();r=1;} return r;}

/*
 * extent: empty callback followed by zero alignment padding then labelled 021DE61C.
 */
void MYSTERY_NET_NoopHandler(void) {}

void MYSTERY_NET_StartSession(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        GFL_NET_StartSession((GFLNetInitializeStruct *)(struct Req *)d_021DFABC, 0, p);
        BG_SYS_SetSubPlaneVisible(0x10, 0);
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState()) {
            GFL_NET_RefreshWmIconAtTopRight(1, ((MysteryNetWork *)p)->heapId);
            ((MysteryNetWork *)p)->wihHandle = WIH_DWC_Create(4, (void *)(((MysteryNetWork *)p)->heapId));
            GFL_NET_BeaconScanStart();
            *state = 2;
        }
        break;
    case 2:
        BG_SYS_SetSubPlaneVisible(0x10, 1);
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_PollWihStatus);
        break;
    }
}

void MYSTERY_NET_StopSession(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        WIH_DWC_Delete(((MysteryNetWork *)p)->wihHandle);
        *(int *)&((MysteryNetWork *)p)->wihHandle = 0;
        *state = 1;
        break;
    case 1:
        if (GFL_NET_Exit(MYSTERY_NET_FlagExit)) *state = 2;
        else *state = 3;
        break;
    case 2:
        if (((MysteryNetWork *)p)->flag5C) {
            ((MysteryNetWork *)p)->flag5C = 0;
            *state = 3;
        }
        break;
    case 3:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}

void MYSTERY_NET_PollWihStatus(int a, int b, char *c)
{
    WIH_DWC_TickTimers();
    ((MysteryNetWork *)c)->result = (void *)WIH_DWC_PollStatus(0);
}

void MYSTERY_NET_StartBeacon(void *a,int *state,char *p) {MysteryNetConfig cfg;u32 h; switch(*state) {case 0: MI_CpuFill8(&cfg,0,124);cfg.kind=9;cfg.bytes=720;cfg.data=p+1956;cfg.lang=GAME_LANGUAGE_Code;cfg.align=PM_VERSION_MASK;cfg.last=1;cfg.flag=0;cfg.heap=((MysteryNetWork *)p)->heapId;h=(uptr)DELIVERY_BEACON_Create((struct DeliveryBeaconParam *)(&cfg));((MysteryNetWork *)p)->beacon=(void *)h;DELIVERY_BEACON_Start((struct DeliveryBeacon *)h);BG_SYS_SetSubPlaneVisible(16,0);((MysteryNetWork *)p)->recvState=0;*state=1;break;case 1:if(GFL_NET_GetRunState()) {GFL_NET_RefreshWmIconAtTopRight(1,((MysteryNetWork *)p)->heapId);BG_SYS_SetSubPlaneVisible(16,1);*state=2;}break;case 2:MYSTERY_NET_SetHandler(a,MYSTERY_NET_RunBeacon);break;} }

void MYSTERY_NET_DeleteBeacon(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        DELIVERY_BEACON_Delete((void *)(((MysteryNetWork *)p)->beacon));
        *state = 1;
        break;
    case 1:
        if (GFL_NET_IsIdle()) *state = 2;
        break;
    case 2:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}

void MYSTERY_NET_RunBeacon(void *a,int b,char *p) {DELIVERY_BEACON_RunStep((struct DeliveryBeacon *)(*(u8 * *)&((MysteryNetWork *)p)->beacon));if(DELIVERY_BEACON_TryComplete((struct DeliveryBeacon *)(*(u8 * *)&((MysteryNetWork *)p)->beacon))) {((MysteryNetWork *)p)->recvState=1;MYSTERY_NET_SetHandler(a,MYSTERY_NET_DeleteBeacon);}}

void MYSTERY_NET_StartIrc(void *a, int *state, char *p)
{
    MysteryNetDescriptor d;
    switch (*state) {
    case 0:
        MI_CpuFill8(&d, 0, 0x7c);
        d.kind = 9;
        d.size = 0x2d0;
        d.data = p + 0x7a4;
        d.zero = 0;
        d.heap = ((MysteryNetWork *)p)->heapId;
        d.setting = GAME_LANGUAGE_Code;
        d.enabled = 1;
        d.flags = PM_VERSION_MASK;
        ((MysteryNetWork *)p)->irc = DELIVERY_IRC_Create((struct DeliveryIrcParam *)(&d));
        DELIVERY_IRC_Start(((MysteryNetWork *)p)->irc);
        ((MysteryNetWork *)p)->recvState = 0;
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState()) {
            GFL_NET_RefreshWmIconAtTopRight(1, ((MysteryNetWork *)p)->heapId);
            *state = 2;
        }
        break;
    case 2:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_RunIrc);
        break;
    }
}

void MYSTERY_NET_DeleteIrc(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        DELIVERY_IRC_Delete((void *)(((MysteryNetWork *)p)->irc));
        *state = 1;
        break;
    case 1:
        if (GFL_NET_IsIdle()) *state = 2;
        break;
    case 2:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}

void MYSTERY_NET_RunIrc(void *a, int *state, char *p)
{
    int result;
    DELIVERY_IRC_Main(((MysteryNetWork *)p)->irc);
    result = DELIVERY_IRC_GetResult(((MysteryNetWork *)p)->irc);
    if (result != 0) {
        switch (result) {
        case 1: ((MysteryNetWork *)p)->recvState = 1; break;
        case 2:
        case 3: ((MysteryNetWork *)p)->recvState = 2; break;
        }
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_DeleteIrc);
    }
}

void MYSTERY_NET_RunNdDownload(void *task,int *state,char *p)
{
    char *q=p+0x60;
    int i,n,j,valid;
    u32 rnd,t,ratio;
    switch(*state) {
    case 0:
        DWC_RAP_SetErrorHookCallback((int (*)(u32, u32, u32, int))((sptr)MYSTERY_NET_GetErrorHookState),(sptr)q);
        MI_CpuFill8(q,0,0x734);
        Q(0x70c)=0;Q(0x710)=0;Q(0x724)=0;Q(0x728)=(uptr)(p+0x7a4);
        W(0x17a4)=0;
        if(!DWC_NdInitAsync((DWCNdCallback)MYSTERY_NET_OnNdAsyncDone,(char *)d_021DFBD0,(char *)d_021DFBD8)) {
            W(0x17a4)=2;*state=9;
        } else {Q(0x730)=1;MYSTERY_NET_SetNdState(q,state,1);}
        break;
    case 1:
        if(Q(0x710)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,3,state,7,7);}
        else if(!DWC_NdSetAttr(d_021DFBEC,d_021DFBF8,d_021DFBF8)) {
            W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,4,state,9,9);
        } else *state=3;
        break;
    case 3:
        if(!DWC_NdGetFileListAsync(q,0,10)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,4,state,9,9);}
        else MYSTERY_NET_SetNdState(q,state,2);
        break;
    case 2:
        for(i=0;i<10;i++) {
            if(!MYSTERY_NET_IsZeroBlock((const unsigned *)(q+0xb0*i),0xb0)) {
                if(MYSTERY_NET_ParseHexValue((const signed char *)(q+0xb0*i+0x93))&PM_VERSION_MASK)
                    ((Flag *)((uptr)q+(u32)i*4))->flag=1;
                else ((Flag *)((uptr)q+(u32)i*4))->flag=0;
            } else ((Flag *)((uptr)q+(u32)i*4))->flag=0;
        }
        Q(0x714)=0;
        for(i=0;i<10;i++) if(((Flag *)((uptr)q+(u32)i*4))->flag) Q(0x714)++;
        *state=4;break;
    case 4:
        n=Q(0x714);
        if(n==1) {
            for(i=0;i<10;i++) if(((Flag *)((uptr)q+(u32)i*4))->flag) {Q(0x724)=i;break;}
        } else if(n>1) {
            j=0;rnd=GF_STANDARD_Rand();
            if(n) rnd=(u32)(((u64)rnd*(u32)n)>>32);
            for(i=0;i<10;i++) {
                if(((Flag *)((uptr)q+(u32)i*4))->flag) {
                    if(j==rnd) {Q(0x724)=i;break;}
                    j++;
                }
            }
            Q(0x724)=i;
        } else {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,1,state,8,8);break;}
        *state=5;break;
    case 5:
        if(!DWC_NdGetFileAsync(q+Q(0x724)*0xb0,(char *)Q(0x728),0x1000)) {
            W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,4,state,9,9);
        } else {
            Q(0x718)=0;d_021DFC00[1]=0;d_021DFC00[3]=0;Q(0x72c)=0;*state=6;
        }break;
    case 6:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {
            GFL_NET_STATE_SetError(0,0,0,0x3f5);W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,3,state,7,7);
        }
        if(!d_021DFC00[1]) {
            if(Q(0x70c)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,3,state,7,7);break;}
            if(DWC_NdGetProgress((unsigned long *)((u32 *)(q+0x71c)),(unsigned long *)((u32 *)(q+0x720)))==1) {
                ratio=Q(0x71c)*100/Q(0x720);
                if(Q(0x718)!=ratio) Q(0x718)=ratio;
            }
        } else if(d_021DFC00[3]) {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,4,state,9,9);}
        else if(!Q(0x710)) {W(0x17a4)=1;MYSTERY_NET_AbortNd((uptr)q,1,state,8,8);}
        else {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,3,state,8,8);}
        break;
    case 7:DWC_NdCancelAsync();*state=8;break;
    case 8:*state=9;break;
    case 9:Q(0x730)=0;DWC_RAP_SetErrorHookCallback(0,0);MYSTERY_NET_SetHandler(task,MYSTERY_NET_EndDownload);break;
    case 100:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {
            GFL_NET_STATE_SetError(0,0,0,0x3f5);W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,3,state,9,9);
        }
        if(d_021DFC00[1]) {
            d_021DFC00[1]=0;
            if(d_021DFC00[3]) {W(0x17a4)=2;MYSTERY_NET_AbortNd((uptr)q,3,state,9,9);}
            else *state=Q(0x708);
        } else if(Q(0x70c)) Q(0x710)=1;
        break;
    case 200:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f5);*state=Q(0x708);}
        if(d_021DFC00[0]) {d_021DFC00[0]=0;*state=Q(0x708);}
        else if(Q(0x70c)) Q(0x710)=1;
        break;
    }
}

/*
 * extent: Follower 021DEE14 is filed separately and verified.
 */
void MYSTERY_NET_EndDownload(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        if (GFL_NET_Exit(0)) *state = 1;
        else *state = 2;
        break;
    case 1:
        if (GFL_NET_GetRunState() == 0) {
            ((MysteryNetWork *)p)->flag5C = 0;
            *state = 2;
        }
        break;
    case 2:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}

void MYSTERY_NET_SetNdState(char *p, int *state, int value)
{
    d_021DFC00[1] = 0;
    d_021DFC00[3] = 0;
    ((MysteryNetNdContext *)p)->state = value;
    ((MysteryNetNdContext *)p)->timer = 0;
    *state = 100;
}

void MYSTERY_NET_AbortNd(u32 p,int a,int *state,int b,int c) {d_021DFC00[0]=0;d_021DFC00[3]=a;((MysteryNetNdContext *)p)->state=b;((MysteryNetNdContext *)p)->timer=0;*state=200;if(DWC_NdCleanupAsync()==0)*state=c;}

void MYSTERY_NET_InitTask(void *p, int a, void *b)
{
    MI_CpuFill8(p, 0, 0x10);
    ((MysteryNetWork *)p)->handlerArg = (u32)a;
    MYSTERY_NET_SetHandler(p, b);
}

void MYSTERY_NET_ClearTask(void *p) {MI_CpuFill8(p,0,16);}

void MYSTERY_NET_Dispatch(char *p)
{
    if (((MysteryNetWork *)p)->paused == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((MysteryNetWork *)p)->handlerArg);
}

void MYSTERY_NET_SetHandler(u32 *p,void *f) {p[0]=(uptr)f;p[2]=0;}

int MYSTERY_NET_IsHandler(int *p, int value)
{
    return *p == value;
}

void *MYSTERY_NET_GetBuffer(char *p)
{
    return p + 0x14;
}

int MYSTERY_NET_GetBufferSize(void)
{
    return 0x20;
}

int MYSTERY_NET_IsEqual(int a, int b)
{
    return a == b;
}

void MYSTERY_NET_FlagExit(void *userArg)
{
    char *p = userArg;

    ((MysteryNetWork *)p)->flag5C = 1;
}

void MYSTERY_NET_OnNdAsyncDone(int a, int b)
{
    d_021DFC00[1] = 1;
    d_021DFC00[3] = b;
    MYSTERY_NET_MarkNdDone();
}

void MYSTERY_NET_MarkNdDone(void)
{
    d_021DFC00[0] = 1;
}

/*
 * lever: Assign the sentinel before the signed-byte load to retain movs/mvns.
 */
int MYSTERY_NET_ParseHexValue(const signed char *p)
{
    unsigned i;
    Digit digit;
    int result;
    int value;
    result = 0;
    for (;;) {
        digit = NO_DIGIT;
        value = *p;
        for (i = 0; i < 23; i++) {
            if (value == d_021DFA8C[i][0]) {
                digit = d_021DFA8C[i][1];
                break;
            }
        }
        if (digit == -1) break;
        result = (result << 4) + digit;
        p++;
    }
    return result;
}

/*
 * extent: Next follower 021DEF54 has its own file.
 */
int MYSTERY_NET_IsZeroBlock(const unsigned *p, unsigned size)
{
    unsigned i;
    for (i = 0; i < size / 4; i++) {
        if (p[i] != 0) return 0;
    }
    return 1;
}

/*
 * extent: Ends at labelled function 021DEF6C.
 */
int MYSTERY_NET_GetErrorHookState(char *p, int unused, int type)
{
    switch (type) {
    case 3:
    case 5:
    case 6:
        return ((MysteryNetNdContext *)p)->busy;
    }
    return 0;
}

int MYSTERY_NET_ImportRecords(char *p, void *a, unsigned short b)
{
    int count = 0;
    int found = 1;
    int i;
    for (i = 0; i < 253; i++) {
        if (*(unsigned short *)(p + i * 2 + 0xd0) == STRBUF_GetEosChar()) found = 0;
    }
    if (found) count++;
    return count + MYSTERY_NET_BuildPokemonFromRecord((struct MysteryNetRec *)p, a, b);
}

struct MysteryNetRec {
    s32 otIdOrItem;
    u32 originGame;
    u32 personality;
    u16 ribbonFlags;
    u16 ball;
    u16 heldItem;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 language;
    u16 nickname;
    u8 pad20[0x14];
    u8 nature;
    u8 gender;
    u8 abilityMode;
    u8 shinyMode;
    u16 eggLocation;
    u16 metLocation;
    u8 metLevel;
    u8 contestCool;
    u8 contestBeauty;
    u8 contestCute;
    u8 contestSmart;
    u8 contestTough;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 otName;
    u8 pad4C[0xE];
    u8 otGender;
    u8 level;
    u8 isEgg;
    u8 pad5D[3];
    u16 name[0x25];
    u8 pad_AA[2];
    u32 eventDate;
    u16 cardId;
    u8 messageIndex;
    u8 giftType;
};

extern const u32 d_021DFB2C[];
extern u8 g0209DF08;
extern u8 g0209DF0C;
extern void *gSpeciesNameBank;

#include "../arm9/gfl_use.h"
struct GameData;
struct MyStatus;
#include "../arm9/game_data.h"
struct Sub0200852CObj;

#include "../arm9/mystatus.h"
#ifdef __MWERKS__
#define POKE_TOOL_Create POKE_TOOL_Create_hdr
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_Create
void *POKE_TOOL_Create(u16 species, u16 level, u32 id, u32 idHigh, u32 heap);
#endif
struct PokemonParam;
struct BoxPokemon;
struct SaveData;
#include "../arm9/save_event.h"
struct MsgBank;
struct Strbuf;
#include "../arm9/msgdata.h"

static inline int chk1(const struct MysteryNetRec *r)
{
    return r->giftType == 1;
}

static inline int chk2(const struct MysteryNetRec *r)
{
    if (r->giftType != 2)
        return 0;
    if (r->otIdOrItem > 0 && r->otIdOrItem <= ITEM_LAST)
        return r->otIdOrItem;
    return 0;
}

static inline int chk3(const struct MysteryNetRec *r)
{
    if (r->giftType != 3)
        return 0x30;
    if (r->otIdOrItem >= 0x21 && r->otIdOrItem <= 0x26)
        return r->otIdOrItem;
    return 0x30;
}

int MYSTERY_NET_BuildPokemonFromRecord(struct MysteryNetRec *r, void *gs, u16 heap)
{
    int count;
    u8 type;
    u16 t;
    int bad;
    int i;
    void *res;
    void *mon;
    u16 mv[4];
    u8 iv[6];
    u32 k;
    u32 ivs;
    u8 day;
    u32 month;
    u16 year;
    u32 mode;
    u32 gender;
    u64 rnd;
    u32 species;
    u16 level;
    u32 id;
    u64 id64;

    count = 0;
    bad = 1;
    for (i = 0; i < 0x25; i++) {
        if (r->name[i] == STRBUF_GetEosChar())
            bad = 0;
    }
    if (bad)
        count++;
    if (r->cardId >= 0x800)
        count++;
    type = r->giftType;
    if (type == 0 || type >= 4)
        count++;
    switch (type) {
    case 1:
        level = r->level;
        id = r->otIdOrItem;
        species = r->species;
        gender = r->gender;
        mode = r->abilityMode;
        iv[0] = r->iv0;
        iv[1] = r->iv1;
        iv[2] = r->iv2;
        iv[3] = r->iv7;
        iv[4] = r->iv3;
        iv[5] = r->iv6;
        mv[0] = r->mv[0];
        mv[1] = r->mv[1];
        mv[2] = r->mv[2];
        mv[3] = r->mv[3];
        if (!chk1(r)) {
            res = 0;
            goto end;
        }
        if (species > 0x289) {
            res = 0;
            goto end;
        }
        if (species == 0) {
            res = 0;
            goto end;
        }
        if (level > 0x64) {
            res = 0;
            goto end;
        }
        if (r->heldItem > ITEM_LAST) {
            res = 0;
            goto end;
        }
        {
            if (level == 0)
                level = (u16)(GFL_USE_GetRandom(0x64) + 1);
            if (r->otIdOrItem == 0)
                id = MYSTATUS_GetId((struct MyStatus *)GAME_DATA_GetMyStatus(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = GFL_USE_GetRandom(0x20);
            }
            id64 = id;
#ifdef __MWERKS__
            mon = POKE_TOOL_Create((u16)species, level, id, 0, heap);
#else
            mon = POKE_TOOL_Create((u16)species, level, id, heap);
#endif
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)GFL_USE_GetRandom(3);
            switch (mode) {
            case 0:
                i = 0;
                break;
            case 1:
                i = 1;
                break;
            case 2:
                i = 0;
                break;
            case 3:
                i = 2;
                break;
            default:
                res = 0;
                goto end;
            }
            if (r->personality != 0)
                rnd = r->personality;
            else {
                if (r->shinyMode == 0)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 0);
                else if (r->shinyMode == 1)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 2);
                else if (r->shinyMode == 2)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 1);
            }
            POKE_TOOL_SetupPartyParamEx(mon, r->species, level, id64, ivs, rnd);
            POKE_TOOL_SetPartyValue(mon, 6, r->heldItem);
            POKE_TOOL_SetDefaultMoves(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < 0x230) {
                    if (POKE_TOOL_AddMove(mon, m) == 0xffff)
                        POKE_TOOL_PushMove(mon, m);
                }
            }
            if (r->personality == 0 && mode == 2)
                POKE_TOOL_SetAbility(mon, species, r->form);
            POKE_TOOL_SetPartyValue(mon, 0x6f, r->form);
            if (r->ball != 0 && r->ball <= 0x19)
                POKE_TOOL_SetPartyValue(mon, 0x98, r->ball);
            else
                POKE_TOOL_SetPartyValue(mon, 0x98, 4);
            if (r->metLevel != 0)
                POKE_TOOL_SetPartyValue(mon, 0x99, r->metLevel);
            POKE_TOOL_SetPartyValue(mon, 0x13, r->contestCool);
            POKE_TOOL_SetPartyValue(mon, 0x14, r->contestBeauty);
            POKE_TOOL_SetPartyValue(mon, 0x15, r->contestCute);
            POKE_TOOL_SetPartyValue(mon, 0x16, r->contestSmart);
            POKE_TOOL_SetPartyValue(mon, 0x17, r->contestTough);
            POKE_TOOL_SetPartyValue(mon, 0x18, r->contestTough);
            for (k = 0; k < 15; k++) {
                if (r->ribbonFlags & (1 << k))
                    POKE_TOOL_SetPartyValue(mon, d_021DFB2C[k], 1);
            }
            if (r->originGame == 0)
                POKE_TOOL_SetPartyValue(mon, 0x77, g0209DF08);
            else
                POKE_TOOL_SetPartyValue(mon, 0x77, r->originGame);
            if (r->language == 0)
                POKE_TOOL_SetPartyValue(mon, 0xc, g0209DF0C);
            else
                POKE_TOOL_SetPartyValue(mon, 0xc, r->language);
            if (r->nickname == 0) {
                GFL_HEAP_Free(mon);
                res = 0;
                goto end;
            }
            if (r->nickname != STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x74, (uptr)&r->nickname);
            {
                u32 v = r->nature;
                if (v == 0xff)
                    v = (u8)GFL_USE_GetRandom(0x19);
                POKE_TOOL_SetPartyValue(mon, 0x70, v);
            }
            POKE_TOOL_SetPartyValue(mon, 0x95, r->eggLocation);
            POKE_TOOL_SetPartyValue(mon, 0x96, r->metLocation);
            if (r->otName == 0) {
                GFL_HEAP_Free(mon);
                res = 0;
                goto end;
            }
            if (r->otName == STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x8e, (uptr)MYSTATUS_GetName(GAME_DATA_GetMyStatus(gs)));
            else
                POKE_TOOL_SetPartyValue(mon, 0x8e, (uptr)&r->otName);
            {
                u32 v = r->otGender;
                if (v <= 2)
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                else {
                    v = MYSTATUS_GetSex((struct MyStatus *)GAME_DATA_GetMyStatus(gs));
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                }
            }
            if (r->isEgg != 0) {
                void *s;
                POKE_TOOL_SetPartyValue(mon, 0x4c, 1);
                s = MSGDATA_AllocString(gSpeciesNameBank, 0x28a);
                POKE_TOOL_SetPartyValue(mon, 0x73, (uptr)s);
                STRBUF_Delete(s);
                POKE_TOOL_SetPartyValue(mon, 9, 10);
            }
            {
                int w = r->eventDate;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->isEgg ? r->eggLocation : r->metLocation;
                SAVE_EVENT_WriteWithDate((struct SaveData *)POKE_TOOL_CastToBoxParam((struct PokemonParam *)mon), loc, year - 2000, month, day);
            }
            POKE_TOOL_RecalcParam(mon);
            res = 0;
            if (POKE_TOOL_GetPartyValue(mon, 3, 0) != 0)
                GFL_HEAP_Free(mon);
            else
                res = mon;
        }
    end:
        if (res == 0)
            count++;
        else
            GFL_HEAP_Free(res);
        break;
    case 2:
        t = chk2(r);
        if (t == 0)
            count++;
        break;
    case 3:
        t = chk3(r);
        if (t == 0x30)
            count++;
        break;
    }
    return count;
}
