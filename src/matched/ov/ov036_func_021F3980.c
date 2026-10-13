/*
 * function: DAILY_LAYOUT_DealCells
 * address:  0x021F3980
 * packet:   pkt_ov036_021F3980
 * region:   ov036
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the image builds the count as `movs #0xf; subs #1`: n is an enum
 *           local (n = 15; cnt = n - 1), which keeps the subtraction unfolded
 *           (a literal 15 - 1 gives `movs #0xe`).  The slot stores are
 *           (p + 0xf)[p[0x1e]] (p[p[0x1e] + 0xf] folds the 0xf into the
 *           index).  The first early exit returns the zero flag a.
 *           The function ends at 0x021F3A6C; the rest of the handed extent is
 *           its pool and the u8/record tables it reads.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   DAILY_LAYOUT_FindPoolCell  0x021F3934  thumb  ov036
 *   DAILY_LAYOUT_GetPoolCell  0x021F394C  thumb  ov036
 *   DAILY_LAYOUT_RemovePoolCell  0x021F395C  thumb  ov036
 *   gDailyLayoutAnchorCells     0x021F3A7C  data  a1
 *   gDailyLayoutCompanionCellsA     0x021F3A82  data  a1
 *   gDailyLayoutCompanionCellsB     0x021F3A90  data  a1
 *   d_021F3AD4     0x021F3AD4  data  a4
 */

typedef unsigned char u8;
typedef enum { K_0 } KType;

typedef struct {
    int a;
    int b;
} P8;

extern u8 gDailyLayoutAnchorCells[];
extern u8 gDailyLayoutCompanionCellsA[];
extern u8 gDailyLayoutCompanionCellsB[];
extern P8 d_021F3AD4[];

typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern int DAILY_LAYOUT_FindPoolCell(u8 *p, int v);
extern int DAILY_LAYOUT_GetPoolCell(u8 *p, int idx);
extern int DAILY_LAYOUT_RemovePoolCell(u8 *p, int idx);

int DAILY_LAYOUT_DealCells(u8 *p)
{
    int a;
    int b;
    int idx;
    int v;
    int cnt;
    KType n;
    int i;
    int r;
    int x;

    a = 0;
    b = 0;
    idx = func_020056EC(6);
    v = gDailyLayoutAnchorCells[idx];
    if (DAILY_LAYOUT_RemovePoolCell(p, DAILY_LAYOUT_FindPoolCell(p, v)) == 0)
        return a;
    (p + 0xf)[p[0x1e]] = v;
    p[0x1e]++;
    n = 15;
    cnt = n - 1;
    if (d_021F3AD4[idx].a == 0)
        a = 1;
    else
        b = 1;
    if (b == 0 || a == 0) {
        if (b == 0)
            v = gDailyLayoutCompanionCellsA[func_020056EC(7)];
        else
            v = gDailyLayoutCompanionCellsB[func_020056EC(8)];
        if (DAILY_LAYOUT_RemovePoolCell(p, DAILY_LAYOUT_FindPoolCell(p, v)) == 0)
            return 0;
        cnt--;
        (p + 0xf)[p[0x1e]] = v;
        p[0x1e]++;
    }
    for (i = 0; i < cnt; i++) {
        r = func_020056EC(cnt - i);
        x = DAILY_LAYOUT_GetPoolCell(p, r);
        if (x < 0)
            return 0;
        if (DAILY_LAYOUT_RemovePoolCell(p, r) == 0)
            return 0;
        (p + 0xf)[p[0x1e]] = x;
        p[0x1e]++;
    }
    return 1;
}
