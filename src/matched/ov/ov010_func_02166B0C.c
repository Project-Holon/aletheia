/*
 * function: SYMBOL_MAP_StartBg2Scale
 * address:  0x02166B0C
 * packet:   pkt_ov010_02166B0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: stores 0x3F800000 and 0 into a two-word datum, then
 * tail-calls func_02005654(SYMBOL_MAP_UpdateBg2Scale, 0).
 *
 * symbols:
 *   func_02005654  0x02005654  thumb
 *   SYMBOL_MAP_UpdateBg2Scale  0x02166A6C  thumb  ov010
 *   g_Bg2ScaleState     0x02172BA4  data  ov010  a4
 */

typedef unsigned int u32;

extern int func_02005654(int a, int b);
extern void SYMBOL_MAP_UpdateBg2Scale(void);
extern u32 g_Bg2ScaleState[2];

void SYMBOL_MAP_StartBg2Scale(void)
{
    g_Bg2ScaleState[0] = 0x3F800000;
    g_Bg2ScaleState[1] = 0;
    func_02005654((int)SYMBOL_MAP_UpdateBg2Scale, 0);
}
