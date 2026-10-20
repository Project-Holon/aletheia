/*
 * file:     net_command.c
 * unit:     yes
 * function: GFL_NET_COMMAND_Init, GFL_NET_COMMAND_Exit, GFL_NET_COMMAND_AddCommandTable, GFL_NET_COMMAND_DeleteCommandTable, GFL_NET_COMMAND_GetHeaderSize, GFL_NET_COMMAND_GetCommandTable, GFL_NET_COMMAND_GetRecvFunc, GFL_NET_COMMAND_GetCommandWork, GFL_NET_COMMAND_GetSizeFunc, GFL_NET_COMMAND_CallCommand, GFL_NET_COMMAND_IsCommandValid, GFL_NET_COMMAND_IsHugeCommand, GFL_NET_COMMAND_GetHugeBuffer, GFL_NET_COMMAND_NoProc, GFL_NET_COMMAND_RecvHugeData, GFL_NET_COMMAND_RecvHugeBuffer, GFL_NET_COMMAND_SetSendSlot, GFL_NET_COMMAND_SendNextSlot, GFL_NET_COMMAND_Main
 * address:  0x0203A494
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x0203A494 (__FILE__ anchor boundary).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_020A7A20   0x020A7A20  data  a1
 *   str_020A7A24   0x020A7A24  data
 *   _pNetSys     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   str_020A7A34   0x020A7A34  data
 *   g_020387A0     0x020387A0  data
 *   g_020A7A20      0x020A7A20  data
 *   GFL_HEAP_Free   0x020307B0  arm
 *   GFL_NET_SYSTEM_GetCurrentAid   0x02039338  arm
 *   GFL_NET_SYSTEM_GetChildBitmap   0x020393A8  arm
 *   GFL_NET_SYSTEM_IsError  0x020393D0  arm
 *   lbl_020A7A20    0x020A7A20  data
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *   str_020A7A54   0x020A7A54  data
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   str_020A7A50   0x020A7A50  data
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
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B08     0x020A7B08  data
 *   g_020A7B20       0x020A7B20  data
 *   g_020A7B50       0x020A7B50  data
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
 *   GFL_NET_SYSTEM_InitWork  0x02037288  arm
 *   GFL_NET_SYSTEM_SetSendQueue  0x02038C18  arm
 *   GFL_NET_SYSTEM_SetNoChildError  0x020394DC  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_HANDLE_RecvNegotiation  0x0203A020  arm
 *   GFL_NET_STATE_Idle  0x0203C00C  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */

#include "../types.h"

#include "net_types.h"

#include "gfl_heap_wrap.h"

#include "mi_memory.h"

#include "net_system.h"

#include "gf_panic.h"






#include "net_handle.h"




#include "net_state.h"






struct GFLNetHandle;

struct NetNegotiationMsg;


void GFL_NET_COMMAND_Init(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData, u32 unusedArg);

void GFL_NET_COMMAND_Exit(void);

void GFL_NET_COMMAND_AddCommandTable(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData);

void GFL_NET_COMMAND_DeleteCommandTable(u32 groupKey);

u32 GFL_NET_COMMAND_GetHeaderSize(u32 destMask);

struct NetCommandTable *GFL_NET_COMMAND_GetCommandTable(u32 command);

NetCommandRecvFunc GFL_NET_COMMAND_GetRecvFunc(u32 command);

u32 GFL_NET_COMMAND_GetCommandWork(u32 command);

NetCommandSizeFunc GFL_NET_COMMAND_GetSizeFunc(u32 command);

void GFL_NET_COMMAND_CallCommand(u32 netId, u32 destMask, int command, u32 size, u32 data, u32 handle);

int GFL_NET_COMMAND_IsCommandValid(unsigned int command);

int GFL_NET_COMMAND_IsHugeCommand(unsigned int command);

u32 GFL_NET_COMMAND_GetHugeBuffer(u32 command, u32 netId, u32 size);

void GFL_NET_COMMAND_NoProc(void);

void GFL_NET_COMMAND_RecvHugeData(int netId, u32 byteCount, void *chunkData, int unusedArg, volatile int handle);

