/*
 * function: func_02022490
 * address:  0x02022490
 * packet:   pkt_02022490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021468A4     0x021468A4  data
 *   func_02005624  0x02005624  thumb
 *   func_02022478  0x02022478  thumb
 *   func_020225F0  0x020225F0  thumb
 *
 * Arms one entry of the two-slot callback block at +0x74 of the dual-screen
 * text cluster: the exact inverse of func_020224DC.  It publishes the
 * context pointer at ctx[idx], the handler at fn[idx] (falling back to the
 * do-nothing func_020225F0 when the caller passes none, the same convention
 * func_02022458 uses), and marks the slot live with arg[idx] = 1.  Before
 * any of that, if BOTH user words are still zero the block was idle, so it
 * registers the dispatcher func_02022478 as a task through func_02005624 and
 * parks the handle at g_021468A4 +0x54 -- the same handle func_020224DC
 * releases once both words go back to zero.
 *
 * CLOSED 2026-09-21 by tools/permuter.py after this address had resisted
 * four hand passes (docs/notes/pkt_02022490.c.txt, four appended sections,
 * ~70 spellings measured plus a negative ../2.0/sp2 probe).  All of those
 * passes reached 76 bytes with 16 concrete out and diagnosed the residue
 * correctly as a three-way register rotation over +0x24..+0x3E: the image
 * keeps the scaled index in r2 and recomputes the slot base into r0 before
 * each offset store, the compile puts the index in r0 and the base in r1
 * (`--explain` prints it as r2->r0 x3, r1->r0 x3, r0->r1 x2).  The lever is
 * `temp(tmp = (char *)p)`, found by the hill search at compile 160 of 800:
 *
 *   a SECOND `char *` alias of the base pointer, declared AFTER the first
 *   store and used in exactly ONE of the two arms.
 *
 * That is why every uniform spelling failed.  The alias is a fresh value
 * with its own definition point and a use count of one, so Chaitin numbering
 * gives it a colour of its own and pushes the index and the base into the
 * image's registers; making it live in both arms, or hoisting its
 * declaration above the `i4` assignment, coalesces it straight back into `p`
 * and restores the 16-byte residue.  The `(char *)` re-cast on the other two
 * stores, which the note's last section identified as load-bearing, remains
 * load-bearing: dropping it costs four bytes.
 *
 * The mid-block declaration needs `-lang c99`, which this file's `lang:`
 * header field supplies.  Note that `match.py one` does NOT read that field
 * and defaults to no `-lang` at all, so re-verifying this file by hand needs
 * `--lang c99` on the command line or it reports CCERR; the manifest path
 * reads the header and is unaffected.
 *
 * Data flow checked against both neighbours: func_020224DC clears arg[idx]
 * first and only then tests both words, this function tests both words first
 * and only then writes, so the handle is created exactly once per
 * idle-to-live transition and released exactly once per live-to-idle one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022490.c \
 *       --func func_02022490 --addr 0x02022490 --cc 1.1p1 --thumb --lang c99
 */
typedef unsigned int u32;

extern char g_021468A4[];
extern void func_02022478(int a0, int *p);
extern void func_020225F0(void);
extern void *func_02005624(u32 a, u32 b, u32 c);

void func_02022490(char *p, int a1, int a2, int a3)
{
    int i4;

    if (*(u32 *)(p + 0x10) == 0 && *(u32 *)(p + 0x14) == 0)
        *(u32 *)(g_021468A4 + 0x54) =
            (u32)func_02005624((int)func_02022478, (u32)p, 0);

    i4 = a3 * 4;
    *(u32 *)(p + i4) = a1;

    char *q = (char *)p;

    if (a2 != 0)
        ((u32 *)(q + i4))[2] = a2;
    else
        ((u32 *)((char *)p + i4))[2] = (u32)func_020225F0;
    ((u32 *)((char *)p + i4))[4] = 1;
}
