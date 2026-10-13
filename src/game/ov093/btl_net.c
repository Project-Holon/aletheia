/*
 * file:     btl_net.c
 * unit:     yes
 * function: func_021D4150, func_021D4230, func_021D4254, func_021D4270, func_021D4294, func_021D42BC, func_021D4330, func_021D4348, func_021D4360, func_021D4378, func_021D4394, func_021D43B8, func_021D43E0, func_021D440C, func_021D4438, func_021D446C, func_021D44B4, func_021D44CC, func_021D4500, func_021D450C, func_021D4558, func_021D45B8, func_021D45FC, func_021D4648, func_021D4674, func_021D4680, func_021D46B0, func_021D46FC, func_021D4784, func_021D47A4, func_021D4800, func_021D4808, func_021D4838, func_021D4880, func_021D4898, func_021D48CC, func_021D4908, func_021D4954, func_021D499C, func_021D49B0, func_021D49CC, func_021D49E0, func_021D4A0C, func_021D4A64, func_021D4A6C, func_021D4AF4, func_021D4B18, func_021D4B58, func_021D4B98, func_021D4BD4, func_021D4BFC, func_021D4C14, func_021D4C58, func_021D4C60, func_021D4C6C, func_021D4C84, func_021D4CB8, func_021D4CE0, func_021D4CEC, func_021D4D24, func_021D4D5C, func_021D4D64
 * address:  0x021D4150
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   d_021F3A98 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B00  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02008468 0x02008468 thumb
 *   func_02045A98  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021D4A04  0x021D4A04  thumb
 */
#include "btl_net_types.h"

struct NetHandle;
struct StrBuf;

/*
 * Battle setup exchange over the wireless link, before the first turn.
 * Every message type is a GFL_NET command id (BTL_NET_CMD_*). One block,
 * d_021F3B88, holds the state for the whole exchange.
 *
 * Order of the exchange:
 *   ENTRY            each player announces itself; the lowest net id wins the lead
 *   SETUP            the leader broadcasts the 32-byte battle setup
 *   PARTY            each player sends its party
 *   PERAP_VOICE      each player sends its recorded voice
 *   RELAY_PARTY      the leader forwards parties to players that cannot see each other
 *   PLAYER_INFO      each player sends its trainer record
 *   RELAY_PLAYER_INFO  the leader forwards trainer records
 * During the battle:
 *   SERVER_CMD       the server sends a command block to one client
 *   CLIENT_REPLY     a client sends its answer back to the server
 */
#define BTL_NET_CMD_ENTRY 0x100
#define BTL_NET_CMD_SETUP 0x101
#define BTL_NET_CMD_PARTY 0x102
#define BTL_NET_CMD_PERAP_VOICE 0x103
#define BTL_NET_CMD_RELAY_PARTY 0x104
#define BTL_NET_CMD_PLAYER_INFO 0x105
#define BTL_NET_CMD_RELAY_PLAYER_INFO 0x106
#define BTL_NET_CMD_SERVER_CMD 0x107
#define BTL_NET_CMD_CLIENT_REPLY 0x108

#define BTL_NET_SEND_ALL 0xff       /* send target: every player */
#define BTL_NET_NO_NETID 0x28       /* "no such player" for a net id */
#define BTL_NET_NO_CLIENT 4         /* "no such client" for a client id */
#define BTL_NET_ENTRY_VALUE 0x64    /* value every player sends in its ENTRY message */
#define BTL_NET_PLAYER_MAX 4

/* Heap id with the flag the allocator uses for a block at the heap tail. */
#define BTL_NET_TAIL_HEAP(heapId) ((u16)(((heapId) & 0x7fff) | 0x8000))

/* The 32-byte battle setup the leader broadcasts. */
typedef struct {
    int words[8];
} BtlNetSetup;

/*
 * One message buffer: the received bytes, then the number of bytes that
 * arrived and a flag that is set while the buffer waits for its message.
 */
struct BtlNetMsgSlot {
    u8 data[0xbb8];
    u16 size;
    u16 waiting;
};

