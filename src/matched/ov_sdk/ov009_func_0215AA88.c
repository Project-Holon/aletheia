/*
 * function: CPS_SocDatagramMode
 * address:  0x0215AA88
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Puts the object at +0xa4 of the current root into mode 0xa and clears its
 * +0x50 word.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data

 */

extern char g_02150FEC[];

void CPS_SocDatagramMode(void)
{
    char *q = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (q != 0) {
        *(unsigned char *)(q + 8) = 0xa;
        *(int *)(q + 0x50) = 0;
    }
}


