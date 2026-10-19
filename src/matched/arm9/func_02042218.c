/*
 * function: BG_SYS_ToHwScreenSize
 * address:  0x02042218
 * packet:   pkt_02041FF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two-dimensional table: the first argument picks a row, the second a column,
 * and each cell is a two- or three-bit index.  Rows 0 and 1 both fall through
 * to the shared `return 0` (a `break` out of the switch), so mwcc if-converts
 * every arm but the last of those two rows -- which is exactly the bne/mov/bx
 * shape the original shows -- while row 2, being the final case, keeps its
 * last arm if-converted too.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_ToHwScreenSize.c \
 *       --func BG_SYS_ToHwScreenSize --addr 0x02042218 --cc 1.1p1 --arm
 */

int BG_SYS_ToHwScreenSize(int a0, int a1)
{
    switch (a1) {
    case 0:
        if (a0 == 1)
            return 0;
        if (a0 == 2)
            return 2;
        if (a0 == 3)
            return 1;
        if (a0 == 4)
            return 3;
        break;
    case 1:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    case 2:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    }
    return 0;
}
