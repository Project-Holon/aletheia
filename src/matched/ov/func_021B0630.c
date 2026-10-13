/*
 * function: SCRCMD_MSGWIN_CleanupInfoSysWin
 * address:  0x021B0630
 * packet:   pkt_021B0630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   SCRCMD_MSGWIN_CloseInfoSysWin  0x021B0480  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18090.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void SCRCMD_MSGWIN_CloseInfoSysWin(u32 v);

int SCRCMD_MSGWIN_CleanupInfoSysWin(u8 *p)
{
    SCRCMD_MSGWIN_CloseInfoSysWin(((struct Obj18090 *)p)->f4);
    return 1;
}
