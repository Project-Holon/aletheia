/*
 * file:     union_command.c
 * unit:     yes
 * function: UNION_COMMAND_GetRecvBuffer, UNION_COMMAND_RecvConnectSync, UNION_COMMAND_SendConnectSync, UNION_COMMAND_RecvPartnerSelectA, UNION_COMMAND_SendPartnerSelectA, UNION_COMMAND_RecvPartnerSelectB, UNION_COMMAND_SendPartnerSelectB, UNION_COMMAND_RecvPartnerMac, UNION_COMMAND_SendMyMac, UNION_COMMAND_RecvPartnerMode, UNION_COMMAND_SendPartnerMode, UNION_COMMAND_RecvMyStatus, UNION_COMMAND_SendMyStatus, UNION_COMMAND_RecvTrainerCard, UNION_COMMAND_SendTrainerCard, UNION_COMMAND_RecvColosseumEntry, UNION_COMMAND_RecvColosseumSetting, UNION_COMMAND_RecvColosseumCancel, UNION_COMMAND_SendColosseumCancel, UNION_COMMAND_RecvAppEntry, UNION_COMMAND_SendAppEntry, UNION_COMMAND_RecvAppEntryRefused, UNION_COMMAND_SendAppEntryRefused, UNION_COMMAND_RecvAppEntryAccepted, UNION_COMMAND_SendAppEntryAccepted, UNION_COMMAND_RecvAppQuitRequest, UNION_COMMAND_SendAppQuitRequest, UNION_COMMAND_RecvAppQuitAccept, UNION_COMMAND_SendAppQuitAccept, UNION_COMMAND_RecvAppSettingRequest, UNION_COMMAND_SendAppSettingRequest, UNION_COMMAND_RecvAppSetting, UNION_COMMAND_SendAppSetting, UNION_COMMAND_RecvAppJoinData, UNION_COMMAND_SendAppJoinData, UNION_COMMAND_RecvAppData, UNION_COMMAND_SendAppData, UNION_COMMAND_RecvAppLeaveData, UNION_COMMAND_SendAppLeaveData, UNION_COMMAND_RecvAppNotice, UNION_COMMAND_SendAppNotice
 * address:  0x02173984
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from union_main.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   MI_CpuCopy8       0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   sUnionCmdAssertText 0x02175624 data a1
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   COMM_ENTRY_MENU_AddMember  0x021CD624  thumb  ov021
 *   UNION_APP_TryAcceptMember  0x02183BE8  thumb  ov022
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 *   UNION_APP_AddQuitRequest  0x02183F6C  thumb ov022
 *   UNION_APP_SetQuitAccepted  0x02183F7C  thumb ov022
 *   UNION_APP_AddSettingTarget  0x02183F88  thumb ov022
 *   UNION_APP_SetSetting  0x02183F98  thumb ov022
 *   UNION_APP_GetSettingSize 0x021840A8 thumb ov022
 *   UNION_APP_SetMemberEntry 0x02183FB8 thumb ov022
 *   UNION_APP_AddEntryTarget 0x02183FA8 thumb ov022
 *   UNION_APP_QueueJoinConfirm  0x02184060  thumb  ov022
 *   UNION_APP_OnMemberDropped 0x021840A4 thumb ov022
 *   UNION_COMMAND_SendAppQuitRequest  0x02173E1C  thumb  ov012
 *   UNION_COMMAND_SendAppSettingRequest  0x02173EC8  thumb  ov012
 *   UNION_COMMAND_SendAppJoinData  0x02173F90  thumb  ov012
 *   UNION_COMMAND_SendAppLeaveData  0x02174084  thumb  ov012
 *   UNION_COMM_StartConnectSync 0x02172EDC thumb ov012
 */
#include "../sdk_fx.h"

#include "union_comm_types.h"
#include "../arm9/net_types.h"
#include "union_command_shared_types.h"

typedef struct UnionAppMessage {
    UnionAppData data;   /* 0x00 */
    u8 mac[8];           /* 0x20 */
} UnionAppMessage;

#include "../arm9/net.h"

#include "../arm9/mi_memory.h"


