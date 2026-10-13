/*
 * function: SCRCMD_MSGWIN_CmdCloseBgWin
 * address:  0x021B13E0
 * packet:   pkt_021B13E0
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
 *   SCRCMD_MSGWIN_CloseBgWin  0x021B1268  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void SCRCMD_MSGWIN_CloseBgWin(void *p);

int SCRCMD_MSGWIN_CmdCloseBgWin(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_MSGWIN_CloseBgWin((void *)b);
return 0;
}

