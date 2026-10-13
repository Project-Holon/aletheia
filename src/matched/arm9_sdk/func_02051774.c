/*
 * function: func_02051774
 * address:  0x02051774
 * packet:   pkt_02051774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_02146A88  0x02146A88  data
 *
 * ARM9 ARM leaf. Loads the global pointer d_02146A88, then reads +0x40 of
 * the object it points at. Called by the ov118 storage helpers
 * func_021D6EAC/func_021D6F0C as the value they store back through
 * BUTTON_MAN_SetUserData.
 *
 * Addresses are Black-image addresses.
 */

#include "../include/G_02146A88.h"

typedef unsigned int u32;

extern struct G_02146A88 *d_02146A88;

u32 func_02051774(void)
{
    return *(u32 *)(*(u32 *)&(*(u32 *)&d_02146A88) + 0x40);
}
