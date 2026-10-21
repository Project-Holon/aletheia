/*
 * file:     vct_mixer.c
 * unit:     yes
 * function: VCT_MIXER_Init, VCT_MIXER_ClearMemberCount, VCT_MIXER_AddMember, VCT_MIXER_RemoveMember, VCT_MIXER_QueueFrame, VCT_MIXER_ReadChannel, VCT_MIXER_MixVoices, VCT_MIXER_SetCodecMode, VCT_MIXER_SetSendEnabled, VCT_MIXER_SetFilterEnabled
 * address:  0x021B0508
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vct_main.c, vct_audio.c, vct_session.c, vct_dsp.c by tools/splitfile.py.
 *
 * symbols:
 *   VCT_MIXER_SetSendEnabled  0x021B0CD8  arm ov013
 *   MIi_CpuClearFastAlias  0x02082AC0  arm
 *   VCT_MIXER_SetFilterEnabled  0x021B0D08  arm ov013
 *   VCT_MIXER_MixVoices  0x021B0B48  arm ov013
 *   VCT_MIXER_QueueFrame  0x021B07F8  arm ov013
 *   VCT_MIXER_AddMember  0x021B0614  arm ov013
 *   VCT_MIXER_RemoveMember  0x021B074C  arm ov013
 *   OS_GetTick  0x020870D0  arm
 *   VCT_MIXER_SetCodecMode  0x021B0C64  arm ov013
 *   gVctSendState     0x021B3C84  data ov013 a4
 *   gVctSendEnabled     0x021B3C24  data ov013 a4
 *   gVctSession     0x021B60D8  data ov013 a4
 *   gVctFrameSpecs     0x021B3AD0  data ov013 a1
 *   gVctSendBuffer     0x021B42C0  data ov013 a4
 *   gVctMembers     0x021B3CB0  data ov013 a4
 *   gVctReceiveSources     0x021B3CBC  data ov013 a4
 *   OS_GetTickLo  0x02087170  arm
 *   VCT_DSP_InitVoiceGateDefaults  0x021B3250  arm ov013
 *   VCT_AUDIO_ClearReadyQueue  0x021B16E4  arm ov013
 *   VCT_AUDIO_InitReceiveSource  0x021B19BC  arm ov013
 *   VCT_AUDIO_ResetPendingList  0x021B12FC  arm ov013
 *   VCT_DSP_InitEchoState  0x021B3364  arm ov013
 *   VCT_DSP_ResetVoiceGate  0x021B3018  arm ov013
 *   VCT_AUDIO_DetachReceiveSource  0x021B1A48  arm ov013
 *   VCT_AUDIO_FlushReadyQueue  0x021B1720  arm ov013
 *   VCT_AUDIO_FlushPendingSlot  0x021B133C  arm ov013
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   VCT_AUDIO_GetReadyCount  0x021B19AC  arm ov013
 *   VCT_AUDIO_PeekReadyPacket  0x021B190C  arm ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm ov013
 *   VCT_AUDIO_SetLastPacket  0x021B1A74  arm ov013
 *   gVctMixScratch     0x021B3E78  data ov013 a4
 *   VCT_MIXER_ReadChannel  0x021B0904  arm ov013
 *   VCT_DSP_MixSaturated  0x021B3624  arm ov013
 *   VCT_DSP_SetEchoReference  0x021B33E0  arm ov013
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   VCT_MIXER_Init  0x021B0508  arm ov013
 *   VCT_MIXER_ClearMemberCount  0x021B0600  arm ov013
 *   _ll_udiv                     0x0209C00C  arm
 */
#include "vct_types.h"

/* Memory, time and error helpers. */

#include "../arm9/mi_memory.h"

typedef unsigned long long OSTick;
#include "../arm9/os_tick.h"


#include "vct_dsp.h"

#include "vct_audio.h"
struct VctReceiveSource;






#include "vct_pool.h"








extern void VCT_MIXER_SetSendEnabled(int enabled);

extern void VCT_MIXER_SetFilterEnabled(int enabled);

