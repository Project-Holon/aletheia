/*
 * file:     mystery_net.c
 * unit:     yes
 * function: MYSTERY_NET_Create, MYSTERY_NET_Delete, MYSTERY_NET_Step, MYSTERY_NET_SetAction, MYSTERY_NET_GetAction, MYSTERY_NET_GetReceivedData, MYSTERY_NET_UpdateWifiError, MYSTERY_NET_Exit, MYSTERY_NET_HandleWifiError, MYSTERY_NET_ShowWifiError, MYSTERY_NET_ShowWifiErrorDw, MYSTERY_NET_NoopHandler, MYSTERY_NET_StartSession, MYSTERY_NET_StopSession, MYSTERY_NET_PollWihStatus, MYSTERY_NET_StartBeacon, MYSTERY_NET_DeleteBeacon, MYSTERY_NET_RunBeacon, MYSTERY_NET_StartIrc, MYSTERY_NET_DeleteIrc, MYSTERY_NET_RunIrc, MYSTERY_NET_RunNdDownload, MYSTERY_NET_EndDownload, MYSTERY_NET_SetNdState, MYSTERY_NET_AbortNd, MYSTERY_NET_InitTask, MYSTERY_NET_ClearTask, MYSTERY_NET_Dispatch, MYSTERY_NET_SetHandler, MYSTERY_NET_IsHandler, MYSTERY_NET_FlagExit, MYSTERY_NET_ParseHexValue, MYSTERY_NET_IsZeroBlock, MYSTERY_NET_GetErrorHookState, MYSTERY_NET_ImportRecords, MYSTERY_NET_BuildPokemonFromRecord
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
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
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
 */

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;
extern unsigned int GFL_HEAP_Free(void *p);

#define Q(k) (*(u32 *)(q+(k)))
#define W(k) (*(u32 *)(p+(k)))
#include "mystery_net_types.h"
struct Req;
struct Rec;

typedef struct { u32 kind;u8 flag,pad;u16 heap;u32 bytes;void *data;u32 lang,align;u8 reserved[96];u32 last;} Config;

typedef struct Descriptor {
    int kind;
    u16 zero, heap;
    int size;
    void *data;
    int setting;
    int flags;
    u8 pad[0x60];
    int enabled;
} Descriptor;

typedef unsigned long long u64;

typedef int s32;

typedef struct { char pad[0x6e0];u32 flag; } Flag;

