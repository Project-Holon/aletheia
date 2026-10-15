/*
 * function: BTLV_SCU_StartBrightnessFade
 * address:  0x021EB584
 * packet:   pkt_ov093_021EB584
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GXx_GetMasterBrightness_  0x0207D55C  arm    arm9
 *   FADE_Start  0x0204E720  arm    arm9
 */
typedef unsigned short u16;
extern int GXx_GetMasterBrightness_(volatile u16 *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
void BTLV_SCU_StartBrightnessFade(int a)
{
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400006c) <= 0)
        FADE_Start(3, 0x10, 0, a);
    else
        FADE_Start(0xc, 0x10, 0, a);
}
