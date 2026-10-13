/*
 * function: PMSI_PARAM_InitSentenceId
 * address:  0x020242C0
 * packet:   pkt_020242C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_PARAM_InitSentence  0x020242A4  thumb
 *   PMSI_PARAM_SetSentenceId  0x02024598  thumb
 */

typedef unsigned int   u32;
extern void PMSI_PARAM_InitSentence(void *obj, u32 id);
extern void PMSI_PARAM_SetSentenceId(void *p0, int p1, int p2);

void PMSI_PARAM_InitSentenceId(void *a, void *b, void *c)
{
    PMSI_PARAM_InitSentence(a, (u32)b);
    PMSI_PARAM_SetSentenceId(a, (int)b, (int)c);
}