/* Two names for 0x02082AC0: see VCT_MIXER_MixVoices. */

int VCT_MIXER_Init(void);

void VCT_MIXER_ClearMemberCount(void);

int VCT_MIXER_AddMember(VctPeer *peer);

void VCT_MIXER_RemoveMember(VctPeer *peer);

int VCT_MIXER_QueueFrame(const u8 *src, u32 length);

int VCT_MIXER_ReadChannel(void *dst, u32 size, u32 channelIndex, u32 *sourceMask);

int VCT_MIXER_MixVoices(void *output, u32 length, u32 *sourceMask);

int VCT_MIXER_SetCodecMode(int codecMode);

extern VctPeer *gVctMembers[3];

extern s16 gVctMixScratch[];

#pragma thumb off

/* Packet bytes (12 byte header included) of one frame at the given codec mode. */
static inline u32 GetPacketBytes(u32 codecMode)
{
    const VctFrameSpec *spec;
    u32 blocks;
    blocks = gVctFrameSpecs[codecMode].blocks;
    spec = &gVctFrameSpecs[codecMode];
    return blocks * 0x44 + spec->extraBytes + 0xC;
}

/*
 * Initialize the transmit state: sequence start from the tick counter,
 * transmit on, no members, default codec mode, the send buffer indexes and
 * the three member slots.
 * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The codecMode store is written in
 * each arm of the mode if/else (the join no longer splits the 3C84 pointer, codecMode goes through the
 * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which
 * gives the later-born address temp the lower register (r1) and the table base r2, so the table
 * load stays below the f1C store.
 */
int VCT_MIXER_Init(void)
{
    u32 i;
    u32 codecMode;

    gVctSendState.sequence = OS_GetTickLo();
    gVctSendEnabled = 1;
    gVctSendState.memberCount = 0;
    gVctSendState.memberMask = 0;
    codecMode = 0;
    if (gVctSession.mode != 1) {
        codecMode = 4;
        gVctSendState.codecMode = codecMode;
    } else {
        gVctSendState.codecMode = codecMode;
    }
    gVctSendState.frameBytes = VCT_FRAME_BYTES;
    gVctSendState.packetBytes = GetPacketBytes(codecMode);
    gVctSendBuffer.readCount = 0;
    gVctSendBuffer.writeCount = 0;
    gVctSendBuffer.pendingMask = 0;
    gVctSendBuffer.sendFrame = 0;
    gVctSendBuffer.scheduleStep = 0;
    gVctSendBuffer.scheduleRow = 0;
    VCT_DSP_InitVoiceGateDefaults();
    for (i = 0; (i < VCT_MAX_MEMBERS) ? 1 : 0; i++) {
        gVctMembers[i] = 0;
        VCT_AUDIO_ClearReadyQueue(i);
        VCT_AUDIO_InitReceiveSource(&gVctReceiveSources[i], i, -1);
    }
    VCT_AUDIO_ResetPendingList();
    VCT_DSP_InitEchoState();
    return 1;
}

/* Forget all members (the member slots themselves are cleared by the engine shutdown). */
void VCT_MIXER_ClearMemberCount(void) { gVctSendState.memberCount = 0; }

/*
 * Register a peer as a chat member: needs a free slot and phase 2 or 3.
 * Returns 1 when the peer is a member afterwards. The first member joined
 * in phase 2 resets the encoder, the gate and the send buffer indexes.
 */
#pragma opt_lifetimes off

