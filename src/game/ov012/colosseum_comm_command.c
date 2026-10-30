/*
 * file:     colosseum_comm_command.c
 * unit:     yes
 * function: COLOSSEUM_AddCommandTable, COLOSSEUM_GetRecvBuffer, COLOSSEUM_NoOp, COLOSSEUM_RecvPlayerEntry, COLOSSEUM_SendPlayerEntry, COLOSSEUM_RecvTrainerCard, COLOSSEUM_SendTrainerCard, COLOSSEUM_RecvPackage, COLOSSEUM_SendPackage, COLOSSEUM_RecvChoiceRequest, COLOSSEUM_SendChoiceRequest, COLOSSEUM_RecvChoiceReply, COLOSSEUM_SendChoiceReply, COLOSSEUM_RecvParty, COLOSSEUM_SendParty, COLOSSEUM_RecvBattlePositions, COLOSSEUM_SendBattlePositions, COLOSSEUM_RecvReady, COLOSSEUM_SendReady, COLOSSEUM_RecvReadyCancel, COLOSSEUM_SendReadyCancel, COLOSSEUM_RecvCancelAck, COLOSSEUM_SendCancelAck, COLOSSEUM_RecvAllReady, COLOSSEUM_SendAllReady, COLOSSEUM_RecvConfirm, COLOSSEUM_RecvFinish, COLOSSEUM_SendFinish
 * address:  0x02174B40
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from union_comm.c, unit_0217422C.c, colosseum.c, COLOSSEUM_SetupBattleMember.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   COLOSSEUM_SendPackage  0x02174C90  thumb  ov012
 *   COLOSSEUM_UpdateCommPlayers  0x0217FF78  thumb  ov019
 *   COLOSSEUM_FlushChoiceReplies  0x02175110  thumb  ov012
 *   COLOSSEUM_UpdateReadyState  0x02175144  thumb  ov012
 *   MI_CpuCopy8       0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   GF_PANIC_Fail  0x02034714  arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   POKEPARTY_Init  0x0201A948  thumb
 *   COLOSSEUM_ResetParties  0x02175240  thumb  ov012
 *   COLOSSEUM_SendParty  0x02174D98  thumb  ov012
 *   COLOSSEUM_AllPartiesReceived  0x02175214  thumb  ov012
 *   COLOSSEUM_SetupBattleInfo  0x02175280  thumb  ov012
 *   COLOSSEUM_ClearBattleInfo  0x0217534C  thumb  ov012
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gColosseumCommandTable 0x02175588 data a4
 *   gColosseumAssertText1 0x0217562C data a4
 *   gColosseumAssertText2 0x0217563C data a4
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   COMM_PLAYER_Create  0x02167518  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   TRCARD_SYS_BuildProfile  0x0216F40C  thumb
 *   gColosseumAllocFile   0x02175630  data  ov012
 *   COMM_PLAYER_Delete  0x0216754C  thumb  ov010
 *   COLOSSEUM_SetupBattleMember  0x02175358  thumb  ov012
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   COLOSSEUM_GetMyChoice  0x021750C0  thumb  ov012
 *   COLOSSEUM_SetMyChoiceReply  0x021750C8  thumb  ov012
 *   COLOSSEUM_AssignChoice  0x021750D8  thumb  ov012
 *   COLOSSEUM_StorePackage  0x021751B4  thumb  ov012
 */
#include "../sdk_fx.h"

#include "union_comm_types.h"
#include "../arm9/net_types.h"
#include "../ov006/event_wificlub_types.h"

#include "../arm9/net.h"


#include "../arm9/mi_memory.h"

#include "../arm9/net_handle.h"


#include "../arm9/pokeparty.h"


#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/net_command.h"

void COLOSSEUM_AddCommandTable(UnionRoomWork *unionRoom);

extern NetCommandEntry gColosseumCommandTable[];

/* Registers the colosseum network commands (base id 0x1500, 14 entries). */
void COLOSSEUM_AddCommandTable(UnionRoomWork *unionRoom)
{
    GFL_NET_COMMAND_AddCommandTable((u32)0x1500, gColosseumCommandTable, (u32)14, unionRoom);
}

/* Net command ids of the colosseum. The receive callbacks sit in the union
 * room command table in ov019. */
