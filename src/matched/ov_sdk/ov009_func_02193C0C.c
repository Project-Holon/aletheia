/*
 * function: stripchars
 * address:  0x02193C0C
 * packet:   pkt_ov009_02193C0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      stripchars (gbucket.o)
 *
 * Replaces every backslash with a forward slash, in place; returns the
 * original pointer.
 */

char *stripchars(char *s)
{
    char *p = s;

    while (*s != 0)
    {
        if (*s == '\\')
            *s = '/';
        s++;
    }

    return p;
}
