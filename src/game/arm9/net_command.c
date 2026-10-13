/*
 * file:     net_command.c
 * unit:     yes
 * function: func_0203A494, func_0203A53C, func_0203A574, func_0203A5E4, func_0203A634, func_0203A67C, func_0203A70C, func_0203A730, func_0203A748, func_0203A770, func_0203A7EC, func_0203A804, func_0203A81C, func_0203A858, func_0203A85C, func_0203A958, func_0203AA94, func_0203ABC0, func_0203ACAC
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
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039548  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_020A7A20   0x020A7A20  data  a1
 *   str_020A7A24   0x020A7A24  data
 *   g_021469D0     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   str_020A7A34   0x020A7A34  data
 *   g_020387A0     0x020387A0  data
 *   g_020A7A20      0x020A7A20  data
 *   func_020307B0   0x020307B0  arm
 *   func_02039338   0x02039338  arm
 *   func_020393A8   0x020393A8  arm
 *   func_020393D0  0x020393D0  arm
 *   lbl_020A7A20    0x020A7A20  data
 *   func_020399A8  0x020399A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *   str_020A7A54   0x020A7A54  data
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   str_020A7A50   0x020A7A50  data
 *   func_02039594  0x02039594  arm
 *   func_0203996C   0x0203996C  arm
 *   func_02082D44  0x02082D44  arm
 *   g_021469DC     0x021469DC  data
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   file_020A7A68  0x020A7A68  data
 *   g_021469D4     0x021469D4  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   msg_020A7A88   0x020A7A88  data
 *   func_02087C6C  0x02087C6C  arm
 *   msg_020A7A94   0x020A7A94  data
 *   func_020395E0  0x020395E0  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   file_020A7AB0  0x020A7AB0  data
 *   file_020A7ACC  0x020A7ACC  data
 *   g_021469D8     0x021469D8  data
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B08     0x020A7B08  data
 *   g_020A7B20       0x020A7B20  data
 *   g_020A7B50       0x020A7B50  data
 *   g_020A7B78     0x020A7B78  data
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7BB4     0x020A7BB4  data
 *   func_020889C0     0x020889C0  arm
 *   func_0203F034     0x0203F034  arm
 *   func_0203F0A8     0x0203F0A8  arm
 *   g_02FFFC3C        0x02FFFC3C  data
 *   func_02034F84  0x02034F84  arm
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   func_02039578  0x02039578  arm
 *   func_02039560  0x02039560  arm
 *   g_020A7BEC      0x020A7BEC  data
 *   file_020A7BA8   0x020A7BA8  data
 *   file_020A7C70   0x020A7C70  data
 *   g_020A7C7C     0x020A7C7C  data
 *   func_0203640C 0x0203640C arm
 *   func_02036428 0x02036428 arm
 *   func_020364D4 0x020364D4 arm
 *   func_02036500 0x02036500 arm
 *   func_02036540 0x02036540 arm
 *   func_020365E8 0x020365E8 arm
 *   func_0203666C 0x0203666C arm
 *   func_020366A8 0x020366A8 arm
 *   func_020368C0 0x020368C0 arm
 *   func_02036A50 0x02036A50 arm
 *   func_02036AF4 0x02036AF4 arm
 *   func_02036B4C 0x02036B4C arm
 *   func_02036B88 0x02036B88 arm
 *   func_02036B98 0x02036B98 arm
 *   func_020370C8 0x020370C8 arm
 *   func_020370F4 0x020370F4 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203D378 0x0203D378 arm
 *   func_0203D394 0x0203D394 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D4D0 0x0203D4D0 arm
 *   func_0203D650 0x0203D650 arm
 *   func_0203D680 0x0203D680 arm
 *   func_0203D6BC 0x0203D6BC arm
 *   func_0203D700 0x0203D700 arm
 *   func_0203D788 0x0203D788 arm
 *   func_0203D798 0x0203D798 arm
 *   func_0203DA4C 0x0203DA4C arm
 *   func_0203DAC4 0x0203DAC4 arm
 */

typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

#include "net_types.h"
typedef signed int     s32;

/* net_ring_buff.c ring buffer (shared name set, see touchpanel.c) */
typedef struct {
    u8   *buf;
    int   size;
    u32   state;                 /* nothing in this file reads it */
    short readPos;               /* 0x0C */
    volatile short writePos;     /* 0x0E */
} NetRingBuff;

