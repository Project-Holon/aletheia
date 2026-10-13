/*
 * function: SCRCMD_WORK_SetTimeIcon
 * address:  0x0215A624
 * packet:   pkt_ov010_0215A624
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Setter: word at +0x100 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of SCRCMD_MSGWIN_CloseInfoSysWin).
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj18787.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

void SCRCMD_WORK_SetTimeIcon(u8 *p, u32 v)
{
    *(u32 *)((u8 *)((struct Obj18787 *)p)->f20 + 0x100) = v;
}
