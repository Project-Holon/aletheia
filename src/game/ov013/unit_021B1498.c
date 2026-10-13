/*
 * file:     unit_021B1498.c
 * unit:     yes
 * function: VCT_AUDIO_GetPendingCount, VCT_AUDIO_FindPending, VCT_AUDIO_UnlinkPending, VCT_AUDIO_EncodeMuLaw, VCT_AUDIO_DecodeMuLaw, VCT_AUDIO_ConvertPcm16ToPcm8, VCT_AUDIO_ConvertPcm8ToPcm16, VCT_AUDIO_ClearReadyQueue, VCT_AUDIO_FlushReadyQueue, VCT_AUDIO_FlushAllReadyQueues, VCT_AUDIO_InsertReadyPacket, VCT_AUDIO_PeekReadyPacket, VCT_AUDIO_PopReadyPacket, VCT_AUDIO_GetReadyCount, VCT_AUDIO_InitReceiveSource, VCT_AUDIO_DetachReceiveSource, VCT_AUDIO_SetLastPacket, VCT_AUDIO_InitSequence, VCT_AUDIO_UpdateSequence, VCT_AUDIO_TrackPacketTiming, VCT_SESSION_AllocPeerRecord, VCT_SESSION_FreePeerRecord, VCT_SESSION_BuildGroupCommand, VCT_SESSION_SendGroupCommand, VCT_SESSION_BuildPeerReply, VCT_SESSION_SendPeerReply, VCT_SESSION_AddPeer, VCT_SESSION_RemovePeer, VCT_SESSION_InitPeerPool
 * address:  0x021B1498
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
 *   gVctPendingCount 0x021B4BA0 data a4
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   gVctPendingList  0x021B4B98  data  a4
 *   gVctMuLawSegmentEnds 0x021B3C28 data a4
 *   gVctReadyTail 0x021B4BC4 data a4
 *   gVctReadyHead 0x021B4BAC data a4
 *   gVctReadyCount 0x021B4BB8 data a4
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020870D0  0x020870D0  arm
 *   gVctSession 0x021B60D8 data a4
 *   VCT_SESSION_AllocPeer 0x021B24FC arm ov013
 *   gVctPeerPool  0x021B4BE0  data  a4
 *   VCT_SESSION_InitPacketHeader  0x021B2848  arm  ov013
 *   VCT_SESSION_CheckCommandAllowed  0x021B29A4  arm  ov013
 *   VCT_SESSION_HasNoOtherTalker  0x021B2958  arm  ov013
 *   VCT_SESSION_SendCommand 0x021B2564 arm ov013
 *   VCT_SESSION_SendReply 0x021B25B0 arm ov013
 *   gVctGroup     0x021B4BD0  data  ov013  a4
 *   VCT_SESSION_FindPeer  0x021B2A20  arm   ov013
 */
#include "vct_types.h"

