/*
 * file:     mi_sharedwram.c
 * function: MI_InitWramManager
 * address:  0x02082198
 * packet:   pkt_02082198
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   MIi_InitWramManager 0x02730468 arm twl
 */

#include "os_emulator.h"
#include "../twl/mi_sharedWram.h"

void MI_InitWramManager(void)
{
    if (OS_IsRunOnTwl()) {
        MIi_InitWramManager();
    }
}
