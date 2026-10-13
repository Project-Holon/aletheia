/*
 * function: CPS_SocRelease
 * address:  0x0215AB5C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word the object at +0xa4 points to, when it is there.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];

void CPS_SocRelease(void)
{
    char *p = *(char **)(g_02150FEC + 4);
    int *q = *(int **)(p + 0xa4);

    if (q) {
        *q = 0;
    }
}