void GFL_NET_COMMAND_RecvHugeBuffer(int netId, int unusedArg, const u8 *header, int unusedArg2, int handle);

u32 GFL_NET_COMMAND_SetSendSlot(GFLNetHandle *handle, u32 destMask, u32 command, u32 totalSize, void *dataAddr);

u32 GFL_NET_COMMAND_SendNextSlot(void);

void GFL_NET_COMMAND_Main(void);

#include "net.h"

extern struct NetSysWork *_pNetSys;

extern struct NetCommandWork *_pCommandWork;

extern struct NetCommandTable g_020A7AE8;

extern char  g_020A7AF8[];

extern struct NetCommandTable g_020A7AE8_arr;

extern char   g_020A7B08[];

extern char g_020A7B20[];

extern char g_020A7B50[];

extern char  g_020A7B78[];

/*
 * Lazy-init wrapper: the 0x22c-byte context at _pCommandWork is allocated on
 * first use with the debug allocator (heap 0, size 0x22c, flags 1, line
 * 0x96), the delegate GFL_NET_COMMAND_AddCommandTable is called, arg3 is published at +8 of
 * the state object in g_020A7AE8, and the 8-byte run at +0x220 plus the byte
 * at +0x228 are cleared.
 *
 * The clearing loop reloads _pCommandWork from memory on every iteration
 * (`ldr r1, [r0]` sits inside the back edge), which is what a global
 * POINTER read in a loop body compiles to when nothing in the loop proves it
 * cannot change -- writing `u8 *p = _pCommandWork;` first would hoist the load
 * and change three instructions.  The loop counter is initialised before the
 * `str r5, [r0, #8]` store (`mov r3, #0` at +0x60), and the byte index is
 * added to the reloaded pointer rather than to a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_Init.c \
 *       --func GFL_NET_COMMAND_Init --addr 0x0203A494 --cc 1.1p1 --arm
 */
void GFL_NET_COMMAND_Init(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData, u32 unusedArg)
{
    int memberIdx;

    if (_pCommandWork == 0) {
        _pCommandWork = GFL_HEAP_Alloc(0, 0x22c, 1, g_020A7AF8, 0x96);
    }
    GFL_NET_COMMAND_AddCommandTable(groupKey, commandList, listNum, userData);
    g_020A7AE8.userData = userData;
    for (memberIdx = 0; memberIdx < 8; memberIdx++) {
        _pCommandWork->memberState[memberIdx] = 0;
    }
    _pCommandWork->initDone = 0;
}

void GFL_NET_COMMAND_Exit(void)
{
    if (_pCommandWork == 0)
        return;
    MI_CpuFill8(_pCommandWork, 0, 0x22c);
    GFL_HEAP_Free(_pCommandWork);
    _pCommandWork = 0;
}

void GFL_NET_COMMAND_AddCommandTable(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData)
{
    struct NetCommandTable *tables = _pCommandWork->commandTables;
    int tableIdx;

    if (tables == 0) {
        return;
    }
    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        if (tables[tableIdx].groupKey == 0 || tables[tableIdx].groupKey == groupKey) {
            tables[tableIdx].groupKey = groupKey;
            _pCommandWork->commandTables[tableIdx].list = commandList;
            _pCommandWork->commandTables[tableIdx].listNum = listNum;
            _pCommandWork->commandTables[tableIdx].userData = userData;
            return;
        }
    }
}

void GFL_NET_COMMAND_DeleteCommandTable(u32 groupKey)
{
    struct NetCommandTable *tables = _pCommandWork->commandTables;
    int tableIdx;

    if (tables == 0)
        return;
    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        if (tables[tableIdx].groupKey == groupKey) {
            MI_CpuFill8(&tables[tableIdx], 0, 0x10);
            return;
        }
    }
}

