/*
 * function: SCRCMD_MSGWIN_CleanupPlainWin
 * address:  0x021B10F4
 * packet:   pkt_021B10F4
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
 *   SCRCMD_MSGWIN_ClosePlainWin  0x021B10A4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18092.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void SCRCMD_MSGWIN_ClosePlainWin(void *p);

int SCRCMD_MSGWIN_CleanupPlainWin(u8 *p)
{
    SCRCMD_MSGWIN_ClosePlainWin((void *)(((struct Obj18092 *)p)->f4));
    return 1;
}
