/*
 * function: func_02051504
 * address:  0x02051504
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A88   0x02146A88  data
 *
 * Counts the non-NULL entries of the 16-slot pointer table g_02146A88.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051504.c \
 *       --func func_02051504 --addr 0x02051504 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 *g_02146A88;

int func_02051504(void)
{
    int n = 0;
    int i;

    for (i = 0; i < 16; i++) {
        if (g_02146A88[i] != 0)
            n++;
    }
    return n;
}
