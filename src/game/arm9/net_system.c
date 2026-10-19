/*
 * file:     net_system.c
 * unit:     yes
 * function: GFL_NET_SYSTEM_SetDebugByte, GFL_NET_SYSTEM_InitRecvState, GFL_NET_SYSTEM_GetSendSize, GFL_NET_SYSTEM_InitWork, GFL_NET_SYSTEM_ResetBuffers, GFL_NET_SYSTEM_ResetRecvBuffer, GFL_NET_SYSTEM_InitDevice, GFL_NET_SYSTEM_SetDeviceOption, GFL_NET_SYSTEM_RecvCallback, GFL_NET_SYSTEM_ConnectDevice, GFL_NET_SYSTEM_ParentConnectHook, GFL_NET_SYSTEM_ChildConnectHook, GFL_NET_SYSTEM_StartParent, GFL_NET_SYSTEM_StartBeaconScan, GFL_NET_SYSTEM_EndDevice, GFL_NET_SYSTEM_SetDeviceMode, GFL_NET_SYSTEM_ConnectToParent, GFL_NET_SYSTEM_FreeWork, GFL_NET_SYSTEM_FreeWorkIfAuto, GFL_NET_SYSTEM_ResetMachineBuffer, GFL_NET_SYSTEM_Main, GFL_NET_SYSTEM_ResetAll, GFL_NET_SYSTEM_PackSendData, GFL_NET_SYSTEM_SendParentData, GFL_NET_SYSTEM_SendWireless, GFL_NET_SYSTEM_SendWifi, GFL_NET_SYSTEM_RecvData, GFL_NET_SYSTEM_RecvParentCallback, GFL_NET_SYSTEM_SendIrc, GFL_NET_SYSTEM_SendMP, GFL_NET_SYSTEM_SendMPParent, GFL_NET_SYSTEM_CheckAllChildRecv, GFL_NET_SYSTEM_ClearChildRecv, GFL_NET_SYSTEM_UpdateMPParent, GFL_NET_SYSTEM_RecvChildData, GFL_NET_SYSTEM_RecvParentData, GFL_NET_SYSTEM_SendCallback, GFL_NET_SYSTEM_SendEndCallback, GFL_NET_SYSTEM_BuildSendPacket, GFL_NET_SYSTEM_SetSendQueue, GFL_NET_SYSTEM_GetChildRingDataSize, GFL_NET_SYSTEM_GetParentRingDataSize, GFL_NET_SYSTEM_DispatchRecv, GFL_NET_SYSTEM_ProcessRecvRing, GFL_NET_SYSTEM_ProcessParentRecv, GFL_NET_SYSTEM_ProcessChildRecv, GFL_NET_SYSTEM_IsConnectMember, GFL_NET_SYSTEM_GetConnectNum, GFL_NET_SYSTEM_IsDeviceReady, GFL_NET_SYSTEM_GetCurrentAid, GFL_NET_SYSTEM_GetChildBitmap, GFL_NET_SYSTEM_IsError, GFL_NET_SYSTEM_CheckError, GFL_NET_SYSTEM_IsSendQueueEntry, GFL_NET_SYSTEM_IsSendQueueEmpty, GFL_NET_SYSTEM_SetNoChildError, GFL_NET_SYSTEM_SetWaitMode, GFL_NET_SYSTEM_SetError, GFL_NET_SYSTEM_ResetError, GFL_NET_SYSTEM_SetNoSend, GFL_NET_SYSTEM_IsSendEnable, GFL_NET_SYSTEM_ClampNetId
 * address:  0x02037224
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x02037224 (__FILE__ anchor boundary).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   _NetPhase   0x020A7A20  data  a1
 *   _FileName   0x020A7A24  data
 *   _pNetSys     0x021469D0  data
 *   _AssertNetIdRange   0x020A7A34  data
 *   GFL_HEAP_Free   0x020307B0  arm
 *   GFL_NET_SYSTEM_GetCurrentAid   0x02039338  arm
 *   GFL_NET_SYSTEM_GetChildBitmap   0x020393A8  arm
 *   GFL_NET_SYSTEM_IsError  0x020393D0  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   _AssertAlways     0x020A7A50  data
 *   _AssertNotMpMode   0x020A7A54  data
 *   GFL_NET_SYSTEM_IsSendEnable  0x02039594  arm
 *   GFL_NET_HANDLE_GetNetHandle   0x0203996C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   _pNetState     0x021469DC  data
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   file_020A7A68  0x020A7A68  data
 *   _pBaseWork     0x021469D4  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   msg_020A7A88   0x020A7A88  data
 *   OS_GetMacAddress  0x02087C6C  arm
 *   msg_020A7A94   0x020A7A94  data
 *   GFL_NET_SYSTEM_ClampNetId  0x020395E0  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   file_020A7AB0  0x020A7AB0  data
 *   file_020A7ACC  0x020A7ACC  data
 *   _pCommandWork     0x021469D8  data
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7B08     0x020A7B08  data
 *   sNet3730       0x020A7AF8  data
 *   sNet3733       0x020A7B20  data
 *   sNet3734       0x020A7B50  data
 *   g_020A7B78     0x020A7B78  data
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7BB4     0x020A7BB4  data
 *   RTC_GetDateTime     0x020889C0  arm
 *   GF_STANDARD_RandSeed     0x0203F034  arm
 *   GF_STANDARD_Rand     0x0203F0A8  arm
 *   g_02FFFC3C        0x02FFFC3C  data
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   GFL_NET_SYSTEM_SetNoSend  0x02039578  arm
 *   GFL_NET_SYSTEM_ResetError  0x02039560  arm
 *   g_020A7BEC      0x020A7BEC  data
 *   file_020A7BA8   0x020A7BA8  data
 *   file_020A7C70   0x020A7C70  data
 *   g_020A7C7C     0x020A7C7C  data
 *   GFL_NET_RING_BUFF_Init 0x0203640C arm
 *   GFL_NET_RING_BUFF_Write 0x02036428 arm
 *   GFL_NET_RING_BUFF_Read 0x020364D4 arm
 *   GFL_NET_RING_BUFF_ReadByte 0x02036500 arm
 *   GFL_NET_RING_BUFF_ReadU16 0x02036540 arm
 *   GFL_NET_RING_BUFF_GetDataSize 0x020365E8 arm
 *   GFL_NET_RING_BUFF_EndChange 0x0203666C arm
 *   GFL_NET_QUEUE_IsEmpty 0x020366A8 arm
 *   GFL_NET_QUEUE_Put 0x020368C0 arm
 *   GFL_NET_QUEUE_FillSendBuffer 0x02036A50 arm
 *   GFL_NET_QUEUE_Init 0x02036AF4 arm
 *   GFL_NET_QUEUE_Reset 0x02036B4C arm
 *   GFL_NET_QUEUE_Exit 0x02036B88 arm
 *   GFL_NET_QUEUE_IsCommandQueued 0x02036B98 arm
 *   GFL_NET_WM_ICON_EasyEnd 0x020370C8 arm
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_IsHandleReady 0x0203D394 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 *   GFL_NET_GetUserArg 0x0203D650 arm
 *   GFL_NET_GetMaxConnectNum 0x0203D680 arm
 *   GFL_NET_GetChildSendSize 0x0203D6BC arm
 *   GFL_NET_CallDeviceReadyFunc 0x0203D700 arm
 *   GFL_NET_GetSession 0x0203D788 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_IRC_WIRELESS_IsActive 0x0203DA4C arm
 *   GFL_NET_IRC_WIRELESS_AddMacAddress 0x0203DAC4 arm
 *   GFL_NET_COMMAND_GetHeaderSize  0x0203A634  arm
 *   GFL_NET_COMMAND_CallCommand  0x0203A770  arm
 *   GFL_NET_COMMAND_IsCommandValid  0x0203A7EC  arm
 *   GFL_NET_COMMAND_IsHugeCommand  0x0203A804  arm
 *   GFL_NET_COMMAND_GetHugeBuffer  0x0203A81C  arm
 *   GFL_NET_COMMAND_Main  0x0203ACAC  arm
 *   GFL_NET_STATE_Idle  0x0203C00C  arm
 *   GFL_NET_STATE_WifiMatchStart  0x0203C864  arm
 *   GFL_NET_STATE_GetErrorMode  0x0203C990  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm

 */

#include "../types.h"

#include "net_types.h"

/* Output of the send queue: where to write and how much room is left. */
struct NetPacketSpan {
    void *dest;
    u16 remaining;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void  MI_CpuFill8(void *dst, u8 val, u32 size);

extern void GFL_NET_SYSTEM_SetError(void);

extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

extern u32 GFL_HEAP_Free(void *p);

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

extern int   GFL_NET_SYSTEM_GetChildBitmap(void);

extern int  GFL_NET_SYSTEM_IsError(void);

extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);

extern int    GFL_NET_SYSTEM_IsSendEnable(void);

extern GFLNetHandle *GFL_NET_HANDLE_GetNetHandle(s32 idx);

extern void MI_CpuCopy8(const void *src, void *dst, int n);

extern int GFL_NET_SYSTEM_ClampNetId(int netId);

extern void GFL_NET_STATE_Idle(void);

extern void GFL_NET_SYSTEM_SetNoChildError(u8 v);

extern void GFL_NET_SYSTEM_SetNoSend(void);

extern void GFL_NET_SYSTEM_ResetError(void);
struct NetRingBuff;

void GFL_NET_RING_BUFF_Init(struct NetRingBuff *ring, u8 *buf, s32 size);

void GFL_NET_RING_BUFF_Write(NetRingBuff *r, const u8 *src, int len);

int GFL_NET_RING_BUFF_Read(NetRingBuff *p, unsigned char *dst, u32 len, u32 max);

u32 GFL_NET_RING_BUFF_ReadByte(NetRingBuff *a);

u32 GFL_NET_RING_BUFF_ReadU16(NetRingBuff *a);

int GFL_NET_RING_BUFF_GetDataSize(NetRingBuff *p);

void GFL_NET_RING_BUFF_EndChange(NetRingBuff *r);

int GFL_NET_QUEUE_IsEmpty(NetQueue *p);

int GFL_NET_QUEUE_Put(NetQueue *queue, u32 command, const u8 *data, u32 size, u32 sendArg, u32 useRing, u32 queueArg);
struct NetSendBuf;
struct NetQueue;

int GFL_NET_QUEUE_FillSendBuffer(struct NetQueue *queue, struct NetSendBuf *out);

void GFL_NET_QUEUE_Init(NetQueue *p, u32 n, NetRingBuff *a, u32 b);

