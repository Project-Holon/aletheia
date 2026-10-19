/*
 * file:     btl_net.c
 * unit:     yes
 * function: BTL_NET_Init, BTL_NET_IsInitialSyncDone, BTL_NET_Exit, BTL_NET_HasCommError, BTL_NET_SendEntry, BTL_NET_RecvEntry, BTL_NET_HasEntry, BTL_NET_IsLeaderKnown, BTL_NET_IsLeader, BTL_NET_GetLeaderValue, BTL_NET_FindNetIdByClient, BTL_NET_SendSetup, BTL_NET_RecvSetup, BTL_NET_GetSetup, BTL_NET_SendParty, BTL_NET_AllocPartyBuf, BTL_NET_RecvPartyDone, BTL_NET_IsPartyReceived, BTL_NET_ResetAfterParty, BTL_NET_SendPerapVoice, BTL_NET_AllocPerapVoiceBuf, BTL_NET_RecvPerapVoiceDone, BTL_NET_IsPerapVoiceReceived, BTL_NET_GetPerapVoice, BTL_NET_ResetAfterPerapVoice, BTL_NET_SendRelayedParty, BTL_NET_AllocRelayedPartyBuf, BTL_NET_RecvRelayedParty, BTL_NET_IsRelayedPartyReceived, BTL_NET_GetParty, BTL_NET_FreeAfterPartyUse, BTL_NET_SendPlayerInfo, BTL_NET_AllocPlayerInfoBuf, BTL_NET_RecvPlayerInfoDone, BTL_NET_IsPlayerInfoReceived, BTL_NET_GetPlayerInfo, BTL_NET_SendRelayedPlayerInfo, BTL_NET_AllocRelayedPlayerInfoBuf, BTL_NET_RecvRelayedPlayerInfoDone, BTL_NET_IsRelayedPlayerInfoReceived, BTL_NET_GetRelayedPlayerInfo, BTL_NET_FreeRelayedPlayerInfo, BTL_NET_BuildPlayerInfoPacket, BTL_NET_FreePlayerInfoPacket, BTL_NET_FreeRecvBuffers, BTL_NET_BeginSync, BTL_NET_PollSync, BTL_NET_SendServerCmd, BTL_NET_AreAllRepliesReceived, BTL_NET_GetClientReply, BTL_NET_GetReplySlot, BTL_NET_RecvClientReply, BTL_NET_ExpectReplies, BTL_NET_HasServerCmd, BTL_NET_GetServerCmd, BTL_NET_SendClientReply, BTL_NET_RecvServerCmd, BTL_NET_GetServerCmdSlot, BTL_NET_ResetReplySlots, BTL_NET_AllocRelayPacket, BTL_NET_FreeRelayPacket, BTL_NET_FillRelayPacket
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
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   gBtlNetSourceName 0x021F3A98 data ov093 a4
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   PERAPVOICE_IsRecorded  0x02007B50  thumb
 *   PERAPVOICE_GetSize  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   WORDSET_CopyString   0x0201F41C  thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   BTL_NET_FreeAfterPlayerInfoUse  0x021D4A04  thumb
 */
#include "btl_net_types.h"

struct NetHandle;
struct StrBuf;

/*
 * Battle setup exchange over the wireless link, before the first turn.
 * Every message type is a GFL_NET command id (BTL_NET_CMD_*). One block,
 * gBtlNet, holds the state for the whole exchange.
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

/* Trainer slot of the battle setup (0x28 bytes, BattleTrainerData in btl_setup_types.h). */
struct BtlNetTrainerData {
    u32 trainerId;
    u32 trainerType;
    u32 aiFlags;
    u16 itemIds[4];
    struct StrBuf *name;
    u8 winWord[8];
    u8 loseWord[8];
};

