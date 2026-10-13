/*
 * function: UNION_APP_HasMembers
 * address:  0x0218401C
 * packet:   pkt_ov022_0218401C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s); blocker of ov012
 * UNION_MAIN_StepGroupActivity.
 */

typedef unsigned char u8;

int UNION_APP_HasMembers(u8 *p)
{
    if (p[1] != 0)
        return 1;
    return 0;
}