void GFL_NET_QUEUE_Reset(NetQueue *p);

void GFL_NET_QUEUE_Exit(NetQueue *queue);

int GFL_NET_QUEUE_IsCommandQueued(NetQueue *p, int v);

u32 GFL_NET_WM_ICON_EasySetLevel(u32 a);

void GFL_NET_SYSTEM_SetDebugByte(u8 phase, int line);

void GFL_NET_SYSTEM_InitRecvState(struct NetRecvCursor *cursor);

u32 GFL_NET_SYSTEM_GetSendSize(void);

int GFL_NET_SYSTEM_InitWork(u32 packetSize, u32 heapId, u32 useParentSize);

void GFL_NET_SYSTEM_ResetBuffers(void);

void GFL_NET_SYSTEM_ResetRecvBuffer(int netId);

int GFL_NET_SYSTEM_InitDevice(u32 packetSize, u32 heapId);

u32 GFL_NET_SYSTEM_SetDeviceOption(u32 arg);

u32 GFL_NET_SYSTEM_RecvCallback(u32 netId, u8 *packet, u32 length);

u32 GFL_NET_SYSTEM_ConnectDevice(u8 renewTgid);

void GFL_NET_SYSTEM_ParentConnectHook(u32 netId);

void GFL_NET_SYSTEM_ChildConnectHook(u32 netId);

u32 GFL_NET_SYSTEM_StartParent(u8 renewTgid, u16 packetSize, u32 sendArg0, u32 sendArg1);

u32 GFL_NET_SYSTEM_StartBeaconScan(u32 sendArg, u16 packetSize);

int GFL_NET_SYSTEM_EndDevice(u32 packetSize);

void GFL_NET_SYSTEM_SetDeviceMode(int interval);

u32 GFL_NET_SYSTEM_ConnectToParent(u32 beaconArg0, u32 beaconArg1, u16 packetSize, u32 beaconArg2);

void GFL_NET_SYSTEM_FreeWork(void);

void GFL_NET_SYSTEM_FreeWorkIfAuto(void);

void GFL_NET_SYSTEM_ResetMachineBuffer(u32 netId);

int GFL_NET_SYSTEM_Main(void);

void GFL_NET_SYSTEM_ResetAll(void);

int GFL_NET_SYSTEM_PackSendData(int checkPending);

void GFL_NET_SYSTEM_SendParentData(void);

void GFL_NET_SYSTEM_SendWireless(void);

void GFL_NET_SYSTEM_SendWifi(void);

u32 GFL_NET_SYSTEM_RecvData(u32 netId, u8 *packet, u32 length);

void GFL_NET_SYSTEM_RecvParentCallback(u32 buffer, u32 size);

void GFL_NET_SYSTEM_SendIrc(void);

void GFL_NET_SYSTEM_SendMP(void);

void GFL_NET_SYSTEM_SendMPParent(void);

int GFL_NET_SYSTEM_CheckAllChildRecv(void);

void GFL_NET_SYSTEM_ClearChildRecv(void);

void GFL_NET_SYSTEM_UpdateMPParent(void);

int GFL_NET_SYSTEM_RecvChildData(u32 netId, NetPacketHeader *packet, s32 length);

int GFL_NET_SYSTEM_RecvParentData(u32 netId, NetPacketHeader *packet, s32 length);

int GFL_NET_SYSTEM_SendCallback(int success);

int GFL_NET_SYSTEM_SendEndCallback(u32 success);

s32 GFL_NET_SYSTEM_BuildSendPacket(struct NetPacketHeader *header, NetQueue *queue, s32 packetSize, u8 seq);

int GFL_NET_SYSTEM_SetSendQueue(u32 command, const void *data, u32 size, u32 sendArg, u32 destNetId, u32 queueArg, u32 noRing);

int GFL_NET_SYSTEM_GetChildRingDataSize(void);

int GFL_NET_SYSTEM_GetParentRingDataSize(void);

void GFL_NET_SYSTEM_DispatchRecv(int command, u32 size, u32 data, struct NetRecvCursor *cursor);

void GFL_NET_SYSTEM_ProcessRecvRing(NetRingBuff *ring, s32 senderID, u8 *buf, struct NetRecvCursor *cursor, u32 maxSize);

void GFL_NET_SYSTEM_ProcessParentRecv(void);

void GFL_NET_SYSTEM_ProcessChildRecv(void);

int GFL_NET_SYSTEM_IsConnectMember(u32 netId);

u32 GFL_NET_SYSTEM_GetConnectNum(void);

int GFL_NET_SYSTEM_IsDeviceReady(void);

u32 GFL_NET_SYSTEM_CheckError(void);

int GFL_NET_SYSTEM_IsSendQueueEntry(u32 command, u32 destNetId);

int GFL_NET_SYSTEM_IsSendQueueEmpty(void);

void GFL_NET_SYSTEM_SetWaitMode(u32 mode);

u32 GFL_NET_COMMAND_GetHeaderSize(u32 commandOption);

void GFL_NET_COMMAND_CallCommand(u32 a, u32 b, int c, u32 d, u32 e, u32 f);

int GFL_NET_COMMAND_IsCommandValid(unsigned int idx);

int GFL_NET_COMMAND_IsHugeCommand(unsigned int idx);

u32 GFL_NET_COMMAND_GetHugeBuffer(u32 command, u32 senderID, u32 totalSize);

void GFL_NET_COMMAND_Main(void);

void GFL_NET_STATE_WifiMatchStart(void);

u32 GFL_NET_STATE_GetErrorMode(void);

void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);

u32 GFL_NET_STATE_GetError(void);

int GFL_NET_SendToHandle(GFLNetHandle *a, u32 b, u32 c, const void *d);

u32 GFL_NET_GetMaxConnectNum(void);

u32 GFL_NET_GetChildSendSize(void);

GFLNetSession *GFL_NET_GetSession(void);

GFLNetSession *GFL_NET_GetInitParam(void);

extern u8 _NetPhase[];  /* [0] MP parent phase (1 receive, 2 wait, 3 done, 4 send); [1] send phase (0 idle, 2 receiving, 4 ready) */

extern char _FileName[];

extern struct NetSysWork *_pNetSys;

extern char _AssertNetIdRange[];

extern char _AssertAlways[];

extern char _AssertNotMpMode[];

void GFL_NET_SYSTEM_SetDebugByte(u8 phase, int line)
{
    _NetPhase[0] = phase;
}

/*
 * Resets a sixteen-byte record: both halfwords at +8 and +0x0A become 0xFFFF
 * (the "no value" sentinel) and the words at +0 and +4 and the halfword at
 * +0x0C are cleared.  The sentinel cannot be encoded as an ARM immediate, so it
 * comes out of the function's own literal pool; the stores then run in the
 * order the source writes them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_InitRecvState.c \
 *       --func GFL_NET_SYSTEM_InitRecvState --addr 0x02037234 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_InitRecvState(struct NetRecvCursor *cursor)
{
    cursor->command = 0;
    cursor->remaining = 0xFFFF;
    cursor->totalSize = 0xFFFF;
    cursor->dest = 0;
    cursor->copied = 0;
}

/*
 * The current capacity, or the measured one: when the state object's byte at
 * +0x64 is set and its halfword at +0x6C is non-zero, that halfword is the
 * answer; otherwise the two measurement calls are multiplied.
 *
 * The conjunction is the reason both loads after the first comparison are
 * conditional (`ldrhne`, `cmpne`) and the early return is a bare `popne`:
 * written as one `&&` in a single `if`, mwcc keeps the whole guard inside the
 * flags.  The product is a plain `mul`, so the function returns a 32-bit
 * value, not a narrowed one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_GetSendSize.c \
 *       --func GFL_NET_SYSTEM_GetSendSize --addr 0x02037258 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_GetSendSize(void)
{
    GFLNetSession *session;

    session = GFL_NET_GetSession();
    if (session->init.bMPMode != 0 && session->init.parentSendSize != 0)
        return session->init.parentSendSize;
    return GFL_NET_GetChildSendSize() * GFL_NET_GetMaxConnectNum();
}

/*
 * Closes the 4-byte residue docs/notes/pkt_02037288_wave25.c.txt records
 * (the `mov r3, r4` / `lsl r1, r1, #1` pair at +0x00B0).  The lever is the
 * ALLOCATION RESULT TYPE, not the size spelling: the seven pointer fields
 * are declared `void *` so each GFL_HEAP_Alloc result is stored without an
 * integer conversion.  With them declared `u32` the file does not even
 * compile; with a cast at each site the argument scheduling shifts and the
 * 0xE8 call's size is finished before r3 is written.  The size arguments
 * themselves must stay as in-place expressions re-reading ->packetBufSize, never
 * bound to a local.
 *
 * The note's other two findings are confirmed and kept: the prototype
 * returns int (the tail `mov r0,#1` is a `return 1`), and the +0x1E0 store
 * is two separate `+ 0x40` adds in the two arms, not one factored add.
 */
int GFL_NET_SYSTEM_InitWork(u32 packetSize, u32 heapId, u32 useParentSize)
{
    u32 maxMembers;
    u32 parentSendSize;

    if (_pNetSys == 0) {
        maxMembers = GFL_NET_GetMaxConnectNum();
        parentSendSize = GFL_NET_SYSTEM_GetSendSize();
        _pNetSys = GFL_HEAP_Alloc(heapId, 0x1f0, 1, _FileName, 0xdd);
        if (useParentSize != 0)
            _pNetSys->packetBufSize = parentSendSize + 0x40;
        else
            _pNetSys->packetBufSize = packetSize + 0x40;

        _pNetSys->parentRecvRingData = GFL_HEAP_Alloc(heapId, _pNetSys->packetBufSize * 3, 1,
                                          _FileName, 0xe6);
        _pNetSys->recvScratchBuf = GFL_HEAP_Alloc(heapId, _pNetSys->packetBufSize * 2, 1,
                                          _FileName, 0xe8);
        _pNetSys->recvRingData = GFL_HEAP_Alloc(heapId, maxMembers * _pNetSys->packetBufSize, 1,
                                          _FileName, 0xe9);
        _pNetSys->sendPacketBuf = GFL_HEAP_Alloc(heapId, GFL_NET_GetChildSendSize(), 1,
                                          _FileName, 0xec);
        _pNetSys->sendRingData = GFL_HEAP_Alloc(heapId, GFL_NET_GetChildSendSize() * 15, 1,
                                          _FileName, 0xed);
        _pNetSys->mpParentPacketBuf = GFL_HEAP_Alloc(heapId, parentSendSize, 1, _FileName, 0xee);
        _pNetSys->mpParentRingData = GFL_HEAP_Alloc(heapId, parentSendSize * 2, 1, _FileName, 0xef);
        GFL_NET_QUEUE_Init(&_pNetSys->sendQueue, 0x64,
                      &_pNetSys->sendRing, heapId);
        GFL_NET_QUEUE_Init(&_pNetSys->mpParentSendQueue, 0xb4,
                      &_pNetSys->mpParentSendRing, heapId);
        _pNetSys->mpWaitMode = 1;
        GFL_NET_SYSTEM_ResetBuffers();
    }
    _pNetSys->memberBitmap = 0;
    _pNetSys->noChildError = 0;
    return 1;
}

