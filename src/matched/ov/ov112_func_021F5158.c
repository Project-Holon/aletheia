/*
 * function: MUSICAL_MCSS_GetElemC
 * address:  0x021F5158
 * packet:   pkt_021F5158
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

unsigned char MUSICAL_MCSS_GetElemC(void *p, int i)
{
    return *(MUSICAL_MCSS_GetElemPtr(p, i) + 8);
}