/* Result of the ENTRY round: for each net id, the value it sent and whether it arrived. */
struct BtlNetEntrySync {
    struct {
        u8 value;
        u8 received;
    } entries[4];
    u8 receivedCount;
    u8 maxValue;
    u8 pad[2];
};

struct BtlNet {
    void *netHandle;
    u16 heapId;
    u8 ownNetId;
    u8 leaderNetId;                 /* BTL_NET_NO_NETID until the ENTRY round ends */
    u16 memberMask;                 /* bit per net id that takes part */
    u8 setupReceived;               /* the SETUP block in setup is valid */
    u8 memberCount;
    u8 reserved0C;
    u8 serverCmdPending;            /* serverCmdSlot holds a command not yet answered */
    u8 reserved0E;
    u8 syncStage;                   /* stage this player announced in its user info */
    u8 syncPending;                 /* syncStage was announced and is not yet confirmed */
    u8 clientIds[BTL_NET_PLAYER_MAX];   /* client id of each net id, BTL_NET_NO_CLIENT if none */
    u8 pad15[3];
    BtlNetSetup setup;
    struct BtlNetMsgSlot serverCmdSlot;
    struct BtlNetMsgSlot replySlots[BTL_NET_PLAYER_MAX];    /* client replies, per net id */
    void *recvBuf[BTL_NET_PLAYER_MAX];  /* receive buffer per net id */
    void *recvDone[BTL_NET_PLAYER_MAX]; /* set when that buffer is complete */
    void *relayBuf[BTL_NET_PLAYER_MAX]; /* forwarded data, per client id */
    void *tempBuf;                  /* buffer of the message in transit */
    void *tempDone;                 /* set when tempBuf is complete */
    union {
        u32 word;
        u16 halves[2];
    } sendScratch;                  /* small outgoing message body */
    struct BtlNetEntrySync entrySync;
};

/* Message header: type in the low byte, byte count above it. */
typedef union {
    u32 word;
    struct {
        u32 type : 8;
        u32 size : 24;
    } h;
} BtlNetPacketHeader;

/* Trainer record: 0x28 bytes, the second part holds the name buffer. */
struct MyStatus {
    u8 head[0x14];
    struct StrBuf *name;
    u8 tail[0x28 - 0x18];
};

