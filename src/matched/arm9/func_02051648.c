/*
 * function: func_02051648
 * address:  0x02051648
 * packet:   pkt_02051648
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048A24  0x02048A24  arm
 *   g_020A1590     0x020A1590  data
 *   g_020A1584     0x020A1584  data
 *   g_020A1578     0x020A1578  data
 *
 * Constructor for the 0x25c-byte emitter record: defaults the three pointer
 * arguments, zeroes three words, stores the id halfword, stamps the 0x25b
 * byte from the source record or from zero, then hands twelve arguments to
 * func_02048A24 and stores its return at +0x20.
 *
 * CLOSES the 268/272 near miss written up in docs/notes/func_02051648.c.txt,
 * whose whole residue was one missing `mov r0, #0`: the compiler kept the
 * prologue's live zero across the branch and reused it for the null arm's
 * first two statements, where the image re-materialises it.
 *
 * The lever is STATEMENT ORDER, found by tools/permuter.py (hill, budget 300,
 * mutation `reorder(+3)`): the three zero stores are written BETWEEN the a4
 * and a5 defaults, not after all three.  Interleaving them that way puts the
 * `ldreq ip, [pc, ...]` for a5 after the three `str r0` of the prologue zero,
 * which is what kills that zero's live range before the branch and forces the
 * null arm to build its own.  Written with all three defaults first the zero
 * survives and the arm is four bytes short; that is the note's residue.  The
 * reorder is value-preserving: the defaults and the stores touch disjoint
 * objects (three parameters versus three fields of `this`).
 *
 * The note's other findings are all still load-bearing and unchanged:
 *   * `src != 0` is the FALL-THROUGH arm; the null arm is the `beq`.
 *   * the three pointer defaults are evaluated unconditionally before the
 *     branch and the compiler predicates each (`ldreq r3, [pc, ...]`).
 *   * `this->f25b = (u8)src->f00` casts the WORD field: the image is
 *     `ldr r2, [lr]` then `strb`, not `ldrb`.
 *   * a6 is truncated at the USE with `(u16)`, not declared `u16`; declared
 *     u16 the compiler emits a single `ldrh` and the file is 2 bytes short
 *     (docs/families/particle.h records this tell for the whole family).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051648.c \
 *       --func func_02051648 --addr 0x02051648 --cc 1.1p1 --arm
 *   EXACT, 272 bytes, 5 relocation sites, all resolved (label x2, literal x3).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int g_020A1590;
extern int g_020A1584;
extern int g_020A1578;

extern int func_02048A24(int a0, int a1, int a2, int a3, int a4, int a5,
                         int a6, int a7, int a8, int a9, int a10, int a11);

struct Src648 {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c;
};

struct Dst648 {
    u8  pad00[0x20];
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u8  pad32[0x229];
    u8  f25b;
};

void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3,
                   int *a4, int *a5, u32 a6)
{
    if (a3 == 0) a3 = &g_020A1590;
    if (a4 == 0) a4 = &g_020A1584;

    this->f24 = 0;
    this->f28 = 0;
    this->f2c = 0;

    if (a5 == 0) a5 = &g_020A1578;

    this->f30 = a2;

    if (src != 0) {
        this->f25b = (u8)src->f00;
        this->f20 = func_02048A24(src->f00, src->f04, src->f08, src->f0c,
                                  src->f10, src->f14, src->f18, src->f1c,
                                  (int)a3, (int)a4, (int)a5, (u16)a6);
    } else {
        this->f25b = 0;
        this->f20 = func_02048A24(0, 0xb50, 0xb50, 0x1555,
                                  0, 0x1000, 0x384000, 0,
                                  (int)a3, (int)a4, (int)a5, (u16)a6);
    }
}
