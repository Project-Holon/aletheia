/*
 * function: func_0218BCB0
 * address:  0x0218BCB0
 * packet:   pkt_ov021_0218BCB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3DC4     0x021D3DC4  data  a4
 */

typedef struct {
    unsigned char b[16];
} Tbl;

extern const Tbl d_021D3DC4;

unsigned char func_0218BCB0(unsigned short *p)
{
    Tbl t = d_021D3DC4;
    if (p[1] >= 16)
        return 0;
    return t.b[p[1]];
}
