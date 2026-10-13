/*
 * function: GPOWER_FreePowerTable
 * address:  0x02010F8C
 * packet:   pkt_02010F18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Frees a buffer from GPOWER_LoadPowerTable.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void GPOWER_FreePowerTable(void *p)
{
    func_020307B0(p);
}
