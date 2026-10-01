/*
 * function: func_0219B120
 * address:  0x0219B120
 * packet:   pkt_ov021_0219B120
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   d_021D50F8  0x021D50F8  data  a4
 *
 * 2026-10-01: original compares the first key against a literal 0 (table row 0 key is 0) before the walk; neither an extern table nor a static const table folds it. Draft kept for the next attempt.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u32 id; u32 *tbl; } Ent;
extern u32 d_021D4FB8[], d_021D4D0C[], d_021D4D30[], d_021D4D18[];
extern u32 d_021D4D3C[], d_021D4EF8[], d_021D4EB8[], d_021D4EC8[];

static const Ent d_021D50F8[] = {
    { 0, d_021D4FB8 }, { 1, d_021D4D0C }, { 2, d_021D4D30 }, { 3, d_021D4D18 },
    { 4, d_021D4D3C }, { 5, d_021D4EF8 }, { 6, d_021D4EB8 }, { 7, d_021D4EC8 },
    { 0x27, 0 },
};

u32 *func_0219B120(u32 id)
{
    int i;
    for (i = 0; d_021D50F8[i].id != 0x27; i++) {
        if (d_021D50F8[i].id == id) {
            return d_021D50F8[i].tbl;
        }
    }
    return 0;
}
