/*
 * function: VCT_DSP_ResetVoiceGate
 * address: 0x021B3018
 * packet: pkt_ov013_021B3018
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * note 2026-10-06 (integrator): volatile f0 fields accepted by the user (f0 is a flag shared with the mic callback).
 * lever: the f0 flag words of both state structs are volatile. Two volatile stores keep their order
 *   against each other, which places the gVoiceGateConfig pool load after the first gVoiceGateState store.
 *   All 120 plain store orders stay at 2 B or more; int/unsigned/pointer types and chained stores
 *   do not move the load. The same declarations bring the sibling 021B3084 from 17 to 15 B off.
 * note pass 2 2026-10-06 P2L01: closed (EXACT in --lang c99 and --lang c). Earlier forms in the
 *   pending header (G2L8, G10L10, P21 L6) stayed at 2 to 6 B.
 * symbols:
 *   gVoiceGateEnergyRing 0x021B4C38 data a4
 *   gVoiceGateState 0x021B4C2C data a4
 *   gVoiceGateConfig 0x021B3C50 data a4
 */
typedef int s32;
typedef unsigned int u32;

typedef struct VadCfg { volatile u32 f0; u32 f4; s32 f8; } VadCfg;
typedef struct VadState { volatile u32 f0; u32 f4; s32 f8; } VadState;

extern u32 gVoiceGateEnergyRing[];
extern VadState gVoiceGateState;
extern VadCfg gVoiceGateConfig;

void VCT_DSP_ResetVoiceGate(void)
{
    int i;
    for (i = 0; i < 4; i++) gVoiceGateEnergyRing[i] = 0x1000000;
    gVoiceGateState.f4 = 0;
    gVoiceGateState.f0 = 0;
    gVoiceGateConfig.f0 = 0;
    gVoiceGateConfig.f4 = 0;
    gVoiceGateState.f8 = 0;
}