#include "../arm9/os_ownerinfo.h"

#include "../arm9/gamesystem.h"

#include "../arm9/gf_panic.h"

#include "../arm9/game_data.h"

#include "../arm9/net_handle.h"




#include "../arm9/mystatus.h"

#include "../arm9/config.h"

struct CommEntryMenu;

#include "../ov021/comm_entry_menu.h"

#include "../ov022/union_app.h"





struct GFLNetHandle;

struct UnionAppEntry;
struct UnionRoomWork;





#include "union_comm.h"

u8 *UNION_COMMAND_GetRecvBuffer(int netId, UnionRoomWork *work, int size);

void UNION_COMMAND_RecvConnectSync(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendConnectSync(void);

void UNION_COMMAND_RecvPartnerSelectA(u32 netId, int size, const u32 *data, UnionRoomWork *work);

int UNION_COMMAND_SendPartnerSelectA(int select);

void UNION_COMMAND_RecvPartnerSelectB(u32 netId, int size, const u32 *data, UnionRoomWork *work);

int UNION_COMMAND_SendPartnerSelectB(int select);

void UNION_COMMAND_RecvPartnerMac(u32 netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendMyMac(void);

void UNION_COMMAND_RecvPartnerMode(u32 netId, int size, const u32 *data, UnionRoomWork *work);

int UNION_COMMAND_SendPartnerMode(int mode);

void UNION_COMMAND_RecvMyStatus(u32 netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendMyStatus(UnionRoomWork *work);

void UNION_COMMAND_RecvTrainerCard(u32 netId, u32 size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendTrainerCard(UnionRoomWork *work);

void UNION_COMMAND_RecvColosseumEntry(int netId, int size, const ColosseumPlayer *player, UnionRoomWork *work);

void UNION_COMMAND_RecvColosseumSetting(int netId, int size, const u32 *value, UnionRoomWork *work);

void UNION_COMMAND_RecvColosseumCancel(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendColosseumCancel(void);

void UNION_COMMAND_RecvAppEntry(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppEntry(UnionRoomWork *work);

void UNION_COMMAND_RecvAppEntryRefused(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppEntryRefused(u32 sendMask);

void UNION_COMMAND_RecvAppEntryAccepted(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppEntryAccepted(int sendMask);

void UNION_COMMAND_RecvAppQuitRequest(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppQuitRequest(void);

void UNION_COMMAND_RecvAppQuitAccept(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppQuitAccept(u32 sendMask);

void UNION_COMMAND_RecvAppSettingRequest(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppSettingRequest(void);

void UNION_COMMAND_RecvAppSetting(int netId, int size, const void *value, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppSetting(const void *data, u32 sendMask);

void UNION_COMMAND_RecvAppJoinData(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppJoinData(u8 sendMask, const UnionAppData *src);

void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppData(u32 sendMask, const UnionAppMessage *message);

void UNION_COMMAND_RecvAppLeaveData(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppLeaveData(u8 sendMask, const UnionAppData *src);

void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value);

extern const char sUnionCmdAssertText[];

/* ---- union command table (net commands 0x1400 to 0x1414) ---- */
u8 *UNION_COMMAND_GetRecvBuffer(int netId, UnionRoomWork *work, int size)
{
    if (size > UNION_RECV_BUFFER_SIZE) GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
    return work->recvBuffer[netId];
}

void UNION_COMMAND_RecvConnectSync(int netId, int size, const void *data, UnionRoomWork *work)
{
    UNION_COMM_StartConnectSync(work);
    work->mySituation.connect.syncReadyBits |= (u8)(1 << netId);
}

int UNION_COMMAND_SendConnectSync(void)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1400, 0, 0);
}

void UNION_COMMAND_RecvPartnerSelectA(u32 netId, int size, const u32 *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) situation->connect.partnerSelectA = *data;
}

int UNION_COMMAND_SendPartnerSelectA(int select)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1401, 4, &select);
}

void UNION_COMMAND_RecvPartnerSelectB(u32 netId, int size, const u32 *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) situation->connect.partnerSelectB = *data;
}

int UNION_COMMAND_SendPartnerSelectB(int select)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1402, 4, &select);
}

void UNION_COMMAND_RecvPartnerMac(u32 netId, int size, const void *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data, &situation->connect.partnerMac, sizeof(UnionMacPacket));
}

int UNION_COMMAND_SendMyMac(void)
{
    UnionMacPacket packet;
    MI_CpuFill8(&packet, 0, sizeof(UnionMacPacket));
    OS_GetMacAddress(packet.mac);
    packet.enabled = 1;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1403, sizeof(UnionMacPacket), &packet);
}

void UNION_COMMAND_RecvPartnerMode(u32 netId, int size, const u32 *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) situation->connect.partnerMode = (u8)*data;
}

int UNION_COMMAND_SendPartnerMode(int mode)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1404, 4, &mode);
}