/* A MyStatus with its name copied in, so it can be sent. */
struct BtlNetMyStatusPacket {
    struct MyStatus status;
    u16 nameChars[0x20];
    u32 nameLength;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_0203D1A4(struct NetHandle *handle);
extern int func_0203D1B4(void);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern int func_0203D3A8(struct NetHandle *handle, u32 cmd, u32 size, u32 data);
extern u32 func_0203D3F8(u32 handle, u32 sendId, u32 cmd, u32 size, u32 data, u32 flag0, u32 flag1, u32 flag2);
extern int POKE_REGULATION_GetDataSize(void);
extern void *func_02007B50(void **p);
extern u32 func_02007B00(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *party, u32 index);
extern int func_02008468(void);
extern u16 func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern u16 STRBUF_GetLength(struct StrBuf *buf);
extern u16 *STRBUF_GetChars(struct StrBuf *buf);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void GFL_NET_HANDLE_SetUserInfo(char *handle, int stage, int flag, int memberMask);
extern unsigned int func_02039CB4(struct NetHandle *handle, unsigned int stage, unsigned int flag);

void func_021D4150(void *netHandle, u16 memberMask, u16 heapId);
int func_021D4230(void);
void func_021D4254(void);
int func_021D4270(void);
int func_021D4294(u16 clientId);
void func_021D42BC(int netId, int unused, u16 *data);
u8 func_021D4330(int netId);
int func_021D4348(void);
int func_021D4360(void);
u8 func_021D4378(void);
u8 func_021D4394(u32 clientId);
u32 func_021D43B8(u32 setup);
void func_021D43E0(int unused0, int unused1, BtlNetSetup *src);
int func_021D440C(BtlNetSetup *dst);
u8 func_021D4438(u32 party);
void *func_021D446C(int netId, int unused, u32 size);
void func_021D44B4(int netId, void *buf);
int func_021D44CC(void);
void func_021D4500(void);
u32 func_021D450C(u32 *voice);
void *func_021D4558(int netId, int unused, u32 size);
void func_021D45B8(int netId, int doneOrSize);
int func_021D45FC(void);
u32 func_021D4648(u32 clientId);
void func_021D4674(void);
u32 func_021D4680(u32 *packet);
void *func_021D46B0(int unused0, int unused1, u32 size);
void func_021D46FC(u32 unused0, u32 unused1, const BtlNetPacketHeader *packet);
int func_021D4784(u32 clientId);
void *func_021D47A4(u8 clientId);
void func_021D4800(void);
int func_021D4808(u32 myStatus);
void *func_021D4838(int netId, int unused, u32 size);
void func_021D4880(int netId, void *buf);
int func_021D4898(void);
void *func_021D48CC(u8 clientId);
u32 func_021D4908(void *myStatus);
u32 func_021D4954(void *unused0, int unused1, int size);
void func_021D499C(int unused, void *buf);
int func_021D49B0(void);
void *func_021D49CC(void);
void func_021D49E0(void);
void func_021D4A04(void);
struct BtlNetMyStatusPacket *func_021D4A0C(struct MyStatus *myStatus, u32 heapId);
void func_021D4A64(void *packet);
void func_021D4A6C(void);
void func_021D4AF4(int stage);
int func_021D4B18(int stage);
u32 func_021D4B58(u32 clientId, u32 data, u32 size);
int func_021D4B98(void);
u16 func_021D4BD4(int clientId, u8 **data);
struct BtlNetMsgSlot *func_021D4BFC(int netId);
void func_021D4C14(int netId, u32 size);
void func_021D4C58(u32 unused);
unsigned char func_021D4C60(void);
u16 func_021D4C6C(u8 **data);
u32 func_021D4C84(u32 data, u32 size);
void func_021D4CB8(int unused, u32 size);
struct BtlNetMsgSlot *func_021D4CE0(void);
void func_021D4CEC(void);
void *func_021D4D24(u32 size, u16 heapId);
void func_021D4D5C(void *packet);
void func_021D4D64(u32 *packet, const void *src, u32 clientId);
extern struct BtlNet *d_021F3B88;
extern const char d_021F3A98[];

/*
 * Create the exchange block. Without a link there is no exchange and the
 * global stays empty. Counts the players in the mask, at most as many as
 * the link negotiated.
 * The three loops use separate counters; the zero of the first one is
 * reused for the two byte stores before the second loop.
 */
void func_021D4150(void *netHandle, u16 memberMask, u16 heapId)
{
    u32 memberCount, i, j, k, maxMembers;
    if (netHandle) {
        d_021F3B88 = func_02030734(heapId, sizeof(struct BtlNet), 1, d_021F3A98, 0xd4);
        d_021F3B88->netHandle = netHandle;
        d_021F3B88->memberMask = memberMask;
        d_021F3B88->heapId = heapId;
        d_021F3B88->ownNetId = func_0203D1A4(netHandle);
        d_021F3B88->leaderNetId = BTL_NET_NO_NETID;
        i = 0;
        d_021F3B88->serverCmdPending = i;
        d_021F3B88->reserved0E = i;
        memberCount = 0;
        for (; i < BTL_NET_PLAYER_MAX; i++) if (memberMask & (1U << i)) memberCount++;
        maxMembers = func_0203D1B4();
        if (memberCount > maxMembers) memberCount = maxMembers;
        d_021F3B88->memberCount = memberCount;
        d_021F3B88->syncStage = 0;
        d_021F3B88->syncPending = 0;
        d_021F3B88->setupReceived = 0;
        for (j = 0; j < BTL_NET_PLAYER_MAX; j++) {
            d_021F3B88->recvBuf[j] = 0;
            d_021F3B88->recvDone[j] = 0;
            d_021F3B88->clientIds[j] = BTL_NET_NO_CLIENT;
        }
        for (k = 0; k < BTL_NET_PLAYER_MAX; k++) d_021F3B88->relayBuf[k] = 0;
        d_021F3B88->tempBuf = 0;
        d_021F3B88->tempDone = 0;
        func_021D4AF4(1);
    } else d_021F3B88 = 0;
}

/* Wait for the first sync stage. Done at once when there is no exchange. */
int func_021D4230(void)
{
    int done;
    if (d_021F3B88) {
        done = 1;
        if (func_021D4B18(1) == 0) done = 0;
        return done;
    }
    return 1;
}

/* Free every buffer and the exchange block itself. */
void func_021D4254(void)
{
    if (d_021F3B88) {
        func_021D4A6C();
        func_020307B0(d_021F3B88);
    }
}

/* Nonzero when the link reports an error. Zero when there is no exchange. */
int func_021D4270(void)
{
    if (d_021F3B88) {
        if (func_0200FB24()) return 1;
        return 0;
    }
    return 0;
}

/* Send the ENTRY message: the fixed value, then the sender's client id. */
int func_021D4294(u16 clientId)
{
    u16 *message = d_021F3B88->sendScratch.halves;
    message[0] = BTL_NET_ENTRY_VALUE;
    message[1] = clientId;
    return func_0203D3A8(d_021F3B88->netHandle, BTL_NET_CMD_ENTRY, 4, (u32)message);
}

/*
 * Receive an ENTRY message from net id netId. The first one from each
 * player counts. When all players have entered, the leader is the lowest
 * net id that sent the highest value.
 */
void func_021D42BC(int netId, int unused, u16 *data)
{
    struct BtlNet *net = d_021F3B88;
    struct BtlNetEntrySync *sync = &net->entrySync;
    int i;

    if (sync->entries[netId].received == 0) {
        u16 value = data[0];
        net->clientIds[netId] = data[1];
        sync->entries[netId].value = value;
        sync->entries[netId].received = 1;
        if (sync->maxValue < value)
            sync->maxValue = value;
        sync->receivedCount++;
        if (sync->receivedCount >= d_021F3B88->memberCount) {
            d_021F3B88->leaderNetId = BTL_NET_NO_NETID;
            for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
                if (sync->entries[i].received != 0 && sync->maxValue == sync->entries[i].value) {
                    d_021F3B88->leaderNetId = i;
                    return;
                }
            }
        }
    }
}

