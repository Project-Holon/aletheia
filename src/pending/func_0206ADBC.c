/*
 * function: func_0206ADBC
 * address:  0x0206ADBC
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, same address-reload residue as func_0206AAD4
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *   g_02148C7C       0x02148C7C  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206ADBC.c \
 *       --func func_0206ADBC --addr 0x0206ADBC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  g_02148B4C[];
extern char g_02148C7C[];
extern void func_0206AD64(void);

void *func_0206ADBC(void)
{
    if ((g_02148B4C[63] & 0x80) == 0) {
        func_0206AD64();
        g_02148B4C[63] |= 0x80;
    }
    return g_02148C7C;
}
