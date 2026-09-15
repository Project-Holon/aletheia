/*
 * unit:     yes
 * function: func_02094860
 * address:  0x02094860
 * packet:   pkt_02094798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * strncpy and strcat implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02094860.c \
 *       --addr 0x02094860 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 *func_02094860(u8 *dest, const u8 *src, u32 n)
{
    u8 *d = dest;

    if (n == 0) {
        return dest;
    }

    do {
        u8 *prev = d;
        *d++ = *src++;
        if (*prev == 0) {
            if (--n == 0) {
                return dest;
            }
            do {
                *d++ = 0;
            } while (--n != 0);
            return dest;
        }

        if (--n == 0) {
            return dest;
        }
    } while (1);
}

u8 *func_020948B0(u8 *dest, const u8 *src)
{
    u8 *d = dest;

    while (*d++)
        ;
    --d;
    while (*d++ = *src++)
        ;

    return dest;
}
