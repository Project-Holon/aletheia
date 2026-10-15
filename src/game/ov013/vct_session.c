/*
 * file:     vct_session.c
 * unit:     yes
 * function: VCT_SESSION_CheckAnnounceTimeout, VCT_SESSION_HandlePacket, VCT_SESSION_AllocPeer, VCT_SESSION_SendCommand, VCT_SESSION_SendReply, VCT_SESSION_FillAnnounceFields, VCT_SESSION_BroadcastPacket, VCT_SESSION_BroadcastState, VCT_SESSION_InitPeer, VCT_SESSION_SendPacket, VCT_SESSION_GetEventCode, VCT_SESSION_InitPacketHeader, VCT_SESSION_AdvancePhase, VCT_SESSION_HasNoOtherTalker, VCT_SESSION_CheckCommandAllowed, VCT_SESSION_FindPeer, VCT_SESSION_HandlePairedPacket, VCT_SESSION_HandleSharedPacket, VCT_SESSION_HandleUnknownProtocolPacket, VCT_SESSION_HandleAnnounce, VCT_POOL_InitFrames, VCT_POOL_Reset, VCT_POOL_AllocFrame, VCT_POOL_FreeFrame
 * address:  0x021B23E0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctGroup  0x021B4BD0  data  ov013  a4
 *   gVctAnnounceTimeout  0x021B3C48  data  ov013  a4
 *   gVctPeerPool  0x021B4BE0  data  a4
 *   func_020870D0  0x020870D0  arm
 *   VCT_SESSION_BuildGroupCommand  0x021B2010  arm  ov013
 *   VCT_SESSION_BuildPeerReply  0x021B20D4  arm  ov013
 *   DWC_SendReliable  0x02176E90  arm  ov009
 *   MSL_C_LIB_MemsetPtr 0x020923B0 arm
 *   gVctGroupEventCodes  0x021B3AF0  data  ov013  a1
 *   gVctPeerEventCodes  0x021B3AF5  data  ov013  a1
 *   gVctHostPhaseTable  0x021B3BC8  data  ov013  a1
 *   gVctClientPhaseTable  0x021B3AFC  data  ov013  a1
 *   gVctHostAllowTable 0x021B3B40 data ov013 a1
 *   gVctClientAllowTable 0x021B3B84 data ov013 a1
 *   VCT_SESSION_FreePeerRecord  0x021B1F54  arm  ov013
 *   gVoiceFramePool 0x021B4C24 data a4
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */
#include "vct_types.h"

