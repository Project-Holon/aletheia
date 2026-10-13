/*
 * function: BRIGHTNESS_ChangeReset
 * address:  0x02023F98
 * packet:   pkt_02023F98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_brightnessMain    0x0214691C  data
 *   g_brightnessSub   0x021468FC  data
 *   g_brightnessSub  0x021468FC  data
 *
 * The teardown counterpart of BRIGHTNESS_ChangeRequest: given the same two-bit engine
 * mask, it zeroes each selected engine's 0x20-byte blend record and clears
 * that engine's active flag.  Main engine's record is at 0x0214691C and its
 * flag at 0x021468FC+0x3c; the sub engine's record is at 0x021468FC+0x20
 * and its flag at 0x021468FC+0x1c.  The two arms are written out in full.
 *
 * THE POOL HAS A DUPLICATE OF 0x021468FC, AND WHICH USES SHARE A SLOT IS
 * THE WHOLE FINDING.  The three pool words are
 *
 *     0x02023FCC  .word 0x0214691C     <- arm 1's memset base
 *     0x02023FD0  .word 0x021468FC     <- BOTH flag stores
 *     0x02023FD4  .word 0x021468FC     <- arm 2's memset base
 *
 * mwccarm emits one pool word per source SYMBOL, in order of first use, so
 * the slot count and the sharing pattern read straight back as the number of
 * distinct externs and which statements name which.  The obvious spelling --
 * one `g_wipe_sub` at 0x021468FC for all three of its uses -- CSEs the two
 * 0x021468FC references into one slot, and the third slot then re-emits
 * 0x0214691C: 64 bytes, every instruction right, two bytes out at 0x02023FD4
 * and nothing any amount of statement shuffling reaches (63 single mutations
 * and a full permuter.py hill pass left it untouched, because it is a pool
 * layout decision, not an allocation one).
 *
 * What reproduces it is TWO distinct externs at 0x021468FC, split along the
 * image's own sharing: `g_brightnessSub` names the object both arms' flag stores
 * reach (+0x3c for main, +0x1c for sub, one slot between them) and
 * `g_brightnessSub` names the one arm 2 memsets (its own slot).  Whether the
 * original really had two objects at one address or one object the compiler
 * saw through two declarations is not decidable from the bytes; what the
 * bytes do fix is that three source-level names were in play, not two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BRIGHTNESS_ChangeReset.c \
 *       --func BRIGHTNESS_ChangeReset --addr 0x02023F98 --cc 1.1p1 --thumb
 */

typedef unsigned int  u32;

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern u32 g_brightnessMain[];
extern u32 g_brightnessSub[];
extern u32 g_brightnessSub[];

void BRIGHTNESS_ChangeReset(u32 mask)
{
    if (mask & 1) {
        MI_CpuFill8(g_brightnessMain, 0, 0x20);
        g_brightnessSub[0x3c / 4] = 0;
    }
    if (mask & 2) {
        MI_CpuFill8(g_brightnessSub, 0, 0x20);
        g_brightnessSub[0x1c / 4] = 0;
    }
}
