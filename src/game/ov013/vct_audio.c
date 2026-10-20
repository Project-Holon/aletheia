/*
 * file:     vct_audio.c
 * unit:     yes
 * function: VCT_AUDIO_EncodeSendFrame, VCT_AUDIO_ReceiveFrame, VCT_AUDIO_DecodePendingFrames, VCT_AUDIO_SendFrameStep, VCT_AUDIO_ResetPendingList, VCT_AUDIO_FlushPendingSlot, VCT_AUDIO_FlushPendingAll, VCT_AUDIO_QueuePending, VCT_AUDIO_GetPendingHead, VCT_AUDIO_GetPendingCount, VCT_AUDIO_FindPending, VCT_AUDIO_UnlinkPending, VCT_AUDIO_EncodeMuLaw, VCT_AUDIO_DecodeMuLaw, VCT_AUDIO_ConvertPcm16ToPcm8, VCT_AUDIO_ConvertPcm8ToPcm16, VCT_AUDIO_ClearReadyQueue, VCT_AUDIO_FlushReadyQueue, VCT_AUDIO_FlushAllReadyQueues, VCT_AUDIO_InsertReadyPacket, VCT_AUDIO_PeekReadyPacket, VCT_AUDIO_PopReadyPacket, VCT_AUDIO_GetReadyCount, VCT_AUDIO_InitReceiveSource, VCT_AUDIO_DetachReceiveSource, VCT_AUDIO_SetLastPacket, VCT_AUDIO_InitSequence, VCT_AUDIO_UpdateSequence, VCT_AUDIO_TrackPacketTiming, VCT_SESSION_AllocPeerRecord, VCT_SESSION_FreePeerRecord, VCT_SESSION_BuildGroupCommand, VCT_SESSION_SendGroupCommand, VCT_SESSION_BuildPeerReply, VCT_SESSION_SendPeerReply, VCT_SESSION_AddPeer, VCT_SESSION_RemovePeer, VCT_SESSION_InitPeerPool, VCT_SESSION_ResetPeerPool
 * address:  0x021B0D18
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vct_audio.c, vct_session.c by tools/splitfile.py.
 *
 * symbols:
 *   gVctSendBuffer  0x021B42C0  data  ov013  a4
 *   gVctSendState  0x021B3C84  data  ov013  a4
 *   gVctSendEnabled  0x021B3C24  data  ov013  a4
 *   gVctAudioStateAdpcm  0x021B3C94  data  ov013  a4
 *   gVctSession  0x021B60D8  data  ov013  a1
 *   VCT_DSP_HighPassFilter  0x021B3278  arm  ov013
 *   VCT_DSP_SuppressEchoWithReference  0x021B3604  arm  ov013
 *   VCT_DSP_UpdateVoiceGate  0x021B3084  arm  ov013
 *   VCT_ADPCM_EncodePacket  0x021B04A8  arm  ov013
 *   MATH_CountPopulation  0x02080D24  arm
 *   gVctReceiveSources  0x021B3CBC  data  ov013  a4
 *   gVctFrameSpecs  0x021B3AD0  data  ov013  a1
 *   VCT_POOL_AllocFrame  0x021B2FB0  arm  ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   MI_CpuCopy8  0x02082D44  arm
 *   VCT_ADPCM_DecodePacket  0x021B043C  arm  ov013
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gVctSendSchedule  0x021B3ADA  data  ov013  a1
 *   DWC_SendUnreliable  0x02177044  arm  ov009
 *   gVctPendingList  0x021B4B98  data
 *   gVctPendingCount  0x021B4BA0  data
 *   gVctMuLawSegmentEnds 0x021B3C28 data a4
 *   gVctReadyTail 0x021B4BC4 data a4
 *   gVctReadyHead 0x021B4BAC data a4
 *   gVctReadyCount 0x021B4BB8 data a4
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetTick  0x020870D0  arm
 *   VCT_SESSION_AllocPeer 0x021B24FC arm ov013
 *   gVctPeerPool  0x021B4BE0  data  a4
 *   VCT_SESSION_InitPacketHeader  0x021B2848  arm  ov013
 *   VCT_SESSION_CheckCommandAllowed  0x021B29A4  arm  ov013
 *   VCT_SESSION_HasNoOtherTalker  0x021B2958  arm  ov013
 *   VCT_SESSION_SendCommand 0x021B2564 arm ov013
 *   VCT_SESSION_SendReply 0x021B25B0 arm ov013
 *   gVctGroup     0x021B4BD0  data  ov013  a4
 *   VCT_SESSION_FindPeer  0x021B2A20  arm   ov013
 *   VCT_SESSION_BuildGroupCommand  0x021B2010  arm  ov013
 *   VCT_SESSION_BuildPeerReply  0x021B20D4  arm  ov013
 *   VCT_SESSION_FreePeerRecord  0x021B1F54  arm  ov013
 */