/* Has net id netId sent its ENTRY message? */
u8 func_021D4330(int netId)
{
    return d_021F3B88->entrySync.entries[netId].received;
}

/* Is the leader known? */
int func_021D4348(void)
{
    if (d_021F3B88->leaderNetId != BTL_NET_NO_NETID)
        return 1;
    return 0;
}

/* Is this player the leader? */
int func_021D4360(void)
{
    if (d_021F3B88->leaderNetId == d_021F3B88->ownNetId)
        return 1;
    return 0;
}

/* The highest ENTRY value, or the fixed entry value when there is no exchange. */
u8 func_021D4378(void)
{
    struct BtlNet *net = d_021F3B88;

    if (net != 0)
        return net->entrySync.maxValue;
    return BTL_NET_ENTRY_VALUE;
}

/* Net id that announced client id clientId, or BTL_NET_NO_NETID. */
u8 func_021D4394(u32 clientId)
{
    int i;

    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (clientId == d_021F3B88->clientIds[i]) {
            return (u8)i;
        }
    }
    return BTL_NET_NO_NETID;
}

/* Broadcast the 32-byte battle setup (SETUP). */
u32 func_021D43B8(u32 setup)
{
    return func_0203D3F8((u32)d_021F3B88->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_SETUP, sizeof(BtlNetSetup), setup, 0, 0, 0);
}

/* Receive the SETUP block. Only the first one is kept. */
void func_021D43E0(int unused0, int unused1, BtlNetSetup *src)
{
    if (d_021F3B88->setupReceived == 0) {
        d_021F3B88->setup = *src;
        d_021F3B88->setupReceived = 1;
    }
}

/* Copy the SETUP block to dst when it has arrived. Returns whether it had. */
int func_021D440C(BtlNetSetup *dst)
{
    if (d_021F3B88->setupReceived != 0) {
        *dst = d_021F3B88->setup;
        return 1;
    }
    return 0;
}

/* Send this player's party to everyone (PARTY). */
u8 func_021D4438(u32 party)
{
    u32 size;
    size = POKE_REGULATION_GetDataSize();
    return func_0203D3F8((u32)d_021F3B88->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_PARTY, size, party, 0, 1, 1);
}

