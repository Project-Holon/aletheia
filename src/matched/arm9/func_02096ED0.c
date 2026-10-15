/*
 * function: __minus_dec
 * address:  0x02096ED0
 * packet:   pkt_02096D10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL __minus_dec (ansi_fp.c): z = x - y on decimal records, with rounding
 * of the digits of y that fall past z's precision.  Three lanes left a hand
 * body at 95 concrete bytes out with the size exact (an allocator tie between
 * the text base and the y->sig.length temporary, docs/notes/pkt_02096ED0.c.txt).
 * The Metrowerks source closes it outright: the declarations
 * `int zlen, dexp; u8 *ib, *i, *ie; const u8 *jb, *j, *jn;`, the borrow loops
 * written `while (*k == 0) --k; while (k != i) { --*k; *++k += 10; }`, the
 * round-down flag with `goto done` out of the trailing-zero scan, and the
 * `u8 dl` narrowing (the image's `and r5, r4, #0xff`) on the leading-zero
 * shift.  Argument order is (dest, minuend, subtrahend): the 38-byte opening
 * copy is `*z = *x`.  No relocations.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__minus_dec.c \
 *       --func __minus_dec --addr 0x02096ED0 --cc 1.1p1 --arm
 *   EXACT, 672 bytes, 0 relocation sites.
 */
typedef unsigned char u8;
typedef signed short s16;

typedef struct decimal {
    char sign;
    char unused;
    s16 exp;
    struct {
        u8 length;
        u8 text[32];
        u8 unused;
    } sig;
} decimal;

void __minus_dec(decimal *z, const decimal *x, const decimal *y)
{
    int zlen, dexp;
    u8 *ib, *i, *ie;
    const u8 *jb, *j, *jn;

    *z = *x;

    if (y->sig.text[0] == 0)
        return;

    zlen = z->sig.length;
    if (zlen < y->sig.length)
        zlen = y->sig.length;

    dexp = z->exp - y->exp;
    zlen += dexp;

    if (zlen > 32)
        zlen = 32;

    while (z->sig.length < zlen)
        z->sig.text[z->sig.length++] = 0;

    ib = z->sig.text;
    i = ib + zlen;

    if (y->sig.length + dexp < zlen)
        i = ib + (y->sig.length + dexp);

    jb = y->sig.text;
    j = jb + (i - ib - dexp);
    jn = j;

    while (i > ib && j > jb) {
        --i;
        --j;
        if (*i < *j) {
            u8 *k = i - 1;
            while (*k == 0)
                --k;
            while (k != i) {
                --*k;
                *++k += 10;
            }
        }
        *i -= *j;
    }

    if (jn - jb < y->sig.length) {
        int round_down = 0;
        if (*jn < 5)
            round_down = 1;
        else if (*jn == 5) {
            const u8 *je = y->sig.text + y->sig.length;

            for (j = jn + 1; j < je; ++j)
                if (*j != 0)
                    goto done;

            i = ib + (jn - jb) + dexp - 1;

            if (*i & 1)
                round_down = 1;
        }
        if (round_down) {
            if (*i < 1) {
                u8 *k = i - 1;

                while (*k == 0)
                    --k;
                while (k != i) {
                    --*k;
                    *++k += 10;
                }
            }

            *i -= 1;
        }
    }
done:
    for (i = ib; *i == 0; ++i) {
    }

    if (i > ib) {
        u8 dl = (u8)(i - ib);
        z->exp -= dl;
        ie = ib + z->sig.length;
        for (; i < ie; ++i, ++ib)
            *ib = *i;
        z->sig.length -= dl;
    }

    ib = z->sig.text;

    for (i = ib + z->sig.length; i > ib;) {
        --i;
        if (*i != 0)
            break;
    }

    z->sig.length = (u8)(i - ib + 1);
}