#include "vct_types.h"
#include "vct_audio_shared_types.h"

#define reg_SQRTCNT     (*(volatile u16 *)0x040002B0)

#define reg_SQRT_RESULT (*(volatile u32 *)0x040002B4)

#define reg_SQRT_PARAM  (*(volatile u32 *)0x040002B8)

#include "vct_dsp.h"



#include "vct_adpcm.h"

#include "../arm9/math.h"

#include "vct_pool.h"


#include "../arm9/mi_memory.h"


#include "../arm9/os_system.h"


#include "../ov009/dwc_transport.h"


#include "../arm9/os_tick.h"

#include "vct_session.h"
struct VctPacket;
struct VctPeer;







VctAudioFrame *VCT_AUDIO_EncodeSendFrame(void);

int VCT_AUDIO_ReceiveFrame(u32 senderAid, VctAudioFrame *frame, u32 size, u64 arrivalTick);

int VCT_AUDIO_DecodePendingFrames(void);

int VCT_AUDIO_SendFrameStep(void);

void VCT_AUDIO_ResetPendingList(void);

void VCT_AUDIO_FlushPendingSlot(unsigned int slot);

void VCT_AUDIO_FlushPendingAll(void);

int VCT_AUDIO_QueuePending(VctRxPacket *packet);

VctRxPacket *VCT_AUDIO_GetPendingHead(void);

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

VctRxPacket *VCT_AUDIO_SetLastPacket(VctReceiveSource *source, VctRxPacket *packet);

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

void VCT_SESSION_ResetPeerPool(void);

/* gVctAudioStateAdpcm is gVctSendState + 0x10 (adpcmPredictor): the pool word names it separately. */
extern AdpcmState gVctAudioStateAdpcm;

extern u8 gVctSendSchedule[][3];

extern VctRxPacket *gVctReadyHead[3];

extern u32 gVctReadyCount[3];

extern VctRxPacket *gVctReadyTail[3];

extern const int gVctMuLawSegmentEnds[8];

extern VctGroupCount gVctGroup;

