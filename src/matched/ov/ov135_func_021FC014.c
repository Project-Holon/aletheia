/*
 * function: WORLDTRADE_INPUT_CategoryHasListEntries
 * address: 0x021FC014
 * packet: pkt_ov135_021FC014
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_GetListRangeCount 0x021FC008 thumb ov135
 *   tbl_02203324 0x02203324 data a4
 *   tbl_022033F8 0x022033F8 data a4
 */
typedef unsigned int u32;
typedef struct { int first; int count; } Span;
extern const int tbl_02203324[];
extern const Span tbl_022033F8[];
extern int WORLDTRADE_INPUT_GetListRangeCount(void *p, u32 idx);
int WORLDTRADE_INPUT_CategoryHasListEntries(void *p, int idx)
{
    int base;
    int i;
    base = tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (WORLDTRADE_INPUT_GetListRangeCount(p, base + i) > 0) return 1;
        }
    } else {
        if (WORLDTRADE_INPUT_GetListRangeCount(p, base) > 0) return 1;
    }
    return 0;
}
