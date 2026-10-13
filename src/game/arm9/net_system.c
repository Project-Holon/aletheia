/*
 * file:     net_system.c
 * unit:     yes
 * function: func_02037224, func_02037234, func_02037258, func_02037288, func_02037478, func_02037680, func_02037700, func_0203778C, func_020377AC, func_020377B8, func_0203781C, func_02037858, func_02037894, func_02037928, func_020379C8, func_02037A44, func_02037A6C, func_02037B08, func_02037BA4, func_02037BE8, func_02037C10, func_02037D78, func_02037D98, func_02037E60, func_02037F48, func_0203802C, func_020380E4, func_020381D8, func_02038298, func_02038340, func_02038380, func_02038524, func_02038570, func_020385C4, func_020387A0, func_02038924, func_02038A48, func_02038A90, func_02038AE0, func_02038C18, func_02038D30, func_02038D4C, func_02038D68, func_02038DF0, func_02039050, func_020390BC, func_02039160, func_020392B8, func_020392EC, func_02039338, func_020393A8, func_020393D0, func_02039414, func_02039468, func_020394C0, func_020394DC, func_020394F0, func_02039548, func_02039560, func_02039578, func_02039594, func_020395E0
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
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039548  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   _NetPhase   0x020A7A20  data  a1
 *   _FileName   0x020A7A24  data
 *   _pNetSys     0x021469D0  data
 *   _AssertNetIdRange   0x020A7A34  data
 *   func_020307B0   0x020307B0  arm
 *   func_02039338   0x02039338  arm
 *   func_020393A8   0x020393A8  arm
 *   func_020393D0  0x020393D0  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   _AssertAlways     0x020A7A50  data
 *   _AssertNotMpMode   0x020A7A54  data
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
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7B08     0x020A7B08  data
 *   sNet3730       0x020A7AF8  data
 *   sNet3733       0x020A7B20  data
 *   sNet3734       0x020A7B50  data
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

/* One packet on the wire: 7-byte header, then the payload. */
struct NetPacketHeader {
    u8 checksumLow;      /* low byte of the checksum over everything from size on */
    u8 checksumHigh;
    u8 size;             /* payload size, low 8 bits */
    u8 memberBitmap;     /* members the sender sees as connected */
    u8 flags;            /* 1 = first packet, 2 = continued, 8 = size above 0xFF, 0xFF = empty */
    u8 seq;
    u8 pad06;
    u8 body[1];
};

/* net_ring_buff.c ring buffer (shared name set, see touchpanel.c) */
typedef struct {
    u8   *buf;
    int   size;
    u32   state;                 /* nothing in this file reads it */
    short readPos;               /* 0x0C */
    short writePos;              /* 0x0E */
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
    u32           pad20;         /* nothing reads it */
    u32           sendContinued; /* 0x24: last packet left the queue unfinished */
} NetQueue;

typedef signed short   s16;

/* Reassembly state of the packet stream of one sender (16 bytes). */
struct NetRecvCursor {
    s32 copied;          /* bytes of the current command already copied to dest */
    u8 *dest;            /* where the command data goes (0 = not allocated yet) */
    u16 remaining;       /* bytes of the command still in the ring */
    u16 totalSize;       /* size of the command, 0xFFFF = size not read yet */
    u16 command;         /* command id, 0 = none started */
    u8  senderID;        /* member index, 0xFF = the parent */
    u8  commandOption;   /* byte read after the size, passed to the command table */
};

/* The object _pNetSys points at (0x1f0 bytes, allocated by func_02037288). */
struct NetSysWork {
    u8  *sendPacketBuf;           /* 0x00: packet being built for a send */
    u8  *sendRingData;            /* 0x04: storage of sendRing, 15 packets */
    u8  *mpParentPacketBuf;       /* 0x08: MP parent packet, parent send size */
    u8  *mpParentRingData;        /* 0x0C: storage of mpParentSendRing */
    u8  *recvRingData;            /* 0x10: storage of the per-member receive rings */
    u8  *parentRecvRingData;      /* 0x14: storage of parentRecvRing */
    u8  *recvScratchBuf;          /* 0x18: buffer a command is copied through */
    NetRingBuff sendRing;         /* 0x1C */
    NetRingBuff parentRecvRing;   /* 0x2C */
    NetRingBuff mpParentSendRing; /* 0x3C */
    NetRingBuff recvRing[GFL_NET_MACHINE_MAX];      /* 0x4C: one per member */
    NetQueue sendQueue;           /* 0xCC */
    NetQueue mpParentSendQueue;   /* 0xF4 */
    struct NetRecvCursor recvCursor[GFL_NET_MACHINE_MAX]; /* 0x11C: one per member */
    struct NetRecvCursor parentRecvCursor; /* 0x19C */
    u32 mpWaitMode;               /* 0x1AC: nonzero = the MP parent waits for all children */
    int parentRecvPending;        /* 0x1B0: receives requested from the parent, not yet delivered */
    int recvPending[GFL_NET_MACHINE_MAX];           /* 0x1B4: same, per member */
    u8  mpParentSeq;              /* 0x1D4: sequence of the MP parent packets */
    u8  sendSeq;                  /* 0x1D5 */
    u8  parentRecvSeq;            /* 0x1D6: sequence of the last packet from the parent */
    u8  recvSeq[GFL_NET_MACHINE_MAX];               /* 0x1D7: per member */
    u8  pad1DF;
    u32 packetBufSize;            /* 0x1E0: largest packet plus 0x40 */
    u16 memberBitmap;             /* 0x1E4: members the parent reported as connected */
    u8  pad1E6;
    u8  noChildError;             /* 0x1E7 */
    u8  sendBusy;                 /* 0x1E8: cleared by the reset, never read in this file */
    u8  errorFlag;                /* 0x1E9 */
    u8  noSend;                   /* 0x1EA */
    u8  sendReady;                /* 0x1EB */
    u8  autoFree;                 /* 0x1EC: free the work once the link is down */
    u8  ircRecvPending;           /* 0x1ED */
    u8  pad1EE[2];
};

/* Output of the send queue: where to write and how much room is left. */
struct NetPacketSpan {
    void *dest;
    u16 remaining;
};