/* net_queue.c: one queued send (0x14 bytes) */
typedef struct NetQueueNode {
    const u8 *data;              /* 0 when the data went to the ring */
    struct NetQueueNode *prev;
    struct NetQueueNode *next;
    u16 size;                    /* 0x0C: bytes still to send */
    u16 command;                 /* 0x0E: 0 = free node */
    u8  sendID;                  /* 0x10 */
    u8  headerSent;              /* 0x11 */
} NetQueueNode;

typedef struct {
    NetQueueNode *head;
    NetQueueNode *tail;
} NetQueueList;

/* net_queue.c send queue, 0x28 bytes */
typedef struct {
    NetQueueList  fast;          /* 0x00 */
    NetQueueList  slow;          /* 0x08 */
    NetQueueNode *current;       /* 0x10: node cut by a full send buffer */
    NetRingBuff  *ring;          /* 0x14 */
    NetQueueNode *nodes;         /* 0x18 */
    s32           nodeMax;       /* 0x1C */
    u32           pad20[2];      /* nothing reads it */
} NetQueue;

/* The object g_021469D0 points at (0x1f0 bytes, allocated by func_02037288). */
struct NetSysWork {
    u8  *f00;           /* 0x00 */
    u8  *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8  *f18;
    NetRingBuff f1C;
    NetRingBuff f2C;
    NetRingBuff f3C;
    NetRingBuff f4C[8];
    NetQueue fCC;
    NetQueue fF4;
    u8  f11C[8][16];
    u8  f19C[16];
    u32 f1AC;
    int f1B0;
    int f1B4[8];
    u8  f1D4;
    u8  f1D5;
    u8  f1D6;
    u8  f1D7[8];
    u8  pad1DF;
    u32 f1E0;
    u16 f1E4;
    u8  pad1E6;
    u8  f1E7;
    u8  f1E8;
    u8  f1E9;
    u8  f1EA;
    u8  f1EB;
    u8  f1EC;
    u8  f1ED;
    u8  pad1EE[2];
};

/* one command: receive handler and size handler (both may be null) */
typedef void (*NetCommandRecvFunc)(u32 netId, u32 size, u32 data, u32 userData, u32 handle);
typedef u32 (*NetCommandSizeFunc)(u32 netId, u32 userData, u32 size);

typedef struct {
    NetCommandRecvFunc recvFunc;
    NetCommandSizeFunc sizeFunc;
} NetCommandEntry;

struct NetCommandTable {
    NetCommandEntry *list;
    int   listNum;
    u32   userData;
    u32   groupKey;
};

/* byte 0x17 of a send slot: the header goes first, then the data chunks */
typedef union {
    u8 raw;
    struct {
        u8 dataActive : 4;      /* header sent, chunks are going out */
        u8 headerPending : 4;   /* header still to send */
    } bits;
} SendSlotState;

struct NetSendSlot {
    u32 handleId;
    u32 totalSize;
    u32 dataAddr;
    u16 command;
    u16 chunkSize;
    u16 lastChunkSize;
    u16 chunksSent;
    u16 chunkCount;
    u8  destMask;
    SendSlotState state;
};

struct NetHugeRecv {
    u32 size;
    u32 data;
    u16 command;
    u16 chunkSize;
    u16 chunksReceived;
    u16 chunkCount;
    u16 destMask;
    u8  used;
};

