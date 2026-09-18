/*
 * function: func_0206AE94
 * address:  0x0206AE94
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 96 compiled against 112: this front end predicates all four guarded stores (`ldrne`/`strne` chains) where the original keeps four `beq` branches and a final `bxeq lr`.  The arms are four instructions each, i.e. under the five-instruction predication budget of docs/idioms/an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md, so the branches are unreachable from plain C; `volatile` on the pointers, on the global, `if (p)` vs `if (p != 0)` and a hoisted word load were all tried
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *
 * Spreads the four bytes of the word at 0x02148B4C + 0xA0 into four optional
 * out-parameters, little-endian first.  Each guard is independent and each
 * byte extraction re-loads the word from its own pool word, which is why the
 * address appears four times in the literal pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AE94.c \
 *       --func func_0206AE94 --addr 0x0206AE94 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_02148B4C[];

void func_0206AE94(u32 *a, u32 *b, u32 *c, u32 *d)
{
    if (a != 0)
        *a = g_02148B4C[0x28] & 0xFF;
    if (b != 0)
        *b = (g_02148B4C[0x28] >> 8) & 0xFF;
    if (c != 0)
        *c = (g_02148B4C[0x28] >> 16) & 0xFF;
    if (d != 0)
        *d = (g_02148B4C[0x28] >> 24) & 0xFF;
}
