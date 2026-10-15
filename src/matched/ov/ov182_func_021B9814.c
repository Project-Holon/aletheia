/*
 * function: THE_END_GRAPHIC_StartFade
 * address:  0x021B9814
 * packet:   pkt_021B9814
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   FADE_Start  0x0204E720  arm
 */
typedef unsigned int u32;

extern u32 GPOWER_GetSpecialPowerId(void);
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

void THE_END_GRAPHIC_StartFade(void *a, void *b, void *c)
{
    if (GPOWER_GetSpecialPowerId() == 0x15)
        FADE_Start(3, (s32)a, (s32)b, (s32)c);
    else
        FADE_Start(0xc, (s32)a, (s32)b, (s32)c);
}