/* Give the link a buffer for the party of net id netId. */
void *func_021D446C(int netId, int unused, u32 size)
{
    d_021F3B88->recvBuf[netId] = func_02030734(BTL_NET_TAIL_HEAP(d_021F3B88->heapId), size, 1, d_021F3A98, 0x1ce);
    return d_021F3B88->recvBuf[netId];
}

/* The party of net id netId is complete in buf. */
void func_021D44B4(int netId, void *buf)
{
    d_021F3B88->recvDone[netId] = buf;
}

/* Have all players that entered delivered their party? */
int func_021D44CC(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++)
        if (func_021D4330(i) && d_021F3B88->recvDone[i] == 0) return 0;
    return 1;
}

/* Free the receive buffers and mark every reply slot as waiting. */
void func_021D4500(void)
{
    func_021D4CEC();
    func_021D4A6C();
}

/*
 * Send this player's recorded voice (PERAP_VOICE). Without a recording a
 * zero word of 4 bytes goes out instead.
 */
u32 func_021D450C(u32 *voice)
{
    u32 size;

    if (func_02007B50((void **)voice) != 0) {
        size = func_02007B00();
    } else {
        size = 4;
        voice = &d_021F3B88->sendScratch.word;
        *voice = 0;
    }
    return func_0203D3F8((u32)d_021F3B88->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_PERAP_VOICE, size, (u32)voice, 0, 1, 1);
}

/*
 * Give the link a buffer for the voice of net id netId. The 4-byte "no
 * recording" message is received into the reply slot of that net id.
 */
void *func_021D4558(int netId, int unused, u32 size)
{
    if (size == 4)
        return &d_021F3B88->replySlots[netId];
    d_021F3B88->recvBuf[netId] = func_02030734(BTL_NET_TAIL_HEAP(d_021F3B88->heapId), size, 1, d_021F3A98, 0x21f);
    return d_021F3B88->recvBuf[netId];
}

/*
 * The voice of net id netId is complete. The 4-byte message only clears
 * the waiting flag of the slot; a longer one is complete in the buffer
 * passed as doneOrSize.
 */
void func_021D45B8(int netId, int doneOrSize)
{
    if (doneOrSize == 4) {
        struct BtlNetMsgSlot *slot = &d_021F3B88->replySlots[netId];
        slot->size = doneOrSize;
        slot->waiting = 0;
    } else {
        d_021F3B88->recvDone[netId] = (void *)doneOrSize;
    }
}

/* Have all players that entered delivered their voice? */
int func_021D45FC(void)
{
    int i;

    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (func_021D4330(i) != 0 && d_021F3B88->replySlots[i].waiting != 0 && d_021F3B88->recvDone[i] == 0)
            return 0;
    }
    return 1;
}

/*
 * The voice buffer of client clientId, or 0 when none arrived.
 * Indexed struct arrays keep the scaled index loaded before the base.
 */
u32 func_021D4648(u32 clientId)
{
    u32 netId;
    netId = func_021D4394(clientId);
    if (netId != BTL_NET_NO_NETID) {
        if (d_021F3B88->recvDone[netId]) return (u32)d_021F3B88->recvBuf[netId];
    }
    return 0;
}

/* Same as the reset above, done after the voices are read. */
void func_021D4674(void)
{
    func_021D4CEC();
    func_021D4A6C();
}

/* Forward a party packet to everyone (RELAY_PARTY); the byte count is in the header. */
u32 func_021D4680(u32 *packet)
{
    return func_0203D3F8((u32)d_021F3B88->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_RELAY_PARTY, (*packet >> 8) + 4, (u32)packet, 0, 1, 1);
}

/* Give the link a buffer for a forwarded party. One is in transit at a time. */
void *func_021D46B0(int unused0, int unused1, u32 size)
{
    if (d_021F3B88->tempBuf == 0)
        d_021F3B88->tempBuf = func_02030734(BTL_NET_TAIL_HEAP(d_021F3B88->heapId), size, 1, d_021F3A98, 0x279);
    return d_021F3B88->tempBuf;
}