extern u64 func_020870D0(void);
extern int DWC_SendReliable(int peerId, VctPacket *packet, int length);
extern void *MSL_C_LIB_MemsetPtr(void *, int, unsigned int);
extern void MIi_CpuClearFast(int, void *, u32);
extern int VCT_SESSION_FreePeerRecord(VctPeer *peer);
extern int VCT_SESSION_BuildGroupCommand(void *a, unsigned int b, unsigned char *buf, unsigned int c);
extern int VCT_SESSION_BuildPeerReply(VctPeer *peer, unsigned int command, unsigned char *buf, unsigned int length);
typedef u32 OSIntrMode;
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
void VCT_SESSION_CheckAnnounceTimeout(void);
int VCT_SESSION_HandlePacket(int senderId, VctPacket *packet, int length, VctEvent *event);
VctPeer *VCT_SESSION_AllocPeer(unsigned int peerId);
int VCT_SESSION_SendCommand(int peer, int command);
int VCT_SESSION_SendReply(int peer, int command);
void VCT_SESSION_FillAnnounceFields(VctPeer *peer, VctPacket *packet);
int VCT_SESSION_BroadcastPacket(VctPeer *peer, VctPacket *packet);
void VCT_SESSION_BroadcastState(int flag);
void VCT_SESSION_InitPeer(VctPeer *peer, unsigned int peerId);
int VCT_SESSION_SendPacket(VctPeer *peer, VctPacket *packet);
int VCT_SESSION_GetEventCode(VctPacket *packet, VctPeer *peer);
int VCT_SESSION_InitPacketHeader(VctPeer *peer, VctPacket *packet, int command);
int VCT_SESSION_AdvancePhase(VctPeer *peer, VctPacket *packet);
int VCT_SESSION_HasNoOtherTalker(VctPeer *peer);
int VCT_SESSION_CheckCommandAllowed(VctPeer *peer, const VctPacket *packet);
VctPeer *VCT_SESSION_FindPeer(int peerId);
int VCT_SESSION_HandlePairedPacket(VctPacket *packet, VctEvent *event);
int VCT_SESSION_HandleSharedPacket(VctPacket *packet, VctEvent *event);
int VCT_SESSION_HandleUnknownProtocolPacket(VctPacket *packet, VctEvent *event);
int VCT_SESSION_HandleAnnounce(VctPacket *packet, VctEvent *event);
int VCT_POOL_InitFrames(VctRxPacket *buffer, u32 size);
void VCT_POOL_Reset(void);
VctRxPacket *VCT_POOL_AllocFrame(void);
void VCT_POOL_FreeFrame(VctRxPacket *frame);
extern VctGroup gVctGroup;
extern u64 gVctAnnounceTimeout;
extern u8 gVctGroupEventCodes[];
extern u8 gVctPeerEventCodes[];
extern s8 gVctHostPhaseTable[][11];
extern s8 gVctClientPhaseTable[][11];
extern s8 gVctHostAllowTable[], gVctClientAllowTable[];



/* Client mode: if the host announced a session and stays silent past the timeout, close it and tell the game. */
void VCT_SESSION_CheckAnnounceTimeout(void)
{
    u64 now;

    now = func_020870D0();
    if (gVctSession.mode != 2)
        return;
    if (gVctSession.sharedSession == 0)
        return;
    if (gVctGroup.announceTick == 0)
        return;
    if (now - gVctGroup.announceTick <= gVctAnnounceTimeout)
        return;
    gVctGroup.announceTick = 0;
    gVctPeerPool.active.mode = 0;
    gVctPeerPool.active.phase = 0;
    VCT_SESSION_BroadcastState(0);
    gVctSession.eventCallback(gVctPeerPool.active.peerId, 9, &gVctPeerPool.active, gVctSession.callbackArg);
}


/* Entry point for a received control packet. Returns 1 when event is filled in. */
int VCT_SESSION_HandlePacket(int senderId, VctPacket *packet, int length, VctEvent *event)
{
    if (length != 0x10)
        return 0;
    if (packet->srcId != senderId || packet->dstId != gVctSession.localId)
        return 0;
    if (packet->protocol != 0x10)
        return VCT_SESSION_HandleUnknownProtocolPacket(packet, event);
    if (gVctSession.sharedSession == 0)
        return VCT_SESSION_HandlePairedPacket(packet, event);
    return VCT_SESSION_HandleSharedPacket(packet, event);
}


/* Take a peer record from the free list and put it on the active list. Fails for ids above 31 and the local id. */
VctPeer *VCT_SESSION_AllocPeer(unsigned int peerId)
{
    VctPeer *peer;

    if (peerId >= 0x20)
        return 0;
    if (peerId == gVctSession.localId)
        return 0;
    peer = gVctPeerPool.freePeers;
    if (peer == 0)
        return 0;
    gVctPeerPool.freePeers = peer->next;
    VCT_SESSION_InitPeer(peer, peerId);
    peer->next = gVctPeerPool.activeHead;
    gVctPeerPool.activeHead = peer;
    return peer;
}