typedef enum { NO_DIGIT = -1 } Digit;
extern void MI_CpuCopy8(const void *,void *,int);
extern void MI_CpuFill8(void *,int,u32);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int GFL_NET_GetRunState(void);
extern char *GFL_NET_GetInitParam(void);
extern void WIH_DWC_Delete(u8 *);
extern void GFL_NET_ERR_ResetState(void);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 GFL_NET_STATE_GetError(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void DWC_ClearError(void);
extern u32 GFL_NET_ERR_WaitLinkClosed(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void GFL_NET_ERR_HaltIfActive(void);
extern void GFL_NET_StartSession(struct Req *req, unsigned int a2, unsigned int a3);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned, unsigned);
extern u8 *WIH_DWC_Create(int idx, void *heap);
extern void GFL_NET_BeaconScanStart(void);
extern int GFL_NET_Exit(int);
extern void WIH_DWC_TickTimers(void);
extern u32 WIH_DWC_PollStatus(void *key);
extern void *DELIVERY_BEACON_Create(u8 *p);
extern int DELIVERY_BEACON_Start(u32 *);
extern int DELIVERY_BEACON_Delete(void *a0);
extern unsigned GFL_NET_IsIdle(void);
extern void DELIVERY_BEACON_RunStep(u8 *);
extern int DELIVERY_BEACON_TryComplete(u8 *);
extern void *DELIVERY_IRC_Create(u8 *p);
extern int DELIVERY_IRC_Start(void *);
extern int DELIVERY_IRC_Delete(void *a0);
extern void DELIVERY_IRC_Main(u8 *p);
extern unsigned char DELIVERY_IRC_GetResult(char *p);
extern void DWC_RAP_SetErrorHookCallback(int,int);
extern int DWC_NdInitAsync(void (*callback)(int, int), char *gamecd, char *passwd);
extern int DWC_NdSetAttr(char *,char *,char *);
extern int DWC_NdGetFileListAsync(void *,u32,u32);
extern int DWC_NdGetFileAsync(void *,char *,u32);
extern void DWC_NdProcess(void);
extern int DWC_NdGetProgress(u32 *,u32 *);
extern int DWC_NdCancelAsync(void);
extern u32 GF_STANDARD_Rand(void);
extern void GFL_NET_STATE_SetError(int,u32,u32,u32);
extern int DWC_NdCleanupAsync(void);
extern unsigned short STRBUF_GetEosChar(void);
extern int MYSTERY_NET_BuildPokemonFromRecord(struct Rec *r, void *gs, u16 heap);
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
int MYSTERY_NET_ShowWifiError(void *a0);
int MYSTERY_NET_ShowWifiErrorDw(void *a0);
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
void MYSTERY_NET_FlagExit(char *p);
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
    MYSTERY_NET_InitTask(p,(int)p,MYSTERY_NET_NoopHandler);
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
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_NoopHandler)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartSession);
        break;
    case 3:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_PollWihStatus)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StopSession);
        break;
    case 4:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_NoopHandler)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_RunNdDownload);
        break;
    case 5:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_RunNdDownload)) ((MysteryNetWork *)p)->nd.done = 1;
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
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_NoopHandler)) return 0;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StartSession)) return 1;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_PollWihStatus)) return 2;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StopSession)) return 3;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_RunNdDownload)) return 4;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_EndDownload)) return 6;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StartBeacon)) return 7;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_RunBeacon)) return 8;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_DeleteBeacon)) return 9;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StartIrc)) return 10;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_RunIrc)) return 11;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_DeleteIrc)) return 12;
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
        switch (*(unsigned char *)(GFL_NET_GetInitParam()+0x65)) {
        case 0: case 5: result=MYSTERY_NET_ShowWifiError(p); break;
        case 1: result=MYSTERY_NET_HandleWifiError(p); break;
        case 3: result=MYSTERY_NET_ShowWifiErrorDw(p); break;
        case 2: case 4: default: break;
        }
    }
    return result;
}




void MYSTERY_NET_Exit(char *p) {if(*(u8 * *)&((MysteryNetWork *)p)->wihHandle) {WIH_DWC_Delete(*(u8 * *)&((MysteryNetWork *)p)->wihHandle); *(int *)&((MysteryNetWork *)p)->wihHandle=0;} MYSTERY_NET_SetAction(p,0); GFL_NET_ERR_ResetState();}




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



int MYSTERY_NET_ShowWifiError(void *a0) {int r=0; if(GFL_NET_ERR_GetErrorLevel()) {GFL_NET_ERR_WaitLinkClosed();GFL_NET_ERR_ShowSimpleScreen();GFL_NET_ERR_ResetState();r=1;} return r;}



int MYSTERY_NET_ShowWifiErrorDw(void *a0) {int r=0; if(GFL_NET_ERR_GetErrorLevel()) {GFL_NET_ERR_WaitLinkClosed();GFL_NET_ERR_ShowSimpleScreen();GFL_NET_ERR_ResetState();r=1;} return r;}



/*
 * extent: empty callback followed by zero alignment padding then labelled 021DE61C.
 */
void MYSTERY_NET_NoopHandler(void) {}