/* A trainer slot with its name copied in, so it can be sent (BtlTrainerPacket). */
struct BtlNetTrainerPacket {
    struct BtlNetTrainerData trainer;
    u16 nameChars[0x20];
    u32 nameLength;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
struct GFLNetHandle;
extern u32 GFL_NET_GetHandleNetID(struct GFLNetHandle *handle);
extern int GFL_NET_GetNegotiationNum(void);
extern u32 GFL_HEAP_Free(void *p);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern int GFL_NET_SendToHandle(struct GFLNetHandle *handle, unsigned int command, unsigned int size, void *data);
extern u32 GFL_NET_SendData(struct GFLNetHandle *handle, unsigned int sendId, unsigned int command, unsigned int size, void *data, unsigned int sendFlags, unsigned int skipIfQueued, unsigned int queueMode);
extern int POKE_REGULATION_GetDataSize(void);
struct PerapVoice;
extern unsigned int PERAPVOICE_IsRecorded(struct PerapVoice *voice);
extern u32 PERAPVOICE_GetSize(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
struct Party;
extern u32 POKEPARTY_GetCount(struct Party *party);
struct PokemonParam;
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, unsigned int pos);
extern int MYSTATUS_GetSize(void);
extern u16 STRBUF_GetEosChar(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
struct Strbuf;
extern u16 STRBUF_GetLength(struct Strbuf *strbuf);
extern u16 *STRBUF_GetChars(struct Strbuf *strbuf);
extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);
extern void GFL_NET_HANDLE_SetUserInfo(struct GFLNetHandle *handle, int timingLow, int timingHigh, int netID);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, unsigned int timingLow, unsigned int timingHigh);

void BTL_NET_Init(void *netHandle, u16 memberMask, u16 heapId);
int BTL_NET_IsInitialSyncDone(void);
void BTL_NET_Exit(void);
int BTL_NET_HasCommError(void);
int BTL_NET_SendEntry(u16 clientId);
void BTL_NET_RecvEntry(int netId, int unused, u16 *data);
u8 BTL_NET_HasEntry(int netId);
int BTL_NET_IsLeaderKnown(void);
int BTL_NET_IsLeader(void);
u8 BTL_NET_GetLeaderValue(void);
u8 BTL_NET_FindNetIdByClient(u32 clientId);
struct BtlRuleExchange;
u32 BTL_NET_SendSetup(struct BtlRuleExchange *setup);
void BTL_NET_RecvSetup(int unused0, int unused1, BtlNetSetup *src);
int BTL_NET_GetSetup(BtlNetSetup *dst);
u8 BTL_NET_SendParty(struct Party *party);
void *BTL_NET_AllocPartyBuf(int netId, int unused, u32 size);
void BTL_NET_RecvPartyDone(int netId, void *buf);
int BTL_NET_IsPartyReceived(void);
void BTL_NET_ResetAfterParty(void);
u32 BTL_NET_SendPerapVoice(u32 *voice);
void *BTL_NET_AllocPerapVoiceBuf(int netId, int unused, u32 size);
void BTL_NET_RecvPerapVoiceDone(int netId, int doneOrSize);
int BTL_NET_IsPerapVoiceReceived(void);
u32 BTL_NET_GetPerapVoice(u32 clientId);
void BTL_NET_ResetAfterPerapVoice(void);
u32 BTL_NET_SendRelayedParty(u32 *packet);
void *BTL_NET_AllocRelayedPartyBuf(int unused0, int unused1, u32 size);
void BTL_NET_RecvRelayedParty(u32 unused0, u32 unused1, const BtlNetPacketHeader *packet);
int BTL_NET_IsRelayedPartyReceived(u32 clientId);
void *BTL_NET_GetParty(u8 clientId);
void BTL_NET_FreeAfterPartyUse(void);
int BTL_NET_SendPlayerInfo(void *myStatus);
void *BTL_NET_AllocPlayerInfoBuf(int netId, int unused, u32 size);
void BTL_NET_RecvPlayerInfoDone(int netId, void *buf);
int BTL_NET_IsPlayerInfoReceived(void);
void *BTL_NET_GetPlayerInfo(u8 clientId);
u32 BTL_NET_SendRelayedPlayerInfo(void *trainerData);
u32 BTL_NET_AllocRelayedPlayerInfoBuf(void *unused0, int unused1, int size);
void BTL_NET_RecvRelayedPlayerInfoDone(int unused, void *buf);
int BTL_NET_IsRelayedPlayerInfoReceived(void);
void *BTL_NET_GetRelayedPlayerInfo(void);
void BTL_NET_FreeRelayedPlayerInfo(void);
void BTL_NET_FreeAfterPlayerInfoUse(void);
struct BtlNetTrainerPacket *BTL_NET_BuildPlayerInfoPacket(struct BtlNetTrainerData *trainerData, u32 heapId);
void BTL_NET_FreePlayerInfoPacket(void *packet);
void BTL_NET_FreeRecvBuffers(void);
void BTL_NET_BeginSync(int stage);
int BTL_NET_PollSync(int stage);
u32 BTL_NET_SendServerCmd(u32 clientId, u32 data, u32 size);
int BTL_NET_AreAllRepliesReceived(void);
u16 BTL_NET_GetClientReply(int clientId, u8 **data);
struct BtlNetMsgSlot *BTL_NET_GetReplySlot(int netId);
void BTL_NET_RecvClientReply(int netId, u32 size);
void BTL_NET_ExpectReplies(u32 unused);
unsigned char BTL_NET_HasServerCmd(void);
u16 BTL_NET_GetServerCmd(u8 **data);
u32 BTL_NET_SendClientReply(u32 data, u32 size);
void BTL_NET_RecvServerCmd(int unused, u32 size);
struct BtlNetMsgSlot *BTL_NET_GetServerCmdSlot(void);
void BTL_NET_ResetReplySlots(void);
void *BTL_NET_AllocRelayPacket(u32 size, u16 heapId);
void BTL_NET_FreeRelayPacket(void *packet);
void BTL_NET_FillRelayPacket(u32 *packet, const void *src, u32 clientId);
extern struct BtlNet *gBtlNet;
extern const char gBtlNetSourceName[];

