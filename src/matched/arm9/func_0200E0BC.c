/*
 * function: func_0200E0BC
 * address:  0x0200E0BC
 * packet:   pkt_0200E0BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sSymbolBandRanges  0x0209DE90  data
 *
 * Band lookup: the index of the first of four records whose .b bound is
 * above value, or 3. func_0200E124 indexes the same table with the result.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 44/44, 9 out, the "pool load
 * in the preheader" wall of docs/notes/pkt_0200E0BC.c.txt): the counter AND
 * the result are enum-typed, as in src/matched/GPOWER_CountDownTimers.c. An enum
 * induction variable keeps the unfolded `cmp #4; bhs` entry guard with the
 * table load after it, and no redundant `if (i >= 4) break;` is needed. The
 * bound is compared unsigned (`(u32)IDX_MAX`) for the image's bhs/blo; with
 * that compare a u32 result swaps r3/r4, an enum result does not.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef enum { IDX_0 = 0, IDX_MAX = 4 } Idx;

struct Rec { u16 a; u16 b; };
extern const struct Rec sSymbolBandRanges[];

u32 func_0200E0BC(u32 value)
{
    Idx i;
    Idx r = 3;

    for (i = 0; i < (u32)IDX_MAX; i++) {
        if (value < sSymbolBandRanges[i].b) {
            r = i;
            break;
        }
    }
    return r;
}
