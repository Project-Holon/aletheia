/*
 * function: SHINKA_DEMO_StartResultBgm
 * address:  0x02204FA0
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 5, clear word +0x34, arm a 1-flag timer on it and move
 * to state 7.
 *
 * symbols:
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);

void SHINKA_DEMO_StartResultBgm(int a, int *p)
{
    if (p[0xc] == 5) {
        p[0xd] = 0;
        GFL_USE_StepBgmLoad((unsigned char *)0x519, (u32 *)(&p[0xd]), 1);
        p[0xc] = 7;
    }
}