/*
 * Create the exchange block. Without a link there is no exchange and the
 * global stays empty. Counts the players in the mask, at most as many as
 * the link negotiated.
 * The three loops use separate counters; the zero of the first one is
 * reused for the two byte stores before the second loop.
 */
void BTL_NET_Init(void *netHandle, u16 memberMask, u16 heapId)
{
    u32 memberCount, i, j, k, maxMembers;
    if (netHandle) {
        gBtlNet = GFL_HEAP_Alloc(heapId, sizeof(struct BtlNet), 1, gBtlNetSourceName, 0xd4);
        gBtlNet->netHandle = netHandle;
        gBtlNet->memberMask = memberMask;
        gBtlNet->heapId = heapId;
        gBtlNet->ownNetId = GFL_NET_GetHandleNetID(netHandle);
        gBtlNet->leaderNetId = BTL_NET_NO_NETID;
        i = 0;
        gBtlNet->serverCmdPending = i;
        gBtlNet->reserved0E = i;
        memberCount = 0;
        for (; i < BTL_NET_PLAYER_MAX; i++) if (memberMask & (1U << i)) memberCount++;
        maxMembers = GFL_NET_GetNegotiationNum();
        if (memberCount > maxMembers) memberCount = maxMembers;
        gBtlNet->memberCount = memberCount;
        gBtlNet->syncStage = 0;
        gBtlNet->syncPending = 0;
        gBtlNet->setupReceived = 0;
        for (j = 0; j < BTL_NET_PLAYER_MAX; j++) {
            gBtlNet->recvBuf[j] = 0;
            gBtlNet->recvDone[j] = 0;
            gBtlNet->clientIds[j] = BTL_NET_NO_CLIENT;
        }
        for (k = 0; k < BTL_NET_PLAYER_MAX; k++) gBtlNet->relayBuf[k] = 0;
        gBtlNet->tempBuf = 0;
        gBtlNet->tempDone = 0;
        BTL_NET_BeginSync(1);
    } else gBtlNet = 0;
}

/* Wait for the first sync stage. Done at once when there is no exchange. */
int BTL_NET_IsInitialSyncDone(void)
{
    int done;
    if (gBtlNet) {
        done = 1;
        if (BTL_NET_PollSync(1) == 0) done = 0;
        return done;
    }
    return 1;
}

/* Free every buffer and the exchange block itself. */
void BTL_NET_Exit(void)
{
    if (gBtlNet) {
        BTL_NET_FreeRecvBuffers();
        GFL_HEAP_Free(gBtlNet);
    }
}

/* Nonzero when the link reports an error. Zero when there is no exchange. */
int BTL_NET_HasCommError(void)
{
    if (gBtlNet) {
        if (GFL_NET_ERR_GetErrorLevel()) return 1;
        return 0;
    }
    return 0;
}

