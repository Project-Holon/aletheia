/*
 * function: func_0206A854
 * address:  0x0206A854
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 40 compiled against 48: the call's second argument is the post-increment pointer (`ldr r0,[r1],#4` with r1 = &g[1]), which the spellings tried do not reproduce; the pair of `bic #1`/`bic #2` also comes out as one `bic #3`
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A854.c \
 *       --func func_0206A854 --addr 0x0206A854 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_02148B4C[];
extern void func_0206DDA4(u32 a, int b);

void func_0206A854(void)
{
    func_0206DDA4(g_02148B4C[0], 62);
    g_02148B4C[63] &= ~3u;
}
