/*
 * function: sub_0207C86C
 * address:  0x0207C86C
 * packet:   pkt_0207C86C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Read the hardware divider result started by sub_0207C930: poll DIVCNT
 * bit 15 until the unit is idle, then take the 64-bit DIV_RESULT, add
 * 0x80000 for rounding and shift right 20, keeping the low 32 bits.
 *
 * symbols:
 *   (none; all addresses are constants)
 */

typedef unsigned int       u32;
typedef unsigned short     u16;
typedef unsigned long long u64;
typedef volatile u32       vu32;
typedef volatile u16       vu16;

u32 sub_0207C86C(void)
{
    u64 v;

    while (*(vu16 *)0x04000280 & 0x8000) {
        /* wait for the divider */
    }
    v = *(u64 *)0x040002A0;
    return (u32)((v + 0x80000) >> 20);
}
