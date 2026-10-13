/*
 * function: FIELDMAP_GetSubscreenBusy
 * address:  0x02189A48
 * packet:   pkt_ov021_02189A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
int FIELDMAP_GetSubscreenBusy(char *p)
{
    return *(unsigned int *)(p + 0x144);
}
