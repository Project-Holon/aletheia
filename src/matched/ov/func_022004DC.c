/*
 * function: WORLDTRADE_TITLE_StateWaitWipeInAlt
 * address:  0x022004DC
 * packet:   pkt_022004DC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *

 *
 * Probe the parent object; on success stamp 5 into +0x28 and report 2.
 */
#include "../include/Obj18607.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 WIPE_SYS_EndCheck(void);

int WORLDTRADE_TITLE_StateWaitWipeInAlt(u8 *p)
{
    if (WIPE_SYS_EndCheck()) {
        ((struct Obj18607 *)p)->f28 = 5;
    }
    return 2;
}
