/*
 * file:     unit_02061224_p04.c
 * unit:     yes
 * function: func_02061644, func_0206164C, func_0206168C
 * address:  0x02061644
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A816C     0x020A816C  data
 */
typedef unsigned int u32;

struct Ent020A816C { u32 w[6]; };

u32 func_02061644(void);
void func_0206164C(u32 *dst);
void func_0206168C(u32 *src);
extern struct Ent020A816C g_020A816C[];


/*
 * An eight-byte unlabelled leaf: `mov r0, #0; bx lr`.  disasm.py only labels
 * a function whose prologue saves lr, so this stub is invisible in the
 * listing and sits between the tail of func_020614D4's literal pool (which
 * ends at 0x02061640) and the next labelled function at 0x0206164C.
 *
 * It is the default callback func_020613D8 installs at 0x020A8144 as a
 * function pointer, so the pool word naming it is the only reference in the
 * image; filing this entry is what lets that pool word resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061644.c \
 *       --func func_02061644 --addr 0x02061644 --arm --cc 1.1p1
 */
u32 func_02061644(void)
{
    return 0;
}


/*
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


/*
 * RESTORE half of the pair whose save half is src/matched/func_0206164C.c:
 * it copies two words per record back from the caller's flat buffer into the
 * first two words of each of the five 0x18-byte records at 0x020A816C.
 *
 * Same lever as the save half (see that file's header): the image derives the
 * second loop zero from the first with `mov ip, r3`, so `j` has to be spelled
 * as a copy of `i` and not as its own literal `0`.
 *
 * The one DIFFERENCE from the save half is declaration order, and it is not
 * cosmetic.  In the save half `t` is declared BETWEEN `i` and `j`, which puts
 * the table pointer in ip and the destination index in lr; here the same order
 * is 10 bytes out because the registers are the other way round -- the image
 * puts the table pointer in lr and the index in ip.  Declaring `j` before `t`
 * reproduces it exactly.  The two mirrors therefore disagree on declaration
 * order despite being written from the same template, which is the
 * declaration-order-is-register-order idiom applied in both directions.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206168C.c \
 *       --func func_0206168C --addr 0x0206168C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */
void func_0206168C(u32 *src)
{
    int i = 0;
    int j = i;
    struct Ent020A816C *t = g_020A816C;

    for (; i < 5; i++) {
        t->w[0] = src[j];
        t->w[1] = src[j + 1];
        j += 2;
        t++;
    }
}
