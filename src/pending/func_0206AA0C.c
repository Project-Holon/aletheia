/*
 * function: func_0206AA0C
 * address:  0x0206AA0C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 52 against 48: same residue as func_0206A9DC (its 0x02148C38 twin)
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *   g_02148C38       0x02148C38  data
 * Twin of func_0206A9DC over the 12-byte slot at 0x02148C38.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA0C.c \
 *       --func func_0206AA0C --addr 0x0206AA0C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern u32 g_02148B4C[];
extern char g_02148C38[];

void func_0206AA0C(struct S12 *p)
{
    if (p == 0)
        return;
    *(struct S12 *)g_02148C38 = *p;
    g_02148B4C[63] &= ~0xA4u;
}
