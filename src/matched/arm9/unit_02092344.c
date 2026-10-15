/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_02092344, memmove
 * address:  0x02092344
 * packet:   pkt_02092120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-wise memcpy (func_02092344) and memmove (memmove).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02092344.c \
 *       --addr 0x02092344 --arm
 */

typedef unsigned int size_t;

void *func_02092344(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (n == 0) {
        return dest;
    }

    do {
        *d++ = *s++;
    } while (--n != 0);

    return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
    if ((const unsigned char *)src >= (unsigned char *)dest) {
        unsigned char *d = (unsigned char *)dest;
        const unsigned char *s = (const unsigned char *)src;

        if (n == 0) {
            return dest;
        }

        do {
            *d++ = *s++;
        } while (--n != 0);

        return dest;
    } else {
        const unsigned char *s = (const unsigned char *)src + n;
        unsigned char *d = (unsigned char *)dest + n;

        if (n == 0) {
            return dest;
        }

        do {
            *--d = *--s;
        } while (--n != 0);

        return dest;
    }
}
