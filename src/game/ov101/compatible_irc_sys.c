/*
 * file:     compatible_irc_sys.c
 * unit:     yes
 * function: COMPATIBLE_IRC_SYS_Create, COMPATIBLE_IRC_SYS_Delete, COMPATIBLE_IRC_SYS_StepStartSession, COMPATIBLE_IRC_SYS_StepShutdown, COMPATIBLE_IRC_SYS_StepConnectChild, COMPATIBLE_IRC_SYS_StepSyncTiming, COMPATIBLE_IRC_SYS_IsPartnerReady, COMPATIBLE_IRC_SYS_StepShareValue, COMPATIBLE_IRC_SYS_ResetStep, COMPATIBLE_IRC_SYS_ClearValues, COMPATIBLE_IRC_SYS_SetOwnValue, COMPATIBLE_IRC_SYS_UpdateValueSync, COMPATIBLE_IRC_SYS_SendOwnValue, COMPATIBLE_IRC_SYS_GetValueDifference, COMPATIBLE_IRC_SYS_SendToHandle, COMPATIBLE_IRC_SYS_SendData, COMPATIBLE_IRC_SYS_AddCommandTable, COMPATIBLE_IRC_SYS_DeleteCommandTable, COMPATIBLE_IRC_SYS_SendProfileRequest, COMPATIBLE_IRC_SYS_PollProfileRequest, COMPATIBLE_IRC_SYS_SendProfileAck, COMPATIBLE_IRC_SYS_PollProfileAck, COMPATIBLE_IRC_SYS_StepSendProfile, COMPATIBLE_IRC_SYS_GetPartnerProfile, COMPATIBLE_IRC_SYS_BuildProfile, COMPATIBLE_IRC_SYS_SetPlayerReady, COMPATIBLE_IRC_SYS_StartSessionCallback, COMPATIBLE_IRC_SYS_RecvValueHandler, COMPATIBLE_IRC_SYS_RecvValueAckHandler, COMPATIBLE_IRC_SYS_RecvOwnValueHandler, COMPATIBLE_IRC_SYS_ProfileSyncInit, COMPATIBLE_IRC_SYS_ProfileSyncExit, COMPATIBLE_IRC_SYS_ProfileSyncSendRequest, COMPATIBLE_IRC_SYS_ProfileSyncPollRequest, COMPATIBLE_IRC_SYS_ProfileSyncSendAck, COMPATIBLE_IRC_SYS_ProfileSyncPollAck, COMPATIBLE_IRC_SYS_ProfileSyncStepSend, COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile, COMPATIBLE_IRC_SYS_RecvRequestHandler, COMPATIBLE_IRC_SYS_RecvAckHandler, COMPATIBLE_IRC_SYS_RecvDoneHandler, COMPATIBLE_IRC_SYS_RecvProfileHandler, COMPATIBLE_IRC_SYS_ProfileSyncGetProfileForAid
 * address:  0x021B6100
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from compatible_irc_sys.c at 0x021B6938 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   gCompatibleIrcSysFileName 0x021B7524 data a1
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   gCompatibleIrcSessionParam 0x021B743C data a4
 *   gCompatibleIrcProfileCommands 0x021B741C data a4
 *   gCompatibleIrcRecvBuffer 0x021B7520 data a4
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_SYSTEM_IsSendQueueEntry 0x02039468 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   OS_GetOwnerInfo 0x02087C88 arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GF_STANDARD_GetCachedDate 0x0203F4E4 arm
 *   MATH_CountPopulation 0x02080D24 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 */
struct Req;
struct Entry;
struct Link;
struct OSOwnerInfo;
struct RtcDate;
struct BigObj;
struct Ctx;
struct Rec44;
struct Sub24;
/* Session parameter block handed to GFL_NET_StartSession (copied from ROM data). */
typedef struct NetSessionParam { int words[26]; int context; int tail; } NetSessionParam;

#include "compatible_irc_sys_types.h"

typedef struct Four { int year, month, day, week; } Four;

extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32);
extern u32 GFL_HEAP_Free(void *p);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_StartSession(struct Req *req, u32 transportArg, u32 userArg);
extern int GFL_NET_Exit(int exitCallback);
extern int GFL_NET_StartChangeoverChild(int);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern u32 GFL_NET_IsParentAid(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int GFL_NET_SYSTEM_IsSendQueueEntry(u32,u32);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *,void *);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);
extern u32 MATH_CountPopulation(u32);
extern void MI_CpuCopy8(void *,const void *,unsigned);
extern unsigned short GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern int MYSTATUS_GetSize(void);
void *COMPATIBLE_IRC_SYS_Create(int context,int playerRecords,int heapId,int offline);
void COMPATIBLE_IRC_SYS_Delete(void *sys);
int COMPATIBLE_IRC_SYS_StepStartSession(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepShutdown(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepConnectChild(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepSyncTiming(IrcSys *sys);
int COMPATIBLE_IRC_SYS_IsPartnerReady(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepShareValue(IrcSys *sys,int value);
void COMPATIBLE_IRC_SYS_ResetStep(IrcSys *sys);
void COMPATIBLE_IRC_SYS_ClearValues(IrcSys *sys);
void COMPATIBLE_IRC_SYS_SetOwnValue(IrcSys *sys,int value);
int COMPATIBLE_IRC_SYS_UpdateValueSync(IrcSys *sys);
int COMPATIBLE_IRC_SYS_SendOwnValue(IrcSys *sys);
int COMPATIBLE_IRC_SYS_GetValueDifference(IrcSys *sys);
int COMPATIBLE_IRC_SYS_SendToHandle(IrcSys *sys,u32 commandId,u32 size,u32 data);
u32 COMPATIBLE_IRC_SYS_SendData(IrcSys *sys,u32 commandId,u32 size,u32 data,u8 target,u32 e,u32 f,u32 g);
void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,u32 b,u32 c,u32 d);
void COMPATIBLE_IRC_SYS_DeleteCommandTable(IrcSys *sys,u32 a);
int COMPATIBLE_IRC_SYS_SendProfileRequest(IrcSys *sys,u32 a,u32 b);
int COMPATIBLE_IRC_SYS_PollProfileRequest(IrcSys *sys);
int COMPATIBLE_IRC_SYS_SendProfileAck(IrcSys *sys);
int COMPATIBLE_IRC_SYS_PollProfileAck(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepSendProfile(IrcSys *sys,int resource);
void COMPATIBLE_IRC_SYS_GetPartnerProfile(IrcSys *sys,IrcCompatibleProfile *out);
void COMPATIBLE_IRC_SYS_BuildProfile(void *playerData,IrcCompatibleProfile *out);
void COMPATIBLE_IRC_SYS_SetPlayerReady(IrcSys *sys, int index);
int COMPATIBLE_IRC_SYS_GetRecvBuffer(void);
int COMPATIBLE_IRC_SYS_GetRecvSize(void);
int COMPATIBLE_IRC_SYS_IsEqual(int a, int b);
void COMPATIBLE_IRC_SYS_ClearPartnerReady(IrcSys *sys);
void COMPATIBLE_IRC_SYS_StartSessionCallback(void);
void COMPATIBLE_IRC_SYS_ExitCallback(IrcSys *sys);
void COMPATIBLE_IRC_SYS_RecvValueHandler(unsigned aid,int size,void *data,unsigned char *work);
void COMPATIBLE_IRC_SYS_RecvValueAckHandler(int aid,int size,int data,IrcSys *work,unsigned handle);
void COMPATIBLE_IRC_SYS_RecvOwnValueHandler(unsigned aid,int size,void *data,unsigned char *work,unsigned handle);
void COMPATIBLE_IRC_SYS_ProfileSyncInit(IrcProfileSync *sync, IrcSys *sys, int heapId);
void COMPATIBLE_IRC_SYS_ProfileSyncExit(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncSendRequest(IrcProfileSync *sync,int first,int second);
int COMPATIBLE_IRC_SYS_ProfileSyncPollRequest(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncSendAck(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncPollAck(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncStepSend(IrcProfileSync *sync,int resource);
void COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(IrcProfileSync *sync,IrcCompatibleProfile *out);
void COMPATIBLE_IRC_SYS_RecvRequestHandler(u32 aid,int size,void *data,IrcProfileSync *work,void *handle);
void COMPATIBLE_IRC_SYS_RecvAckHandler(u32 aid,int size,int data,IrcProfileSync *work,void *handle);
void COMPATIBLE_IRC_SYS_RecvDoneHandler(u32 aid,int size,int data,IrcProfileSync *work,void *handle);
void COMPATIBLE_IRC_SYS_RecvProfileHandler(u32 aid, int size, int data, IrcProfileSync *work, u32 handle);
u32 COMPATIBLE_IRC_SYS_ProfileSyncGetProfileForAid(u32 aid,IrcProfileSync *sync);
extern const char gCompatibleIrcSysFileName[];
extern const NetSessionParam gCompatibleIrcSessionParam;
extern const u32 gCompatibleIrcProfileCommands[];
extern char gCompatibleIrcRecvBuffer[];

void *COMPATIBLE_IRC_SYS_Create(int context,int playerRecords,int heapId,int offline) {
 IrcSys *sys;
 sys=GFL_HEAP_Alloc(heapId,0x8c,0,gCompatibleIrcSysFileName,0x113);
 MI_CpuFill8((void *)sys,0,0x8c);
 sys->context=context;
 sys->heapId=heapId;
 sys->sessionReady=0;
 sys->offline=offline;
 sys->playerRecords=(void *)playerRecords;
 return sys;
}

void COMPATIBLE_IRC_SYS_Delete(void *sys) { GFL_HEAP_Free(sys); }

int COMPATIBLE_IRC_SYS_StepStartSession(IrcSys *sys) {
 NetSessionParam config;
 if(sys->offline!=0) return 1;
 switch(sys->step) {
 case 0:
  if(GFL_NET_GetRunState()!=0) { sys->step=2; }
  else {
   config=gCompatibleIrcSessionParam;
   config.context=sys->context;
   GFL_NET_StartSession((struct Req *)(&config),(u32)COMPATIBLE_IRC_SYS_StartSessionCallback,(int)sys);
  }
  sys->step=1;
  break;
 case 1:
  if(GFL_NET_GetRunState()!=0) sys->step=2;
  break;
 case 2:
  COMPATIBLE_IRC_SYS_ProfileSyncInit(&sys->profileSync,sys,sys->heapId);
  sys->sessionReady=1;
  sys->step=3;
  break;
 case 3:
  sys->step=0;
  return 1;
 }
 return 0;
}

int COMPATIBLE_IRC_SYS_StepShutdown(IrcSys *sys)
{
    if (sys->offline != 0)
        return 1;
    switch (sys->step) {
    case 0:
        if (sys->sessionReady != 0) {
            COMPATIBLE_IRC_SYS_ProfileSyncExit(&sys->profileSync);
            sys->sessionReady = 0;
        }
        sys->exitDone = 0;
        sys->step = 1;
        break;
    case 1:
        if (GFL_NET_Exit((int)COMPATIBLE_IRC_SYS_ExitCallback) != 0)
            sys->step = 2;
        else
            sys->step = 3;
        break;
    case 2:
        if (sys->exitDone != 0)
            sys->step = 3;
        break;
    case 3:
        sys->step = 0;
        return 1;
    }
    return 0;
}

int COMPATIBLE_IRC_SYS_StepConnectChild(IrcSys *sys)
{
    if (sys->offline != 0) return 1;
    switch(sys->step) {
    case 0:
        GFL_NET_StartChangeoverChild(0);
        sys->step = 1;
        sys->connecting = 1;
        sys->partnerReady = 0;
        sys->readyMask = 0;
        break;
    case 1:
        if(sys->partnerReady != 0) {
            sys->connecting = 0;
            sys->step = 2;
        }
        break;
    case 2:
        sys->step = 0;
        return 1;
    }
    return 0;
}

int COMPATIBLE_IRC_SYS_StepSyncTiming(IrcSys *sys)
{
    if(sys->offline) return 1;
    switch(sys->step) {
    case 0:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),14,13);
        sys->step=1;
        break;
    case 1:
        if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),14,13)) sys->step=2;
        break;
    case 2:
        sys->step=0;
        return 1;
    }
    return 0;
}

int COMPATIBLE_IRC_SYS_IsPartnerReady(IrcSys *sys) { if(sys->offline) return 1; return sys->partnerReady; }

int COMPATIBLE_IRC_SYS_StepShareValue(IrcSys *sys,int value)
{
    int i;
    if(sys->offline) return 1;
    switch(sys->step) {
    case 0:
        sys->valueAckReceived=0;
        if(COMPATIBLE_IRC_SYS_SendToHandle(sys,0xD00,4,(unsigned int)(&value))) sys->step=1;
        break;
    case 1:
        if(GFL_NET_IsParentAid()) {
            for(i=0;i<2;i++) { if(value != sys->receivedValue[i]) break; }
            if(i == 2) sys->step=2;
        } else sys->step=3;
        break;
    case 2:
        if(COMPATIBLE_IRC_SYS_SendToHandle(sys,0xD01,4,(unsigned int)(&value))) sys->step=4;
        break;
    case 3:
        if(sys->valueAckReceived) sys->step=4;
        break;
    case 4:
        sys->step=0;
        return 1;
    }
    return 0;
}

void COMPATIBLE_IRC_SYS_ResetStep(IrcSys *sys) { sys->step=0; }

void COMPATIBLE_IRC_SYS_ClearValues(IrcSys *sys) { sys->partnerValue=0; sys->ownValue=0; }

void COMPATIBLE_IRC_SYS_SetOwnValue(IrcSys *sys,int value) { sys->ownValue=value; }

int COMPATIBLE_IRC_SYS_UpdateValueSync(IrcSys *sys)
{
    u16 old;
    if (sys->offline) return 1;
    old = sys->syncCounter;
    sys->syncCounter += 1;
    if (old > 180) {
        sys->syncCounter = 0;
        if (!GFL_NET_SYSTEM_IsSendQueueEntry(0xD02,GFL_NET_GetHandleNetID((void *)GFL_NET_HANDLE_GetCurrentHandle())))
            return COMPATIBLE_IRC_SYS_SendOwnValue(sys);
    }
    return 0;
}

int COMPATIBLE_IRC_SYS_SendOwnValue(IrcSys *sys)
{
    unsigned int id;
    u8 other;
    if(sys->offline) return 1;
    id=GFL_NET_GetHandleNetID((void *)GFL_NET_HANDLE_GetCurrentHandle());
    other=(id == 0);
    if(GFL_NET_SYSTEM_IsSendQueueEntry(0xD02,id) == 0) {
        return COMPATIBLE_IRC_SYS_SendData(sys,0xD02,4,(u32)&sys->ownValue,other,0,0,1);
    } else {
        return 0;
    }
}

int COMPATIBLE_IRC_SYS_GetValueDifference(IrcSys *sys) { if(sys->offline) return 0; return sys->ownValue-sys->partnerValue; }

/*
 * note: trailing two zero alignment bytes. Extern b/c widened because
 *       caller forwards full words without callee's u16 truncation pairs.
 */
int COMPATIBLE_IRC_SYS_SendToHandle(IrcSys *sys,u32 commandId,u32 size,u32 data) {
    if(sys->offline!=0) return 1;
    return GFL_NET_SendToHandle((struct Entry *)GFL_NET_HANDLE_GetCurrentHandle(),commandId,size,data);
}

u32 COMPATIBLE_IRC_SYS_SendData(IrcSys *sys,u32 commandId,u32 size,u32 data,u8 target,u32 e,u32 f,u32 g) {
    if(sys->offline!=0) return 1;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),target,commandId,size,data,e,f,g);
}

/*
 * note: trailing two zero alignment bytes.
 */
void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,u32 b,u32 c,u32 d) {
    if(sys->offline==0) GFL_NET_COMMAND_AddCommandTable(a,b,c,d);
}

