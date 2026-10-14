/*
 * function: ZUKAN_DETAIL_FORM_SignalAnimDone
 * address:  0x021C5200
 * packet:   pkt_021C5200
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Sets +0xC of the object at +4 to 1 when both words are non-zero.
 */


void ZUKAN_DETAIL_FORM_SignalAnimDone(int *p)
{
    if (p[0] == 0)
        return;
    if (p[1] == 0)
        return;
    *(int *)(p[1] + 0xc) = 1;
}