/*
 * Receive a forwarded party. The header gives the client id and the byte
 * count. Make sure relayBuf has a block for that client, copy the body in
 * and release the buffer in transit.
 * The header is read as bitfields through a const pointer: the byte count
 * then shares its load with the first read, and the call arguments keep
 * their order.
 */
void func_021D46FC(u32 unused0, u32 unused1, const BtlNetPacketHeader *packet)
{
    if (d_021F3B88->relayBuf[packet->h.type] == 0) {
        d_021F3B88->relayBuf[packet->h.type] = func_02030734(BTL_NET_TAIL_HEAP(d_021F3B88->heapId), packet->h.size, 1, d_021F3A98, 0x282);
    }
    MI_CpuCopy8(packet + 1, d_021F3B88->relayBuf[packet->h.type], packet->h.size);
    func_020307B0(d_021F3B88->tempBuf);
    d_021F3B88->tempBuf = 0;
}

/* Has the forwarded party of client clientId arrived? */
int func_021D4784(u32 clientId)
{
    if (d_021F3B88->relayBuf[clientId]) return 1;
    return 0;
}

/*
 * The party of client clientId: its own buffer when it is connected, else
 * the forwarded copy. The loop reads every member and drops the result.
 */
void *func_021D47A4(u8 clientId)
{
    u32 netId = func_021D4394(clientId);
    void *party;
    u32 count;
    u32 i;

    if (netId != BTL_NET_NO_NETID) {
        return d_021F3B88->recvBuf[netId];
    }
    party = d_021F3B88->relayBuf[clientId];
    if (party != 0) {
        count = func_0201AA18(party);
        for (i = 0; i < count; i++) {
            func_0201AB28(party, i);
        }
        return party;
    }
    return 0;
}

/* Free the receive buffers once the parties are used. */
void func_021D4800(void)
{
    func_021D4A6C();
}

/* Send this player's trainer record to everyone (PLAYER_INFO). */
int func_021D4808(u32 myStatus)
{
    u32 size = func_02008468();
    return func_0203D3F8((u32)d_021F3B88->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_PLAYER_INFO, size, myStatus, 0, 1, 1);
}

/* Give the link a buffer for the trainer record of net id netId. */
void *func_021D4838(int netId, int unused, u32 size)
{
    d_021F3B88->recvBuf[netId] = func_02030734(BTL_NET_TAIL_HEAP(d_021F3B88->heapId), size, 1, d_021F3A98, 0x2d4);
    return d_021F3B88->recvBuf[netId];
}

/* The trainer record of net id netId is complete in buf. */
void func_021D4880(int netId, void *buf)
{
    d_021F3B88->recvDone[netId] = buf;
}

/* Have all players that entered delivered their trainer record? */
int func_021D4898(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (func_021D4330(i) != 0 && d_021F3B88->recvDone[i] == 0)
            return 0;
    }
    return 1;
}

/*
 * The trainer record of client clientId: its own buffer when it is
 * connected, else the forwarded record when one has arrived.
 */
void *func_021D48CC(u8 clientId)
{
    int netId = func_021D4394(clientId);
    void *record;
    if (netId != BTL_NET_NO_NETID) return d_021F3B88->recvBuf[netId];
    record = d_021F3B88->tempBuf;
    if (record != 0 && d_021F3B88->tempDone != 0) return record;
    return 0;
}

/* Forward a trainer record to everyone (RELAY_PLAYER_INFO) and free the packet. */
u32 func_021D4908(void *myStatus)
{
    void *packet;
    u32 result;

    packet = (void *)func_021D4A0C((struct MyStatus *)myStatus, BTL_NET_TAIL_HEAP(d_021F3B88->heapId));
    result = func_0203D3F8((u32)d_021F3B88->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_RELAY_PLAYER_INFO, sizeof(struct BtlNetMyStatusPacket), (u32)packet, 0, 1, 0);
    func_021D4A64(packet);
    return result;
}

/*
 * Give the link a buffer for a forwarded trainer record and keep it in
 * tempBuf. The heap id is built the other way round than elsewhere, and
 * the result is read back from the field.
 */
