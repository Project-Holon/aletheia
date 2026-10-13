/*
 * function: func_0216FEAC
 * address:  0x0216FEAC
 * packet:   pkt_ov010_0216FEAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
typedef enum { SPOT_INDEX_FIRST } SpotIndex;

struct SpotPosition;
struct SpotRecord;
extern int func_0216FE2C(struct SpotRecord *spots, int index, struct SpotPosition *position, u8 *unlockMask);

int func_0216FEAC(void *spots, void *position, u8 *unlockMask)
{
    SpotIndex index;
    int count;

    count = 0;
    for (index = 0; index < 0x30; index++) {
        if (func_0216FE2C(spots, index, position, unlockMask) == 0)
            count++;
    }
    return count;
}
