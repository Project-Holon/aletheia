/*
 * function: func_02051534
 * address:  0x02051534
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 func_02051414 at +0x20: 0x02051414 (pkt_02051230, 208 bytes) open, no outside branch
 *
 * symbols:
 *   g_02146A88   0x02146A88  data
 *
 * For every live slot of g_02146A88, calls func_02051414 with the slot value;
 * returns how many slots were live (not what the callee returned).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051534.c \
 *       --func func_02051534 --addr 0x02051534 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 *g_02146A88;
typedef unsigned char  u8;
extern void func_02051414(u8 *a0);

int func_02051534(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_02146A88[i] != 0) {
            func_02051414((u8 *)g_02146A88[i]);
            n++;
        }
    }
    return n;
}
