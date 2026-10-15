/*
 * function: _strlwr
 * address:  0x0217F21C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * In-place character remap: for every byte of the NUL-terminated string at
 * s that is a non-negative value below 0x80, replace it with the byte at
 * the same index in the 128-entry table at 0x020A60DC; leave negative and
 * high bytes alone.  Returns s.
 *
 * symbols:
 *   __tolower_map     0x020A60DC  data
 */

extern unsigned char __tolower_map[];

char *_strlwr(char *s)
{
    char *ret = s;
    int c = *s;

    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = __tolower_map[c];
            }
            *s = c;
            c = *++s;
        } while (c != 0);
    }
    return ret;
}