/* Build a command packet for a peer, send it, return -4 when the send fails. */
int VCT_SESSION_SendCommand(int peer, int command)
{
    u8 packet[16];
    int result;

    result = VCT_SESSION_BuildGroupCommand((void *)peer, command, packet, 16);
    if (result != 0)
        return result;
    if (VCT_SESSION_SendPacket((VctPeer *)peer, (VctPacket *)packet) != 0)
        return 0;
    return -4;
}


/* Same as above for a reply to a peer record. */
int VCT_SESSION_SendReply(int peer, int command)
{
    u8 packet[16];
    int result;

    result = VCT_SESSION_BuildPeerReply((VctPeer *)peer, command, packet, 16);
    if (result != 0)
        return result;
    if (VCT_SESSION_SendPacket((VctPeer *)peer, (VctPacket *)packet) != 0)
        return 0;
    return -4;
}


/* An announcement (flag 1) carries the floor holder and the member mask. */
void VCT_SESSION_FillAnnounceFields(VctPeer *peer, VctPacket *packet)
{
    if (packet->flag == 1) {
        packet->floorHolderId = peer->peerId;
        packet->memberMask = gVctGroup.peerMask;
    }
}


/* Send the packet to every group member except the local one. Returns -4 when no send worked. */
int VCT_SESSION_BroadcastPacket(VctPeer *peer, VctPacket *packet)
{
    int sent;
    u8 id;

    sent = 0;
    VCT_SESSION_FillAnnounceFields(peer, packet);
    for (id = 0; id < 0x20; id++) {
        unsigned int bit = (id != 0) ? (1 << id) : 1;
        if ((gVctGroup.peerMask & bit) != 0 && id != gVctSession.localId) {
            packet->dstId = id;
            if (DWC_SendReliable(id, packet, 0x10) != 0)
                sent++;
        }
    }
    if (packet->flag == 1)
        peer->memberMask = gVctGroup.peerMask;
    else if (packet->flag == 0)
        peer->memberMask = 0;
    return sent == 0 ? -4 : 0;
}


/* Broadcast the session state: flag 1 announces the session, 0 closes it. */
void VCT_SESSION_BroadcastState(int flag)
{
    u8 buffer[16];

    ((VctPacket *)buffer)->kind = 0xff;
    VCT_SESSION_InitPacketHeader(&gVctPeerPool.active, (VctPacket *)buffer, 4);
    ((VctPacket *)buffer)->flag = flag;
    VCT_SESSION_BroadcastPacket(&gVctPeerPool.active, (VctPacket *)buffer);
}


/* Clear a peer record and bind it to a peer id. */
void VCT_SESSION_InitPeer(VctPeer *peer, unsigned int peerId)
{
    MSL_C_LIB_MemsetPtr(peer, 0, 24);
    peer->mode = gVctSession.mode;
    peer->phase = 0;
    peer->peerId = peerId;
}


/* Send a control packet: group packets with command 4 go to all members, others to the peer. Returns 1 on success. */
int VCT_SESSION_SendPacket(VctPeer *peer, VctPacket *packet)
{
    if (packet->kind == 0xff && packet->command == 4) {
        VCT_SESSION_BroadcastPacket(peer, packet);
    } else if (DWC_SendReliable(peer->peerId, packet, 0x10) == 0) {
        return 0;
    }
    return 1;
}


/* Map a received packet to the event code for the game and update the peer. */
int VCT_SESSION_GetEventCode(VctPacket *packet, VctPeer *peer)
{
    peer->floorHolderId = packet->floorHolderId;
    if (packet->kind == 0xff) {
        if (packet->command == 0) {
            peer->memberMask = (peer->peerId != 0) ? (1 << peer->peerId) : 1;
        }
        return gVctGroupEventCodes[packet->command];
    }
    if (packet->kind == 0) {
        if (packet->command == 0) {
            if (peer->phase == 1) {
                peer->memberMask = (peer->peerId != 0) ? (1 << peer->peerId) : 1;
                return 7;
            }
            if (peer->phase == 5)
                return 9;
            return 12;
        }
        return gVctPeerEventCodes[packet->command];
    }
    return 12;
}