/* Error record the state module keeps (four words). */
struct NetErrorInfo {
    int code;
    u32 detail0;
    u32 detail1;
    u32 line;            /* nonzero once an error was reported */
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void  MI_CpuFill8(void *dst, u8 val, u32 size);

extern void *func_02082BCC(void *dst, int val, u32 size);

extern void func_02039548(void);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern u32 func_020307B0(void *p);

extern u16 func_02039338(void);

extern int   func_020393A8(void);

extern int  func_020393D0(void);

extern GFLNetHandle *func_020399A8(void);

extern u16 func_0203F1FC(const u8 *src, u32 len);

extern int    func_02039594(void);

extern GFLNetHandle *func_0203996C(s32 idx);

extern void func_02082D44(const void *src, void *dst, int n);

extern int func_020395E0(int netId);

extern void func_0203C00C(void);

extern void func_020394DC(u8 v);

extern void func_02039578(void);

extern void func_02039560(void);

void func_0203640C(NetRingBuff *ring, u32 buffer, int size);

void func_02036428(NetRingBuff *r, const u8 *src, int len);

int func_020364D4(NetRingBuff *p, unsigned char *dst, u32 len, u32 max);

u32 func_02036500(NetRingBuff *a);

u32 func_02036540(NetRingBuff *a);

int func_020365E8(NetRingBuff *p);

void func_0203666C(NetRingBuff *r);

int func_020366A8(NetQueue *p);

int func_020368C0(NetQueue *queue, u32 command, const u8 *data, u32 size, u32 sendArg, u32 useRing, u32 queueArg);

int func_02036A50(u32 list, u16 *info);

void func_02036AF4(NetQueue *p, u32 n, NetRingBuff *a, u32 b);

int func_02036B4C(NetQueue *p);

void func_02036B88(NetQueue *queue);

int func_02036B98(NetQueue *p, int v);

u32 func_020370F4(u32 a);

void func_02037224(u8 phase, int line);

void func_02037234(struct NetRecvCursor *cursor);

u32 func_02037258(void);

int func_02037288(u32 packetSize, u32 heapId, u32 useParentSize);

void func_02037478(void);

void func_02037680(int netId);

int func_02037700(u32 packetSize, u32 heapId);

u32 func_0203778C(u32 arg);

u32 func_020377AC(u32 netId, u8 *packet, u32 length);

u32 func_020377B8(u8 renewTgid);

void func_0203781C(u32 netId);

void func_02037858(u32 netId);

u32 func_02037894(u8 renewTgid, u16 packetSize, u32 sendArg0, u32 sendArg1);

u32 func_02037928(u32 sendArg, u16 packetSize);

int func_020379C8(u32 packetSize);

void func_02037A44(int interval);

u32 func_02037A6C(u32 beaconArg0, u32 beaconArg1, u16 packetSize, u32 beaconArg2);

void func_02037B08(void);

void func_02037BA4(void);

void func_02037BE8(u32 netId);

int func_02037C10(void);

void func_02037D78(void);

int func_02037D98(int checkPending);

void func_02037E60(void);

void func_02037F48(void);

void func_0203802C(void);

u32 func_020380E4(u32 netId, u8 *packet, u32 length);

void func_020381D8(u32 buffer, u32 size);

void func_02038298(void);

void func_02038340(void);

void func_02038380(void);

int func_02038524(void);

void func_02038570(void);

void func_020385C4(void);

int func_020387A0(u32 netId, u8 *packet, s32 length);

int func_02038924(u32 netId, u8 *packet, s32 length);

int func_02038A48(int success);

int func_02038A90(u32 success);

s32 func_02038AE0(struct NetPacketHeader *header, NetQueue *queue, s32 packetSize, u8 seq);

int func_02038C18(u32 command, const void *data, u32 size, u32 sendArg, u32 destNetId, u32 queueArg, u32 noRing);

void func_02038D30(int unusedArg0, int unusedArg1, int unusedArg2, int unusedArg3);

void func_02038D4C(int unusedArg0, int unusedArg1, int unusedArg2, int unusedArg3);

void func_02038D68(int command, u32 size, u32 data, struct NetRecvCursor *cursor);

void func_02038DF0(NetRingBuff *ring, s32 senderID, u8 *buf, struct NetRecvCursor *cursor, u32 maxSize);

void func_02039050(void);

void func_020390BC(void);

int func_02039160(u32 netId);

u32 func_020392B8(void);

int func_020392EC(void);

u16 func_02039338(void);

int func_020393A8(void);

int func_020393D0(void);

u32 func_02039414(void);

int func_02039468(u32 command, u32 destNetId);

int func_020394C0(void);

void func_020394DC(u8 v);

void func_020394F0(u32 mode);

void func_02039548(void);

void func_02039560(void);

void func_02039578(void);

int func_02039594(void);

int func_020395E0(int slot);

GFLNetHandle *func_0203996C(s32 idx);

GFLNetHandle *func_020399A8(void);

u32 func_0203A634(u32 commandOption);

void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);

int func_0203A7EC(unsigned int idx);

int func_0203A804(unsigned int idx);

u32 func_0203A81C(u32 command, u32 senderID, u32 totalSize);

void func_0203ACAC(void);

void func_0203C00C(void);

void func_0203C864(void);

u32 func_0203C990(void);

void func_0203C9AC(int a, u32 b, u32 c, u32 d);

struct NetErrorInfo *func_0203CA98(void);

int func_0203D3A8(GFLNetHandle *a, u32 b, u32 c, const void *d);

u32 func_0203D680(void);

u32 func_0203D6BC(void);

GFLNetSession *func_0203D788(void);

GFLNetSession *func_0203D798(void);

extern u8 _NetPhase[];  /* [0] MP parent phase (1 receive, 2 wait, 3 done, 4 send); [1] send phase (0 idle, 2 receiving, 4 ready) */

extern char _FileName[];

extern struct NetSysWork *_pNetSys;


extern char _AssertNetIdRange[];





extern char _AssertAlways[];

extern char _AssertNotMpMode[];





void func_02037224(u8 phase, int line)
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
 *   python tools/match.py one --src src/matched/func_02037234.c \
 *       --func func_02037234 --addr 0x02037234 --cc 1.1p1 --arm
 */
void func_02037234(struct NetRecvCursor *cursor)
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
 *   python tools/match.py one --src src/matched/func_02037258.c \
 *       --func func_02037258 --addr 0x02037258 --cc 1.1p1 --arm
 */
u32 func_02037258(void)
{
    GFLNetSession *session;

    session = func_0203D788();
    if (session->init.bMPMode != 0 && session->init.parentSendSize != 0)
        return session->init.parentSendSize;
    return func_0203D6BC() * func_0203D680();
}

























/*
 * Closes the 4-byte residue docs/notes/pkt_02037288_wave25.c.txt records
 * (the `mov r3, r4` / `lsl r1, r1, #1` pair at +0x00B0).  The lever is the
 * ALLOCATION RESULT TYPE, not the size spelling: the seven pointer fields
 * are declared `void *` so each func_02030734 result is stored without an
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
int func_02037288(u32 packetSize, u32 heapId, u32 useParentSize)
{
    u32 maxMembers;
    u32 parentSendSize;

    if (_pNetSys == 0) {
        maxMembers = func_0203D680();
        parentSendSize = func_02037258();
        _pNetSys = func_02030734(heapId, 0x1f0, 1, _FileName, 0xdd);
        if (useParentSize != 0)
            _pNetSys->packetBufSize = parentSendSize + 0x40;
        else
            _pNetSys->packetBufSize = packetSize + 0x40;

        _pNetSys->parentRecvRingData = func_02030734(heapId, _pNetSys->packetBufSize * 3, 1,
                                          _FileName, 0xe6);
        _pNetSys->recvScratchBuf = func_02030734(heapId, _pNetSys->packetBufSize * 2, 1,
                                          _FileName, 0xe8);
        _pNetSys->recvRingData = func_02030734(heapId, maxMembers * _pNetSys->packetBufSize, 1,
                                          _FileName, 0xe9);
        _pNetSys->sendPacketBuf = func_02030734(heapId, func_0203D6BC(), 1,
                                          _FileName, 0xec);
        _pNetSys->sendRingData = func_02030734(heapId, func_0203D6BC() * 15, 1,
                                          _FileName, 0xed);
        _pNetSys->mpParentPacketBuf = func_02030734(heapId, parentSendSize, 1, _FileName, 0xee);
        _pNetSys->mpParentRingData = func_02030734(heapId, parentSendSize * 2, 1, _FileName, 0xef);
        func_02036AF4(&_pNetSys->sendQueue, 0x64,
                      &_pNetSys->sendRing, heapId);
        func_02036AF4(&_pNetSys->mpParentSendQueue, 0xb4,
                      &_pNetSys->mpParentSendRing, heapId);
        _pNetSys->mpWaitMode = 1;
        func_02037478();
    }
    _pNetSys->memberBitmap = 0;
    _pNetSys->noChildError = 0;
    return 1;
}

























/*
 * Second half of net_system init: wipe and re-seed every buffer
 * func_02037288 allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. func_0203640C is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as func_02037680); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
void func_02037478(void)
{
    s32 i;
    s32 maxMembers;
    s32 parentSendSize;
    s32 childSendSize;

    maxMembers = func_0203D680();
    parentSendSize = func_02037258();
    childSendSize = func_0203D6BC();

    func_02082BCC(_pNetSys->recvRingData, 0, _pNetSys->packetBufSize * maxMembers);
    for (i = 0; i < maxMembers; i++) {
        func_0203640C(&_pNetSys->recvRing[i],
              (u32)(_pNetSys->recvRingData + i * _pNetSys->packetBufSize), _pNetSys->packetBufSize);
        _pNetSys->recvSeq[i] = 0;
    }

    func_02082BCC(_pNetSys->mpParentRingData, 0, parentSendSize + parentSendSize);
    func_0203640C(&_pNetSys->mpParentSendRing, (u32)_pNetSys->mpParentRingData, (u32)parentSendSize << 1);
    for (i = 0; i < parentSendSize; i++)
        _pNetSys->mpParentPacketBuf[i] = 0;

    func_02082BCC(_pNetSys->sendRingData, 0, childSendSize * 16 - childSendSize);
    func_0203640C(&_pNetSys->sendRing, (u32)_pNetSys->sendRingData, ((u32)childSendSize << 4) - childSendSize);
    *_pNetSys->sendPacketBuf = 0xff;
    for (i = 1; i < childSendSize; i++)
        _pNetSys->sendPacketBuf[i] = 0;

    func_02082BCC(_pNetSys->parentRecvRingData, 0, _pNetSys->packetBufSize + _pNetSys->packetBufSize * 2);
    func_0203640C(&_pNetSys->parentRecvRing, (u32)_pNetSys->parentRecvRingData,
                  _pNetSys->packetBufSize * 3);
    for (i = 0; i < GFL_NET_MACHINE_MAX; i++) {
        func_02037234(&_pNetSys->recvCursor[i]);
        _pNetSys->recvPending[i] = 0;
    }
    _pNetSys->parentRecvPending = 0;
    func_02037234(&_pNetSys->parentRecvCursor);
    func_02037224(4, 0x13a);
    _NetPhase[1] = 4;
    func_02036B4C(&_pNetSys->sendQueue);
    func_02036B4C(&_pNetSys->mpParentSendQueue);
    _pNetSys->sendBusy = 0;
    _pNetSys->sendReady = 1;
    _pNetSys->noSend = 0;
    _pNetSys->ircRecvPending = 0;
}























/*
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: func_0203640C here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride packetBufSize passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { recvRingData + i * packetBufSize, packetBufSize }.
 */
