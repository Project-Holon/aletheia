/*
 * function: func_0206A9DC
 * address:  0x0206A9DC
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 52 compiled against 48: mwccarm hoists the &g_02148B4C load and gives the copy destination lr, forcing `push {r4,lr}`; the original loads the destination into r3 before the ldm/stm and the flags base into r0 afterwards
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *   g_02148C2C       0x02148C2C  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A9DC.c \
 *       --func func_0206A9DC --addr 0x0206A9DC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern u32 g_02148B4C[];
extern char g_02148C2C[];

void func_0206A9DC(struct S12 *p)
{
    if (p == 0)
        return;
    *(struct S12 *)g_02148C2C = *p;
    g_02148B4C[63] &= ~0xA4u;
}