/*
 * Bit test against a channel mask: 0xFF is always live, otherwise the bit of
 * the argument named by the index GFL_NET_SYSTEM_GetCurrentAid() reports decides, and a zero
 * index falls back to the 0x80 bit.  `1 << f()` is emitted as the shifted
 * register of a `tst`, and each success path is the conditional
 * `movne r0, #1` / `popne` pair, so the source is the return chain above a
 * final plain `return 0;`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetHeaderSize.c \
 *       --func GFL_NET_COMMAND_GetHeaderSize --addr 0x0203A634 --cc 1.1p1 --arm
 */
u32 GFL_NET_COMMAND_GetHeaderSize(u32 destMask)
{
    if (destMask == 0xFF)
        return 1;
    if (destMask & (1 << GFL_NET_SYSTEM_GetCurrentAid()))
        return 1;
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && (destMask & 0x80) != 0)
        return 1;
    return 0;
}

/*
 * net_command.c's command-record lookup.  The 16-bit command is split into
 * a group (the high byte, kept unshifted throughout: the original compares
 * the masked value, never a shifted one) and an index (the low byte).
 *
 * Group 0 is the static base table at 0x020A7AE8 -- a { void *list; int
 * listNum; } pair whose strings name it "_BaseTable" (the assert text at
 * 0x020A7B08 reads "_BaseTable.listNum > co...", 0x020A7AF8 is
 * "net_command.c", and the line number is 0x10D).  listNum is SIGNED: the
 * guard is `bgt`, not `bhi`.
 *
 * Any other group scans the four 0x10-byte records behind the pointer at
 * 0x021469D8, the _pCommandWork context src/matched/GFL_NET_COMMAND_Init.c
 * allocates; the second assert string at 0x020A7B20 names those records
 * "_pCommandWork->aNetHugeRecv[index].used".
 *
 * TWO POOL WORDS FOR ONE ADDRESS.  The original spends two separate pool
 * entries on 0x020A7AE8 (at +0x78 and +0x88).  It is one object reached by
 * two declarations: the `.listNum` guard reads the struct, while the
 * returned pointer is the list base spelled as an array.  Collapsing them
 * into a single `&g_020A7AE8` makes the file 140 bytes, four short.
 *
 * DECLARATION ORDER.  `int tableIdx` must be declared BEFORE the two masks, and
 * the index must be `int`, not `u32`.  With the masks first the 3-register
 * rotation r2 -> ip -> r3 -> r2 appears and nothing else moves it (found by
 * tools/permuter.py: decl-order(index<->tableIdx) ; decl-order(group<->tableIdx)).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetCommandTable.c \
 *       --func GFL_NET_COMMAND_GetCommandTable --addr 0x0203A67C --cc 1.1p1 --arm
 */
struct NetCommandTable *GFL_NET_COMMAND_GetCommandTable(u32 command)
{
    int tableIdx;
    u32 group = command & 0xff00;
    int index = (int)(command & 0xff);

    if (group == 0) {
        if (g_020A7AE8.listNum <= index)
            GF_PANIC_Fail(g_020A7AF8, 0x10D, g_020A7B08);
        return &g_020A7AE8_arr;
    }
    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        struct NetCommandTable *table = _pCommandWork->commandTables + tableIdx;
        if (group == table->groupKey) {
            if (table->listNum <= index)
                return 0;
            return table;
        }
    }
    return 0;
}

NetCommandRecvFunc GFL_NET_COMMAND_GetRecvFunc(u32 command)
{
    struct NetCommandTable *table = GFL_NET_COMMAND_GetCommandTable(command);
    if (table != 0) {
        return table->list[command & 0xff].recvFunc;
    }
    return 0;
}

/*
 * The null-tolerant third word of the object GFL_NET_COMMAND_GetCommandTable caches: the
 * conditional `ldrne` / `moveq` pair is exactly the `? :` form, not an
 * if/return, which would have needed a second epilogue.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetCommandWork.c \
 *       --func GFL_NET_COMMAND_GetCommandWork --addr 0x0203A730 --cc 1.1p1 --arm
 */
u32 GFL_NET_COMMAND_GetCommandWork(u32 command)
{
    struct NetCommandTable *table = GFL_NET_COMMAND_GetCommandTable(command);

    return table != 0 ? (uptr)table->userData : 0;
}