#define COLOSSEUM_CMD_PLAYER_ENTRY   0x1501

#define COLOSSEUM_CMD_TRAINER_CARD   0x1502

#define COLOSSEUM_CMD_PACKAGE        0x1503

#define COLOSSEUM_CMD_CHOICE_REQUEST 0x1504

#define COLOSSEUM_CMD_CHOICE_REPLY   0x1505

#define COLOSSEUM_CMD_PARTY          0x1506

#define COLOSSEUM_CMD_POSITIONS      0x1507

#define COLOSSEUM_CMD_READY          0x1508

#define COLOSSEUM_CMD_READY_CANCEL   0x1509

#define COLOSSEUM_CMD_CANCEL_ACK     0x150A

#define COLOSSEUM_CMD_ALL_READY      0x150B

#define COLOSSEUM_CMD_FINISH         0x150D

#define COLOSSEUM_HEAP_ID 0x41

#define COLOSSEUM_PLAYER_MAX 4

#define COLOSSEUM_NO_CHOICE 0xFF

#define COLOSSEUM_RECV_BUFFER_SIZE 0x800

/* One player of the battle (16 bytes, filled by COLOSSEUM_SetupBattleMember). */
typedef struct ColosseumBattleMember {
    struct Party *party;
    ColosseumPlayer *player;
    u8 pad08;
    u8 levelLimit;
    u8 pad0a[6];
} ColosseumBattleMember;

/* Output of COLOSSEUM_SetupBattleInfo, 0x58 bytes. */
typedef struct ColosseumBattleInfo {
    ColosseumBattleMember member[COLOSSEUM_PLAYER_MAX]; /* 0x00 */
    u8 pad40[4];
    int teamMode;                                       /* 0x44: 3 or 1 */
    u8 pad48[0xC];
    void *trainerRecord;                                /* 0x54 */
} ColosseumBattleInfo;

#include "../arm9/gf_panic.h"


#include "../arm9/poke_regulation.h"


#include "../ov010/comm_player.h"
struct GameData;

#include "../arm9/game_data.h"
struct MyStatus;

#include "../arm9/mystatus.h"

#include "../arm9/os_ownerinfo.h"
struct TrainerCardProfile;

#include "../ov010/trcard_sys.h"
struct CommPlayerWork;


void COLOSSEUM_SetupBattleMember(ColosseumWork *colosseum, ColosseumBattleMember *member, u8 playerIndex, int heapId);
struct GameSystem;

#include "../arm9/gamesystem.h"
#include "../version.h"


u8 *COLOSSEUM_GetRecvBuffer(int netId, u8 *buffer, int size);

void COLOSSEUM_NoOp(void);

