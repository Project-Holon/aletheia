/*
 * function: CTVT_ADPCM_ResetEncoder
 * address: 0x021B69E0
 * packet: pkt_ov172_021B69E0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Clear the halfword at +4 and the byte at +6 of the ov172 state block. Filed
 * as the call witness for ov172 CTVT_TALK_UpdateVoiceSend.
 *
 * symbols:
 *   gCtvtAdpcmState 0x021C88E4 data a4 ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct D021C88E4 {
    u8 pad0[4];
    u16 h4;
    u8 b6;
};

extern struct D021C88E4 gCtvtAdpcmState;

void CTVT_ADPCM_ResetEncoder(void)
{
    gCtvtAdpcmState.h4 = 0;
    gCtvtAdpcmState.b6 = 0;
}
