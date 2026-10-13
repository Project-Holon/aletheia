/*
 * function: func_021D335C
 * address:  0x021D335C
 * packet:   pkt_021D335C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Writes (p[0] | p[1] << 8) to the 16-bit display register at 0x04000052 (sub nonzero)
 * or 0x04001052 (sub zero).
 *
 * symbols:
 *   (none)
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void func_021D335C(u32 *p, int sub)
{
    if (sub) {
        *(volatile u16 *)0x04000052 = p[0] | (p[1] << 8);
    } else {
        *(volatile u16 *)0x04001052 = p[0] | (p[1] << 8);
    }
}