struct NetCommandWork {
    struct NetCommandTable  commandTables[4];
    struct NetSendSlot sendSlots[5];
    struct NetHugeRecv  aNetHugeRecv[9];
    u8 pad16c[0xb4];
    u8 memberState[8];
    u8 initDone;
    u8 pad229[3];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *func_02082BCC(void *dst, int val, u32 size);

extern void func_02039548(void);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u32 func_020307B0(void *p);

extern u16 func_02039338(void);

extern int   func_020393A8(void);

extern int  func_020393D0(void);

extern GFLNetHandle *func_020399A8(void);

extern int    func_02039594(void);

extern GFLNetHandle *func_0203996C(s32 idx);

extern int func_020395E0(int slot);

extern void func_0203C00C(void);

extern void func_020394DC(u8 v);

extern void func_02039578(void);

extern void func_02039560(void);

int func_02037288(u32 a0, u32 heap, u32 c);

int func_02038C18(u32 command, const void *data, u32 size, u32 isQueued, u32 handleId, u32 destMask, u32 isChunk);

u16 func_02039338(void);

int func_020393A8(void);

int func_020393D0(void);

void func_020394DC(u8 v);

void func_02039548(void);

void func_02039560(void);

void func_02039578(void);

int func_02039594(void);

int func_020395E0(int slot);

int func_020395EC(GFLNetHandle *a);

GFLNetHandle *func_0203996C(s32 idx);

GFLNetHandle *func_020399A8(void);

u32 func_020399B8(u8 *p);

void func_0203A020(u32 idx, u32 a1, const u8 *a2, u32 a3, u8 *base);

void func_0203A494(u32 groupKey, u32 commandList, u32 listNum, u32 userData, u32 unusedArg);

void func_0203A53C(void);

void func_0203A574(u32 groupKey, u32 commandList, u32 listNum, u32 userData);

void func_0203A5E4(u32 groupKey);

u32 func_0203A634(u32 destMask);

struct NetCommandTable *func_0203A67C(u32 command);

NetCommandRecvFunc func_0203A70C(u32 command);

u32 func_0203A730(u32 command);

NetCommandSizeFunc func_0203A748(u32 command);

void func_0203A770(u32 netId, u32 destMask, int command, u32 size, u32 data, u32 handle);

int func_0203A7EC(unsigned int command);

int func_0203A804(unsigned int command);

u32 func_0203A81C(u32 command, u32 netId, u32 size);

void func_0203A858(void);

void func_0203A85C(int netId, u32 byteCount, void *chunkData, int unusedArg, volatile int handle);

void func_0203A958(int netId, int unusedArg, const u8 *header, int unusedArg2, int handle);

u32 func_0203AA94(u32 handle, u32 destMask, u32 command, u32 totalSize, u32 dataAddr);

u32 func_0203ABC0(void);

void func_0203ACAC(void);

void func_0203C00C(void);

GFLNetSession *func_0203D798(void);

extern struct NetSysWork *g_021469D0;

extern struct NetCommandWork *g_021469D8;

extern struct NetCommandTable g_020A7AE8;

extern char  g_020A7AF8[];

extern struct NetCommandTable g_020A7AE8_arr;

extern char   g_020A7B08[];

extern char g_020A7B20[];

extern char g_020A7B50[];

extern char  g_020A7B78[];


/*
 * Lazy-init wrapper: the 0x22c-byte context at g_021469D8 is allocated on
 * first use with the debug allocator (heap 0, size 0x22c, flags 1, line
 * 0x96), the delegate func_0203A574 is called, arg3 is published at +8 of
 * the state object in g_020A7AE8, and the 8-byte run at +0x220 plus the byte
 * at +0x228 are cleared.
 *
 * The clearing loop reloads g_021469D8 from memory on every iteration
 * (`ldr r1, [r0]` sits inside the back edge), which is what a global
 * POINTER read in a loop body compiles to when nothing in the loop proves it
 * cannot change -- writing `u8 *p = g_021469D8;` first would hoist the load
 * and change three instructions.  The loop counter is initialised before the
 * `str r5, [r0, #8]` store (`mov r3, #0` at +0x60), and the byte index is
 * added to the reloaded pointer rather than to a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A494.c \
 *       --func func_0203A494 --addr 0x0203A494 --cc 1.1p1 --arm
 */
void func_0203A494(u32 groupKey, u32 commandList, u32 listNum, u32 userData, u32 unusedArg)
{
    int memberIdx;

    if (g_021469D8 == 0) {
        g_021469D8 = func_02030734(0, 0x22c, 1, g_020A7AF8, 0x96);
    }
    func_0203A574(groupKey, commandList, listNum, userData);
    g_020A7AE8.userData = userData;
    for (memberIdx = 0; memberIdx < 8; memberIdx++) {
        g_021469D8->memberState[memberIdx] = 0;
    }
    g_021469D8->initDone = 0;
}





























void func_0203A53C(void)
{
    if (g_021469D8 == 0)
        return;
    func_02082BCC(g_021469D8, 0, 0x22c);
    func_020307B0(g_021469D8);
    g_021469D8 = 0;
}





























void func_0203A574(u32 groupKey, u32 commandList, u32 listNum, u32 userData)
{
    struct NetCommandTable *tables = g_021469D8->commandTables;
    int tableIdx;

    if (tables == 0) {
        return;
    }
    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        if (tables[tableIdx].groupKey == 0 || tables[tableIdx].groupKey == groupKey) {
            tables[tableIdx].groupKey = groupKey;
            g_021469D8->commandTables[tableIdx].list = (NetCommandEntry *)commandList;
            g_021469D8->commandTables[tableIdx].listNum = listNum;
            g_021469D8->commandTables[tableIdx].userData = userData;
            return;
        }
    }
}




