/* Send the ENTRY message: the fixed value, then the sender's client id. */
int BTL_NET_SendEntry(u16 clientId)
{
    u16 *message = gBtlNet->sendScratch.halves;
    message[0] = BTL_NET_ENTRY_VALUE;
    message[1] = clientId;
    return GFL_NET_SendToHandle(gBtlNet->netHandle, BTL_NET_CMD_ENTRY, 4, message);
}

/*
 * Receive an ENTRY message from net id netId. The first one from each
 * player counts. When all players have entered, the leader is the lowest
 * net id that sent the highest value.
 */
void BTL_NET_RecvEntry(int netId, int unused, u16 *data)
{
    struct BtlNet *net = gBtlNet;
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
        if (sync->receivedCount >= gBtlNet->memberCount) {
            gBtlNet->leaderNetId = BTL_NET_NO_NETID;
            for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
                if (sync->entries[i].received != 0 && sync->maxValue == sync->entries[i].value) {
                    gBtlNet->leaderNetId = i;
                    return;
                }
            }
        }
    }
}

/* Has net id netId sent its ENTRY message? */
u8 BTL_NET_HasEntry(int netId)
{
    return gBtlNet->entrySync.entries[netId].received;
}

/* Is the leader known? */
int BTL_NET_IsLeaderKnown(void)
{
    if (gBtlNet->leaderNetId != BTL_NET_NO_NETID)
        return 1;
    return 0;
}

/* Is this player the leader? */
int BTL_NET_IsLeader(void)
{
    if (gBtlNet->leaderNetId == gBtlNet->ownNetId)
        return 1;
    return 0;
}

/* The highest ENTRY value, or the fixed entry value when there is no exchange. */
u8 BTL_NET_GetLeaderValue(void)
{
    struct BtlNet *net = gBtlNet;

    if (net != 0)
        return net->entrySync.maxValue;
    return BTL_NET_ENTRY_VALUE;
}

/* Net id that announced client id clientId, or BTL_NET_NO_NETID. */
u8 BTL_NET_FindNetIdByClient(u32 clientId)
{
    int i;

    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (clientId == gBtlNet->clientIds[i]) {
            return (u8)i;
        }
    }
    return BTL_NET_NO_NETID;
}

/* Broadcast the 32-byte battle setup (SETUP). */
u32 BTL_NET_SendSetup(struct BtlRuleExchange *setup)
{
    return GFL_NET_SendData(gBtlNet->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_SETUP, sizeof(BtlNetSetup), (void *)setup, 0, 0, 0);
}

/* Receive the SETUP block. Only the first one is kept. */
void BTL_NET_RecvSetup(int unused0, int unused1, BtlNetSetup *src)
{
    if (gBtlNet->setupReceived == 0) {
        gBtlNet->setup = *src;
        gBtlNet->setupReceived = 1;
    }
}

/* Copy the SETUP block to dst when it has arrived. Returns whether it had. */
int BTL_NET_GetSetup(BtlNetSetup *dst)
{
    if (gBtlNet->setupReceived != 0) {
        *dst = gBtlNet->setup;
        return 1;
    }
    return 0;
}

/* Send this player's party to everyone (PARTY). */
u8 BTL_NET_SendParty(struct Party *party)
{
    u32 size;
    size = POKE_REGULATION_GetDataSize();
    return GFL_NET_SendData(gBtlNet->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_PARTY, size, (void *)party, 0, 1, 1);
}

/* Give the link a buffer for the party of net id netId. */
void *BTL_NET_AllocPartyBuf(int netId, int unused, u32 size)
{
    gBtlNet->recvBuf[netId] = GFL_HEAP_Alloc(BTL_NET_TAIL_HEAP(gBtlNet->heapId), size, 1, gBtlNetSourceName, 0x1ce);
    return gBtlNet->recvBuf[netId];
}

/* The party of net id netId is complete in buf. */
void BTL_NET_RecvPartyDone(int netId, void *buf)
{
    gBtlNet->recvDone[netId] = buf;
}

/* Have all players that entered delivered their party? */
int BTL_NET_IsPartyReceived(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++)
        if (BTL_NET_HasEntry(i) && gBtlNet->recvDone[i] == 0) return 0;
    return 1;
}

/* Free the receive buffers and mark every reply slot as waiting. */
void BTL_NET_ResetAfterParty(void)
{
    BTL_NET_ResetReplySlots();
    BTL_NET_FreeRecvBuffers();
}