extern u32 func_02087988(void);
extern void func_0208799C(u32 irq);
extern void VCT_POOL_FreeFrame(VctRxPacket *packet);
extern void MI_CpuFill8(void *dst, int value, int size);
extern unsigned long long func_020870D0(void);
extern VctPeer *VCT_SESSION_AllocPeer(unsigned int index);
extern void VCT_SESSION_InitPacketHeader(void *peer, void *message, unsigned int type);
extern int VCT_SESSION_CheckCommandAllowed(void *peer, const u8 *message);
extern int VCT_SESSION_HasNoOtherTalker(VctPeer *peer);
extern int VCT_SESSION_SendCommand(int peer, int type);
extern int VCT_SESSION_SendReply(int peer, int type);
extern VctPeer *VCT_SESSION_FindPeer(int aid);
int VCT_AUDIO_GetPendingCount(unsigned int slot);
VctRxPacket *VCT_AUDIO_FindPending(u32 slot);
u32 VCT_AUDIO_UnlinkPending(VctRxPacket *packet);
void VCT_AUDIO_EncodeMuLaw(unsigned char *dst, const short *src, unsigned int sampleCount);
void VCT_AUDIO_DecodeMuLaw(unsigned char *src, short *dst, unsigned int sampleCount);
void VCT_AUDIO_ConvertPcm16ToPcm8(unsigned char *dst, short *src, unsigned int sampleCount);
void VCT_AUDIO_ConvertPcm8ToPcm16(signed char *src, short *dst, unsigned int sampleCount, int mode);
void VCT_AUDIO_ClearReadyQueue(unsigned int slot);
void VCT_AUDIO_FlushReadyQueue(u32 slot);
void VCT_AUDIO_FlushAllReadyQueues(void);
int VCT_AUDIO_InsertReadyPacket(VctRxPacket *packet, u32 slot);
void *VCT_AUDIO_PeekReadyPacket(unsigned int slot);
VctRxPacket *VCT_AUDIO_PopReadyPacket(u32 slot);
int VCT_AUDIO_GetReadyCount(unsigned int slot);
void VCT_AUDIO_InitReceiveSource(VctReceiveSource *source, u32 queueIndex, int peerAid);
void VCT_AUDIO_DetachReceiveSource(VctReceiveSource *source);
void VCT_AUDIO_SetLastPacket(VctReceiveSource *source, VctRxPacket *packet);
void VCT_AUDIO_InitSequence(VctReceiveSource *source, u16 seq);
int VCT_AUDIO_UpdateSequence(VctReceiveSource *source, VctRxPacket *packet, u16 seq);
int VCT_AUDIO_TrackPacketTiming(VctReceiveSource *source, VctRxPacket *packet);
VctPeer *VCT_SESSION_AllocPeerRecord(unsigned int index);
int VCT_SESSION_FreePeerRecord(VctPeer *peer);
int VCT_SESSION_BuildGroupCommand(void *peer, unsigned int type, unsigned char *buffer, unsigned int size);
int VCT_SESSION_SendGroupCommand(int peer, int type);
int VCT_SESSION_BuildPeerReply(VctPeer *peer, unsigned int type, unsigned char *buffer, unsigned int size);
int VCT_SESSION_SendPeerReply(int peer, int type);
int VCT_SESSION_AddPeer(unsigned char aid);
int VCT_SESSION_RemovePeer(int aid);
int VCT_SESSION_InitPeerPool(VctInitParams *params);
extern VctRxPacket *gVctReadyHead[3];
extern u32 gVctReadyCount[3];
extern VctRxPacket *gVctReadyTail[3];
extern const int gVctMuLawSegmentEnds[8];
extern VctGroupCount gVctGroup;








int VCT_AUDIO_GetPendingCount(unsigned int slot) { return gVctPendingCount[slot]; }









VctRxPacket *VCT_AUDIO_FindPending(u32 slot)
{
    VctRxPacket *packet = gVctPendingList.head;
    u32 irq = func_02087988();

    for (; packet; packet = packet->next) {
        if (packet->queueIndex == slot) {
            func_0208799C(irq);
            return packet;
        }
    }
    func_0208799C(irq);
    return 0;
}









u32 VCT_AUDIO_UnlinkPending(VctRxPacket *packet)
{
    u32 irq = func_02087988();

    if (packet->prev)
        packet->prev->next = packet->next;
    else {
        gVctPendingList.head = packet->next;
        if (packet->next)
            packet->next->prev = 0;
    }
    if (packet->next)
        packet->next->prev = packet->prev;
    else {
        gVctPendingList.tail = packet->prev;
        if (packet->prev)
            packet->prev->next = 0;
    }
    gVctPendingCount[packet->queueIndex]--;
    func_0208799C(irq);
    return gVctPendingCount[packet->queueIndex];
}









/*
 * note: 2026-10-05 tried forms (all DIFF 26/172): an inline encode() with an
 *   inline seg_search() helper, mask types and orders, clamp spellings,
 *   pragmas opt_lifetimes, scheduling, peephole, opt_common_subs,
 *   opt_propagation, opt_dead_assignments, opt_dead_code,
 *   opt_strength_reduction, opt_loop_invariants.
 * note: pass 2 2026-10-06 P2L37: EXACT. The u-law encode is written in the
 *   loop body (no inline helpers). The segment search uses segment as its own
 *   counter, with a goto on a hit and segment = 8 on fall-through, as the helper's
 *   "return size". The code value goes through an int code and the store is
 *   dst[i] = code ^ signMask. With the inline helpers, the mask and the segment
 *   counter swapped registers (r5/r6).
 */