/*
 * volatile: SQRTCNT polls at 021B0D90; SQRT result/parameter are hardware registers at 040002B4/040002B8.
 * residual: none; EXACT 544/544 in --lang c99 and --lang c, all twelve relocations resolved.
 * evidence: fresh xor-zero dependency, comma reset expression and byte reset bitfield each tied 10. Signed reset flag and own MATH_CountPopulation u8 return correction also tied 10.
 * checks: 1 own matched 3278/3604/04A8/1688 and MATH_CountPopulation bodies read; 3084 original reads x/sq/byte-output pointer, arity 3; 2 no exact reset twin; 3 signed f8 and exact u8 SDK return compiled without change; 4 inline, commutative-operand and named-field idioms read; 5 full directory and fresh ov013 neighbours reread, no addressed stack aggregate; next hypothesis a reset helper using an independently evidenced enclosing record.
 * permuter: earlier budget-300 search consumed; not repeated. Prior inline reset, enum flag and signed x did not improve.
 * note 2026-10-05 (lane S2, wave P4): only the f8 reset block at +012C..+0134 differs. The original keeps
 *   ldrb; orr; strb; str r5 in source order, we put the zero store between ldrb and orr (the same shape
 *   for the f14 block at +0140 matches). Tried: inline helper replaced by plain statements, f8 as u32 and as
 *   void pointer, nested if instead of &&, reset stores in either source order (scheduler output unchanged),
 *   each of opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole off
 *   (all 10 bytes). No twin found. Header: status DIFF, 10 bytes.
 * recoup 2026-10-05 (lane R13): no loop counter here, so the ov013 021B0614 opt_lifetimes shape does not apply. Levers 1-2 no change
 *   (callee arities and widths already match matched callers). Lever 3/4/5: f8 block as nested if, store first, f5 = f5 | 0x80,
 *   byte temp, else-if with empty then, negated condition, f5 through a u8 pointer local: all 10 B. Pointer local for gVctSendState
 *   (whole function 53 B, f8/f14 blocks only 362 B). Pragmas not repeated (header lists them). Residue unchanged: zero store
 *   scheduled before orr in the f8 block only.
 * final push 2026-10-05 G3L8 (32 compiles, 3 rounds): still DIFF 10 B. New facts: (1) scheduling off and peephole off do not change the
 *   order, so the f8 block is ordered before the scheduler (ldrb; str; orr; strb). (2) The order depends on the field offset of the reset
 *   store: fields at +0,+4,+8,+0xC of gVctSendState get the zero store between ldrb and orr; fields at +0x14,+0x18,+0x20,+0x24 keep source
 *   order; the f14 block is never wrong, also when written first. Removing the later f4/f10/f12 accesses does not change it. Tried without
 *   effect: else-if instead of &&, no && at all, raw-offset access, int f8, u32 w[4] array view, cast pointer view, early pointer local,
 *   f5 as ((u8 *)f)[5], Frame data[] start moved to +6, f as u32 arithmetic, Frame fr[2] view (changes the whole function), reversed
 *   && operand order, opt_dead_code / opt_strength_reduction / opt_loop_invariants off. No twin in the listings (orrne #0x80 hits in
 *   ov114, arm9 are stack or different shapes). Open idea: the original f8 store is not provably independent of the strb at f+5.
 * pass 2 2026-10-06 P2L22 (40 compiles, 3 rounds): still DIFF 10 B. New facts: the f8 store follows strb f5 only when mwcc
 *   cannot prove f and gVctSendState+8 apart. f from an extern pointer or a pointer select (cond ? &d : &d + 0x460) gives the
 *   right order but a second base and addeq (479 B). Integer forms (u32 cast, off local, if/else, inline helper, u8 *buf with
 *   opt_propagation off) keep the points-to. In a sized struct, accesses at +0x10 and up are treated as may-alias, below
 *   0x10 as independent (also for a separate global); int[]/struct[] views make f14 independent too (20 B).
 *   AdpcmState member at +0x10 with &gVctSendState.st as the call argument also gives 10 B (pool word folds to 021B3C94).
 *   Notes: scratchpad wD9r/p2_P2L22/research.md.
 * pass 3 2026-10-06 P3L11 (38 compiles, 3 rounds): still DIFF 10 B. New facts: (1) one TU struct at 3C84 holding
 *   the ctx and the 42C0 frames/counters, with `Ctx42C0 *w = &big.w` for the 42C0 side, puts both reset blocks in
 *   original order (frame and ctx in one object: unknown frame offset vs ctx+8 is a same-object alias), but the
 *   backend then drops the first `f8CC = f4` store and swaps str f8D4/cmp (72 B). Keeping that store needs the id
 *   load to alias (id inside the struct: 12 B, but gVctSession is used by many other TUs and TU B's bss ends at
 *   4B98, so not plausible). (2) volatile flags, opt_pointer_analysis off (on segfaults the compiler),
 *   c99_alias_by_type, opt_scalarize/decomposeaggregates, scheduling off, static/defined globals, `f = 0` init,
 *   inline helpers under opt_propagation off, named `u32 *req`, 0F38 Frame layout: all 10 B or worse.
 *   Open lead: a frame pointer the ARM backend cannot trace, still emitted as add r8, r6, r0 from the shared pool.
 *   Notes: scratchpad wD9r/p3_P3L11/research.md.
 * pass 4 2026-10-06 P4L05: closed. The frame flag byte f5 and the two reset-request flags f8 and f14 of
 *   gVctSendState are volatile members. The request flags are set from other paths (021B0CD8 sets f8,
 *   021B0614 and 021B074C set f14) and f5 is the flag byte of the frame buffer that the wireless layer
 *   reads. Two volatile accesses keep their source order, so the f8 reset store stays after strb f5.
 *   Volatile on f8/f14 alone (P3L11 a1) or on f5 alone stays 10 B; both sides are needed.
 */
