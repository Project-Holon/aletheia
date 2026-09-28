/*
 * function: func_020338F8
 * address:  0x020338F8
 * packet:   pkt_0203331C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Accessor for the singleton pointer at 0x02146998.
 *
 * symbols:
 *   g_02146998  0x02146998  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020338F8.c \
 *       --func func_020338F8 --addr 0x020338F8 --cc 1.1p1 --arm
 */

extern void *g_02146998;

void *func_020338F8(void)
{
    return g_02146998;
}
