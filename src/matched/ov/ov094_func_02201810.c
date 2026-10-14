/*
 * function: BTLV_MCSS_CellCallbackCheckStopCell
 * address:  0x02201810
 * packet:   pkt_ov094_02201810
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   MCSS_GetStopCellNum  0x02015EF4  thumb
 *   MCSS_GetStopCellIndex  0x02015EFC  thumb
 *
 * blocker (cleared 2026-10-01, arm9 leaf filed): two unlabelled arm9 Thumb leaves (the integrator's; no witness outside this range).
 *   Every concrete byte matches; only the two bl relocation sites stay wildcarded.
 *   Verified C (match.py one --arm9 no --region, --thumb, dsi/1.1p1 -O4,p), both EXACT:
 *
 *     typedef unsigned char u8;
 *     u8 MCSS_GetStopCellNum(char *p)              // 0x02015EF4, 6 bytes
 *     {
 *         return **(u8 **)(p + 0x30);
 *     }
 *     u8 MCSS_GetStopCellIndex(char *p, int i)       // 0x02015EFC, 8 bytes
 *     {
 *         return (*(u8 **)(p + 0x30) + i)[2];  // `[i + 2]` is 5 bytes out
 *     }
 *
 * lever: the first test reads the row through the indexed base (`base[idx].h`), the loop
 *   through `e = &base[idx]` inside the loop body; a shared `base + off` char cast is CSE'd
 *   into one register and comes out 8 bytes short. `idx == -1` (u16 against int -1) is not
 *   folded: it keeps the movs/mvns pair. The two `v = 1` arms cross-jump only when the
 *   found test is `if (found == 0) v = 0; else v = 1;`.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    int pad[2];
    void *h;
    char pad2[0x5C - 12];
} Row;

extern int BTLV_EFFECT_GetMcss(void);
extern u8 MCSS_GetStopCellNum(char *p);
extern u8 MCSS_GetStopCellIndex(char *p, u8 i);

int BTLV_MCSS_CellCallbackCheckStopCell(u32 flags, int a, int *out, int key)
{
    Row *base = (Row *)BTLV_EFFECT_GetMcss();
    u16 idx = flags;
    int found;
    int n;
    int i;
    int v;

    if (idx == -1)
        return 0;
    if (base[idx].h == 0)
        return 0;
    if (flags & 0x80000000) {
        found = 0;
        n = MCSS_GetStopCellNum(base[idx].h);
        for (i = 0; i < n; i++) {
            Row *e = &base[idx];

            if (key == MCSS_GetStopCellIndex(e->h, i))
                found = 1;
        }
        if (found == 0)
            v = 0;
        else
            v = 1;
    } else {
        v = 1;
    }
    out[3] = v;
    return 1;
}
