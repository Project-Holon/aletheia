/*
 * function: func_020637BC
 * address:  0x020637BC
 * packet:   pkt_020637BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * Twelve concrete bytes differ of twenty-four: the sentinel compare against
 * 0xffffffff folds to `cmn r0, #1` after the front end, so the loaded value
 * takes r0 and the explicit `mvn r0, #0` disappears.  Ten spellings of the
 * constant were tried (`0xffffffff`, `0xffffffffu`, `(u32)-1`, `~0u`, `-1`,
 * signed casts, a named local, both operand orders) and all of them fold.
 * See docs/notes/pkt_020637BC.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020637BC.c \
 *       --func func_020637BC --addr 0x020637BC --arm --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_020637BC(u32 *p, u32 i)
{
    u32 v = p[i];

    if (v == 0xffffffffu) {
        return 0;
    }

    return 1;
}