void func_0203A5E4(u32 groupKey)
{
    struct NetCommandTable *tables = g_021469D8->commandTables;
    int tableIdx;

    if (tables == 0)
        return;
    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        if (tables[tableIdx].groupKey == groupKey) {
            func_02082BCC(&tables[tableIdx], 0, 0x10);
            return;
        }
    }
}






























/*
 * Bit test against a channel mask: 0xFF is always live, otherwise the bit of
 * the argument named by the index func_02039338() reports decides, and a zero
 * index falls back to the 0x80 bit.  `1 << f()` is emitted as the shifted
 * register of a `tst`, and each success path is the conditional
 * `movne r0, #1` / `popne` pair, so the source is the return chain above a
 * final plain `return 0;`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A634.c \
 *       --func func_0203A634 --addr 0x0203A634 --cc 1.1p1 --arm
 */
u32 func_0203A634(u32 destMask)
{
    if (destMask == 0xFF)
        return 1;
    if (destMask & (1 << func_02039338()))
        return 1;
    if (func_02039338() == 0 && (destMask & 0x80) != 0)
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
 * 0x021469D8, the _pCommandWork context src/matched/func_0203A494.c
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
 *   python tools/match.py one --src src/matched/func_0203A67C.c \
 *       --func func_0203A67C --addr 0x0203A67C --cc 1.1p1 --arm
 */
struct NetCommandTable *func_0203A67C(u32 command)
{
    int tableIdx;
    u32 group = command & 0xff00;
    int index = (int)(command & 0xff);

    if (group == 0) {
        if (g_020A7AE8.listNum <= index)
            func_02034714(g_020A7AF8, 0x10D, g_020A7B08);
        return &g_020A7AE8_arr;
    }
    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        struct NetCommandTable *table = g_021469D8->commandTables + tableIdx;
        if (group == table->groupKey) {
            if (table->listNum <= index)
                return 0;
            return table;
        }
    }
    return 0;
}






























NetCommandRecvFunc func_0203A70C(u32 command)
{
    struct NetCommandTable *table = func_0203A67C(command);
    if (table != 0) {
        return table->list[command & 0xff].recvFunc;
    }
    return 0;
}






























/*
 * The null-tolerant third word of the object func_0203A67C caches: the
 * conditional `ldrne` / `moveq` pair is exactly the `? :` form, not an
 * if/return, which would have needed a second epilogue.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A730.c \
 *       --func func_0203A730 --addr 0x0203A730 --cc 1.1p1 --arm
 */
u32 func_0203A730(u32 command)
{
    struct NetCommandTable *table = func_0203A67C(command);

    return table != 0 ? table->userData : 0;
}






























NetCommandSizeFunc func_0203A748(u32 command)
{
    struct NetCommandTable *table = func_0203A67C(command);
    if (table != 0) {
        return table->list[command & 0xff].sizeFunc;
    }
    return 0;
}






























void func_0203A770(u32 netId, u32 destMask, int command, u32 size, u32 data, u32 handle)
{
    u32 accepted;
    NetCommandRecvFunc recvFunc;

    if (func_0203A634(destMask) == 0) {
        return;
    }
    accepted = 1;
    if (func_020399B8((u8 *)handle) == 0) {
        if (command >= 0x11) {
            accepted = 0;
        }
    }
    if (accepted == 0) {
        return;
    }
    recvFunc = func_0203A70C(command);
    if (recvFunc == 0) {
        return;
    }
    recvFunc(netId, size, data, func_0203A730(command), handle);
}






























int func_0203A7EC(unsigned int command)
{
    return func_0203A70C(command) != 0;
}






























int func_0203A804(unsigned int command)
{
    return func_0203A748(command) != 0;
}






























/*
 * Indirect dispatch: the first argument names a slot whose function pointer
 * comes back from func_0203A748; a null slot answers 0 with the conditional
 * `moveq`/`popeq` pair, and otherwise the pointer is called with the second
 * argument, the current value func_0203A730 reports and the third argument.
 * func_0203A730's own body ignores its parameter, but the caller still loads
 * one, so the source declares it with a parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A81C.c \
 *       --func func_0203A81C --addr 0x0203A81C --cc 1.1p1 --arm
 */
