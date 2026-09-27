/*
 * function: func_0216FEAC
 * address:  0x0216FEAC
 * packet:   pkt_ov010_0216FEAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the 48 table records func_0216FE2C classifies as reachable.
 * The listing extent (2960 bytes) runs over the unit's rodata; the
 * function itself is 44 bytes (EXACT* for that reason). The counter is
 * enum-typed: that keeps the unfolded loop entry guard, which the original
 * tests on the zero in the count register.
 *
 * symbols:
 *   func_0216FE2C  0x0216FE2C  thumb  ov010
 */

typedef unsigned char u8;
typedef enum { SLOT_0 } Slot;

extern int func_0216FE2C(void *tbl, int idx, void *pos, u8 *flags);

int func_0216FEAC(void *tbl, void *pos, u8 *flags)
{
    Slot i;
    int n;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (func_0216FE2C(tbl, i, pos, flags) == 0)
            n++;
    }
    return n;
}
