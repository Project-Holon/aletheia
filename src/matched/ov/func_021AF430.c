/*
 * function: SCRCMD_WaitPokeVoice
 * address:  0x021AF430
 * packet:   pkt_021AF430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * SCRCMD_WORK_GetFadeParam (0x0215A6AC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetFadeParam  0x0215A6AC  thumb
 *   PM_VOICE_IsActive  0x02006BD0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 PM_VOICE_IsActive(u32);
extern u32 SCRCMD_WORK_GetFadeParam(u32, u32, u32, u32);

int SCRCMD_WaitPokeVoice(u32 a, u32 b, u32 c, u32 d)
{
if (PM_VOICE_IsActive(SCRCMD_WORK_GetFadeParam(b, b, c, d)) == 0) {
    return 1;
}
return 0;
}

