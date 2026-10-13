/*
 * function: DWCi_GXlInvisible
 * address:  0x021D6090
 * packet:   pkt_ov016_021D6090
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GXlInvisible (graphics.o)
 *
 * Closed (w5_nm): the plane mask is read into a local first and DISPCNT is read
 * again inside the store expression (get-then-set order); reading both into
 * locals up front gave the converse r0/r2 roles.
 *
 * symbols:
 *   (none)
 */

#define REG_DISPCNT(base) (*(volatile unsigned long *)(base))

void DWCi_GXlInvisible(int lcd, int plane)
{
    if (lcd == 1) {
        unsigned long v = (REG_DISPCNT(0x04001000) & 0x1f00) >> 8;

        REG_DISPCNT(0x04001000) = (REG_DISPCNT(0x04001000) & ~0x1f00) | ((v & ~plane) << 8);
    } else {
        unsigned long v = (REG_DISPCNT(0x04000000) & 0x1f00) >> 8;

        REG_DISPCNT(0x04000000) = (REG_DISPCNT(0x04000000) & ~0x1f00) | ((v & ~plane) << 8);
    }
}
