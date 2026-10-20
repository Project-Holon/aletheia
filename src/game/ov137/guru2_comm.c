/*
 * file:     guru2_comm.c
 * unit:     yes
 * function: GURU2_COMM_Create, GURU2_COMM_Destroy, GURU2_COMM_RegisterCommands, GURU2_COMM_Exit, GURU2_COMM_SendWithHeader, GURU2_COMM_Send, GURU2_COMM_RecvPartyData, GURU2_COMM_RecvSessionClosed, GURU2_COMM_RecvJoinRequest, GURU2_COMM_RecvParentNotice, GURU2_COMM_GetOwnPlayerId, GURU2_COMM_RecvMemberCount, GURU2_COMM_RecvStatusFlags, GURU2_COMM_RecvPlayerReady, GURU2_COMM_RecvSlotAssignment, GURU2_COMM_RecvPlayerCount, GURU2_COMM_RecvPlayerInput, GURU2_COMM_RecvRoundResult, GURU2_COMM_RecvSelectedSlot, GURU2_COMM_RecvAngles, GURU2_COMM_RecvAbortVote, GURU2_COMM_RecvContinueVote, GURU2_COMM_GetRecvBuffer, GURU2_COMM_GetPartyCopy
 * address:  0x021DCB04
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from guru2.c, guru2_main.c, GURU2_MAIN_BroadcastResult.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gGuru2CommCommandTable 0x021E1A68 data a4
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_SetStateFromParent 0x021DE08C thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   MATH_CountPopulation 0x02080D24 arm
 *   GURU2_RECEIPT_SetStateFromChild 0x021DE17C thumb ov137
 *   GURU2_MAIN_StoreSlotAssignment 0x021E172C thumb ov137
 *   GURU2_MAIN_SyncPlayerCount 0x021E1758 thumb ov137
 *   GURU2_MAIN_SetPlayerInput 0x021E168C thumb ov137
 *   GURU2_MAIN_StoreRoundResult 0x021E1694 thumb ov137
 *   GURU2_MAIN_SetPlayerSelectedSlot 0x021E180C thumb ov137
 *   GURU2_MAIN_StoreAngles 0x021E1814 thumb ov137
 *   d_021E2268 0x021E2268 data a4
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GURU2_COMM_GetPartyCopy 0x021DCE00 thumb ov137
 *   GURU2_GetUnionApp 0x021DCAFC thumb ov137
 */

#include "ov137_types.h"
#include "guru2_shared_types.h"
#include "guru2_comm_shared_types.h"
#include "guru2_types.h"

struct Guru2JoinPacket {u8 playerId,memberCount; volatile u8 kind; u8 accepted;};

#include "../arm9/mi_memory.h"

#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_Alloc_hdr
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
void * GFL_HEAP_Alloc(u16, u32, int, const char *, u16);
#endif


#include "../arm9/net_command.h"
struct GFLNetHandle;

#include "../arm9/net_handle.h"


#include "../arm9/net.h"

#include "../arm9/net_system.h"

#include "guru2_receipt.h"
struct UnionAppWork;

#include "../ov022/union_app.h"


#include "../arm9/math.h"
struct Guru2Lobby;


#include "guru2_main.h"






#include "guru2.h"

struct Guru2Comm *GURU2_COMM_Create(struct Guru2Session *session,int heap);

void GURU2_COMM_Destroy(struct Guru2Comm *p);

void GURU2_COMM_RegisterCommands(u32 a);

void GURU2_COMM_Exit(struct Guru2Comm *p);

int GURU2_COMM_SendWithHeader(struct Guru2Comm *p,u32 id,const void *data,u32 size);

int GURU2_COMM_Send(struct Guru2Comm *p,u32 a,const void *b,u32 c);

void GURU2_COMM_RecvPartyData(int i,int unused,void *q,struct Guru2Comm *p);

void GURU2_COMM_RecvSessionClosed(int a,int b,int c,struct Guru2Comm *p);

void GURU2_COMM_RecvJoinRequest(int a,int b,u8 *c,struct Guru2Comm *p);

void GURU2_COMM_RecvParentNotice(int a,int b,int c,struct Guru2Comm *p);

int GURU2_COMM_GetOwnPlayerId(void);

void GURU2_COMM_RecvMemberCount(int a,int b,u8 *c,struct Guru2Comm *p);

void GURU2_COMM_RecvStatusFlags(int a,int b,u16 *c,struct Guru2Comm *p);