void MYSTERY_NET_StartSession(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        GFL_NET_StartSession((struct Req *)d_021DFABC, 0, (unsigned)p);
        BG_SYS_SetSubPlaneVisible(0x10, 0);
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState()) {
            GFL_NET_RestartWithDefaultTimeout(1, ((MysteryNetWork *)p)->heapId);
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
        if (GFL_NET_Exit((int)MYSTERY_NET_FlagExit)) *state = 2;
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



void MYSTERY_NET_StartBeacon(void *a,int *state,char *p) {Config cfg;u32 h; switch(*state) {case 0: MI_CpuFill8(&cfg,0,124);cfg.kind=9;cfg.bytes=720;cfg.data=p+1956;cfg.lang=GAME_LANGUAGE_Code;cfg.align=2097152;cfg.last=1;cfg.flag=0;cfg.heap=((MysteryNetWork *)p)->heapId;h=(u32)DELIVERY_BEACON_Create((u8 *)(&cfg));((MysteryNetWork *)p)->beacon=(void *)h;DELIVERY_BEACON_Start((u32 *)h);BG_SYS_SetSubPlaneVisible(16,0);((MysteryNetWork *)p)->recvState=0;*state=1;break;case 1:if(GFL_NET_GetRunState()) {GFL_NET_RestartWithDefaultTimeout(1,((MysteryNetWork *)p)->heapId);BG_SYS_SetSubPlaneVisible(16,1);*state=2;}break;case 2:MYSTERY_NET_SetHandler(a,MYSTERY_NET_RunBeacon);break;} }



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



void MYSTERY_NET_RunBeacon(void *a,int b,char *p) {DELIVERY_BEACON_RunStep(*(u8 * *)&((MysteryNetWork *)p)->beacon);if(DELIVERY_BEACON_TryComplete(*(u8 * *)&((MysteryNetWork *)p)->beacon)) {((MysteryNetWork *)p)->recvState=1;MYSTERY_NET_SetHandler(a,MYSTERY_NET_DeleteBeacon);}}



void MYSTERY_NET_StartIrc(void *a, int *state, char *p)
{
    Descriptor d;
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
        d.flags = 0x200000;
        ((MysteryNetWork *)p)->irc = DELIVERY_IRC_Create((u8 *)(&d));
        DELIVERY_IRC_Start(((MysteryNetWork *)p)->irc);
        ((MysteryNetWork *)p)->recvState = 0;
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState()) {
            GFL_NET_RestartWithDefaultTimeout(1, ((MysteryNetWork *)p)->heapId);
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
        DWC_RAP_SetErrorHookCallback((int)MYSTERY_NET_GetErrorHookState,(int)q);
        MI_CpuFill8(q,0,0x734);
        Q(0x70c)=0;Q(0x710)=0;Q(0x724)=0;Q(0x728)=(u32)(p+0x7a4);
        W(0x17a4)=0;
        if(!DWC_NdInitAsync(MYSTERY_NET_OnNdAsyncDone,d_021DFBD0,d_021DFBD8)) {
            W(0x17a4)=2;*state=9;
        } else {Q(0x730)=1;MYSTERY_NET_SetNdState(q,state,1);}
        break;
    case 1:
        if(Q(0x710)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,7,7);}
        else if(!DWC_NdSetAttr(d_021DFBEC,d_021DFBF8,d_021DFBF8)) {
            W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);
        } else *state=3;
        break;
    case 3:
        if(!DWC_NdGetFileListAsync(q,0,10)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);}
        else MYSTERY_NET_SetNdState(q,state,2);
        break;
    case 2:
        for(i=0;i<10;i++) {
            if(!MYSTERY_NET_IsZeroBlock((const unsigned *)(q+0xb0*i),0xb0)) {
                if(MYSTERY_NET_ParseHexValue((const signed char *)(q+0xb0*i+0x93))&0x200000)
                    ((Flag *)((u32)q+(u32)i*4))->flag=1;
                else ((Flag *)((u32)q+(u32)i*4))->flag=0;
            } else ((Flag *)((u32)q+(u32)i*4))->flag=0;
        }
        Q(0x714)=0;
        for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) Q(0x714)++;
        *state=4;break;
    case 4:
        n=Q(0x714);
        if(n==1) {
            for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) {Q(0x724)=i;break;}
        } else if(n>1) {
            j=0;rnd=GF_STANDARD_Rand();
            if(n) rnd=(u32)(((u64)rnd*(u32)n)>>32);
            for(i=0;i<10;i++) {
                if(((Flag *)((u32)q+(u32)i*4))->flag) {
                    if(j==rnd) {Q(0x724)=i;break;}
                    j++;
                }
            }
            Q(0x724)=i;
        } else {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,1,state,8,8);break;}
        *state=5;break;
    case 5:
        if(!DWC_NdGetFileAsync(q+Q(0x724)*0xb0,(char *)Q(0x728),0x1000)) {
            W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);
        } else {
            Q(0x718)=0;d_021DFC00[1]=0;d_021DFC00[3]=0;Q(0x72c)=0;*state=6;
        }break;
    case 6:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {
            GFL_NET_STATE_SetError(0,0,0,0x3f5);W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,7,7);
        }
        if(!d_021DFC00[1]) {
            if(Q(0x70c)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,7,7);break;}
            if(DWC_NdGetProgress((u32 *)(q+0x71c),(u32 *)(q+0x720))==1) {
                ratio=Q(0x71c)*100/Q(0x720);
                if(Q(0x718)!=ratio) Q(0x718)=ratio;
            }
        } else if(d_021DFC00[3]) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);}
        else if(!Q(0x710)) {W(0x17a4)=1;MYSTERY_NET_AbortNd((u32)q,1,state,8,8);}
        else {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,8,8);}
        break;
    case 7:DWC_NdCancelAsync();*state=8;break;
    case 8:*state=9;break;
    case 9:Q(0x730)=0;DWC_RAP_SetErrorHookCallback(0,0);MYSTERY_NET_SetHandler(task,MYSTERY_NET_EndDownload);break;
    case 100:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {
            GFL_NET_STATE_SetError(0,0,0,0x3f5);W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,9,9);
        }
        if(d_021DFC00[1]) {
            d_021DFC00[1]=0;
            if(d_021DFC00[3]) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,9,9);}
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