VctAudioFrame *VCT_AUDIO_EncodeSendFrame(void)
{
    u8 *samples;
    VctAudioFrame *frame;
    int energy;
    u32 rms;
    int mode;
    u32 pending;

    mode = gVctSendState.codecMode;
    pending = gVctSendBuffer.writeCount - gVctSendBuffer.readCount;
    if (pending > 1) {
        gVctSendBuffer.readCount = gVctSendBuffer.writeCount - 1;
        pending = 1;
    }
    if (pending == 0)
        return 0;

    /* byte offset form kept: frames[idx] indexing changes the code (DIFF). */
    frame = (VctAudioFrame *)((u8 *)&gVctSendBuffer + ((gVctSendBuffer.readCount & 1) ? 0 : sizeof(VctAudioFrame)));
    samples = frame->data;
    if (mode >= 2)
        samples += 4;

    energy = VCT_DSP_HighPassFilter((short *)samples, gVctSendState.frameBytes);
    reg_SQRTCNT = 0;
    reg_SQRT_PARAM = energy;
    while (reg_SQRTCNT & 0x8000)
        ;
    rms = reg_SQRT_RESULT;

    if (gVctSendState.echoSuppressEnabled != 0)
        VCT_DSP_SuppressEchoWithReference((short *)samples, gVctSendState.frameBytes, rms);

    frame->flags = mode;
    if (gVctSendEnabled != 0) {
        switch (gVctSendState.lastGateResult = VCT_DSP_UpdateVoiceGate(energy, rms, 0)) {
        case 0:
            gVctSendBuffer.readCount++;
            return 0;
        case 1:
            frame->flags |= 0x80;
            break;
        case 3:
            frame->type = 0x41;
            break;
        }
    }
    if (gVctSendEnabled == 0 && gVctSendState.markerRequestNoVad != 0) {
        frame->flags |= 0x80;
        gVctSendState.markerRequestNoVad = 0;
    }
    if (gVctSendState.markerRequest != 0) {
        frame->flags |= 0x80;
        gVctSendState.markerRequest = 0;
    }

    if (mode >= 2) {
        if (frame->flags & 0x80) {
            gVctSendState.adpcmPredictor = 0;
            gVctSendState.adpcmStepIndex = 0;
        }
        VCT_ADPCM_EncodePacket((AdpcmHeader *)(samples - 4), samples, gVctSendState.frameBytes >> 1, &gVctAudioStateAdpcm, mode);
    } else if (mode == 1) {
        VCT_AUDIO_EncodeMuLaw(samples, (short *)samples, gVctSendState.frameBytes >> 1);
    } else if (mode == 0) {
        VCT_AUDIO_ConvertPcm16ToPcm8(samples, (short *)samples, gVctSendState.frameBytes >> 1);
    }

    gVctSendBuffer.pendingMask = gVctSendState.memberMask;
    gVctSendBuffer.pendingMask = gVctSendState.memberMask & ~(1 << gVctSession.localId);
    gVctSendBuffer.scheduleRow = MATH_CountPopulation(gVctSendBuffer.pendingMask) - 1;
    if (gVctSendBuffer.scheduleRow > 7)
        return 0;
    gVctSendBuffer.scheduleStep = 0;
    return frame;
}

