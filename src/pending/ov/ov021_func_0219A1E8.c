/*
 * function: func_0219A1E8
 * address:  0x0219A1E8
 * packet:   pkt_ov021_0219A1E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   d_021D5074  0x021D5074  data  a4
 *
 * 2026-10-01: logic correct (one index reused for the inner scan); original copies v to r4 and computes the row address after the key compare, ours hoists it; row local, direct indexing and a table pointer local all give the same 46-byte residue.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 d_021D5074[][6];

u16 func_0219A1E8(u16 key, u16 v)
{
    u16 (*t)[6] = d_021D5074;
    int i = 0;
    u16 *row;
    do {
        if (key == t[i][0]) {
            row = t[i];
            for (i = 1; row[i] != 9; i++) {
                if (v == row[i]) {
                    i++;
                    if (row[i] == 9) {
                        i = 1;
                    }
                    return row[i];
                }
            }
            return 9;
        }
        i++;
    } while (t[i][0] != 0xFF);
    return 9;
}
