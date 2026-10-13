/*
 * function: VCT_SESSION_RemoveMember
 * address: 0x021B074C
 * packet: pkt_ov013_021B074C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * Remove request from its slot; clear mask and shut down an empty session.
 * final push 2026-10-05 G5L4: closed. The counter is read into a local before the slot clear and
 * written back after it, under opt_propagation off (otherwise the load sinks below the slot store).
 * A do-while loop avoids the entry guard that propagation off adds to the for form. The clear value
 * is a named local set before the counter read, so the zero is born before the counter value
 * (zero r2, counter r1).
 * symbols:
 *   gVctMembers 0x021B3CB0 data ov013 a4
 *   d_021B3CBC 0x021B3CBC data ov013 a4
 *   d_021B3C84 0x021B3C84 data ov013 a4
 *   VCT_AUDIO_DetachReceiveSource 0x021B1A48 arm ov013
 *   VCT_AUDIO_FlushReadyQueue 0x021B1720 arm ov013
 *   VCT_AUDIO_FlushPendingSlot 0x021B133C arm ov013
 *   VCT_DSP_ResetVoiceGate 0x021B3018 arm ov013
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u8 pad0[8]; u32 f8; } Req;
typedef struct { u8 pad0[4]; u32 f4; u8 pad8[12]; int f14; u8 pad18[8]; int f20; } Ctx;
extern Req *gVctMembers[3];
extern char d_021B3CBC[];
extern Ctx d_021B3C84;
extern void VCT_AUDIO_DetachReceiveSource(char *p);
extern void VCT_AUDIO_FlushReadyQueue(u32 i);
extern void VCT_AUDIO_FlushPendingSlot(u32 i);
extern void VCT_DSP_ResetVoiceGate(void);
#pragma opt_propagation off
void VCT_SESSION_RemoveMember(const Req *p)
{
    u32 i;
    int n;
    Req *z;
    i = 0;
    do {
        if(gVctMembers[i]==p) {
            z = 0;
            n = d_021B3C84.f20;
            gVctMembers[i]=z;
            d_021B3C84.f20 = n - 1;
            VCT_AUDIO_DetachReceiveSource(d_021B3CBC+i*0x94);
            VCT_AUDIO_FlushReadyQueue(i);
            VCT_AUDIO_FlushPendingSlot(i);
            d_021B3C84.f4 &= ~p->f8;
            break;
        }
        i++;
    } while(i<3);
    if(d_021B3C84.f20==0) {
        d_021B3C84.f14=1;
        VCT_DSP_ResetVoiceGate();
        d_021B3C84.f4=0;
    }
}
#pragma opt_propagation reset
