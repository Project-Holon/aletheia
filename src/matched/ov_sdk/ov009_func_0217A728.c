/*
 * function: DWC_Http_GetResult
 * address:  0x0217A728
 * packet:   pkt_ov009_0217A728
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The label==0 path breaks to the shared return-0 epilogue (an inlined
 * `return 0` there costs 8 bytes and a whole-function diff).
 *
 * sdk:      DWC_Http_GetResult (dwc_http.o)
 *
 * symbols:
 *   strcmp  0x020948e0  arm
 */

extern int strcmp(const char *s1, const char *s2);

char *DWC_Http_GetResult(char *http, char *label)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (*(char **)(http + 0x1a74 + i * 8) == 0)
            break;
        if (strcmp(label, *(char **)(http + 0x1a74 + i * 8)) == 0)
            return *(char **)(http + 0x1a78 + i * 8);
    }
    return 0;
}