int VCT_MIXER_AddMember(VctPeer *peer)
{
    u32 slotIndex;

    if (peer == 0) {
        return 0;
    }
    if (gVctSendState.memberCount == VCT_MAX_MEMBERS) {
        return 0;
    }
    if (peer->phase != 2 && peer->phase != 3) {
        return 0;
    }
    for (slotIndex = 0; (slotIndex < VCT_MAX_MEMBERS) ? 1 : 0; slotIndex++) {
        if (gVctMembers[slotIndex] == peer) {
            return 1;
        }
    }
    for (slotIndex = 0; (slotIndex < VCT_MAX_MEMBERS) ? 1 : 0; slotIndex++) {
        if (gVctMembers[slotIndex] == 0) {
            gVctMembers[slotIndex] = peer;
            break;
        }
    }
    gVctSendState.memberCount++;
    gVctSendState.memberMask |= peer->memberMask;
    VCT_AUDIO_InitReceiveSource(&gVctReceiveSources[slotIndex], slotIndex, peer->floorHolderId);
    VCT_AUDIO_ClearReadyQueue(slotIndex);
    if (peer->phase != 2) {
        return 1;
    }
    if (gVctSendState.memberCount == 1) {
        VCT_DSP_ResetVoiceGate();
        gVctSendState.sequence = OS_GetTickLo();
        gVctSendState.adpcmPredictor = 0;
        gVctSendState.adpcmStepIndex = 0;
        gVctSendState.markerRequest = 1;
        gVctSendBuffer.readCount = 0;
        gVctSendBuffer.writeCount = 0;
        gVctSendBuffer.pendingMask = 0;
        gVctSendBuffer.sendFrame = 0;
        gVctSendBuffer.scheduleStep = 0;
        gVctSendBuffer.scheduleRow = 0;
    }
    return 1;
}

#pragma opt_lifetimes reset

/* Remove a peer from the members; the last member leaving resets the gate and the member mask. */
#pragma opt_propagation off

void VCT_MIXER_RemoveMember(VctPeer *peer)
{
    u32 slotIndex;
    int oldCount;
    VctPeer *nullPeer;
    slotIndex = 0;
    do {
        if(gVctMembers[slotIndex]==peer) {
            nullPeer = 0;
            oldCount = gVctSendState.memberCount;
            gVctMembers[slotIndex]=nullPeer;
            gVctSendState.memberCount = oldCount - 1;
            VCT_AUDIO_DetachReceiveSource(&gVctReceiveSources[slotIndex]);
            VCT_AUDIO_FlushReadyQueue(slotIndex);
            VCT_AUDIO_FlushPendingSlot(slotIndex);
            gVctSendState.memberMask &= ~peer->memberMask;
            break;
        }
        slotIndex++;
    } while(slotIndex<VCT_MAX_MEMBERS);
    if(gVctSendState.memberCount==0) {
        gVctSendState.markerRequest=1;
        VCT_DSP_ResetVoiceGate();
        gVctSendState.memberMask=0;
    }
}

#pragma opt_propagation reset

#pragma opt_propagation off

/*
 * Queue one microphone frame (length must be the frame size) into the next
 * send buffer slot and stamp its header (magic, tick divisor, sequence,
 * timestamp). Returns 1 when queued; 0 when the length is wrong, there is
 * no member, or no member is in phase 2.
 *
 * pass 3 2026-10-06 P3L09: closed. The codec mode field is read through a const pointer to the shared
 * state (`const VctSendState *sendState = &gVctSendState; if (sendState->codecMode >= 2)`). A const load has no memory
 * dependence on the header magic store, so the scheduler issues moveq before the f1C load
 * (idiom a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer). The rest is the
 * G7L4 form: opt_propagation off, `(i < 3) ? 1 : 0` while loop, magic and divisor as named locals.
 */