/*
 * Send this player's recorded voice (PERAP_VOICE). Without a recording a
 * zero word of 4 bytes goes out instead.
 */
u32 BTL_NET_SendPerapVoice(u32 *voice)
{
    u32 size;

    if (PERAPVOICE_IsRecorded((struct PerapVoice *)voice) != 0) {
        size = PERAPVOICE_GetSize();
    } else {
        size = 4;
        voice = &gBtlNet->sendScratch.word;
        *voice = 0;
    }
    return GFL_NET_SendData(gBtlNet->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_PERAP_VOICE, size, voice, 0, 1, 1);
}

/*
 * Give the link a buffer for the voice of net id netId. The 4-byte "no
 * recording" message is received into the reply slot of that net id.
 */
void *BTL_NET_AllocPerapVoiceBuf(int netId, int unused, u32 size)
{
    if (size == 4)
        return &gBtlNet->replySlots[netId];
    gBtlNet->recvBuf[netId] = GFL_HEAP_Alloc(BTL_NET_TAIL_HEAP(gBtlNet->heapId), size, 1, gBtlNetSourceName, 0x21f);
    return gBtlNet->recvBuf[netId];
}

/*
 * The voice of net id netId is complete. The 4-byte message only clears
 * the waiting flag of the slot; a longer one is complete in the buffer
 * passed as doneOrSize.
 */
void BTL_NET_RecvPerapVoiceDone(int netId, int doneOrSize)
{
    if (doneOrSize == 4) {
        struct BtlNetMsgSlot *slot = &gBtlNet->replySlots[netId];
        slot->size = doneOrSize;
        slot->waiting = 0;
    } else {
        gBtlNet->recvDone[netId] = (void *)doneOrSize;
    }
}

/* Have all players that entered delivered their voice? */
int BTL_NET_IsPerapVoiceReceived(void)
{
    int i;

    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (BTL_NET_HasEntry(i) != 0 && gBtlNet->replySlots[i].waiting != 0 && gBtlNet->recvDone[i] == 0)
            return 0;
    }
    return 1;
}

/*
 * The voice buffer of client clientId, or 0 when none arrived.
 * Indexed struct arrays keep the scaled index loaded before the base.
 */
u32 BTL_NET_GetPerapVoice(u32 clientId)
{
    u32 netId;
    netId = BTL_NET_FindNetIdByClient(clientId);
    if (netId != BTL_NET_NO_NETID) {
        if (gBtlNet->recvDone[netId]) return (u32)gBtlNet->recvBuf[netId];
    }
    return 0;
}

/* Same as the reset above, done after the voices are read. */
void BTL_NET_ResetAfterPerapVoice(void)
{
    BTL_NET_ResetReplySlots();
    BTL_NET_FreeRecvBuffers();
}

/* Forward a party packet to everyone (RELAY_PARTY); the byte count is in the header. */
u32 BTL_NET_SendRelayedParty(u32 *packet)
{
    return GFL_NET_SendData(gBtlNet->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_RELAY_PARTY, (*packet >> 8) + 4, packet, 0, 1, 1);
}

/* Give the link a buffer for a forwarded party. One is in transit at a time. */
void *BTL_NET_AllocRelayedPartyBuf(int unused0, int unused1, u32 size)
{
    if (gBtlNet->tempBuf == 0)
        gBtlNet->tempBuf = GFL_HEAP_Alloc(BTL_NET_TAIL_HEAP(gBtlNet->heapId), size, 1, gBtlNetSourceName, 0x279);
    return gBtlNet->tempBuf;
}

/*
 * Receive a forwarded party. The header gives the client id and the byte
 * count. Make sure relayBuf has a block for that client, copy the body in
 * and release the buffer in transit.
 * The header is read as bitfields through a const pointer: the byte count
 * then shares its load with the first read, and the call arguments keep
 * their order.
 */
void BTL_NET_RecvRelayedParty(u32 unused0, u32 unused1, const BtlNetPacketHeader *packet)
{
    if (gBtlNet->relayBuf[packet->h.type] == 0) {
        gBtlNet->relayBuf[packet->h.type] = GFL_HEAP_Alloc(BTL_NET_TAIL_HEAP(gBtlNet->heapId), packet->h.size, 1, gBtlNetSourceName, 0x282);
    }
    MI_CpuCopy8(packet + 1, gBtlNet->relayBuf[packet->h.type], packet->h.size);
    GFL_HEAP_Free(gBtlNet->tempBuf);
    gBtlNet->tempBuf = 0;
}

