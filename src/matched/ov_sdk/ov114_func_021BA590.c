/*
 * function: func_021BA590
 * address:  0x021BA590
 * packet:   pkt_ov114_021BA590
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_compareToken (nhttp_stdlib_ntr)
 *
 * Closed (w5_nm): the case fold is a conditional expression over the bitwise
 * AND of the two range tests, `((c >= 'A') & (c <= 'Z')) ? c + 0x20 : c`, which
 * is what materialises the `mov rX,#1 / movlt rX,#0 / tst` flag pairs; the loop
 * is `while (fold(*p1) == fold(*p2))` with the terminator test inside and
 * `return -1` after it.
 *
 * symbols:
 *   (none)
 */

#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))

int func_021BA590(char *p1_p, char *p2_p)
{
    while (NHTTPi_TOLOWER(*p1_p) == NHTTPi_TOLOWER(*p2_p)) {
        if (*p1_p == '\0' || *p1_p == ' ')
            return 0;
        p1_p++;
        p2_p++;
    }
    return -1;
}
