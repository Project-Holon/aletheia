/*
 * function: func_0219A1E8
 * address:  0x0219A1E8
 * packet:   pkt_ov021_0219A1E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D5074  0x021D5074  data  a4
 *
 * Row lookup: find the 6-halfword record whose key matches, then return the
 * entry after v in its 9-terminated list (wrapping to entry 1).  The row is
 * an inline argument formed through a (u8 *) byte offset, so the add stays
 * after the key compare; the helper's `for (i = 1, p = row; ...)` local copy
 * of the row gives the image's colours (row r0, index r3, v copied to r4).
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern u16 d_021D5074[][6];

static inline u16 NextInRow(u16 *row, u16 v)
{
    int i;
    u16 *p;

    for (i = 1, p = row; p[i] != 9; i++) {
        if (v == p[i]) {
            i++;
            if (p[i] == 9) i = 1;
            return p[i];
        }
    }
    return 9;
}

u16 func_0219A1E8(u16 key, u16 v)
{
    int i = 0;

    do {
        if (key == d_021D5074[i][0]) {
            return NextInRow((u16 *)((u8 *)d_021D5074 + i * 12), v);
        }
        i++;
    } while (d_021D5074[i][0] != 0xFF);
    return 9;
}
