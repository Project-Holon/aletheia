/*
 * file:     unit_021B0D18.c
 * unit:     yes
 * function: VCT_AUDIO_EncodeSendFrame, VCT_AUDIO_ReceiveFrame, VCT_AUDIO_DecodePendingFrames, VCT_AUDIO_SendFrameStep, VCT_AUDIO_ResetPendingList, VCT_AUDIO_FlushPendingSlot, VCT_AUDIO_FlushPendingAll, VCT_AUDIO_QueuePending
 * address:  0x021B0D18
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
 *   gVctSendBuffer  0x021B42C0  data  ov013  a4
 *   gVctSendState  0x021B3C84  data  ov013  a4
 *   gVctSendEnabled  0x021B3C24  data  ov013  a4
 *   gVctAudioStateAdpcm  0x021B3C94  data  ov013  a4
 *   gVctSession  0x021B60D8  data  ov013  a1
 *   VCT_DSP_HighPassFilter  0x021B3278  arm  ov013
 *   VCT_DSP_SuppressEchoWithReference  0x021B3604  arm  ov013
 *   VCT_DSP_UpdateVoiceGate  0x021B3084  arm  ov013
 *   VCT_ADPCM_EncodePacket  0x021B04A8  arm  ov013
 *   VCT_AUDIO_EncodeMuLaw  0x021B1588  arm  ov013
 *   VCT_AUDIO_ConvertPcm16ToPcm8  0x021B1688  arm  ov013
 *   func_02080D24  0x02080D24  arm
 *   gVctReceiveSources  0x021B3CBC  data  ov013  a4
 *   gVctFrameSpecs  0x021B3AD0  data  ov013  a1
 *   VCT_POOL_AllocFrame  0x021B2FB0  arm  ov013
 *   VCT_AUDIO_FlushReadyQueue  0x021B1720  arm  ov013
 *   VCT_AUDIO_FlushAllReadyQueues  0x021B1790  arm  ov013
 *   VCT_AUDIO_TrackPacketTiming  0x021B1B94  arm  ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   MI_CpuCopy8  0x02082D44  arm
 *   VCT_AUDIO_GetPendingHead  0x021B1488  arm  ov013
 *   VCT_AUDIO_GetPendingCount  0x021B1498  arm  ov013
 *   VCT_AUDIO_FindPending  0x021B14A8  arm  ov013
 *   VCT_ADPCM_DecodePacket  0x021B043C  arm  ov013
 *   VCT_AUDIO_DecodeMuLaw  0x021B1634  arm  ov013
 *   VCT_AUDIO_ConvertPcm8ToPcm16  0x021B16B4  arm  ov013
 *   VCT_AUDIO_UnlinkPending  0x021B14F8  arm  ov013
 *   VCT_AUDIO_InsertReadyPacket  0x021B1810  arm  ov013
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gVctSendSchedule  0x021B3ADA  data  ov013  a1
 *   func_02177044  0x02177044  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021B4B98     0x021B4B98  data  a4
 *   g_021B4BA0     0x021B4BA0  data  a4
 *   gVctPendingList  0x021B4B98  data
 *   gVctPendingCount  0x021B4BA0  data
 */
#include "vct_types.h"

#define reg_SQRTCNT     (*(volatile u16 *)0x040002B0)
#define reg_SQRT_RESULT (*(volatile u32 *)0x040002B4)
#define reg_SQRT_PARAM  (*(volatile u32 *)0x040002B8)

extern int VCT_DSP_HighPassFilter(short *samples, u32 byteCount);
extern void VCT_DSP_SuppressEchoWithReference(short *samples, u32 byteCount, u32 rms);
extern int VCT_DSP_UpdateVoiceGate(u32 energy, u32 rms, u8 *outFlag);
extern void VCT_ADPCM_EncodePacket(AdpcmHeader *header, void *dst, int sampleCount, AdpcmState *state, int mode);
extern void VCT_AUDIO_EncodeMuLaw(unsigned char *dst, const short *src, unsigned int sampleCount);
extern void VCT_AUDIO_ConvertPcm16ToPcm8(u8 *dst, short *src, u32 sampleCount);
extern u8 func_02080D24(u32 mask);
extern VctRxPacket *VCT_POOL_AllocFrame(void);
extern void VCT_AUDIO_FlushReadyQueue(u32 slot);
extern void VCT_AUDIO_FlushAllReadyQueues(void);
extern int VCT_AUDIO_TrackPacketTiming(VctReceiveSource *source, VctRxPacket *packet);
extern void VCT_POOL_FreeFrame(VctRxPacket *packet);
extern void MI_CpuCopy8(void *src, void *dst, u32 size);
extern VctRxPacket *VCT_AUDIO_GetPendingHead(void);
extern int VCT_AUDIO_GetPendingCount(unsigned int slot);
extern VctRxPacket *VCT_AUDIO_FindPending(u32 slot);
extern void VCT_ADPCM_DecodePacket(AdpcmState *state, void *dst, int sampleCount, int mode);
extern void VCT_AUDIO_DecodeMuLaw(unsigned char *src, short *dst, unsigned int sampleCount);
extern void VCT_AUDIO_ConvertPcm8ToPcm16(signed char *src, short *dst, unsigned int sampleCount, int mode);
extern u32 VCT_AUDIO_UnlinkPending(VctRxPacket *packet);
extern int VCT_AUDIO_InsertReadyPacket(VctRxPacket *packet, u32 slot);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);
extern int func_02177044(unsigned char aid, void *buffer, int size);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
VctAudioFrame *VCT_AUDIO_EncodeSendFrame(void);
int VCT_AUDIO_ReceiveFrame(u32 senderAid, VctAudioFrame *frame, u32 size, u64 arrivalTick);
int VCT_AUDIO_DecodePendingFrames(void);
int VCT_AUDIO_SendFrameStep(void);
void VCT_AUDIO_ResetPendingList(void);
void VCT_AUDIO_FlushPendingSlot(unsigned int slot);
void VCT_AUDIO_FlushPendingAll(void);
int VCT_AUDIO_QueuePending(VctRxPacket *packet);
/* gVctAudioStateAdpcm is gVctSendState + 0x10 (adpcmPredictor): the pool word names it separately. */
extern AdpcmState gVctAudioStateAdpcm;
extern u8 gVctSendSchedule[][3];




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
    gVctSendBuffer.scheduleRow = func_02080D24(gVctSendBuffer.pendingMask) - 1;
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
        func_02177044((u8)(31 - zeros), gVctSendBuffer.sendFrame, gVctSendState.packetBytes);
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