/*
 * Second half of net_system init: wipe and re-seed every buffer
 * GFL_NET_SYSTEM_InitWork allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. GFL_NET_RING_BUFF_Init is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as GFL_NET_SYSTEM_ResetRecvBuffer); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
void GFL_NET_SYSTEM_ResetBuffers(void)
{
    s32 i;
    s32 maxMembers;
    s32 parentSendSize;
    s32 childSendSize;

    maxMembers = GFL_NET_GetMaxConnectNum();
    parentSendSize = GFL_NET_SYSTEM_GetSendSize();
    childSendSize = GFL_NET_GetChildSendSize();

    MI_CpuFill8(_pNetSys->recvRingData, 0, _pNetSys->packetBufSize * maxMembers);
    for (i = 0; i < maxMembers; i++) {
        GFL_NET_RING_BUFF_Init(&_pNetSys->recvRing[i],
              (u8 *)(_pNetSys->recvRingData + i * _pNetSys->packetBufSize), _pNetSys->packetBufSize);
        _pNetSys->recvSeq[i] = 0;
    }

    MI_CpuFill8(_pNetSys->mpParentRingData, 0, parentSendSize + parentSendSize);
    GFL_NET_RING_BUFF_Init(&_pNetSys->mpParentSendRing, (u8 *)_pNetSys->mpParentRingData, (u32)parentSendSize << 1);
    for (i = 0; i < parentSendSize; i++)
        _pNetSys->mpParentPacketBuf[i] = 0;

    MI_CpuFill8(_pNetSys->sendRingData, 0, childSendSize * 16 - childSendSize);
    GFL_NET_RING_BUFF_Init(&_pNetSys->sendRing, (u8 *)_pNetSys->sendRingData, ((u32)childSendSize << 4) - childSendSize);
    *_pNetSys->sendPacketBuf = 0xff;
    for (i = 1; i < childSendSize; i++)
        _pNetSys->sendPacketBuf[i] = 0;

    MI_CpuFill8(_pNetSys->parentRecvRingData, 0, _pNetSys->packetBufSize + _pNetSys->packetBufSize * 2);
    GFL_NET_RING_BUFF_Init(&_pNetSys->parentRecvRing, (u8 *)_pNetSys->parentRecvRingData,
                  _pNetSys->packetBufSize * 3);
    for (i = 0; i < GFL_NET_MACHINE_MAX; i++) {
        GFL_NET_SYSTEM_InitRecvState(&_pNetSys->recvCursor[i]);
        _pNetSys->recvPending[i] = 0;
    }
    _pNetSys->parentRecvPending = 0;
    GFL_NET_SYSTEM_InitRecvState(&_pNetSys->parentRecvCursor);
    GFL_NET_SYSTEM_SetDebugByte(4, 0x13a);
    _NetPhase[1] = 4;
    GFL_NET_QUEUE_Reset(&_pNetSys->sendQueue);
    GFL_NET_QUEUE_Reset(&_pNetSys->mpParentSendQueue);
    _pNetSys->sendBusy = 0;
    _pNetSys->sendReady = 1;
    _pNetSys->noSend = 0;
    _pNetSys->ircRecvPending = 0;
}

/*
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: GFL_NET_RING_BUFF_Init here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride packetBufSize passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { recvRingData + i * packetBufSize, packetBufSize }.
 */
void GFL_NET_SYSTEM_ResetRecvBuffer(int netId)
{
    if (netId >= GFL_NET_MACHINE_MAX) {
        GF_PANIC_Fail(_FileName, 0x155, _AssertNetIdRange);
    }
    _pNetSys->recvPending[netId] = 0;
    GFL_NET_RING_BUFF_Init(&_pNetSys->recvRing[netId], (u8 *)(_pNetSys->recvRingData + netId * _pNetSys->packetBufSize), _pNetSys->packetBufSize);
    _pNetSys->recvSeq[netId] = 0;
    GFL_NET_SYSTEM_InitRecvState(&_pNetSys->recvCursor[netId]);
}

/*
 * Filed on lane 1 as the single-caller callee of src/pending/GFL_NET_STATE_WifiMatchStart.c.
 * The 0x340 field is a table of function pointers reached through two
 * indirect calls; the third reaches a slot at +0x68 past two unread words at
 * +0x44 and +0x48, which is why the struct keeps them as padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_InitDevice.c \
 *       --func GFL_NET_SYSTEM_InitDevice --addr 0x02037700 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_InitDevice(u32 packetSize, u32 heapId)
{
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();
    u32 useParentSize = 0;

    if (session->init.bMPMode != 0 && session->init.parentSendSize != 0)
        useParentSize = 1;
    GFL_NET_SYSTEM_InitWork(packetSize, heapId, useParentSize);
    session->ops->setup(initParam->init.heapId, session, 0, session->userArg);
    session->ops->begin(0);
    session->ops->setEventCallback(GFL_NET_SYSTEM_RecvChildData);
    return 1;
}

/*
 * 32-byte hook dispatcher: GFL_NET_GetSession returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SetDeviceOption.c \
 *       --func GFL_NET_SYSTEM_SetDeviceOption --addr 0x0203778C --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_SetDeviceOption(u32 arg)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u32 (*isFriendWaiting)(u32) = session->ops->isFriendWaiting;

    return isFriendWaiting(arg);
}

u32 GFL_NET_SYSTEM_RecvCallback(u32 netId, u8 *packet, u32 length)
{
    return GFL_NET_SYSTEM_RecvData(netId, packet, length);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ConnectDevice.c \
 *       --func GFL_NET_SYSTEM_ConnectDevice --addr 0x020377B8 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_ConnectDevice(u8 renewTgid)
{
    u32 zero;
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();
    u16 heapId;
    void (*setEventCallback)(void *);

    initParam->init.bRenewTgid = renewTgid;
    setEventCallback = session->ops->setEventCallback;
    setEventCallback(GFL_NET_SYSTEM_RecvCallback);

    zero = 0;
    heapId = initParam->init.heapId;
    GFL_NET_SYSTEM_InitWork(0x80, heapId, zero);

    GFL_NET_SYSTEM_ResetRecvBuffer(zero);
    GFL_NET_SYSTEM_ResetRecvBuffer(1);
    GFL_NET_SYSTEM_ResetRecvBuffer(2);

    return 1;
}

/*
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ParentConnectHook.c \
 *       --func GFL_NET_SYSTEM_ParentConnectHook --addr 0x0203781C --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_ParentConnectHook(u32 netId)
{
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();
    void (*hook)(u32, u32);

    GFL_NET_SYSTEM_ResetRecvBuffer(netId);

    hook = initParam->init.connectFunc;
    if (hook == 0)
        return;
    hook(session->userArg, netId);
}

/*
 * Byte-for-byte twin of GFL_NET_SYSTEM_ParentConnectHook (same 60 bytes, same call order): two
 * context getters, the per-slot reset for `arg`, then the hook at +8 of the
 * first context when it is installed, called with the first context's word at
 * +0x34C and the argument.  Two copies of the same 60 bytes exist in the image
 * and this is the second, so the pair also demonstrates that the listing's
 * duplicate-glue pattern is real code and not one function reached twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ChildConnectHook.c \
 *       --func GFL_NET_SYSTEM_ChildConnectHook --addr 0x02037858 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_ChildConnectHook(u32 netId)
{
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();
    void (*hook)(u32, u32);

    GFL_NET_SYSTEM_ResetRecvBuffer(netId);

    hook = initParam->init.connectFunc;
    if (hook == 0)
        return;
    hook(session->userArg, netId);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_StartParent.c \
 *       --func GFL_NET_SYSTEM_StartParent --addr 0x02037894 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_StartParent(u8 renewTgid, u16 packetSize, u32 sendArg0, u32 sendArg1)
{
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();
    u32 flag;
    u16 heapId;
    void (*setRecvCallback)(void *);
    void (*setEventCallback)(void *);
    u32 (*sendToParent)(u32, u32);

    initParam->init.bRenewTgid = renewTgid;

    setRecvCallback = session->ops->setConnectCallback;
    setRecvCallback(GFL_NET_SYSTEM_ParentConnectHook);

    setEventCallback = session->ops->setEventCallback;
    setEventCallback(GFL_NET_SYSTEM_RecvChildData);

    if (session->init.bMPMode != 0 && session->init.parentSendSize != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    initParam = GFL_NET_GetInitParam();
    heapId = initParam->init.heapId;
    GFL_NET_SYSTEM_InitWork(packetSize, heapId, flag);

    sendToParent = session->ops->startParent;
    return sendToParent(sendArg0, sendArg1);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_StartBeaconScan.c \
 *       --func GFL_NET_SYSTEM_StartBeaconScan --addr 0x02037928 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_StartBeaconScan(u32 sendArg, u16 packetSize)
{
    GFLNetSession *session = GFL_NET_GetSession();
    void (*setRecvCallback)(void *);
    u32 (*sendToChild)(u32, u32);
    void (*setEventCallback)(void *);
    u32 result;
    u32 flag;
    GFLNetSession *initParam;
    u16 heapId;

    setRecvCallback = session->ops->setConnectCallback;
    setRecvCallback(GFL_NET_SYSTEM_ChildConnectHook);

    sendToChild = session->ops->startChildScan;
    result = sendToChild(sendArg, 0);

    if (result == 1) {
        setEventCallback = session->ops->setEventCallback;
        setEventCallback(GFL_NET_SYSTEM_RecvParentData);

        if (session->init.bMPMode != 0 && session->init.parentSendSize != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        initParam = GFL_NET_GetInitParam();
        heapId = initParam->init.heapId;
        GFL_NET_SYSTEM_InitWork(packetSize, heapId, flag);

        _NetPhase[1] = 4;
    }

    return result;
}

/*
 * Context teardown through three vtable slots at +0x3c, +0xbc and +0x68 of the
 * object the context's word at +0x340 names.  The first and third are handed a
 * function address as their argument (0x02037858 and 0x02038924), which is why
 * the pool holds two code pointers; the +0xbc slot's answer decides whether the
 * rest runs, and the byte at +1 of the object at 0x020A7A20 is set to 4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_EndDevice.c \
 *       --func GFL_NET_SYSTEM_EndDevice --addr 0x020379C8 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_EndDevice(u32 packetSize)
{
    int   result;
    GFLNetSession *session = GFL_NET_GetSession();

    session->ops->setConnectCallback(GFL_NET_SYSTEM_ChildConnectHook);
    result = session->ops->startAutoSearch();
    if (result == 1) {
        session->ops->setEventCallback(GFL_NET_SYSTEM_RecvParentData);
        GFL_NET_SYSTEM_InitWork(packetSize, GFL_NET_GetInitParam()->init.heapId, 0);
        _NetPhase[1] = 4;
    }
    return result;
}

void GFL_NET_SYSTEM_SetDeviceMode(int interval)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetModeOps *ops = session->ops;
    if (ops == 0)
        return;
    ops->startJoinLock(interval);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ConnectToParent.c \
 *       --func GFL_NET_SYSTEM_ConnectToParent --addr 0x02037A6C --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_ConnectToParent(u32 beaconArg0, u32 beaconArg1, u16 packetSize, u32 beaconArg2)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    void (*setEventCallback)(void *);
    u32 flag;
    u16 heapId;
    u32 (*sendBeaconData)(u32, u32, u32, u32, u32);

    setEventCallback = session->ops->setEventCallback;
    setEventCallback(GFL_NET_SYSTEM_RecvParentData);

    if (beaconArg0 != 0) {
        if (session->init.bMPMode != 0 && session->init.parentSendSize != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        initParam = GFL_NET_GetInitParam();
        heapId = initParam->init.heapId;
        GFL_NET_SYSTEM_InitWork(packetSize, heapId, flag);

        _NetPhase[1] = 4;
    }

    sendBeaconData = session->ops->startChild;
    return sendBeaconData(beaconArg0, beaconArg1, 0, 0, beaconArg2);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_FreeWork.c \
 *       --func GFL_NET_SYSTEM_FreeWork --addr 0x02037B08 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_FreeWork(void)
{
    GFL_NET_GetSession();
    GFL_NET_GetInitParam();

    if (_pNetSys == 0) {
        return;
    }

    GFL_HEAP_Free(_pNetSys->parentRecvRingData);
    GFL_HEAP_Free(_pNetSys->recvScratchBuf);
    GFL_HEAP_Free(_pNetSys->recvRingData);

    GFL_NET_QUEUE_Exit(&_pNetSys->mpParentSendQueue);
    GFL_NET_QUEUE_Exit(&_pNetSys->sendQueue);

    GFL_HEAP_Free(_pNetSys->sendPacketBuf);
    GFL_HEAP_Free(_pNetSys->sendRingData);
    GFL_HEAP_Free(_pNetSys->mpParentPacketBuf);
    GFL_HEAP_Free(_pNetSys->mpParentRingData);

    GFL_HEAP_Free(_pNetSys);

    _pNetSys = 0;
}

/*
 * 64 bytes gated on the byte at +0x1EC of the object the global pointer names:
 * when it is set, the first getter's non-zero answer runs GFL_NET_SYSTEM_FreeWork and
 * returns, the second getter's non-zero answer returns without it, and
 * everything else runs GFL_NET_SYSTEM_FreeWork.  The two `bl GFL_NET_SYSTEM_FreeWork` are separate
 * copies in the original, which is what the two arms give.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_FreeWorkIfAuto.c \
 *       --func GFL_NET_SYSTEM_FreeWorkIfAuto --addr 0x02037BA4 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_FreeWorkIfAuto(void)
{
    if (_pNetSys->autoFree == 0)
        return;
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (GFL_NET_SYSTEM_GetChildBitmap() == 0)
            GFL_NET_SYSTEM_FreeWork();
        return;
    }
    GFL_NET_SYSTEM_FreeWork();
}

/*
 * Guards the eight-slot table behind the global at 0x021469D0: an unarmed
 * global returns through `popeq`, an index past 7 through `popcs` (the compare
 * is unsigned, so a negative index is rejected as well), and only a live slot
 * reaches GFL_NET_SYSTEM_ResetRecvBuffer.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ResetMachineBuffer.c \
 *       --func GFL_NET_SYSTEM_ResetMachineBuffer --addr 0x02037BE8 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_ResetMachineBuffer(u32 netId)
{
    if (_pNetSys == 0)
        return;
    if (netId >= GFL_NET_MACHINE_MAX)
        return;
    GFL_NET_SYSTEM_ResetRecvBuffer(netId);
}

/*
 * The net tick dispatcher.  Two shapes are load-bearing: the noSend/0x393D0
 * early exit is an out-of-line `goto bail` block placed AFTER the main body,
 * and the main path's `return 1` is reached by a `goto done` that lands on
 * the SAME `mov r0,#1; pop` the bail block falls into.  Writing either as a
 * plain `return 1` duplicates the epilogue and loses the `b #0x2037d6c`.
 */