void GURU2_COMM_RecvPlayerReady(int a,int b,void *c,struct Guru2Comm *p);

void GURU2_COMM_RecvSlotAssignment(int a,int b,void *c,struct Guru2Comm *p);

void GURU2_COMM_RecvPlayerCount(int a,int b,int *c,struct Guru2Comm *p);

void GURU2_COMM_RecvPlayerInput(int a,int b,u8 *c,struct Guru2Comm *p);

void GURU2_COMM_RecvRoundResult(int a,int b,void *c,struct Guru2Comm *p);

void GURU2_COMM_RecvSelectedSlot(int a,int b,int *c,struct Guru2Comm *p);

void GURU2_COMM_RecvAngles(int a,int b,void *c,struct Guru2Comm *p);

void GURU2_COMM_RecvAbortVote(int a,int b,void *c,struct Guru2Comm *p);

void GURU2_COMM_RecvContinueVote(int a,int b,void *c,struct Guru2Comm *p);

void *GURU2_COMM_GetRecvBuffer(int a,struct Guru2Comm *p);

void *GURU2_COMM_GetPartyCopy(struct Guru2Comm *p, int i);

extern const char d_021E2268[];

extern const u8 gGuru2CommCommandTable[];

/*
 * GFL_HEAP_Alloc 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * d_021E2268 0x021E2268 data a4
 */
struct Guru2Comm *GURU2_COMM_Create(struct Guru2Session *session,int heap)
{
    struct Guru2Comm *p;
    p=GFL_HEAP_Alloc(heap,88,0,d_021E2268,152);
    MI_CpuFill8(p,0,88);
    p->session=session;
    p->recvBuffer=GFL_HEAP_Alloc(heap,0x1be4,0,d_021E2268,159);
    p->partyCopies=GFL_HEAP_Alloc(heap,0x1be4,0,d_021E2268,161);
    return p;
}

void GURU2_COMM_Destroy(struct Guru2Comm *p) {GFL_HEAP_Free(p->recvBuffer);GFL_HEAP_Free(p->partyCopies);GFL_HEAP_Free(p);}

void GURU2_COMM_RegisterCommands(u32 work) {GFL_NET_COMMAND_AddCommandTable(0x2800,(u32)gGuru2CommCommandTable,16,work);}

void GURU2_COMM_Exit(struct Guru2Comm *p) { }

/*
 * lever: separate q=(u8 *)((u32)p+4) keeps the updated buffer base;
 *   assigning p+=4 or retaining an integer parameter gave 50 bytes/DIFF.
 */
int GURU2_COMM_SendWithHeader(struct Guru2Comm *p,u32 id,const void *data,u32 size) {u8 *q;void *v;v=GFL_NET_HANDLE_GetCurrentHandle();q=(u8 *)((u32)p+4);MI_CpuCopy8(data,q+4,size);return GFL_NET_SendToHandle(v,(u16)id,(u16)(size+4),q+4);}

int GURU2_COMM_Send(struct Guru2Comm *p,u32 id,const void *data,u32 size) {return GURU2_COMM_SendWithHeader(p,id,data,size);}

void GURU2_COMM_RecvPartyData(int netId,int unused,void *data,struct Guru2Comm *p) {p->partyReceivedMask=p->partyReceivedMask|(s16)(1<<netId);MI_CpuCopy8(data,GURU2_COMM_GetPartyCopy(p,netId),1428);}

void GURU2_COMM_RecvSessionClosed(int netId,int size,int data,struct Guru2Comm *p)
{
    if(GFL_NET_SYSTEM_GetCurrentAid()!=0) {
        p->acceptingJoins=0;
        p->sessionClosed=1;
        GURU2_RECEIPT_SetStateFromParent(p->session->lobbyWork,27,(u8)netId);
    }
}