void COLOSSEUM_RecvPlayerEntry(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendPlayerEntry(const void *data, u32 toParent);

void COLOSSEUM_RecvTrainerCard(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);

int COLOSSEUM_SendTrainerCard(const void *data);

void COLOSSEUM_RecvPackage(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendPackage(const void *package);

void COLOSSEUM_RecvChoiceRequest(u32 netId, u32 size, u8 *data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendChoiceRequest(ColosseumWork *work);

void COLOSSEUM_RecvChoiceReply(u32 netId, u32 size, u32 *data, UnionRoomWork *unionWork);

int COLOSSEUM_SendChoiceReply(ColosseumWork *work, u32 netId, u32 result);

void COLOSSEUM_RecvParty(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendParty(const void *party);

void COLOSSEUM_RecvBattlePositions(int netId, u32 size, void *data, UnionRoomWork *unionWork);

int COLOSSEUM_SendBattlePositions(const void *positions);

void COLOSSEUM_RecvReady(int netId, int size, int data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendReady(void);

void COLOSSEUM_RecvReadyCancel(int netId, int size, int data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendReadyCancel(void);

void COLOSSEUM_RecvCancelAck(int netId, int size, int data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendCancelAck(int netId);

void COLOSSEUM_RecvAllReady(int netId, int size, int data, UnionRoomWork *unionWork);

u32 COLOSSEUM_SendAllReady(void);

void COLOSSEUM_RecvConfirm(int netId, int size, int data, UnionRoomWork *unionWork);

void COLOSSEUM_RecvFinish(int netId, int size, int data, UnionRoomWork *unionWork);

int COLOSSEUM_SendFinish(void);

ColosseumWork *COLOSSEUM_Create(const struct GameData *gameData, void *gameSystem, const struct MyStatus *myStatus, u32 modeFlag);

void COLOSSEUM_Delete(ColosseumWork *work, void *gameSystem);

void COLOSSEUM_SetStartFlag(ColosseumWork *work, int flag);

void COLOSSEUM_SetMyChoice(ColosseumWork *work, int choice);

u8 COLOSSEUM_GetMyChoice(ColosseumWork *work);

void COLOSSEUM_SetMyChoiceReply(ColosseumWork *work, int reply);

u8 COLOSSEUM_GetMyChoiceReply(ColosseumWork *work);

int COLOSSEUM_AssignChoice(ColosseumWork *work, int netId, int value);

void COLOSSEUM_FlushChoiceReplies(ColosseumWork *work);

void COLOSSEUM_UpdateReadyState(ColosseumWork *work);

void COLOSSEUM_StorePackage(ColosseumWork *work, int netId, const CommPlayerPackage *package);

int COLOSSEUM_TakePackage(ColosseumWork *work, int netId, CommPlayerPackage *out);

void COLOSSEUM_ClearConfirmCount(ColosseumWork *work);

int COLOSSEUM_AllPartiesReceived(ColosseumWork *work);

void COLOSSEUM_ResetParties(ColosseumWork *work, int keepOwn);

void COLOSSEUM_SetupBattleInfo(ColosseumWork *work, struct GameSystem *gameSystem, ColosseumBattleInfo *out, int heapId);

void COLOSSEUM_ClearBattleInfo(ColosseumBattleInfo *out);

extern const char gColosseumAssertText1[];

extern const char gColosseumAssertText2[];

extern char gColosseumAllocFile[];

#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_02175664[];
extern const char str_ja_02175680[];
extern const char str_ja_02175698[];
extern const char str_ja_021756A4[];
extern const char str_ja_021756C8[];
#endif

u8 *COLOSSEUM_GetRecvBuffer(int netId, u8 *buffer, int size)
{
#if LANGUAGE == LANGUAGE_JAPANESE
    if (size > COLOSSEUM_RECV_BUFFER_SIZE) GF_PANIC_FailPrintf(str_ja_02175664, 0x6C, str_ja_02175680, size, COLOSSEUM_RECV_BUFFER_SIZE);
#else
    if (size > COLOSSEUM_RECV_BUFFER_SIZE) GF_PANIC_Fail(gColosseumAssertText1, 0, gColosseumAssertText1);
#endif
    return buffer + 4 + (netId << 11);
}

void COLOSSEUM_NoOp(void)
{
}

void COLOSSEUM_RecvPlayerEntry(u32 netId, u32 size, void *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (netId == GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) return;
    if (colosseum == 0 || colosseum->commPlayer == 0) return;
    MI_CpuCopy8(data, &colosseum->player[netId], size);
}

u32 COLOSSEUM_SendPlayerEntry(const void *data, u32 toParent)
{
    u32 sendId = 0;
    if (toParent != 1) sendId = 255;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),(u8)sendId,COLOSSEUM_CMD_PLAYER_ENTRY,sizeof(ColosseumPlayer),data,1,0,1);
}

void COLOSSEUM_RecvTrainerCard(u32 netId, u32 size, void *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;

    if (netId == GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        return;
    }
    if (colosseum == 0 || colosseum->commPlayer == 0) {
        return;
    }
    if (colosseum->trainerCard[netId] == 0) {
        return;
    }
    MI_CpuCopy8(data, colosseum->trainerCard[netId], size);
    colosseum->trainerCardReceived[netId] = 1;
}

int COLOSSEUM_SendTrainerCard(const void *data)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),255,COLOSSEUM_CMD_TRAINER_CARD,0x678,data,1,0,1);
}

void COLOSSEUM_RecvPackage(u32 netId, u32 size, void *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (netId == GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) return;
    if (colosseum == 0 || colosseum->commPlayer == 0) return;
    COLOSSEUM_StorePackage(colosseum,netId,data);
}

u32 COLOSSEUM_SendPackage(const void *package)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),255,COLOSSEUM_CMD_PACKAGE,sizeof(CommPlayerPackage),package,0,1,1);
}