int VCT_MIXER_QueueFrame(const u8 *src, u32 length)
{
  VctAudioFrame *header;
  u32 i;
  u8 frameType;
  u32 slotOffset;
  u8 hasJoinedMember;
  u16 sequence;
  u32 magic;
  const VctSendState *sendState;
  hasJoinedMember = 0;
  if (length != gVctSendState.frameBytes)
  {
    return 0;
  }
  if (gVctSendState.memberCount == 0)
  {
    return 0;
  }
  i = 0;
  while ((i < VCT_MAX_MEMBERS) ? (1) : (0))
  {
    if ((0 != gVctMembers[i]) && (gVctMembers[i]->phase == 2))
    {
      hasJoinedMember = 1;
      break;
    }
    i++;
  }
  if (hasJoinedMember == 0)
  {
    return 0;
  }
  slotOffset = (gVctSendBuffer.writeCount & 1) ? 0 : VCT_PACKET_SLOT_BYTES;
  header = (VctAudioFrame *) ((u8 *) &gVctSendBuffer + slotOffset);
  magic = VCT_PACKET_MAGIC;
  header->magic = magic;
  sendState = &gVctSendState;
  if (sendState->codecMode >= 2)
  {
    MIi_CpuCopyFast(src, ((u8 *) header) + 0x10, length);
  }
  else
  {
    MIi_CpuCopyFast(src, ((u8 *) header) + 0xC, length);
  }
  frameType = 0x40;
  header->type = frameType;
  sequence = gVctSendState.sequence;
  gVctSendState.sequence = gVctSendState.sequence + 1;
  header->seq = sequence;
  header->timestamp = (u32) (OS_GetTick() / (u32)frameType);
  gVctSendBuffer.writeCount++;
  return 1;
}

#pragma opt_propagation reset

/*
 * Take one queued packet for member channel channelIndex (0x94-byte
 * channels at 0x021B3CBC). Compares the packet's u64 due tick at +0x46C
 * against the tick count: more than 0x34 ahead falls back to the channel's
 * held packet at +0x3C, more than 0x8B4C behind is released and the loop
 * retries; otherwise it counts sequence gaps (lostPacketCount), updates
 * the delay estimate from the tick difference to the sent tick at +0x464,
 * copies the samples (+0x474) to dst and sets the sender's bit in
 * *sourceMask.
 * VCT_AUDIO_SetLastPacket is void in its own file, but this caller loops on the
 * r0 it leaves behind (mov r4, r0 after each call), so it is declared
 * int here.
 */
int VCT_MIXER_ReadChannel(void *dst, u32 size, u32 channelIndex, u32 *sourceMask)
{
    int queuedCount;
    VctRxPacket *packet;
    VctReceiveSource *channel;
    int isFirstTry;
    u64 nowTick;
    u32 delay;
    u32 delayDelta;

    channel = &gVctReceiveSources[channelIndex];
    isFirstTry = 1;
    queuedCount = VCT_AUDIO_GetReadyCount(channelIndex);
    while (queuedCount != 0) {
        nowTick = OS_GetTick();
        packet = VCT_AUDIO_PeekReadyPacket(channelIndex);
        if (packet != 0) {
            if (packet->playTick > nowTick + 0x34) {
                if (packet->marker == 0 && channel->lastPacket != 0) {
                    channel->playedFrames++;
                    MIi_CpuCopyFast(channel->lastPacket->payload, dst, size);
                    VCT_POOL_FreeFrame(channel->lastPacket);
                    channel->lastPacket = 0;
                    if (sourceMask != 0) {
                        *sourceMask |= 1 << packet->senderAid;
                    }
                    return 1;
                }
                return 0;
            }
            if (nowTick > packet->playTick + 0x8B4C) {
                channel->lastPlayedSeq = packet->seq;
                queuedCount = (sptr)VCT_AUDIO_SetLastPacket(channel, packet);
                VCT_AUDIO_PeekReadyPacket(channelIndex);
                isFirstTry = 0;
                continue;
            }
            if (channel->lastPlayedSeq + 1 != packet->seq && channel->lastPlayedSeq != 0 && channel->lastPlayedSeq <= packet->seq) {
                if (packet->marker == 0) {
                    channel->dropped++;
                }
            }
            channel->lastPlayedSeq = packet->seq;
            if (isFirstTry != 0 && channel->pendingSkips != 0) {
                queuedCount = (sptr)VCT_AUDIO_SetLastPacket(channel, packet);
                VCT_AUDIO_PeekReadyPacket(channelIndex);
                channel->pendingSkips--;
                continue;
            }
            delay = (u32)(nowTick - packet->arrivalTick);
            delayDelta = delay - channel->lastLatency;
            channel->lastLatency = delay;
            channel->latencyFilter = channel->lastLatency + ((delayDelta - channel->lastLatency) >> 4);
            channel->latency = channel->latencyFilter;
            MIi_CpuCopyFast(packet->payload, dst, size);
            VCT_AUDIO_SetLastPacket(channel, packet);
            if (sourceMask != 0) {
                *sourceMask |= 1 << packet->senderAid;
            }
            return 1;
        } else {
            channel->queueDepth = queuedCount;
            return 0;
        }
    }
    if (channel->lastPacket != 0) {
        VCT_POOL_FreeFrame(channel->lastPacket);
        channel->lastPacket = 0;
    }
    return 0;
}

