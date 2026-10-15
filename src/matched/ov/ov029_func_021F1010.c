/*
 * function: C_GEAR_DrawEmptyBoard
 * address:  0x021F1010
 * packet:   pkt_ov029_021F1010
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_DrawTile  0x021F1290  thumb  ov029
 *   BG_SYS_PushTile  0x020409B4  arm
 *   d_021F3324     0x021F3324  data  a4
 */

typedef struct { int a, b; } Pair;

extern const Pair d_021F3324;
extern void C_GEAR_DrawTile(void *p, int i, int j, int k);
typedef unsigned int   u32;
extern void BG_SYS_PushTile(u32 index);

void C_GEAR_DrawEmptyBoard(void *p)
{
    Pair t = d_021F3324;
    int i, j, n;

    for (i = 0; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            C_GEAR_DrawTile(p, i, j, 0);
    }
    BG_SYS_PushTile(4);
}