NetCommandSizeFunc GFL_NET_COMMAND_GetSizeFunc(u32 command)
{
    struct NetCommandTable *table = GFL_NET_COMMAND_GetCommandTable(command);
    if (table != 0) {
        return table->list[command & 0xff].sizeFunc;
    }
    return 0;
}

void GFL_NET_COMMAND_CallCommand(u32 netId, u32 destMask, int command, u32 size, u32 data, u32 handle)
{
    u32 accepted;
    NetCommandRecvFunc recvFunc;

    if (GFL_NET_COMMAND_GetHeaderSize(destMask) == 0) {
        return;
    }
    accepted = 1;
    if (GFL_NET_HANDLE_IsNegotiationDone((struct GFLNetHandle *)handle) == 0) {
        if (command >= 0x11) {
            accepted = 0;
        }
    }
    if (accepted == 0) {
        return;
    }
    recvFunc = GFL_NET_COMMAND_GetRecvFunc(command);
    if (recvFunc == 0) {
        return;
    }
    recvFunc(netId, size, data, GFL_NET_COMMAND_GetCommandWork(command), handle);
}

int GFL_NET_COMMAND_IsCommandValid(unsigned int command)
{
    return GFL_NET_COMMAND_GetRecvFunc(command) != 0;
}

int GFL_NET_COMMAND_IsHugeCommand(unsigned int command)
{
    return GFL_NET_COMMAND_GetSizeFunc(command) != 0;
}

/*
 * Indirect dispatch: the first argument names a slot whose function pointer
 * comes back from GFL_NET_COMMAND_GetSizeFunc; a null slot answers 0 with the conditional
 * `moveq`/`popeq` pair, and otherwise the pointer is called with the second
 * argument, the current value GFL_NET_COMMAND_GetCommandWork reports and the third argument.
 * GFL_NET_COMMAND_GetCommandWork's own body ignores its parameter, but the caller still loads
 * one, so the source declares it with a parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_GetHugeBuffer.c \
 *       --func GFL_NET_COMMAND_GetHugeBuffer --addr 0x0203A81C --cc 1.1p1 --arm
 */
u32 GFL_NET_COMMAND_GetHugeBuffer(u32 command, u32 netId, u32 size)
{
    NetCommandSizeFunc getBuffer = GFL_NET_COMMAND_GetSizeFunc(command);

    if (getBuffer == 0)
        return 0;
    return getBuffer(netId, GFL_NET_COMMAND_GetCommandWork(command), size);
}

void GFL_NET_COMMAND_NoProc(void)
{
}

/*
 * One slot of a network table: index 0xff aliases to slot 8, the incoming
 * tag must match GFL_NET_HANDLE_GetCurrentHandle(), and the entry is swept copy-then-count.
 * The global pointer at 0x021469D8 is re-read after every call, so the C
 * dereferences it afresh in each statement rather than keeping a local.
 *
 * The fifth parameter is volatile: every use re-reads its incoming stack
 * slot (ldr r1,[sp,#0x20] after the tag call, ldr r0,[sp,#0x20] again for
 * GFL_NET_COMMAND_CallCommand) instead of living in a callee-saved register, which is what
 * keeps the saved set at r4-r8 rather than adding sb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_RecvHugeData.c \
 *       --func GFL_NET_COMMAND_RecvHugeData --addr 0x0203A85C --cc 1.1p1
 */
