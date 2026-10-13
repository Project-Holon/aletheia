/*
 * function: STARTMENU_SaveEraseStartFadeOut
 * address:  0x021BD23C
 * packet:   pkt_ov088_021BD23C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 */

typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

void STARTMENU_SaveEraseStartFadeOut(void)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x81);
}
