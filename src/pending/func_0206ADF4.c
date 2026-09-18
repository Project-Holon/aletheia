/*
 * function: func_0206ADF4
 * address:  0x0206ADF4
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
 *   g_02148CAC       0x02148CAC  data
 * Same lazy-init as func_0206ADBC over a second 0x02148Cxx slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206ADF4.c \
 *       --func func_0206ADF4 --addr 0x0206ADF4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  g_02148B4C[];
extern char g_02148CAC[];
extern void func_0206AD64(void);

void *func_0206ADF4(void)
{
    if ((g_02148B4C[63] & 0x80) == 0) {
        func_0206AD64();
        g_02148B4C[63] |= 0x80;
    }
    return g_02148CAC;
}