void VCT_AUDIO_EncodeMuLaw(unsigned char *dst, const short *src, unsigned int sampleCount)
{
    unsigned int i;

    for (i = 0; i < sampleCount; i++) {
        int sample, segment, code;
        unsigned char signMask;
        const int *segmentEnd;

        sample = src[i] >> 2;
        if (sample < 0) {
            signMask = 0x7f;
            sample = -sample;
        } else {
            signMask = 0xff;
        }
        if (sample > 8159)
            sample = 8159;
        segmentEnd = gVctMuLawSegmentEnds;
        for (segment = 0; segment < 8; segment++)
            if (sample + 0x21 <= *segmentEnd++)
                goto found;
        segment = 8;
    found:
        if (segment >= 8) {
            dst[i] = 0x7f ^ signMask;
        } else {
            code = (segment << 4) | (((sample + 0x21) >> (segment + 1)) & 0xf);
            dst[i] = code ^ signMask;
        }
    }
}








void VCT_AUDIO_DecodeMuLaw(unsigned char *src, short *dst, unsigned int sampleCount)
{
    unsigned int i;

    for (i = 0; i < sampleCount; i++) {
        int code = ~src[i];
        int magnitude = (((code & 0xf) << 3) + 0x84) << ((code & 0x70) >> 4);

        dst[i] = (code & 0x80) ? 0x84 - magnitude : magnitude - 0x84;
    }
}








void VCT_AUDIO_ConvertPcm16ToPcm8(unsigned char *dst, short *src, unsigned int sampleCount)
{
    unsigned int i;

    for (i = 0; i < sampleCount; i++)
        dst[i] = (signed char)(src[i] >> 8);
}








void VCT_AUDIO_ConvertPcm8ToPcm16(signed char *src, short *dst, unsigned int sampleCount, int mode)
{
    unsigned int i;

    for (i = 0; i < sampleCount; i++)
        dst[i] = (short)(src[i] << 8);
}







void VCT_AUDIO_ClearReadyQueue(unsigned int slot)
{
    u32 irq = func_02087988();
    gVctReadyTail[slot] = 0;
    gVctReadyHead[slot] = 0;
    gVctReadyCount[slot] = 0;
    func_0208799C(irq);
}








void VCT_AUDIO_FlushReadyQueue(u32 slot)
{
    VctRxPacket *packet;
    u32 irq = func_02087988();

    packet = gVctReadyHead[slot];
    while (packet) {
        VctRxPacket *next = packet->next;
        gVctReadyHead[slot] = next;
        if (next)
            next->prev = 0;
        VCT_POOL_FreeFrame(packet);
        packet = gVctReadyHead[slot];
    }
    gVctReadyTail[slot] = 0;
    gVctReadyCount[slot] = 0;
    func_0208799C(irq);
}








void VCT_AUDIO_FlushAllReadyQueues(void)
{
    int slot;
    VctRxPacket *packet;
    u32 irq = func_02087988();

    slot = 0;
    while (slot < 3) {
        while ((packet = gVctReadyHead[slot]) != 0) {
            VctRxPacket *next = packet->next;

            gVctReadyHead[slot] = next;
            if (next)
                next->prev = 0;
            VCT_POOL_FreeFrame(packet);
        }
        gVctReadyTail[slot] = 0;
        gVctReadyCount[slot] = 0;
        slot++;
    }
    func_0208799C(irq);
}







int VCT_AUDIO_InsertReadyPacket(VctRxPacket *packet, u32 slot)
{
    int irq;
    VctRxPacket *cur;

    if (packet == 0)
        return -1;
    if (slot >= 3)
        return -1;

    irq = func_02087988();
    if (gVctReadyHead[slot] == 0) {
        gVctReadyHead[slot] = packet;
        packet->prev = 0;
        gVctReadyHead[slot]->next = 0;
        gVctReadyTail[slot] = gVctReadyHead[slot];
    } else {
        for (cur = gVctReadyTail[slot]; cur != 0; cur = cur->prev) {
            if (cur->seq < packet->seq) {
                packet->prev = cur;
                packet->next = cur->next;
                cur->next = packet;
                if (packet->next != 0)
                    packet->next->prev = packet;
                if (cur == gVctReadyTail[slot])
                    gVctReadyTail[slot] = packet;
                goto done;
            }
        }
        packet->prev = 0;
        packet->next = gVctReadyHead[slot];
        gVctReadyHead[slot]->prev = packet;
        gVctReadyHead[slot] = packet;
    }
done:
    gVctReadyCount[slot]++;
    func_0208799C(irq);
    return gVctReadyCount[slot];
}