void COMPATIBLE_IRC_SYS_DeleteCommandTable(IrcSys *sys,u32 a) {
    if(sys->offline==0) GFL_NET_COMMAND_DeleteCommandTable(a);
}

int COMPATIBLE_IRC_SYS_SendProfileRequest(IrcSys *sys,u32 a,u32 b) {
    if(sys->offline!=0) return 1;
    return COMPATIBLE_IRC_SYS_ProfileSyncSendRequest(&sys->profileSync,a,b);
}

int COMPATIBLE_IRC_SYS_PollProfileRequest(IrcSys *sys) {
    if(sys->offline!=0) return 1;
    return COMPATIBLE_IRC_SYS_ProfileSyncPollRequest(&sys->profileSync);
}

int COMPATIBLE_IRC_SYS_SendProfileAck(IrcSys *sys) {
    if(sys->offline!=0) return 1;
    return COMPATIBLE_IRC_SYS_ProfileSyncSendAck(&sys->profileSync);
}

int COMPATIBLE_IRC_SYS_PollProfileAck(IrcSys *sys) { if(sys->offline) return 1; return COMPATIBLE_IRC_SYS_ProfileSyncPollAck(&sys->profileSync); }

int COMPATIBLE_IRC_SYS_StepSendProfile(IrcSys *sys,int resource) { if(sys->offline) return 1; return COMPATIBLE_IRC_SYS_ProfileSyncStepSend(&sys->profileSync,resource); }

