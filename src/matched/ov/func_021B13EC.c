/*
 * function: SCRCMD_MSGWIN_CleanupBgWin
 * address:  0x021B13EC
 * packet:   pkt_021B13EC
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
 *   SCRCMD_MSGWIN_CloseBgWin  0x021B1268  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void SCRCMD_MSGWIN_CloseBgWin(void *p);

int SCRCMD_MSGWIN_CleanupBgWin(u8 *p)
{
    SCRCMD_MSGWIN_CloseBgWin((void *)(((struct Obj18094 *)p)->f4));
    return 1;
}
