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
 * func_02051A2C.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 d_02146A88;

u32 func_02051774(void)
{
    return *(u32 *)(*(u32 *)&d_02146A88 + 0x40);
}
