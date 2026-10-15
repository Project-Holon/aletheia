/*
 * function: DWC_SetConnectionKeepAliveTime
 * address:  0x021772B8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the word at +0x724 of the state block when both are present.
 *
 * symbols:
 *   gDwcTransInfo  0x021AB180  data
 */

extern char gDwcTransInfo[];

int DWC_SetConnectionKeepAliveTime(int v)
{
    char *p = *(char **)gDwcTransInfo;

    if (p == 0 || v == 0) {
        return 0;
    }

    *(int *)(p + 0x724) = v;

    return 1;
}