/*
 * lever: Returning zero keeps the clearing value in r0 and frees r2 for byte loads.
 */
int VCT_SESSION_InitPacketHeader(VctPeer *peer, VctPacket *packet, int command)
{
    packet->magic = 0x5f564354;
    packet->protocol = 0x10;
    packet->command = command;
    packet->srcId = gVctSession.localId;
    packet->dstId = peer->peerId;
    packet->flag = 0;
    packet->floorHolderId = gVctSession.localId;
    packet->memberMask = 0;
    return 0;
}


/* Look up the next phase of the peer for this packet. -2 and -3 close the link and send a reply. */
int VCT_SESSION_AdvancePhase(VctPeer *peer, VctPacket *packet)
{
    int column;
    int next;

    column = packet->command;
    if (packet->kind == 0)
        column += 5;
    if ((unsigned int)column >= 0xb)
        column = -1;
    if (column < 0)
        return -1;
    if (gVctSession.mode == 1)
        next = gVctHostPhaseTable[peer->phase][column];
    else
        next = gVctClientPhaseTable[peer->phase][column];
    switch (next) {
    case -1:
        return next;
    case -2:
        VCT_SESSION_SendReply((int)peer, 1);
        peer->phase = 0;
        peer->mode = 0;
        return next;
    case -3:
        VCT_SESSION_SendReply((int)peer, 3);
        peer->phase = 0;
        peer->mode = 0;
        return next;
    default:
        return next;
    }
}


/* Returns 1 when no other peer than the given one is in phase 2. */
int VCT_SESSION_HasNoOtherTalker(VctPeer *peer)
{
    VctPeer *cur;

    cur = gVctPeerPool.activeHead;
    while (cur) {
        if (cur->mode != 0 && cur->phase == 2) {
            if (peer != cur)
                return 0;
        }
        cur = cur->next;
    }
    return 1;
}


static inline s8 lookup(u32 table, int row, u32 column) { return *(s8 *)(row * 11 + table + column); }


/*
 * lever: Calling the indexed inline in each table-selection arm restores the MLA register and independent -1/-2 constants.
 * checks: Per-arm inline lookup is EXACT; one data table in each arm preserves the original dispatch.
 */
/* Check whether a command is allowed in the peer phase; moves the peer to the next phase. Returns 0 when refused. */
int VCT_SESSION_CheckCommandAllowed(VctPeer *peer, const VctPacket *packet)
{
    u32 column;
    int next;
    column = packet->command;
    if (packet->kind == 0)
        column += 5;
    if (column >= 11)
        column = -1;
    if ((int)column < 0)
        return -1;
    if (gVctSession.mode == 1)
        next = lookup((u32)gVctHostAllowTable, peer->phase, column);
    else
        next = lookup((u32)gVctClientAllowTable, peer->phase, column);
    if (next == -1)
        return 1;
    if (next == -2)
        return 0;
    peer->phase = next;
    return 1;
}


/* Find the record of a peer in use. */
VctPeer *VCT_SESSION_FindPeer(int peerId)
{
    VctPeer *peer;

    peer = gVctPeerPool.activeHead;
    if (gVctSession.mode == 2) {
        if (gVctPeerPool.active.mode != 0 && gVctPeerPool.active.peerId == peerId)
            return &gVctPeerPool.active;
        return 0;
    }
    while (peer) {
        if (peer->mode != 0 && peer->peerId == peerId)
            return peer;
        peer = peer->next;
    }
    return 0;
}


