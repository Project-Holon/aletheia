/*
 * function: func_020419E4
 * address:  0x020419E4
 * packet:   pkt_020416D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02146A44      0x02146A44  data
 *   func_02041B94   0x02041B94  arm
 *   func_02041A1C   0x02041A1C  arm
 *
 * Tear the video state down: nothing at all when the context slot is
 * already null, otherwise the two shutdown routines of the pair that
 * func_020416D4 drives, and then both halves of the halfword at +4 of the
 * context are zeroed.  The two stores re-read the slot, because the first
 * store could alias it; the zero is materialised once and shared.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020419E4.c \
 *       --func func_020419E4 --addr 0x020419E4 --cc 1.1p1 --arm
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Every concrete byte is right; the site(s) above stay wildcarded because 02041B94 and 02041A1C
 * has exactly one witness image wide and it is the branch inside this very range.
 * Blocking evidence class: label/matched, no outside witness.  It unsticks when the
 * callee is itself EXACT (the `matched` class) or a second caller turns up.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * Blocking evidence class: label/matched, no outside witness.  Both callees
 * (0x02041B94 and 0x02041A1C) have exactly one witness image wide and it is
 * the branch inside this range, so no cut of a one-function file can free
 * them; either one being matched to EXACT closes this file.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8  pad_00[4];
    u16 unk_04;
    u16 unk_06;
};

extern struct Ctx *g_02146A44;

extern void func_02041B94(void);
extern void func_02041A1C(void);

void func_020419E4(void)
{
    if (g_02146A44 == 0)
        return;

    func_02041B94();
    func_02041A1C();
    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
}
