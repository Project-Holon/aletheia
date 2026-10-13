/*
 * function: SCRCMD_SCREENEFFECTS_CheckBrightnessDone
 * address:  0x021B2860
 * packet:   pkt_021B2860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FADE_IsActive  0x0204E804  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FADE_IsActive(void);

int SCRCMD_SCREENEFFECTS_CheckBrightnessDone(u32 a, u32 b, u32 c, u32 d)
{
if (FADE_IsActive() != 1) {
    return 1;
}
return 0;
}

