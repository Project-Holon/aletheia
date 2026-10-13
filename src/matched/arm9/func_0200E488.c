/*
 * function: func_0200E488
 * address:  0x0200E488
 * packet:   pkt_0200E488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: promoted.  0x0216736C is the unlabelled ov010 leaf matched
 *           in src/matched/QUESTIONNAIRE_GetFirstAnswerMessageOffset.c (ov010/pkt_02167358); it attests as
 *           `matched, overlay` under the ov010 hint.  The source shape that
 *           works: a1-1 must be a named local computed before the call;
 *           writing `f(a0) + (a1 - 1)` gives `adds r0, r1, r0` instead of
 *           `adds r0, r0, r1`.
 * symbols:
 *   QUESTIONNAIRE_GetFirstAnswerMessageOffset    0x0216736C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 QUESTIONNAIRE_GetFirstAnswerMessageOffset(u32 id);

u32 func_0200E488(u32 a0, u32 a1)
{
    u32 n = a1 - 1;
    u32 v = QUESTIONNAIRE_GetFirstAnswerMessageOffset((u8)a0);

    return v + n;
}
