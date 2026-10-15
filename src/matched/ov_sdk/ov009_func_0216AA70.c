/*
 * function: DWCi_CheckLogin
 * address:  0x0216AA70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the block held in the global at 0x021AA874 has 5 in its +4
 * word.
 *
 * symbols:
 *   gDwcLoginControl  0x021AA874  data

 */

extern char gDwcLoginControl[];

int DWCi_CheckLogin(void)
{
    char *p = *(char **)gDwcLoginControl;

    if (p != 0 && *(int *)(p + 4) == 5) return 1;
    return 0;
}