void GURU2_COMM_RecvJoinRequest(int netId,int size,u8 *data,struct Guru2Comm *p)
{
    struct Guru2JoinPacket s;
    if(netId!=0) {
        if(GFL_NET_SYSTEM_GetCurrentAid()!=0) return;
        s=*(struct Guru2JoinPacket *)data;
        s.playerId=netId; s.memberCount=p->expectedMemberCount;
        switch(((struct Guru2JoinPacket *)data)->kind) {
        case 0:
            if(p->expectedMemberCount!=UNION_APP_GetMemberCount(GURU2_GetUnionApp(p)) ||
               p->expectedMemberCount!=MATH_CountPopulation(UNION_APP_GetJoinedBits(GURU2_GetUnionApp(p)))) s.accepted=0;
            else { p->joinedMask|=1<<netId; s.accepted=1; }
            break;
        case 1: break;
        }
        GURU2_COMM_Send(p,0x2801,&s,4);
    } else {
        switch(data[2]) {
        case 0:
            netId=data[0];
            if(netId!=GFL_NET_SYSTEM_GetCurrentAid()) return;
            if(data[3]==0) GURU2_RECEIPT_SetStateFromParent(p->session->lobbyWork,8,netId);
            else { p->acceptedCount=data[1]; GURU2_RECEIPT_SetStateFromParent(p->session->lobbyWork,7,netId); }
            break;
        case 1: GURU2_RECEIPT_SetStateFromParent(p->session->lobbyWork,19,data[0]); break;
        }
    }
}

void GURU2_COMM_RecvParentNotice(int netId,int size,int data,struct Guru2Comm *p) {if(GFL_NET_SYSTEM_GetCurrentAid()!=0) GURU2_RECEIPT_SetStateFromParent(p->session->lobbyWork,13,0);}

int GURU2_COMM_GetOwnPlayerId(void) {return GFL_NET_SYSTEM_GetCurrentAid();}

void GURU2_COMM_RecvMemberCount(int netId,int size,u8 *data,struct Guru2Comm *p)
{
    GURU2_RECEIPT_SetStateFromChild(p->session->lobbyWork,1,*data);
    if(!GFL_NET_SYSTEM_GetCurrentAid()) p->memberCountAck=0;
}

/*
 * GURU2_RECEIPT_SetStateFromChild 0x021DE17C thumb ov137
 * GURU2_MAIN_StoreSlotAssignment 0x021E172C thumb ov137
 * GURU2_MAIN_SyncPlayerCount 0x021E1758 thumb ov137
 * GURU2_MAIN_SetPlayerInput 0x021E168C thumb ov137
 * GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
void GURU2_COMM_RecvStatusFlags(int netId,int size,u16 *data,struct Guru2Comm *p) { p->statusFlags|=*data; }

void GURU2_COMM_RecvPlayerReady(int netId,int size,void *data,struct Guru2Comm *p) { p->ackMask|=(u16)(1<<netId); }

void GURU2_COMM_RecvSlotAssignment(int netId,int size,void *data,struct Guru2Comm *p) { GURU2_MAIN_StoreSlotAssignment(p->session->gameWork,data); }

void GURU2_COMM_RecvPlayerCount(int netId,int size,int *data,struct Guru2Comm *p) { GURU2_MAIN_SyncPlayerCount(p->session->gameWork,*data); }

void GURU2_COMM_RecvPlayerInput(int netId,int size,u8 *data,struct Guru2Comm *p) { GURU2_MAIN_SetPlayerInput(p->session->gameWork,*data); }

/*
 * GURU2_MAIN_StoreRoundResult 0x021E1694 thumb ov137
 * GURU2_MAIN_SetPlayerSelectedSlot 0x021E180C thumb ov137
 * GURU2_MAIN_StoreAngles 0x021E1814 thumb ov137
 */
void GURU2_COMM_RecvRoundResult(int netId,int size,void *data,struct Guru2Comm *p) { if(netId==0) GURU2_MAIN_StoreRoundResult(p->session->gameWork,data); }

void GURU2_COMM_RecvSelectedSlot(int netId,int size,int *data,struct Guru2Comm *p) { GURU2_MAIN_SetPlayerSelectedSlot(p->session->gameWork,netId,*data); }

void GURU2_COMM_RecvAngles(int netId,int size,void *data,struct Guru2Comm *p) { GURU2_MAIN_StoreAngles(p->session->gameWork,data); }

void GURU2_COMM_RecvAbortVote(int netId,int size,void *data,struct Guru2Comm *p) { p->abortMask|=(u16)(1<<netId); }

void GURU2_COMM_RecvContinueVote(int netId,int size,void *data,struct Guru2Comm *p) { p->continueMask|=(u16)(1<<netId); }

void *GURU2_COMM_GetRecvBuffer(int index,struct Guru2Comm *p) { return p->recvBuffer+index*GURU2_PARTY_ENTRY_SIZE; }

void *GURU2_COMM_GetPartyCopy(struct Guru2Comm *p, int i)
{
    return p->partyCopies + i * GURU2_PARTY_ENTRY_SIZE;
}