void func_02037680(int netId)
{
    if (netId >= GFL_NET_MACHINE_MAX) {
        func_02034714(_FileName, 0x155, _AssertNetIdRange);
    }
    _pNetSys->recvPending[netId] = 0;
    func_0203640C(&_pNetSys->recvRing[netId], (u32)(_pNetSys->recvRingData + netId * _pNetSys->packetBufSize), _pNetSys->packetBufSize);
    _pNetSys->recvSeq[netId] = 0;
    func_02037234(&_pNetSys->recvCursor[netId]);
}























/*
 * Filed on lane 1 as the single-caller callee of src/pending/func_0203C864.c.
 * The 0x340 field is a table of function pointers reached through two
 * indirect calls; the third reaches a slot at +0x68 past two unread words at
 * +0x44 and +0x48, which is why the struct keeps them as padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037700.c \
 *       --func func_02037700 --addr 0x02037700 --cc 1.1p1 --arm
 */
int func_02037700(u32 packetSize, u32 heapId)
{
    GFLNetSession *initParam = func_0203D798();
    GFLNetSession *session = func_0203D788();
    u32 useParentSize = 0;

    if (session->init.bMPMode != 0 && session->init.parentSendSize != 0)
        useParentSize = 1;
    func_02037288(packetSize, heapId, useParentSize);
    session->ops->connectToParent(initParam->init.heapId, session, 0, session->userArg);
    session->ops->stop(0);
    session->ops->setErrorCallback(func_020387A0);
    return 1;
}























/*
 * 32-byte hook dispatcher: func_0203D788 returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203778C.c \
 *       --func func_0203778C --addr 0x0203778C --cc 1.1p1 --arm
 */
u32 func_0203778C(u32 arg)
{
    GFLNetSession *session = func_0203D788();
    u32 (*getBssDesc)(u32) = session->ops->getBssDesc;

    return getBssDesc(arg);
}




















u32 func_020377AC(u32 netId, u8 *packet, u32 length)
{
    return func_020380E4(netId, packet, length);
}













































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020377B8.c \
 *       --func func_020377B8 --addr 0x020377B8 --cc 1.1p1 --arm
 */
u32 func_020377B8(u8 renewTgid)
{
    u32 zero;
    GFLNetSession *initParam = func_0203D798();
    GFLNetSession *session = func_0203D788();
    u16 heapId;
    void (*setErrorCallback)(void *);

    initParam->init.bRenewTgid = renewTgid;
    setErrorCallback = session->ops->setErrorCallback;
    setErrorCallback(func_020377AC);

    zero = 0;
    heapId = initParam->init.heapId;
    func_02037288(0x80, heapId, zero);

    func_02037680(zero);
    func_02037680(1);
    func_02037680(2);

    return 1;
}













































/*
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203781C.c \
 *       --func func_0203781C --addr 0x0203781C --cc 1.1p1 --arm
 */
void func_0203781C(u32 netId)
{
    GFLNetSession *initParam = func_0203D798();
    GFLNetSession *session = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(netId);

    hook = initParam->init.connectFunc;
    if (hook == 0)
        return;
    hook(session->userArg, netId);
}













































/*
 * Byte-for-byte twin of func_0203781C (same 60 bytes, same call order): two
 * context getters, the per-slot reset for `arg`, then the hook at +8 of the
 * first context when it is installed, called with the first context's word at
 * +0x34C and the argument.  Two copies of the same 60 bytes exist in the image
 * and this is the second, so the pair also demonstrates that the listing's
 * duplicate-glue pattern is real code and not one function reached twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037858.c \
 *       --func func_02037858 --addr 0x02037858 --cc 1.1p1 --arm
 */
void func_02037858(u32 netId)
{
    GFLNetSession *initParam = func_0203D798();
    GFLNetSession *session = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(netId);

    hook = initParam->init.connectFunc;
    if (hook == 0)
        return;
    hook(session->userArg, netId);
}












































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037894.c \
 *       --func func_02037894 --addr 0x02037894 --cc 1.1p1 --arm
 */
