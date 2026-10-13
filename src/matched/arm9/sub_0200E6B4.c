/*
 * function: sub_0200E6B4
 * address:  0x0200E6B4
 * packet:   pkt_0200E6B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PMSI_PARAM_SetDefaultGreeting  0x02024344  thumb
 *   PMSI_PARAM_SetDefaultSentence  0x020242D8  thumb
 *
 * Promoted from src/pending/sub_0200E6B4.c: every concrete byte was
 * already reproduced, and both callees were unresolved relocations
 * because each is called from exactly this one place in the whole ROM,
 * the case the honesty rule's cut remedy cannot reach (docs/MATCHING.md,
 * "the limit of the remedy"). Both are now EXACT entries in their own
 * right (src/matched/sub_020242A4.c's PMSI_PARAM_SetDefaultGreeting, and
 * src/matched/unit_020242D8.c's PMSI_PARAM_SetDefaultSentence), so the `matched` class
 * attests both calls without a second caller, and this file closes to
 * EXACT.
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte
 * slots starting at obj+8, tagging each with its index 0..3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E6B4.c \
 *       --func sub_0200E6B4 --addr 0x0200E6B4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void PMSI_PARAM_SetDefaultGreeting(void *obj);
extern void PMSI_PARAM_SetDefaultSentence(void *slot, u32 idx);

void sub_0200E6B4(void *obj)
{
    PMSI_PARAM_SetDefaultGreeting(obj);
    PMSI_PARAM_SetDefaultSentence((u8 *)obj + 8, 0);
    PMSI_PARAM_SetDefaultSentence((u8 *)obj + 0x10, 1);
    PMSI_PARAM_SetDefaultSentence((u8 *)obj + 0x18, 2);
    obj = (u8 *)obj + 0x20;
    PMSI_PARAM_SetDefaultSentence(obj, 3);
}
