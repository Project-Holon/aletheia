/*
 * function: MUSICAL_MCSS_GetElemB
 * address:  0x021F514C
 * packet:   pkt_021F514C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MUSICAL_MCSS_GetElemPtr  0x021F4F54  thumb  ov112
 */

unsigned char *MUSICAL_MCSS_GetElemPtr(unsigned char *p, int i);

unsigned char MUSICAL_MCSS_GetElemB(void *p, int i)
{
    return *(unsigned char *)(MUSICAL_MCSS_GetElemPtr(p, i) + 10);
}