/* Has the forwarded party of client clientId arrived? */
int BTL_NET_IsRelayedPartyReceived(u32 clientId)
{
    if (gBtlNet->relayBuf[clientId]) return 1;
    return 0;
}

/*
 * The party of client clientId: its own buffer when it is connected, else
 * the forwarded copy. The loop reads every member and drops the result.
 */
void *BTL_NET_GetParty(u8 clientId)
{
    u32 netId = BTL_NET_FindNetIdByClient(clientId);
    void *party;
    u32 count;
    u32 i;

    if (netId != BTL_NET_NO_NETID) {
        return gBtlNet->recvBuf[netId];
    }
    party = gBtlNet->relayBuf[clientId];
    if (party != 0) {
        count = POKEPARTY_GetCount(party);
        for (i = 0; i < count; i++) {
            POKEPARTY_GetMember(party, i);
        }
        return party;
    }
    return 0;
}

/* Free the receive buffers once the parties are used. */
void BTL_NET_FreeAfterPartyUse(void)
{
    BTL_NET_FreeRecvBuffers();
}

/* Send this player's trainer record to everyone (PLAYER_INFO). */
int BTL_NET_SendPlayerInfo(void *myStatus)
{
    u32 size = MYSTATUS_GetSize();
    return GFL_NET_SendData(gBtlNet->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_PLAYER_INFO, size, (void *)myStatus, 0, 1, 1);
}

/* Give the link a buffer for the trainer record of net id netId. */
void *BTL_NET_AllocPlayerInfoBuf(int netId, int unused, u32 size)
{
    gBtlNet->recvBuf[netId] = GFL_HEAP_Alloc(BTL_NET_TAIL_HEAP(gBtlNet->heapId), size, 1, gBtlNetSourceName, 0x2d4);
    return gBtlNet->recvBuf[netId];
}

/* The trainer record of net id netId is complete in buf. */
void BTL_NET_RecvPlayerInfoDone(int netId, void *buf)
{
    gBtlNet->recvDone[netId] = buf;
}

/* Have all players that entered delivered their trainer record? */
int BTL_NET_IsPlayerInfoReceived(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (BTL_NET_HasEntry(i) != 0 && gBtlNet->recvDone[i] == 0)
            return 0;
    }
    return 1;
}

/*
 * The trainer record of client clientId: its own buffer when it is
 * connected, else the forwarded record when one has arrived.
 */
void *BTL_NET_GetPlayerInfo(u8 clientId)
{
    int netId = BTL_NET_FindNetIdByClient(clientId);
    void *record;
    if (netId != BTL_NET_NO_NETID) return gBtlNet->recvBuf[netId];
    record = gBtlNet->tempBuf;
    if (record != 0 && gBtlNet->tempDone != 0) return record;
    return 0;
}

/* Forward a trainer record to everyone (RELAY_PLAYER_INFO) and free the packet. */
u32 BTL_NET_SendRelayedPlayerInfo(void *trainerData)
{
    void *packet;
    u32 result;

    packet = (void *)BTL_NET_BuildPlayerInfoPacket((struct BtlNetTrainerData *)trainerData, BTL_NET_TAIL_HEAP(gBtlNet->heapId));
    result = GFL_NET_SendData(gBtlNet->netHandle, BTL_NET_SEND_ALL, BTL_NET_CMD_RELAY_PLAYER_INFO, sizeof(struct BtlNetTrainerPacket), packet, 0, 1, 0);
    BTL_NET_FreePlayerInfoPacket(packet);
    return result;
}

/*
 * Give the link a buffer for a forwarded trainer record and keep it in
 * tempBuf. The heap id is built the other way round than elsewhere, and
 * the result is read back from the field.
 */
u32 BTL_NET_AllocRelayedPlayerInfoBuf(void *unused0, int unused1, int size)
{
    u32 heapId = (u16)(0x8000 | (gBtlNet->heapId & 0x7fff));
    u32 buf = (u32)GFL_HEAP_Alloc(heapId, size, 1, gBtlNetSourceName, 0x31e);

    gBtlNet->tempBuf = (void *)buf;
    return (u32)gBtlNet->tempBuf;
}