void COMPATIBLE_IRC_SYS_GetPartnerProfile(IrcSys *sys,IrcCompatibleProfile *out) { if(!sys->offline) COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(&sys->profileSync,out); }

/*
 * lever: pack the words with unsigned left/right shift pairs; u8 casts
 *   keep separate truncation shifts and add eight bytes.
 */
void COMPATIBLE_IRC_SYS_BuildProfile(void *playerData,IrcCompatibleProfile *out)
{
    u8 ownerInfo[0x54];
    Four date;
    void *sub;
    void *record;
    int flag;
    OS_GetOwnerInfo((struct OSOwnerInfo *)(&ownerInfo));
    sub=GAMESYSTEM_GetGameData(playerData);
    playerData=GAME_DATA_GetMyStatus(sub);
    out->birthMonth=ownerInfo[2];
    out->birthDay=ownerInfo[3];
    MYSTATUS_Copy(playerData,out->myStatus);
    record=POKEPARTY_GetMember(GAME_DATA_GetMyParty(sub),0);
    flag=0;
    out->leadSpecies=POKE_TOOL_GetPartyValue(record,5,0);
    out->leadType2=POKE_TOOL_GetPartyValue(record,111,0);
    out->leadType1=POKE_TOOL_GetPartyValue(record,110,0);
    out->leadNature=POKE_TOOL_GetPartyValue(record,76,0);
    GF_STANDARD_GetCachedDate((struct RtcDate *)(&date));
    if(date.day == 14) flag=1;
    out->isDay14=(u8)flag;
    out->packedDate=((u32)date.year << 24) | (((u32)date.month << 24) >> 8) | (((u32)date.day << 24) >> 16) | date.week;
}