u32 func_0203A81C(u32 command, u32 netId, u32 size)
{
    NetCommandSizeFunc getBuffer = func_0203A748(command);

    if (getBuffer == 0)
        return 0;
    return getBuffer(netId, func_0203A730(command), size);
}




























void func_0203A858(void)
{
}































/*
 * One slot of a network table: index 0xff aliases to slot 8, the incoming
 * tag must match func_020399A8(), and the entry is swept copy-then-count.
 * The global pointer at 0x021469D8 is re-read after every call, so the C
 * dereferences it afresh in each statement rather than keeping a local.
 *
 * The fifth parameter is volatile: every use re-reads its incoming stack
 * slot (ldr r1,[sp,#0x20] after the tag call, ldr r0,[sp,#0x20] again for
 * func_0203A770) instead of living in a callee-saved register, which is what
 * keeps the saved set at r4-r8 rather than adding sb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A85C.c \
 *       --func func_0203A85C --addr 0x0203A85C --cc 1.1p1
 */
void func_0203A85C(int netId, u32 byteCount, void *chunkData, int unusedArg, volatile int handle)
{
    int slotIdx = netId;

    if (netId == 0xff) {
        slotIdx = 8;
    }
    if (handle != (u32)func_020399A8()) {
        return;
    }
    if (g_021469D8->aNetHugeRecv[slotIdx].used == 0) {
        return;
    }
    if (g_021469D8->aNetHugeRecv[slotIdx].data != 0) {
        MI_CpuCopy8(chunkData,
                    (void *)(g_021469D8->aNetHugeRecv[slotIdx].data
                             + g_021469D8->aNetHugeRecv[slotIdx].chunksReceived
                                   * g_021469D8->aNetHugeRecv[slotIdx].chunkSize),
                    byteCount);
    }
    g_021469D8->aNetHugeRecv[slotIdx].chunksReceived++;
    if (g_021469D8->aNetHugeRecv[slotIdx].chunksReceived != g_021469D8->aNetHugeRecv[slotIdx].chunkCount) {
        return;
    }
    if (g_021469D8->aNetHugeRecv[slotIdx].data != 0) {
        func_0203A770(netId, g_021469D8->aNetHugeRecv[slotIdx].destMask,
                      g_021469D8->aNetHugeRecv[slotIdx].command, g_021469D8->aNetHugeRecv[slotIdx].size,
                      g_021469D8->aNetHugeRecv[slotIdx].data, handle);
    }
    g_021469D8->aNetHugeRecv[slotIdx].used = 0;
}






























/*
 * net_command.c: register the huge-data header in slot netId (0xff -> 8) of
 * the 0x14-stride aNetHugeRecv table at g_021469D8 + 0xb8, asserting the slot was free
 * (line 0x1ff) and that func_0203A81C accepted it (line 0x203).
 *
 * Closed from docs/notes/pkt_0203A958.c.txt (39 bytes out) by the same
 * lever as func_0203A020 in net_handle.c: the record parameter is
 * `const u8 *header`, which lets the `*(u32 *)header` load hoist above the in-use
 * strb and the five halfword copies interleave as the image has them.
 * The old `tmp` local for the +6 halfword is then unneeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A958.c  *       --func func_0203A958 --addr 0x0203A958 --arm --cc 1.1p1
 */
void func_0203A958(int netId, int unusedArg, const u8 *header, int unusedArg2, int handle)
{
    int slotIdx;
    u16 command, chunkSize, destMask, chunkCount;

    slotIdx = netId;
    if (netId == 0xff)
        slotIdx = 8;
    if (handle != (int)func_020399A8())
        return;
    if (func_0203A81C(*((u16 *)(header + 6)), netId, *((u32 *)header)) == 0)
        return;
    if (g_021469D8->aNetHugeRecv[slotIdx].used != 0)
        func_02034714(g_020A7AF8, 0x1ff, g_020A7B20);
    g_021469D8->aNetHugeRecv[slotIdx].used = 1;
    {
        u32 size = *((u32 *)header);
        g_021469D8->aNetHugeRecv[slotIdx].size = size;
        g_021469D8->aNetHugeRecv[slotIdx].data = func_0203A81C(*((u16 *)(header + 6)), netId, size);
    }
    if (g_021469D8->aNetHugeRecv[slotIdx].data == 0)
        func_02034714(g_020A7AF8, 0x203, g_020A7B50);
    command = *((u16 *)(header + 6));
    chunkSize = *((u16 *)(header + 8));
    destMask = *((u16 *)(header + 0xa));
    chunkCount = *((u16 *)(header + 4));
    g_021469D8->aNetHugeRecv[slotIdx].command = command;
    g_021469D8->aNetHugeRecv[slotIdx].chunkSize = chunkSize;
    g_021469D8->aNetHugeRecv[slotIdx].destMask = destMask;
    g_021469D8->aNetHugeRecv[slotIdx].chunkCount = chunkCount;
    g_021469D8->aNetHugeRecv[slotIdx].chunksReceived = 0;
}































