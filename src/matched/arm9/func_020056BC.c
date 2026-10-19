/*
 * function: GFL_USE_GetMainTaskList
 * address:  0x020056BC
 * packet:   pkt_020056BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020AA194  0x020AA194  data
 *
 * Unlabelled Thumb leaf in the ARM9 module (disasm.py emits it as ARM
 * because nothing saves lr). Reads a pointer field out of the data object
 * d_020AA194 (+0x10), then a word at +0x20 of that. Called by the ov119
 * wrappers POKETRADE_2D_ScheduleMainPlaneVisible/POKETRADE_2D_ScheduleSubPlaneVisible.
 *
 * Addresses are Black-image addresses.
 */

#include "../include/G_GflSys.h"

typedef unsigned int u32;

extern struct GflSys d_020AA194;

u32 GFL_USE_GetMainTaskList(void)
{
    return *(u32 *)(*(u32 *)(((unsigned char *)&d_020AA194) + 0x10) + 0x20);
}