void COMPATIBLE_IRC_SYS_SetPlayerReady(IrcSys *sys, int index)
{
    sys->readyMask |= 1 << index;
    if (MATH_CountPopulation(sys->readyMask) >= 2)
        sys->partnerReady = 1;
}

int COMPATIBLE_IRC_SYS_GetRecvBuffer(void) { return (int)gCompatibleIrcRecvBuffer; }

int COMPATIBLE_IRC_SYS_GetRecvSize(void) { return 4; }

int COMPATIBLE_IRC_SYS_IsEqual(int a, int b) { return a == b ? 1 : 0; }

void COMPATIBLE_IRC_SYS_ClearPartnerReady(IrcSys *sys) { sys->partnerReady = 0; }

void COMPATIBLE_IRC_SYS_StartSessionCallback(void) { }

void COMPATIBLE_IRC_SYS_ExitCallback(IrcSys *sys) { sys->exitDone = 1; }

void COMPATIBLE_IRC_SYS_RecvValueHandler(unsigned aid,int size,void *data,unsigned char *work) { unsigned v; if(GFL_NET_IsParentAid()) { MI_CpuCopy8(data,&v,4); *(unsigned *)(work+0x68+aid*4)=v; } }

void COMPATIBLE_IRC_SYS_RecvValueAckHandler(int aid,int size,int data,IrcSys *work,unsigned handle) { if(handle==(unsigned)GFL_NET_HANDLE_GetCurrentHandle()) work->valueAckReceived=1; }

void COMPATIBLE_IRC_SYS_RecvOwnValueHandler(unsigned aid,int size,void *data,unsigned char *work,unsigned handle) { if(handle==(unsigned)GFL_NET_HANDLE_GetCurrentHandle()) { if(aid!=GFL_NET_SYSTEM_GetCurrentAid()) MI_CpuCopy8(data,work+0x3c,4); } }

void COMPATIBLE_IRC_SYS_ProfileSyncInit(IrcProfileSync *sync, IrcSys *sys, int heapId)
{
    int line;

    MI_CpuFill8((void *)sync, 0, 0x34);
    line = 0x57b;
    sync->sys = sys;
    sync->sendProfile = GFL_HEAP_Alloc(heapId, 0x2c, 0, gCompatibleIrcSysFileName, line);
    MI_CpuFill8((void *)sync->sendProfile, 0, 0x2c);
    sync->selfProfile = GFL_HEAP_Alloc(heapId, 0x2c, 0, gCompatibleIrcSysFileName, line + 2);
    MI_CpuFill8((void *)sync->selfProfile, 0, 0x2c);
    sync->partnerProfile = GFL_HEAP_Alloc(heapId, 0x2c, 0, gCompatibleIrcSysFileName, line + 4);
    MI_CpuFill8((void *)sync->partnerProfile, 0, 0x2c);
    COMPATIBLE_IRC_SYS_AddCommandTable(sys, 0x1000, (u32)gCompatibleIrcProfileCommands, 4, (u32)sync);
}