void *VCT_AUDIO_PeekReadyPacket(unsigned int slot)
{
    u32 irq = func_02087988();
    if (gVctReadyHead[slot] != 0) {
        func_0208799C(irq);
        return gVctReadyHead[slot];
    }
    func_0208799C(irq);
    return 0;
}







VctRxPacket *VCT_AUDIO_PopReadyPacket(u32 slot)
{
    VctRxPacket *packet;
    u32 irq = func_02087988();

    packet = gVctReadyHead[slot];
    if (packet) {
        VctRxPacket *next = packet->next;

        gVctReadyHead[slot] = next;
        gVctReadyCount[slot]--;
        if (next)
            next->prev = 0;
        else
            gVctReadyTail[slot] = 0;
    }
    func_0208799C(irq);
    return (VctRxPacket *)gVctReadyCount[slot];
}






int VCT_AUDIO_GetReadyCount(unsigned int slot) { return gVctReadyCount[slot]; }







void VCT_AUDIO_InitReceiveSource(VctReceiveSource *source, u32 queueIndex, int peerAid)
{
    MI_CpuFill8(source, 0, 0x28);
    source->playoutDelay = 0x134DF;
    source->lastLatency = 0;
    source->latencyFilter = 0;
    source->queueIndex = queueIndex;
    source->peerAid = peerAid;
    source->jitter = 0;
    source->transit = 0;
    source->hold = 0;
    source->lo = 0;
    source->hi = 0x134DF;
    source->lowCount = 0;
    source->timestamp0 = 0;
    source->tick0 = 0;
    source->count = 0;
    source->pendingSkips = 0;
    source->prevTimestamp = 0;
    source->maxSeq = 0;
    source->lastPlayedSeq = 0;
    source->probation = 1;
    source->lastPacket = 0;
    source->lastPacketSize = 0;
    source->noiseLevel = 0;
}







void VCT_AUDIO_DetachReceiveSource(VctReceiveSource *source)
{
    if (source->lastPacket) {
        VCT_POOL_FreeFrame(source->lastPacket);
        source->lastPacket = 0;
    }
    source->peerAid = -1;
}







void VCT_AUDIO_SetLastPacket(VctReceiveSource *source, VctRxPacket *packet)
{
    if (source->lastPacket)
        VCT_POOL_FreeFrame(source->lastPacket);
    source->lastPacket = packet;
    VCT_AUDIO_PopReadyPacket(source->queueIndex);
}







void VCT_AUDIO_InitSequence(VctReceiveSource *source, u16 seq)
{
    source->baseSeq = seq;
    source->badSeq = 0x00010001;
    source->cycles = 0;
    source->probation = 0;
}







/*
 * RFC 3550 update_seq shape: MAX_DROPOUT 3000, MAX_MISORDER 100.
 */
int VCT_AUDIO_UpdateSequence(VctReceiveSource *source, VctRxPacket *packet, u16 seq)
{
    u16 last = source->baseSeq;
    u16 delta = seq - last;

    if (delta < 3000) {
        if (seq < last)
            source->cycles += 0x10000;
        source->baseSeq = seq;
    } else if (delta <= 0x10000 - 100) {
        if (seq == source->badSeq) {
            VCT_AUDIO_InitSequence(source, seq);
            source->maxSeq = (u16)(seq - 1);
        } else {
            source->badSeq = (u16)(seq + 1);
            return 0;
        }
    } else if (seq + source->cycles > source->maxSeq + 0x10000 - 100) {
        packet->seq = seq + source->cycles - 0x10000;
        return 1;
    }
    packet->seq = seq + source->cycles;
    return 1;
}







/*
 * RTP receive bookkeeping: sequence check (VCT_AUDIO_UpdateSequence), interarrival
 * jitter (J += (|D| - J) / 16), playout-time and drift tracking. The
 * constants are OS ticks (OS_MilliSecondsToTicks folded): 0x8B18 = 68 ms,
 * 0x7FD88 ~ 1 s, 0x134DF = 151 ms, 0x68520 = 816 ms, 0x8701 = 66 ms.
 * The `(unsigned int)jitterUnits` in the delay store is what keeps the
 * original's second `jitterUnits * 0x8B18` (fresh pool load, fresh mul) from
 * being CSE'd with the one in `source->lo`.
 */
