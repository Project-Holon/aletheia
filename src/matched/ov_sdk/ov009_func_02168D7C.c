/*
 * function: func_02168D7C
 * address:  0x02168D7C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the object at +0xc of the current root exists and its first word
 * is 1.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data

 */

extern char g_021AA860[];

int func_02168D7C(void)
{
    int r = 0;
    char *p = *(char **)(g_021AA860 + 0xc);

    if (p != 0 && *(int *)p == 1) r = 1;
    return r;
}


