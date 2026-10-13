/*
 * function: SCRCMD_MSGWIN_CleanupSpWin
 * address:  0x021B14E8
 * packet:   pkt_021B14E8
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
 *   SCRCMD_MSGWIN_CloseSpWin  0x021B13F8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18095.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void SCRCMD_MSGWIN_CloseSpWin(u32 v);

int SCRCMD_MSGWIN_CleanupSpWin(u8 *p)
{
    SCRCMD_MSGWIN_CloseSpWin(((struct Obj18095 *)p)->f4);
    return 1;
}