int VCT_AUDIO_TrackPacketTiming(VctReceiveSource *source, VctRxPacket *packet)
{
    int transit;
    int driftFlag = 0;
    int timestampDelta;
    int delta;
    int jitterUnits;
    int jitter3;
    unsigned long long now;

    if (source->probation != 0) {
        VCT_AUDIO_InitSequence(source, packet->seq);
    } else {
        if (!VCT_AUDIO_UpdateSequence(source, packet, packet->seq)) {
            source->dropped++;
            return driftFlag;
        }
        source->lastSeq = packet->seq;
        if (source->maxSeq == packet->seq) {
            source->dropped++;
            return driftFlag;
        }
        if (source->maxSeq + 1 != packet->seq && packet->marker == 0) {
            delta = packet->seq - source->maxSeq;
            if (delta < 0)
                delta = -delta;
            if (delta > 100) {
                source->maxSeq = packet->seq;
                return 0;
            }
            if (source->maxSeq > packet->seq)
                source->reordered++;
        }
    }
    source->maxSeq = packet->seq;
    if (source->timestamp0 == 0) {
        source->timestamp0 = packet->timestamp;
        source->tick0 = packet->arrivalTick;
        source->count = 0;
    }
    timestampDelta = (packet->timestamp - source->timestamp0) << 6;
    transit = (int)((unsigned int)timestampDelta - (packet->arrivalTick - source->tick0));
    if (source->transit == 0 || packet->marker != 0) {
        source->transit = transit;
    } else {
        delta = transit - source->transit;
        if (delta < 0)
            delta = -delta;
        source->transit = transit;
        if ((unsigned long long)delta > (long long)((source->jitter + 0x8B18) * 2) + 0xCC8DULL)
            source->hold = delta / 0x8B18 + 2;
        if (source->hold <= 0)
            source->jitterOut = source->jitter = source->jitter + ((delta - source->jitter) >> 4);
    }
    packet->playTick = source->playoutDelay + ((unsigned int)timestampDelta + source->tick0);
    now = func_020870D0();
    if (packet->playTick + 0x8B18 < now)
        return 0;
    if (packet->playTick > now + 0x7FD88)
        return 0;
    if (source->hold <= 0) {
        jitter3 = source->jitter * 3;
        jitterUnits = jitter3 / 0x8B18;
        if (jitter3 > source->hi) {
            source->hi = (jitterUnits + 1) * 0x8B18 + 0x134DF;
            source->lo = source->hi - 0xD0A4;
            source->playoutDelay = (unsigned int)jitterUnits * 0x8B18 + 0x134DF;
            source->lowCount = 0;
        } else if (jitter3 < source->lo) {
            if (++source->lowCount > 70) {
                source->hi = (jitterUnits + 1) * 0x8B18 + 0x134DF;
                source->lo = jitterUnits * 0x8B18 - 0x458C;
                if (source->lo < 0)
                    source->lo = 0;
                source->playoutDelay = (unsigned int)jitterUnits * 0x8B18 + 0x134DF;
                source->lowCount = 0;
            }
        }
        if (source->playoutDelay > 0x68520)
            source->playoutDelay = 0x68520;
        if (source->count < 16) {
            source->count++;
            source->avg = transit;
            source->base = transit;
        } else {
            source->avg = (transit + source->avg * 31) / 32;
        }
        source->drift = source->base - source->avg;
        if (source->drift > 0x8701)
            driftFlag = 1;
        if (source->drift < -0x8701) {
            source->pendingSkips++;
            driftFlag = -1;
        }
        if (driftFlag != 0) {
            source->count = 0;
            source->timestamp0 = 0;
        }
    }
    source->hold--;
    return 1;
}






VctPeer *VCT_SESSION_AllocPeerRecord(unsigned int index)
{
    if (gVctSession.mode == 0 || gVctSession.mode == 2)
        return 0;
    return VCT_SESSION_AllocPeer(index);
}






int VCT_SESSION_FreePeerRecord(VctPeer *peer)
{
    VctPeer *prev = 0;
    VctPeer *cur = gVctPeerPool.activeHead;

    if (peer == 0)
        return 0;
    if (gVctSession.mode == 2) {
        if (peer == &gVctPeerPool.active)
            gVctPeerPool.active.mode = 0;
        return 1;
    }
    for (; cur; prev = cur, cur = cur->next) {
        if (cur == peer) {
            peer->mode = 0;
            if (prev)
                prev->next = peer->next;
            else if (cur->next)
                gVctPeerPool.activeHead = cur->next;
            else
                gVctPeerPool.activeHead = 0;
            peer->next = gVctPeerPool.freePeers;
            gVctPeerPool.freePeers = peer;
            return 1;
        }
    }
    return 0;
}