/* The forwarded trainer record is complete in buf. */
void BTL_NET_RecvRelayedPlayerInfoDone(int unused, void *buf)
{
    gBtlNet->tempDone = buf;
}

/* Has a forwarded trainer record arrived? */
int BTL_NET_IsRelayedPlayerInfoReceived(void)
{
    if (gBtlNet->tempDone)
        return 1;
    return 0;
}

/* The forwarded trainer record. */
void *BTL_NET_GetRelayedPlayerInfo(void)
{
    return gBtlNet->tempBuf;
}

/* Free the forwarded trainer record. */
void BTL_NET_FreeRelayedPlayerInfo(void)
{
    GFL_HEAP_Free(gBtlNet->tempBuf);
    gBtlNet->tempBuf = 0;
    gBtlNet->tempDone = 0;
}

/* Same as the free above for the receive buffers; the next function starts right after. */
void BTL_NET_FreeAfterPlayerInfoUse(void)
{
    BTL_NET_FreeRecvBuffers();
}

/* Copy a trainer record and its name into a new packet for sending. */
struct BtlNetTrainerPacket *BTL_NET_BuildPlayerInfoPacket(struct BtlNetTrainerData *trainerData, u32 heapId)
{
    struct BtlNetTrainerPacket *packet = GFL_HEAP_Alloc(heapId, sizeof(struct BtlNetTrainerPacket), 1, gBtlNetSourceName, 0x349);

    MI_CpuCopy8(trainerData, packet, sizeof(struct BtlNetTrainerData));
    MIi_CpuClear16(STRBUF_GetEosChar(), packet->nameChars, sizeof(packet->nameChars));
    if (trainerData->name != 0) {
        packet->nameLength = STRBUF_GetLength((struct Strbuf *)trainerData->name);
        WORDSET_CopyString(STRBUF_GetChars((struct Strbuf *)trainerData->name), packet->nameChars, 0x20);
    }
    return packet;
}

/* Free a packet made by the function above. */
void BTL_NET_FreePlayerInfoPacket(void *packet)
{
    GFL_HEAP_Free(packet);
}

/* Free the per-player buffers, the forwarded buffers and the one in transit. */
void BTL_NET_FreeRecvBuffers(void)
{
    int i;

    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (gBtlNet->recvBuf[i] != 0) {
            GFL_HEAP_Free(gBtlNet->recvBuf[i]);
            gBtlNet->recvBuf[i] = 0;
            gBtlNet->recvDone[i] = 0;
        }
    }
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (gBtlNet->relayBuf[i] != 0) {
            GFL_HEAP_Free(gBtlNet->relayBuf[i]);
            gBtlNet->relayBuf[i] = 0;
        }
    }
    if (gBtlNet->tempBuf != 0) {
        GFL_HEAP_Free(gBtlNet->tempBuf);
        gBtlNet->tempBuf = 0;
        gBtlNet->tempDone = 0;
    }
}

/* Announce sync stage stage in the user info of this player. */
void BTL_NET_BeginSync(int stage)
{
    if (gBtlNet != 0) {
        gBtlNet->syncStage = stage;
        gBtlNet->syncPending = 1;
        GFL_NET_HANDLE_SetUserInfo(gBtlNet->netHandle, stage, 1, gBtlNet->memberMask);
    }
}

/*
 * Wait until all players announced the stage. While the announcement is
 * pending, ask the link; otherwise announce stage stage now.
 * Returns nonzero when the stage is reached, and when there is no exchange.
 */
