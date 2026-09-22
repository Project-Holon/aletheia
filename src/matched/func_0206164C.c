/*
 * function: func_0206164C
 * address:  0x0206164C
 * packet:   pkt_020611D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A816C     0x020A816C  data
 *
 * SAVE half of the save/restore pair the NNS G2D multi-cell renderer uses
 * around a mode switch: it copies the first two words of each of the five
 * 0x18-byte records at 0x020A816C out into the caller's flat buffer, two
 * words per record.  func_0206168C at 0x0206168C is the exact mirror and
 * restores them.
 *
 * The residue docs/notes/pkt_0206164C.c.txt recorded (10 concrete bytes, "which
 * of the three loop quantities gets which register") is resolved here, and the
 * lever is not declaration order, which that note swept exhaustively: it is
 * WHERE THE FIRST ZERO IS MATERIALISED.  The image does
 *
 *     mov r3, #0          <- i
 *     ...
 *     mov lr, r3          <- j = i, derived from the same zero
 *
 * so `i` must be the value that owns the literal and `j` must be spelled as a
 * COPY OF IT, not as its own `0`.  `int i = 0; ... int j = i;` with the `for`
 * carrying an empty init clause is byte-exact; `int j = 0` in any of the six
 * declaration orders leaves the two `mov`s swapped, which is the whole of the
 * previously recorded 10-byte residue.  This is the same shape the sibling
 * func_02061460 note describes (the original derives the second zero from the
 * first, the compiler materialises a second one), and the same fix applies.
 *
 * `t` sits between the two so the pointer, not `j`, takes ip; that ordering is
 * the permuter's decl-order(j<->t) result and is load-bearing for the
 * `add ip, ip, #0x18` / `add lr, lr, #2` pair.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206164C.c \
 *       --func func_0206164C --addr 0x0206164C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */

typedef unsigned int u32;

struct Ent020A816C { u32 w[6]; };

extern struct Ent020A816C g_020A816C[];

void func_0206164C(u32 *dst)
{
    int i = 0;
    struct Ent020A816C *t = g_020A816C;
    int j = i;

    for (; i < 5; i++) {
        dst[j] = t->w[0];
        dst[j + 1] = t->w[1];
        t++;
        j += 2;
    }
}
