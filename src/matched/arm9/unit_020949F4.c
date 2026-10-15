/*
 * unit:     yes
 * function: strncmp
 * address:  0x020949F4
 * packet:   pkt_02094798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * strncmp and strchr implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020949F4.c \
 *       --addr 0x020949F4 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int strncmp(const u8 *s1, const u8 *s2, u32 n)
{
    if (n != 0) {
        do {
            u8 c2 = *s2++;
            u8 c1 = *s1++;
            if (c1 != c2) {
                return c1 - c2;
            }
            if (c1 == 0) {
                break;
            }
        } while (--n != 0);
    }

    return 0;
}

u8 *strchr(const u8 *s, int c)
{
    u8 ch = (u8)c;
    u8 val = *s++;

    while (val != 0) {
        if (val == ch) {
            return (u8 *)s - 1;
        }
        val = *s++;
    }

    if (ch != 0) {
        return 0;
    }

    return (u8 *)s - 1;
}