int VCT_SESSION_BuildGroupCommand(void *peer, unsigned int type, unsigned char *buffer, unsigned int size)
{
    int dstId = 0xff;

    if (peer == 0)
        return -1;
    if (size < 0x10)
        return -1;
    if (gVctSession.sharedSession == 1)
        return -3;
    if (type >= 5)
        return -3;
    buffer[4] = dstId;
    VCT_SESSION_InitPacketHeader(peer, buffer, type & 0xff);
    if (VCT_SESSION_CheckCommandAllowed(peer, buffer) == 0)
        return 0xfc - dstId;
    if (gVctSession.mode == 1 && type == 0) {
        if (VCT_SESSION_HasNoOtherTalker(peer) == 0)
            return 0xfc - dstId;
    }
    return 0;
}





int VCT_SESSION_SendGroupCommand(int peer, int type)
{
    if (gVctSession.mode == 2)
        return -3;
    return VCT_SESSION_SendCommand(peer, type);
}






int VCT_SESSION_BuildPeerReply(VctPeer *peer, unsigned int type, unsigned char *buffer, unsigned int size)
{
    int zero = 0;

    if (peer == 0)
        return -1;
    if (size < 0x10)
        return -1;
    if (type >= 6)
        return -3;
    buffer[4] = zero;
    VCT_SESSION_InitPacketHeader(peer, buffer, type & 0xff);
    if (type == 0) {
        if (gVctSession.mode == 1 && peer->phase == 4) {
            if (VCT_SESSION_HasNoOtherTalker(peer) == 0)
                return zero - 3;
        }
        peer->memberMask = peer->peerId ? 1 << peer->peerId : 1;
    }
    if (VCT_SESSION_CheckCommandAllowed(peer, buffer) == 0)
        return -3;
    return 0;
}




int VCT_SESSION_SendPeerReply(int peer, int type)
{
    if (gVctSession.mode == 2)
        return -3;
    return VCT_SESSION_SendReply(peer, type);
}



int VCT_SESSION_AddPeer(unsigned char aid)
{
    VctPeer *peer;

    if (gVctSession.mode != 3)
        return -2;
    if (gVctGroup.peerCount == 3)
        return -6;
    if (aid == gVctSession.localId)
        return -1;
    if (VCT_SESSION_FindPeer(aid))
        return 0;
    peer = VCT_SESSION_AllocPeerRecord(aid);
    if (peer == 0)
        return -1;
    peer->peerId = aid;
    peer->floorHolderId = aid;
    peer->phase = 2;
    peer->memberMask = 1 << aid;
    gVctSession.eventCallback(aid, 7, peer, gVctSession.callbackArg);
    gVctGroup.peerCount++;
    return 0;
}



int VCT_SESSION_RemovePeer(int aid)
{
    VctPeer *peer;

    if (gVctSession.mode != 3)
        return -2;
    peer = VCT_SESSION_FindPeer(aid);
    if (peer == 0)
        return -1;
    gVctSession.eventCallback(aid, 9, peer, gVctSession.callbackArg);
    gVctGroup.peerCount--;
    return 0;
}



int VCT_SESSION_InitPeerPool(VctInitParams *params)
{
    unsigned int i;

    if (params->peerBuffer == 0 || params->peerCount == 0 || params->peerCount > 8)
        return 0;
    gVctPeerPool.freePeers = params->peerBuffer;
    MI_CpuFill8(params->peerBuffer, 0, params->peerCount * sizeof(VctPeer));
    MI_CpuFill8(&gVctPeerPool.active, 0, sizeof(VctPeer));
    MI_CpuFill8(&gVctPeerPool.rejectPeer, 0, sizeof(VctPeer));
    for (i = 0; i < params->peerCount - 1; i++)
        gVctPeerPool.freePeers[i].next = &gVctPeerPool.freePeers[i + 1];
    (gVctPeerPool.freePeers + params->peerCount - 1)->next = 0;
    gVctPeerPool.activeHead = 0;
    gVctGroup.peerMask = 0;
    gVctGroup.peerCount = 0;
    gVctSession.sessionFlags = 0;
    gVctPeerPool.tickFunc = (void *)func_020870D0;
    gVctPeerPool.rngMul = 0x5D588B65;
    gVctPeerPool.rngAdd = 0x269EC3;
    return 1;
}
