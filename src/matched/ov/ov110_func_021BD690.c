/*
 * function: PMS_INPUT_InitSentenceCursor
 * address: 0x021BD690
 * packet: pkt_ov110_021BD690
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * blocker: 0x02024530, Thumb ARM9, integrator-owned unlabelled leaf.
 * No witness outside this caller; tu --suggest-split leaves it out.
 * Scratch one verdict EXACT (4 bytes), fixed compiler/flags, no region:
 * typedef unsigned short u16;
 * unsigned int PMSI_PARAM_GetSentenceId(const u16 *p) { return p[1]; }
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   PMSI_PARAM_GetSentenceType 0x0202452C thumb
 *   PMSI_PARAM_GetSentenceCount 0x02024584 thumb
 *   PMSI_PARAM_GetSentenceId 0x02024530 thumb
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int PMSI_PARAM_GetSentenceType(const u16 *p);
extern u8 PMSI_PARAM_GetSentenceCount(u32 i);
extern unsigned int PMSI_PARAM_GetSentenceId(const u16 *p);
void PMS_INPUT_InitSentenceCursor(u8 *p, u16 *out)
{
    *(s16 *)p=PMSI_PARAM_GetSentenceType(out);
    p[3]=PMSI_PARAM_GetSentenceCount(*(s16 *)p);
    p[2]=PMSI_PARAM_GetSentenceId(out);
}