void UNION_COMMAND_RecvMyStatus(u32 netId, int size, const void *data, UnionRoomWork *work)
{
    MYSTATUS_Copy((struct MyStatus *)data, GAME_DATA_GetMyStatusPlayer(work->parent->gameData, netId));
    work->mySituation.connect.myStatusRecvBits |= (u8)(1 << netId);
}

int UNION_COMMAND_SendMyStatus(UnionRoomWork *work)
{
    GFLNetHandle *handle;
    int size;
    handle = GFL_NET_HANDLE_GetCurrentHandle();
    size = MYSTATUS_GetSize();
    return GFL_NET_SendToHandle(handle, (u16)0x1405, (u16)size, GAME_DATA_GetMyStatus(work->parent->gameData));
}

/* stand-in: the plain path work->mySituation.connect.trainerCardReceived
 * folds the two offsets into one add of 0x288D and changes the bytes; the
 * enum-typed offset keeps the add of 0x2830 and the +0x5D store apart. */
void UNION_COMMAND_RecvTrainerCard(u32 netId, u32 size, const void *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
#ifdef __MWERKS__
        enum { SITUATION_OFFSET = 0x2830 } offset = SITUATION_OFFSET;
        UnionMySituation *situation = (UnionMySituation *)((u8 *)work + offset);
#else
        UnionMySituation *situation = &work->mySituation;
#endif
        situation->connect.trainerCardReceived = 1;
        MI_CpuCopy8(data, work->recvTrainerCard, size);
    }
}

u32 UNION_COMMAND_SendTrainerCard(UnionRoomWork *work)
{
    if (work->myTrainerCard == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x1406, 0x678, work->myTrainerCard, 1, 0, 1);
}

void UNION_COMMAND_RecvColosseumEntry(int netId, int size, const ColosseumPlayer *player, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    struct GameData *gameData;
    u32 macBuffer[2];
    colosseum = work->colosseum;
    gameData = GAMESYSTEM_GetGameData(work->parent->gameSystem);
    if (colosseum == 0 || colosseum->commPlayer == 0 || colosseum->entryMenu == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    OS_GetMacAddress((u8 *)macBuffer);
    COMM_ENTRY_MENU_AddMember(colosseum->entryMenu, netId, GAME_DATA_GetMyStatus(gameData), player->modeFlag, (u8 *)macBuffer);
}

void UNION_COMMAND_RecvColosseumSetting(int netId, int size, const u32 *value, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    colosseum = work->colosseum;
    if (colosseum == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    colosseum->parentSetting = *value;
}

void UNION_COMMAND_RecvColosseumCancel(int netId, int size, const void *data, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    colosseum = work->colosseum;
    if (colosseum == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    colosseum->entryCancelled = 1;
}

int UNION_COMMAND_SendColosseumCancel(void)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1409, 0, 0);
}

void UNION_COMMAND_RecvAppEntry(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        work->entryRefuseBits |= (u8)(1 << netId);
        return;
    }
    if (UNION_APP_TryAcceptMember(work->app, (u8)netId) == 1) {
        work->entryAcceptBits |= (u8)(1 << netId);
        return;
    }
    work->entryRefuseBits |= (u8)(1 << netId);
}

