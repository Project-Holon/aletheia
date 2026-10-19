/*
 * function: NNS_GfdInitVramManager
 * address:  0x020613D8
 * packet:   pkt_020611D4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_GfdSetTexVramSlotOrder   0x02061390  arm
 *   NNSi_GfdUpdateVramManager   0x02061460  arm
 *   NNSi_GfdDefaultAllocTexVram   0x020614D4  arm
 *   NNSi_GfdDefaultFreeTexVram   0x02061644  arm
 *   g_02146B70      0x02146B70  data
 *   NNS_GfdDefaultFuncAllocTexVram      0x020A8140  data
 *   NNS_GfdDefaultFuncFreeTexVram      0x020A8144  data
 *
 * The mode selector of the NNS G2D multi-cell renderer.  It builds one of two
 * five-slot tables through NNSi_GfdSetTexVramSlotOrder depending on the mode, publishes the
 * mode word at 0x02146B70, re-runs NNSi_GfdUpdateVramManager (the table walker that lives
 * just past this function), and installs the two callbacks at 0x020A8140 /
 * 0x020A8144 when the second argument is non-zero.
 *
 * The mode test is written `mode <= 2`: the original's fall-through arm is the
 * (2, 0) table pair and its branch is the positive `bhi` to the (0, 2) pair,
 * which is what mwccarm emits for the negated form.
 *
 * THE COMPILER PIN.  The C below is, character for character, the body
 * docs/notes/pkt_020613D8.c.txt parked as DIFF.  The residue that note records
 * -- "this compiler cross-jumps the two calls' identical two-instruction tails
 * (`str ip, [sp]; bl NNSi_GfdSetTexVramSlotOrder`) into one shared block, the original keeps
 * both copies", 128 compiled against 136 -- is a FRONT-END artefact, not a
 * source-shape question.  Under `../2.0/sp2` the same source keeps both copies
 * and is byte-exact at 136.  The note's sweep (separate `if`s, `else if`, an
 * explicit `goto`, a `switch`, and four `#pragma`s) was correct in concluding
 * that no spelling moves it under 1.1p1.
 *
 * The pin is shared with src/matched/NNS_GfdAllocVram.c in this same cluster and
 * its evidence row is in docs/FRONTEND-PINS.md; a whole-function tail
 * duplication that 1.1p1 merges and 2.0/sp2 keeps is a second instance of the
 * same "2.0 spends bytes where 1.1p1 shares them" family as the kept-constants
 * tell.
 *
 * The pool word for NNSi_GfdDefaultFreeTexVram at +0x80 resolves only because
 * src/matched/NNSi_GfdDefaultFreeTexVram.c is an EXACT manifest entry: this store is the
 * only reference to that eight-byte stub anywhere in the image.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_GfdInitVramManager.c \
 *       --func NNS_GfdInitVramManager --addr 0x020613D8 --arm --cc ../2.0/sp2
 *   EXACT, 136 bytes, 8 relocation sites, all 8 resolved.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_02146B70;
extern u32 NNS_GfdDefaultFuncAllocTexVram;
extern u32 NNS_GfdDefaultFuncFreeTexVram;

extern void NNSi_GfdSetTexVramSlotOrder(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void NNSi_GfdUpdateVramManager(void);
extern u32 NNSi_GfdDefaultAllocTexVram(u32 size, u32 which);
extern u32 NNSi_GfdDefaultFreeTexVram(void);

void NNS_GfdInitVramManager(u32 mode, u32 flag)
{
    if (mode <= 2) {
        NNSi_GfdSetTexVramSlotOrder(4, 3, 2, 0, 1);
    } else {
        NNSi_GfdSetTexVramSlotOrder(4, 3, 0, 2, 1);
    }

    g_02146B70 = (u16)mode;
    NNSi_GfdUpdateVramManager();

    if (flag == 0) {
        return;
    }

    NNS_GfdDefaultFuncAllocTexVram = (u32)NNSi_GfdDefaultAllocTexVram;
    NNS_GfdDefaultFuncFreeTexVram = (u32)NNSi_GfdDefaultFreeTexVram;
}
