/*
 * function: TOWN_MAP_SPOT_CountVisited
 * address:  0x0216FEAC
 * packet:   pkt_ov010_0216FEAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts the 48 table records TOWN_MAP_SPOT_Classify classifies as reachable.
 * The listing extent (2960 bytes) runs over the unit's rodata; the
 * function itself is 44 bytes (EXACT* for that reason). The counter is
 * enum-typed: that keeps the unfolded loop entry guard, which the original
 * tests on the zero in the count register.
 *
 * symbols:
 *   TOWN_MAP_SPOT_Classify  0x0216FE2C  thumb  ov010
 */

typedef unsigned char u8;
typedef enum { SLOT_0 } Slot;

struct Pos;
struct Rec;
extern int TOWN_MAP_SPOT_Classify(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);

int TOWN_MAP_SPOT_CountVisited(void *tbl, void *pos, u8 *flags)
{
    Slot i;
    int n;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (TOWN_MAP_SPOT_Classify(tbl, i, pos, flags) == 0)
            n++;
    }
    return n;
}