/*
 * The net_command.c command-queue trio, 0x0203AA94..0x0203AD6C, folded into
 * one translation unit: the enqueue (func_0203AA94), the header pump
 * (func_0203ABC0) and the chunk pump (func_0203ACAC).  All three walk the
 * same five 0x18-byte send slot table at g_021469D8 and share the 4-bit
 * state nibble pair at slot +0x17 (headerPending, dataActive).  Filed as a unit because the
 * three are individually EXACT and reproduce the range with its pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AA94.c \
 *       --addr 0x0203AA94 --arm
 */
u32 func_0203AA94(u32 handle, u32 destMask, u32 command, u32 totalSize, u32 dataAddr)
{
    GFLNetSession *session;
    struct NetCommandWork *work;
    u8 *firstState;
    SendSlotState *state;
    struct NetSendSlot *slot;
    int slotIdx;
    int chunkLimit;

    session = func_0203D798();
    work = g_021469D8;
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
        func_02034714(g_020A7AF8, 0x22b, g_020A7B78);
    slot->chunkSize = session->init.childSendSize - 0xc;
    slot->chunkCount = totalSize / slot->chunkSize;
    slot->lastChunkSize = totalSize % slot->chunkSize;
    if (slot->lastChunkSize != 0)
        slot->chunkCount = slot->chunkCount + 1;
    slot->chunksSent = 0;
    slot->command = command;
    slot->destMask = destMask;
    slot->dataAddr = dataAddr;
    slot->handleId = func_020395EC((void *)handle);
    slot->state.bits.headerPending = 1;
    return slot->state.bits.headerPending;
}































u32 func_0203ABC0(void)
{
    u16 header[6];
    struct NetSendSlot *slot;
    struct NetSendSlot *slots;
    int slotIdx;

    slots = g_021469D8->sendSlots;
    for (slotIdx = 0; slotIdx < 5; slotIdx++) {
        slot = slots + slotIdx;
        if (slot->state.bits.headerPending) {
            header[2] = slot->chunkCount;
            *(u32 *)&header[0] = slot->totalSize;
            header[3] = slot->command;
            header[4] = slot->chunkSize;
            header[5] = slot->destMask;
            slot->state.bits.dataActive = func_02038C18(0xd, (const u8 *)header, 0xc, 1,
                                          slot->handleId, slot->destMask, 0);
            slot->state.bits.headerPending = 1 - slot->state.bits.dataActive;
            return slot->state.bits.dataActive;
        }
    }
    return 0;
}































void func_0203ACAC(void)
{
    int slotIdx;
    u32 chunkBytes;
    u32 chunkIdx;
    u32 chunkAddr;
    struct NetCommandWork *work;
    struct NetSendSlot *slot;

    work = g_021469D8;
    for (slotIdx = 0; slotIdx < 5; slotIdx++) {
        if (work->sendSlots[slotIdx].state.bits.dataActive) {
            slot = &work->sendSlots[slotIdx];
            chunkIdx = slot->chunksSent;
            chunkBytes = slot->chunkSize;
            chunkAddr = slot->dataAddr + chunkBytes * chunkIdx;
            if (chunkIdx + 1 == slot->chunkCount)
                chunkBytes = slot->lastChunkSize;
            if (func_02038C18(0xc, (const u8 *)chunkAddr, chunkBytes, 1,
                              slot->handleId, slot->destMask, 1) != 0)
                slot->chunksSent = slot->chunksSent + 1;
            if (slot->chunksSent == slot->chunkCount)
                slot->state.bits.dataActive = 0;
            return;
        }
    }
    func_0203ABC0();
}





























