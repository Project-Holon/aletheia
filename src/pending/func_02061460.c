/*
 * function: func_02061460
 * address:  0x02061460
 * packet:   pkt_020613D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   g_02146B70   0x02146B70  data
 *   g_020A816C   0x020A816C  data
 *
 * The table walker of the NNS G2D multi-cell renderer, called by func_020613D8
 * once the mode word is published.  Five 0x18-byte records at 0x020A816C: the
 * first `n` of them (record 0 when n <= 1) get their enable word at +8 set to
 * 1 and the rest to 0, and every record's two limit words at +0 / +4 are
 * written from its own mode word at +0xC (0x10000 for the non-zero case,
 * 0x20000 for the zero case).
 *
 * Residue, six bytes, three instructions: the register that holds zero.  The
 * original materialises the loop counter's zero first (`mov r5, #0`) and
 * derives the flag store's zero from it (`mov lr, r5`, `mov r1, r5`,
 * `mov r3, r5`); this compiler materialises the loop's zero into lr first
 * (`mov lr, #0`) and gives the counter a second `mov r5, #0`.  The two
 * registers are otherwise identical.  Types are pinned by the byte
 * comparison: the counter is a full 32-bit local (no truncation across the
 * increment) and the guard is an unsigned compare (`addhi`) while the flag
 * test is signed (`strlt`/`strge`), which only `int i` / `int n` with an
 * unsigned guard reproduces.  Sixty-four type/guard/compare spellings and ten
 * statement shapes were compiled; the best is six bytes.
 *
 * This is a separate file from func_020613D8 on purpose: the two functions are
 * the only two places in the image that name 0x02146B70, so a unit spanning
 * both would leave that pool word with no witness outside the compared range.
 * Cut apart, each file's pool word is the other's witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061460.c \
 *       --func func_02061460 --addr 0x02061460 --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Rec020A816C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 pad_10[2];
};

extern u16 g_02146B70;
extern struct Rec020A816C g_020A816C[];

void func_02061460(void)
{
    int i = 0;
    int n = g_02146B70;
    struct Rec020A816C *t = g_020A816C;

    if (n > 1u) {
        n++;
    }

    do {
        if ((s32)i < (s32)n) {
            t->unk_08 = 1;
        } else {
            t->unk_08 = 0;
        }
        if (t->unk_0c != 0) {
            t->unk_00 = 0;
            t->unk_04 = 0x10000;
        } else {
            t->unk_00 = 0;
            t->unk_04 = 0x20000;
        }
        i++;
        t++;
    } while (i < 5);
}