void COMPATIBLE_IRC_SYS_ProfileSyncExit(IrcProfileSync *sync) { COMPATIBLE_IRC_SYS_DeleteCommandTable(sync->sys,0x1000); GFL_HEAP_Free(sync->sendProfile); GFL_HEAP_Free(sync->selfProfile); GFL_HEAP_Free(sync->partnerProfile); MI_CpuFill8(sync, 0, 0x34); }

int COMPATIBLE_IRC_SYS_ProfileSyncSendRequest(IrcProfileSync *sync,int first,int second) { sync->ownRequest[1]=first; sync->ownRequest[0]=second; return COMPATIBLE_IRC_SYS_SendToHandle(sync->sys,0x1000,8,(u32)sync->ownRequest)!=0; }

int COMPATIBLE_IRC_SYS_ProfileSyncPollRequest(IrcProfileSync *sync) { if(sync->requestReceived==1) { sync->requestReceived=0; return 1; } return 0; }

int COMPATIBLE_IRC_SYS_ProfileSyncSendAck(IrcProfileSync *sync) { int value; return COMPATIBLE_IRC_SYS_SendToHandle(sync->sys,0x1001,4,(u32)(&value))!=0; }

int COMPATIBLE_IRC_SYS_ProfileSyncPollAck(IrcProfileSync *sync) { if(sync->ackReceived==1) { sync->ackReceived=0; return 1; } return 0; }

int COMPATIBLE_IRC_SYS_ProfileSyncStepSend(IrcProfileSync *sync,int resource)
{
    switch(sync->state) {
    case 0:
        if(resource) COMPATIBLE_IRC_SYS_BuildProfile((void *)resource, sync->sendProfile); else return 1;
        if(COMPATIBLE_IRC_SYS_SendData(sync->sys,0x1003,44,(u32)sync->sendProfile,255,0,0,1)) sync->state=1;
        break;
    case 1:
        if(sync->profileReceived) { sync->profileReceived=0; sync->state=0; return 1; }
        break;
    }
    return 0;
}

void COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(IrcProfileSync *sync,IrcCompatibleProfile *out) { *out=*sync->partnerProfile; }

void COMPATIBLE_IRC_SYS_RecvRequestHandler(u32 aid,int size,void *data,IrcProfileSync *work,void *handle) {
 if(handle==GFL_NET_HANDLE_GetCurrentHandle()) { if(aid!=GFL_NET_SYSTEM_GetCurrentAid()) { MI_CpuCopy8(data,work->partnerRequest,8); work->requestReceived=1; } }
}

void COMPATIBLE_IRC_SYS_RecvAckHandler(u32 aid,int size,int data,IrcProfileSync *work,void *handle) {
 if(handle==GFL_NET_HANDLE_GetCurrentHandle()) { if(aid!=GFL_NET_SYSTEM_GetCurrentAid()) work->ackReceived=1; }
}

void COMPATIBLE_IRC_SYS_RecvDoneHandler(u32 aid,int size,int data,IrcProfileSync *work,void *handle) {
 if(handle==GFL_NET_HANDLE_GetCurrentHandle()) { if(aid!=GFL_NET_SYSTEM_GetCurrentAid()) work->doneReceived=1; }
}

void COMPATIBLE_IRC_SYS_RecvProfileHandler(u32 aid, int size, int data, IrcProfileSync *work, u32 handle)
{
    void *record;
    if (*(int *)work->sys != 0) {
        record = GAME_DATA_GetMyStatusPlayer((void *)*(int *)work->sys, aid);
        MI_CpuCopy8((void *)(data + 12), record, MYSTATUS_GetSize());
    }
    if (handle == (u32)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (aid != GFL_NET_SYSTEM_GetCurrentAid())
            work->profileReceived = 1;
    }
}

u32 COMPATIBLE_IRC_SYS_ProfileSyncGetProfileForAid(u32 aid,IrcProfileSync *sync) {
 if(aid==GFL_NET_SYSTEM_GetCurrentAid()) return (u32)sync->selfProfile;
 return (u32)sync->partnerProfile;
}
