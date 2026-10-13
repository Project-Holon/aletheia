/*
 * function: SCRCMD_MSGWIN_CleanupTalkWin
 * address:  0x021B0EE8
 * packet:   pkt_021B0EE8
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
 *   SCRCMD_MSGWIN_CloseTalkWin  0x021B0AB0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18091.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void SCRCMD_MSGWIN_CloseTalkWin(u32 v);

int SCRCMD_MSGWIN_CleanupTalkWin(u8 *p)
{
    SCRCMD_MSGWIN_CloseTalkWin(((struct Obj18091 *)p)->f4);
    return 1;
}
