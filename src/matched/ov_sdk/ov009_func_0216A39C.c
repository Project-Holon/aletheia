/*
 * function: DWCi_GetUserData
 * address:  0x0216A39C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x1c of the block held at +0x0 of the module state object, zero when the block is unset.
 *
 * symbols:
 *   gDwcLoginControl  0x021AA874  data
 */

extern char gDwcLoginControl[];

int DWCi_GetUserData(void)
{
    int *p = *(int **)gDwcLoginControl;

    return p != 0 ? *(int *)((char *)p + 0x1c) : 0;
}