/*
 * The last two arguments are one u64 (an OS tick, stored to the packet's
 * arrivalTick): split across r3 and the stack, which is what pulls the high
 * word into a register at entry.
 */
int VCT_AUDIO_ReceiveFrame(u32 senderAid, VctAudioFrame *frame, u32 size, u64 arrivalTick)
{
    VctRxPacket *packet;
    VctReceiveSource *source;
    int mode;
    u32 i;
    u8 *dst;

    source = 0;
    if (gVctSendState.memberCount == 0)
        return 0;

    for (i = 0; i < 3; i++) {
        if (senderAid == gVctReceiveSources[i].peerAid) {
            source = &gVctReceiveSources[i];
            break;
        }
    }
    if (source == 0)
        return 0;

    if (frame->type == 0x41) {
        source->noiseLevel = frame->seq;
        source->timestamp0 = 0;
        source->count = 1;
        return 0;
    }
    if (frame->type != 0x40)
        return 0;

    mode = frame->flags & 0x7f;
    source->codecMode = mode;
    if (mode >= 5)
        return 0;
    if (size != gVctFrameSpecs[mode].blocks * 0x44 + gVctFrameSpecs[mode].extraBytes + 0xc)
        return 0;
    if ((gVctSendState.memberMask & (senderAid != 0 ? 1 << senderAid : 1)) == 0)
        return 0;

    if ((packet = VCT_POOL_AllocFrame()) == 0) {
        VCT_AUDIO_FlushReadyQueue(source->queueIndex);
        VCT_AUDIO_FlushPendingSlot(source->queueIndex);
        if ((packet = VCT_POOL_AllocFrame()) == 0) {
            VCT_AUDIO_FlushAllReadyQueues();
            VCT_AUDIO_FlushPendingAll();
            packet = VCT_POOL_AllocFrame();
        }
        if (packet == 0)
            return 0;
    }

    dst = &packet->buffer[sizeof(packet->buffer)] - (size - 0xc);
    MI_CpuCopy8(frame->data, dst, size - 0xc);
    packet->queueIndex = source->queueIndex;
    packet->codecMode = mode;
    packet->payload = dst;
    packet->payloadSize = size - 0xc;
    packet->arrivalTick = arrivalTick;
    packet->senderAid = senderAid;
    packet->marker = frame->flags & 0x80;
    packet->timestamp = frame->timestamp;
    packet->seq = frame->seq;
    if (VCT_AUDIO_TrackPacketTiming(source, packet) == 0) {
        VCT_POOL_FreeFrame(packet);
        return 0;
    }
    VCT_AUDIO_QueuePending(packet);
    return 1;
}

/*
 * The three sample converters are passed packet->codecMode as a fourth
 * argument: the original keeps the format in r3 across the argument set-up
 * of all three calls, which only a live fourth argument reproduces (a plain
 * local or the bare field lands in r0).
 */
int VCT_AUDIO_DecodePendingFrames(void)
{
    VctRxPacket *head;
    int i;
    int count;
    u32 slot;
    int irq;
    VctRxPacket *packet;
    int mode;

    head = VCT_AUDIO_GetPendingHead();
    if (head == 0)
        return 0;

    irq = OS_DisableInterrupts();
    slot = head->queueIndex;
    count = VCT_AUDIO_GetPendingCount(slot);
    for (i = 0; i < count; i++) {
        packet = VCT_AUDIO_FindPending(slot);
        mode = packet->codecMode;
        if (mode >= 2)
            VCT_ADPCM_DecodePacket(packet->payload, packet->buffer, packet->payloadSize, mode);
        else if (mode == 1)
            VCT_AUDIO_DecodeMuLaw(packet->payload, (short int *)packet->buffer, packet->payloadSize);
        else
            VCT_AUDIO_ConvertPcm8ToPcm16(packet->payload, (short int *)packet->buffer, packet->payloadSize, mode);
        packet->payload = packet->buffer;
        VCT_AUDIO_UnlinkPending(packet);
        if (VCT_AUDIO_InsertReadyPacket(packet, packet->queueIndex) < 0)
            VCT_POOL_FreeFrame(packet);
    }
    OS_RestoreInterrupts(irq);
    return count;
}

