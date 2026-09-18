/*
 * function: func_0206AD20
 * address:  0x0206AD20
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, same address-reload residue as func_0206AAD4; also PC24 func_0206AB18 at +0x1c has no outside branch
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *   g_02148B54       0x02148B54  data
 *   g_02148D0C       0x02148D0C  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AD20.c \
 *       --func func_0206AD20 --addr 0x0206AD20 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  g_02148B4C[];
extern char g_02148B54[];
extern char g_02148D0C[];
extern void func_0206AB18(void *a, void *b);

void *func_0206AD20(void)
{
    if ((g_02148B4C[63] & 16) == 0) {
        func_0206AB18(g_02148B54, g_02148D0C);
        g_02148B4C[63] |= 16;
    }
    return g_02148D0C;
}
