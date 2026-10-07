/*
 * function: func_02166324
 * address:  0x02166324
 * packet:   pkt_ov010_02166324
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a tile/graphic index for a cell of a 3-wide, 30-cell grid from its
 * neighbours: column (pos % 3) decides left/right edges, the cells above
 * (pos - 3) and below (pos + 3) decide the vertical links.
 *
 * symbols:
 *   func_0216630C  0x0216630C  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned char u8;

extern u8 func_0216630C(u8 *grid, int id);

int func_02166324(u8 *grid, int id)
{
    int pos = func_0216630C(grid, id);
    int left = 0;
    int col = pos % 3;
    int right;
    int up;
    int down;

    if (col != 0 && pos != 1) {
        left = 1;
    }
    right = 0;
    if (col != 2 && pos != 1) {
        right = 1;
    }
    up = 0;
    if (pos - 3 >= 0 && grid[pos - 3] != 0) {
        up = 1;
    }
    down = 0;
    if (pos + 3 < 30 && grid[pos + 3] != 0) {
        down = 1;
    }

    if (id == 1) {
        return 0x119;
    }
    if (id == 5) {
        return 0x118;
    }
    if (left && right) {
        return 0x11D;
    }
    if (left && !right) {
        if (up && down) {
            return 0x11E;
        }
        if (up) {
            return 0x120;
        }
        if (down) {
            return 0x11B;
        }
    }
    if (!left && right) {
        if (up && down) {
            return 0x11C;
        }
        if (up) {
            return 0x11F;
        }
        if (down) {
            return 0x11A;
        }
    }
    return 0x119;
}