int GFL_NET_SYSTEM_Main(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *initParam = GFL_NET_GetInitParam();

    if (_pNetSys == 0) {
        if (session != 0)
            session->ops->update(0);
        return 1;
    }

    {
        u32 (*getSignalLevel)(void) = session->ops->getSignalLevel;
        if (getSignalLevel != 0) {
            GFL_NET_WM_ICON_EasySetLevel(getSignalLevel());
        }
    }

    if (_pNetSys->noSend != 0)
        goto bail;
    if (GFL_NET_SYSTEM_IsError() != 0)
        goto bail;

    if (initParam->init.bMPMode == 0 && (initParam->init.bNetType == 0 || initParam->init.bNetType == 5)) {
        GFL_NET_SYSTEM_SendWireless();
    } else if ((u8)(initParam->init.bNetType + 0xfd) <= 1) {
        GFL_NET_SYSTEM_SendWifi();
    } else if ((u8)(initParam->init.bNetType + 0xff) <= 1) {
        GFL_NET_SYSTEM_SendIrc();
    } else {
        GFL_NET_SYSTEM_SendMP();
        GFL_NET_SYSTEM_ProcessParentRecv();
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            if (GFL_NET_SYSTEM_IsConnectMember(0) != 0 && initParam->init.bMPMode != 0)
                GFL_NET_SYSTEM_UpdateMPParent();
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
            goto skip;
    }
    GFL_NET_SYSTEM_ProcessChildRecv();
skip:
    if (initParam->init.bNetType != 1 && initParam->init.bNetType != 2) {
        session->ops->update(
            _pNetSys->memberBitmap);
    }
    GFL_NET_COMMAND_Main();
    GFL_NET_SYSTEM_FreeWorkIfAuto();
    goto done;

bail:
    session->ops->update(0);
done:
    return 1;
}

/*
 * Teardown hook for the same global src/matched/GFL_NET_SYSTEM_ResetMachineBuffer.c guards: the
 * armed pointer goes to GFL_NET_SYSTEM_ResetBuffers, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ResetAll.c \
 *       --func GFL_NET_SYSTEM_ResetAll --addr 0x02037D78 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_ResetAll(void)
{
    struct NetSysWork *work;

    work = _pNetSys;
    if (work == 0)
        return;
    GFL_NET_SYSTEM_ResetBuffers();
}

int GFL_NET_SYSTEM_PackSendData(int checkPending)
{
    int result = 0;
    if (_NetPhase[1] != 4)
        return result;
    if (checkPending != 0) {
        struct NetSysWork *work = _pNetSys;
        if (work->parentRecvPending > 0)
            return result;
        if (GFL_NET_SYSTEM_BuildSendPacket((struct NetPacketHeader *)work->sendPacketBuf, &work->sendQueue, GFL_NET_GetChildSendSize(), work->sendSeq) != 0) {
            struct NetSysWork *workAgain = _pNetSys;
            workAgain->sendSeq++;
        }
        _NetPhase[1] = 0;
        result = 1;
    } else {
        struct NetSysWork *work = _pNetSys;
        if (GFL_NET_SYSTEM_BuildSendPacket((struct NetPacketHeader *)work->sendPacketBuf, &work->sendQueue, GFL_NET_GetChildSendSize(), work->sendSeq) != 0) {
            struct NetSysWork *workAgain = _pNetSys;
            workAgain->sendSeq++;
            _NetPhase[1] = 0;
            result = 1;
        }
    }
    return result;
}

void GFL_NET_SYSTEM_SendParentData(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u32 childSendSize = GFL_NET_GetChildSendSize();
    u32 result;

    result = session->ops->isConnected();
    if (result == 0)
        return;
    result = GFL_NET_SYSTEM_GetCurrentAid();
    result = GFL_NET_SYSTEM_IsConnectMember(result);
    if (result == 0)
        return;
    if (_NetPhase[1] != 0)
        return;
    if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        result = session->ops->sendData((u32)_pNetSys->sendPacketBuf, childSendSize, 0, GFL_NET_SYSTEM_SendCallback);
        if (result == 0)
            return;
        _NetPhase[1] = 2;
        _pNetSys->parentRecvPending = _pNetSys->parentRecvPending + 1;
    } else {
        _NetPhase[1] = 2;
        GFL_NET_SYSTEM_SendCallback(1);
        GFL_NET_SYSTEM_RecvChildData(0, (NetPacketHeader *)_pNetSys->sendPacketBuf, (u16)childSendSize);
        _pNetSys->parentRecvPending = _pNetSys->parentRecvPending + 1;
    }
}

/*
 * Declaration order is what closes this one: p must be declared LAST of the
 * four locals so it takes r6 and the loop index takes r4 (see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The failure arm of the +0x5C poll is an out-of-line `goto`, not an
 * if-converted tail; the (u16) truncation of v happens after the n>0 test
 * and the index is zeroed before it.
 */
void GFL_NET_SYSTEM_SendWireless(void)
{
    s32 i;
    s32 maxMembers;
    u32 childSendSize;
    GFLNetSession *session;

    session = GFL_NET_GetSession();

    if (session->ops->isDataSharing() == 0)
        return;

    if (_pNetSys->sendReady != 0)
        GFL_NET_SYSTEM_PackSendData(1);

    if (session->ops->stepDataSharing((u32)_pNetSys->sendPacketBuf) != 1)
        goto fail;

    _NetPhase[1] = 4;
    _pNetSys->sendReady = 1;

    childSendSize = GFL_NET_GetChildSendSize();
    maxMembers = GFL_NET_GetMaxConnectNum();
    i = 0;
    if (maxMembers > 0) {
        childSendSize = (unsigned short)childSendSize;
        do {
        GFL_NET_SYSTEM_RecvChildData((unsigned short)i,
                      (NetPacketHeader *)(session->ops->getSharedData(i)), childSendSize);
            i++;
        } while (i < maxMembers);
    }
    return;

fail:
    _pNetSys->sendReady = 0;
}