void GFL_NET_COMMAND_RecvHugeData(int netId, u32 byteCount, void *chunkData, int unusedArg, volatile int handle)
{
    int slotIdx = netId;

    if (netId == 0xff) {
        slotIdx = 8;
    }
    if (handle != (uptr)GFL_NET_HANDLE_GetCurrentHandle()) {
        return;
    }
    if (_pCommandWork->aNetHugeRecv[slotIdx].used == 0) {
        return;
    }
    if (_pCommandWork->aNetHugeRecv[slotIdx].data != 0) {
        MI_CpuCopy8(chunkData,
                    (void *)(_pCommandWork->aNetHugeRecv[slotIdx].data
                             + _pCommandWork->aNetHugeRecv[slotIdx].chunksReceived
                                   * _pCommandWork->aNetHugeRecv[slotIdx].chunkSize),
                    byteCount);
    }
    _pCommandWork->aNetHugeRecv[slotIdx].chunksReceived++;
    if (_pCommandWork->aNetHugeRecv[slotIdx].chunksReceived != _pCommandWork->aNetHugeRecv[slotIdx].chunkCount) {
        return;
    }
    if (_pCommandWork->aNetHugeRecv[slotIdx].data != 0) {
        GFL_NET_COMMAND_CallCommand(netId, _pCommandWork->aNetHugeRecv[slotIdx].destMask,
                      _pCommandWork->aNetHugeRecv[slotIdx].command, _pCommandWork->aNetHugeRecv[slotIdx].size,
                      _pCommandWork->aNetHugeRecv[slotIdx].data, handle);
    }
    _pCommandWork->aNetHugeRecv[slotIdx].used = 0;
}

/*
 * net_command.c: register the huge-data header in slot netId (0xff -> 8) of
 * the 0x14-stride aNetHugeRecv table at _pCommandWork + 0xb8, asserting the slot was free
 * (line 0x1ff) and that GFL_NET_COMMAND_GetHugeBuffer accepted it (line 0x203).
 *
 * Closed from docs/notes/pkt_0203A958.c.txt (39 bytes out) by the same
 * lever as GFL_NET_HANDLE_RecvNegotiation in net_handle.c: the record parameter is
 * `const u8 *header`, which lets the `*(u32 *)header` load hoist above the in-use
 * strb and the five halfword copies interleave as the image has them.
 * The old `tmp` local for the +6 halfword is then unneeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_RecvHugeBuffer.c  *       --func GFL_NET_COMMAND_RecvHugeBuffer --addr 0x0203A958 --arm --cc 1.1p1
 */
