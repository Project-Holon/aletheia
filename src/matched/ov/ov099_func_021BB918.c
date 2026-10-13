/*
 * function: func_021BB918
 * address:  0x021BB918
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   d_021C398C     0x021C398C  data   ov099
 */
typedef struct {
    int v[16];
} Tbl;

extern const Tbl d_021C398C;
typedef unsigned int   u32;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);

int func_021BB918(void *w, unsigned int idx, int *unused)
{
    Tbl t;

    GF_FONT_SetTextColor(1, 2, 0);
    GF_FONT_SetTextColor(1, 2, 0);
    t = d_021C398C;
    if (idx > 15)
        idx = 15;
    return t.v[idx];
}