/*
 * Fourth entry of this packet's chain, and the one the lane table expected to
 * need two callees filed: it calls GFL_NET_SYSTEM_RecvParentCallback, whose own entry is in this
 * shard, so that site resolves through `matched`; 0x020366A8 and 0x0203D3A8,
 * the other two the table named, turn out to have outside witnesses
 * (0x02038B48 and 0x02039AAC) once the compared range is this one function
 * rather than the whole packet.
 *
 * The two literals in the tail are different objects: the first argument to
 * GFL_NET_SYSTEM_RecvParentCallback is one dereference of the 0x021469D0 pointer word, and the
 * final store is into the byte at 0x020A7A20 + 1.  Reading them as the same
 * symbol makes the compiler pool the address once and spend a second
 * callee-saved register on the transfer value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SendWifi.c \
 *       --func GFL_NET_SYSTEM_SendWifi --addr 0x0203802C --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_SendWifi(void)
{
    GFLNetSession *session;
    u32 value;

    session = GFL_NET_GetSession();

    if (GFL_NET_QUEUE_IsEmpty(&_pNetSys->sendQueue) != 0)
        GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x10, 0, 0);

    value = (u32)session->ops->resetLink;
    if (value != 0)
        ((void (*)(void))value)();
    if (session->ops->isActive() != 1)
        return;

    value = GFL_NET_GetChildSendSize();
    if (session->ops->getErrorCode() != 1)
        return;
    if (GFL_NET_SYSTEM_PackSendData(0) == 0)
        return;

    GFL_NET_SYSTEM_RecvParentCallback((u32)_pNetSys->sendPacketBuf, value);
    _NetPhase[1] = 4;
}

/*
 * Validates one incoming record against the per-slot table reached through
 * 0x021469D0: the byte at +4 of the record is a presence/state tag (0xFF is
 * "locked out", bit 1 is the "no free slot" rejection), then the two-byte
 * header of the body is checked against the result of 0x0203F1FC, then the
 * slot's own counter byte at 0x1D7+slot is compared with rec[5]-1 before
 * being overwritten with rec[5].  Slot `netId` lives at 0x54 + (netId << 4), so the
 * per-slot block is 16 bytes and the counter table is a byte array.
 *
 * The +8 bit of rec[4] biases the third argument by 0xFF; both the globals are
 * re-read from the pointer word after every call, which is why the C indexes
 * _pNetSys directly instead of caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_RecvData.c \
 *       --func GFL_NET_SYSTEM_RecvData --addr 0x020380E4 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_RecvData(u32 netId, u8 *packet, u32 length)
{
    int checksum;
    u32 dataSize;

    GFL_NET_GetInitParam();
    GFL_NET_GetChildSendSize();

    if (packet[4] == 0xFF)
        return 0;
    if (_pNetSys->recvRing[netId].state == 0 && (packet[4] & 2))
        return 0;

    checksum = GF_STANDARD_CalcCrc16(packet + 2, length - 2);
    if (packet[0] != (u8)checksum || ((checksum & 0xFF00) >> 8) != packet[1])
        return 0;
    if (_pNetSys->recvSeq[netId] != 0 &&
        (u8)(packet[5] - 1) != _pNetSys->recvSeq[netId])
        return 0;

    _pNetSys->recvSeq[netId] = packet[5];
    dataSize = packet[2];
    if (packet[4] & 8)
        dataSize += 0xFF;
    GFL_NET_RING_BUFF_Write(&_pNetSys->recvRing[netId], packet + 7, dataSize);
    _pNetSys->recvRing[netId].state = 1;
    return 1;
}

/*
 * Second half of this packet's chain: it calls GFL_NET_SYSTEM_RecvData, whose own entry
 * is in this shard, so the call site is attested by `matched` rather than by
 * the single in-range witness the lane table saw.
 *
 * The flow: two global locks are set up, then the interface object reached
 * through *(p + 0x340) is asked twice (its +0xA4 and +0xAC entries); only if
 * both answer non-zero does the transfer run - otherwise the two literals at
 * 0x020A7A24/0x020A7A50 go to 0x02034714 with 0x400.  The transfer calls the
 * object's +0x64 entry with the two arguments and zeroed r2/r3, reads the
 * +0x80 entry for the record number, and hands (u16)record-number, first
 * argument and (u16)second argument to GFL_NET_SYSTEM_RecvData before the fixed 4 /
 * 0x40C delay through 0x02037224.
 *
 * The guards' polarity is the `bne` / `beq` pair at +0x2C and +0x38: the two
 * object calls are one conjunction whose false arm is the failure block
 * written first, which is the if/else spelling and not a guard chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_RecvParentCallback.c \
 *       --func GFL_NET_SYSTEM_RecvParentCallback --addr 0x020381D8 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_RecvParentCallback(u32 buffer, u32 size)
{
    GFLNetSession *session;
    u32 aid;

    GFL_NET_GetInitParam();
    session = GFL_NET_GetSession();

    if (session->ops->getChannel() == 0 ||
        session->ops->getTgid() == 0) {
        GF_PANIC_Fail(_FileName, 0x400, _AssertAlways);
        return;
    }

    if (_NetPhase[1] != 0)
        return;
    session->ops->sendData(buffer, size, 0, 0);
    aid = session->ops->getMyAid();
    GFL_NET_SYSTEM_RecvData((u16)aid, (u8 *)buffer, (u16)size);
    GFL_NET_SYSTEM_SetDebugByte(4, 0x40C);
}

/*
 * Third entry of this packet's chain, and the one that shows why the object
 * word has to be re-read rather than cached: 0x021469D0 is a pointer word and
 * every use of the object it points at goes back through the pool address, so
 * the C indexes _pNetSys directly each time.
 *
 * The state machine is three bytes of the object (0x1E7 = "armed", 0x1ED =
 * "in flight", 0x1D5 = a mode byte feeding 0x02038AE0): returning early
 * unless armed, arming the in-flight flag once 0x02038AE0 agrees, and only
 * then running the object's +0x64 entry, which clears the flag when it
 * returns non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SendIrc.c \
 *       --func GFL_NET_SYSTEM_SendIrc --addr 0x02038298 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_SendIrc(void)
{
    GFLNetSession *session;
    u32 childSendSize;

    GFL_NET_GetInitParam();
    session = GFL_NET_GetSession();
    childSendSize = GFL_NET_GetChildSendSize();

    if (_pNetSys->noChildError == 0)
        return;
    if (_pNetSys->ircRecvPending == 0) {
        if (GFL_NET_SYSTEM_BuildSendPacket((struct NetPacketHeader *)_pNetSys->sendPacketBuf, &_pNetSys->sendQueue,
                          GFL_NET_GetChildSendSize(),
                          _pNetSys->sendSeq) != 0)
            _pNetSys->ircRecvPending = 1;
    }

    if (_pNetSys->ircRecvPending != 1)
        return;
    if (session->ops->sendData((u32)_pNetSys->sendPacketBuf, childSendSize,
                                                    0, 0) == 0)
        return;
    _pNetSys->ircRecvPending = 0;
}

/*
 * Promoted from src/pending/ on lane 1.  All 64 concrete bytes are right; the
 * one open site was the PC24 at +0x0038, the `bl` to GFL_NET_SYSTEM_SendParentData, which had
 * exactly one branch reference in the whole image (this one) and so no
 * `label` witness.  With src/matched/GFL_NET_SYSTEM_SendParentData.c filed EXACT the site
 * resolves through the `matched` class and the file prints EXACT with no
 * change to its C.
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether GFL_NET_SYSTEM_PackSendData(1) and GFL_NET_SYSTEM_SendParentData are reached.  The first
 * GFL_NET_GetInitParam() result is discarded - the image overwrites r0 with
 * GFL_NET_GetSession()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_SYSTEM_SendMP.c \
 *       --func GFL_NET_SYSTEM_SendMP --addr 0x02038340 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_SendMP(void)
{
    GFLNetSession *session;

    GFL_NET_GetInitParam();
    session = GFL_NET_GetSession();
    if (session->ops->isConnected() == 0)
        return;
    if (GFL_NET_SYSTEM_IsConnectMember(GFL_NET_SYSTEM_GetCurrentAid()) == 0)
        return;
    GFL_NET_SYSTEM_PackSendData(1);
    GFL_NET_SYSTEM_SendParentData();
}

void GFL_NET_SYSTEM_SendMPParent(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    GFL_NET_GetMaxConnectNum();
    if (_NetPhase[0] == 1) {
        if ((int)GFL_NET_SYSTEM_GetConnectNum() > 1) {
            GFL_NET_SYSTEM_SetDebugByte(2, 0x46a);
            if (session->ops->isConnected() != 0) {
                u32 size = GFL_NET_SYSTEM_GetSendSize();
                if (session->ops->sendData(
                        (u32)_pNetSys->mpParentPacketBuf, size, 0, GFL_NET_SYSTEM_SendEndCallback) != 0)
                    goto tail;
                GFL_NET_SYSTEM_SetDebugByte(1, 0x46a + 4);
                goto tail;
            }
            if ((GFL_NET_GetInitParam())->init.bNetType != 3 && (GFL_NET_GetInitParam())->init.bNetType != 4)
                goto tail;
            if (session->ops->getErrorCode() == 0) {
                GFL_NET_SYSTEM_SetDebugByte(1, 0x475);
                goto tail;
            }
            if (_pNetSys->mpParentPacketBuf[2] == 0)
                return;
            {
                u32 size = GFL_NET_GetChildSendSize();
                session->ops->sendData(
                    (u32)_pNetSys->mpParentPacketBuf, size, 0x64, 0);
            }
        }
    }
tail:
    if (_NetPhase[0] == 2) {
        GFL_NET_SYSTEM_ClearChildRecv();
        GFL_NET_SYSTEM_RecvParentData(0, (NetPacketHeader *)_pNetSys->mpParentPacketBuf, (u16)GFL_NET_SYSTEM_GetSendSize());
        GFL_NET_SYSTEM_SetDebugByte(3, 0x490 - 3);
    }
    if (session->ops->isConnected() == 0)
        goto last;
    if ((GFL_NET_GetInitParam())->init.bNetType == 3)
        goto last;
    if ((GFL_NET_GetInitParam())->init.bNetType != 4)
        return;
last:
    GFL_NET_SYSTEM_SetDebugByte(4, 0x492);
}

int GFL_NET_SYSTEM_CheckAllChildRecv(void)
{
    int i;

    for (i = 0; i < GFL_NET_MACHINE_MAX; i++) {
        if (GFL_NET_SYSTEM_IsConnectMember((u16)i) != 0 && _pNetSys->recvPending[i] > 0) {
            return 0;
        }
    }
    return 1;
}

void GFL_NET_SYSTEM_ClearChildRecv(void)
{
    int i;
    int maxMembers = GFL_NET_GetMaxConnectNum();

    for (i = 0; i < maxMembers; i++) {
        if (GFL_NET_SYSTEM_IsConnectMember((u16)i) != 0) {
            _pNetSys->recvPending[i] += 1;
        }
    }
}

/*
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to GFL_NET_SYSTEM_SendMPParent in both of the middle bands.
 * GFL_NET_SYSTEM_SetDebugByte takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual GF_PANIC_Fail(file, line, expr) triple.
 */
