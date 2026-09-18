/*
 * function: func_0206DB40
 * address:  0x0206DB40
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0214BAB4       0x0214BAB4  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DB40.c \
 *       --func func_0206DB40 --addr 0x0206DB40 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern char *g_0214BAB4;

void func_0206DB40(u32 *p)
{
    if (g_0214BAB4 == 0) {
        *p = 0;
        g_0214BAB4 = (char *)p;
    }
}