/* Packet handler when each pair of peers has its own link (sharedSession 0). */
int VCT_SESSION_HandlePairedPacket(VctPacket *packet, VctEvent *event)
{
    VctPeer *peer;
    int next;

    if (packet->kind == 0xFF) {
        if (packet->command == 4)
            return VCT_SESSION_HandleAnnounce(packet, event);
        if (packet->command == 3)
            return 0;
    }
    peer = VCT_SESSION_FindPeer(packet->srcId);
    if (peer) {
        next = VCT_SESSION_AdvancePhase(peer, packet);
        switch (next) {
        case -1:
            return 0;
        case -2:
            event->code = 0xC;
            peer->mode = 0;
            event->peer = peer;
            return 1;
        }
        event->code = VCT_SESSION_GetEventCode(packet, peer);
        event->peer = peer;
        peer->phase = next;
        return event->code != 0;
    }
    peer = VCT_SESSION_AllocPeer(packet->srcId);
    if (peer == 0) {
        VCT_SESSION_InitPeer(&gVctPeerPool.rejectPeer, packet->srcId);
        VCT_SESSION_SendReply((int)&gVctPeerPool.rejectPeer, 3);
        return 0;
    }
    next = VCT_SESSION_AdvancePhase(peer, packet);
    if (next == -2 || next == -1) {
        VCT_SESSION_FreePeerRecord(peer);
        return 0;
    }
    event->code = VCT_SESSION_GetEventCode(packet, peer);
    event->peer = peer;
    peer->phase = next;
    return event->code != 0;
}


/*
 * note: Audio session start/continue gate.
 *
 * note pass 2 2026-10-06 P2L53: EXACT (c99 and c). The event fill
 * (event->code, event->peer, peer->phase) is written out in each arm and only the tick
 * stamp is shared. The two fill copies are cross-jumped after jump threading,
 * which leaves the lone `b` hop at +0x88 (idiom
 * a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy).
 * The event->code compare then sits after a join with two stored values, so it
 * is reloaded (`ldr r0,[r7]`), and the zero/result colours (r6/r4) follow.
 */
/* Packet handler when all peers share one session (sharedSession set), using the single active record. */
int VCT_SESSION_HandleSharedPacket(VctPacket *packet, VctEvent *event)
{
    VctPeer *peer;
    int next;

    if (gVctPeerPool.active.mode == 2) {
        if (gVctPeerPool.active.peerId == packet->srcId) {
            peer = &gVctPeerPool.active;
            next = VCT_SESSION_AdvancePhase(peer, packet);
            switch (next) {
            case -2:
                event->code = 0xC;
                event->peer = 0;
                return 1;
            case -3:
            case -1:
                return 0;
            default:
                break;
            }
            event->code = VCT_SESSION_GetEventCode(packet, peer);
            event->peer = peer;
            peer->phase = next;
        } else {
            VCT_SESSION_BroadcastState(1);
            return 0;
        }
    } else {
        if (!(gVctGroup.peerMask & ((packet->srcId != 0) ? (1 << packet->srcId) : 1)))
            return 0;
        gVctPeerPool.active.peerId = packet->srcId;
        gVctPeerPool.active.mode = 2;
        gVctPeerPool.active.phase = 0;
        peer = &gVctPeerPool.active;
        next = VCT_SESSION_AdvancePhase(peer, packet);
        switch (next) {
        case -3:
        case -2:
        case -1:
            gVctPeerPool.active.mode = 0;
            return 0;
        }
        event->code = VCT_SESSION_GetEventCode(packet, peer);
        event->peer = peer;
        peer->phase = next;
    }
    if (event->code == 10) {
        VCT_SESSION_BroadcastState(1);
        gVctGroup.announceTick = func_020870D0();
    } else {
        VCT_SESSION_BroadcastState(0);
        gVctGroup.announceTick = 0;
    }
    return 1;
}