static inline u32 countLeadingZeros(u32 x)
{
    asm { clz x, x }
    return x;
}

int VCT_AUDIO_SendFrameStep(void)
{
    int i;
    int count;
    u32 mask;
    u32 zeros;

    if (gVctSendState.memberCount == 0)
        return 1;

    if (gVctSendBuffer.sendFrame == 0) {
        gVctSendBuffer.sendFrame = VCT_AUDIO_EncodeSendFrame();
        if (gVctSendBuffer.sendFrame != 0 && gVctSendState.echoSuppressEnabled != 0)
            return 0;
        return 1;
    }

    count = 1;
    if (gVctSession.mode == 2)
        count = gVctSendSchedule[gVctSendBuffer.scheduleRow][gVctSendBuffer.scheduleStep++];

    for (i = 0; i < count; i++) {
        mask = gVctSendBuffer.pendingMask;
        zeros = countLeadingZeros(mask);
        if (zeros == 32)
            break;
        gVctSendBuffer.pendingMask = mask & ~(0x80000000 >> zeros);
        DWC_SendUnreliable((u8)(31 - zeros), gVctSendBuffer.sendFrame, gVctSendState.packetBytes);
        if (gVctSendBuffer.pendingMask == 0) {
            gVctSendBuffer.readCount++;
            gVctSendBuffer.sendFrame = 0;
            gVctSendBuffer.pendingMask = 0;
            break;
        }
    }
    return 1;
}

void VCT_AUDIO_ResetPendingList(void)
{
    int irq;
    int i;

    irq = OS_DisableInterrupts();
    gVctPendingList.tail = 0;
    gVctPendingList.head = 0;
    for (i = 0; i < 3; i++) {
        gVctPendingCount[i] = 0;
    }
    OS_RestoreInterrupts(irq);
}

void VCT_AUDIO_FlushPendingSlot(unsigned int slot)
{
    int irq;
    VctRxPacket *packet;

    irq = OS_DisableInterrupts();
    while ((packet = VCT_AUDIO_FindPending(slot)) != 0) {
        VCT_AUDIO_UnlinkPending(packet);
        VCT_POOL_FreeFrame(packet);
    }
    gVctPendingCount[slot] = 0;
    OS_RestoreInterrupts(irq);
}

void VCT_AUDIO_FlushPendingAll(void)
{
    int irq;
    int i;
    VctRxPacket *packet;
    VctRxPacket *current;

    irq = OS_DisableInterrupts();
    packet = gVctPendingList.head;
    while (packet != 0) {
        current = packet;
        packet = packet->next;
        VCT_POOL_FreeFrame(current);
    }
    gVctPendingList.head = 0;
    gVctPendingList.tail = 0;
    for (i = 0; i < 3; i++) {
        gVctPendingCount[i] = 0;
    }
    OS_RestoreInterrupts(irq);
}

int VCT_AUDIO_QueuePending(VctRxPacket *packet)
{
    int irq;

    irq = OS_DisableInterrupts();
    if (gVctPendingList.head == 0) {
        gVctPendingList.head = packet;
        packet->prev = 0;
        gVctPendingList.head->next = 0;
        gVctPendingList.tail = gVctPendingList.head;
    } else {
        packet->prev = gVctPendingList.tail;
        packet->next = 0;
        gVctPendingList.tail->next = packet;
        gVctPendingList.tail = packet;
    }
    gVctPendingCount[packet->queueIndex]++;
    OS_RestoreInterrupts(irq);
    return gVctPendingCount[packet->queueIndex];
}