void GFL_NET_SYSTEM_UpdateMPParent(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *initParam = GFL_NET_GetInitParam();
    u8 netType = initParam->init.bNetType;

    if ((u8)(netType + 0xff) <= 1) {
        if (GFL_NET_SYSTEM_IsConnectMember(0) == 0)
            return;
        if (initParam->init.bMPMode != 0)
            GF_PANIC_Fail(_FileName, 0x4d5, _AssertNotMpMode);
        if (_NetPhase[0] == 4 && _pNetSys->mpWaitMode != 0
            && GFL_NET_SYSTEM_CheckAllChildRecv() != 0)
            GFL_NET_SYSTEM_SetDebugByte(1, 0x4da);
        if (_NetPhase[0] != 1)
            return;
        {
            u32 size = GFL_NET_SYSTEM_GetSendSize();
            if (session->ops->sendData(
                    (u32)_pNetSys->mpParentPacketBuf, size, 0, 0) == 0)
                return;
        }
        GFL_NET_SYSTEM_SetDebugByte(4, 0x4e1);
        GFL_NET_SYSTEM_ClearChildRecv();
        return;
    }
    if ((u8)(netType + 0xfd) <= 1) {
        if (_NetPhase[0] == 4) {
            struct NetSysWork *work = _pNetSys;
            u32 size = GFL_NET_SYSTEM_GetSendSize();

            GFL_NET_SYSTEM_BuildSendPacket((struct NetPacketHeader *)work->mpParentPacketBuf, &work->mpParentSendQueue, size, work->mpParentSeq);
            work = _pNetSys;
            work->mpParentSeq = (u8)(work->mpParentSeq + 1);
            GFL_NET_SYSTEM_SetDebugByte(1, 0x4f4);
        }
        GFL_NET_SYSTEM_SendMPParent();
        return;
    }
    if (session->ops->isConnected() == 0)
        return;
    if (GFL_NET_SYSTEM_CheckAllChildRecv() == 0)
        return;
    if (_NetPhase[0] == 4) {
        struct NetSysWork *work = _pNetSys;
        u32 size = GFL_NET_SYSTEM_GetSendSize();

        GFL_NET_SYSTEM_BuildSendPacket((struct NetPacketHeader *)work->mpParentPacketBuf, &work->mpParentSendQueue, size, work->mpParentSeq);
        work = _pNetSys;
        work->mpParentSeq = (u8)(work->mpParentSeq + 1);
        GFL_NET_SYSTEM_SetDebugByte(1, 0x501);
    }
    GFL_NET_SYSTEM_SendMPParent();
}

/*
 * The indexed twin of src/matched/GFL_NET_SYSTEM_RecvParentData.c (the own-slot variant):
 * same receive/validate/copy shape, but every global offset is scaled by
 * the slot index -- the 0x1B4 credit counter by i*4, the 0x54 accepted
 * flag and the 0x4C payload by i*16, the 0x1D7 sequence byte by i.  The
 * extra middle block this one has and 0x02038924 does not is the sequence
 * check at 0x1D7+i with its own 0x3F3 error line.
 */
int GFL_NET_SYSTEM_RecvChildData(u32 netId, NetPacketHeader *packet, s32 length)
{
    struct NetSysWork *work;
    struct NetErrorInfo *errorInfo;
    u32 flags;
    s32 dataSize;
    int checksum;

    GFL_NET_GetChildSendSize();
    if (packet == 0)
        return 0;
    work = _pNetSys;
    work->recvPending[netId] = work->recvPending[netId] - 1;
    if (netId == 0)
        _pNetSys->memberBitmap = packet->memberBitmap;
    flags = packet->flags;
    if (flags == 0xff)
        return 0;
    if (_pNetSys->recvRing[netId].state == 0) {
        if (flags & 2)
            return 0;
    }
    checksum = GF_STANDARD_CalcCrc16(&packet->size, length - 2);
    if (packet->checksumLow != (u8)checksum || ((checksum & 0xff00) >> 8) != packet->checksumHigh) {
        GFL_NET_SYSTEM_SetError();
        errorInfo = (struct NetErrorInfo *)GFL_NET_STATE_GetError();
        if (errorInfo->gameCode == 0)
            GFL_NET_STATE_SetError(errorInfo->errorCode, errorInfo->errorType, errorInfo->dwcError, 0x3f2);
        return 0;
    }
    {
        u8 *recvSeq = _pNetSys->recvSeq;
        if (recvSeq[netId] != 0 && (u8)(packet->seq - 1) != recvSeq[netId]) {
            GFL_NET_SYSTEM_SetError();
            errorInfo = (struct NetErrorInfo *)GFL_NET_STATE_GetError();
            if (errorInfo->gameCode == 0)
                GFL_NET_STATE_SetError(errorInfo->errorCode, errorInfo->errorType, errorInfo->dwcError, 0x3f3);
            return 0;
        }
        recvSeq[netId] = packet->seq;
    }
    dataSize = packet->size;
    if (packet->flags & 8)
        dataSize += 0xff;
    GFL_NET_RING_BUFF_Write(&_pNetSys->recvRing[netId], packet->body, dataSize);
    _pNetSys->recvRing[netId].state = 1;
    return 1;
}

int GFL_NET_SYSTEM_RecvParentData(u32 netId, NetPacketHeader *packet, s32 length)
{
    struct NetSysWork *work;
    struct NetErrorInfo *errorInfo;
    u32 flags;
    s32 dataSize;
    int checksum;

    (int)GFL_NET_GetInitParam();
    GFL_NET_GetChildSendSize();
    work = _pNetSys;
    work->parentRecvPending = work->parentRecvPending - 1;
    if (packet == 0)
        return 0;
    if (netId == 0)
        _pNetSys->memberBitmap = packet->memberBitmap;
    flags = packet->flags;
    if (flags == 0xff)
        return 0;
    if (_pNetSys->parentRecvRing.state == 0) {
        if (flags & 2)
            return 0;
    }
    checksum = GF_STANDARD_CalcCrc16(&packet->size, length - 2);
    if (packet->checksumLow != (u8)checksum || ((checksum & 0xff00) >> 8) != packet->checksumHigh) {
        GFL_NET_SYSTEM_SetError();
        errorInfo = (struct NetErrorInfo *)GFL_NET_STATE_GetError();
        if (errorInfo->gameCode == 0)
            GFL_NET_STATE_SetError(errorInfo->errorCode, errorInfo->errorType, errorInfo->dwcError, 0x3f2);
        return 0;
    }
    _pNetSys->parentRecvSeq = packet->seq;
    dataSize = packet->size;
    if (packet->flags & 8)
        dataSize += 0xff;
    GFL_NET_RING_BUFF_Write(&_pNetSys->parentRecvRing, packet->body, dataSize);
    _pNetSys->parentRecvRing.state = 1;
    return 1;
}

