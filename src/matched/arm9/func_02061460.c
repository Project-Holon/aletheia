/*
 * function: func_02061460
 * address:  0x02061460
 * packet:   pkt_020611D4
 * region:   arm9
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146B70  0x02146B70  data a2
 *   g_020A816C  0x020A816C  data
 *
 * Re-derive every descriptor's enable and limit words from the renderer
 * mode (docs/families/cluster_020611D4.h): records below n = mode (plus
 * one when mode > 1) are enabled, and each record's {lo, hi} limit pair
 * is reset to {0, 0x10000} or {0, 0x20000} by its +0x0c kind word.
 *
 * THE LEVER, after two earlier lanes left this at 6 bytes (docs/notes/
 * pkt_020611D4.c.txt, docs/notes/pkt_020613D8.c.txt): the three stored
 * zeros are ONE named zero, `lo`, and the loop counter is INITIALISED
 * FROM IT (`for (i = lo; ...)`).  The image's `mov r5, #0` is the
 * counter's start and `mov lr, r5` / `mov r1, r5` / `mov r3, r5` are the
 * hoisted copies of the same value; with a literal 0 at each store (and
 * `i = 0`) the compiler materialises a separate zero into lr first and
 * gives the counter its own `mov r5, #0` -- the whole 6-byte residue.
 * `u32 z = i` spellings (tried before) do not reach it: the counter must
 * be derived from the zero, not the zero from the counter.  The permuter
 * is flat on the literal-zero body (hill, 161 singles), because no
 * value-preserving mutation it has introduces a shared zero variable.
 *
 * Front end: NOT pinned; EXACT under both dsi/1.1p1 and ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061460.c \
 *       --func func_02061460 --addr 0x02061460 --arm
 */

typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Rec020A816C {
    u32 unk_00; u32 unk_04; u32 unk_08; u32 unk_0c; u32 pad_10[2];
};

extern u16 g_02146B70;
extern struct Rec020A816C g_020A816C[];

void func_02061460(void)
{
    int i;
    u32 lo = 0;
    struct Rec020A816C *t = g_020A816C;
    int n = g_02146B70;

    if (n > 1u) n++;

    for (i = lo; i < 5; i++, t++) {
        if (i < n) t->unk_08 = 1;
        else       t->unk_08 = lo;
        if (t->unk_0c != 0) {
            t->unk_00 = lo;
            t->unk_04 = 0x10000;
        } else {
            t->unk_00 = lo;
            t->unk_04 = 0x20000;
        }
    }
}
