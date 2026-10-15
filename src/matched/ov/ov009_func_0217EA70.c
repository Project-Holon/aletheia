/*
 * function: gsiMemoryRealloc
 * address: 0x0217EA70
 * packet: pkt_ov009_0217EA70
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov009/unit_0217D3AC.c and filed here.
 *
 * symbols:
 *   MSL_C_LIB_ReallocResource 0x020913FC arm
 */

extern void *MSL_C_LIB_ReallocResource(unsigned long a0, unsigned long a1);
void *gsiMemoryRealloc(unsigned long a0, unsigned long a1);

void *gsiMemoryRealloc(unsigned long a0, unsigned long a1)
{
    return MSL_C_LIB_ReallocResource(a0, a1);
}
