/*
 * function: MUSICAL_MCSS_GetElemA
 * address:  0x021F5140
 * packet:   pkt_021F5140
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

unsigned char MUSICAL_MCSS_GetElemA(void *p, int i)
{
    return *(unsigned char *)(MUSICAL_MCSS_GetElemPtr(p, i) + 9);
}