u32 func_021D4954(void *unused0, int unused1, int size)
{
    u32 heapId = (u16)(0x8000 | (d_021F3B88->heapId & 0x7fff));
    u32 buf = (u32)func_02030734(heapId, size, 1, d_021F3A98, 0x31e);

    d_021F3B88->tempBuf = (void *)buf;
    return (u32)d_021F3B88->tempBuf;
}

/* The forwarded trainer record is complete in buf. */
void func_021D499C(int unused, void *buf)
{
    d_021F3B88->tempDone = buf;
}

/* Has a forwarded trainer record arrived? */
int func_021D49B0(void)
{
    if (d_021F3B88->tempDone)
        return 1;
    return 0;
}

/* The forwarded trainer record. */
void *func_021D49CC(void)
{
    return d_021F3B88->tempBuf;
}

/* Free the forwarded trainer record. */
void func_021D49E0(void)
{
    func_020307B0(d_021F3B88->tempBuf);
    d_021F3B88->tempBuf = 0;
    d_021F3B88->tempDone = 0;
}

/* Same as the free above for the receive buffers; the next function starts right after. */
void func_021D4A04(void)
{
    func_021D4A6C();
}

/* Copy a trainer record and its name into a new packet for sending. */
struct BtlNetMyStatusPacket *func_021D4A0C(struct MyStatus *myStatus, u32 heapId)
{
    struct BtlNetMyStatusPacket *packet = func_02030734(heapId, sizeof(struct BtlNetMyStatusPacket), 1, d_021F3A98, 0x349);

    MI_CpuCopy8(myStatus, packet, sizeof(struct MyStatus));
    MIi_CpuClear16(func_02045A98(), packet->nameChars, sizeof(packet->nameChars));
    if (myStatus->name != 0) {
        packet->nameLength = STRBUF_GetLength(myStatus->name);
        sub_0201F41C(STRBUF_GetChars(myStatus->name), packet->nameChars, 0x20);
    }
    return packet;
}

/* Free a packet made by the function above. */
void func_021D4A64(void *packet)
{
    func_020307B0(packet);
}

/* Free the per-player buffers, the forwarded buffers and the one in transit. */
void func_021D4A6C(void)
{
    int i;

    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (d_021F3B88->recvBuf[i] != 0) {
            func_020307B0(d_021F3B88->recvBuf[i]);
            d_021F3B88->recvBuf[i] = 0;
            d_021F3B88->recvDone[i] = 0;
        }
    }
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (d_021F3B88->relayBuf[i] != 0) {
            func_020307B0(d_021F3B88->relayBuf[i]);
            d_021F3B88->relayBuf[i] = 0;
        }
    }
    if (d_021F3B88->tempBuf != 0) {
        func_020307B0(d_021F3B88->tempBuf);
        d_021F3B88->tempBuf = 0;
        d_021F3B88->tempDone = 0;
    }
}

/* Announce sync stage stage in the user info of this player. */
void func_021D4AF4(int stage)
{
    if (d_021F3B88 != 0) {
        d_021F3B88->syncStage = stage;
        d_021F3B88->syncPending = 1;
        GFL_NET_HANDLE_SetUserInfo(d_021F3B88->netHandle, stage, 1, d_021F3B88->memberMask);
    }
}

/*
 * Wait until all players announced the stage. While the announcement is
 * pending, ask the link; otherwise announce stage stage now.
 * Returns nonzero when the stage is reached, and when there is no exchange.
 */
int func_021D4B18(int stage)
{
    struct BtlNet *net = d_021F3B88;
    int reached;

    if (net != 0) {
        if (net->syncPending != 0) {
            reached = func_02039CB4((struct NetHandle *)net->netHandle, net->syncStage, 1);
            if (reached != 0) {
                d_021F3B88->syncStage = 0;
                d_021F3B88->syncPending = 0;
                return reached;
            }
        } else {
            GFL_NET_HANDLE_SetUserInfo(net->netHandle, stage, 1, net->memberMask);
        }
        return 0;
    }
    return 1;
}

/* Server sends a command block to client clientId (SERVER_CMD). Nonzero on success. */
u32 func_021D4B58(u32 clientId, u32 data, u32 size)
{
    u32 netId = func_021D4394(clientId);

    if (netId != BTL_NET_NO_NETID) {
        return func_0203D3F8((u32)d_021F3B88->netHandle, netId, BTL_NET_CMD_SERVER_CMD, size, data, 0, 0, 1);
    }
    return 1;
}

