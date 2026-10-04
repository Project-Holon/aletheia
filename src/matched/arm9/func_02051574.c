/*
 * function: func_02051574
 * address:  0x02051574
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 func_020514F4 at +0x20: 0x020514F4 is itself capped (see src/pending/func_020514F4.c)
 *
 * symbols:
 *   g_02146A88   0x02146A88  data
 *
 * Same walk as func_02051534, but each live slot goes to func_020514F4 -
 * the pair is a start/stop pass over the same 16-entry table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051574.c \
 *       --func func_02051574 --addr 0x02051574 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 *g_02146A88;
extern int func_020514F4(u32 *p);

int func_02051574(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_02146A88[i] != 0) {
            func_020514F4((u32 *)g_02146A88[i]);
            n++;
        }
    }
    return n;
}