/*
 * Idempotent bring-up: when the argument is non-zero and the mode byte at
 * 0x020A7A21 still reads 2, it is flipped to 4 and the call is skipped; in
 * every other case the 0x5C0-byte block at 0x020A7A24 is handed to
 * GF_PANIC_Fail with 0x020A7A50 as the third argument.  Either way the
 * function answers 1 through the single shared epilogue (`mov r0, #1;
 * pop {r3, pc}`), which is why the taken arm ends in `beq` to that epilogue
 * and not in a predicated return.
 *
 * The three globals are *arrays*, not pointers: the image loads the pool word
 * straight into r0 and then does `ldrb r1, [r0, #1]`, so `extern u8
 * _NetPhase[]` with a `[1]` subscript is the spelling that reproduces it - as
 * `extern u8 *_NetPhase` the compiler adds a second load and the file grows
 * to 88 bytes.  The arm's two instructions are predicated (`moveq`/`strbeq`)
 * rather than branched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SendCallback.c \
 *       --func GFL_NET_SYSTEM_SendCallback --addr 0x02038A48 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_SendCallback(int success)
{
    if (success != 0 && _NetPhase[1] == 2) {
        _NetPhase[1] = 4;
    } else {
        GF_PANIC_Fail(_FileName, 0x5C0, _AssertAlways);
    }
    return 1;
}

int GFL_NET_SYSTEM_SendEndCallback(u32 success)
{
    GFL_NET_GetChildSendSize();
    GFL_NET_GetMaxConnectNum();
    GFL_NET_GetInitParam();
    if (success != 0) {
        GFL_NET_SYSTEM_SetDebugByte(4, 0x5d4);
    } else {
        GF_PANIC_Fail(_FileName, 0x5d8, _AssertAlways);
    }
    return 1;
}

s32 GFL_NET_SYSTEM_BuildSendPacket(struct NetPacketHeader *header, NetQueue *queue, s32 packetSize, u8 seq)
{
    GFLNetSession *initParam;
    GFLNetSession *session;
    struct NetPacketSpan span;
    s32 dataSize;
    u16 checksum;

    initParam = GFL_NET_GetInitParam();
    session = GFL_NET_GetSession();

    MI_CpuFill8(header, 0, (u32)packetSize);

    if (queue->sendContinued == 0)
        header->flags = 1;
    else
        header->flags = 2;
    queue->sendContinued = 0;

    header->memberBitmap = session->ops->getAidBitmap();

    if (GFL_NET_QUEUE_IsEmpty(queue) == 0)
    {
        if ((u8)(initParam->init.bNetType + 0xfd) > 1)
            goto body;
        if (session->ops->isBusy() != 1)
            goto body;
    }
    header->flags = 0xff;
    return 0;

body:
    ;

    span.remaining = (u16)(packetSize - 7);
    span.dest = &header->body[0];
    if (GFL_NET_QUEUE_FillSendBuffer((struct NetQueue *)queue, (struct NetSendBuf *)(&span)) == 0)
        queue->sendContinued = 1;

    if (span.remaining != 0xffff)
        dataSize = (packetSize - span.remaining) - 7;
    else
        dataSize = packetSize - 7;

    if (dataSize > 0xff)
    {
        dataSize = dataSize + 1;
        header->flags = header->flags | 8;
    }

    header->size = (u8)dataSize;
    header->seq = seq;

    checksum = GF_STANDARD_CalcCrc16(&header->size, packetSize - 2);
    header->checksumLow = (u8)checksum;
    header->checksumHigh = (u8)((checksum & 0xff00) >> 8);

    return 1;
}

/*
 * Seven-argument entry to the comms send path.  The seventh argument is a
 * flag whose INVERSE becomes the `broadcast` byte handed to GFL_NET_QUEUE_Put:
 * `flag == 0` gives 1, anything else gives 0, materialised as
 * `mov r5,#1` / `cmp r4,#0` / `movne r5,#0` before the first call.
 *
 * The module handle behind the global at 0x021469D0 is fetched once and every
 * later read comes off the same pooled base; a null handle, a busy queue
 * (GFL_NET_SYSTEM_CheckError non-zero or GFL_NET_STATE_GetErrorMode zero) and a failed GFL_NET_SYSTEM_IsSendEnable
 * all return 0 early.  GFL_NET_GetInitParam's result is only used for its +0x64
 * byte, which selects the +0xf4 table over the +0xcc one when the fifth
 * argument is the 0xff wildcard.
 *
 * The broadcast flag is additionally cleared when the third argument is not
 * less than the handle's +0x1e0 word: `cmp r7,r0` / `cmpge r5,#1` /
 * `moveq r5,#0` is the conjunction `if (size >= packetBufSize && useRing != 0) flag = 0;`
 * written as one expression
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * On a failed send the error path reports through GFL_NET_STATE_GetError's three-word
 * record with line 0x3f4 and returns 0; a successful send returns 1.
 *
 * Addresses are Black-image addresses.
 *
 * BYTE-CORRECT, PARKED: 280 bytes, 0 concrete mismatches.  Capped at MATCH by
 * the sole unresolved site, the PC24 at +0x00D0 naming GFL_NET_QUEUE_Put
 * (0x020368C0).  That address has no branch anywhere in the image outside this
 * function's own `bl` and no manifest entry, so neither `label` nor `matched`
 * can attest it; the call is the last thing before the function's two tail
 * exits, so no cut frees it either.  Filing 0x020368C0 promotes this file
 * unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_SYSTEM_SetSendQueue.c \
 *       --func GFL_NET_SYSTEM_SetSendQueue --addr 0x02038C18 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_SetSendQueue(u32 command, const void *data, u32 size, u32 sendArg, u32 destNetId, u32 queueArg, u32 noRing)
{
    GFLNetSession *initParam;
    struct NetSysWork *work;
    struct NetErrorInfo *err;
    NetQueue *queue;
    u32 useRing;

    useRing = 1;
    if (noRing != 0)
        useRing = 0;

    initParam = GFL_NET_GetInitParam();
    if (_pNetSys == 0)
        return 0;
    if (GFL_NET_SYSTEM_CheckError() != 0 || GFL_NET_STATE_GetErrorMode() != 0)
        return 0;
    if (GFL_NET_SYSTEM_IsSendEnable() == 0)
        return 0;

    work = _pNetSys;
    if ((int)size >= (int)work->packetBufSize && useRing == 1)
        useRing = 0;

    if (initParam->init.bMPMode != 0 && destNetId == 0xff)
        queue = &work->mpParentSendQueue;
    else
        queue = &work->sendQueue;

    if (GFL_NET_QUEUE_Put(queue, command, data, size, sendArg, useRing, queueArg) != 0)
        return 1;

    GFL_NET_SYSTEM_SetError();
    err = (struct NetErrorInfo *)GFL_NET_STATE_GetError();
    if (err->gameCode == 0)
        GFL_NET_STATE_SetError(err->errorCode, err->errorType, err->dwcError, 0x3f4);
    return 0;
}

int GFL_NET_SYSTEM_GetChildRingDataSize(void)
{
    return GFL_NET_RING_BUFF_GetDataSize(&_pNetSys->sendRing);
}

int GFL_NET_SYSTEM_GetParentRingDataSize(void)
{
    return GFL_NET_RING_BUFF_GetDataSize(&_pNetSys->mpParentSendRing);
}

/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_DispatchRecv.c \
 *       --func GFL_NET_SYSTEM_DispatchRecv --addr 0x02038D68 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_DispatchRecv(int command, u32 size, u32 data, struct NetRecvCursor *cursor)
{
    u32 handle;

    GFL_NET_GetInitParam();
    handle = (u32)GFL_NET_HANDLE_GetNetHandle(GFL_NET_SYSTEM_GetCurrentAid());
    GFL_NET_COMMAND_CallCommand(cursor->senderID, cursor->commandOption, command, size, data, handle);

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        handle = (u32)GFL_NET_HANDLE_GetNetHandle(0xFF);
        if (command < 0x11)
            GFL_NET_COMMAND_CallCommand(cursor->senderID, cursor->commandOption, command, size, data, handle);
    }

    GFL_NET_SYSTEM_InitRecvState(cursor);
}

/*
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header GFL_NET_RING_BUFF_Init builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - GFL_NET_RING_BUFF_Read is written in BOTH arms of the GFL_NET_COMMAND_IsHugeCommand test,
 *       if (!GFL_NET_COMMAND_IsHugeCommand(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     GFL_NET_RING_BUFF_ReadU16's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */
void GFL_NET_SYSTEM_ProcessRecvRing(NetRingBuff *ring, s32 senderID, u8 *buf, struct NetRecvCursor *cursor, u32 maxSize)
{
    int len;
    s16 savedReadPos;
    u8 *dest;
    u32 command;
    int copyCount;

    GFL_NET_GetInitParam();
    while (GFL_NET_RING_BUFF_GetDataSize(ring) != 0) {
        command = cursor->command;
        if (command == 0) {
            command = GFL_NET_RING_BUFF_ReadU16(ring);
            if (command == 0) {
                GF_PANIC_Fail(_FileName, 0x6E3, _AssertAlways);
                continue;
            }
        }
        savedReadPos = ring->readPos;
        cursor->command = command;
        if (cursor->totalSize == 0xFFFF) {
            if (GFL_NET_RING_BUFF_GetDataSize(ring) < 3) {
                ring->readPos = savedReadPos;
                return;
            }
            {
                u16 v = GFL_NET_RING_BUFF_ReadU16(ring);
                cursor->remaining = v;
                cursor->totalSize = v;
            }
            cursor->senderID = senderID;
            cursor->commandOption = GFL_NET_RING_BUFF_ReadByte(ring);
        }
        savedReadPos = ring->readPos;
        if (GFL_NET_COMMAND_IsHugeCommand(command) && GFL_NET_COMMAND_GetHeaderSize(cursor->commandOption)) {
            if (cursor->dest == 0)
                cursor->dest = (u8 *)GFL_NET_COMMAND_GetHugeBuffer(command, cursor->senderID, cursor->totalSize);
            dest = cursor->dest + cursor->copied;
        } else {
            dest = buf;
            cursor->dest = buf;
        }
        if (!GFL_NET_COMMAND_GetHeaderSize(cursor->commandOption))
            dest = 0;
        if (!GFL_NET_COMMAND_IsHugeCommand(command))
            len = GFL_NET_RING_BUFF_Read(ring, buf, cursor->remaining, cursor->remaining);
        else
            len = GFL_NET_RING_BUFF_Read(ring, buf, cursor->remaining, maxSize - 7);
        cursor->remaining = cursor->remaining - (u16)len;
        copyCount = len;
        if (cursor->totalSize > cursor->copied) {
            copyCount = cursor->totalSize - cursor->copied;
            if (copyCount > len)
                copyCount = len;
            if (dest != 0)
                MI_CpuCopy8(buf, dest, copyCount);
        }
        cursor->copied += copyCount;
        if (cursor->remaining == 0) {
            GFL_NET_SYSTEM_DispatchRecv(command, cursor->totalSize, (u32)cursor->dest, cursor);
            continue;
        }
        if (!GFL_NET_COMMAND_IsCommandValid(command))
            return;
        if (GFL_NET_COMMAND_IsHugeCommand(command))
            return;
        if (!GFL_NET_COMMAND_GetHeaderSize(cursor->commandOption))
            return;
        cursor->remaining += (u16)len;
        ring->readPos = savedReadPos;
        return;
    }
}

void GFL_NET_SYSTEM_ProcessParentRecv(void)
{
    int i;
    struct NetSysWork *work;

    if (_pNetSys == 0)
        return;

    GFL_NET_RING_BUFF_EndChange(&_pNetSys->parentRecvRing);

    for (i = 0; i < 4; i++) {
        if ((int)GFL_NET_RING_BUFF_GetDataSize(&_pNetSys->parentRecvRing) <= 0)
            return;

        work = _pNetSys;
        GFL_NET_SYSTEM_ProcessRecvRing(&work->parentRecvRing, 0xFF, work->recvScratchBuf,
                      &work->parentRecvCursor, GFL_NET_SYSTEM_GetSendSize());
    }
}

