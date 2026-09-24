/*
 * function: func_0216C82C
 * address:  0x0216C82C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 1 unless the current object is in mode 2 (always 1) or carries a zero
 * byte at +0x35d with a mode other than 2.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data

 */

extern char g_021AA878[];

int func_0216C82C(void)
{
    int r = 1;
    char *p = *(char **)(g_021AA878 + 4);

    if (*(unsigned char *)(p + 0x365) != 2)
        if (*(unsigned char *)(p + 0x35d) == 0) r = 0;
    return r;
}


