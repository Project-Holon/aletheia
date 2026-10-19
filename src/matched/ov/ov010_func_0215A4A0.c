/*
 * function: EVENT_TRAINER_IsSecondaryScriptId
 * address:  0x0215A4A0
 * packet:   pkt_ov010_0215A4A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (blocker of ov021 SCRCMD_GetTrainerMessageIds).
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

u32 EVENT_TRAINER_IsSecondaryScriptId(u32 a)
{
    return a >= 5000;
}