void MYSTERY_NET_SetHandler(u32 *p,void *f) {p[0]=(u32)f;p[2]=0;}



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



void MYSTERY_NET_FlagExit(char *p)
{
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
    return count + MYSTERY_NET_BuildPokemonFromRecord((struct Rec *)p, a, b);
}




struct Rec {
    s32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 f1D;
    u16 f1E;
    u8 pad20[0x14];
    u8 f34;
    u8 f35;
    u8 f36;
    u8 f37;
    u16 f38;
    u16 f3A;
    u8 f3C;
    u8 f3D;
    u8 f3E;
    u8 f3F;
    u8 f40;
    u8 f41;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 f4A;
    u8 pad4C[0xE];
    u8 f5A;
    u8 f5B;
    u8 f5C;
    u8 pad5D[3];
    u16 name[0x25];
    u8 pad_AA[2];
    u32 fAC;
    u16 fB0;
    u8 fB2;
    u8 fB3;
};

extern const u32 d_021DFB2C[];
extern u8 g0209DF08;
extern u8 g0209DF0C;
extern void *gSpeciesNameBank;

extern u32 func_020056EC(u32 range);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;

extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *POKE_TOOL_Create(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_SetDefaultMoves(void *p);
extern u32 POKE_TOOL_AddMove(void *p, u32 move);
extern void POKE_TOOL_PushMove(void *p, int move);
extern void POKE_TOOL_SetAbility(void *p, u32 species, u32 arg);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *POKE_TOOL_Dummy(void *p);
extern void SAVE_EVENT_WriteWithDate(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void POKE_TOOL_RecalcParam(void *p);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);

static inline int chk1(const struct Rec *r)
{
    return r->fB3 == 1;
}

static inline int chk2(const struct Rec *r)
{
    if (r->fB3 != 2)
        return 0;
    if (r->f0 > 0 && r->f0 <= 0x272)
        return r->f0;
    return 0;
}

static inline int chk3(const struct Rec *r)
{
    if (r->fB3 != 3)
        return 0x30;
    if (r->f0 >= 0x21 && r->f0 <= 0x26)
        return r->f0;
    return 0x30;
}

int MYSTERY_NET_BuildPokemonFromRecord(struct Rec *r, void *gs, u16 heap)
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
    if (r->fB0 >= 0x800)
        count++;
    type = r->fB3;
    if (type == 0 || type >= 4)
        count++;
    switch (type) {
    case 1:
        level = r->f5B;
        id = r->f0;
        species = r->species;
        gender = r->f35;
        mode = r->f36;
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
        if (r->f10 > 0x272) {
            res = 0;
            goto end;
        }
        {
            if (level == 0)
                level = (u16)(func_020056EC(0x64) + 1);
            if (r->f0 == 0)
                id = func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = func_020056EC(0x20);
            }
            id64 = id;
            mon = POKE_TOOL_Create((u16)species, level, id, 0, heap);
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)func_020056EC(3);
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
            if (r->f8 != 0)
                rnd = r->f8;
            else {
                if (r->f37 == 0)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 0);
                else if (r->f37 == 1)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 2);
                else if (r->f37 == 2)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 1);
            }
            POKE_TOOL_SetupPartyParamEx(mon, r->species, level, id64, ivs, rnd);
            POKE_TOOL_SetPartyValue(mon, 6, r->f10);
            POKE_TOOL_SetDefaultMoves(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < 0x230) {
                    if (POKE_TOOL_AddMove(mon, m) == 0xffff)
                        POKE_TOOL_PushMove(mon, m);
                }
            }
            if (r->f8 == 0 && mode == 2)
                POKE_TOOL_SetAbility(mon, species, r->form);
            POKE_TOOL_SetPartyValue(mon, 0x6f, r->form);
            if (r->fE != 0 && r->fE <= 0x19)
                POKE_TOOL_SetPartyValue(mon, 0x98, r->fE);
            else
                POKE_TOOL_SetPartyValue(mon, 0x98, 4);
            if (r->f3C != 0)
                POKE_TOOL_SetPartyValue(mon, 0x99, r->f3C);
            POKE_TOOL_SetPartyValue(mon, 0x13, r->f3D);
            POKE_TOOL_SetPartyValue(mon, 0x14, r->f3E);
            POKE_TOOL_SetPartyValue(mon, 0x15, r->f3F);
            POKE_TOOL_SetPartyValue(mon, 0x16, r->f40);
            POKE_TOOL_SetPartyValue(mon, 0x17, r->f41);
            POKE_TOOL_SetPartyValue(mon, 0x18, r->f41);
            for (k = 0; k < 15; k++) {
                if (r->fC & (1 << k))
                    POKE_TOOL_SetPartyValue(mon, d_021DFB2C[k], 1);
            }
            if (r->f4 == 0)
                POKE_TOOL_SetPartyValue(mon, 0x77, g0209DF08);
            else
                POKE_TOOL_SetPartyValue(mon, 0x77, r->f4);
            if (r->f1D == 0)
                POKE_TOOL_SetPartyValue(mon, 0xc, g0209DF0C);
            else
                POKE_TOOL_SetPartyValue(mon, 0xc, r->f1D);
            if (r->f1E == 0) {
                GFL_HEAP_Free(mon);
                res = 0;
                goto end;
            }
            if (r->f1E != STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x74, (u32)&r->f1E);
            {
                u32 v = r->f34;
                if (v == 0xff)
                    v = (u8)func_020056EC(0x19);
                POKE_TOOL_SetPartyValue(mon, 0x70, v);
            }
            POKE_TOOL_SetPartyValue(mon, 0x95, r->f38);
            POKE_TOOL_SetPartyValue(mon, 0x96, r->f3A);
            if (r->f4A == 0) {
                GFL_HEAP_Free(mon);
                res = 0;
                goto end;
            }
            if (r->f4A == STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x8e, (u32)func_020084F4(GAME_DATA_GetMyStatus(gs)));
            else
                POKE_TOOL_SetPartyValue(mon, 0x8e, (u32)&r->f4A);
            {
                u32 v = r->f5A;
                if (v <= 2)
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                else {
                    v = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(gs));
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                }
            }
            if (r->f5C != 0) {
                void *s;
                POKE_TOOL_SetPartyValue(mon, 0x4c, 1);
                s = MSGDATA_AllocString(gSpeciesNameBank, 0x28a);
                POKE_TOOL_SetPartyValue(mon, 0x73, (u32)s);
                STRBUF_Delete(s);
                POKE_TOOL_SetPartyValue(mon, 9, 10);
            }
            {
                int w = r->fAC;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->f5C ? r->f38 : r->f3A;
                SAVE_EVENT_WriteWithDate(POKE_TOOL_Dummy(mon), loc, year - 2000, month, day);
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
