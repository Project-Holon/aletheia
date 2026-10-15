/*
 * function: wcscpy
 * address:  0x02096594
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     the second of the two unlabelled leaves trailing fwide's
 *           word run (the first is wcslen, its own file).  It is
 *           wcslen's wide-string copy counterpart: a `do { t = p;
 *           *p = *s++; p++; } while (*t);` loop, which is what keeps the
 *           `mov ip, r3` / `ldrh r2, [ip]` re-read of the character just
 *           stored -- the store and the loop test go through two different
 *           pointer variables, so the value is not forwarded into the compare.
 */

typedef unsigned short u16;

u16 *wcscpy(u16 *d, const u16 *s)
{
    u16 *r = d;
    u16 *p = d;
    u16 *t;

    do {
        t = p;
        *p = *s++;
        p++;
    } while (*t);
    return r;
}