u32 func_02037894(u8 renewTgid, u16 packetSize, u32 sendArg0, u32 sendArg1)
{
    GFLNetSession *initParam = func_0203D798();
    GFLNetSession *session = func_0203D788();
    u32 flag;
    u16 heapId;
    void (*setRecvCallback)(void *);
    void (*setErrorCallback)(void *);
    u32 (*sendToParent)(u32, u32);

    initParam->init.bRenewTgid = renewTgid;

    setRecvCallback = session->ops->setRecvCallback;
    setRecvCallback(func_0203781C);

    setErrorCallback = session->ops->setErrorCallback;
    setErrorCallback(func_020387A0);

    if (session->init.bMPMode != 0 && session->init.parentSendSize != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    initParam = func_0203D798();
    heapId = initParam->init.heapId;
    func_02037288(packetSize, heapId, flag);

    sendToParent = session->ops->sendToParent;
    return sendToParent(sendArg0, sendArg1);
}












































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037928.c \
 *       --func func_02037928 --addr 0x02037928 --cc 1.1p1 --arm
 */
u32 func_02037928(u32 sendArg, u16 packetSize)
{
    GFLNetSession *session = func_0203D788();
    void (*setRecvCallback)(void *);
    u32 (*sendToChild)(u32, u32);
    void (*setErrorCallback)(void *);
    u32 result;
    u32 flag;
    GFLNetSession *initParam;
    u16 heapId;

    setRecvCallback = session->ops->setRecvCallback;
    setRecvCallback(func_02037858);

    sendToChild = session->ops->sendToChild;
    result = sendToChild(sendArg, 0);

    if (result == 1) {
        setErrorCallback = session->ops->setErrorCallback;
        setErrorCallback(func_02038924);

        if (session->init.bMPMode != 0 && session->init.parentSendSize != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        initParam = func_0203D798();
        heapId = initParam->init.heapId;
        func_02037288(packetSize, heapId, flag);

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
 *   python tools/match.py one --src src/matched/func_020379C8.c \
 *       --func func_020379C8 --addr 0x020379C8 --cc 1.1p1 --arm
 */
int func_020379C8(u32 packetSize)
{
    int   result;
    GFLNetSession *session = func_0203D788();

    session->ops->setRecvCallback(func_02037858);
    result = session->ops->getFrameCount();
    if (result == 1) {
        session->ops->setErrorCallback(func_02038924);
        func_02037288(packetSize, func_0203D798()->init.heapId, 0);
        _NetPhase[1] = 4;
    }
    return result;
}












































void func_02037A44(int interval)
{
    GFLNetSession *session = func_0203D788();
    GFLNetModeOps *ops = session->ops;
    if (ops == 0)
        return;
    ops->setFrameInterval(interval);
}













































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037A6C.c \
 *       --func func_02037A6C --addr 0x02037A6C --cc 1.1p1 --arm
 */
u32 func_02037A6C(u32 beaconArg0, u32 beaconArg1, u16 packetSize, u32 beaconArg2)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *initParam = func_0203D798();
    void (*setErrorCallback)(void *);
    u32 flag;
    u16 heapId;
    u32 (*sendBeaconData)(u32, u32, u32, u32, u32);

    setErrorCallback = session->ops->setErrorCallback;
    setErrorCallback(func_02038924);

    if (beaconArg0 != 0) {
        if (session->init.bMPMode != 0 && session->init.parentSendSize != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        initParam = func_0203D798();
        heapId = initParam->init.heapId;
        func_02037288(packetSize, heapId, flag);

        _NetPhase[1] = 4;
    }

    sendBeaconData = session->ops->sendBeaconData;
    return sendBeaconData(beaconArg0, beaconArg1, 0, 0, beaconArg2);
}













































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037B08.c \
 *       --func func_02037B08 --addr 0x02037B08 --cc 1.1p1 --arm
 */
void func_02037B08(void)
{
    func_0203D788();
    func_0203D798();

    if (_pNetSys == 0) {
        return;
    }

    func_020307B0(_pNetSys->parentRecvRingData);
    func_020307B0(_pNetSys->recvScratchBuf);
    func_020307B0(_pNetSys->recvRingData);

    func_02036B88(&_pNetSys->mpParentSendQueue);
    func_02036B88(&_pNetSys->sendQueue);

    func_020307B0(_pNetSys->sendPacketBuf);
    func_020307B0(_pNetSys->sendRingData);
    func_020307B0(_pNetSys->mpParentPacketBuf);
    func_020307B0(_pNetSys->mpParentRingData);

    func_020307B0(_pNetSys);

    _pNetSys = 0;
}











































/*
 * 64 bytes gated on the byte at +0x1EC of the object the global pointer names:
 * when it is set, the first getter's non-zero answer runs func_02037B08 and
 * returns, the second getter's non-zero answer returns without it, and
 * everything else runs func_02037B08.  The two `bl func_02037B08` are separate
 * copies in the original, which is what the two arms give.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BA4.c \
 *       --func func_02037BA4 --addr 0x02037BA4 --cc 1.1p1 --arm
 */
void func_02037BA4(void)
{
    if (_pNetSys->autoFree == 0)
        return;
    if (func_02039338() == 0) {
        if (func_020393A8() == 0)
            func_02037B08();
        return;
    }
    func_02037B08();
}











































/*
 * Guards the eight-slot table behind the global at 0x021469D0: an unarmed
 * global returns through `popeq`, an index past 7 through `popcs` (the compare
 * is unsigned, so a negative index is rejected as well), and only a live slot
 * reaches func_02037680.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BE8.c \
 *       --func func_02037BE8 --addr 0x02037BE8 --cc 1.1p1 --arm
 */
void func_02037BE8(u32 netId)
{
    if (_pNetSys == 0)
        return;
    if (netId >= GFL_NET_MACHINE_MAX)
        return;
    func_02037680(netId);
}











































/*
 * The net tick dispatcher.  Two shapes are load-bearing: the noSend/0x393D0
 * early exit is an out-of-line `goto bail` block placed AFTER the main body,
 * and the main path's `return 1` is reached by a `goto done` that lands on
 * the SAME `mov r0,#1; pop` the bail block falls into.  Writing either as a
 * plain `return 1` duplicates the epilogue and loses the `b #0x2037d6c`.
 */
int func_02037C10(void)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *initParam = func_0203D798();

    if (_pNetSys == 0) {
        if (session != 0)
            session->ops->requestDisconnect(0);
        return 1;
    }

    {
        u32 (*getMyAid)(void) = session->ops->getMyAid;
        if (getMyAid != 0) {
            func_020370F4(getMyAid());
        }
    }

    if (_pNetSys->noSend != 0)
        goto bail;
    if (func_020393D0() != 0)
        goto bail;

    if (initParam->init.bMPMode == 0 && (initParam->init.bNetType == 0 || initParam->init.bNetType == 5)) {
        func_02037F48();
    } else if ((u8)(initParam->init.bNetType + 0xfd) <= 1) {
        func_0203802C();
    } else if ((u8)(initParam->init.bNetType + 0xff) <= 1) {
        func_02038298();
    } else {
        func_02038340();
        func_02039050();
        if (func_02039338() == 0) {
            if (func_02039160(0) != 0 && initParam->init.bMPMode != 0)
                func_020385C4();
        }
        if (func_02039338() != 0)
            goto skip;
    }
    func_020390BC();
skip:
    if (initParam->init.bNetType != 1 && initParam->init.bNetType != 2) {
        session->ops->requestDisconnect(
            _pNetSys->memberBitmap);
    }
    func_0203ACAC();
    func_02037BA4();
    goto done;

bail:
    session->ops->requestDisconnect(0);
done:
    return 1;
}










































/*
 * Teardown hook for the same global src/matched/func_02037BE8.c guards: the
 * armed pointer goes to func_02037478, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037D78.c \
 *       --func func_02037D78 --addr 0x02037D78 --cc 1.1p1 --arm
 */
void func_02037D78(void)
{
    struct NetSysWork *work;

    work = _pNetSys;
    if (work == 0)
        return;
    func_02037478();
}










































int func_02037D98(int checkPending)
{
    int result = 0;
    if (_NetPhase[1] != 4)
        return result;
    if (checkPending != 0) {
        struct NetSysWork *work = _pNetSys;
        if (work->parentRecvPending > 0)
            return result;
        if (func_02038AE0((struct NetPacketHeader *)work->sendPacketBuf, &work->sendQueue, func_0203D6BC(), work->sendSeq) != 0) {
            struct NetSysWork *workAgain = _pNetSys;
            workAgain->sendSeq++;
        }
        _NetPhase[1] = 0;
        result = 1;
    } else {
        struct NetSysWork *work = _pNetSys;
        if (func_02038AE0((struct NetPacketHeader *)work->sendPacketBuf, &work->sendQueue, func_0203D6BC(), work->sendSeq) != 0) {
            struct NetSysWork *workAgain = _pNetSys;
            workAgain->sendSeq++;
            _NetPhase[1] = 0;
            result = 1;
        }
    }
    return result;
}








































void func_02037E60(void)
{
    GFLNetSession *session = func_0203D788();
    u32 childSendSize = func_0203D6BC();
    u32 result;

    result = session->ops->getConnectedNum();
    if (result == 0)
        return;
    result = func_02039338();
    result = func_02039160(result);
    if (result == 0)
        return;
    if (_NetPhase[1] != 0)
        return;
    if (func_02039338() != 0) {
        result = session->ops->receivePacket((u32)_pNetSys->sendPacketBuf, childSendSize, 0, func_02038A48);
        if (result == 0)
            return;
        _NetPhase[1] = 2;
        _pNetSys->parentRecvPending = _pNetSys->parentRecvPending + 1;
    } else {
        _NetPhase[1] = 2;
        func_02038A48(1);
        func_020387A0(0, (u8 *)_pNetSys->sendPacketBuf, (u16)childSendSize);
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
void func_02037F48(void)
{
    s32 i;
    s32 maxMembers;
    u32 childSendSize;
    GFLNetSession *session;

    session = func_0203D788();

    if (session->ops->getSendBufferFree() == 0)
        return;

    if (_pNetSys->sendReady != 0)
        func_02037D98(1);

    if (session->ops->setSendMask((u32)_pNetSys->sendPacketBuf) != 1)
        goto fail;

    _NetPhase[1] = 4;
    _pNetSys->sendReady = 1;

    childSendSize = func_0203D6BC();
    maxMembers = func_0203D680();
    i = 0;
    if (maxMembers > 0) {
        childSendSize = (unsigned short)childSendSize;
        do {
        func_020387A0((unsigned short)i,
                      (u8 *)(session->ops->getRecvSize(i)), childSendSize);
            i++;
        } while (i < maxMembers);
    }
    return;

fail:
    _pNetSys->sendReady = 0;
}









































/*
 * Fourth entry of this packet's chain, and the one the lane table expected to
 * need two callees filed: it calls func_020381D8, whose own entry is in this
 * shard, so that site resolves through `matched`; 0x020366A8 and 0x0203D3A8,
 * the other two the table named, turn out to have outside witnesses
 * (0x02038B48 and 0x02039AAC) once the compared range is this one function
 * rather than the whole packet.
 *
 * The two literals in the tail are different objects: the first argument to
 * func_020381D8 is one dereference of the 0x021469D0 pointer word, and the
 * final store is into the byte at 0x020A7A20 + 1.  Reading them as the same
 * symbol makes the compiler pool the address once and spend a second
 * callee-saved register on the transfer value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203802C.c \
 *       --func func_0203802C --addr 0x0203802C --cc 1.1p1 --arm
 */
void func_0203802C(void)
{
    GFLNetSession *session;
    u32 value;

    session = func_0203D788();

    if (func_020366A8(&_pNetSys->sendQueue) != 0)
        func_0203D3A8(func_020399A8(), 0x10, 0, 0);

    value = (u32)session->ops->resetLink;
    if (value != 0)
        ((void (*)(void))value)();
    if (session->ops->getRunState() != 1)
        return;

    value = func_0203D6BC();
    if (session->ops->getErrorCode() != 1)
        return;
    if (func_02037D98(0) == 0)
        return;

    func_020381D8((u32)_pNetSys->sendPacketBuf, value);
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
 *   python tools/match.py one --src src/matched/func_020380E4.c \
 *       --func func_020380E4 --addr 0x020380E4 --cc 1.1p1 --arm
 */
u32 func_020380E4(u32 netId, u8 *packet, u32 length)
{
    int checksum;
    u32 dataSize;

    func_0203D798();
    func_0203D6BC();

    if (packet[4] == 0xFF)
        return 0;
    if (_pNetSys->recvRing[netId].state == 0 && (packet[4] & 2))
        return 0;

    checksum = func_0203F1FC(packet + 2, length - 2);
    if (packet[0] != (u8)checksum || ((checksum & 0xFF00) >> 8) != packet[1])
        return 0;
    if (_pNetSys->recvSeq[netId] != 0 &&
        (u8)(packet[5] - 1) != _pNetSys->recvSeq[netId])
        return 0;

    _pNetSys->recvSeq[netId] = packet[5];
    dataSize = packet[2];
    if (packet[4] & 8)
        dataSize += 0xFF;
    func_02036428(&_pNetSys->recvRing[netId], packet + 7, dataSize);
    _pNetSys->recvRing[netId].state = 1;
    return 1;
}









































/*
 * Second half of this packet's chain: it calls func_020380E4, whose own entry
 * is in this shard, so the call site is attested by `matched` rather than by
 * the single in-range witness the lane table saw.
 *
 * The flow: two global locks are set up, then the interface object reached
 * through *(p + 0x340) is asked twice (its +0xA4 and +0xAC entries); only if
 * both answer non-zero does the transfer run - otherwise the two literals at
 * 0x020A7A24/0x020A7A50 go to 0x02034714 with 0x400.  The transfer calls the
 * object's +0x64 entry with the two arguments and zeroed r2/r3, reads the
 * +0x80 entry for the record number, and hands (u16)record-number, first
 * argument and (u16)second argument to func_020380E4 before the fixed 4 /
 * 0x40C delay through 0x02037224.
 *
 * The guards' polarity is the `bne` / `beq` pair at +0x2C and +0x38: the two
 * object calls are one conjunction whose false arm is the failure block
 * written first, which is the if/else spelling and not a guard chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020381D8.c \
 *       --func func_020381D8 --addr 0x020381D8 --cc 1.1p1 --arm
 */
void func_020381D8(u32 buffer, u32 size)
{
    GFLNetSession *session;
    u32 aid;

    func_0203D798();
    session = func_0203D788();

    if (session->ops->getChannel() == 0 ||
        session->ops->getTgid() == 0) {
        func_02034714(_FileName, 0x400, _AssertAlways);
        return;
    }

    if (_NetPhase[1] != 0)
        return;
    session->ops->receivePacket(buffer, size, 0, 0);
    aid = session->ops->isParent();
    func_020380E4((u16)aid, (u8 *)buffer, (u16)size);
    func_02037224(4, 0x40C);
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
 *   python tools/match.py one --src src/matched/func_02038298.c \
 *       --func func_02038298 --addr 0x02038298 --cc 1.1p1 --arm
 */
void func_02038298(void)
{
    GFLNetSession *session;
    u32 childSendSize;

    func_0203D798();
    session = func_0203D788();
    childSendSize = func_0203D6BC();

    if (_pNetSys->noChildError == 0)
        return;
    if (_pNetSys->ircRecvPending == 0) {
        if (func_02038AE0((struct NetPacketHeader *)_pNetSys->sendPacketBuf, &_pNetSys->sendQueue,
                          func_0203D6BC(),
                          _pNetSys->sendSeq) != 0)
            _pNetSys->ircRecvPending = 1;
    }

    if (_pNetSys->ircRecvPending != 1)
        return;
    if (session->ops->receivePacket((u32)_pNetSys->sendPacketBuf, childSendSize,
                                                    0, 0) == 0)
        return;
    _pNetSys->ircRecvPending = 0;
}








































/*
 * Promoted from src/pending/ on lane 1.  All 64 concrete bytes are right; the
 * one open site was the PC24 at +0x0038, the `bl` to func_02037E60, which had
 * exactly one branch reference in the whole image (this one) and so no
 * `label` witness.  With src/matched/func_02037E60.c filed EXACT the site
 * resolves through the `matched` class and the file prints EXACT with no
 * change to its C.
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether func_02037D98(1) and func_02037E60 are reached.  The first
 * func_0203D798() result is discarded - the image overwrites r0 with
 * func_0203D788()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038340.c \
 *       --func func_02038340 --addr 0x02038340 --cc 1.1p1 --arm
 */
void func_02038340(void)
{
    GFLNetSession *session;

    func_0203D798();
    session = func_0203D788();
    if (session->ops->getConnectedNum() == 0)
        return;
    if (func_02039160(func_02039338()) == 0)
        return;
    func_02037D98(1);
    func_02037E60();
}






































void func_02038380(void)
{
    GFLNetSession *session = func_0203D788();

    func_0203D680();
    if (_NetPhase[0] == 1) {
        if ((int)func_020392B8() > 1) {
            func_02037224(2, 0x46a);
            if (session->ops->getConnectedNum() != 0) {
                u32 size = func_02037258();
                if (session->ops->receivePacket(
                        (u32)_pNetSys->mpParentPacketBuf, size, 0, func_02038A90) != 0)
                    goto tail;
                func_02037224(1, 0x46a + 4);
                goto tail;
            }
            if ((func_0203D798())->init.bNetType != 3 && (func_0203D798())->init.bNetType != 4)
                goto tail;
            if (session->ops->getErrorCode() == 0) {
                func_02037224(1, 0x475);
                goto tail;
            }
            if (_pNetSys->mpParentPacketBuf[2] == 0)
                return;
            {
                u32 size = func_0203D6BC();
                session->ops->receivePacket(
                    (u32)_pNetSys->mpParentPacketBuf, size, 0x64, 0);
            }
        }
    }
tail:
    if (_NetPhase[0] == 2) {
        func_02038570();
        func_02038924(0, _pNetSys->mpParentPacketBuf, (u16)func_02037258());
        func_02037224(3, 0x490 - 3);
    }
    if (session->ops->getConnectedNum() == 0)
        goto last;
    if ((func_0203D798())->init.bNetType == 3)
        goto last;
    if ((func_0203D798())->init.bNetType != 4)
        return;
last:
    func_02037224(4, 0x492);
}





































int func_02038524(void)
{
    int i;

    for (i = 0; i < GFL_NET_MACHINE_MAX; i++) {
        if (func_02039160((u16)i) != 0 && _pNetSys->recvPending[i] > 0) {
            return 0;
        }
    }
    return 1;
}






































void func_02038570(void)
{
    int i;
    int maxMembers = func_0203D680();

    for (i = 0; i < maxMembers; i++) {
        if (func_02039160((u16)i) != 0) {
            _pNetSys->recvPending[i] += 1;
        }
    }
}






































/*
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to func_02038380 in both of the middle bands.
 * func_02037224 takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual func_02034714(file, line, expr) triple.
 */
void func_020385C4(void)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *initParam = func_0203D798();
    u8 netType = initParam->init.bNetType;

    if ((u8)(netType + 0xff) <= 1) {
        if (func_02039160(0) == 0)
            return;
        if (initParam->init.bMPMode != 0)
            func_02034714(_FileName, 0x4d5, _AssertNotMpMode);
        if (_NetPhase[0] == 4 && _pNetSys->mpWaitMode != 0
            && func_02038524() != 0)
            func_02037224(1, 0x4da);
        if (_NetPhase[0] != 1)
            return;
        {
            u32 size = func_02037258();
            if (session->ops->receivePacket(
                    (u32)_pNetSys->mpParentPacketBuf, size, 0, 0) == 0)
                return;
        }
        func_02037224(4, 0x4e1);
        func_02038570();
        return;
    }
    if ((u8)(netType + 0xfd) <= 1) {
        if (_NetPhase[0] == 4) {
            struct NetSysWork *work = _pNetSys;
            u32 size = func_02037258();

            func_02038AE0((struct NetPacketHeader *)work->mpParentPacketBuf, &work->mpParentSendQueue, size, work->mpParentSeq);
            work = _pNetSys;
            work->mpParentSeq = (u8)(work->mpParentSeq + 1);
            func_02037224(1, 0x4f4);
        }
        func_02038380();
        return;
    }
    if (session->ops->getConnectedNum() == 0)
        return;
    if (func_02038524() == 0)
        return;
    if (_NetPhase[0] == 4) {
        struct NetSysWork *work = _pNetSys;
        u32 size = func_02037258();

        func_02038AE0((struct NetPacketHeader *)work->mpParentPacketBuf, &work->mpParentSendQueue, size, work->mpParentSeq);
        work = _pNetSys;
        work->mpParentSeq = (u8)(work->mpParentSeq + 1);
        func_02037224(1, 0x501);
    }
    func_02038380();
}






































/*
 * The indexed twin of src/matched/func_02038924.c (the own-slot variant):
 * same receive/validate/copy shape, but every global offset is scaled by
 * the slot index -- the 0x1B4 credit counter by i*4, the 0x54 accepted
 * flag and the 0x4C payload by i*16, the 0x1D7 sequence byte by i.  The
 * extra middle block this one has and 0x02038924 does not is the sequence
 * check at 0x1D7+i with its own 0x3F3 error line.
 */
int func_020387A0(u32 netId, u8 *packet, s32 length)
{
    struct NetSysWork *work;
    struct NetErrorInfo *errorInfo;
    u32 flags;
    s32 dataSize;
    int checksum;

    func_0203D6BC();
    if (packet == 0)
        return 0;
    work = _pNetSys;
    work->recvPending[netId] = work->recvPending[netId] - 1;
    if (netId == 0)
        _pNetSys->memberBitmap = packet[3];
    flags = packet[4];
    if (flags == 0xff)
        return 0;
    if (_pNetSys->recvRing[netId].state == 0) {
        if (flags & 2)
            return 0;
    }
    checksum = func_0203F1FC(packet + 2, length - 2);
    if (packet[0] != (u8)checksum || ((checksum & 0xff00) >> 8) != packet[1]) {
        func_02039548();
        errorInfo = func_0203CA98();
        if (errorInfo->line == 0)
            func_0203C9AC(errorInfo->code, errorInfo->detail0, errorInfo->detail1, 0x3f2);
        return 0;
    }
    {
        u8 *recvSeq = _pNetSys->recvSeq;
        if (recvSeq[netId] != 0 && (u8)(packet[5] - 1) != recvSeq[netId]) {
            func_02039548();
            errorInfo = func_0203CA98();
            if (errorInfo->line == 0)
                func_0203C9AC(errorInfo->code, errorInfo->detail0, errorInfo->detail1, 0x3f3);
            return 0;
        }
        recvSeq[netId] = packet[5];
    }
    dataSize = packet[2];
    if (packet[4] & 8)
        dataSize += 0xff;
    func_02036428(&_pNetSys->recvRing[netId], packet + 7, dataSize);
    _pNetSys->recvRing[netId].state = 1;
    return 1;
}





































int func_02038924(u32 netId, u8 *packet, s32 length)
{
    struct NetSysWork *work;
    struct NetErrorInfo *errorInfo;
    u32 flags;
    s32 dataSize;
    int checksum;

    (int)func_0203D798();
    func_0203D6BC();
    work = _pNetSys;
    work->parentRecvPending = work->parentRecvPending - 1;
    if (packet == 0)
        return 0;
    if (netId == 0)
        _pNetSys->memberBitmap = packet[3];
    flags = packet[4];
    if (flags == 0xff)
        return 0;
    if (_pNetSys->parentRecvRing.state == 0) {
        if (flags & 2)
            return 0;
    }
    checksum = func_0203F1FC((const u8 *)(packet + 2), length - 2);
    if (packet[0] != (u8)checksum || ((checksum & 0xff00) >> 8) != packet[1]) {
        func_02039548();
        errorInfo = func_0203CA98();
        if (errorInfo->line == 0)
            func_0203C9AC(errorInfo->code, errorInfo->detail0, errorInfo->detail1, 0x3f2);
        return 0;
    }
    _pNetSys->parentRecvSeq = packet[5];
    dataSize = packet[2];
    if (packet[4] & 8)
        dataSize += 0xff;
    func_02036428(&_pNetSys->parentRecvRing, packet + 7, dataSize);
    _pNetSys->parentRecvRing.state = 1;
    return 1;
}





































/*
 * Idempotent bring-up: when the argument is non-zero and the mode byte at
 * 0x020A7A21 still reads 2, it is flipped to 4 and the call is skipped; in
 * every other case the 0x5C0-byte block at 0x020A7A24 is handed to
 * func_02034714 with 0x020A7A50 as the third argument.  Either way the
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
 *   python tools/match.py one --src src/matched/func_02038A48.c \
 *       --func func_02038A48 --addr 0x02038A48 --cc 1.1p1 --arm
 */
int func_02038A48(int success)
{
    if (success != 0 && _NetPhase[1] == 2) {
        _NetPhase[1] = 4;
    } else {
        func_02034714(_FileName, 0x5C0, _AssertAlways);
    }
    return 1;
}





































int func_02038A90(u32 success)
{
    func_0203D6BC();
    func_0203D680();
    func_0203D798();
    if (success != 0) {
        func_02037224(4, 0x5d4);
    } else {
        func_02034714(_FileName, 0x5d8, _AssertAlways);
    }
    return 1;
}





































s32 func_02038AE0(struct NetPacketHeader *header, NetQueue *queue, s32 packetSize, u8 seq)
{
    GFLNetSession *initParam;
    GFLNetSession *session;
    struct NetPacketSpan span;
    s32 dataSize;
    u16 checksum;

    initParam = func_0203D798();
    session = func_0203D788();

    MI_CpuFill8(header, 0, (u32)packetSize);

    if (queue->sendContinued == 0)
        header->flags = 1;
    else
        header->flags = 2;
    queue->sendContinued = 0;

    header->memberBitmap = session->ops->getRssi();

    if (func_020366A8(queue) == 0)
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
    if (func_02036A50((u32)queue, (u16 *)(&span)) == 0)
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

    checksum = func_0203F1FC(&header->size, packetSize - 2);
    header->checksumLow = (u8)checksum;
    header->checksumHigh = (u8)((checksum & 0xff00) >> 8);

    return 1;
}




































/*
 * Seven-argument entry to the comms send path.  The seventh argument is a
 * flag whose INVERSE becomes the `broadcast` byte handed to func_020368C0:
 * `flag == 0` gives 1, anything else gives 0, materialised as
 * `mov r5,#1` / `cmp r4,#0` / `movne r5,#0` before the first call.
 *
 * The module handle behind the global at 0x021469D0 is fetched once and every
 * later read comes off the same pooled base; a null handle, a busy queue
 * (func_02039414 non-zero or func_0203C990 zero) and a failed func_02039594
 * all return 0 early.  func_0203D798's result is only used for its +0x64
 * byte, which selects the +0xf4 table over the +0xcc one when the fifth
 * argument is the 0xff wildcard.
 *
 * The broadcast flag is additionally cleared when the third argument is not
 * less than the handle's +0x1e0 word: `cmp r7,r0` / `cmpge r5,#1` /
 * `moveq r5,#0` is the conjunction `if (size >= packetBufSize && useRing != 0) flag = 0;`
 * written as one expression
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * On a failed send the error path reports through func_0203CA98's three-word
 * record with line 0x3f4 and returns 0; a successful send returns 1.
 *
 * Addresses are Black-image addresses.
 *
 * BYTE-CORRECT, PARKED: 280 bytes, 0 concrete mismatches.  Capped at MATCH by
 * the sole unresolved site, the PC24 at +0x00D0 naming func_020368C0
 * (0x020368C0).  That address has no branch anywhere in the image outside this
 * function's own `bl` and no manifest entry, so neither `label` nor `matched`
 * can attest it; the call is the last thing before the function's two tail
 * exits, so no cut frees it either.  Filing 0x020368C0 promotes this file
 * unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038C18.c \
 *       --func func_02038C18 --addr 0x02038C18 --cc 1.1p1 --arm
 */
int func_02038C18(u32 command, const void *data, u32 size, u32 sendArg, u32 destNetId, u32 queueArg, u32 noRing)
{
    GFLNetSession *initParam;
    struct NetSysWork *work;
    struct NetErrorInfo *err;
    NetQueue *queue;
    u32 useRing;

    useRing = 1;
    if (noRing != 0)
        useRing = 0;

    initParam = func_0203D798();
    if (_pNetSys == 0)
        return 0;
    if (func_02039414() != 0 || func_0203C990() != 0)
        return 0;
    if (func_02039594() == 0)
        return 0;

    work = _pNetSys;
    if ((int)size >= (int)work->packetBufSize && useRing == 1)
        useRing = 0;

    if (initParam->init.bMPMode != 0 && destNetId == 0xff)
        queue = &work->mpParentSendQueue;
    else
        queue = &work->sendQueue;

    if (func_020368C0(queue, command, data, size, sendArg, useRing, queueArg) != 0)
        return 1;

    func_02039548();
    err = func_0203CA98();
    if (err->line == 0)
        func_0203C9AC(err->code, err->detail0, err->detail1, 0x3f4);
    return 0;
}



































void func_02038D30(int unusedArg0, int unusedArg1, int unusedArg2, int unusedArg3)
{
    func_020365E8(&_pNetSys->sendRing);
}



































void func_02038D4C(int unusedArg0, int unusedArg1, int unusedArg2, int unusedArg3)
{
    func_020365E8(&_pNetSys->mpParentSendRing);
}




































/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038D68.c \
 *       --func func_02038D68 --addr 0x02038D68 --cc 1.1p1 --arm
 */
void func_02038D68(int command, u32 size, u32 data, struct NetRecvCursor *cursor)
{
    u32 handle;

    func_0203D798();
    handle = (u32)func_0203996C(func_02039338());
    func_0203A770(cursor->senderID, cursor->commandOption, command, size, data, handle);

    if (func_02039338() == 0) {
        handle = (u32)func_0203996C(0xFF);
        if (command < 0x11)
            func_0203A770(cursor->senderID, cursor->commandOption, command, size, data, handle);
    }

    func_02037234(cursor);
}




































/*
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header func_0203640C builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - func_020364D4 is written in BOTH arms of the func_0203A804 test,
 *       if (!func_0203A804(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     func_02036540's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */
void func_02038DF0(NetRingBuff *ring, s32 senderID, u8 *buf, struct NetRecvCursor *cursor, u32 maxSize)
{
    int len;
    s16 savedReadPos;
    u8 *dest;
    u32 command;
    int copyCount;

    func_0203D798();
    while (func_020365E8(ring) != 0) {
        command = cursor->command;
        if (command == 0) {
            command = func_02036540(ring);
            if (command == 0) {
                func_02034714(_FileName, 0x6E3, _AssertAlways);
                continue;
            }
        }
        savedReadPos = ring->readPos;
        cursor->command = command;
        if (cursor->totalSize == 0xFFFF) {
            if (func_020365E8(ring) < 3) {
                ring->readPos = savedReadPos;
                return;
            }
            {
                u16 v = func_02036540(ring);
                cursor->remaining = v;
                cursor->totalSize = v;
            }
            cursor->senderID = senderID;
            cursor->commandOption = func_02036500(ring);
        }
        savedReadPos = ring->readPos;
        if (func_0203A804(command) && func_0203A634(cursor->commandOption)) {
            if (cursor->dest == 0)
                cursor->dest = (u8 *)func_0203A81C(command, cursor->senderID, cursor->totalSize);
            dest = cursor->dest + cursor->copied;
        } else {
            dest = buf;
            cursor->dest = buf;
        }
        if (!func_0203A634(cursor->commandOption))
            dest = 0;
        if (!func_0203A804(command))
            len = func_020364D4(ring, buf, cursor->remaining, cursor->remaining);
        else
            len = func_020364D4(ring, buf, cursor->remaining, maxSize - 7);
        cursor->remaining = cursor->remaining - (u16)len;
        copyCount = len;
        if (cursor->totalSize > cursor->copied) {
            copyCount = cursor->totalSize - cursor->copied;
            if (copyCount > len)
                copyCount = len;
            if (dest != 0)
                func_02082D44(buf, dest, copyCount);
        }
        cursor->copied += copyCount;
        if (cursor->remaining == 0) {
            func_02038D68(command, cursor->totalSize, (u32)cursor->dest, cursor);
            continue;
        }
        if (!func_0203A7EC(command))
            return;
        if (func_0203A804(command))
            return;
        if (!func_0203A634(cursor->commandOption))
            return;
        cursor->remaining += (u16)len;
        ring->readPos = savedReadPos;
        return;
    }
}


































void func_02039050(void)
{
    int i;
    struct NetSysWork *work;

    if (_pNetSys == 0)
        return;

    func_0203666C(&_pNetSys->parentRecvRing);

    for (i = 0; i < 4; i++) {
        if ((int)func_020365E8(&_pNetSys->parentRecvRing) <= 0)
            return;

        work = _pNetSys;
        func_02038DF0(&work->parentRecvRing, 0xFF, work->recvScratchBuf,
                      &work->parentRecvCursor, func_02037258());
    }
}



































/*
 * n slots of 0x10 bytes at g+0x4c, each prepared by func_0203666C and then
 * offered to func_02038DF0 up to four times, with the record at g+0x11c and
 * the frame returned by func_0203D6BC handed to each call.
 *
 * Three spellings are load-bearing.  The global is re-read through
 * _pNetSys itself in every statement (mwcc keeps its address in `sb` and
 * reloads the value, because the calls may store through it).  There is no
 * explicit `if (n <= 0) return;`: with `n = func_0203D680();` followed
 * straight by `for (i = 0; i < n; i++)` the loop's pre-test folds to
 * `cmp r7, #0` / `pople` because i is known zero, and the loop-exit
 * epilogue tail-merges with the function's own.  And the inner body is
 * `if (test > 0) call(...)` rather than `if (test <= 0) break;`, because
 * the original's branch lands on the inner increment (the continue path).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020390BC.c \
 *       --func func_020390BC --addr 0x020390BC --cc 1.1p1 --arm
 */
void func_020390BC(void)
{
    int i, j, maxMembers;
    u8 *sendSize;

    sendSize = (u8 *)func_0203D6BC();
    if (_pNetSys == 0)
        return;

    maxMembers = func_0203D680();

    for (i = 0; i < maxMembers; i++) {
        func_0203666C(&_pNetSys->recvRing[i]);
        for (j = 0; j < 4; j++) {
            if (func_020365E8(&_pNetSys->recvRing[i]) > 0)
                func_02038DF0(&_pNetSys->recvRing[i], i,
                              _pNetSys->recvScratchBuf,
                              &_pNetSys->recvCursor[i], (u32)sendSize);
        }
    }
}



































int func_02039160(u32 netId)
{
    GFLNetSession *session;
    GFLNetSession *initParam;
    struct NetSysWork *work;
    u32 netType;
    u16 bitmap;

    session = func_0203D788();
    initParam = func_0203D798();
    work = _pNetSys;
    if (work == 0)
        return 0;
    netType = (u8)(initParam->init.bNetType + 0xff);
    if (netType <= 1) {
        if (work->noChildError != 0) {
            if (session->ops->isParent() != -1) {
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
            if (session->ops->getConnectedNum() != 0)
                return 1;
        }
        return 0;
    }
    if (func_020392EC() == 0)
        return 0;
    if (session->ops->getConnectedNum() == 0)
        return 0;
    if (netId == (u32)func_02039338())
        return 1;
    if (func_02039338() == 0 || initParam->init.bMPMode == 0) {
        bitmap = (u16)session->ops->getRssi();
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
 *   python tools/match.py one --src src/matched/func_020392B8.c \
 *       --func func_020392B8 --addr 0x020392B8 --cc 1.1p1 --arm
 */
u32 func_020392B8(void)
{
    int count;
    int i;

    count = 0;
    for (i = 0; i < GFL_NET_MACHINE_MAX; i++) {
        if (func_02039160((u16)i) != 0)
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
 *   python tools/match.py one --src src/matched/func_020392EC.c \
 *       --func func_020392EC --addr 0x020392EC --cc 1.1p1 --arm
 */
int func_020392EC(void)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *initParam = func_0203D798();

    if (_pNetSys != 0 && (u8)(initParam->init.bNetType + 0xFF) <= 3)
        return 1;

    return session->ops->getRunState();
}
































u16 func_02039338(void)
{
    GFLNetSession *session;
    u8 netTypeBias;
    s32 aid;

    if (_pNetSys == 0) {
        goto none;
    }

    session = func_0203D788();
    netTypeBias = (func_0203D798())->init.bNetType + 0xff;

    if (netTypeBias <= 1) {
        aid = session->ops->isParent();
        if (aid == -1) {
            goto none;
        }
        return (u16)aid;
    }

    return (u16)session->ops->isParent();

none:
    return 0;
}































int func_020393A8(void)
{
    u16 memberBitmap;

    memberBitmap = func_0203D788()->ops->getRssi();
    return memberBitmap & 0xFFFE;
}































/*
 * Is the link busy?  The +0x1e9 flag on the link state forces a yes, and
 * otherwise the driver's own predicate at +0x88 decides.
 *
 * The two halves of the flag test share one `ne` chain and a single `popne`,
 * so they are one `&&` rather than nested `if`s.  func_0203D788 is called
 * before the flag is even read because its result is needed on the fall
 * through path, and the compiler will not sink a call past a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020393D0.c \n *       --func func_020393D0 --addr 0x020393D0 --cc 1.1p1 --arm
 */
int func_020393D0(void)
{
    GFLNetSession *session;

    session = func_0203D788();

    if (_pNetSys != 0 && _pNetSys->errorFlag != 0) {
        return 1;
    }
    return session->ops->isInitialized() != 0;
}
































/*
 * Asks the transport's +0x88 virtual whether the link is up, falling back to
 * the +0x1E9 flag of the object at 0x021469D0 when the virtual is missing or
 * answers zero.  Both re-tests are conditional-execution chains (`cmpne`), so
 * the source is the `!= 0 && ...` spelling in each place.  The result local
 * is declared after the context refresh and assigned at its first use: with
 * `u32 r = 0;` ahead of the refresh the value is live across func_0203D788
 * and the allocator spends a callee-saved register on it (`push {r4, lr}`
 * instead of the original's `push {r3, lr}`).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039414.c  *       --func func_02039414 --addr 0x02039414 --cc 1.1p1 --arm
 */
u32 func_02039414(void)
{
    GFLNetSession *session = func_0203D788();
    u32 result = 0;

    if (session != 0 && session->ops != 0)
        result = session->ops->isInitialized();
    if (result == 0) {
        struct NetSysWork *work = _pNetSys;

        if (work != 0 && work->errorFlag != 0)
            result = 1;
    }
    return result;
}
































int func_02039468(u32 command, u32 destNetId)
{
    GFLNetSession *initParam = func_0203D798();

    if (initParam->init.bMPMode != 0 && destNetId == 0xff) {
        return func_02036B98(&_pNetSys->mpParentSendQueue, command);
    } else {
        return func_02036B98(&_pNetSys->sendQueue, command);
    }
}
































/*
 * Leaf that saves no lr: tail-calls func_020366A8 on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, sendQueue).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */
int func_020394C0(void)
{
    return func_020366A8(&_pNetSys->sendQueue);
}































/*
 * A leaf setter on the link state: store the argument byte at +0x1e7.  It
 * saves no registers, so disasm.py gives it no label and it prints as a run
 * of `.word`s between two pools
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020394DC.c \n *       --func func_020394DC --addr 0x020394DC --cc 1.1p1 --arm
 */
void func_020394DC(u8 v)
{
    _pNetSys->noChildError = v;
}































void func_020394F0(u32 mode)
{
    u8 netType = func_0203D798()->init.bNetType;

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
 * Set the +0x1e9 flag on the link state.  func_02039560 is the clearing half;
 * the two are byte-for-byte the same but for the stored constant.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039548.c \n *       --func func_02039548 --addr 0x02039548 --cc 1.1p1 --arm
 */
void func_02039548(void)
{
    _pNetSys->errorFlag = 1;
}






























/*
 * Clear the +0x1e9 flag func_02039548 sets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039560.c \n *       --func func_02039560 --addr 0x02039560 --cc 1.1p1 --arm
 */
void func_02039560(void)
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
 *   python tools/match.py one --src src/matched/func_02039578.c \n *       --func func_02039578 --addr 0x02039578 --cc 1.1p1 --arm
 */
void func_02039578(void)
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
 *   python tools/match.py one --src src/matched/func_02039594.c \n *       --func func_02039594 --addr 0x02039594 --cc 1.1p1 --arm
 */
int func_02039594(void)
{
    GFLNetSession *initParam;

    if (_pNetSys == 0) {
        goto yes;
    }

    initParam = func_0203D798();
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
 *   python tools/match.py one --src src/matched/func_020395E0.c \n *       --func func_020395E0 --addr 0x020395E0 --cc 1.1p1 --arm
 */
int func_020395E0(int netId)
{
    if (netId >= GFL_NET_MACHINE_MAX) {
        netId = 0xFF;
    }
    return netId;
}






