void COLOSSEUM_RecvChoiceRequest(u32 netId, u32 size, u8 *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum == 0 || colosseum->commPlayer == 0) return;
    if (GFL_NET_IsParentAid() == 0) return;
    COLOSSEUM_AssignChoice(colosseum,netId,*data);
}

u32 COLOSSEUM_SendChoiceRequest(ColosseumWork *work)
{
    u8 choice = COLOSSEUM_GetMyChoice(work);
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),0,COLOSSEUM_CMD_CHOICE_REQUEST,1,&choice,1,0,0);
}

void COLOSSEUM_RecvChoiceReply(u32 netId, u32 size, u32 *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum == 0 || colosseum->commPlayer == 0) return;
    COLOSSEUM_SetMyChoiceReply(colosseum, *data);
}

/*
 * lever: The address-taken payload is the third parameter: sp+0x20
 *        after the 16-byte home area, 8-byte save and 16-byte call frame.
 *        Taking the first parameter's address added a reload and gave DIFF.
 */
int COLOSSEUM_SendChoiceReply(ColosseumWork *work, u32 netId, u32 result)
{
    COLOSSEUM_GetMyChoice(work);
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),(u8)netId,COLOSSEUM_CMD_CHOICE_REPLY,4,&result,1,0,0);
}

void COLOSSEUM_RecvParty(u32 netId, u32 size, void *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum == 0) return;
    if (colosseum->party[netId] == 0) return;
    MI_CpuCopy8(data, colosseum->party[netId], size);
    colosseum->partyReceived[netId] = 1;
}

/*
 * Caller consumes 020399A8's live r0 despite its filed void return.
 */
u32 COLOSSEUM_SendParty(const void *party)
{
    GFLNetHandle *handle = GFL_NET_HANDLE_GetCurrentHandle();
    return GFL_NET_SendData(handle,255,COLOSSEUM_CMD_PARTY,POKE_REGULATION_GetDataSize(),party,1,0,1);
}

void COLOSSEUM_RecvBattlePositions(int netId, u32 size, void *data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum) {
        MI_CpuCopy8(data,colosseum->battlePosition,size);
        colosseum->positionsReceived = 1;
    }
}

int COLOSSEUM_SendBattlePositions(const void *positions) { return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),COLOSSEUM_CMD_POSITIONS,4,positions); }

void COLOSSEUM_RecvReady(int netId,int size,int data,UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum) colosseum->readyReceived[netId] = 1;
}

u32 COLOSSEUM_SendReady(void)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, COLOSSEUM_CMD_READY, 0, 0, 1, 0, 0);
}

void COLOSSEUM_RecvReadyCancel(int netId, int size, int data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum != 0) {
        colosseum->readyCancelled[netId] = 1;
        colosseum->readyReceived[netId] = 0;
    }
}

u32 COLOSSEUM_SendReadyCancel(void) { return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),0,COLOSSEUM_CMD_READY_CANCEL,0,0,1,0,0); }

void COLOSSEUM_RecvCancelAck(int netId,int size,int data,UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum) colosseum->readySent = 0;
}

u32 COLOSSEUM_SendCancelAck(int netId) { return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),(u8)netId,COLOSSEUM_CMD_CANCEL_ACK,0,0,1,0,0); }

void COLOSSEUM_RecvAllReady(int netId,int size,int data,UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum) colosseum->allReady = 1;
}

u32 COLOSSEUM_SendAllReady(void)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xff, COLOSSEUM_CMD_ALL_READY, 0, 0, 1, 0, 0);
}

void COLOSSEUM_RecvConfirm(int netId, int size, int data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum != 0)
        colosseum->confirmCount++;
}

void COLOSSEUM_RecvFinish(int netId, int size, int data, UnionRoomWork *unionWork)
{
    ColosseumWork *colosseum = unionWork->colosseum;
    if (colosseum != 0) {
        colosseum->finished[netId] = 1;
    }
}

int COLOSSEUM_SendFinish(void) { return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), COLOSSEUM_CMD_FINISH, 0, 0); }


