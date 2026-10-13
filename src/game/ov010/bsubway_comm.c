/*
 * file:     bsubway_comm.c
 * unit:     yes
 * function: BSUBWAY_COMM_NetInit, BSUBWAY_COMM_GetBeaconData, BSUBWAY_COMM_AddCommandTable, BSUBWAY_COMM_DeleteCommandTable, BSUBWAY_COMM_StartTimingSync, BSUBWAY_COMM_CheckTimingSync, BSUBWAY_COMM_SetSendPlayerData, BSUBWAY_COMM_SetSendTrainerData, BSUBWAY_COMM_SetSendRetireSelect, BSUBWAY_COMM_SetSendPlayMode, BSUBWAY_COMM_SetSendWord5, BSUBWAY_COMM_SetSendWord6, BSUBWAY_COMM_SetSendWord7, BSUBWAY_COMM_SetSendData, BSUBWAY_COMM_SendData, BSUBWAY_COMM_SetRecvMode, BSUBWAY_COMM_IsRecvEnd, BSUBWAY_COMM_RecvPlayerData, BSUBWAY_COMM_RecvTrainerData, BSUBWAY_COMM_RecvRetireSelect, BSUBWAY_COMM_RecvMyStatus, BSUBWAY_COMM_RecvPlayMode, BSUBWAY_COMM_RecvWord5, BSUBWAY_COMM_RecvWord6, BSUBWAY_COMM_RecvWord7
 * address:  0x02167AB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from comm_player.c at 0x02167AB0: bsubway script comm block, called only from ov021 bsubway_scr.c (name guess, no anchor).
 *
 * symbols:
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   d_02172014  0x02172014  data  ov010
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   func_02087C6C 0x02087C6C arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_02171FD4  0x02171FD4  data  ov010  a4
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   BSUBWAY_SCR_GetParty  0x021CA210  thumb  ov021
 *   func_02008550  0x02008550  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BSUBWAY_SCR_GetWinCount  0x021CA234  thumb  ov021
 *   BSUBWAY_SCR_GetStageNo  0x021CA2CC  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 */
struct Req;
struct NetHandle;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

#include "../ov021/bsubway_scr_types.h"

extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *, void *);
extern void func_02087C6C(void *);
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_StartTimingSync();
extern int GFL_NET_CheckTimingSync();
extern void *BSUBWAY_SCR_GetParty(u8 *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u16 BSUBWAY_SCR_GetWinCount(u8 *p);
extern u16 BSUBWAY_SCR_GetStageNo(u16 v);
extern void func_02082D44(void *dst, void *src, int n);
extern u32 func_0200FB24(void);
extern int GFL_NET_SendToHandle(struct NetHandle *a, u32 b, u32 c, u32 d);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void BSUBWAY_COMM_NetInit(void *arg);
void *BSUBWAY_COMM_GetBeaconData(BsubwayScrWork *work);
int BSUBWAY_COMM_GetBeaconSize(void);
int BSUBWAY_COMM_CheckConnectService(int a, int b);
void BSUBWAY_COMM_AddCommandTable(u32 work);
void BSUBWAY_COMM_DeleteCommandTable(void *work);
int BSUBWAY_COMM_StartTimingSync(int timingNo);
int BSUBWAY_COMM_CheckTimingSync(int timingNo);
void BSUBWAY_COMM_SetSendPlayerData(BsubwayScrWork *work, void *gameData);
void BSUBWAY_COMM_SetSendTrainerData(BsubwayScrWork *work);
void BSUBWAY_COMM_SetSendRetireSelect(BsubwayScrWork *work, u16 retire);
void BSUBWAY_COMM_SetSendPlayMode(BsubwayScrWork *work);
void BSUBWAY_COMM_SetSendWord5(BsubwayScrWork *work, u32 value);
void BSUBWAY_COMM_SetSendWord6(BsubwayScrWork *work, u32 value);
void BSUBWAY_COMM_SetSendWord7(BsubwayScrWork *work, u32 value);
void BSUBWAY_COMM_SetSendData(BsubwayScrWork *work, u32 cmd, u16 arg);
int BSUBWAY_COMM_SendData(BsubwayScrWork *work);
void BSUBWAY_COMM_SetRecvMode(BsubwayScrWork *work, u8 mode);
int BSUBWAY_COMM_IsRecvEnd(BsubwayScrWork *work, u16 *result);
void BSUBWAY_COMM_RecvPlayerData(int netId, int size, const u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvTrainerData(u16 netId, int size, void *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvRetireSelect(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvMyStatus(u16 netId, int size, void *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvPlayMode(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvWord5(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvWord6(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvWord7(u16 netId, int size, u16 *data, BsubwayScrWork *work);
extern u8 d_02172014[];
extern const u32 d_02171FD4[];


/*
 * Tail call to ARM GFL_NET_StartSession with (&d_02172014, 0, arg). No lr-saving
 * prologue; bl from ov021 BSUBWAY_SCR_CmdTool at 0x021CB4F4.
 */
void BSUBWAY_COMM_NetInit(void *arg)
{
    GFL_NET_StartSession((struct Req *)d_02172014, 0, (u32)arg);
}


/*
 * Fills the own comm record (MyStatus copy, MAC address, magic 0x3A0B) and
 * returns it.  The trailing unlabelled constant getter and equality
 * predicate are included.
 */
void *BSUBWAY_COMM_GetBeaconData(BsubwayScrWork *work)
{
    BsubwayCommInfo *info;
    info = &work->commInfo;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus(work->gameData), info);
    func_02087C6C(info->macAddress);
    info->magic = 0x3a0b;
    return info;
}


int BSUBWAY_COMM_GetBeaconSize(void)
{
    return 0x28;
}


int BSUBWAY_COMM_CheckConnectService(int a, int b)
{
    if (a == b) return 1;
    return 0;
}


/*
 * Adds the net command table 0x2C00..0x2C08 with the work as callback
 * argument.  Trailing extent is already matched BSUBWAY_COMM_DeleteCommandTable.
 */
void BSUBWAY_COMM_AddCommandTable(u32 work)
{
    GFL_NET_COMMAND_AddCommandTable(0x2c00, (u32)d_02171FD4, 0x2c08, work);
}


/*
 * Unlabelled leaf, blocker of ov021 func_021CB8AC: tail call of GFL_NET_COMMAND_DeleteCommandTable(0x2C00); the argument is ignored.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void BSUBWAY_COMM_DeleteCommandTable(void *work)
{
    GFL_NET_COMMAND_DeleteCommandTable(0x2c00);
}


/* Starts the timing sync timingNo on the current net handle. */
int BSUBWAY_COMM_StartTimingSync(int timingNo)
{
    return GFL_NET_StartTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), timingNo);
}


/* Checks the timing sync timingNo on the current net handle. */
int BSUBWAY_COMM_CheckTimingSync(int timingNo)
{
    return GFL_NET_CheckTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), timingNo);
}


/* Player data: own sex, the species of the two chosen members and the stage. */
void BSUBWAY_COMM_SetSendPlayerData(BsubwayScrWork *work, void *gameData)
{
    void *myStatus;
    void *party;
    int i;

    myStatus = GAME_DATA_GetMyStatus(gameData);
    party = BSUBWAY_SCR_GetParty((u8 *)work);
    work->sendBuf.player.sex = func_02008550(myStatus);
    for (i = 0; i < 2; i++)
        work->sendBuf.player.monsNo[i] = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, work->memberIndex[i]), 5, 0);
    work->sendBuf.player.stage = BSUBWAY_SCR_GetStageNo(BSUBWAY_SCR_GetWinCount((u8 *)work));
}


/*
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 BSUBWAY_COMM_SetSendData.
 */
void BSUBWAY_COMM_SetSendTrainerData(BsubwayScrWork *work)
{
    func_02082D44(work->trainerNo, work->sendBuf.raw, 0x1C);
}


void BSUBWAY_COMM_SetSendRetireSelect(BsubwayScrWork *work, u16 retire)
{
    work->stateBits.retireSelect = retire;
    work->sendBuf.select.retire = retire;
}


void BSUBWAY_COMM_SetSendPlayMode(BsubwayScrWork *work)
{
    *(u32 *)work->sendBuf.raw = work->playMode;
}


void BSUBWAY_COMM_SetSendWord5(BsubwayScrWork *work, u32 value)
{
    *(u32 *)work->sendBuf.raw = value;
}


void BSUBWAY_COMM_SetSendWord6(BsubwayScrWork *work, u32 value)
{
    *(u32 *)work->sendBuf.raw = value;
}


void BSUBWAY_COMM_SetSendWord7(BsubwayScrWork *work, u32 value)
{
    *(u32 *)work->sendBuf.raw = value;
}


/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void BSUBWAY_COMM_SetSendData(BsubwayScrWork *work, u32 cmd, u16 arg)
{
    void *gameData;
    gameData = work->gameData;
    switch (cmd) {
    case 0:
        work->sendCommand = 0x2C00;
        BSUBWAY_COMM_SetSendPlayerData(work, gameData);
        return;
    case 1:
        work->sendCommand = 0x2C01;
        BSUBWAY_COMM_SetSendTrainerData(work);
        return;
    case 2:
        work->sendCommand = 0x2C02;
        BSUBWAY_COMM_SetSendRetireSelect(work, arg);
        return;
    case 3:
        work->sendCommand = 0x2C03;
        MYSTATUS_Copy(GAME_DATA_GetMyStatus(gameData), work->sendBuf.raw);
        return;
    case 4:
        work->sendCommand = 0x2C04;
        BSUBWAY_COMM_SetSendPlayMode(work);
        return;
    case 5:
        work->sendCommand = 0x2C05;
        BSUBWAY_COMM_SetSendWord5(work, arg);
        return;
    case 6:
        work->sendCommand = 0x2C06;
        BSUBWAY_COMM_SetSendWord6(work, arg);
        return;
    case 7:
        work->sendCommand = 0x2C07;
        BSUBWAY_COMM_SetSendWord7(work, arg);
        return;
    default:
        work->sendCommand = 0x2C08;
        return;
    }
}


int BSUBWAY_COMM_SendData(BsubwayScrWork *work)
{
    u16 command;
    if (func_0200FB24() != 0)
        return 1;
    command = work->sendCommand;
    if (command >= 0x2C08)
        return 1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), command, 0x46, (u32)work->sendBuf.raw) == 1)
        return 1;
    return 0;
}


