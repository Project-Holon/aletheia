/*
 * unit:     yes
 * function: PDC_MSG_StartFadeIn, PDC_MSG_IsFadeIdle
 * address:  0x021B6B5C
 * packet:   pkt_ov098_021B6B5C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two unlabelled tail-call stubs (object + 4), filed as the blocker of
 * PDC_MAIN_StepIntro (lane S25). tu range is the 24 code bytes only; the listing
 * extent runs on into PDC_MSG_TakeStreamEnded.
 *
 * symbols:
 *   PDC_MSG_BlendStartFadeIn  0x021B6C60  thumb  ov098
 *   PDC_MSG_BlendUpdate  0x021B6CDC  thumb  ov098
 */

extern void PDC_MSG_BlendStartFadeIn(char *p);
typedef unsigned char  u8;
extern int PDC_MSG_BlendUpdate(u8 *p);

void PDC_MSG_StartFadeIn(char *p)
{
    PDC_MSG_BlendStartFadeIn(p + 4);
}

int PDC_MSG_IsFadeIdle(char *p)
{
    return PDC_MSG_BlendUpdate((u8 *)(p + 4));
}
