/*
 * function: func_02094B20
 * address:  0x02094B20
 * packet:   pkt_02094798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * strstr implementation in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02094B20.c \
 *       --func func_02094B20 --addr 0x02094B20 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

u8 *func_02094B20(const u8 *s1, const u8 *s2)
{
    u8 c2;
    u8 c1;
    const u8 *p;

    if (s2 == 0 || (c2 = *s2) == 0) {
        return (u8 *)s1;
    }

    c1 = *s1;
    p = s1 + 1;

    if (c1 != 0) {
        do {
            if (c1 == c2) {
                const u8 *p2 = s2 + 1;
                const u8 *p1 = p;
                u8 sc2, sc1;

                do {
                    sc2 = *p2++;
                    sc1 = *p1++;
                    if (sc1 != sc2) {
                        break;
                    }
                } while (sc1 != 0);

                if (sc2 == 0) {
                    return (u8 *)p - 1;
                }
            }
            c1 = *p++;
        } while (c1 != 0);
    }

    return 0;
}