/* Packet with a protocol other than 0x10: drop the peer, answer with reply 2 and report event 2. */
int VCT_SESSION_HandleUnknownProtocolPacket(VctPacket *packet, VctEvent *event)
{
    VctPeer *peer;

    if (packet->kind == 0xff && packet->command == 4)
        return 0;
    peer = VCT_SESSION_FindPeer(packet->srcId);
    if (peer) {
        event->code = 2;
        event->peer = peer;
        peer->mode = 0;
        VCT_SESSION_SendReply((int)peer, 2);
        return 1;
    }
    VCT_SESSION_InitPeer(&gVctPeerPool.rejectPeer, packet->srcId);
    VCT_SESSION_SendReply((int)&gVctPeerPool.rejectPeer, 2);
    return 0;
}


/* Client mode: the host announces (flag 1) or closes (flag 0) the shared session. */
int VCT_SESSION_HandleAnnounce(VctPacket *packet, VctEvent *event)
{
    if (gVctSession.mode != 2)
        return 0;
    if (gVctSession.hostId != packet->srcId)
        return 0;
    switch (packet->flag) {
    case 0:
        if (gVctPeerPool.active.mode == 0)
            return 0;
        if (gVctPeerPool.active.phase == 5 || gVctPeerPool.active.phase == 2)
            event->code = 9;
        else
            event->code = 5;
        gVctPeerPool.active.mode = 0;
        gVctPeerPool.active.phase = 0;
        event->peer = &gVctPeerPool.active;
        break;
    case 1:
        gVctPeerPool.active.mode = 2;
        if (packet->floorHolderId == gVctSession.localId) {
            gVctPeerPool.active.phase = 2;
            event->code = 7;
            gVctPeerPool.active.memberMask = packet->memberMask;
        } else {
            gVctPeerPool.active.phase = 3;
            event->code = 6;
            gVctPeerPool.active.memberMask = packet->floorHolderId == 0 ? 1 : 1 << packet->floorHolderId;
        }
        gVctPeerPool.active.floorHolderId = packet->floorHolderId;
        event->peer = &gVctPeerPool.active;
        break;
    default:
        return 0;
    }
    return 1;
}


/*
 * lever: fill call takes data, p and b; r1/r2 stay live across the guards.
 */
/* Set up the frame buffer pool over a 32 byte aligned area of 4 to 72 frames and chain the free list. */
int VCT_POOL_InitFrames(VctRxPacket *buffer, u32 size)
{
    u32 i;
    u32 count;
    VctRxPacket *area;
    count = size / 0x478;
    area = buffer;
    gVoiceFramePool.base = area;
    if (count < 4 || count > 0x48) return 0;
    if (area == 0) return 0;
    if ((u32)area & 0x1f) {
        gVoiceFramePool.base = 0;
        return 0;
    }
    i = 0;
    MIi_CpuClearFast(i, area, size);
    for (i = 0; i < count - 1; i++)
        gVoiceFramePool.base[i].freeLink = &gVoiceFramePool.base[i + 1];
    (gVoiceFramePool.base + count)[-1].freeLink = 0;
    gVoiceFramePool.freeHead = gVoiceFramePool.base;
    return 1;
}


/* Forget the frame buffer area of the frame pool. */
void VCT_POOL_Reset(void)
{
    gVoiceFramePool.freeHead = 0;
    gVoiceFramePool.base = 0;
}


/* Take a frame buffer from the free list, or return 0 when the pool is empty. */
VctRxPacket *VCT_POOL_AllocFrame(void)
{
    VctRxPacket *result=0;
    int irq=OS_DisableInterrupts();
    if(gVoiceFramePool.freeHead != 0) {
        result=gVoiceFramePool.freeHead;
        gVoiceFramePool.freeHead=gVoiceFramePool.freeHead->freeLink;
    }
    OS_RestoreInterrupts(irq);
    return result;
}


/* Clear the list links of a frame buffer and put it back on the free list. */
void VCT_POOL_FreeFrame(VctRxPacket *frame)
{
    int irq=OS_DisableInterrupts();
    frame->freeLink=gVoiceFramePool.freeHead;
    gVoiceFramePool.freeHead=frame;
    frame->prev=0;
    frame->next=0;
    OS_RestoreInterrupts(irq);
}