void GFL_NET_COMMAND_RecvHugeBuffer(int netId, int unusedArg, const u8 *header, int unusedArg2, int handle)
{
    int slotIdx;
    u16 command, chunkSize, destMask, chunkCount;

    slotIdx = netId;
    if (netId == 0xff)
        slotIdx = 8;
    if (handle != (sptr)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (GFL_NET_COMMAND_GetHugeBuffer(*((u16 *)(header + 6)), netId, *((u32 *)header)) == 0)
        return;
    if (_pCommandWork->aNetHugeRecv[slotIdx].used != 0)
        GF_PANIC_Fail(g_020A7AF8, 0x1ff, g_020A7B20);
    _pCommandWork->aNetHugeRecv[slotIdx].used = 1;
    {
        u32 size = *((u32 *)header);
        _pCommandWork->aNetHugeRecv[slotIdx].size = size;
        _pCommandWork->aNetHugeRecv[slotIdx].data = GFL_NET_COMMAND_GetHugeBuffer(*((u16 *)(header + 6)), netId, size);
    }
    if (_pCommandWork->aNetHugeRecv[slotIdx].data == 0)
        GF_PANIC_Fail(g_020A7AF8, 0x203, g_020A7B50);
    command = *((u16 *)(header + 6));
    chunkSize = *((u16 *)(header + 8));
    destMask = *((u16 *)(header + 0xa));
    chunkCount = *((u16 *)(header + 4));
    _pCommandWork->aNetHugeRecv[slotIdx].command = command;
    _pCommandWork->aNetHugeRecv[slotIdx].chunkSize = chunkSize;
    _pCommandWork->aNetHugeRecv[slotIdx].destMask = destMask;
    _pCommandWork->aNetHugeRecv[slotIdx].chunkCount = chunkCount;
    _pCommandWork->aNetHugeRecv[slotIdx].chunksReceived = 0;
}

/*
 * The net_command.c command-queue trio, 0x0203AA94..0x0203AD6C, folded into
 * one translation unit: the enqueue (GFL_NET_COMMAND_SetSendSlot), the header pump
 * (GFL_NET_COMMAND_SendNextSlot) and the chunk pump (GFL_NET_COMMAND_Main).  All three walk the
 * same five 0x18-byte send slot table at _pCommandWork and share the 4-bit
 * state nibble pair at slot +0x17 (headerPending, dataActive).  Filed as a unit because the
 * three are individually EXACT and reproduce the range with its pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AA94.c \
 *       --addr 0x0203AA94 --arm
 */
u32 GFL_NET_COMMAND_SetSendSlot(GFLNetHandle *handle, u32 destMask, u32 command, u32 totalSize, void *dataAddr)
{
    GFLNetSession *session;
    struct NetCommandWork *work;
    u8 *firstState;
    SendSlotState *state;
    struct NetSendSlot *slot;
    int slotIdx;
    int chunkLimit;

    session = GFL_NET_GetInitParam();
    work = _pCommandWork;
    firstState = &work->sendSlots[0].state.raw;
    for (slotIdx = 0; slotIdx < 5; slotIdx++) {
        state = (SendSlotState *)&firstState[slotIdx * 0x18];
        if (state->bits.headerPending)
            continue;
        if (state->bits.dataActive == 0)
            break;
    }
    if (slotIdx == 5)
        return 0;

    slot = &work->sendSlots[slotIdx];
    slot->totalSize = totalSize;
    chunkLimit = session->init.childSendSize - 0xc;
    if (chunkLimit <= 0)
        GF_PANIC_Fail(g_020A7AF8, 0x22b, g_020A7B78);
    slot->chunkSize = session->init.childSendSize - 0xc;
    slot->chunkCount = totalSize / slot->chunkSize;
    slot->lastChunkSize = totalSize % slot->chunkSize;
    if (slot->lastChunkSize != 0)
        slot->chunkCount = slot->chunkCount + 1;
    slot->chunksSent = 0;
    slot->command = command;
    slot->destMask = destMask;
    slot->dataAddr = dataAddr;
    slot->handleId = GFL_NET_HANDLE_GetNetHandleID(handle);
    slot->state.bits.headerPending = 1;
    return slot->state.bits.headerPending;
}

u32 GFL_NET_COMMAND_SendNextSlot(void)
{
    u16 header[6];
    struct NetSendSlot *slot;
    struct NetSendSlot *slots;
    int slotIdx;

    slots = _pCommandWork->sendSlots;
    for (slotIdx = 0; slotIdx < 5; slotIdx++) {
        slot = slots + slotIdx;
        if (slot->state.bits.headerPending) {
            header[2] = slot->chunkCount;
            *(u32 *)&header[0] = slot->totalSize;
            header[3] = slot->command;
            header[4] = slot->chunkSize;
            header[5] = slot->destMask;
            slot->state.bits.dataActive = GFL_NET_SYSTEM_SetSendQueue(0xd, (const u8 *)header, 0xc, 1,
                                          slot->handleId, slot->destMask, 0);
            slot->state.bits.headerPending = 1 - slot->state.bits.dataActive;
            return slot->state.bits.dataActive;
        }
    }
    return 0;
}

void GFL_NET_COMMAND_Main(void)
{
    int slotIdx;
    u32 chunkBytes;
    u32 chunkIdx;
    uptr chunkAddr;
    struct NetCommandWork *work;
    struct NetSendSlot *slot;

    work = _pCommandWork;
    for (slotIdx = 0; slotIdx < 5; slotIdx++) {
        if (work->sendSlots[slotIdx].state.bits.dataActive) {
            slot = &work->sendSlots[slotIdx];
            chunkIdx = slot->chunksSent;
            chunkBytes = slot->chunkSize;
            chunkAddr = (uptr)slot->dataAddr + chunkBytes * chunkIdx;
            if (chunkIdx + 1 == slot->chunkCount)
                chunkBytes = slot->lastChunkSize;
            if (GFL_NET_SYSTEM_SetSendQueue(0xc, (const u8 *)chunkAddr, chunkBytes, 1,
                              slot->handleId, slot->destMask, 1) != 0)
                slot->chunksSent = slot->chunksSent + 1;
            if (slot->chunksSent == slot->chunkCount)
                slot->state.bits.dataActive = 0;
            return;
        }
    }
    GFL_NET_COMMAND_SendNextSlot();
}
