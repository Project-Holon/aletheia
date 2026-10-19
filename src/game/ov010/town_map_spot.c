/*
 * file:     town_map_spot.c
 * unit:     yes
 * function: TOWN_MAP_SPOT_Classify, TOWN_MAP_SPOT_CountVisited
 * address:  0x0216FE2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from waza_oshie.c (which held Classify at its end) and merged with the old
 * town_map_spot.c by tools/splitfile.py: Classify and CountVisited are one original.
 * The listing extent of CountVisited (2960 bytes) runs over the unit rodata.
 *
 * symbols:
 *   TOWN_MAP_SPOT_Classify  0x0216FE2C  thumb  ov010
 */
#include "waza_oshie_shared_types.h"

struct Rec {
    u8 x;
    u8 y;
    u8 pad[10];
};

struct Pos {
    u8 pad[0x0c];
    u16 x;
    u16 y;
};

/*
 * Classifies table entry idx (12-byte records) against a position:
 * 0 = inside, 1 = within three steps on one axis, 2 = out of reach or
 * locked. 0xFF marks an unused record; 0xFE records are gated by a bit
 * (idx - 0x21) of the 16-bit mask at flags.
 */
int TOWN_MAP_SPOT_Classify(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags)
{
    int x;
    int y;
    int m;

    x = tbl[idx].x;
    if (x == 0xff)
        return 2;
    if (x == 0xfe) {
        m = flags[0] | (flags[1] << 8);
        if (m & (1 << (idx - 0x21)))
            return 0;
        return 2;
    }
    if (x <= pos->x) {
        y = tbl[idx].y;
        if (y <= pos->y)
            return 0;
        if (y - pos->y <= 3)
            return 1;
    } else {
        y = tbl[idx].y;
        if (y <= pos->y) {
            if (x <= pos->x)
                return 0;
            if (x - pos->x <= 3)
                return 1;
        }
    }
    return 2;
}

typedef enum { SPOT_INDEX_FIRST } SpotIndex;

int TOWN_MAP_SPOT_CountVisited(void *spots, void *position, u8 *unlockMask)
{
    SpotIndex index;
    int count;

    count = 0;
    for (index = 0; index < 0x30; index++) {
        if (TOWN_MAP_SPOT_Classify(spots, index, position, unlockMask) == 0)
            count++;
    }
    return count;
}
