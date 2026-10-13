/*
 * function: FIELD_MSGBG_GetMenuHeightChars
 * address:  0x02190AEC
 * packet:   pkt_ov021_02190AEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, sole blocker of ov010 SCRCMD_WORK_StartMenu's MATCH.
 */

unsigned FIELD_MSGBG_GetMenuHeightChars(unsigned a, unsigned b, unsigned c, int d)
{
    unsigned n = a * (b + c);
    unsigned r = (n + 7) >> 3;

    if (d && r * 8 - n < 6) {
        r++;
    }
    return r;
}
