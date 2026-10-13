/*
 * function: BTLV_SCU_StartFadeIn
 * address:  0x021EE228
 * packet:   pkt_ov093_021EE228
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 */

typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

void BTLV_SCU_StartFadeIn(void)
{
    int x = 0x10;
    FADE_Start(1, 0, x, x - 0x13);
}