int BTL_NET_PollSync(int stage)
{
    struct BtlNet *net = gBtlNet;
    int reached;

    if (net != 0) {
        if (net->syncPending != 0) {
            reached = GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)net->netHandle, net->syncStage, 1);
            if (reached != 0) {
                gBtlNet->syncStage = 0;
                gBtlNet->syncPending = 0;
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
u32 BTL_NET_SendServerCmd(u32 clientId, u32 data, u32 size)
{
    u32 netId = BTL_NET_FindNetIdByClient(clientId);

    if (netId != BTL_NET_NO_NETID) {
        return GFL_NET_SendData(gBtlNet->netHandle, netId, BTL_NET_CMD_SERVER_CMD, size, (void *)data, 0, 0, 1);
    }
    return 1;
}

/* Has every connected client delivered its reply? */
int BTL_NET_AreAllRepliesReceived(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        if (BTL_NET_HasEntry(i) != 0 && gBtlNet->replySlots[i].waiting != 0)
            return 0;
    }
    return 1;
}

/*
 * The reply of client clientId: its data through *data, its size returned.
 * The image reaches the size and waiting fields by subtracting from the
 * array base it already holds, which this form reproduces.
 */
u16 BTL_NET_GetClientReply(int clientId, u8 **data)
{
    struct BtlNetMsgSlot *slot = &gBtlNet->replySlots[BTL_NET_FindNetIdByClient(clientId)];
    *data = (u8 *)slot;
    return slot->size;
}

/* The reply slot of net id netId. */
struct BtlNetMsgSlot *BTL_NET_GetReplySlot(int netId)
{
    return &gBtlNet->replySlots[netId];
}

/*
 * A reply of size bytes arrived from net id netId. The original stores
 * twice, once through a local pointer and once through the global.
 */
void BTL_NET_RecvClientReply(int netId, u32 size)
{
    struct BtlNetMsgSlot *slot = &gBtlNet->replySlots[netId];
    slot->size = (u16)size;
    slot->waiting = 0;
    gBtlNet->replySlots[netId].size = (u16)size;
    gBtlNet->replySlots[netId].waiting = 0;
}

/* Mark every reply slot as waiting (tail call). */
void BTL_NET_ExpectReplies(u32 unused)
{
    BTL_NET_ResetReplySlots();
}

/* Is there a server command not yet answered? */
unsigned char BTL_NET_HasServerCmd(void)
{
    return gBtlNet->serverCmdPending;
}

/* The server command: its data through *data, its size returned. */
u16 BTL_NET_GetServerCmd(u8 **data)
{
    struct BtlNetMsgSlot *slot = &gBtlNet->serverCmdSlot;
    *data = (u8 *)slot;
    return slot->size;
}

/* A client sends its reply to the leader (CLIENT_REPLY). The command is answered once it went out. */
u32 BTL_NET_SendClientReply(u32 data, u32 size)
{
    struct BtlNet *net = gBtlNet;
    u32 result;

    result = GFL_NET_SendData(net->netHandle, net->leaderNetId, BTL_NET_CMD_CLIENT_REPLY, size, (void *)data, 0, 1, 1);
    if (result != 0) {
        net = gBtlNet;
        net->serverCmdPending = 0;
    }
    return result;
}

/* A server command of size bytes arrived. Only taken when the last one was answered. */
void BTL_NET_RecvServerCmd(int unused, u32 size)
{
    struct BtlNet *net = gBtlNet;

    if (net->serverCmdPending == 0) {
        struct BtlNetMsgSlot *slot = &net->serverCmdSlot;
        slot->size = (u16)size;
        slot->waiting = 0;
        gBtlNet->serverCmdPending = 1;
    }
}

/* The slot a server command is received into. */
struct BtlNetMsgSlot *BTL_NET_GetServerCmdSlot(void)
{
    return &gBtlNet->serverCmdSlot;
}

/*
 * Mark every reply slot as waiting with no data.
 * The slot pointer is based at the array and the size and waiting
 * offsets stay inside the iteration; the global is read once.
 */
void BTL_NET_ResetReplySlots(void)
{
    int i;
    for (i = 0; i < BTL_NET_PLAYER_MAX; i++) {
        struct BtlNetMsgSlot *slot = &gBtlNet->replySlots[i];
        slot->size = 0;
        slot->waiting = 1;
    }
}

/* Allocate a packet for size bytes of forwarded data and write its header. */
void *BTL_NET_AllocRelayPacket(u32 size, u16 heapId)
{
    BtlNetPacketHeader *header = GFL_HEAP_Alloc(heapId, size + 4, 1, gBtlNetSourceName, 0x477);

    header->h.size = size;
    header->h.type = 4;
    return header;
}

/* Free a packet made by the function above. */
void BTL_NET_FreeRelayPacket(void *packet)
{
    GFL_HEAP_Free(packet);
}

/* Set the client id in the header of a packet, then copy size bytes in behind it. */
void BTL_NET_FillRelayPacket(u32 *packet, const void *src, u32 clientId)
{
    *packet = (*packet & ~255u) | (u8)clientId;
    MI_CpuCopy8(src, packet + 1, *packet >> 8);
}
