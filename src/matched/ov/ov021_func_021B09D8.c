/*
 * function: SCRCMD_MSGWIN_GetBalloonOffset
 * address:  0x021B09D8
 * packet:   pkt_ov021_021B09D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_MSGWIN_SelectBalloonOffset  0x021B0960  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void SCRCMD_MSGWIN_SelectBalloonOffset(u32 a, u32 b, u32 c, u32 d, u8 e);

void SCRCMD_MSGWIN_GetBalloonOffset(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    SCRCMD_MSGWIN_SelectBalloonOffset(a, b, c, d, e);
}
