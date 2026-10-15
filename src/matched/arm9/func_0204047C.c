/*
 * function: BG_SYS_SetVisibleLayer
 * address:  0x0204047C
 * packet:   pkt_0204047C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf: a two-to-four entry register write-back.  idx 0..7
 * selects one of eight volatile 16-bit MMIO registers (two banks of four,
 * 0x04000008..0x0400000E and 0x04001008..0x0400100E); each case clears the
 * low two bits of the register and ORs in the low bits of val.  idx > 7 is a
 * no-op (`bx lr` / `pop {r3,pc}` in the follower).
 *
 * The constants are absolute hardware addresses, so they are plain pool words
 * with no relocation.
 */

void BG_SYS_SetVisibleLayer(int idx, unsigned short val)
{
    volatile unsigned short *p;

    switch (idx) {
    case 0:
        p = (volatile unsigned short *)0x04000008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 1:
        p = (volatile unsigned short *)0x0400000A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 2:
        p = (volatile unsigned short *)0x0400000C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 3:
        p = (volatile unsigned short *)0x0400000E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 4:
        p = (volatile unsigned short *)0x04001008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 5:
        p = (volatile unsigned short *)0x0400100A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 6:
        p = (volatile unsigned short *)0x0400100C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 7:
        p = (volatile unsigned short *)0x0400100E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    }
}