/*
 * n slots of 0x10 bytes at g+0x4c, each prepared by GFL_NET_RING_BUFF_EndChange and then
 * offered to GFL_NET_SYSTEM_ProcessRecvRing up to four times, with the record at g+0x11c and
 * the frame returned by GFL_NET_GetChildSendSize handed to each call.
 *
 * Three spellings are load-bearing.  The global is re-read through
 * _pNetSys itself in every statement (mwcc keeps its address in `sb` and
 * reloads the value, because the calls may store through it).  There is no
 * explicit `if (n <= 0) return;`: with `n = GFL_NET_GetMaxConnectNum();` followed
 * straight by `for (i = 0; i < n; i++)` the loop's pre-test folds to
 * `cmp r7, #0` / `pople` because i is known zero, and the loop-exit
 * epilogue tail-merges with the function's own.  And the inner body is
 * `if (test > 0) call(...)` rather than `if (test <= 0) break;`, because
 * the original's branch lands on the inner increment (the continue path).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ProcessChildRecv.c \
 *       --func GFL_NET_SYSTEM_ProcessChildRecv --addr 0x020390BC --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_ProcessChildRecv(void)
{
    int i, j, maxMembers;
    u8 *sendSize;

    sendSize = (u8 *)GFL_NET_GetChildSendSize();
    if (_pNetSys == 0)
        return;

    maxMembers = GFL_NET_GetMaxConnectNum();

    for (i = 0; i < maxMembers; i++) {
        GFL_NET_RING_BUFF_EndChange(&_pNetSys->recvRing[i]);
        for (j = 0; j < 4; j++) {
            if (GFL_NET_RING_BUFF_GetDataSize(&_pNetSys->recvRing[i]) > 0)
                GFL_NET_SYSTEM_ProcessRecvRing(&_pNetSys->recvRing[i], i,
                              _pNetSys->recvScratchBuf,
                              &_pNetSys->recvCursor[i], (u32)sendSize);
        }
    }
}

int GFL_NET_SYSTEM_IsConnectMember(u32 netId)
{
    GFLNetSession *session;
    GFLNetSession *initParam;
    struct NetSysWork *work;
    u32 netType;
    u16 bitmap;

    session = GFL_NET_GetSession();
    initParam = GFL_NET_GetInitParam();
    work = _pNetSys;
    if (work == 0)
        return 0;
    netType = (u8)(initParam->init.bNetType + 0xff);
    if (netType <= 1) {
        if (work->noChildError != 0) {
            if (session->ops->getMyAid() != -1) {
                if (netId == 0)
                    return 1;
                if (netId == 1)
                    return 1;
            }
        }
        return 0;
    }
    netType = (u8)(initParam->init.bNetType + 0xfd);
    if (netType <= 1) {
        if (netId < 2 || netId == 0xff) {
            if (session->ops->isConnected() != 0)
                return 1;
        }
        return 0;
    }
    if (GFL_NET_SYSTEM_IsDeviceReady() == 0)
        return 0;
    if (session->ops->isConnected() == 0)
        return 0;
    if (netId == (u32)GFL_NET_SYSTEM_GetCurrentAid())
        return 1;
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 || initParam->init.bMPMode == 0) {
        bitmap = (u16)session->ops->getAidBitmap();
        if (((1 << netId) & bitmap) != 0)
            return 1;
    } else {
        if (((1 << netId) & _pNetSys->memberBitmap) != 0)
            return 1;
    }
    return 0;
}

/*
 * Counts the eight slots whose test function answers non-zero.  The slot
 * number goes in as a `u16` - the `lsl #16` / `lsr #16` pair in the loop is
 * that narrowing - so the callee is declared with a `u16` parameter and the
 * cast costs nothing at the call site.  The counter is in r4 and the index in
 * r5, which is the declaration order below.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_GetConnectNum.c \
 *       --func GFL_NET_SYSTEM_GetConnectNum --addr 0x020392B8 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_GetConnectNum(void)
{
    int count;
    int i;

    count = 0;
    for (i = 0; i < GFL_NET_MACHINE_MAX; i++) {
        if (GFL_NET_SYSTEM_IsConnectMember((u16)i) != 0)
            count++;
    }
    return count;
}

/*
 * Returns 1 while the state byte at +0x65 is one to four, but only while the
 * global at 0x021469D0 is live; otherwise it dispatches through the vtable at
 * +0x340 of the net state and returns that hook's value (+0x6C slot).
 *
 * The `add r0, r0, #0xff` / `and r0, r0, #0xff` pair is `(u8)(v - 1)`: mwcc
 * writes the -1 as +0xFF because the truncation to u8 makes the two
 * equivalent and 0xFF keeps the `and` mask a plain immediate.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_IsDeviceReady.c \
 *       --func GFL_NET_SYSTEM_IsDeviceReady --addr 0x020392EC --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_IsDeviceReady(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *initParam = GFL_NET_GetInitParam();

    if (_pNetSys != 0 && (u8)(initParam->init.bNetType + 0xFF) <= 3)
        return 1;

    return session->ops->isActive();
}

u16 GFL_NET_SYSTEM_GetCurrentAid(void)
{
    GFLNetSession *session;
    u8 netTypeBias;
    s32 aid;

    if (_pNetSys == 0) {
        goto none;
    }

    session = GFL_NET_GetSession();
    netTypeBias = (GFL_NET_GetInitParam())->init.bNetType + 0xff;

    if (netTypeBias <= 1) {
        aid = session->ops->getMyAid();
        if (aid == -1) {
            goto none;
        }
        return (u16)aid;
    }

    return (u16)session->ops->getMyAid();

none:
    return 0;
}

int GFL_NET_SYSTEM_GetChildBitmap(void)
{
    u16 memberBitmap;

    memberBitmap = GFL_NET_GetSession()->ops->getAidBitmap();
    return memberBitmap & 0xFFFE;
}

/*
 * Is the link busy?  The +0x1e9 flag on the link state forces a yes, and
 * otherwise the driver's own predicate at +0x88 decides.
 *
 * The two halves of the flag test share one `ne` chain and a single `popne`,
 * so they are one `&&` rather than nested `if`s.  GFL_NET_GetSession is called
 * before the flag is even read because its result is needed on the fall
 * through path, and the compiler will not sink a call past a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_IsError.c \n *       --func GFL_NET_SYSTEM_IsError --addr 0x020393D0 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_IsError(void)
{
    GFLNetSession *session;

    session = GFL_NET_GetSession();

    if (_pNetSys != 0 && _pNetSys->errorFlag != 0) {
        return 1;
    }
    return session->ops->getLastErrorCode() != 0;
}

/*
 * Asks the transport's +0x88 virtual whether the link is up, falling back to
 * the +0x1E9 flag of the object at 0x021469D0 when the virtual is missing or
 * answers zero.  Both re-tests are conditional-execution chains (`cmpne`), so
 * the source is the `!= 0 && ...` spelling in each place.  The result local
 * is declared after the context refresh and assigned at its first use: with
 * `u32 r = 0;` ahead of the refresh the value is live across GFL_NET_GetSession
 * and the allocator spends a callee-saved register on it (`push {r4, lr}`
 * instead of the original's `push {r3, lr}`).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_CheckError.c  *       --func GFL_NET_SYSTEM_CheckError --addr 0x02039414 --cc 1.1p1 --arm
 */
u32 GFL_NET_SYSTEM_CheckError(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u32 result = 0;

    if (session != 0 && session->ops != 0)
        result = session->ops->getLastErrorCode();
    if (result == 0) {
        struct NetSysWork *work = _pNetSys;

        if (work != 0 && work->errorFlag != 0)
            result = 1;
    }
    return result;
}

int GFL_NET_SYSTEM_IsSendQueueEntry(u32 command, u32 destNetId)
{
    GFLNetSession *initParam = GFL_NET_GetInitParam();

    if (initParam->init.bMPMode != 0 && destNetId == 0xff) {
        return GFL_NET_QUEUE_IsCommandQueued(&_pNetSys->mpParentSendQueue, command);
    } else {
        return GFL_NET_QUEUE_IsCommandQueued(&_pNetSys->sendQueue, command);
    }
}

/*
 * Leaf that saves no lr: tail-calls GFL_NET_QUEUE_IsEmpty on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, sendQueue).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */
int GFL_NET_SYSTEM_IsSendQueueEmpty(void)
{
    return GFL_NET_QUEUE_IsEmpty(&_pNetSys->sendQueue);
}

/*
 * A leaf setter on the link state: store the argument byte at +0x1e7.  It
 * saves no registers, so disasm.py gives it no label and it prints as a run
 * of `.word`s between two pools
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SetNoChildError.c \n *       --func GFL_NET_SYSTEM_SetNoChildError --addr 0x020394DC --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_SetNoChildError(u8 v)
{
    _pNetSys->noChildError = v;
}

void GFL_NET_SYSTEM_SetWaitMode(u32 mode)
{
    u8 netType = GFL_NET_GetInitParam()->init.bNetType;

    if ((u8)(netType + 0xff) > 1) {
        return;
    }
    _pNetSys->mpWaitMode = mode;
    if (mode == 0) {
        return;
    }
    _pNetSys->parentRecvPending = 0;
    _pNetSys->recvPending[0] = 0;
    _pNetSys->recvPending[1] = 0;
}

/*
 * Set the +0x1e9 flag on the link state.  GFL_NET_SYSTEM_ResetError is the clearing half;
 * the two are byte-for-byte the same but for the stored constant.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SetError.c \n *       --func GFL_NET_SYSTEM_SetError --addr 0x02039548 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_SetError(void)
{
    _pNetSys->errorFlag = 1;
}

/*
 * Clear the +0x1e9 flag GFL_NET_SYSTEM_SetError sets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ResetError.c \n *       --func GFL_NET_SYSTEM_ResetError --addr 0x02039560 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_ResetError(void)
{
    _pNetSys->errorFlag = 0;
}

/*
 * Set the +0x1ea flag, but only when the link state has been constructed.
 * The guard and the store share one `ne` predication rather than a branch,
 * and the stored 1 is materialised into r0, the register the pool address
 * was loaded into, because that register is dead by then.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SetNoSend.c \n *       --func GFL_NET_SYSTEM_SetNoSend --addr 0x02039578 --cc 1.1p1 --arm
 */
void GFL_NET_SYSTEM_SetNoSend(void)
{
    if (_pNetSys != 0) {
        _pNetSys->noSend = 1;
    }
}

/*
 * May the caller proceed?  With no link state, or with the +0x64 byte of the
 * session record set, the answer is an unconditional yes; in the two session
 * states 0 and 5 it is whatever the +0x1eb byte of the link state says; any
 * other state is a yes.
 *
 * The `state == 0 || state == 5` pair is one `cmp` / `cmpne` chain feeding a
 * single `eq` block, so it has to be written as one disjunction: as two
 * `if`s the shared block is duplicated.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_IsSendEnable.c \n *       --func GFL_NET_SYSTEM_IsSendEnable --addr 0x02039594 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_IsSendEnable(void)
{
    GFLNetSession *initParam;

    if (_pNetSys == 0) {
        goto yes;
    }

    initParam = GFL_NET_GetInitParam();
    if (initParam->init.bMPMode != 0) {
        goto yes;
    }
    if (initParam->init.bNetType == 0 || initParam->init.bNetType == 5) {
        return _pNetSys->sendReady;
    }
yes:
    return 1;
}

/*
 * Clamp a slot index to the sentinel: anything from 8 up becomes 0xff, and
 * everything below passes through untouched.  Twelve bytes, no prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ClampNetId.c \n *       --func GFL_NET_SYSTEM_ClampNetId --addr 0x020395E0 --cc 1.1p1 --arm
 */
int GFL_NET_SYSTEM_ClampNetId(int netId)
{
    if (netId >= GFL_NET_MACHINE_MAX) {
        netId = 0xFF;
    }
    return netId;
}