/* Has every connected client delivered its reply? */
int func_021D4B98(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (func_021D4330(i) != 0 && d_021F3B88->replySlots[i].waiting != 0)
            return 0;
    }
    return 1;
}

/*
 * The reply of client clientId: its data through *data, its size returned.
 * The image reaches the size and waiting fields by subtracting from the
 * array base it already holds, which this form reproduces.
 */
u16 func_021D4BD4(int clientId, u8 **data)
{
    struct BtlNetMsgSlot *slot = &d_021F3B88->replySlots[func_021D4394(clientId)];
    *data = (u8 *)slot;
    return slot->size;
}

/* The reply slot of net id netId. */
struct BtlNetMsgSlot *func_021D4BFC(int netId)
{
    return &d_021F3B88->replySlots[netId];
}

/*
 * A reply of size bytes arrived from net id netId. The original stores
 * twice, once through a local pointer and once through the global.
 */
void func_021D4C14(int netId, u32 size)
{
    struct BtlNetMsgSlot *slot = &d_021F3B88->replySlots[netId];
    slot->size = (u16)size;
    slot->waiting = 0;
    d_021F3B88->replySlots[netId].size = (u16)size;
    d_021F3B88->replySlots[netId].waiting = 0;
}

/* Mark every reply slot as waiting (tail call). */
void func_021D4C58(u32 unused)
{
    func_021D4CEC();
}

/* Is there a server command not yet answered? */
unsigned char func_021D4C60(void)
{
    return d_021F3B88->serverCmdPending;
}

/* The server command: its data through *data, its size returned. */
u16 func_021D4C6C(u8 **data)
{
    struct BtlNetMsgSlot *slot = &d_021F3B88->serverCmdSlot;
    *data = (u8 *)slot;
    return slot->size;
}

/* A client sends its reply to the leader (CLIENT_REPLY). The command is answered once it went out. */
u32 func_021D4C84(u32 data, u32 size)
{
    struct BtlNet *net = d_021F3B88;
    u32 result;

    result = func_0203D3F8((u32)net->netHandle, net->leaderNetId, BTL_NET_CMD_CLIENT_REPLY, size, data, 0, 1, 1);
    if (result != 0) {
        net = d_021F3B88;
        net->serverCmdPending = 0;
    }
    return result;
}

/* A server command of size bytes arrived. Only taken when the last one was answered. */
void func_021D4CB8(int unused, u32 size)
{
    struct BtlNet *net = d_021F3B88;

    if (net->serverCmdPending == 0) {
        struct BtlNetMsgSlot *slot = &net->serverCmdSlot;
        slot->size = (u16)size;
        slot->waiting = 0;
        d_021F3B88->serverCmdPending = 1;
    }
}

/* The slot a server command is received into. */
struct BtlNetMsgSlot *func_021D4CE0(void)
{
    return &d_021F3B88->serverCmdSlot;
}

/*
 * Mark every reply slot as waiting with no data.
 * The slot pointer is based at the array and the size and waiting
 * offsets stay inside the iteration; the global is read once.
 */
void func_021D4CEC(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        struct BtlNetMsgSlot *slot = &d_021F3B88->replySlots[i];
        slot->size = 0;
        slot->waiting = 1;
    }
}

/* Allocate a packet for size bytes of forwarded data and write its header. */
void *func_021D4D24(u32 size, u16 heapId)
{
    BtlNetPacketHeader *header = func_02030734(heapId, size + 4, 1, d_021F3A98, 0x477);

    header->h.size = size;
    header->h.type = 4;
    return header;
}

/* Free a packet made by the function above. */
void func_021D4D5C(void *packet)
{
    func_020307B0(packet);
}

/* Set the client id in the header of a packet, then copy size bytes in behind it. */
void func_021D4D64(u32 *packet, const void *src, u32 clientId)
{
    *packet = (*packet & ~255u) | (u8)clientId;
    MI_CpuCopy8(src, packet + 1, *packet >> 8);
}