/*
 * Mix the voices of all members into output (length bytes): the first
 * member that delivers a packet fills output, the later ones are decoded
 * into a scratch buffer and added. With no members or a wrong length the
 * output is cleared. *sourceMask receives the senders that contributed.
 *
 * The two MIi_CpuClearFast calls (found==0 arm, failed-guard arm) are
 * kept apart in the original; under one extern name 1.1p1 cross-jumps the
 * two `bl`s into one (4 bytes short, see docs/notes/pkt_ov013_021B0B48.c.txt).
 * Two extern names for 0x02082AC0 (MIi_CpuClearFast and MIi_CpuClearFastAlias)
 * give two independent call sites, the
 * call-site form of
 * docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 * `j = i + 1; if (j == 3) ret = 1; else for (...)` is what gives the
 * original's `cmp sb,#3; moveq r4,#1; beq; bhs`.
 */
int VCT_MIXER_MixVoices(void *output, u32 length, u32 *sourceMask)
{
    int mixed;
    u32 i;
    u32 next;

    if (sourceMask != 0)
        *sourceMask = 0;

    mixed = 0;
    if (length == gVctSendState.frameBytes && gVctSendState.memberCount != 0) {
        for (i = 0; i < VCT_MAX_MEMBERS; i++) {
            if (VCT_MIXER_ReadChannel(output, length, i, sourceMask) == 1) {
                mixed = 1;
                break;
            }
        }
        if (mixed != 0) {
            next = i + 1;
            if (next == VCT_MAX_MEMBERS) {
                mixed = 1;
            } else {
                for (; next < VCT_MAX_MEMBERS; next++) {
                    if (VCT_MIXER_ReadChannel(gVctMixScratch, length, next, sourceMask) == 1)
                        VCT_DSP_MixSaturated(output, gVctMixScratch, output, length);
                }
            }
        } else {
            MIi_CpuClearFast(0, output, length);
        }
    } else {
        mixed = 0;
#ifdef __MWERKS__
        MIi_CpuClearFastAlias(mixed, output, length);
#else
        MIi_CpuClearFast(mixed, output, length);
#endif
    }

    if (gVctSendState.echoSuppressEnabled != 0)
        VCT_DSP_SetEchoReference(output, length);
    return mixed;
}

/* Select the codec mode (0 to 4; modes 0 and 1 need engine mode 1) and reset the encoder. Returns 1 on success. */
int VCT_MIXER_SetCodecMode(int codecMode)
{
    if (codecMode >= 5) {
        return 0;
    }
    if (gVctSession.mode != 1 && (unsigned)codecMode <= 1) {
        return 0;
    }
    gVctSendState.packetBytes = gVctFrameSpecs[codecMode].blocks * 0x44 + gVctFrameSpecs[codecMode].extraBytes + 0xC;
    gVctSendState.codecMode = codecMode;
    gVctSendState.adpcmPredictor = 0;
    gVctSendState.adpcmStepIndex = 0;
    return 1;
}

/* Enable or disable sending; the gate is reset and a disable asks the sender to mute. */
void VCT_MIXER_SetSendEnabled(int enabled)
{
    gVctSendEnabled = enabled;
    VCT_DSP_ResetVoiceGate();
    if (enabled == 0) gVctSendState.markerRequestNoVad = 1;
}

/* Switch the echo suppression stage of the voice chat on or off. */
void VCT_MIXER_SetFilterEnabled(int enabled)
{
    gVctSendState.echoSuppressEnabled = enabled;
}
