/*
 * function: func_0206AAD4
 * address:  0x0206AAD4
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 64 compiled against 68: after the call mwccarm keeps &g_02148B4C live in r4 (hence a push); the original re-materialises the address from its pool word. `volatile` on the global does not change it
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *   g_02148B98       0x02148B98  data
 *   g_02148C4C       0x02148C4C  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AAD4.c \
 *       --func func_0206AAD4 --addr 0x0206AAD4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  g_02148B4C[];
extern char g_02148B98[];
extern char g_02148C4C[];
extern void func_0207B67C(void *a, void *b);

void *func_0206AAD4(void)
{
    if ((g_02148B4C[63] & 8) == 0) {
        func_0207B67C(g_02148B98, g_02148C4C);
        g_02148B4C[63] |= 8;
    }
    return g_02148C4C;
}
