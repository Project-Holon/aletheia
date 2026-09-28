/*
 * function: func_02194CE8
 * address:  0x02194CE8
 * packet:   pkt_ov021_02194CE8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; the sole blocker is the callee 0x02194D1C, an unlabelled leaf
 * (disasm only labels prologues that save lr) with no outside witness, so both
 * call sites stay wildcarded.  The MATCH* extent runs long because that leaf is
 * the disassembler's next label-less follower.
 *
 * Re-verified 2026-09-27 (recursive MATCH unblocker lane, 0x02180000..0x0219FFFF):
 * still MATCH*, 50/50 bytes, both sites unresolved.  The leaf was attacked
 * bottom-up; the best C shape reproduces 344/344 bytes with 32 bytes of pure
 * register-naming residue in five VTX_16 groups, so no matched EXACT entry could
 * be filed.  Full write-up: docs/notes/func_02194D1C.c.txt.  The caller promotes
 * with no C change the moment the leaf lands.
 *
 * symbols:
 *   func_02194D1C  0x02194D1C  thumb  ov021
 */

typedef unsigned short u16;

extern void func_02194D1C(int a, void *b, int c);

void func_02194CE8(int a, u16 *b)
{
    switch (*b) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        break;
    case 3:
        func_02194D1C(a, b, 0);
        break;
    case 4:
        func_02194D1C(a, b, 1);
        break;
    }
}
