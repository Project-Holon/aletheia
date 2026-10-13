/*
 * function: PALANM_GetPairedCodeForFirst
 * address:  0x0202142C
 * packet:   pkt_020213F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0008 ABS32 PALANM_LookupPairedCode          : 020213F8 (thumb, from name) has no witness outside 0202142C..02021438
 *
 * symbols:
 *   PALANM_LookupPairedCode  0x020213F8  thumb
 */

extern unsigned short PALANM_LookupPairedCode(int a0, int a1);

unsigned short PALANM_GetPairedCodeForFirst(int a0)
{
    return PALANM_LookupPairedCode(a0, 0);
}
