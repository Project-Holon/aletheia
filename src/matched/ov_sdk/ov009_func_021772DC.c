/*
 * function: DWC_GetConnectionKeepAliveTime
 * address:  0x021772DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x724 of the block held at +0x0 of the module state object, zero when the block is unset.
 *
 * symbols:
 *   gDwcTransInfo  0x021AB180  data
 */

extern char gDwcTransInfo[];

int DWC_GetConnectionKeepAliveTime(void)
{
    int *p = *(int **)gDwcTransInfo;

    return p != 0 ? *(int *)((char *)p + 0x724) : 0;
}
