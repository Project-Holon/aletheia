/*
 * function: SCRCMD_MSGWIN_CmdClosePlainWin
 * address:  0x021B10E8
 * packet:   pkt_021B10E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_MSGWIN_ClosePlainWin  0x021B10A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void SCRCMD_MSGWIN_ClosePlainWin(void *p);

int SCRCMD_MSGWIN_CmdClosePlainWin(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_MSGWIN_ClosePlainWin((void *)b);
return 0;
}

