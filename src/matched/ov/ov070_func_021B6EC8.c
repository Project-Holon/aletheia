/*
 * function: ITEMMENU_FindUseRange
 * address:  0x021B6EC8
 * packet:   pkt_ov070_021B6EC8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (push {r4,r5}, no lr) called twice by ITEMMENU_HandleActionMenuChoice:
 * finds the entry of the 8-entry range table at 0x021BB9C4 whose
 * [lo, lo + n) holds id, or -1.
 *
 * symbols:
 *   gItemMenuUseRanges  0x021BB9C4  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

extern const RangeEnt gItemMenuUseRanges[8];

int ITEMMENU_FindUseRange(u16 id)
{
    u32 i;
    const RangeEnt *e;

    for (i = 0; i < 8; i++) {
        e = &gItemMenuUseRanges[i];
        if (id >= e->lo && id < e->lo + e->n)
            return i;
    }
    return -1;
}