/*
 * Byte setter at +0x725. bl from ov021 BSUBWAY_SCR_CmdTool at 0x021CB596.
 */
void BSUBWAY_COMM_SetRecvMode(BsubwayScrWork *work, u8 mode)
{
    work->recvMode = mode;
}


int BSUBWAY_COMM_IsRecvEnd(BsubwayScrWork *work, u16 *result)
{
    int expected;
    if (func_0200FB24() != 0)
        return 1;
    expected = 1;
    if (work->recvMode != 1)
        expected = 2;
    if (work->recvCount == expected) {
        work->recvCount = 0;
        if (result != 0)
            *result = work->recvResult;
        return 1;
    }
    return 0;
}


/*
 * lever: Const source halfwords restores c[0]/c[1] load scheduling.
 */
void BSUBWAY_COMM_RecvPlayerData(int netId, int size, const u16 *data, BsubwayScrWork *work)
{
    u16 sameCount = 0;
    u16 sex;
    u16 monsNo;
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid()) {
        sex = data[0];
        monsNo = data[1];
        work->partnerSex = sex;
        work->partnerMonsNo[0] = monsNo;
        work->partnerMonsNo[1] = data[2];
        work->partnerStage = data[3];
        work->stateBits.partnerNo = work->partnerSex + 5;
        if (work->memberMonsNo[0] == monsNo || work->memberMonsNo[0] == work->partnerMonsNo[1])
            sameCount += 1;
        if (work->memberMonsNo[1] == monsNo || work->memberMonsNo[1] == work->partnerMonsNo[1])
            sameCount += 2;
        work->recvResult = sameCount;
    }
}


void BSUBWAY_COMM_RecvTrainerData(u16 netId, int size, void *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid() && GFL_NET_SYSTEM_GetCurrentAid() != 0)
        func_02082D44(data, work->trainerNo, 0x1c);
}


void BSUBWAY_COMM_RecvRetireSelect(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid()) {
        work->recvResult = 0;
        if ((work)->stateBits.retireSelect != 0 || *data != 0)
            work->recvResult = 1;
    }
}


void BSUBWAY_COMM_RecvMyStatus(u16 netId, int size, void *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid())
        func_02082D44(data, &work->partnerMyStatus, 0x20);
}


void BSUBWAY_COMM_RecvPlayMode(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid()) {
        if (work->playMode != *data)
            work->recvResult = 0;
        else
            work->recvResult = 1;
    }
}


void BSUBWAY_COMM_RecvWord5(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid())
        work->recvResult = *data;
}


void BSUBWAY_COMM_RecvWord6(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid())
        work->recvResult = *data;
}


void BSUBWAY_COMM_RecvWord7(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != GFL_NET_SYSTEM_GetCurrentAid())
        work->recvResult = *data;
}