u32 UNION_COMMAND_SendAppEntry(UnionRoomWork *work)
{
    work->entryResult = 0;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140A, MYSTATUS_GetSize(),
                  GAME_DATA_GetMyStatus(work->parent->gameData), 1, 0, 0);
}

void UNION_COMMAND_RecvAppEntryRefused(int netId, int size, const void *data, UnionRoomWork *work) { work->entryResult = 2; }

int UNION_COMMAND_SendAppEntryRefused(u32 sendMask)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x140B, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppEntryAccepted(int netId, int size, const void *data, UnionRoomWork *work)
{
    work->entryResult = 1;
}

int UNION_COMMAND_SendAppEntryAccepted(int sendMask)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x140C, 0, 0, 1, 0, 0);
}

/* The second null test is dead code, but the bytes have its branch. */
void UNION_COMMAND_RecvAppQuitRequest(int netId, int size, const void *data, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    if (GFL_NET_IsParentAid() != 0) {
        app = work->app;
        if (app == 0) {
            if (app == 0) {
                GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
                return;
            }
        } else {
            UNION_APP_AddQuitRequest(app, (u8)netId);
        }
    }
}

u32 UNION_COMMAND_SendAppQuitRequest(void)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140D, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppQuitAccept(int netId, int size, const void *data, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    app = work->app;
    if (app == 0) {
        if (app == 0) {
            GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
    } else {
        UNION_APP_SetQuitAccepted(app);
    }
}

u32 UNION_COMMAND_SendAppQuitAccept(u32 sendMask)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x140E, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppSettingRequest(int netId, int size, const void *data, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    if (GFL_NET_IsParentAid() != 0) {
        app = work->app;
        if (app == 0) {
            if (app == 0) {
                GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
                return;
            }
        } else {
            UNION_APP_AddSettingTarget(app, (u8)netId);
        }
    }
}

int UNION_COMMAND_SendAppSettingRequest(void)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140F, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppSetting(int netId, int size, const void *value, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    if (GFL_NET_IsParentAid() != 1) {
        app = work->app;
        if (app == 0) {
            GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_SetSetting(app, value);
    }
}

u32 UNION_COMMAND_SendAppSetting(const void *data, u32 sendMask)
{
    GFLNetHandle *handle;
    u32 size;
    handle = GFL_NET_HANDLE_GetCurrentHandle();
    size = UNION_APP_GetSettingSize(handle);
    return GFL_NET_SendDataMask(handle, sendMask, 0x1410, size, data, 1, 0, 0);
}

void UNION_COMMAND_RecvAppJoinData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    UNION_APP_SetMemberEntry(work->app, work, (u8)netId, (struct UnionAppEntry *)data);
    UNION_APP_AddEntryTarget(work->app, netId);
}

int UNION_COMMAND_SendAppJoinData(u8 sendMask, const UnionAppData *src)
{
    UnionAppMessage message;
    MI_CpuFill8(&message, 0, sizeof(UnionAppMessage));
    message.data = *src;
    OS_GetMacAddress(message.mac);
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1411, sizeof(UnionAppMessage), &message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    UNION_APP_SetMemberEntry(work->app, work, (u8)netId, (struct UnionAppEntry *)data);
}

u32 UNION_COMMAND_SendAppData(u32 sendMask, const UnionAppMessage *message)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1412, sizeof(UnionAppMessage), message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppLeaveData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        if (work->app == 0) {
            GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_SetMemberEntry(work->app, work, (u8)netId, (struct UnionAppEntry *)data);
        UNION_APP_QueueJoinConfirm(work->app, (u8)netId);
    }
}

int UNION_COMMAND_SendAppLeaveData(u8 sendMask, const UnionAppData *src)
{
    UnionAppMessage message;
    MI_CpuFill8(&message, 0, sizeof(UnionAppMessage));
    message.data = *src;
    OS_GetMacAddress(message.mac);
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1413, sizeof(UnionAppMessage), &message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        if (work->app == 0) {
            GF_PANIC_Fail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_OnMemberDropped(work->app, *data);
    }
}

u32 UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1414, 1, &value, 1, 0, 0);
}