/* Head of the list of received packets that wait for decoding. */
VctRxPacket *VCT_AUDIO_GetPendingHead(void)
{
    return gVctPendingList.head;
}

int VCT_AUDIO_GetPendingCount(unsigned int slot) { return gVctPendingCount[slot]; }

VctRxPacket *VCT_AUDIO_FindPending(u32 slot)
{
    VctRxPacket *packet = gVctPendingList.head;
    u32 irq = OS_DisableInterrupts();

    for (; packet; packet = packet->next) {
        if (packet->queueIndex == slot) {
            OS_RestoreInterrupts(irq);
            return packet;
        }
    }
    OS_RestoreInterrupts(irq);
    return 0;
}

u32 VCT_AUDIO_UnlinkPending(VctRxPacket *packet)
{
    u32 irq = OS_DisableInterrupts();

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
    OS_RestoreInterrupts(irq);
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
    u32 irq = OS_DisableInterrupts();
    gVctReadyTail[slot] = 0;
    gVctReadyHead[slot] = 0;
    gVctReadyCount[slot] = 0;
    OS_RestoreInterrupts(irq);
}

void VCT_AUDIO_FlushReadyQueue(u32 slot)
{
    VctRxPacket *packet;
    u32 irq = OS_DisableInterrupts();

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
    OS_RestoreInterrupts(irq);
}

void VCT_AUDIO_FlushAllReadyQueues(void)
{
    int slot;
    VctRxPacket *packet;
    u32 irq = OS_DisableInterrupts();

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
    OS_RestoreInterrupts(irq);
}

int VCT_AUDIO_InsertReadyPacket(VctRxPacket *packet, u32 slot)
{
    int irq;
    VctRxPacket *cur;

    if (packet == 0)
        return -1;
    if (slot >= 3)
        return -1;

    irq = OS_DisableInterrupts();
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
    OS_RestoreInterrupts(irq);
    return gVctReadyCount[slot];
}

void *VCT_AUDIO_PeekReadyPacket(unsigned int slot)
{
    u32 irq = OS_DisableInterrupts();
    if (gVctReadyHead[slot] != 0) {
        OS_RestoreInterrupts(irq);
        return gVctReadyHead[slot];
    }
    OS_RestoreInterrupts(irq);
    return 0;
}

VctRxPacket *VCT_AUDIO_PopReadyPacket(u32 slot)
{
    VctRxPacket *packet;
    u32 irq = OS_DisableInterrupts();

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
    OS_RestoreInterrupts(irq);
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

VctRxPacket *VCT_AUDIO_SetLastPacket(VctReceiveSource *source, VctRxPacket *packet)
{
    if (source->lastPacket)
        VCT_POOL_FreeFrame(source->lastPacket);
    source->lastPacket = packet;
    return VCT_AUDIO_PopReadyPacket(source->queueIndex);
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
    now = OS_GetTick();
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
    VCT_SESSION_InitPacketHeader(peer, (struct VctPacket *)buffer, type & 0xff);
    if (VCT_SESSION_CheckCommandAllowed(peer, (struct VctPacket *)buffer) == 0)
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
    VCT_SESSION_InitPacketHeader(peer, (struct VctPacket *)buffer, type & 0xff);
    if (type == 0) {
        if (gVctSession.mode == 1 && peer->phase == 4) {
            if (VCT_SESSION_HasNoOtherTalker(peer) == 0)
                return zero - 3;
        }
        peer->memberMask = peer->peerId ? 1 << peer->peerId : 1;
    }
    if (VCT_SESSION_CheckCommandAllowed(peer, (struct VctPacket *)buffer) == 0)
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
    gVctPeerPool.tickFunc = (void *)OS_GetTick;
    gVctPeerPool.rngMul = 0x5D588B65;
    gVctPeerPool.rngAdd = 0x269EC3;
    return 1;
}

/* Empty the free and active peer lists of the peer pool. */
void VCT_SESSION_ResetPeerPool(void)
{
    gVctPeerPool.activeHead = 0;
    gVctPeerPool.freePeers = 0;
}
