/*
 * function: func_021DE14C
 * address:  0x021DE14C
 * packet:   pkt_021DE14C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * ARM leaf scan over an array of string pointers: returns 7 as soon as it
 *     meets an entry with no string or an empty one, and 0 when all `n` entries
 *     carry text.  Used to reject a table of names with a hole in it.
 */

int func_021DE14C(char **names, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        char *s = names[i];

        if (s == 0 || *s == 0)
            return 7;
    }
    return 0;
}

