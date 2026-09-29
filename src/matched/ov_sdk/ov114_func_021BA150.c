/*
 * function: func_021BA150
 * address:  0x021BA150
 * packet:   pkt_ov114_021BA150
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_strnicmp (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 *
 * symbols:
 *   (none)
 */

#define LOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))

int func_021BA150(const char *p1_p, const char *p2_p, int size)
{
    char c2;
    char c1;

    while (size > 0) {
        c1 = *p1_p++;
        c2 = *p2_p++;
        if (c1 == 0 || c2 == 0) {
            if (c1 == 0 && c2 == 0) {
                size = 0;
                break;
            }
        }
        if (LOWER(c1) != LOWER(c2))
            break;
        size--;
    }
    return size;
}
